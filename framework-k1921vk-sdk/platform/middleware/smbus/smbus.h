/*==============================================================================
 * Драйвер SMBus 2.0 для работы с I2C микроконтроллеров К1921ВКx
 *
 * Драйвер реализует основные протоколы Network layer (layer 3) SMBus 2.0
 * спецификации для Master устройства.
 *
 * Поддерживаемые протоколы и режимы:
 *   - Quick command
 *   - Receive/Send byte
 *   - Read/Write byte
 *   - Read/Write word
 *   - Block Read/Write
 *   - Process Call
 *   - Block Process Call
 *   - Packet Error Checking mechanism
 *
 * Нестандартные протоколы:
 *   - Burst Read/Write - аналог Read/Write word, только количество байт не
 *                        жестко задано, а передается параметром
 *
 * Поддержка режимов I2C:
 *   - 10-битный адрес Slave
 *   - HS режим соединения
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

#ifndef __SMBUS_H
#define __SMBUS_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include "smbus_hw.h"
#include <stdio.h>

//-- Defines -------------------------------------------------------------------

//-- Types ---------------------------------------------------------------------
typedef enum {
    SMBUS_FLAG_OK = 0x00,
    SMBUS_FLAG_ADDR_NAK = 0x01,
    SMBUS_FLAG_CMD_DENIED = 0x02,
    SMBUS_FLAG_DATA_NAK = 0x03,
    SMBUS_FLAG_PEC_ERR = 0x04,
    SMBUS_FLAG_MASTERCODE_ERR = 0x05,
    SMBUS_FLAG_HW_UNKNOWN_ERR = 0x06,
} SMBus_Flag_TypeDef;

typedef enum {
    SMBUS_STAT_IDLE = 0x00,
    SMBUS_STAT_BUSY = 0x01,
    SMBUS_STAT_ERR = 0x02
} SMBus_Status_TypeDef;

typedef struct
{
    uint16_t Address;    // slave address
    uint8_t Mastercode;  // 00h - HS off, 0x08-0x0F - HS on
    uint8_t EnAddr10bit; // 0 - false, otherwise - true
    uint8_t EnPEC;       // 0 - false, otherwise - true
} SMBus_SlaveDescriptor_TypeDef;

//-- Functions -----------------------------------------------------------------
// Protocols
SMBus_Status_TypeDef SMBus_QuickRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave);

SMBus_Status_TypeDef SMBus_QuickWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave);

SMBus_Status_TypeDef SMBus_SendByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint8_t Data);

SMBus_Status_TypeDef SMBus_ReceiveByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                       uint8_t* Data);

SMBus_Status_TypeDef SMBus_WriteByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t Data, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_WriteWord(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint16_t Data, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_ReadByte(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint8_t* Data, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_ReadWord(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                    uint16_t* Data, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_BlockWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                      uint8_t* Data, uint8_t Bytes, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_BlockRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t* Data, uint8_t* Bytes, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_ProcessCall(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                       uint16_t WrData, uint16_t* RdData, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_BlockProcessCall(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                            uint8_t* WrData, uint8_t WrBytes, uint8_t* RdData, uint8_t* RdBytes, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_BurstWrite(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                      uint8_t* Data, uint8_t Bytes, uint8_t CmdCode);

SMBus_Status_TypeDef SMBus_BurstRead(SMBus_MasterNum_TypeDef MasterN, SMBus_SlaveDescriptor_TypeDef* Slave,
                                     uint8_t* Data, uint8_t Bytes, uint8_t CmdCode);

// Misc
void SMBus_Init(SMBus_MasterNum_TypeDef MasterN, uint32_t FSFreq, uint32_t HSFreq);
SMBus_Status_TypeDef SMBus_GetStatus(SMBus_MasterNum_TypeDef MasterN, SMBus_Flag_TypeDef* Flag);
void SMBus_Callback(SMBus_MasterNum_TypeDef MasterN);

#ifdef __cplusplus
}
#endif

#endif // __SMBUS_H
