/*==============================================================================
 * UART загрузчик для К1921ВК01T
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
#define IRQ_TOTAL 150

//-- Variables -----------------------------------------------------------------
static __attribute__((section("vtable"))) void (*Vectors[IRQ_TOTAL])(void) __attribute__((aligned(1024)));

//-- Init functions ------------------------------------------------------------
static void DebugInit()
{
#ifdef DEBUG
    // настраиваем служебные выводы на выход
    DBG_PORT->OUTENSET = DBG_INFO_MSK;
    NT_COMMON_REG->DBG_PORT_DEN |= DBG_INFO_MSK;
#endif
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
    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = 0; //extosc
    //PLLCLK = REFSRC * (NF/NR) * (1/(1<<OD))
#if (XIOSC == 8000000)

    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 0;
#elif (XIOSC == 12000000)
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 1;
#elif (XIOSC == 16000000)
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 2;
#elif (XIOSC == 20000000)
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 3;
#elif (XIOSC == 24000000)
    NT_COMMON_REG->PLL_OD = 3;
    NT_COMMON_REG->PLL_NF = 98;
    NT_COMMON_REG->PLL_NR = 4;
#else
#error "Please define XIOSC with correct value!"
#endif
    uint32_t pll_stable_wait = PLL_STABLE_TIMEOUT;
    while (pll_stable_wait) {
        pll_stable_wait--;
    }
    // additional waitstates
    NT_BOOTFLASH->T_ACC = 6;
    //switch sysclk
    NT_COMMON_REG->SYS_CLK = 0x3; //pll
    // Wait switching done
    uint32_t timeout_counter = SYSCLK_SWITCH_TIMEOUT;
    while (timeout_counter) {
        timeout_counter--;
    }
}

static void UartInit()
{
#if (UART_NUMBER == 0)
    //fix func priorities
    NT_COMMON_REG->GPIOPCTLD_bit.PIN11 = 2;
    NT_COMMON_REG->GPIOPCTLE_bit.PIN0 = 2;
    NT_COMMON_REG->GPIODENC = (1 << 3) | (1 << 4);
    NT_COMMON_REG->GPIOPCTLC_bit.PIN3 = 1;
    NT_COMMON_REG->GPIOPCTLC_bit.PIN4 = 1;
    NT_GPIOC->ALTFUNCSET = (1 << 3) | (1 << 4);
#elif (UART_NUMBER == 1)
    NT_COMMON_REG->GPIODENA = (1 << 3) | (1 << 4);
    NT_COMMON_REG->GPIOPCTLA_bit.PIN3 = 0;
    NT_COMMON_REG->GPIOPCTLA_bit.PIN4 = 0;
    NT_GPIOA->ALTFUNCSET = (1 << 3) | (1 << 4);
#elif (UART_NUMBER == 2)
    NT_COMMON_REG->GPIODENF = (1 << 10) | (1 << 11);
    NT_COMMON_REG->GPIOPCTLF_bit.PIN10 = 0;
    NT_COMMON_REG->GPIOPCTLF_bit.PIN11 = 0;
    NT_GPIOF->ALTFUNCSET = (1 << 10) | (1 << 11);
#elif (UART_NUMBER == 3)
    //fix func priorities
    NT_COMMON_REG->GPIOPCTLF_bit.PIN12 = 2;
    NT_COMMON_REG->GPIOPCTLF_bit.PIN13 = 2;
    NT_COMMON_REG->GPIODEND = (1 << 2) | (1 << 1);
    NT_COMMON_REG->GPIOPCTLD_bit.PIN2 = 1;
    NT_COMMON_REG->GPIOPCTLD_bit.PIN1 = 1;
    NT_GPIOD->ALTFUNCSET = (1 << 2) | (1 << 1);
#else
#error "Please define UART_NUMBER with correct value!"
#endif
    NT_COMMON_REG->UART_CLK_bit.UARTx_CLKEN = 1;
    NT_COMMON_REG->PER_RST0_bit.UARTx_RST = 1;
    UARTx->IFLS = (0 << UART_IFLS_RXIFLSEL_Pos |
                   0 << UART_IFLS_TXIFLSEL_Pos);
    UARTx->IMSC = UART_MIS_RXMIS_Msk;
    NVIC_EnableIRQ(UARTx_RX_IRQn);
}

static void TimerInit()
{
    NT_COMMON_REG->PER_RST0_bit.TMR_RST = 1;
    TMR->RELOAD = TMR_LOAD;
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
    // Используется BOOTEN нога, которая разрешает работу загрузчика.
    NT_COMMON_REG->BOOTEN_PORT_DEN |= BOOTEN_PIN_MSK;
    //выходим из загрузчика, если BOOTEN не был активен при сбросе
    if (!IS_BOOTEN_ACTIVE)
        boot_exit();
    DBG_PRINT(0x32);
    PeriphInit();
    DBG_PRINT(0x33);
    boot_init();
    DBG_PRINT(0x34);
    boot_core();
    return 0;
}

void HardFault_Handler(void)
{
    DBG_PRINT(0x35);
    while (1) {
    }
}
