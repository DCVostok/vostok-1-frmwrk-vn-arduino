/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "wiring_private.h"


#define TONE_MAX_FREQ (SystemCoreClock / 2)
uint32_t lastOutputPin = 0xFFFFFFFF;

GPIO_TypeDef* gpio_port;
volatile uint32_t gpio_pin_msk;
volatile int64_t toggleCount;
volatile bool toneIsActive = false;
volatile bool firstTimeRunning = false;

#ifdef MCU_K1921VK035
  #define TONE_TIMER      TMR2
  #define TONE_TIMER_IRQ  TMR2_IRQn
  #define TONE_TIMER_RCU_RST  RCU_APBRst_TMR2
  #define TONE_TIMER_RCU_CLK  RCU_APBClk_TMR2
  #define TONE_TIMER_ITStatusClear(timer)TMR_ITStatusClear(timer)
  #define TONE_IRQHandler TMR2_IRQHandler
#elif MCU_K1921VK01T
  #define TONE_TIMER      NT_TIMER2
  #define TONE_TIMER_IRQ  TIM2_IRQn
  #define TONE_TIMER_RCC_PERIPH_RST  RCC_PeriphRst_Timer2
  #define TONE_TIMER_ITStatusClear(timer)TIMER_ITStatusClear(timer)
  #define TONE_IRQHandler TIM2_IRQHandler
#endif





void inline reset_timer(){
  
  NVIC_DisableIRQ(TONE_TIMER_IRQ);
  NVIC_ClearPendingIRQ(TONE_TIMER_IRQ);
  #ifdef MCU_K1921VK035
    TMR_ITCmd(TONE_TIMER, DISABLE);
    TMR_Cmd(TONE_TIMER, DISABLE);
    TMR_SetCounter(TONE_TIMER,0);
  #elif MCU_K1921VK01T
    TIMER_ITCmd(TONE_TIMER, DISABLE);
    TIMER_Cmd(TONE_TIMER, DISABLE);
    TIMER_SetCounter(TONE_TIMER,0);
  #endif

}

void tone (unsigned char outputPin, unsigned int frequency, unsigned long duration)
{
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(outputPin);
  if(pin_description == NULL){
    return;
  }
  frequency = frequency > TONE_MAX_FREQ ? TONE_MAX_FREQ : frequency;
  digital_pin_use_hook(outputPin);
  // Configure interrupt request
  NVIC_DisableIRQ(TONE_TIMER_IRQ);
  NVIC_ClearPendingIRQ(TONE_TIMER_IRQ);
  
  if(!firstTimeRunning)
  {
    firstTimeRunning = true;
    
    NVIC_SetPriority(TONE_TIMER_IRQ, 0);
    #ifdef MCU_K1921VK035
      RCU_APBClkCmd(TONE_TIMER_RCU_CLK, ENABLE);
      RCU_APBRstCmd(TONE_TIMER_RCU_RST, ENABLE);
    #elif MCU_K1921VK01T
      RCC_PeriphRstCmd(TONE_TIMER_RCC_PERIPH_RST, ENABLE);
    #endif
    
  }
  
  if (toneIsActive && (outputPin != lastOutputPin))
    noTone(lastOutputPin);

  gpio_port = pin_description->port;
  gpio_pin_msk = pin_description->pin_msk;
  toggleCount = (duration > 0 ? frequency * duration * 2 / 1000UL : -1);
  if (outputPin != lastOutputPin)
  {
    lastOutputPin = outputPin;
    digitalWrite(outputPin, LOW);
    pinMode(outputPin, OUTPUT);
    toneIsActive = true;
  }
  reset_timer();
  #ifdef MCU_K1921VK035
    TMR_SetLoad(TONE_TIMER,SystemCoreClock/(frequency*2));
    TMR_ITCmd(TONE_TIMER, ENABLE);
    TMR_Cmd(TONE_TIMER, ENABLE);
  #elif MCU_K1921VK01T
    TIMER_SetReload(TONE_TIMER,SystemCoreClock/frequency);
    TIMER_ITCmd(TONE_TIMER, ENABLE);
    TIMER_Cmd(TONE_TIMER, ENABLE);
  #endif
  
  
  NVIC_EnableIRQ(TONE_TIMER_IRQ);
}

void noTone (uint8_t outputPin)
{
  reset_timer();
  digitalWrite(outputPin, LOW);
  toneIsActive = false;
}

#ifdef __cplusplus
extern "C" {
#endif

void TONE_IRQHandler(){
  if (toggleCount != 0)
  {
    // Toggle the ouput pin
    GPIO_ToggleBits(gpio_port,gpio_pin_msk);

    if (toggleCount > 0){
      --toggleCount;
    }
  }
  else
  {
    reset_timer();
    GPIO_ClearBits(gpio_port,gpio_pin_msk);
    toneIsActive = false;
  }
  #ifdef MCU_K1921VK035
        TMR_ITStatusClear(TONE_TIMER);
  #elif MCU_K1921VK01T
        TIMER_ITStatusClear(TONE_TIMER);
  #endif
}

#ifdef __cplusplus
}
#endif
