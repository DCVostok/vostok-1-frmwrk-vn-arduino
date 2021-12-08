#ifndef K1921VK_SDK_H
#define K1921VK_SDK_H



#ifdef MCU_K1921VK035 
    #include "system_K1921VK035.h"
    #include "plib035.h"
#elif MCU_K1921VK01T
    #include "system_K1921VK01T.h"
    #include "niietcm4.h"
    #include "pin_alt_func_map.h"
    typedef NT_UART_TypeDef UART_TypeDef;
    typedef NT_GPIO_TypeDef GPIO_TypeDef;
    typedef NT_PWM_TypeDef  PWM_TypeDef;
    typedef NT_I2C_TypeDef I2C_TypeDef;
    typedef NT_SPI_TypeDef SPI_TypeDef;
    
    
#else
    #error "MCU_* not defined"
#endif

#endif// K1921VK_SDK_H