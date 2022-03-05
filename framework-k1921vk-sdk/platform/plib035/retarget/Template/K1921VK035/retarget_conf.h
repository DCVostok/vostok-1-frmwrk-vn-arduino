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

#ifndef RETARGET_CONF_H
#define RETARGET_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include <stdio.h>
#include "K1921VK035.h"

//-- Defines -------------------------------------------------------------------
#ifdef RETARGET
#ifdef RETARGET_USE_ITM
#ifndef RETARGET_ITM_BAUD
#define RETARGET_ITM_BAUD 2000000
#endif
#else
#define RETARGET_UART UART1
#define RETARGET_UART_NUM UART1_Num
#define RETARGET_UART_PORT GPIOB
#define RETARGET_UART_PORT_EN RCU_HCLKCFG_GPIOBEN_Msk
#define RETARGET_UART_PIN_TX_POS 8
#define RETARGET_UART_PIN_RX_POS 9
#define RETARGET_UART_RX_IRQHandler UART1_RX_IRQHandler
#define RETARGET_UART_RX_IRQn UART1_RX_IRQn
#ifndef RETARGET_UART_BAUD
#define RETARGET_UART_BAUD 115200
#endif
#endif
#if defined( __CMCPPARM__ )
#define printf(...) fprintf(&hRetarget,__VA_ARGS__);
#define scanf(...) fscanf(&hRetarget,__VA_ARGS__);
extern FILE hRetarget;
#endif
#else
#define printf(...) ((void)0)
#endif // RETARGET

//-- Functions -----------------------------------------------------------------
void retarget_init(void);
int retarget_get_char(void);
int retarget_put_char(int ch);

#ifdef __cplusplus
}
#endif

#endif // RETARGET_CONF_H
