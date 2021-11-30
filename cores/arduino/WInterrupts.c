#include "Arduino.h"
#include <gpio_irq_table.h>
uint8_t enabled = 0;
void attachInterrupt(pin_size_t pin, voidFuncPtr callback, PinStatus mode)
{
  attachInterruptParam(pin,callback,mode,NULL);
}

void attachInterruptParam(pin_size_t pin, voidFuncPtrParam callback, PinStatus mode, void* param)
{
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(pin);
   if(pin_description == NULL){
    return;
  }
  GPIO_IntType_TypeDef GPIO_IntType = mode == LOW || mode == HIGH ? GPIO_IntType_Level: GPIO_IntType_Edge;
  GPIO_IntPol_TypeDef GPIO_IntPol = mode == RISING || mode == HIGH ? GPIO_IntPol_Pos: GPIO_IntPol_Neg;

  GPIO_ITConfig(pin_description->port, pin_description->pin_msk, GPIO_IntType, GPIO_IntPol);
  GPIO_ITCmd(pin_description->port, pin_description->pin_msk, ENABLE);
  if (!enabled) {
    gpio_irq_table_init();
    enabled = 1;
  }
  gpio_irq_table_Add_CallBackWithParam(pin_description->port, pin_description->pin_msk,callback,param);
}

void detachInterrupt(pin_size_t pin)
{
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(pin);
   if(pin_description == NULL){
    return;
  }
  GPIO_ITCmd(pin_description->port, pin_description->pin_msk, DISABLE);
  gpio_irq_table_Remove_Callback(pin_description->port, pin_description->pin_msk);
}


