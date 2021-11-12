/*==============================================================================
 * Инициализация К1921ВК035
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

//-- Includes ------------------------------------------------------------------
#include "system_K1921VK035.h"
#include "K1921VK035.h"

//-- Variables -----------------------------------------------------------------
uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)

//-- Functions -----------------------------------------------------------------
void SystemCoreClockUpdate(void)
{
    uint32_t current_sysclk;
    uint32_t pll_n, pll_m, pll_od, pll_refclk, pll_div = 1;

    current_sysclk = RCU->SYSCLKSTAT_bit.SYSSTAT;

    switch (current_sysclk) {
    case RCU_SYSCLKSTAT_SYSSTAT_OSICLK:
        SystemCoreClock = OSICLK_VAL;
        break;
    case RCU_SYSCLKSTAT_SYSSTAT_OSECLK:
        SystemCoreClock = OSECLK_VAL;
        break;
    case RCU_SYSCLKSTAT_SYSSTAT_PLLDIVCLK:
    case RCU_SYSCLKSTAT_SYSSTAT_PLLCLK:
        if (current_sysclk == RCU_SYSCLKSTAT_SYSSTAT_PLLDIVCLK)
            pll_div = RCU->PLLDIV_bit.DIV + 1;
        pll_n = RCU->PLLCFG_bit.N;
        pll_m = RCU->PLLCFG_bit.M;
        pll_od = RCU->PLLCFG_bit.OD;
        if (RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_OSICLK)
            pll_refclk = OSICLK_VAL;
        else // RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_OSECLK
            pll_refclk = OSECLK_VAL;
        SystemCoreClock = (pll_refclk * pll_m) / (pll_n * (1 << pll_od) * pll_div);
        break;
    }
}

void ClkInit()
{
    uint32_t timeout_counter = 0;
    uint32_t sysclk_source;

//clockout control
#if defined CKO_OSI
    SIU->CLKOUTCTL = SIU_CLKOUTCTL_CLKOUTEN_Msk;
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_OSICLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = OSICLK
#elif defined CKO_OSE && (OSECLK_VAL != 0)
    SIU->CLKOUTCTL = SIU_CLKOUTCTL_CLKOUTEN_Msk;
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_OSECLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = OSECLK
#elif defined CKO_PLL
    SIU->CLKOUTCTL = SIU_CLKOUTCTL_CLKOUTEN_Msk;
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_PLLCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (1 << RCU_CLKOUTCFG_DIVN_Pos) |
                     (RCU_CLKOUTCFG_DIVEN_Msk) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = PLLCLK/4
#endif

//wait till external oscillator is ready
#if defined OSECLK_VAL && (OSECLK_VAL != 0)
    while ((!RCU->SYSCLKSTAT_bit.OSECLKOK) && (timeout_counter < OSECLK_STARTUP_TIMEOUT))
        timeout_counter++;
    if (timeout_counter == OSECLK_STARTUP_TIMEOUT) //OSE failed to startup
        while (1) {
        };
#endif

//select system clock
#ifdef SYSCLK_PLL
//PLLCLK = REFSRC * (M/N) * (1/(2^OD))
#if (OSECLK_VAL == 8000000)
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_N_Pos) |
                  (25 << RCU_PLLCFG_M_Pos);
#elif (OSECLK_VAL == 12000000)
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (3 << RCU_PLLCFG_N_Pos) |
                  (50 << RCU_PLLCFG_M_Pos);
#elif (OSECLK_VAL == 16000000)
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (2 << RCU_PLLCFG_N_Pos) |
                  (25 << RCU_PLLCFG_M_Pos);
#elif (OSECLK_VAL == 20000000)
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (2 << RCU_PLLCFG_N_Pos) |
                  (20 << RCU_PLLCFG_M_Pos);
#elif (OSECLK_VAL == 24000000)
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (3 << RCU_PLLCFG_N_Pos) |
                  (25 << RCU_PLLCFG_M_Pos);
#elif defined OSICLK_VAL
    RCU->PLLCFG = (RCU_PLLCFG_REFSRC_OSICLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_N_Pos) |
                  (25 << RCU_PLLCFG_M_Pos);
#else
#error "Please define OSICLK_VAL and OSECLK_VAL with correct values!"
#endif
    RCU->PLLCFG |= (1 << RCU_PLLCFG_OD_Pos) |
                   (RCU_PLLCFG_OUTEN_Msk);
    while (!RCU->PLLCFG_bit.LOCK) {
    };
    // additional waitstates
    MFLASH->CTRL = (3 << MFLASH_CTRL_LAT_Pos);
    //select PLL as source system clock
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_PLLCLK;
#elif defined SYSCLK_OSI
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_OSICLK;
#elif defined SYSCLK_OSE
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_OSECLK;
#else
#error "Please define SYSCLK source (SYSCLK_PLL | SYSCLK_OSI | SYSCLK_OSE)!"
#endif

    //switch sysclk
    RCU->SYSCLKCFG = (sysclk_source << RCU_SYSCLKCFG_SYSSEL_Pos);
    // Wait switching done
    timeout_counter = 0;
    while ((RCU->SYSCLKSTAT_bit.SYSSTAT != RCU->SYSCLKCFG_bit.SYSSEL) && (timeout_counter < SYSCLK_SWITCH_TIMEOUT))
        timeout_counter++;
    if (timeout_counter == SYSCLK_SWITCH_TIMEOUT) //SYSCLK failed to switch
        while (1) {
        };

    //flush and enable cache
    MFLASH->CTRL_bit.IFLUSH = 1;
    while (MFLASH->ICSTAT_bit.BUSY) {
    };
    MFLASH->CTRL_bit.DFLUSH = 1;
    while (MFLASH->DCSTAT_bit.BUSY) {
    };
    MFLASH->CTRL |= (MFLASH_CTRL_DCEN_Msk) | (MFLASH_CTRL_ICEN_Msk) | (MFLASH_CTRL_PEN_Msk);
}

void FPUInit()
{
    SCB->CPACR = 0x00F00000;
    __DSB();
    __ISB();
}
void SystemInit(void)
{
    ClkInit();
    FPUInit();
}
