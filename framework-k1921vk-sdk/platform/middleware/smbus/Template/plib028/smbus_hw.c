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
 *                              2018 АО "НИИЭТ"
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
    if (MasterN == SMBUS_MASTER0) {
        //IO config
        RCU_AHBClkCmd(RCU_AHBClk_GPIOC, ENABLE);
        RCU_AHBRstCmd(RCU_AHBRst_GPIOC, ENABLE);
        GPIO_Init_TypeDef GPIO_InitStruct;
        GPIO_StructInit(&GPIO_InitStruct);
        GPIO_InitStruct.AltFuncNum = GPIO_AltFuncNum_1;
        GPIO_InitStruct.AltFunc = ENABLE;
        GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
        GPIO_InitStruct.OutMode = GPIO_OutMode_OD;
        GPIO_InitStruct.Pin = GPIO_Pin_8 | GPIO_Pin_9;
        GPIO_InitStruct.Digital = ENABLE;
        GPIO_Init(GPIOC, &GPIO_InitStruct);

        //reset & clock init
        RCU_APBClk0Cmd(RCU_APBClk0_I2C0, ENABLE);
        RCU_APBRst0Cmd(RCU_APBRst0_I2C0, ENABLE);
    } else if (MasterN == SMBUS_MASTER1) {
        //IO config
        RCU_AHBClkCmd(RCU_AHBClk_GPIOA, ENABLE);
        RCU_AHBRstCmd(RCU_AHBRst_GPIOA, ENABLE);
        GPIO_Init_TypeDef GPIO_InitStruct;
        GPIO_StructInit(&GPIO_InitStruct);
        GPIO_InitStruct.AltFuncNum = GPIO_AltFuncNum_2;
        GPIO_InitStruct.AltFunc = ENABLE;
        GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
        GPIO_InitStruct.OutMode = GPIO_OutMode_OD;
        GPIO_InitStruct.Pin = GPIO_Pin_0 | GPIO_Pin_1;
        GPIO_InitStruct.Digital = ENABLE;
        GPIO_Init(GPIOA, &GPIO_InitStruct);

        //reset & clock init
        RCU_APBClk0Cmd(RCU_APBClk0_I2C1, ENABLE);
        RCU_APBRst0Cmd(RCU_APBRst0_I2C1, ENABLE);
    }

    //config FS mode
    I2C_FSFreqConfig(SMBus_Regs[MasterN], FSFreq, SMBUS_SYSTEM_FREQ);

    //config HS mode
    I2C_HSFreqConfig(SMBus_Regs[MasterN], HSFreq, SMBUS_SYSTEM_FREQ);

    //enable module and interrupt
    I2C_Cmd(SMBus_Regs[MasterN], ENABLE);
    I2C_ITCmd(SMBus_Regs[MasterN], ENABLE);

    //enable global interrupt
    NVIC_EnableIRQ(SMBus_IRQs[MasterN]);
}

uint32_t SMBus_HW_IsBusBusy(SMBus_MasterNum_TypeDef MasterN)
{
    return I2C_BusBusyStatus(SMBus_Regs[MasterN]);
}

SMBus_HW_State_TypeDef SMBus_HW_GetState(SMBus_MasterNum_TypeDef MasterN)
{
    return (SMBus_HW_State_TypeDef)I2C_GetState(SMBus_Regs[MasterN]);
}

void SMBus_HW_Start(SMBus_MasterNum_TypeDef MasterN)
{
    I2C_StartCmd(SMBus_Regs[MasterN]);
}

void SMBus_HW_SetData(SMBus_MasterNum_TypeDef MasterN, uint8_t Data)
{
    I2C_SetData(SMBus_Regs[MasterN], Data);
}

uint32_t SMBus_HW_GetData(SMBus_MasterNum_TypeDef MasterN)
{
    return I2C_GetData(SMBus_Regs[MasterN]);
}

void SMBus_HW_NACK(SMBus_MasterNum_TypeDef MasterN)
{
    I2C_NACKCmd(SMBus_Regs[MasterN]);
}

void SMBus_HW_ClearIRQ(SMBus_MasterNum_TypeDef MasterN)
{
    I2C_ITStatusClear(SMBus_Regs[MasterN]);
}

void SMBus_HW_Stop(SMBus_MasterNum_TypeDef MasterN)
{
    I2C_StopCmd(SMBus_Regs[MasterN]);
}

void SMBus_HW_PEC(SMBus_MasterNum_TypeDef MasterN)
{
    I2C_PECCmd(SMBus_Regs[MasterN]);
}

uint32_t SMBus_HW_IsPECFail(SMBus_MasterNum_TypeDef MasterN)
{
    return I2C_PECFailStatus(SMBus_Regs[MasterN]);
}
