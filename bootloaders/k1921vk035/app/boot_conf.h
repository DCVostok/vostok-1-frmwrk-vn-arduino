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
#include "K1921VK035.h"

//--- Defines ------------------------------------------------------------------
//Global configuration
#define GLOBMEM(ADDR)   *(volatile uint32_t*)(ADDR)
#define RAMFUNC         __attribute__( (long_call, section(".ramfunc") ) )
#define BOOT_VER_MAJOR  0x0001
#define BOOT_VER_MINOR  0x0001
#define BOOT_VER        ((BOOT_VER_MAJOR<<16)|BOOT_VER_MINOR)
#define SYSCLK          100000000

//Debug
#define DBG_PORT        GPIOA
#define DBG_PORT_EN     RCU_HCLKCFG_GPIOAEN_Msk
#define DBG_INFO_MSK    0xFF
#define DBG_INFO_POS    8
#define DBG_INFO        DBG_PORT->DATAOUT
#if defined (DEBUG)
    #define DBG_PRINT(MSG)   DBG_INFO = MSG<<DBG_INFO_POS
#else
    #define DBG_PRINT(MSG)    ((void)0);
#endif

//UART
#define UART                UART1
#define UART_NUM            1
#define UART_PORT           GPIOB
#define UART_PORT_EN        RCU_HCLKCFG_GPIOBEN_Msk
#define UART_PIN_RX_POS     9
#define UART_PIN_TX_POS     8
#define UART_PINS_MSK       ((1<<UART_PIN_RX_POS) | (1<<UART_PIN_TX_POS))
#define UART_RX_IRQHandler  UART1_RX_IRQHandler
#define UART_RX_IRQn        UART1_RX_IRQn

//TMR
#define TMR             TMR0
#define TMR_CLK         SYSCLK
#define TMR_CLK_PERIOD  (1000000000/TMR_CLK)    //ns
#define TMR_TIMEOUT     500000000               //ns
#define TMR_LOAD        (TMR_TIMEOUT/TMR_CLK_PERIOD)
#define TMR_EN          TMR0EN
#define TMR_IRQHandler  TMR0_IRQHandler
#define TMR_IRQn        TMR0_IRQn

//Packet parser
#define PACKET_FIFO_BYTES       8192
#define PACKET_HOST_SIGN        0x5C81
#define PACKET_DEVICE_SIGN      0x7EA3
#define PACKET_EMPTY_DATA       0x55
#define PACKET_TMP_DATA_BYTES   (1024+8)

#endif //BOOT_CONF_H
