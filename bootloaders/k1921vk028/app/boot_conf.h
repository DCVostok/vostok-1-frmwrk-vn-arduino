/*==============================================================================
 * UART загрузчик для К1921ВК028
 *
 * Общий файл конфигурации загрузчика: глобальные константы, общие макросы, типы
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

#ifndef BOOT_CONF_H
#define BOOT_CONF_H

//--- Includes -----------------------------------------------------------------
#include <stdio.h>
#include "K1921VK028.h"

//--- Defines ------------------------------------------------------------------
#define _CONCAT(x,y) x ## y
#define CONCAT(x,y) _CONCAT(x,y)

//Global configuration
#define GLOBMEM(ADDR)   *(volatile uint32_t*)(ADDR)
#define RAMFUNC         __attribute__( (long_call, section(".ram0func") ) )
#define BOOT_VER_MAJOR  0x0001
#define BOOT_VER_MINOR  0x0001
#define BOOT_VER        ((BOOT_VER_MAJOR<<16)|BOOT_VER_MINOR)
#define SYSCLK          200000000

//Debug
#define DBG_PORT        GPIOA
#define DBG_PORT_EN     RCU_HCLKCFG_GPIOAEN_Msk
#define DBG_INFO_MSK    0xFF
#define DBG_INFO_POS    0
#define DBG_INFO        DBG_PORT->DATAOUT
#if defined (DEBUG)
    #define DBG_PRINT(MSG)   DBG_INFO = (~MSG)
#else
    #define DBG_PRINT(MSG)    ((void)0);
#endif

//UART
#ifndef UART_NUMBER
    #define UART_NUMBER 0
#endif
#if (UART_NUMBER == 0)
    #define UARTx                UART0
    #define UARTx_NUM            UART_NUMBER
    #define UARTx_RX_IRQHandler  UART0_RX_IRQHandler
    #define UARTx_RX_IRQn        UART0_RX_IRQn
    #define UARTx_RX_PIN_STATE   (GPIOC->DATA & (1 << 11))
#elif (UART_NUMBER == 1)
    #define UARTx                UART1
    #define UARTx_NUM            UART_NUMBER
    #define UARTx_RX_IRQHandler  UART1_RX_IRQHandler
    #define UARTx_RX_IRQn        UART1_RX_IRQn
    #define UARTx_RX_PIN_STATE   (GPIOC->DATA & (1 << 15))
#elif (UART_NUMBER == 2)
    #define UARTx                UART2
    #define UARTx_NUM            UART_NUMBER
    #define UARTx_RX_IRQHandler  UART2_RX_IRQHandler
    #define UARTx_RX_IRQn        UART2_RX_IRQn
    #define UARTx_RX_PIN_STATE   (GPIOC->DATA & (1 << 9))
#elif (UART_NUMBER == 3)
    #define UARTx                UART3
    #define UARTx_NUM            UART_NUMBER
    #define UARTx_RX_IRQHandler  UART3_RX_IRQHandler
    #define UARTx_RX_IRQn        UART3_RX_IRQn
    #define UARTx_RX_PIN_STATE   (GPIOE->DATA & (1 << 8))
#endif

//TMR
#define TMR             TMR0
#define TMR_EN          TMR0EN

//Packet parser
#define PACKET_FIFO_BYTES       131072
#define PACKET_HOST_SIGN        0x5C81
#define PACKET_DEVICE_SIGN      0x7EA3
#define PACKET_EMPTY_DATA       0x55
#define PACKET_TMP_DATA_BYTES   (16384+8)

#endif //BOOT_CONF_H
