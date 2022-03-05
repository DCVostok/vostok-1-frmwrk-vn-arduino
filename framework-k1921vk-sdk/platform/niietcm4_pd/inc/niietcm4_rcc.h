/**
  ******************************************************************************
  * @file    niietcm4_rcc.h
  *
  * @brief   Файл содержит все прототипы функций для RCC (Reset & Clock Control).
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    26.10.2015
  *
  ******************************************************************************
  * @attention
  *
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
  * <h2><center>&copy; 2015 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_RCC_H
#define __NIIETCM4_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/** @defgroup RCC_Exported_Defines Константы
  * @{
  */

    #define RCC_CLK_CHANGE_TIMEOUT      ((uint32_t)10000) /*!< Время ожидания смены источника тактирования */
    #define RCC_CLK_PLL_STABLE_TIMEOUT  ((uint32_t)100) /*!< Время ожидания стабилизации выходной частоты PLL */

/**
  * @}
  */

/** @defgroup RCC_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор источника опорного сигнала PLL.
  */

typedef enum
{
    RCC_PLLRef_XI_OSC,       /*!< Сигнал со входа XI_OSC */
    RCC_PLLRef_USB_CLK,      /*!< Сигнал с входной альтернативной функции CLK_USB */
    RCC_PLLRef_USB_60MHz,    /*!< Сигнал на выходе блока USB */
    RCC_PLLRef_ETH_25MHz     /*!< Входной тактовый сигнал блока Ethernet */
}RCC_PLLRef_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_PLLRef_TypeDef.
  */

#define IS_RCC_PLL_REF(PLL_REF) (((PLL_REF) == RCC_PLLRef_XI_OSC) || \
                                 ((PLL_REF) == RCC_PLLRef_USB_CLK) || \
                                 ((PLL_REF) == RCC_PLLRef_USB_60MHz)|| \
                                 ((PLL_REF) == RCC_PLLRef_ETH_25MHz))


/**
  * @brief  Выходной делитель NO
  */

typedef enum
{
    RCC_PLLNO_Disable,       /*!< Делитель NO выключен */
    RCC_PLLNO_Div2,          /*!< Коэффициент деления NO равен 2 */
    RCC_PLLNO_Div4 = 3       /*!< Коэффициент деления NO равен 4 */
}RCC_PLLNO_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_PLLNO_TypeDef.
  */

#define IS_RCC_PLL_NO(PLL_NO) (((PLL_NO) == RCC_PLLNO_Disable) || \
                               ((PLL_NO) == RCC_PLLNO_Div2) || \
                               ((PLL_NO) == RCC_PLLNO_Div4))

/**
  * @brief  Выбор источника тактирования для UART.
  */

typedef enum
{
    RCC_UARTClk_SYSCLK,     /*!< Текущая системная частота */
    RCC_UARTClk_XI_OSC,     /*!< Сигнал со входа XI_OSC */
    RCC_UARTClk_USB_CLK,    /*!< Сигнал с входной альтернативной функции CLK_USB */
    RCC_UARTClk_USB_60MHz   /*!< Сигнал на выходе блока USB */
}RCC_UARTClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_UARTClk_TypeDef.
  */

#define IS_RCC_UART_CLK(UART_CLK) (((UART_CLK) == RCC_UARTClk_SYSCLK) || \
                                   ((UART_CLK) == RCC_UARTClk_XI_OSC) || \
                                   ((UART_CLK) == RCC_UARTClk_USB_CLK) || \
                                   ((UART_CLK) == RCC_UARTClk_USB_60MHz))

 /**
   * @brief  Выбор источника тактирования для SPI.
   */

 typedef enum
 {
     RCC_SPIClk_SYSCLK,     /*!< Текущая системная частота */
     RCC_SPIClk_XI_OSC,     /*!< Сигнал со входа XI_OSC */
     RCC_SPIClk_USB_CLK,    /*!< Сигнал с входной альтернативной функции CLK_USB */
     RCC_SPIClk_USB_60MHz   /*!< Сигнал на выходе блока USB */
 }RCC_SPIClk_TypeDef;

 /**
   * @brief Макрос проверки аргументов типа @ref RCC_SPIClk_TypeDef.
   */

 #define IS_RCC_SPI_CLK(SPI_CLK) (((SPI_CLK) == RCC_SPIClk_SYSCLK) || \
                                  ((SPI_CLK) == RCC_SPIClk_XI_OSC) || \
                                  ((SPI_CLK) == RCC_SPIClk_USB_CLK) || \
                                  ((SPI_CLK) == RCC_SPIClk_USB_60MHz))

