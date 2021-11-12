/*==============================================================================
 * Файл конфигурации USB
 *------------------------------------------------------------------------------
 * НИИЭТ, Дмитрий Сериков <lonie@niiet.ru>
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_CONF_H
#define __USB_CONF_H

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
#include "K1921VK01T.h"
#include "usb_const.h"

/* Exported defines ----------------------------------------------------------*/

/* Выбор режима работы */
#if !(defined(USE_HOST_MODE) || defined(USE_DEVICE_MODE) || defined(USE_OTG_MODE))
//#define USE_HOST_MODE
#define USE_DEVICE_MODE
//#define USE_OTG_MODE
#endif

#if !(defined(USE_USB_DEV_FS) || defined(USE_USB_DEV_HS))
#define USE_USB_DEV_FS
//#define USE_USB_DEV_HS
#endif

#ifdef USE_DEVICE_MODE
    #ifndef USE_USB_DEV_FS
        #ifndef USE_USB_DEV_HS
            #error  "USE_USB_DEV_FS or USE_USB_DEV_HS should be defined"
        #endif
    #endif
#elif defined USE_HOST_MODE

#elif defined USE_OTG_MODE

#else
    #error  "USE_OTG_MODE or USE_DEVICE_MODE or USE_HOST_MODE should be defined"
#endif

#define LOBYTE(x)   ((unsigned char)(x & 0x00FF))
#define HIBYTE(x)   ((unsigned char)((x & 0xFF00) >>8))
#define MIN(a, b)   (((a) < (b)) ? (a) : (b))

#endif /* __USB_CONF_H */
