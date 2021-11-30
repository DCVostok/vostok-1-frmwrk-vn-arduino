
#include "pin_alt_func_map.h"


GPIO_AltFunc_TypeDef get_alt_func_pwm(NT_GPIO_TypeDef* port, uint32_t pin_msk){
    if(port == NT_GPIOA && (pin_msk & 0xFC00 > 0)){ // A10 - A15
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOB && (pin_msk & 0x1F0 > 0)){//B4 - B8
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOA && (pin_msk & 0xFE > 0)){//A1 - A7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOA && (pin_msk & 0xFE > 0)){//A1 - A7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOE && (pin_msk & GPIO_Pin_2 > 0)){//E2
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOE && (pin_msk & GPIO_Pin_11 > 0)){//E1
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOF && (pin_msk & GPIO_Pin_5 > 0)){//F5
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & 0b11 > 0)){//G0-G1
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & GPIO_Pin_7 > 0)){//G7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & 0xE000 > 0)){//G13-G15
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOH && (pin_msk & 0b11 > 0)){//H0-H1
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOH && (pin_msk & 0b11 > 0)){//H0-H1
        return GPIO_AltFunc_3;
    }
    return GPIO_AltFunc_1;
}