/**
  * @brief  Выбор источника тактирования для USB.
  */

typedef enum
{
    RCC_USBClk_USB_CLK,     /*!< Сигнал с входной альтернативной функции CLK_USB */
    RCC_USBClk_XI_OSC       /*!< Сигнал со входа XI_OSC */
}RCC_USBClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_USBClk_TypeDef.
  */

#define IS_RCC_USB_CLK(USB_CLK) (((USB_CLK) == RCC_USBClk_XI_OSC) || \
                                 ((USB_CLK) == RCC_USBClk_USB_CLK))

/**
  * @brief  Выбор фиксированной частоты на входе CLK_USB.
  */

typedef enum
{
    RCC_USBFreq_12MHz,      /*!< 12 МГц сигнал на входе CLK_USB */
    RCC_USBFreq_24MHz       /*!< 24 МГц сигнал на входе CLK_USB */
}RCC_USBFreq_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_USBFreq_TypeDef.
  */

#define IS_RCC_USB_FREQ(USB_FREQ) (((USB_FREQ) == RCC_USBFreq_12MHz) || \
                                   ((USB_FREQ) == RCC_USBFreq_24MHz))

/**
  * @brief  Выбор модуля ADC для настройки его тактового сигнала.
  */

typedef enum
{
    RCC_ADCClk_0,      /*!< Тактовый сигнал ADC 0 */
    RCC_ADCClk_1,      /*!< Тактовый сигнал ADC 1 */
    RCC_ADCClk_2,      /*!< Тактовый сигнал ADC 2 */
    RCC_ADCClk_3,      /*!< Тактовый сигнал ADC 3 */
    RCC_ADCClk_4,      /*!< Тактовый сигнал ADC 4 */
    RCC_ADCClk_5,      /*!< Тактовый сигнал ADC 5 */
    RCC_ADCClk_6,      /*!< Тактовый сигнал ADC 6 */
    RCC_ADCClk_7,      /*!< Тактовый сигнал ADC 7 */
    RCC_ADCClk_8,      /*!< Тактовый сигнал ADC 8 */
    RCC_ADCClk_9,      /*!< Тактовый сигнал ADC 9 */
    RCC_ADCClk_10,     /*!< Тактовый сигнал ADC 10 */
    RCC_ADCClk_11,     /*!< Тактовый сигнал ADC 11 */
}RCC_ADCClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_ADCClk_TypeDef.
  */

#define IS_RCC_ADC_CLK(ADC_CLK) (((ADC_CLK) == RCC_ADCClk_0) || \
                                 ((ADC_CLK) == RCC_ADCClk_1) || \
                                 ((ADC_CLK) == RCC_ADCClk_2) || \
                                 ((ADC_CLK) == RCC_ADCClk_3) || \
                                 ((ADC_CLK) == RCC_ADCClk_4) || \
                                 ((ADC_CLK) == RCC_ADCClk_5) || \
                                 ((ADC_CLK) == RCC_ADCClk_6) || \
                                 ((ADC_CLK) == RCC_ADCClk_7) || \
                                 ((ADC_CLK) == RCC_ADCClk_8) || \
                                 ((ADC_CLK) == RCC_ADCClk_9) || \
                                 ((ADC_CLK) == RCC_ADCClk_10) || \
                                 ((ADC_CLK) == RCC_ADCClk_11))

/**
  * @brief  Выбор источника системной частоты.
  */

typedef enum
{
    RCC_SysClk_CPE_Sel,     /*!< Источник определяется состоянием вывода CPE: 0-POR, 1-XI_OSC */
    RCC_SysClk_POR,         /*!< Внутренний источник тактового сигнала */
    RCC_SysClk_XI_OSC,      /*!< Внешний источник тактового сигнала на входе XI_OSC */
    RCC_SysClk_PLL,         /*!< Выход блока PLL */
    RCC_SysClk_PLLDIV,      /*!< Выход блока PLL через делитель PLL DIV */
    RCC_SysClk_USB60MHz,    /*!< Выход блока USB 60 МГц */
    RCC_SysClk_USB_CLK,     /*!< Внешний источник тактового сигнала на входе CLK_USB */
    RCC_SysClk_ETH25MHz,    /*!< Входной тактовый сигнал блока Ethernet */
}RCC_SysClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_SysClk_TypeDef.
  */

