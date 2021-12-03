#ifdef MCU_K1921VK01T
#include "pin_alt_func_map.h"


GPIO_AltFunc_TypeDef get_alt_func_pwm(NT_GPIO_TypeDef* port, uint32_t pin_msk){
    if(port == NT_GPIOA && (pin_msk & 0xFC00 )){ // A10 - A15
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOB && (pin_msk & 0x1F0 )){//B4 - B8
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOA && (pin_msk & 0xFE )){//A1 - A7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOA && (pin_msk & 0xFE )){//A1 - A7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOE && (pin_msk & GPIO_Pin_2 )){//E2
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOE && (pin_msk & GPIO_Pin_11 )){//E1
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOF && (pin_msk & GPIO_Pin_5 )){//F5
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & 0b11 )){//G0-G1
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & GPIO_Pin_7 )){//G7
        return GPIO_AltFunc_2;
    }
    if(port == NT_GPIOG && (pin_msk & 0xE000 )){//G13-G15
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOH && (pin_msk & 0b11)){//H0-H1
        return GPIO_AltFunc_3;
    }
    if(port == NT_GPIOH && (pin_msk & 0b11)){//H0-H1
        return GPIO_AltFunc_3;
    }
    return GPIO_AltFunc_1;
}

#endif