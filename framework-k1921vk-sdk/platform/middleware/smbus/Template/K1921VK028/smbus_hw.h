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
#include "K1921VK028.h"
#include "system_K1921VK028.h"
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
    SMBUS_IDLE = I2C_ST_MODE_IDLE,       /*!< General - Idle, no valid status information available */
    SMBUS_STDONE = I2C_ST_MODE_STDONE,   /*!< FS master - Start condition generated */
    SMBUS_RSDONE = I2C_ST_MODE_RSDONE,   /*!< FS master - Repeated start condition generated */
    SMBUS_IDLARL = I2C_ST_MODE_IDLARL,   /*!< FS master - Arbitration lost, unaddressed slave mode entered */
    SMBUS_MTADPA = I2C_ST_MODE_MTADPA,   /*!< FS master transmit - Slave address sent, positive ACK */
    SMBUS_MTADNA = I2C_ST_MODE_MTADNA,   /*!< FS master transmit - Slave address sent, negative ACK */
    SMBUS_MTDAPA = I2C_ST_MODE_MTDAPA,   /*!< FS master transmit - Data byte sent, positive ACK */
    SMBUS_MTDANA = I2C_ST_MODE_MTDANA,   /*!< FS master transmit - Data byte sent, negative ACK */
    SMBUS_MRADPA = I2C_ST_MODE_MRADPA,   /*!< FS master receive - Slave addres sent, positive ACK */
    SMBUS_MRADNA = I2C_ST_MODE_MRADNA,   /*!< FS master receive - Slave addres sent, negative ACK */
    SMBUS_MRDAPA = I2C_ST_MODE_MRDAPA,   /*!< FS master receive - Data byte received, positive ACK */
    SMBUS_MRDANA = I2C_ST_MODE_MRDANA,   /*!< FS master receive - Data byte received, negative ACK */
    SMBUS_MTMCER = I2C_ST_MODE_MTMCER,   /*!< FS master - Mastercode transmitted, error detected (positive ACK) */
    SMBUS_SRADPA = I2C_ST_MODE_SRADPA,   /*!< FS slave receive - Slave address received, positive ACK */
    SMBUS_SRAAPA = I2C_ST_MODE_SRAAPA,   /*!< FS slave receive - Slave address received after arbitration loss, positive ACK */
    SMBUS_SRDAPA = I2C_ST_MODE_SRDAPA,   /*!< FS slave receive - Data byte received, positive ACK */
    SMBUS_SRDANA = I2C_ST_MODE_SRDANA,   /*!< FS slave receive - Data byte received, negative ACK */
    SMBUS_STADPA = I2C_ST_MODE_STADPA,   /*!< FS slave transmit - Slave address received, positive ACK */
    SMBUS_STAAPA = I2C_ST_MODE_STAAPA,   /*!< FS slave transmit - Slave address received, negative ACK */
    SMBUS_STDAPA = I2C_ST_MODE_STDAPA,   /*!< FS slave transmit - Data byte sent, positive ACK */
    SMBUS_STDANA = I2C_ST_MODE_STDANA,   /*!< FS slave transmit - Data byte sent, negative ACK */
    SMBUS_SATADP = I2C_ST_MODE_SATADP,   /*!< FS slave transmit alert response - Alert response address received, positive ACK */
    SMBUS_SATAAP = I2C_ST_MODE_SATAAP,   /*!< FS slave transmit alert response - Alert response address received after arbitration loss, positive ACK */
    SMBUS_SATDAP = I2C_ST_MODE_SATDAP,   /*!< FS slave transmit alert response - Alert response data byte sent, positive ACK */
    SMBUS_SATDAN = I2C_ST_MODE_SATDAN,   /*!< FS slave transmit alert response - Alert response data byte sent, negative ACK */
    SMBUS_SSTOP = I2C_ST_MODE_SSTOP,     /*!< FS slave - Slave mode stop condition detected */
    SMBUS_SGADPA = I2C_ST_MODE_SGADPA,   /*!< FS slave - Global call address received, positive ACK */
    SMBUS_SDAAPA = I2C_ST_MODE_SDAAPA,   /*!< FS slave - Global call address received after arbitration loss, positive ACK */
    SMBUS_BERROR = I2C_ST_MODE_BERROR,   /*!< General - Bus error detected (invalid start or stop condition */
    SMBUS_HMTMCOK = I2C_ST_MODE_HMTMCOK, /*!< HS master - Master code transmitted OK - switched to HS mode */
    SMBUS_HRSDONE = I2C_ST_MODE_HRSDONE, /*!< HS master - Repeated start condition generated */
    SMBUS_HIDLARL = I2C_ST_MODE_HIDLARL, /*!< HS master - Arbitration lost, HS unaddressed slave mode entered */
    SMBUS_HMTADPA = I2C_ST_MODE_HMTADPA, /*!< HS master transmit - Slave address sent, positive ACK */
    SMBUS_HMTADNA = I2C_ST_MODE_HMTADNA, /*!< HS master transmit - Slave address sent, negative ACK */
    SMBUS_HMTDAPA = I2C_ST_MODE_HMTDAPA, /*!< HS master transmit - Data byte sent, positive ACK */
    SMBUS_HMTDANA = I2C_ST_MODE_HMTDANA, /*!< HS master transmit - Data byte sent, negative ACK */
    SMBUS_HMRADPA = I2C_ST_MODE_HMRADPA, /*!< HS master receive - Slave address sent, positive ACK */
    SMBUS_HMRADNA = I2C_ST_MODE_HMRADNA, /*!< HS master receive - Slave address sent, negative ACK */
    SMBUS_HMRDAPA = I2C_ST_MODE_HMRDAPA, /*!< HS master receive - Data byte received, positive ACK */
    SMBUS_HMRDANA = I2C_ST_MODE_HMRDANA, /*!< HS master receive - Data byte received, negative ACK */
    SMBUS_HSRADPA = I2C_ST_MODE_HSRADPA, /*!< HS slave receive - Slave address received, positive ACK */
    SMBUS_HSRDAPA = I2C_ST_MODE_HSRDAPA, /*!< HS slave receive - Data byte received, positive ACK */
    SMBUS_HSRDANA = I2C_ST_MODE_HSRDANA, /*!< HS slave receive - Data byte received, negative ACK */
    SMBUS_HSTADPA = I2C_ST_MODE_HSTADPA, /*!< HS slave transmit - Slave address received, positive ACK */
    SMBUS_HSTDAPA = I2C_ST_MODE_HSTDAPA, /*!< HS slave transmit - Data byte sent, positive ACK */
    SMBUS_HSTDANA = I2C_ST_MODE_HSTDANA, /*!< HS slave transmit - Data byte sent, negative ACK */
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
