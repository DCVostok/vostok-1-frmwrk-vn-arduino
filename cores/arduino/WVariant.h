#ifndef WVARIANT_H
#define WVARIANT_H

#include "Arduino.h"
#include "k1921vk_sdk.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif


/* Types used for the table below */
typedef struct _PinDescription
{
  GPIO_TypeDef* port;
  uint32_t      pin_msk;
  uint32_t      pin_attribute;
  uint32_t      adc_ch;

} PinDescription ;

#define PIN_ATTR_NONE                (0UL<<0)
#define PIN_ATTR_COMBO               (1UL<<0)
#define PIN_ATTR_ANALOG              (1UL<<1)
#define PIN_ATTR_DIGITAL             (1UL<<2)
#define PIN_ATTR_PWM                 (1UL<<3)
#define PIN_ATTR_TIMER_IN            (1UL<<4)
#define PIN_ATTR_EXTINT              (1UL<<5)
#define PIN_ATTR_LVL_SHIFTER_CTRL    (1UL<<6)
#define PIN_ATTR_NEED_LS_CTRL        (1UL<<7)

#define ADC_NONE 0xfffffffe
#define ADC_CH_NUM(num) (num)

/* Pins table to be instantiated into variant.cpp */
extern const PinDescription pins_description_map[] ; // key - arduino pin num
extern const pin_size_t adc_ls_ctrl_map[]; // key - ADC_CH_NUM



#ifdef __cplusplus
} // extern "C"
#endif
#endif//WVARIANT_H