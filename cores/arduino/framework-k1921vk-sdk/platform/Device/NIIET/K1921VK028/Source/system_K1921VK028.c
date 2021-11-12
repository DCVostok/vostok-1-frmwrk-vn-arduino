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

//-- Includes ------------------------------------------------------------------
#include "system_K1921VK028.h"
#include "K1921VK028.h"

//-- Variables -----------------------------------------------------------------
uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)
uint32_t APB0BusClock;    // APB0 Bus Clock Frequency
uint32_t APB1BusClock;    // APB1 Bus Clock Frequency

//-- Functions -----------------------------------------------------------------
void SystemCoreClockUpdate(void)
{
    uint32_t current_sysclk;
    uint32_t pll_div1, pll_div2, pll_fbdiv, pll_refdiv, pll_refclk, pll_div = 1;

    current_sysclk = RCU->SYSCLKSTAT_bit.SYSSTAT;

    switch (current_sysclk) {
    case RCU_SYSCLKSTAT_SYSSTAT_REFCLK:
        SystemCoreClock = REFCLK_VAL;
        break;
    case RCU_SYSCLKSTAT_SYSSTAT_SRCCLK:
        SystemCoreClock = SRCCLK_VAL;
        break;
    case RCU_SYSCLKSTAT_SYSSTAT_PLLDIVCLK:
    case RCU_SYSCLKSTAT_SYSSTAT_PLLCLK:
        if (current_sysclk == RCU_SYSCLKSTAT_SYSSTAT_PLLDIVCLK)
            pll_div = RCU->PLLDIV_bit.DIV + 1;
        pll_div1 = RCU->PLLCFG_bit.DIV1;
        pll_div2 = RCU->PLLCFG_bit.DIV2;
        pll_fbdiv = RCU->PLLCFG_bit.FBDIV;
        pll_refdiv = RCU->PLLCFG_bit.REFDIV;
        if (RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_OSICLK)
            pll_refclk = OSICLK_VAL;
        else if (RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_OSECLK)
            pll_refclk = OSECLK_VAL;
        else // (RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_PLLEXTCLK)
            pll_refclk = PLLEXTCLK_VAL;
        SystemCoreClock = (pll_refclk * pll_fbdiv) / (pll_refdiv * pll_div1 * pll_div2 * pll_div);
        break;
    }

    APB0BusClock = SystemCoreClock / (1 << RCU->APBCFG_bit.DIV);
    APB1BusClock = SystemCoreClock;
}

void ClkInit()
{
    uint32_t timeout_counter = 0;
    uint32_t sysclk_source;

//clockout control
#ifndef CKO_NONE
    //D0 clockout
    RCU->HCLKCFG_bit.GPIODEN = 1;
    RCU->HRSTCFG_bit.GPIODEN = 1;
    GPIOD->ALTFUNCNUM0_bit.PIN0 = 2;
    GPIOD->ALTFUNCSET_bit.PIN0 = 1;
    GPIOD->DENSET_bit.PIN0 = 1;
#endif

#if defined CKO_REF
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_REFCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = REFCLK
#elif defined CKO_SRC
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_SRCCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = SRCCLK
#elif defined CKO_SYS
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_SYSCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (3 << RCU_CLKOUTCFG_DIVN_Pos) |
                     (RCU_CLKOUTCFG_DIVEN_Msk) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = SYSCLK/8
#elif defined CKO_PLL
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_PLLCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
                     (3 << RCU_CLKOUTCFG_DIVN_Pos) |
                     (RCU_CLKOUTCFG_DIVEN_Msk) |
                     (RCU_CLKOUTCFG_CLKEN_Msk); //CKO = PLLCLK/8
#endif

//wait till oscillator is ready
#if defined OSECLK_VAL && (OSECLK_VAL != 0) && (CPE == 0)
    while ((!RCU->SYSCLKSTAT_bit.SRCCLKOK) && (timeout_counter < SRCCLK_STARTUP_TIMEOUT))
        timeout_counter++;
    if (timeout_counter == SRCCLK_STARTUP_TIMEOUT)
        while (1) {
        };
#endif

//select system clock
#ifdef SYSCLK_PLL
    //PLLCLK = (REFSRC/REFDIV) * (FBDIV/(DIV1*DIV2))
    uint32_t pllcfg_clr = (RCU_PLLCFG_REFSRC_Msk |
                           RCU_PLLCFG_REFDIV_Msk |
                           RCU_PLLCFG_DIV1_Msk |
                           RCU_PLLCFG_DIV2_Msk);
    RCU->PLLCFG_bit.BP = 0;
#if (OSECLK_VAL == 8000000)
    RCU->PLLCFG_bit.FBDIV = 100;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG |= (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                   (1 << RCU_PLLCFG_REFDIV_Pos) |
                   (4 << RCU_PLLCFG_DIV1_Pos) |
                   (1 << RCU_PLLCFG_DIV2_Pos);
#elif (OSECLK_VAL == 12000000)
    RCU->PLLCFG_bit.FBDIV = 50;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_REFDIV_Pos) |
                  (3 << RCU_PLLCFG_DIV1_Pos) |
                  (1 << RCU_PLLCFG_DIV2_Pos);
#elif (OSECLK_VAL == 16000000)
    RCU->PLLCFG_bit.FBDIV = 50;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_REFDIV_Pos) |
                  (4 << RCU_PLLCFG_DIV1_Pos) |
                  (1 << RCU_PLLCFG_DIV2_Pos);
#elif (OSECLK_VAL == 20000000)
    RCU->PLLCFG_bit.FBDIV = 40;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_REFDIV_Pos) |
                  (4 << RCU_PLLCFG_DIV1_Pos) |
                  (1 << RCU_PLLCFG_DIV2_Pos);
#elif (OSECLK_VAL == 24000000)
    RCU->PLLCFG_bit.FBDIV = 50;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (2 << RCU_PLLCFG_REFDIV_Pos) |
                  (3 << RCU_PLLCFG_DIV1_Pos) |
                  (1 << RCU_PLLCFG_DIV2_Pos);
#elif defined EXTCLK_VAL && (EXTCLK_VAL != 0)
    //for example, if EXTCLK = 10000000
    RCU->PLLCFG_bit.FBDIV = 60;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_EXTCLK << RCU_PLLCFG_REFSRC_Pos) |
                  (2 << RCU_PLLCFG_REFDIV_Pos) |
                  (3 << RCU_PLLCFG_DIV1_Pos) |
                  (1 << RCU_PLLCFG_DIV2_Pos);
#else
#error "Please define OSECLK_VAL or EXTCLK_VAL with correct values!"
#endif
    RCU->PLLCFG_bit.OUTDIS = 0;
    while (!RCU->PLLCFG_bit.LOCK) {
    };
    // additional waitstates
    MFLASH->CTRL = (7 << MFLASH_CTRL_LAT_Pos);
    BFLASH->CTRL = (7 << BFLASH_CTRL_LAT_Pos);
    //apb0 div by 2
    RCU->APBCFG_bit.DIV = 1;
    //select PLL as source system clock
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_PLLCLK;
#elif defined SYSCLK_REF
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_REFCLK;
#elif defined SYSCLK_SRC
    sysclk_source = RCU_SYSCLKCFG_SYSSEL_SRCCLK;
#else
#error "Please define SYSCLK source (SYSCLK_PLL | SYSCLK_REF | SYSCLK_SRC)!"
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
    MFLASH->CTRL |= (MFLASH_CTRL_DCEN_Msk) | (MFLASH_CTRL_ICEN_Msk);
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
