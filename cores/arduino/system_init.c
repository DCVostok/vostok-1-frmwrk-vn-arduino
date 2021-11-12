#include "Arduino.h"
#include "k1921vk_sdk.h"

//irq freq 1 Mhz and irq period 1 microsecond
#define SYSTICK_IRQ_FREQ (1000)

void init(){
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock/SYSTICK_IRQ_FREQ);
}

void initVariant(){

}