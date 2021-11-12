/*==============================================================================
 * Инициализация К1921ВК028
 *------------------------------------------------------------------------------
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
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

#ifndef SYSTEM_K1921VK028_H
#define SYSTEM_K1921VK028_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include <stdint.h>

//-- Defines -------------------------------------------------------------------
#ifndef CPE
#define CPE 0
#endif

#define OSICLK_VAL 16000000
#ifndef OSECLK_VAL
#define OSECLK_VAL 0
#endif
#ifndef EXTCLK_VAL
#define EXTCLK_VAL 0
#endif
#define SYSCLK_SWITCH_TIMEOUT 0x100000

#if (CPE == 0)
#define REFCLK_VAL OSICLK_VAL
#define SRCCLK_VAL OSECLK_VAL
#elif (CPE == 1)
#define REFCLK_VAL OSECLK_VAL
#define SRCCLK_VAL OSICLK_VAL
#else
#error "Please define CPE with correct state!"
#endif
#define SRCCLK_STARTUP_TIMEOUT 0x100000

#ifndef TRACEEXTCLK_VAL
#define TRACEEXTCLK_VAL OSECLK_VAL
#endif

#ifndef PLLEXTCLK_VAL
#define PLLEXTCLK_VAL OSECLK_VAL
#endif

//-- Variables -----------------------------------------------------------------
extern uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)
extern uint32_t APB0BusClock;    // APB0 Bus Clock Frequency
extern uint32_t APB1BusClock;    // APB1 Bus Clock Frequency

//-- Functions -----------------------------------------------------------------
// Initialize the System
extern void SystemInit(void);
// Updates the SystemCoreClock with current core Clock retrieved from registers
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_K1921VK028_H
