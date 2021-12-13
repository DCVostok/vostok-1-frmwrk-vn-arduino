#ifndef K1921VK_SDK_H
#define K1921VK_SDK_H



#ifdef MCU_K1921VK035 
    #include "system_K1921VK035.h"
    #include "plib035.h"
    #define GPIO_PORT_TO_IRQ(port) (port == GPIOA ? GPIOA_IRQn:\
                                    port == GPIOB ? GPIOB_IRQn:\
                                    GPIOA_IRQn)
#elif MCU_K1921VK01T
    #include "system_K1921VK01T.h"
    #include "niietcm4.h"
    #include "pin_alt_func_map.h"
    typedef NT_UART_TypeDef UART_TypeDef;
    typedef NT_GPIO_TypeDef GPIO_TypeDef;
    typedef NT_PWM_TypeDef  PWM_TypeDef;
    typedef NT_I2C_TypeDef I2C_TypeDef;
    typedef NT_SPI_TypeDef SPI_TypeDef;

    #define GPIO_PORT_TO_IRQ(port) (port == NT_GPIOA ? GPIOA_IRQn:\
                                port == NT_GPIOB ? GPIOB_IRQn:\
                                port == NT_GPIOC ? GPIOC_IRQn:\
                                port == NT_GPIOD ? GPIOD_IRQn:\
                                port == NT_GPIOE ? GPIOE_IRQn:\
                                port == NT_GPIOF ? GPIOF_IRQn:\
                                port == NT_GPIOG ? GPIOG_IRQn:\
                                port == NT_GPIOH ? GPIOH_IRQn:\
                                GPIOA_IRQn)
    
    
    
#else
    #error "MCU_* not defined"
#endif

#endif// K1921VK_SDK_H