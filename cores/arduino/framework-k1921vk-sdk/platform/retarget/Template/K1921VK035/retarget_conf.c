/*==============================================================================
 * Перенаправление printf() для К1921ВК035
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
#include "retarget_conf.h"

//-- Defines -------------------------------------------------------------------
// Trace
#define ITM_TER_STIM0 (1 << 0) // ITM stimulus0 enable
#define ITM_TER_STIM1 (1 << 1) // ITM stimulus1 enable
#define ITM_TER_STIM2 (1 << 2) // ITM stimulus2 enable
#define TPIU_SPPR_TRACEPORT 0  // TPIU Selected Pin Protocol Trace Port
#define TPIU_SPPR_MANCHESTER 1 // TPIU Selected Pin Protocol Manchester
#define TPIU_SPPR_NRZ 2        // TPIU Selected Pin Protocol NRZ (uart)
#define ITM_LAR_UNLOCK 0xC5ACCE55UL
#define ITM_TCR_TraceBusID_VAL 0x59

//-- Variables -----------------------------------------------------------------
extern uint32_t SystemCoreClock;
#if defined (__CMCPPARM__)
  extern FILE hRetarget;
#endif

//-- Functions -----------------------------------------------------------------
void retarget_init()
{
#if defined RETARGET && !defined RETARGET_USE_ITM
    uint32_t baud_icoef = SystemCoreClock / (16 * RETARGET_UART_BAUD);
    uint32_t baud_fcoef = ((SystemCoreClock / (16.0f * RETARGET_UART_BAUD) - baud_icoef) * 64 + 0.5f);
    uint32_t uartclk_ref = RCU_UARTCFG_UARTCFG_CLKSEL_OSICLK;

    RCU->HCLKCFG |= RETARGET_UART_PORT_EN;
    RCU->HRSTCFG |= RETARGET_UART_PORT_EN;
    RETARGET_UART_PORT->ALTFUNCSET = (1 << RETARGET_UART_PIN_TX_POS) | (1 << RETARGET_UART_PIN_RX_POS);
    RETARGET_UART_PORT->DENSET = (1 << RETARGET_UART_PIN_TX_POS) | (1 << RETARGET_UART_PIN_RX_POS);

    if (RCU->SYSCLKSTAT_bit.SYSSTAT == RCU_SYSCLKCFG_SYSSEL_OSECLK)
        uartclk_ref = RCU_UARTCFG_UARTCFG_CLKSEL_OSECLK;
    else if (RCU->SYSCLKSTAT_bit.SYSSTAT == RCU_SYSCLKCFG_SYSSEL_OSICLK)
        uartclk_ref = RCU_UARTCFG_UARTCFG_CLKSEL_OSICLK;
    else if (RCU->SYSCLKSTAT_bit.SYSSTAT == RCU_SYSCLKCFG_SYSSEL_PLLCLK)
        uartclk_ref = RCU_UARTCFG_UARTCFG_CLKSEL_PLLCLK;
    else if (RCU->SYSCLKSTAT_bit.SYSSTAT == RCU_SYSCLKCFG_SYSSEL_PLLDIVCLK)
        uartclk_ref = RCU_UARTCFG_UARTCFG_CLKSEL_PLLDIVCLK;
    RCU->UARTCFG[RETARGET_UART_NUM].UARTCFG = (uartclk_ref << RCU_UARTCFG_UARTCFG_CLKSEL_Pos) |
                                              RCU_UARTCFG_UARTCFG_CLKEN_Msk |
                                              RCU_UARTCFG_UARTCFG_RSTDIS_Msk;
    RETARGET_UART->IBRD = baud_icoef;
    RETARGET_UART->FBRD = baud_fcoef;
    RETARGET_UART->LCRH = UART_LCRH_FEN_Msk | (3 << UART_LCRH_WLEN_Pos);
    RETARGET_UART->CR = UART_CR_TXE_Msk | UART_CR_RXE_Msk | UART_CR_UARTEN_Msk;
#elif defined RETARGET && defined RETARGET_USE_ITM
    RCU->TRACECFG_bit.CLKSEL = RCU->SYSCLKSTAT_bit.SYSSTAT; //Источники SYSCLK и TRACECLK одинаковы
/*  //Обычно порт трассировки включается из IDE, поэтому можно не использовать ручную инициализацию
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    TPI->ACPR = OSECLK_VAL / RETARGET_ITM_BAUD - 1;
    TPI->SPPR = TPIU_SPPR_NRZ;
    TPI->FFCR &= ~(TPI_FFCR_EnFCont_Msk);

    ITM->LAR = ITM_LAR_UNLOCK;
    ITM->TCR = (ITM_TCR_TraceBusID_VAL << ITM_TCR_TraceBusID_Pos) | ITM_TCR_DWTENA_Msk | ITM_TCR_ITMENA_Msk;
    ITM->TER = ITM_TER_STIM0;*/
#endif //RETARGET
}

int retarget_get_char()
{
#if defined RETARGET && !defined RETARGET_USE_ITM
    while (RETARGET_UART->FR_bit.RXFE) {
    };
    return (int)RETARGET_UART->DR_bit.DATA;
#else
    return 0;
#endif //RETARGET
}

int retarget_put_char(int ch)
{
#if defined RETARGET && !defined RETARGET_USE_ITM
    while (RETARGET_UART->FR_bit.BUSY) {
    };
    RETARGET_UART->DR = ch;
#elif defined RETARGET && defined RETARGET_USE_ITM
    ITM_SendChar(ch);
#else
    (void)ch;
#endif //RETARGET
    return 0;
}


