/*==============================================================================
 * Драйвер SMBus 2.0 для работы с I2C микроконтроллеров К1921ВКx
 *
 * Шаблон заголовочного файла инициализации I2C периферии микроконтроллера и
 * предоставления интерфейса к аппаратным модулям.
 * Файл необходимо скопировать в директорию с проектом и внести соответсвующие
 * правки.
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
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

#ifndef __SMBUS_HW_H
#define __SMBUS_HW_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include "K1921VK01T.h"
#include "system_K1921VK01T.h"
#include <stdio.h>

//-- Defines -------------------------------------------------------------------
#define SMBUS_SYSTEM_FREQ SystemCoreClock
#define SMBUS_BLOCK_BYTES_MAX 32

//-- Types ---------------------------------------------------------------------
typedef enum {
    SMBUS_MASTER0 = 0,
    SMBUS_MASTER1 = 1,

    //^^^ add masters here ^^^
    SMBUS_MASTERS_TOTAL
} SMBus_MasterNum_TypeDef;

typedef enum {
    SMBUS_IDLE = 0x0UL,     /*!< General - Idle, no valid status information available */
    SMBUS_STDONE = 0x1UL,   /*!< FS master - Start condition generated */
    SMBUS_RSDONE = 0x2UL,   /*!< FS master - Repeated start condition generated */
    SMBUS_IDLARL = 0x3UL,   /*!< FS master - Arbitration lost, unaddressed slave mode entered */
    SMBUS_MTADPA = 0x4UL,   /*!< FS master transmit - Slave address sent, positive ACK */
    SMBUS_MTADNA = 0x5UL,   /*!< FS master transmit - Slave address sent, negative ACK */
    SMBUS_MTDAPA = 0x6UL,   /*!< FS master transmit - Data byte sent, positive ACK */
    SMBUS_MTDANA = 0x7UL,   /*!< FS master transmit - Data byte sent, negative ACK */
    SMBUS_MRADPA = 0x8UL,   /*!< FS master receive - Slave addres sent, positive ACK */
    SMBUS_MRADNA = 0x9UL,   /*!< FS master receive - Slave addres sent, negative ACK */
    SMBUS_MRDAPA = 0xAUL,   /*!< FS master receive - Data byte received, positive ACK */
    SMBUS_MRDANA = 0xBUL,   /*!< FS master receive - Data byte received, negative ACK */
    SMBUS_MTMCER = 0xCUL,   /*!< FS master - Mastercode transmitted, error detected (positive ACK) */
    SMBUS_SRADPA = 0x10UL,  /*!< FS slave receive - Slave address received, positive ACK */
    SMBUS_SRAAPA = 0x11UL,  /*!< FS slave receive - Slave address received after arbitration loss, positive ACK */
    SMBUS_SRDAPA = 0x12UL,  /*!< FS slave receive - Data byte received, positive ACK */
    SMBUS_SRDANA = 0x13UL,  /*!< FS slave receive - Data byte received, negative ACK */
    SMBUS_STADPA = 0x14UL,  /*!< FS slave transmit - Slave address received, positive ACK */
    SMBUS_STAAPA = 0x15UL,  /*!< FS slave transmit - Slave address received, negative ACK */
    SMBUS_STDAPA = 0x16UL,  /*!< FS slave transmit - Data byte sent, positive ACK */
    SMBUS_STDANA = 0x17UL,  /*!< FS slave transmit - Data byte sent, negative ACK */
    SMBUS_SATADP = 0x18UL,  /*!< FS slave transmit alert response - Alert response address received, positive ACK */
    SMBUS_SATAAP = 0x19UL,  /*!< FS slave transmit alert response - Alert response address received after arbitration loss, positive ACK */
    SMBUS_SATDAP = 0x1AUL,  /*!< FS slave transmit alert response - Alert response data byte sent, positive ACK */
    SMBUS_SATDAN = 0x1BUL,  /*!< FS slave transmit alert response - Alert response data byte sent, negative ACK */
    SMBUS_SSTOP = 0x1CUL,   /*!< FS slave - Slave mode stop condition detected */
    SMBUS_SGADPA = 0x1DUL,  /*!< FS slave - Global call address received, positive ACK */
    SMBUS_SDAAPA = 0x1EUL,  /*!< FS slave - Global call address received after arbitration loss, positive ACK */
    SMBUS_BERROR = 0x1FUL,  /*!< General - Bus error detected (invalid start or stop condition */
    SMBUS_HMTMCOK = 0x21UL, /*!< HS master - Master code transmitted OK - switched to HS mode */
    SMBUS_HRSDONE = 0x22UL, /*!< HS master - Repeated start condition generated */
    SMBUS_HIDLARL = 0x23UL, /*!< HS master - Arbitration lost, HS unaddressed slave mode entered */
    SMBUS_HMTADPA = 0x24UL, /*!< HS master transmit - Slave address sent, positive ACK */
    SMBUS_HMTADNA = 0x25UL, /*!< HS master transmit - Slave address sent, negative ACK */
    SMBUS_HMTDAPA = 0x26UL, /*!< HS master transmit - Data byte sent, positive ACK */
    SMBUS_HMTDANA = 0x27UL, /*!< HS master transmit - Data byte sent, negative ACK */
    SMBUS_HMRADPA = 0x28UL, /*!< HS master receive - Slave address sent, positive ACK */
    SMBUS_HMRADNA = 0x29UL, /*!< HS master receive - Slave address sent, negative ACK */
    SMBUS_HMRDAPA = 0x2AUL, /*!< HS master receive - Data byte received, positive ACK */
    SMBUS_HMRDANA = 0x2BUL, /*!< HS master receive - Data byte received, negative ACK */
    SMBUS_HSRADPA = 0x30UL, /*!< HS slave receive - Slave address received, positive ACK */
    SMBUS_HSRDAPA = 0x32UL, /*!< HS slave receive - Data byte received, positive ACK */
    SMBUS_HSRDANA = 0x33UL, /*!< HS slave receive - Data byte received, negative ACK */
    SMBUS_HSTADPA = 0x34UL, /*!< HS slave transmit - Slave address received, positive ACK */
    SMBUS_HSTDAPA = 0x36UL, /*!< HS slave transmit - Data byte sent, positive ACK */
    SMBUS_HSTDANA = 0x37UL, /*!< HS slave transmit - Data byte sent, negative ACK */
} SMBus_HW_State_TypeDef;

//-- Functions -----------------------------------------------------------------
void SMBus_HW_Init(SMBus_MasterNum_TypeDef Master, uint32_t FSFreq, uint32_t HSFreq);
uint32_t SMBus_HW_IsBusBusy(SMBus_MasterNum_TypeDef MasterN);
SMBus_HW_State_TypeDef SMBus_HW_GetState(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_Start(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_SetData(SMBus_MasterNum_TypeDef MasterN, uint8_t Data);
uint32_t SMBus_HW_GetData(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_ClearIRQ(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_Stop(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_NACK(SMBus_MasterNum_TypeDef MasterN);
void SMBus_HW_PEC(SMBus_MasterNum_TypeDef MasterN);
uint32_t SMBus_HW_IsPECFail(SMBus_MasterNum_TypeDef MasterN);

#ifdef __cplusplus
}
#endif

#endif // __SMBUS_HW_H
