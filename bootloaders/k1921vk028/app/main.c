/*==============================================================================
 * UART загрузчик для К1921ВК028
 *
 * Первичная настройка периферии и переход на исполнение ядра загрузчика из ОЗУ
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
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "boot_core.h"

//-- Defines -------------------------------------------------------------------
#define IRQ_TOTAL 208

//-- Variables -----------------------------------------------------------------
static __attribute__((section("vtable"))) void (*Vectors[IRQ_TOTAL])(void) __attribute__((aligned(1024)));

//-- Init functions ------------------------------------------------------------
static void DebugInit()
{
#ifdef DEBUG
    // настраиваем служебные выводы на выход
    RCU->HCLKCFG = DBG_PORT_EN;
    RCU->HRSTCFG = DBG_PORT_EN;
    DBG_PORT->DENSET = DBG_INFO_MSK;
    DBG_PORT->OUTENSET = DBG_INFO_MSK;
#endif
}

static void FPUInit()
{
    SCB->CPACR = 0x00F00000;
    __DSB();
    __ISB();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
}

static void ClockInit()
{

    //PLLCLK = (REFSRC/REFDIV) * (FBDIV/(DIV1*DIV2))
    uint32_t pllcfg_clr = (RCU_PLLCFG_REFSRC_Msk |
                           RCU_PLLCFG_REFDIV_Msk |
                           RCU_PLLCFG_DIV1_Msk |
                           RCU_PLLCFG_DIV2_Msk);
    RCU->PLLCFG_bit.BP = 0;
    RCU->PLLCFG_bit.FBDIV = 50;
    RCU->PLLCFG_bit.PD = 0;
    RCU->PLLCFG = (RCU->PLLCFG & (~pllcfg_clr)) |
                  (RCU_PLLCFG_REFSRC_OSECLK << RCU_PLLCFG_REFSRC_Pos) |
                  (1 << RCU_PLLCFG_REFDIV_Pos) |
                  (3 << RCU_PLLCFG_DIV1_Pos) |
                  (2 << RCU_PLLCFG_DIV2_Pos);

    RCU->PLLCFG_bit.OUTDIS = 0;
    while (!RCU->PLLCFG_bit.LOCK) {
    };
    // additional waitstates
    MFLASH->CTRL = (7 << MFLASH_CTRL_LAT_Pos);
    BFLASH->CTRL = (7 << BFLASH_CTRL_LAT_Pos);
    //apb0 div by 2
    RCU->APBCFG_bit.DIV = 1;
    //select PLL as source system clock
    RCU->SYSCLKCFG = (RCU_SYSCLKCFG_SYSSEL_PLLCLK << RCU_SYSCLKCFG_SYSSEL_Pos);
    // Wait switching done
    uint32_t timeout_counter = SYSCLK_SWITCH_TIMEOUT;
    while (timeout_counter) {
        timeout_counter--;
    }
}

static void UartInit()
{
#if (UART_NUMBER == 0)
    RCU->HCLKCFG |= RCU_HCLKCFG_GPIOCEN_Msk;
    RCU->HRSTCFG |= RCU_HRSTCFG_GPIOCEN_Msk;
    GPIOC->ALTFUNCNUM1_bit.PIN10 = GPIO_ALTFUNCNUM0_PIN0_AF1;
    GPIOC->ALTFUNCNUM1_bit.PIN11 = GPIO_ALTFUNCNUM0_PIN0_AF1;
    GPIOC->ALTFUNCSET = (1 << 10) | (1 << 11);
    GPIOC->DENSET = (1 << 10) | (1 << 11);
#elif (UART_NUMBER == 1)
    RCU->HCLKCFG |= RCU_HCLKCFG_GPIOCEN_Msk;
    RCU->HRSTCFG |= RCU_HRSTCFG_GPIOCEN_Msk;
    GPIOC->ALTFUNCNUM1_bit.PIN14 = GPIO_ALTFUNCNUM0_PIN0_AF2;
    GPIOC->ALTFUNCNUM1_bit.PIN15 = GPIO_ALTFUNCNUM0_PIN0_AF2;
    GPIOC->ALTFUNCSET = (1 << 14) | (1 << 15);
    GPIOC->DENSET = (1 << 14) | (1 << 15);
#elif (UART_NUMBER == 2)
    RCU->HCLKCFG |= RCU_HCLKCFG_GPIOCEN_Msk;
    RCU->HRSTCFG |= RCU_HRSTCFG_GPIOCEN_Msk;
    GPIOC->ALTFUNCNUM1_bit.PIN8 = GPIO_ALTFUNCNUM0_PIN0_AF2;
    GPIOC->ALTFUNCNUM1_bit.PIN9 = GPIO_ALTFUNCNUM0_PIN0_AF2;
    GPIOC->ALTFUNCSET = (1 << 8) | (1 << 9);
    GPIOC->DENSET = (1 << 8) | (1 << 9);
#elif (UART_NUMBER == 3)
    RCU->HCLKCFG |= RCU_HCLKCFG_GPIOEEN_Msk;
    RCU->HRSTCFG |= RCU_HRSTCFG_GPIOEEN_Msk;
    GPIOE->ALTFUNCNUM1_bit.PIN8 = GPIO_ALTFUNCNUM0_PIN0_AF4;
    GPIOE->ALTFUNCNUM1_bit.PIN9 = GPIO_ALTFUNCNUM0_PIN0_AF4;
    GPIOE->ALTFUNCSET = (1 << 8) | (1 << 9);
    GPIOE->DENSET = (1 << 8) | (1 << 9);
#else
#error "Please define UART_NUMBER with correct value!"
#endif

    RCU->UARTCFG[UARTx_NUM].UARTCFG = (RCU_UARTCFG_UARTCFG_CLKSEL_PLLCLK << RCU_UARTCFG_UARTCFG_CLKSEL_Pos) |
                                      (1 << RCU_UARTCFG_UARTCFG_CLKEN_Pos) |
                                      (1 << RCU_UARTCFG_UARTCFG_RSTDIS_Pos) |
                                      (1 << RCU_UARTCFG_UARTCFG_DIVEN_Pos);
    UARTx->IFLS = UART_IFLS_RXIFLSEL_Lvl18 << UART_IFLS_RXIFLSEL_Pos |
                  UART_IFLS_RXIFLSEL_Lvl18 << UART_IFLS_TXIFLSEL_Pos;
    UARTx->IMSC = UART_MIS_RXMIS_Msk;
    NVIC_EnableIRQ(UARTx_RX_IRQn);
}

static void TimerInit()
{
    RCU->PRSTCFG0_bit.TMR_EN = 1;
    RCU->PCLKCFG0_bit.TMR_EN = 1;
    TMR->LOAD = 0xFFFFFFFF;
}

static void NVICInit()
{
    uint32_t* src = (uint32_t*)SCB->VTOR;
    uint32_t* dst = (uint32_t*)Vectors;
    uint32_t n = IRQ_TOTAL;

    while (n--)
        *dst++ = *src++;

    SCB->VTOR = (uint32_t)Vectors;
}

void PeriphInit()
{
    NVICInit();
    FPUInit();
    ClockInit();
    UartInit();
    TimerInit();
}

//-- Main ----------------------------------------------------------------------
int main()
{
    DebugInit();
    DBG_PRINT(0x31);
    PeriphInit();
    DBG_PRINT(0x32);
    boot_init();
    DBG_PRINT(0x33);
    boot_core();
    return 0;
}
