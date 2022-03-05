/*==============================================================================
 * Инициализация К1921ВК01T
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
#include "system_K1921VK01T.h"
#include "K1921VK01T.h"
//-- Types ---------------------------------------------------------------------
typedef enum {
    COMMON_REG_SYS_CLK_SEL_SRC_CPE = 0x0,      /*!< select POR clock or XI_OSC by input CPE */
    COMMON_REG_SYS_CLK_SEL_SRC_POR = 0x1,      /*!< POR clock */
    COMMON_REG_SYS_CLK_SEL_SRC_ExtOsc = 0x2,   /*!<  external oscillator clock (XI_OSC) */
    COMMON_REG_SYS_CLK_SEL_SRC_PLL = 0x3,      /*!< PLL clock */
    COMMON_REG_SYS_CLK_SEL_SRC_PLLDiv = 0x4,   /*!< PLL clock with post-divider */
    COMMON_REG_SYS_CLK_SEL_SRC_USB60MHz = 0x5, /*!< USB clock 60 MHz */
    COMMON_REG_SYS_CLK_SEL_SRC_USBClk = 0x6,   /*!< clock from input CLK_USB GPIO A0 (12/24 MHz) */
    COMMON_REG_SYS_CLK_SEL_SRC_ETH25MHz = 0x7, /*!< clock from external Ethernet clock GPIO B3 or GPIO A8 */
} COMMON_REG_SYS_CLK_SEL_SRC_Enum;

typedef enum {
    COMMON_REG_SYS_CLK_CURR_SRC_CPE = 0x0,      /*!< select POR clock or XI_OSC by input CPE */
    COMMON_REG_SYS_CLK_CURR_SRC_POR = 0x1,      /*!< POR clock */
    COMMON_REG_SYS_CLK_CURR_SRC_ExtOsc = 0x2,   /*!<  external oscillator clock (XI_OSC) */
    COMMON_REG_SYS_CLK_CURR_SRC_PLL = 0x3,      /*!< PLL clock */
    COMMON_REG_SYS_CLK_CURR_SRC_PLLDiv = 0x4,   /*!< PLL clock with post-divider */
    COMMON_REG_SYS_CLK_CURR_SRC_USB60MHz = 0x5, /*!< USB clock 60 MHz */
    COMMON_REG_SYS_CLK_CURR_SRC_USBClk = 0x6,   /*!< clock from input CLK_USB GPIO A0 (12/24 MHz) */
    COMMON_REG_SYS_CLK_CURR_SRC_ETH25MHz = 0x7, /*!< clock from external Ethernet clock GPIO B3 or GPIO A8 */
} COMMON_REG_SYS_CLK_CURR_SRC_Enum;

typedef enum {
    COMMON_REG_PLL_CTRL_REFSEL_ExtOsc = 0x0,   /*!< tact signal from external oscillator */
    COMMON_REG_PLL_CTRL_REFSEL_USBClk = 0x1,   /*!< tact signal from USB clock(GPIO A0) */
    COMMON_REG_PLL_CTRL_REFSEL_USB60MHz = 0x2, /*!< tact signal from USB 60 MHz */
    COMMON_REG_PLL_CTRL_REFSEL_ETH25MHz = 0x3, /*!< tact signal from Ethernet 25 MHz */
} COMMON_REG_PLL_CTRL_REFSEL_Enum;

//-- Variables -----------------------------------------------------------------
uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)

