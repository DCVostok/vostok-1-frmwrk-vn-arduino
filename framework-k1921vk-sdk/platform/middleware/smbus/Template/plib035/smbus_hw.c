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

//-- Functions -----------------------------------------------------------------
void SMBus_HW_Init(SMBus_MasterNum_TypeDef MasterN, uint32_t FSFreq, uint32_t HSFreq)
{
    if (MasterN == SMBUS_MASTER0)
    {
        //IO config
        RCU_AHBClkCmd(RCU_AHBClk_GPIOA, ENABLE);
        RCU_AHBRstCmd(RCU_AHBRst_GPIOA, ENABLE);
        GPIO_Init_TypeDef GPIO_InitStruct;
        GPIO_StructInit(&GPIO_InitStruct);
        GPIO_InitStruct.AltFunc = ENABLE;
        GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
        GPIO_InitStruct.OutMode = GPIO_OutMode_OD;
        GPIO_InitStruct.Pin = GPIO_Pin_0 | GPIO_Pin_1;
        GPIO_InitStruct.Digital = ENABLE;
        GPIO_Init(GPIOA, &GPIO_InitStruct);

        //reset & clock init
        RCU_APBClkCmd(RCU_APBClk_I2C, ENABLE);
        RCU_APBRstCmd(RCU_APBRst_I2C, ENABLE);
    }
    //else if (Master == SMBUS_MASTER1) {}

    //config FS mode
    I2C_FSFreqConfig(FSFreq, SMBUS_SYSTEM_FREQ);

    //config HS mode
    I2C_HSFreqConfig(HSFreq, SMBUS_SYSTEM_FREQ);

    //enable module and interrupt
    I2C_Cmd(ENABLE);
    I2C_ITCmd(ENABLE);

    //enable global interrupt
    NVIC_EnableIRQ(I2C_IRQn);
}

uint32_t SMBus_HW_IsBusBusy(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    return I2C_BusBusyStatus();
}

SMBus_HW_State_TypeDef SMBus_HW_GetState(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    return (SMBus_HW_State_TypeDef)I2C_GetState();
}

void SMBus_HW_Start(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    I2C_StartCmd();
}

void SMBus_HW_SetData(SMBus_MasterNum_TypeDef MasterN, uint8_t Data)
{
    (void)MasterN;
    I2C_SetData(Data);
}

uint32_t SMBus_HW_GetData(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    return I2C_GetData();
}

void SMBus_HW_NACK(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    I2C_NACKCmd();
}

void SMBus_HW_ClearIRQ(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    I2C_ITStatusClear();
}

void SMBus_HW_Stop(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    I2C_StopCmd();
}

void SMBus_HW_PEC(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    I2C_PECCmd();
}

uint32_t SMBus_HW_IsPECFail(SMBus_MasterNum_TypeDef MasterN)
{
    (void)MasterN;
    return I2C_PECFailStatus();
}
