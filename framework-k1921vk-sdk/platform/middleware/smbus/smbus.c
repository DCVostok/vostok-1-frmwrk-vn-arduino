/*==============================================================================
 * Драйвер SMBus 2.0 для работы с I2C микроконтроллеров К1921ВКx
 *
 *------------------------------------------------------------------------------
 * НИИЭТ, Дмитрий Сериков <lonie@niiet.ru>
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "smbus.h"

//-- Private types -------------------------------------------------------------
typedef enum {
    MODE_WR = 0,
    MODE_RD
} SMBus_ModeRW_TypeDef;

typedef enum {
    PROT_ANY = 0,
    PROT_QUICK_WRITE,
    PROT_QUICK_READ,
    PROT_SEND_BYTE,
    PROT_RECEIVE_BYTE,
    PROT_WRITE_BYTE,
    PROT_READ_BYTE,
    PROT_WRITE_WORD,
    PROT_READ_WORD,
    PROT_BLOCK_WRITE,
    PROT_BLOCK_READ,
    PROT_PROCESS_CALL,
    PROT_BLOCK_PROCESS_CALL,
    PROT_BURST_WRITE,
    PROT_BURST_READ,
} SMBus_Protocol_TypeDef;

typedef enum {
    STATE_ANY = 0,
    STATE_SEND_START,
    STATE_SEND_MASTERCODE,
    STATE_SEND_REP_START,
    STATE_SEND_ADDRESS_HI,
    STATE_SEND_ADDRESS_LO,
    STATE_SEND_CMD_CODE,
    STATE_SEND_DATA,
    STATE_RECV_DATA,
    STATE_SEND_PEC,
    STATE_RECV_PEC,
    STATE_SEND_STOP
} SMBus_State_TypeDef;

typedef struct
{
    SMBus_SlaveDescriptor_TypeDef* SlaveDescr;
    uint8_t WrBytes;
    uint8_t* RdBytes; //we need to return number of bytes readen, so it's a pointer
    uint8_t WrBytesRemain;
    uint8_t RdBytesRemain;
    uint8_t* WrDataPtr;
    uint8_t* RdDataPtr;
    uint8_t CmdCode;
    SMBus_ModeRW_TypeDef ModeRW;
    SMBus_Protocol_TypeDef ProtocolType;
    SMBus_State_TypeDef CurrState;
    SMBus_Flag_TypeDef Flag;
    SMBus_Status_TypeDef Status;
} SMBus_MasterDescriptor_TypeDef;

//-- Private variables ---------------------------------------------------------
static SMBus_MasterDescriptor_TypeDef MasterDescr[SMBUS_MASTERS_TOTAL];
static uint16_t WrDataTemp;
static uint8_t RdBytesTemp;

//-- Private functions ---------------------------------------------------------
static uint32_t SMBus_IsMasterBusy(SMBus_MasterNum_TypeDef MasterN)
{
    return (SMBus_HW_IsBusBusy(MasterN) || (MasterDescr[MasterN].Status == SMBUS_STAT_BUSY));
}

static void SMBus_SendAddresHigh(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_HW_SetData(MasterN, (((MasterDescr[MasterN].SlaveDescr->Address & 0xFF00) >> 7) | 0xF0 | MasterDescr[MasterN].ModeRW));
}

static void SMBus_SendAddresLow(SMBus_MasterNum_TypeDef MasterN)
{
    if (MasterDescr[MasterN].SlaveDescr->EnAddr10bit != 0)
        SMBus_HW_SetData(MasterN, (MasterDescr[MasterN].SlaveDescr->Address & 0xFF));
    else
        SMBus_HW_SetData(MasterN, ((MasterDescr[MasterN].SlaveDescr->Address << 1) | MasterDescr[MasterN].ModeRW));
}

static void SMBus_ErrStop(SMBus_MasterNum_TypeDef MasterN, SMBus_Flag_TypeDef Flag)
{
    MasterDescr[MasterN].Status = SMBUS_STAT_ERR;
    MasterDescr[MasterN].Flag = Flag;
    MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
    SMBus_HW_Stop(MasterN);
}

static void SMBus_FSM(SMBus_MasterNum_TypeDef MasterN)
{
    switch (MasterDescr[MasterN].CurrState) {

    case STATE_SEND_START:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_STDONE) &&
            ((MasterDescr[MasterN].SlaveDescr->Mastercode & 0xf8) == 0x08)) {
            MasterDescr[MasterN].CurrState = STATE_SEND_MASTERCODE;
            SMBus_HW_SetData(MasterN, MasterDescr[MasterN].SlaveDescr->Mastercode);
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_STDONE) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HRSDONE)) {
            if (MasterDescr[MasterN].SlaveDescr->EnAddr10bit != 0) {
                MasterDescr[MasterN].CurrState = STATE_SEND_ADDRESS_HI;
                SMBus_SendAddresHigh(MasterN);
            } else {
                MasterDescr[MasterN].CurrState = STATE_SEND_ADDRESS_LO;
                SMBus_SendAddresLow(MasterN);
            }
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_MASTERCODE:
        if (SMBus_HW_GetState(MasterN) == SMBUS_HMTMCOK) {
            MasterDescr[MasterN].CurrState = STATE_SEND_START;
            SMBus_HW_Start(MasterN);
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_MASTERCODE_ERR);
        break;

    case STATE_SEND_REP_START:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_RSDONE) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HRSDONE)) {
            MasterDescr[MasterN].ModeRW = MODE_RD;
            if (MasterDescr[MasterN].SlaveDescr->EnAddr10bit != 0) {
                //after rep start we send high bit again, but handle it like if we sent low
                MasterDescr[MasterN].CurrState = STATE_SEND_ADDRESS_LO;
                SMBus_SendAddresHigh(MasterN);
            } else {
                MasterDescr[MasterN].CurrState = STATE_SEND_ADDRESS_LO;
                SMBus_SendAddresLow(MasterN);
            }
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_ADDRESS_HI:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_HMTADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMRADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_MTADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_MRADPA)) {
            MasterDescr[MasterN].CurrState = STATE_SEND_ADDRESS_LO;
            SMBus_SendAddresLow(MasterN);
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_HMTADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HMRADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_MTADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_MRADNA))
            SMBus_ErrStop(MasterN, SMBUS_FLAG_ADDR_NAK);
        else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_ADDRESS_LO:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_HMTADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMRADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_MTADPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_MRADPA)) {
            if ((MasterDescr[MasterN].ProtocolType == PROT_QUICK_WRITE) ||
                (MasterDescr[MasterN].ProtocolType == PROT_QUICK_READ)) {
                MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;
                MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
                SMBus_HW_Stop(MasterN);
            } else if (MasterDescr[MasterN].ProtocolType == PROT_SEND_BYTE) {
                MasterDescr[MasterN].CurrState = STATE_SEND_DATA;
                MasterDescr[MasterN].WrBytesRemain -= 1;
                SMBus_HW_SetData(MasterN, *MasterDescr[MasterN].WrDataPtr);
            } else if (MasterDescr[MasterN].ProtocolType == PROT_RECEIVE_BYTE) {
                MasterDescr[MasterN].CurrState = STATE_RECV_DATA;
                if (MasterDescr[MasterN].SlaveDescr->EnPEC == 0)
                    SMBus_HW_NACK(MasterN);
            } else if (MasterDescr[MasterN].ModeRW == MODE_WR) {
                SMBus_HW_SetData(MasterN, MasterDescr[MasterN].CmdCode);
                MasterDescr[MasterN].CurrState = STATE_SEND_CMD_CODE;
            } else //it was repeated start and we need to read data
            {
                if ((MasterDescr[MasterN].RdBytesRemain == 1) &&
                    (MasterDescr[MasterN].SlaveDescr->EnPEC == 0))
                    SMBus_HW_NACK(MasterN);
                MasterDescr[MasterN].CurrState = STATE_RECV_DATA;
            }
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_HMTADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HMRADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_MTADNA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_MRADNA))
            SMBus_ErrStop(MasterN, SMBUS_FLAG_ADDR_NAK);
        else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_CMD_CODE:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDANA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMTDANA))
            SMBus_ErrStop(MasterN, SMBUS_FLAG_CMD_DENIED);
        else if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDAPA) ||
                 (SMBus_HW_GetState(MasterN) == SMBUS_HMTDAPA)) {
            if ((MasterDescr[MasterN].ProtocolType == PROT_READ_BYTE) ||
                (MasterDescr[MasterN].ProtocolType == PROT_READ_WORD) ||
                (MasterDescr[MasterN].ProtocolType == PROT_BLOCK_READ) ||
                (MasterDescr[MasterN].ProtocolType == PROT_BURST_READ)) {
                MasterDescr[MasterN].CurrState = STATE_SEND_REP_START;
                SMBus_HW_Start(MasterN);
            } else //all write protocols
            {
                MasterDescr[MasterN].CurrState = STATE_SEND_DATA;
                if ((MasterDescr[MasterN].ProtocolType == PROT_BLOCK_WRITE) ||
                    (MasterDescr[MasterN].ProtocolType == PROT_BLOCK_PROCESS_CALL))
                    SMBus_HW_SetData(MasterN, MasterDescr[MasterN].WrBytes);
                else {
                    MasterDescr[MasterN].WrBytesRemain -= 1;
                    SMBus_HW_SetData(MasterN, *MasterDescr[MasterN].WrDataPtr++);
                }
            }
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_DATA:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDAPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMTDAPA)) {
            if ((MasterDescr[MasterN].WrBytesRemain == 0) &&
                ((MasterDescr[MasterN].ProtocolType == PROT_PROCESS_CALL) ||
                 (MasterDescr[MasterN].ProtocolType == PROT_BLOCK_PROCESS_CALL))) {
                MasterDescr[MasterN].CurrState = STATE_SEND_REP_START;
                SMBus_HW_Start(MasterN);
            } else if ((MasterDescr[MasterN].WrBytesRemain == 0) &&
                       (MasterDescr[MasterN].SlaveDescr->EnPEC)) {
                SMBus_HW_PEC(MasterN);
                MasterDescr[MasterN].CurrState = STATE_SEND_PEC;
            } else if (MasterDescr[MasterN].WrBytesRemain == 0) {
                MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
                MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
                SMBus_HW_Stop(MasterN);
            } else {
                MasterDescr[MasterN].WrBytesRemain -= 1;
                SMBus_HW_SetData(MasterN, *MasterDescr[MasterN].WrDataPtr++);
            }
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDANA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HMTDANA))
            SMBus_ErrStop(MasterN, SMBUS_FLAG_DATA_NAK);
        else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_RECV_DATA:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_MRDANA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMRDANA)) {
            if (MasterDescr[MasterN].RdBytesRemain == 1) {
                *MasterDescr[MasterN].RdDataPtr = (uint8_t)SMBus_HW_GetData(MasterN);
                MasterDescr[MasterN].RdBytesRemain -= 1;
                *MasterDescr[MasterN].RdBytes += 1;
                MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
            } else {
                MasterDescr[MasterN].Status = SMBUS_STAT_ERR;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_DATA_NAK;
            }
            MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
            SMBus_HW_Stop(MasterN);
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_MRDAPA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HMRDAPA)) {
            if (((MasterDescr[MasterN].ProtocolType == PROT_BLOCK_READ) ||
                 (MasterDescr[MasterN].ProtocolType == PROT_BLOCK_PROCESS_CALL)) &&
                (MasterDescr[MasterN].RdBytesRemain == 0)) {
                MasterDescr[MasterN].RdBytesRemain = (uint8_t)SMBus_HW_GetData(MasterN);
                *MasterDescr[MasterN].RdBytes = 0;
            } else {
                *MasterDescr[MasterN].RdDataPtr = (uint8_t)SMBus_HW_GetData(MasterN);
                MasterDescr[MasterN].RdDataPtr++;
                *MasterDescr[MasterN].RdBytes += 1;
                MasterDescr[MasterN].RdBytesRemain -= 1;
            }
            if ((MasterDescr[MasterN].RdBytesRemain == 1) &&
                (MasterDescr[MasterN].SlaveDescr->EnPEC == 0))
                SMBus_HW_NACK(MasterN);
            if ((MasterDescr[MasterN].RdBytesRemain == 0) &&
                (MasterDescr[MasterN].SlaveDescr->EnPEC)) {
                SMBus_HW_NACK(MasterN);
                SMBus_HW_PEC(MasterN);
                MasterDescr[MasterN].CurrState = STATE_RECV_PEC;
            } else
                MasterDescr[MasterN].CurrState = STATE_RECV_DATA;
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_SEND_PEC:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDAPA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMTDAPA)) {
            MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;
            MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
            MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
            SMBus_HW_Stop(MasterN);
        } else if ((SMBus_HW_GetState(MasterN) == SMBUS_MTDANA) ||
                   (SMBus_HW_GetState(MasterN) == SMBUS_HMTDANA))
            SMBus_ErrStop(MasterN, SMBUS_FLAG_PEC_ERR);
        else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    case STATE_RECV_PEC:
        if ((SMBus_HW_GetState(MasterN) == SMBUS_MRDANA) ||
            (SMBus_HW_GetState(MasterN) == SMBUS_HMRDANA)) {
            if (SMBus_HW_IsPECFail(MasterN)) {
                MasterDescr[MasterN].Status = SMBUS_STAT_ERR;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_PEC_ERR;
            } else {
                MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;
                MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
            }
            MasterDescr[MasterN].CurrState = STATE_SEND_STOP;
            SMBus_HW_Stop(MasterN);
        } else
            SMBus_ErrStop(MasterN, SMBUS_FLAG_HW_UNKNOWN_ERR);
        break;

    default:
        //do nothing
        break;
    }
}

//-- Protocol functions --------------------------------------------------------
SMBus_Status_TypeDef SMBus_QuickWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_QUICK_WRITE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_QuickRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_QUICK_READ;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_RD;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_SendByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint8_t Data)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    WrDataTemp = Data;
    MasterDescr[MasterN].ProtocolType = PROT_SEND_BYTE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = (uint8_t*)&WrDataTemp;
    MasterDescr[MasterN].WrBytes = 1;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_ReceiveByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                       uint8_t* Data)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    RdBytesTemp = 0;
    MasterDescr[MasterN].ProtocolType = PROT_RECEIVE_BYTE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_RD;
    MasterDescr[MasterN].RdDataPtr = Data;
    MasterDescr[MasterN].RdBytes = &RdBytesTemp;
    MasterDescr[MasterN].RdBytesRemain = 1;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_WriteByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t Data, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    WrDataTemp = Data;
    MasterDescr[MasterN].ProtocolType = PROT_WRITE_BYTE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = (uint8_t*)&WrDataTemp;
    MasterDescr[MasterN].WrBytes = 1;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_WriteWord(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint16_t Data, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    WrDataTemp = Data;
    MasterDescr[MasterN].ProtocolType = PROT_WRITE_WORD;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = (uint8_t*)&WrDataTemp;
    MasterDescr[MasterN].WrBytes = 2;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_ReadByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint8_t* Data, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    RdBytesTemp = 0;
    MasterDescr[MasterN].ProtocolType = PROT_READ_BYTE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].RdDataPtr = Data;
    MasterDescr[MasterN].RdBytes = &RdBytesTemp;
    MasterDescr[MasterN].RdBytesRemain = 1;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_ReadWord(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint16_t* Data, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    RdBytesTemp = 0;
    MasterDescr[MasterN].ProtocolType = PROT_READ_WORD;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].RdDataPtr = (uint8_t*)Data;
    MasterDescr[MasterN].RdBytes = &RdBytesTemp;
    MasterDescr[MasterN].RdBytesRemain = 2;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_BlockWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                      uint8_t* Data, uint8_t Bytes, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_BLOCK_WRITE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = Data;
    if (Bytes > SMBUS_BLOCK_BYTES_MAX)
        MasterDescr[MasterN].WrBytes = SMBUS_BLOCK_BYTES_MAX;
    else
        MasterDescr[MasterN].WrBytes = Bytes;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_BlockRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t* Data, uint8_t* Bytes, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_BLOCK_READ;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].RdDataPtr = Data;
    MasterDescr[MasterN].RdBytes = Bytes;
    MasterDescr[MasterN].RdBytesRemain = 0; //this value will be updated after rep start
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_ProcessCall(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                       uint16_t WrData, uint16_t* RdData, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    WrDataTemp = WrData;
    RdBytesTemp = 0;
    MasterDescr[MasterN].ProtocolType = PROT_PROCESS_CALL;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = (uint8_t*)&WrDataTemp;
    MasterDescr[MasterN].WrBytes = 2;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].RdDataPtr = (uint8_t*)RdData;
    MasterDescr[MasterN].RdBytes = &RdBytesTemp;
    MasterDescr[MasterN].RdBytesRemain = 2;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_BlockProcessCall(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                            uint8_t* WrData, uint8_t WrBytes, uint8_t* RdData, uint8_t* RdBytes, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_BLOCK_PROCESS_CALL;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = WrData;
    if (WrBytes > SMBUS_BLOCK_BYTES_MAX)
        MasterDescr[MasterN].WrBytes = SMBUS_BLOCK_BYTES_MAX;
    else
        MasterDescr[MasterN].WrBytes = WrBytes;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].RdDataPtr = RdData;
    MasterDescr[MasterN].RdBytes = RdBytes;
    MasterDescr[MasterN].RdBytesRemain = 0; //this value will be updated after rep start
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

//-- Custom protocol functions -------------------------------------------------
SMBus_Status_TypeDef SMBus_BurstWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                      uint8_t* Data, uint8_t Bytes, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    MasterDescr[MasterN].ProtocolType = PROT_BURST_WRITE;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].WrDataPtr = Data;
    MasterDescr[MasterN].WrBytes = Bytes;
    MasterDescr[MasterN].WrBytesRemain = MasterDescr[MasterN].WrBytes;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

SMBus_Status_TypeDef SMBus_BurstRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t* Data, uint8_t Bytes, uint8_t CmdCode)
{
    // check if line is free and no transactions performed
    if (SMBus_IsMasterBusy(MasterN))
        return SMBUS_STAT_ERR;
    // set transaction
    RdBytesTemp = 0;
    MasterDescr[MasterN].ProtocolType = PROT_BURST_READ;
    MasterDescr[MasterN].SlaveDescr = Slave;
    MasterDescr[MasterN].CurrState = STATE_SEND_START;
    MasterDescr[MasterN].Status = SMBUS_STAT_BUSY;
    MasterDescr[MasterN].ModeRW = MODE_WR;
    MasterDescr[MasterN].RdDataPtr = Data;
    MasterDescr[MasterN].RdBytes = &RdBytesTemp;
    MasterDescr[MasterN].RdBytesRemain = Bytes;
    MasterDescr[MasterN].CmdCode = CmdCode;
    // send start bit
    SMBus_HW_Start(MasterN);
    return MasterDescr[MasterN].Status;
}

//-- Misc functions ------------------------------------------------------------
void SMBus_Init(SMBus_MasterNum_TypeDef MasterN, uint32_t FSFreq, uint32_t HSFreq)
{
    MasterDescr[MasterN].ProtocolType = PROT_ANY;
    MasterDescr[MasterN].CurrState = STATE_ANY;
    MasterDescr[MasterN].Flag = SMBUS_FLAG_OK;
    MasterDescr[MasterN].Status = SMBUS_STAT_IDLE;

    SMBus_HW_Init(MasterN, FSFreq, HSFreq);
}

void SMBus_Callback(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_FSM(MasterN);
    SMBus_HW_ClearIRQ(MasterN);
}

SMBus_Status_TypeDef SMBus_GetStatus(SMBus_MasterNum_TypeDef MasterN, SMBus_Flag_TypeDef* Flag)
{
    *Flag = MasterDescr[MasterN].Flag;
    if (SMBus_HW_IsBusBusy(MasterN))
        return SMBUS_STAT_BUSY;
    else
        return MasterDescr[MasterN].Status;
}
