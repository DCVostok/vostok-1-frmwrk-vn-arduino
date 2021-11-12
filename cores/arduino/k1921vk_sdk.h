#ifndef K1921VK_SDK_H
#define K1921VK_SDK_H

#define MCU_K1921VK035

#ifdef MCU_K1921VK035 
    #include "system_K1921VK035.h"
    #include "plib035.h"
#elif MCU_K1921VK01T
    #include "system_K1921VK01T.h"
    #include "niietcm4.h"
#else
    #error "MCU_* not defined"
#endif

#endif// K1921VK_SDK_H