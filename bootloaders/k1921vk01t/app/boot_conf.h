/*==============================================================================
 * UART загрузчик для К1921ВК035
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
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

#ifndef BOOT_CONF_H
#define BOOT_CONF_H

//--- Includes -----------------------------------------------------------------
#include <stdio.h>
#include "K1921VK01T.h"
#include "system_K1921VK01T.h"

//--- Defines ------------------------------------------------------------------
#define _CONCAT(x,y) x ## y
#define CONCAT(x,y) _CONCAT(x,y)

//Global configuration
#define GLOBMEM(ADDR)   *(volatile uint32_t*)(ADDR)
#define RAMFUNC         __attribute__( (long_call, section(".ramfunc") ) )
#define BOOT_VER_MAJOR  0x0001
#define BOOT_VER_MINOR  0x0001
#define BOOT_VER        ((BOOT_VER_MAJOR<<16)|BOOT_VER_MINOR)
#define SYSCLK          100000000
#ifndef XIOSC
    #define XIOSC           12000000
#endif

//Debug
#define DBG_PORT        NT_GPIOG
#define DBG_PORT_DEN    GPIODENG
#define DBG_INFO_POS    8
#define DBG_INFO_MSK    (0xFF << DBG_INFO_POS)
#define DBG_INFO        DBG_PORT->DATAOUT
#if defined (DEBUG)
    #define DBG_PRINT(MSG)   DBG_INFO = ~(MSG<<DBG_INFO_POS)
#else
    #define DBG_PRINT(MSG)    ((void)0);
#endif

//Boot enable pin
#ifndef BOOTEN_PORT_LETTER
    #define BOOTEN_PORT_LETTER E
#endif
#ifndef BOOTEN_PIN_NUMBER
    #define BOOTEN_PIN_NUMBER 8
#endif
#define BOOTEN_PORT        CONCAT(NT_GPIO, BOOTEN_PORT_LETTER)
#define BOOTEN_PORT_DEN    CONCAT(GPIODEN, BOOTEN_PORT_LETTER)
#define BOOTEN_PIN_POS     BOOTEN_PIN_NUMBER
#define BOOTEN_PIN_MSK     (1<<BOOTEN_PIN_POS)
#define IS_BOOTEN_ACTIVE   (BOOTEN_PORT->DATA & BOOTEN_PIN_MSK)

//UART
#ifndef UART_NUMBER
    #define UART_NUMBER 2
#endif
#define UART_NAME            CONCAT(UART, UART_NUMBER)
#define UARTx                CONCAT(NT_, UART_NAME)
#define UARTx_NUM            UART_NUMBER
#define UARTx_CLKEN          CONCAT(CLKEN_, UART_NAME)
#define UARTx_RST            CONCAT(UARTRST, UART_NUMBER)
#define UARTx_RX_IRQHandler  CONCAT(UART_NAME, _RX_IRQHandler)
#define UARTx_RX_IRQn        CONCAT(UART_NAME, _RX_IRQn)
#if (UART_NUMBER == 0)
    #define UARTx_RX_PIN_STATE   (NT_GPIOC->DATA & (1 << 4))
#elif (UART_NUMBER == 1)
    #define UARTx_RX_PIN_STATE   (NT_GPIOA->DATA & (1 << 4))
#elif (UART_NUMBER == 2)
    #define UARTx_RX_PIN_STATE   (NT_GPIOF->DATA & (1 << 11))
#elif (UART_NUMBER == 3)
    #define UARTx_RX_PIN_STATE   (NT_GPIOD->DATA & (1 << 1))
#endif

//TMR
#define TMR             NT_TIMER0
#define TMR_CLK         SYSCLK
#define TMR_CLK_PERIOD  (1000000000/TMR_CLK)    //ns
#define TMR_TIMEOUT     500000000               //ns
#define TMR_LOAD        (TMR_TIMEOUT/TMR_CLK_PERIOD)
#define TMR_RST         TIMERRST0
#define TMR_IRQHandler  TMR0_IRQHandler
#define TMR_IRQn        TMR0_IRQn

//Packet parser
#define PACKET_FIFO_BYTES       65536
#define PACKET_HOST_SIGN        0x5C81
#define PACKET_DEVICE_SIGN      0x7EA3
#define PACKET_EMPTY_DATA       0x55
#define PACKET_TMP_DATA_BYTES   (8192+8)

#endif //BOOT_CONF_H