#define IS_RCC_SYS_CLK(SYS_CLK) (((SYS_CLK) == RCC_SysClk_CPE_Sel) || \
                                 ((SYS_CLK) == RCC_SysClk_POR) || \
                                 ((SYS_CLK) == RCC_SysClk_XI_OSC) || \
                                 ((SYS_CLK) == RCC_SysClk_PLL) || \
                                 ((SYS_CLK) == RCC_SysClk_PLLDIV) || \
                                 ((SYS_CLK) == RCC_SysClk_USB60MHz) || \
                                 ((SYS_CLK) == RCC_SysClk_USB_CLK) || \
                                 ((SYS_CLK) == RCC_SysClk_ETH25MHz))

/**
  * @brief  Управление тактированием периферийных блоков
  */

typedef enum
{
    RCC_PeriphClk_QEP0 = ((uint32_t)(1<<1)),        /*!< Управление тактированием блока QEP 0 */
    RCC_PeriphClk_QEP1 = ((uint32_t)(1<<2)),        /*!< Управление тактированием блока QEP 1 */
    RCC_PeriphClk_CMP  = ((uint32_t)(1<<9)),        /*!< Управление тактированием блока аналогового компаратора */
    RCC_PeriphClk_PWM0 = ((uint32_t)(1<<10)),       /*!< Управление тактированием блока PWM 0 */
    RCC_PeriphClk_PWM1 = ((uint32_t)(1<<11)),       /*!< Управление тактированием блока PWM 1 */
    RCC_PeriphClk_PWM2 = ((uint32_t)(1<<12)),       /*!< Управление тактированием блока PWM 2 */
    RCC_PeriphClk_PWM3 = ((uint32_t)(1<<13)),       /*!< Управление тактированием блока PWM 3 */
    RCC_PeriphClk_PWM4 = ((uint32_t)(1<<14)),       /*!< Управление тактированием блока PWM 4 */
    RCC_PeriphClk_PWM5 = ((uint32_t)(1<<15)),       /*!< Управление тактированием блока PWM 5 */
    RCC_PeriphClk_PWM6 = ((uint32_t)(1<<16)),       /*!< Управление тактированием блока PWM 6 */
    RCC_PeriphClk_PWM7 = ((uint32_t)(1<<17)),       /*!< Управление тактированием блока PWM 7 */
    RCC_PeriphClk_PWM8 = ((uint32_t)(1<<18)),       /*!< Управление тактированием блока PWM 8 */
    RCC_PeriphClk_WD   = ((uint32_t)(1<<19)),       /*!< Управление тактированием сторожевого таймера */
    RCC_PeriphClk_I2C0 = ((uint32_t)(1<<20)),       /*!< Управление тактированием блока I2C 0 */
    RCC_PeriphClk_I2C1 = ((uint32_t)(1<<21)),       /*!< Управление тактированием блока I2C 1 */
    RCC_PeriphClk_ADC  = ((uint32_t)(1<<24))        /*!< Управление тактированием контроллера ADC */
}RCC_PeriphClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_PeriphClk_TypeDef.
  */

#define IS_RCC_PERIPH_CLK(PERIPH_CLK) (((PERIPH_CLK) == RCC_PeriphClk_QEP0) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_QEP1) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_CMP) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM0) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM1) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM2) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM3) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM4) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM5) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM6) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM7) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_PWM8) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_WD) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_I2C0) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_I2C1) || \
                                       ((PERIPH_CLK) == RCC_PeriphClk_ADC))

/**
  * @brief  Управление сбросом периферийных блоков
  */

