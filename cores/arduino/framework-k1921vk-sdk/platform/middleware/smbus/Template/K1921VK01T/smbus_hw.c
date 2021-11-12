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
static NT_I2C_TypeDef* SMBus_Regs[SMBUS_MASTERS_TOTAL] = {
    NT_I2C0, // Master 0
    NT_I2C1, // Master 1
};
static const IRQn_Type SMBus_IRQs[SMBUS_MASTERS_TOTAL] = {
    I2C0_IRQn, // Master 0
    I2C1_IRQn, // Master 0
};

//-- Functions -----------------------------------------------------------------
void SMBus_HW_Init(SMBus_MasterNum_TypeDef MasterN, uint32_t FSFreq, uint32_t HSFreq)
{
    uint32_t freq_calc;

    if (MasterN == SMBUS_MASTER0) {
        //IO config
        NT_COMMON_REG->GPIOPCTLG_bit.PIN0 = 0; //af1 G0 (SDA)
        NT_COMMON_REG->GPIOPCTLF_bit.PIN5 = 0; //af1 F5 (SCL)
        NT_GPIOG->ALTFUNCSET = 1<<0;
        NT_GPIOF->ALTFUNCSET = 1<<5;
        NT_COMMON_REG->GPIODENG |= 1<<0;
        NT_COMMON_REG->GPIODENF |= 1<<5;

        //reset & clock init
        NT_COMMON_REG->APB_CLK_bit.I2CEN0 = 1;
        NT_COMMON_REG->PER_RST0_bit.I2CRST0 = 1;
    }
    else if (MasterN == SMBUS_MASTER1) {
        //IO config
        NT_COMMON_REG->GPIOPCTLD_bit.PIN10 = 1; //af2 D10 (SDA)
        NT_COMMON_REG->GPIOPCTLD_bit.PIN9 = 1; //af2 D9 (SCL)
        NT_GPIOD->ALTFUNCSET = (1<<10) | (1<<9);
        NT_COMMON_REG->GPIODENG |= (1<<10) | (1<<9);

        //reset & clock init
        NT_COMMON_REG->APB_CLK_bit.I2CEN0 = 1;
        NT_COMMON_REG->PER_RST0_bit.I2CRST0 = 1;
    }

    //config FS mode
    freq_calc = SMBUS_SYSTEM_FREQ / (4 * FSFreq);
    SMBus_Regs[MasterN]->CTL1_bit.SCLFRQ = freq_calc & 0x7F;
    //config HS mode
    freq_calc = SMBUS_SYSTEM_FREQ / (3 * HSFreq);
    SMBus_Regs[MasterN]->CTL2_bit.HSDIV = freq_calc & 0x0F;

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
