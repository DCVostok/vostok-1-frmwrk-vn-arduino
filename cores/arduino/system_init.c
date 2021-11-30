#include "Arduino.h"
#include "k1921vk_sdk.h"

//irq freq 1 Mhz and irq period 1 microsecond
#define SYSTICK_IRQ_FREQ (1000)

void init(){
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock/SYSTICK_IRQ_FREQ);

    #ifdef MCU_K1921VK035
        RCU_AHBClkCmd(RCU_AHBClk_GPIOA, ENABLE);
        RCU_AHBRstCmd(RCU_AHBRst_GPIOA, ENABLE);
        RCU_AHBClkCmd(RCU_AHBClk_GPIOB, ENABLE);
        RCU_AHBRstCmd(RCU_AHBRst_GPIOB, ENABLE);
    #elif MCU_K1921VK01T
        // хак, чтобы избежать зависших секвенсоров от выставленных запросов по 0 каналу АЦП
        // цифровыми компараторами. 
        for (uint32_t i = 0; i < 24; i++)
        {
            ADC_DC_DeInit((ADC_DC_Module_TypeDef)i);
        }
    #endif
    analogReadResolution(ADC_RESOLUTION);

}

void initVariant(){

}