typedef enum
{
    RCC_PeriphRst_WD,          /*!< Управление сбросом сторожевого таймера */
    RCC_PeriphRst_I2C0,        /*!< Управление сбросом блока I2C 0 */
    RCC_PeriphRst_I2C1,       /*!< Управление сбросом блока I2C 1 */
    RCC_PeriphRst_USB,         /*!< Управление сбросом блока USB */
    RCC_PeriphRst_Timer0,      /*!< Управление сбросом блока Timer 0 */
    RCC_PeriphRst_Timer1,      /*!< Управление сбросом блока Timer 1 */
    RCC_PeriphRst_Timer2,      /*!< Управление сбросом блока Timer 2 */
    RCC_PeriphRst_UART0,       /*!< Управление сбросом блока UART 0 */
    RCC_PeriphRst_UART1,       /*!< Управление сбросом блока UART 1 */
    RCC_PeriphRst_UART2,       /*!< Управление сбросом блока UART 2 */
    RCC_PeriphRst_UART3,       /*!< Управление сбросом блока UART 3 */
    RCC_PeriphRst_SPI0,        /*!< Управление сбросом блока SPI 0 */
    RCC_PeriphRst_SPI1,        /*!< Управление сбросом блока SPI 1 */
    RCC_PeriphRst_SPI2,        /*!< Управление сбросом блока SPI 2 */
    RCC_PeriphRst_SPI3,        /*!< Управление сбросом блока SPI 3 */
    RCC_PeriphRst_ETH ,        /*!< Управление сбросом блока Ethernet */
    RCC_PeriphRst_QEP0,        /*!< Управление сбросом блока QEP 0 */
    RCC_PeriphRst_QEP1,        /*!< Управление сбросом блока QEP 1 */
    RCC_PeriphRst_PWM0,        /*!< Управление сбросом блока PWM 0 */
    RCC_PeriphRst_PWM1,        /*!< Управление сбросом блока PWM 1 */
    RCC_PeriphRst_PWM2,        /*!< Управление сбросом блока PWM 2 */
    RCC_PeriphRst_PWM3,        /*!< Управление сбросом блока PWM 3 */
    RCC_PeriphRst_PWM4,        /*!< Управление сбросом блока PWM 4 */
    RCC_PeriphRst_PWM5,        /*!< Управление сбросом блока PWM 5 */
    RCC_PeriphRst_PWM6,        /*!< Управление сбросом блока PWM 6 */
    RCC_PeriphRst_PWM7,        /*!< Управление сбросом блока PWM 7 */
    RCC_PeriphRst_PWM8,        /*!< Управление сбросом блока PWM 8 */
    RCC_PeriphRst_CAP0,        /*!< Управление сбросом блока CAP 0 */
    RCC_PeriphRst_CAP1,        /*!< Управление сбросом блока CAP 1 */
    RCC_PeriphRst_CAP2,        /*!< Управление сбросом блока CAP 2 */
    RCC_PeriphRst_CAP3,        /*!< Управление сбросом блока CAP 3 */
    RCC_PeriphRst_CAP4,        /*!< Управление сбросом блока CAP 4 */
    RCC_PeriphRst_CAP5,        /*!< Управление сбросом блока CAP 5 */
    RCC_PeriphRst_CMP          /*!< Управление сбросом блока аналогового компаратора */
}RCC_PeriphRst_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RCC_PeriphRst_TypeDef.
  */

#define IS_RCC_PERIPH_RST(PERIPH_RST) (((PERIPH_RST) == RCC_PeriphRst_WD) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_I2C0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_I2C1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_USB) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_Timer0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_Timer1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_Timer2) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_UART0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_UART1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_UART2) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_UART3) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_SPI0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_SPI1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_SPI2) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_SPI3) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_ETH) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_QEP0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_QEP1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM2) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM3) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM4) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM5) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM6) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM7) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_PWM8) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP0) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP1) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP2) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP3) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP4) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CAP5) || \
                                       ((PERIPH_RST) == RCC_PeriphRst_CMP))

/**
  * @brief  Структура инициализации PLL
  *
  */

typedef struct
{
    uint32_t RCC_PLLDiv;                    /*!< Значение делителя сигнала на выходе блока PLL.
                                                 Параметр может принимать любое значение из диапазона 0-255. */
    RCC_PLLRef_TypeDef RCC_PLLRef;          /*!< Источник опорного сигнала PLL.
                                                 Параметр может принимать любое значение из @ref RCC_PLLRef_TypeDef. */
    RCC_PLLNO_TypeDef RCC_PLLNO;             /*!< Выходной делитель NO.
                                                 Параметр может принимать любое значение из @ref RCC_PLLNO_TypeDef. */
    uint32_t RCC_PLLNR;                     /*!< Опорный делитель NR.
                                                 Параметр может принимать любое значение из иапазона 2-33. */
    uint32_t RCC_PLLNF;                     /*!< Делитель обратной связи NF.
                                                 Параметр может принимать любое значение из иапазона 2-513. */
}RCC_PLLInit_TypeDef;

