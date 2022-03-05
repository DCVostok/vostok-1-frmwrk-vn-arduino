/*==============================================================================
 * Перенаправление printf() для К1921ВК01T
 *      UART0 использует:
 *          - C[3] (TX)
 *          - C[4] (RX)
 *      UART1 использует:
 *          - A[3] (TX)
 *          - A[4] (RX)
 *      UART2 использует:
 *          - F[10] (TX)
 *          - F[11] (RX)
 *      UART3 использует:
 *          - D[2] (TX)
 *          - D[1] (RX)
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

//-- Types ---------------------------------------------------------------------
typedef enum {
    GPIO_AltFunc1 = 0x0, /*!< first alternative function for pin */
    GPIO_AltFunc2 = 0x1, /*!< second alternative function for pin */
    GPIO_AltFunc3 = 0x2, /*!< third alternative function for pin */
} GPIO_AltFunc_Enum;

typedef enum {
    UART_LCR_H_WLEN_5bit = 0x0, /*!< 5 bit in informational word */
    UART_LCR_H_WLEN_6bit = 0x1, /*!< 6 bit in informational word */
    UART_LCR_H_WLEN_7bit = 0x2, /*!< 7 bit in informational word */
    UART_LCR_H_WLEN_8bit = 0x3, /*!< 8 bit in informational word */
} UART_LCR_H_WLEN_Enum;

//-- Variables -----------------------------------------------------------------
extern uint32_t SystemCoreClock;
#if defined (__CMCPPARM__)
  extern FILE hRetarget;
#endif

//-- Functions -----------------------------------------------------------------
void retarget_init()
{
#if defined RETARGET && !defined RETARGET_USE_ITM
  #ifdef RETARGET_CLK_VAL
      uint32_t baud_icoef = RETARGET_CLK_VAL / (16 * RETARGET_UART_BAUD);
    uint32_t baud_fcoef = ((RETARGET_CLK_VAL / (16.0f * RETARGET_UART_BAUD) - baud_icoef) * 64 + 0.5f);
    #else
    uint32_t baud_icoef = SystemCoreClock / (16 * RETARGET_UART_BAUD);
    uint32_t baud_fcoef = ((SystemCoreClock / (16.0f * RETARGET_UART_BAUD) - baud_icoef) * 64 + 0.5f);
    #endif

#if (RETARGET_UART_NUM == 0)
    //fix func priorities
    NT_COMMON_REG->GPIOPCTLD_bit.PIN11 = GPIO_AltFunc3;
    NT_COMMON_REG->GPIOPCTLE_bit.PIN0 = GPIO_AltFunc3;

    NT_COMMON_REG->GPIODENC = (1 << 3) | (1 << 4);
    NT_COMMON_REG->GPIOPCTLC_bit.PIN3 = GPIO_AltFunc2;
    NT_COMMON_REG->GPIOPCTLC_bit.PIN4 = GPIO_AltFunc2;
    NT_GPIOC->ALTFUNCSET = (1 << 3) | (1 << 4);
#elif (RETARGET_UART_NUM == 1)
    NT_COMMON_REG->GPIODENA = (1 << 3) | (1 << 4);
    NT_COMMON_REG->GPIOPCTLA_bit.PIN3 = GPIO_AltFunc1;
    NT_COMMON_REG->GPIOPCTLA_bit.PIN4 = GPIO_AltFunc1;
    NT_GPIOA->ALTFUNCSET = (1 << 3) | (1 << 4);
#elif (RETARGET_UART_NUM == 2)
    NT_COMMON_REG->GPIODENF = (1 << 10) | (1 << 11);
    NT_COMMON_REG->GPIOPCTLF_bit.PIN10 = GPIO_AltFunc1;
    NT_COMMON_REG->GPIOPCTLF_bit.PIN11 = GPIO_AltFunc1;
    NT_GPIOF->ALTFUNCSET = (1 << 10) | (1 << 11);
#elif (RETARGET_UART_NUM == 3)
    //fix func priorities
    NT_COMMON_REG->GPIOPCTLF_bit.PIN12 = GPIO_AltFunc3;
    NT_COMMON_REG->GPIOPCTLF_bit.PIN13 = GPIO_AltFunc3;

    NT_COMMON_REG->GPIODEND = (1 << 2) | (1 << 1);
    NT_COMMON_REG->GPIOPCTLD_bit.PIN2 = GPIO_AltFunc2;
    NT_COMMON_REG->GPIOPCTLD_bit.PIN1 = GPIO_AltFunc2;
    NT_GPIOD->ALTFUNCSET = (1 << 2) | (1 << 1);
#else
#error "Please define RETARGET_UART_NUM with correct value!"
#endif
    NT_COMMON_REG->UART_CLK_bit.RETARGET_UART_CLKEN = 1;
    NT_COMMON_REG->PER_RST0_bit.RETARGET_UART_RST = 1;
    RETARGET_UART->IBRD = baud_icoef;
    RETARGET_UART->FBRD = baud_fcoef;
    RETARGET_UART->LCR_H = UART_LCR_H_FEN_Msk | (UART_LCR_H_WLEN_8bit << UART_LCR_H_WLEN_Pos);
    RETARGET_UART->CR = UART_CR_TXE_Msk | UART_CR_RXE_Msk | UART_CR_UARTEN_Msk;
#if defined (__CMCPPARM__)
    _fopen(&hRetarget);
#endif
#elif defined RETARGET && defined RETARGET_USE_ITM
/*  //Обычно порт трассировки включается из IDE, поэтому можно не использовать ручную инициализацию
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    TPI->ACPR = SRCCLK_VAL / RETARGET_ITM_BAUD - 1;
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
