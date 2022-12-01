#include "Arduino.h"
#include "k1921vk_sdk.h"
#ifdef __cplusplus
extern "C" {
#endif

uint32_t ticks_ms = 0; // ticks in milliseconds

void SysTick_Handler(){
    ticks_ms++;
}

uint32_t millis(void){
    volatile uint32_t ticks_ms_readed;
    __disable_irq();
    ticks_ms_readed = ticks_ms;
    __enable_irq();
    return ticks_ms_readed;
}

uint8_t SysTick_read_count_flag(){
    return ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == (SysTick_CTRL_COUNTFLAG_Msk));
}
// Interrupt-compatible version of micros
uint32_t micros(void){
  SysTick_read_count_flag();
  uint32_t m = millis();
  uint32_t tms = SysTick->LOAD + 1;
  uint32_t u = tms - SysTick->VAL;
  if (SysTick_read_count_flag()) {
    m = millis();
    u = tms - SysTick->VAL;
  }
  return (m * 1000 + (u * 1000) / tms);
}

void delay(uint32_t ms)
{
  if (ms != 0) {
    uint32_t start = millis();
    do {
      yield();
    } while (millis() - start < ms);
  }
}


void delayMicroseconds(unsigned int us){
  uint32_t currentTicks = SysTick->VAL;
  /* Number of ticks per millisecond */
  uint32_t tickPerMs = SysTick->LOAD + 1;
  /* Number of ticks to count */
  uint32_t nbTicks = ((us - ((us > 0) ? 1 : 0)) * tickPerMs) / 1000;
  /* Number of elapsed ticks */
  uint32_t elapsedTicks = 0;
  uint32_t oldTicks = currentTicks;
  do {
    currentTicks = SysTick->VAL;
    elapsedTicks += (oldTicks < currentTicks) ? tickPerMs + oldTicks - currentTicks :
                    oldTicks - currentTicks;
    oldTicks = currentTicks;
  } while (nbTicks > elapsedTicks);
}

#ifdef __cplusplus
}
#endif

