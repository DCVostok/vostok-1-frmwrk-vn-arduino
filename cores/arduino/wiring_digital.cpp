#include "Arduino.h"
#include "wiring_private.h"

#ifdef __cplusplus
extern "C" {
#endif
#define INPUT_FILTER_SAMPLE_PEROD 50



void pinMode( pin_size_t ulPin, PinMode ulMode ){
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(ulPin);
  if(pin_description == NULL){
    return;
  }

  GPIO_Init_TypeDef gpio_init_struct;
  GPIO_StructInit(&gpio_init_struct);

  #ifdef MCU_K1921VK035
    gpio_init_struct.Pin = pin_description->pin_msk;
    gpio_init_struct.Out = ulMode  == OUTPUT || ulMode  == OUTPUT_OPENDRAIN ? ENABLE : DISABLE;
    gpio_init_struct.AltFunc = DISABLE;
    gpio_init_struct.OutMode = ulMode  == OUTPUT_OPENDRAIN ? GPIO_OutMode_OD : GPIO_OutMode_PP;
    gpio_init_struct.InMode = GPIO_InMode_Schmitt;
    gpio_init_struct.PullMode = ulMode == INPUT_PULLUP ?   GPIO_PullMode_PU:
                                ulMode == INPUT_PULLDOWN ? GPIO_PullMode_PD:
                                                           GPIO_PullMode_Disable;
    gpio_init_struct.DriveMode = GPIO_DriveMode_HighFast;
    gpio_init_struct.Digital = ENABLE;
  #elif MCU_K1921VK01T
    gpio_init_struct.GPIO_AltFunc = GPIO_AltFunc_1;
    gpio_init_struct.GPIO_Dir = ulMode  == OUTPUT || ulMode  == OUTPUT_OPENDRAIN ? GPIO_Dir_Out : GPIO_Dir_In;
    gpio_init_struct.GPIO_Mode = GPIO_Mode_IO;
    gpio_init_struct.GPIO_Out = ulMode  == OUTPUT || ulMode  == OUTPUT_OPENDRAIN ? GPIO_Out_En : GPIO_Out_Dis;
    gpio_init_struct.GPIO_OutMode =  ulMode  == OUTPUT_OPENDRAIN ? GPIO_OutMode_OD : GPIO_OutMode_PP;
    gpio_init_struct.GPIO_PullUp = ulMode == INPUT_PULLUP ?   GPIO_PullUp_En:
                                   ulMode == INPUT_PULLDOWN ? GPIO_PullUp_Dis:
                                                           GPIO_PullUp_Dis;;
    gpio_init_struct.GPIO_Pin = pin_description->pin_msk;
  #endif
  GPIO_QualSampleConfig(pin_description->port,INPUT_FILTER_SAMPLE_PEROD);
  GPIO_QualModeConfig(pin_description->port,pin_description->pin_msk,GPIO_QualMode_6Sample);
  GPIO_QualCmd(pin_description->port,pin_description->pin_msk,ENABLE);

  GPIO_Init(pin_description->port,&gpio_init_struct);
  return;
}

void digitalWrite( pin_size_t ulPin, PinStatus ulVal )
{

  const PinDescription *pin_description = PIN_GET_DESCRIPTION(ulPin);
  if(pin_description == NULL){
    return;
  }
  digital_pin_use_hook(ulPin);
  if(ulVal == LOW){
    GPIO_ClearBits(pin_description->port, pin_description->pin_msk);
  }
  else{
    GPIO_SetBits(pin_description->port, pin_description->pin_msk);
  }
  
  return;
}

PinStatus digitalRead( pin_size_t ulPin )
{
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(ulPin);
  if(pin_description == NULL){
    return LOW;
  }
  digital_pin_use_hook(ulPin);
  return GPIO_ReadBit(pin_description->port, pin_description->pin_msk) ? HIGH: LOW;
}

GPIO_TypeDef * digitalPinToPort(pin_size_t ulPin){
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(ulPin);
  if(pin_description == NULL){
    return 0;
  }
  digital_pin_use_hook(ulPin);
  return pin_description->port;
}
uint32_t digitalPinToBitMask(pin_size_t ulPin){
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(ulPin);
  if(pin_description == NULL){
    return 0;
  }
  digital_pin_use_hook(ulPin);
  return pin_description->pin_msk;
}

uint32_t * portOutputRegister(GPIO_TypeDef * gpio){

  return (uint32_t *)(&(gpio->DATAOUT));
}
uint32_t * portInputRegister(GPIO_TypeDef * gpio){

  return (uint32_t *)(&(gpio->DATAOUT));
}

#ifdef __cplusplus
}
#endif