//-- Functions -----------------------------------------------------------------
void SystemCoreClockUpdate(void)
{
    uint32_t current_sysclk;
    uint32_t pll_nf, pll_nr, pll_od, pll_refclk, pll_div = 1;

    current_sysclk = NT_COMMON_REG->SYS_CLK_bit.CURR_SRC;

    switch (current_sysclk) {
    case COMMON_REG_SYS_CLK_CURR_SRC_POR:
        SystemCoreClock = OSICLK_VAL;
        break;
    case COMMON_REG_SYS_CLK_CURR_SRC_ExtOsc:
        SystemCoreClock = OSECLK_VAL;
        break;
    case COMMON_REG_SYS_CLK_CURR_SRC_USB60MHz:
        SystemCoreClock = 60000000;
        break;
    case COMMON_REG_SYS_CLK_CURR_SRC_USBClk:
        if (NT_COMMON_REG->USB_CTRL_bit.FSEL)
            SystemCoreClock = 24000000;
        else
            SystemCoreClock = 12000000;
        break;
    case COMMON_REG_SYS_CLK_CURR_SRC_ETH25MHz:
        SystemCoreClock = 25000000;
        break;
    case COMMON_REG_SYS_CLK_CURR_SRC_PLLDiv:
        pll_div = 2 * (NT_COMMON_REG->PLL_CTRL_bit.PLL_DIV + 1);
    case COMMON_REG_SYS_CLK_CURR_SRC_PLL:
        pll_nf = NT_COMMON_REG->PLL_NF + 2;
        pll_nr = NT_COMMON_REG->PLL_NR + 2;
        if ((NT_COMMON_REG->PLL_OD == 1) || (NT_COMMON_REG->PLL_OD == 2))
            pll_od = 2;
        else if (NT_COMMON_REG->PLL_OD == 3)
            pll_od = 4;
        else
            pll_od = 1;
        if (NT_COMMON_REG->PLL_CTRL_bit.REFSEL == COMMON_REG_PLL_CTRL_REFSEL_ExtOsc)
            pll_refclk = OSECLK_VAL;
        else if (NT_COMMON_REG->PLL_CTRL_bit.REFSEL == COMMON_REG_PLL_CTRL_REFSEL_USBClk) {
            if (NT_COMMON_REG->USB_CTRL_bit.FSEL)
                pll_refclk = 24000000;
            else
                pll_refclk = 12000000;
        } else if (NT_COMMON_REG->PLL_CTRL_bit.REFSEL == COMMON_REG_PLL_CTRL_REFSEL_USB60MHz)
            pll_refclk = 60000000;
        else // NT_COMMON_REG->PLL_CTRL_bit.REFSEL == COMMON_REG_PLL_CTRL_REFSEL_ETH25MHz)
            pll_refclk = 25000000;
        SystemCoreClock = (pll_refclk * pll_nf) / (pll_nr * pll_od * pll_div);
        break;
    }
}

void ClkInit()
{
    uint32_t timeout_counter = 0;
    uint32_t sysclk_source;

//clockout control
#if defined CKO_PLL
    NT_COMMON_REG->GPIODEN3_bit.PORTH |= (1 << 0);
    NT_COMMON_REG->GPIOPCTLH_bit.PIN0 = 1;
    NT_GPIOH->ALTFUNCSET = (1 << 0);
#endif

//select system clock
#ifdef SYSCLK_PLL
//PLLCLK = REFSRC * (NF/NR) * (1/(1<<OD))
#if (OSECLK_VAL == 8000000)
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = COMMON_REG_PLL_CTRL_REFSEL_ExtOsc;
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 0;
#elif (OSECLK_VAL == 12000000)
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = COMMON_REG_PLL_CTRL_REFSEL_ExtOsc;
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 1;
#elif (OSECLK_VAL == 16000000)
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = COMMON_REG_PLL_CTRL_REFSEL_ExtOsc;
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 2;
#elif (OSECLK_VAL == 20000000)
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = COMMON_REG_PLL_CTRL_REFSEL_ExtOsc;
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 3;
#elif (OSECLK_VAL == 24000000)
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = COMMON_REG_PLL_CTRL_REFSEL_ExtOsc;
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 4;
#else
#error "Please define OSECLK_VAL with correct value!"
#endif
    uint32_t pll_stable_wait = PLL_STABLE_TIMEOUT;
    while (pll_stable_wait) {
        pll_stable_wait--;
    }
    // additional waitstates
    NT_BOOTFLASH->T_ACC = 6;
    //select PLL as source system clock
    sysclk_source = COMMON_REG_SYS_CLK_SEL_SRC_PLL;
#elif defined SYSCLK_OSI
    sysclk_source = COMMON_REG_SYS_CLK_SEL_SRC_POR;
#elif defined SYSCLK_OSE
    sysclk_source = COMMON_REG_SYS_CLK_SEL_SRC_ExtOsc;
#else
#error "Please define SYSCLK source (SYSCLK_PLL | SYSCLK_OSI | SYSCLK_OSE)!"
#endif
    //switch sysclk
    NT_COMMON_REG->SYS_CLK = sysclk_source;
    // Wait switching done
    timeout_counter = 0;
    while (((NT_COMMON_REG->SYS_CLK_bit.CURR_SRC) != sysclk_source) && (timeout_counter < SYSCLK_SWITCH_TIMEOUT))
        timeout_counter++;
    if (timeout_counter == SYSCLK_SWITCH_TIMEOUT) //SYSCLK failed to switch
        while (1) {
        };
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
