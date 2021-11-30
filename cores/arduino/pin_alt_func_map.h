#ifndef PIN_ALT_FUNC_MAP_H
#define PIN_ALT_FUNC_MAP_H
#include "niietcm4.h"


GPIO_AltFunc_TypeDef get_alt_func_pwm(NT_GPIO_TypeDef* port, uint32_t pin_msk);

#endif