/**
  * @brief Макрос проверки значения выходного делителя PLL на попадание в допустимый диапазон.
  */

#define IS_RCC_PLLDIV(PLLDIV) (((PLLDIV) & ((uint32_t)0xFFFFFF00)) == ((uint32_t)0x00))

/**
  * @brief Макрос проверки значения опорного делителя PLL на попадание в допустимый диапазон.
  */

#define IS_RCC_PLL_NR(PLL_NR) (((PLL_NR) <= ((uint32_t)33)) && ((PLL_NR) >= ((uint32_t)2)))

/**
  * @brief Макрос проверки значения делителя ОС PLL на попадание в допустимый диапазон.
  */

#define IS_RCC_PLL_NF(PLL_NF) (((PLL_NF) <= ((uint32_t)513)) && ((PLL_NF) >= ((uint32_t)2)))

/**
  * @brief Макрос проверки значения делителя тактового сигнала на попадание в допустимый диапазон.
  */

#define IS_RCC_CLK_DIV(CLK_DIV) ((CLK_DIV) < ((uint32_t)64))

 /**
   * @brief Макрос проверки значения желаемой частоты при автонастройке в допустимый диапазон.
   */

 #define IS_RCC_SYS_FREQ(SYS_FREQ) (((SYS_FREQ) < ((uint32_t)100000000)) && ((SYS_FREQ) >= ((uint32_t)1000000)))

/**
  * @}
  */


/** @defgroup RCC_Exported_Functions Функции
  * @{
  */

void RCC_SysClkDiv2Out(FunctionalState State);

/** @defgroup RCC_Init_Deinit Конфигурация PLL
  * @{
  */

OperationStatus RCC_PLLAutoConfig(RCC_PLLRef_TypeDef RCC_PLLRef, uint32_t SysFreq);
void RCC_PLLInit(RCC_PLLInit_TypeDef* RCC_PLLInit_Struct);
void RCC_PLLDeInit(void);
void RCC_PLLStructInit(RCC_PLLInit_TypeDef* RCC_PLLInit_Struct);
void RCC_PLLPowerDownCmd(FunctionalState State);

/**
  * @}
  */

/** @defgroup RCC_CLK_Config Управление тактированием
  * @{
  */

void RCC_PeriphClkCmd(RCC_PeriphClk_TypeDef RCC_PeriphClk, FunctionalState State);
OperationStatus RCC_SysClkSel(RCC_SysClk_TypeDef RCC_SysClk);
RCC_SysClk_TypeDef RCC_SysClkStatus(void);

/** @defgroup RCC_CLK_Config_USB Тактирование USB
  * @{
  */

void RCC_USBClkConfig(RCC_USBClk_TypeDef RCC_USBClk, RCC_USBFreq_TypeDef RCC_USBFreq, FunctionalState State);

/**
  * @}
  */

/** @defgroup RCC_CLK_Config_UART Тактирование UART
  * @{
  */

void RCC_UARTClkSel(NT_UART_TypeDef* UARTx, RCC_UARTClk_TypeDef RCC_UARTClk);
void RCC_UARTClkDivConfig(NT_UART_TypeDef* UARTx, uint32_t DivVal, FunctionalState DivState);
void RCC_UARTClkCmd(NT_UART_TypeDef* UARTx, FunctionalState State);

/**
  * @}
  */

/** @defgroup RCC_CLK_Config_SPI Тактирование SPI
  * @{
  */

void RCC_SPIClkSel(NT_SPI_TypeDef* SPIx, RCC_SPIClk_TypeDef RCC_SPIClk);
void RCC_SPIClkDivConfig(NT_SPI_TypeDef* SPIx, uint32_t DivVal, FunctionalState DivState);
void RCC_SPIClkCmd(NT_SPI_TypeDef* SPIx, FunctionalState State);

/**
  * @}
  */

/** @defgroup RCC_CLK_Config_ADC Тактирование ADC
  * @{
  */

void RCC_ADCClkDivConfig(RCC_ADCClk_TypeDef RCC_ADCClk, uint32_t DivVal, FunctionalState DivState);
void RCC_ADCClkCmd(RCC_ADCClk_TypeDef RCC_ADCClk, FunctionalState State);

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCC_RST_Config Управление сбросом
  * @{
  */

void RCC_PeriphRstCmd(RCC_PeriphRst_TypeDef RCC_PeriphRst, FunctionalState State);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_RCC_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
