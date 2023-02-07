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
  uint16_t      pin_attribute;
  uint8_t       adc_ch;
  uint8_t       pwm_ch;

} PinDescription ;



#define PIN_ATTR_NONE                (0UL<<0)
#define PIN_ATTR_COMBO               (1UL<<0)
#define PIN_ATTR_DIGITAL             (1UL<<2)
#define PIN_ATTR_TIMER_IN            (1UL<<4)
#define PIN_ATTR_EXTINT              (1UL<<5)
#define PIN_ATTR_LVL_SHIFTER_CTRL    (1UL<<6)
#define PIN_ATTR_NEED_LS_CTRL        (1UL<<7)

#define PIN_ADC_NONE (0xfe)
#define PIN_ADC_CH_NUM(num) (num)

#define PIN_PWM_NONE (0xfe)
#define PIN_PWM_CH_NUM(num) (num)


typedef struct _PwmChDescription
{
  PWM_TypeDef* pwm;
  uint8_t     pwm_ch;
} PwmChDescription;

#define PWM_CH_DESCRIPTION_CH_A (0)
#define PWM_CH_DESCRIPTION_CH_B (1)

#ifndef PIN_GET_DESCRIPTION
  #define PIN_GET_DESCRIPTION(pinNum) (pinNum <= PINS_COUNT ? &(pins_description_map[pinNum]) : NULL)
#endif

#ifndef PIN_GET_DESCRIPTION_WITH_PWM
  #define PIN_GET_DESCRIPTION_WITH_PWM(pinNum) PIN_GET_DESCRIPTION(pinNum)
#endif

#ifndef PIN_GET_DESCRIPTION_WITH_ADC
  #define PIN_GET_DESCRIPTION_WITH_ADC(pinNum) PIN_GET_DESCRIPTION(pinNum)
#endif

/* Pins table to be instantiated into variant.cpp */
extern const PinDescription pins_description_map[] ; // key - arduino pin num
extern const pin_size_t adc_ls_ctrl_map[]; // key - ADC_CH_NUM

void digital_pin_use_hook(pin_size_t pin_num);
void analog_pin_use_hook(pin_size_t pin_num);


#ifdef __cplusplus
} // extern "C"
#endif
#endif//WVARIANT_H