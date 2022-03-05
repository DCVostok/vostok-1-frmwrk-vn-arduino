/*==============================================================================
 * Драйвер SMBus 2.0 для работы с I2C микроконтроллеров К1921ВКx
 *
 * Шаблон файла с исходным кодом инициализации I2C периферии микроконтроллера и
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

//-- Includes ------------------------------------------------------------------
#include "smbus.h"

//-- Private variables ---------------------------------------------------------
static I2C_TypeDef* SMBus_Regs[SMBUS_MASTERS_TOTAL] = {
    I2C0, // Master 0
    I2C1, // Master 1
};
static const IRQn_Type SMBus_IRQs[SMBUS_MASTERS_TOTAL] = {
    I2C0_IRQn, // Master 0
    I2C1_IRQn, // Master 1
};

//-- Functions -----------------------------------------------------------------
void SMBus_HW_Init(SMBus_MasterNum_TypeDef MasterN, uint32_t FSFreq, uint32_t HSFreq)
{
    uint32_t freq_calc;

    if (MasterN == SMBUS_MASTER0) {
        RCU->HCLKCFG_bit.GPIOCEN = 1;
        RCU->HRSTCFG_bit.GPIOCEN = 1;
        //IO config
        GPIOC->ALTFUNCNUM1_bit.PIN8 = 1;
        GPIOC->ALTFUNCNUM1_bit.PIN9 = 1;
        GPIOC->ALTFUNCSET = (GPIO_ALTFUNCSET_PIN8_Msk |
                             GPIO_ALTFUNCSET_PIN9_Msk);
        GPIOC->PULLMODE |= ((GPIO_PULLMODE_PIN8_PU << GPIO_PULLMODE_PIN8_Pos) |
                            (GPIO_PULLMODE_PIN9_PU << GPIO_PULLMODE_PIN9_Pos));
        GPIOC->OUTMODE |= ((GPIO_OUTMODE_PIN8_OD << GPIO_OUTMODE_PIN8_Pos) |
                           (GPIO_OUTMODE_PIN9_OD << GPIO_OUTMODE_PIN9_Pos));
        GPIOC->DENSET = (GPIO_ALTFUNCSET_PIN8_Msk |
                         GPIO_ALTFUNCSET_PIN9_Msk);
        //reset & clock init
        RCU->PCLKCFG0_bit.I2C0EN = 1;
        RCU->PRSTCFG0_bit.I2C0EN = 1;
    }
    else if (MasterN == SMBUS_MASTER1) {
        RCU->HCLKCFG_bit.GPIOAEN = 1;
        RCU->HRSTCFG_bit.GPIOAEN = 1;
        //IO config
        GPIOA->ALTFUNCNUM0_bit.PIN0 = 2;
        GPIOA->ALTFUNCNUM0_bit.PIN1 = 2;
        GPIOA->ALTFUNCSET = (GPIO_ALTFUNCSET_PIN0_Msk |
                             GPIO_ALTFUNCSET_PIN1_Msk);
        GPIOA->PULLMODE |= ((GPIO_PULLMODE_PIN0_PU << GPIO_PULLMODE_PIN0_Pos) |
                            (GPIO_PULLMODE_PIN1_PU << GPIO_PULLMODE_PIN1_Pos));
        GPIOA->OUTMODE |= ((GPIO_OUTMODE_PIN0_OD << GPIO_OUTMODE_PIN0_Pos) |
                           (GPIO_OUTMODE_PIN1_OD << GPIO_OUTMODE_PIN1_Pos));
        GPIOA->DENSET = (GPIO_ALTFUNCSET_PIN0_Msk |
                         GPIO_ALTFUNCSET_PIN1_Msk);
        //reset & clock init
        RCU->PCLKCFG0_bit.I2C1EN = 1;
        RCU->PRSTCFG0_bit.I2C1EN = 1;
    }

    //config FS mode
    freq_calc = SMBUS_SYSTEM_FREQ / (4 * FSFreq);
    SMBus_Regs[MasterN]->CTL1_bit.SCLFRQ = freq_calc & 0x7F;
    SMBus_Regs[MasterN]->CTL3_bit.SCLFRQ = freq_calc >> 7;
    //config HS mode
    freq_calc = SMBUS_SYSTEM_FREQ / (3 * HSFreq);
    SMBus_Regs[MasterN]->CTL2_bit.HSDIV = freq_calc & 0x0F;
    SMBus_Regs[MasterN]->CTL4_bit.HSDIV = freq_calc >> 4;

    //enable module and interrupt
    SMBus_Regs[MasterN]->CTL1_bit.ENABLE = 1;
    SMBus_Regs[MasterN]->CTL0_bit.INTEN = 1;

    //enable global interrupt
    NVIC_EnableIRQ(SMBus_IRQs[MasterN]);
}

uint32_t SMBus_HW_IsBusBusy(SMBus_MasterNum_TypeDef MasterN)
{
    return SMBus_Regs[MasterN]->CST_bit.BB;
}

SMBus_HW_State_TypeDef SMBus_HW_GetState(SMBus_MasterNum_TypeDef MasterN)
{
    return (SMBus_HW_State_TypeDef)SMBus_Regs[MasterN]->ST_bit.MODE;
}

void SMBus_HW_Start(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_Regs[MasterN]->CTL0_bit.START = 1;
}

void SMBus_HW_SetData(SMBus_MasterNum_TypeDef MasterN, uint8_t Data)
{
    SMBus_Regs[MasterN]->SDA = Data;
}

uint32_t SMBus_HW_GetData(SMBus_MasterNum_TypeDef MasterN)
{
    return SMBus_Regs[MasterN]->SDA;
}

void SMBus_HW_NACK(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_Regs[MasterN]->CTL0_bit.ACK = 1;
}

void SMBus_HW_ClearIRQ(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_Regs[MasterN]->CTL0_bit.CLRST = 1;
}

void SMBus_HW_Stop(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_Regs[MasterN]->CTL0_bit.STOP = 1;
}

void SMBus_HW_PEC(SMBus_MasterNum_TypeDef MasterN)
{
    SMBus_Regs[MasterN]->CST_bit.PECNEXT = 1;
}

uint32_t SMBus_HW_IsPECFail(SMBus_MasterNum_TypeDef MasterN)
{
    return SMBus_Regs[MasterN]->CST_bit.PECFAULT;
}
