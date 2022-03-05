/**
  ******************************************************************************
  * @file    niietcm4_adc.h
  *
  * @brief   Файл содержит все прототипы функций для работы с АЦП, секвенсорами,
  *          цифровыми компараторами.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    10.12.2015
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
#ifndef __NIIETCM4_ADC_H
#define __NIIETCM4_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Constants Константы
  * @{
  */

/** @defgroup ADC_Exported_Constants_Сhan Маски каналов для измерений
  * @{
  */
#define ADC_Channel_None          ((uint32_t)0x00000000)  /*!< Канал ADC не выбран */
#define ADC_Channel_0             ((uint32_t)0x00000001)  /*!< Канал ADC 0 */
#define ADC_Channel_1             ((uint32_t)0x00000002)  /*!< Канал ADC 1 */
#define ADC_Channel_2             ((uint32_t)0x00000004)  /*!< Канал ADC 2 */
#define ADC_Channel_3             ((uint32_t)0x00000008)  /*!< Канал ADC 3 */
#define ADC_Channel_4             ((uint32_t)0x00000010)  /*!< Канал ADC 4 */
#define ADC_Channel_5             ((uint32_t)0x00000020)  /*!< Канал ADC 5 */
#define ADC_Channel_6             ((uint32_t)0x00000040)  /*!< Канал ADC 6 */
#define ADC_Channel_7             ((uint32_t)0x00000080)  /*!< Канал ADC 7 */
#define ADC_Channel_8             ((uint32_t)0x00000100)  /*!< Канал ADC 8 */
#define ADC_Channel_9             ((uint32_t)0x00000200)  /*!< Канал ADC 9 */
#define ADC_Channel_10            ((uint32_t)0x00000400)  /*!< Канал ADC 10 */
#define ADC_Channel_11            ((uint32_t)0x00000800)  /*!< Канал ADC 11 */
#define ADC_Channel_12            ((uint32_t)0x00001000)  /*!< Канал ADC 12 */
#define ADC_Channel_13            ((uint32_t)0x00002000)  /*!< Канал ADC 13 */
#define ADC_Channel_14            ((uint32_t)0x00004000)  /*!< Канал ADC 14 */
#define ADC_Channel_15            ((uint32_t)0x00008000)  /*!< Канал ADC 15 */
#define ADC_Channel_16            ((uint32_t)0x00010000)  /*!< Канал ADC 16 */
#define ADC_Channel_17            ((uint32_t)0x00020000)  /*!< Канал ADC 17 */
#define ADC_Channel_18            ((uint32_t)0x00040000)  /*!< Канал ADC 18 */
#define ADC_Channel_19            ((uint32_t)0x00080000)  /*!< Канал ADC 19 */
#define ADC_Channel_20            ((uint32_t)0x00100000)  /*!< Канал ADC 20 */
#define ADC_Channel_21            ((uint32_t)0x00200000)  /*!< Канал ADC 21 */
#define ADC_Channel_22            ((uint32_t)0x00400000)  /*!< Канал ADC 22 */
#define ADC_Channel_23            ((uint32_t)0x00800000)  /*!< Канал ADC 23 */
#define ADC_Channel_All           ((uint32_t)0x00FFFFFF)  /*!< Все каналы */
/**
  * @brief Макрос проверки попадания масок каналов в допустимый диапазон.
  */

#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) & (uint32_t)0xFF000000) == ((uint32_t)0x000000))

/**
  * @}
  */

/** @defgroup ADC_Exported_Constants_DC Маски выбора цифровых компараторов
  * @{
  */

#define ADC_DC_None     ((uint32_t)0x00000000)  /*!< Цифровой компаратор не выбран */
#define ADC_DC_0        ((uint32_t)0x00000001)  /*!< Цифровой компаратор 0 */
#define ADC_DC_1        ((uint32_t)0x00000002)  /*!< Цифровой компаратор 1 */
#define ADC_DC_2        ((uint32_t)0x00000004)  /*!< Цифровой компаратор 2 */
#define ADC_DC_3        ((uint32_t)0x00000008)  /*!< Цифровой компаратор 3 */
#define ADC_DC_4        ((uint32_t)0x00000010)  /*!< Цифровой компаратор 4 */
#define ADC_DC_5        ((uint32_t)0x00000020)  /*!< Цифровой компаратор 5 */
#define ADC_DC_6        ((uint32_t)0x00000040)  /*!< Цифровой компаратор 6 */
#define ADC_DC_7        ((uint32_t)0x00000080)  /*!< Цифровой компаратор 7 */
#define ADC_DC_8        ((uint32_t)0x00000100)  /*!< Цифровой компаратор 8 */
#define ADC_DC_9        ((uint32_t)0x00000200)  /*!< Цифровой компаратор 9 */
#define ADC_DC_10       ((uint32_t)0x00000400)  /*!< Цифровой компаратор 10 */
#define ADC_DC_11       ((uint32_t)0x00000800)  /*!< Цифровой компаратор 11 */
#define ADC_DC_12       ((uint32_t)0x00001000)  /*!< Цифровой компаратор 12 */
#define ADC_DC_13       ((uint32_t)0x00002000)  /*!< Цифровой компаратор 13 */
#define ADC_DC_14       ((uint32_t)0x00004000)  /*!< Цифровой компаратор 14 */
#define ADC_DC_15       ((uint32_t)0x00008000)  /*!< Цифровой компаратор 15 */
#define ADC_DC_16       ((uint32_t)0x00010000)  /*!< Цифровой компаратор 16 */
#define ADC_DC_17       ((uint32_t)0x00020000)  /*!< Цифровой компаратор 17 */
#define ADC_DC_18       ((uint32_t)0x00040000)  /*!< Цифровой компаратор 18 */
#define ADC_DC_19       ((uint32_t)0x00080000)  /*!< Цифровой компаратор 19 */
#define ADC_DC_20       ((uint32_t)0x00100000)  /*!< Цифровой компаратор 20 */
#define ADC_DC_21       ((uint32_t)0x00200000)  /*!< Цифровой компаратор 21 */
#define ADC_DC_22       ((uint32_t)0x00400000)  /*!< Цифровой компаратор 22 */
#define ADC_DC_23       ((uint32_t)0x00800000)  /*!< Цифровой компаратор 23 */
#define ADC_DC_All      ((uint32_t)0x00FFFFFF)  /*!< Все цифровые компараторы */

/**
  * @brief Макрос проверки попадания масок компараторов в допустимый диапазон.
  */

#define IS_ADC_DC(DC) (((DC) & (uint32_t)0xFF000000) == ((uint32_t)0x000000))

/**
  * @}
  */

/** @defgroup ADC_Exported_Constants_SEQ Маски выбора секвенсоров
  * @{
  */

#define ADC_SEQ_0        ((uint32_t)0x00000001)  /*!< Секвенсор 0 */
#define ADC_SEQ_1        ((uint32_t)0x00000002)  /*!< Секвенсор 1 */
#define ADC_SEQ_2        ((uint32_t)0x00000004)  /*!< Секвенсор 2 */
#define ADC_SEQ_3        ((uint32_t)0x00000008)  /*!< Секвенсор 3 */
#define ADC_SEQ_4        ((uint32_t)0x00000010)  /*!< Секвенсор 4 */
#define ADC_SEQ_5        ((uint32_t)0x00000020)  /*!< Секвенсор 5 */
#define ADC_SEQ_6        ((uint32_t)0x00000040)  /*!< Секвенсор 6 */
#define ADC_SEQ_7        ((uint32_t)0x00000080)  /*!< Секвенсор 7 */

/**
  * @brief Макрос проверки попадания масок секвенсоров в допустимый диапазон.
  */

#define IS_ADC_SEQ(SEQ) (((SEQ) != (uint32_t)0x00000000) && (((SEQ) & (uint32_t)0xFFFFFF00) == ((uint32_t)0x00)))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADC_Exported_Types Типы
  * @{
  */

/**
  * @brief Проверка значения количества перезапусков модулей АЦП секвенсором
  *   после которого генерируется прерывание, на попадание в допустимый диапазон.
  */

#define IS_ADC_SEQ_IT_RATE(IT_RATE) (((IT_RATE) > ((uint32_t)0x0)) && ((IT_RATE) < ((uint32_t)0x100)))

/**
  * @brief Проверка значения количества перезапусков модулей АЦП секвенсором после запуска секвенсора по событию
  *   на попадание в допустимый диапазон.
  */

#define IS_ADC_SEQ_CONVERSION_COUNT(CONVERSION_COUNT) (((CONVERSION_COUNT) > ((uint32_t)0x0)) && ((CONVERSION_COUNT) <= ((uint32_t)0x100)))

/**
  * @brief Проверка значения задержки запуска преобразования модулем АЦП на попадание в допустимый диапазон.
  */

#define IS_ADC_SEQ_CONVERSION_DELAY(CONVERSION_DELAY) ((CONVERSION_DELAY) < ((uint32_t)0x1000000))

/**
  * @brief Проверка значения задержки начала преобразования модулем АЦП после запуска модуля секвенсором
  *   на попадание в допустимый диапазон.
  */

#define IS_ADC_PHASE(PHASE) ((PHASE) < ((uint32_t)0x1000))

/**
  * @brief Проверка значения порога диапазона срабатывания компаратора на попадание в допустимый диапазон.
  */

#define IS_ADC_DC_THRESHOLD(THRESHOLD) ((THRESHOLD) < ((uint32_t)0x1000))

/**
  * @brief  События запуска секвенсоров.
  */

typedef enum
{
    ADC_SEQ_StartEvent_SWReq   = ((uint32_t)0x0),    /*!< Запуск по программному запросу. */
    ADC_SEQ_StartEvent_CMP0    = ((uint32_t)0x1),    /*!< Сигнал от блока аналогового компаратора 0. */
    ADC_SEQ_StartEvent_CMP1    = ((uint32_t)0x2),    /*!< Сигнал от блока аналогового компаратора 1. */
    ADC_SEQ_StartEvent_CMP2    = ((uint32_t)0x3),    /*!< Сигнал от блока аналогового компаратора 2. */
    ADC_SEQ_StartEvent_ITGPIO  = ((uint32_t)0x4),    /*!< Любое прерывание GPIO. */
    ADC_SEQ_StartEvent_TIM     = ((uint32_t)0x5),    /*!< Сигнал от блока таймеров. */
    ADC_SEQ_StartEvent_PWM012A = ((uint32_t)0x6),    /*!< Сигналы A от блоков ШИМ 0, 1, 2. */
    ADC_SEQ_StartEvent_PWM012B = ((uint32_t)0x7),    /*!< Сигналы B от блоков ШИМ 0, 1, 2. */
    ADC_SEQ_StartEvent_PWM345A = ((uint32_t)0x8),    /*!< Сигналы A от блоков ШИМ 3, 4, 5. */
    ADC_SEQ_StartEvent_PWM345B = ((uint32_t)0x9),    /*!< Сигналы B от блоков ШИМ 3, 4, 5. */
    ADC_SEQ_StartEvent_PWM678A = ((uint32_t)0xA),    /*!< Сигналы A от блоков ШИМ 6, 7, 8. */
    ADC_SEQ_StartEvent_PWM678B = ((uint32_t)0xB),    /*!< Сигналы B от блоков ШИМ 6, 7, 8. */
    ADC_SEQ_StartEvent_Cycle   = ((uint32_t)0xF),    /*!< Циклическая работа сразу после запуска секвенсора */
}ADC_SEQ_StartEvent_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_SEQ_StartEvent_TypeDef.
  */

#define IS_ADC_SEQ_START_EVENT(START_EVENT)  (((START_EVENT) == ADC_SEQ_StartEvent_SWReq)  || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_CMP0)   || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_CMP1)   || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_CMP2)   || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_ITGPIO) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_TIM)    || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM012A) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM012B) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM345A) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM345B) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM678A) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_PWM678B) || \
                                              ((START_EVENT) == ADC_SEQ_StartEvent_Cycle))

/**
  * @brief  Количество измерений, используемых для получения результата преобразования.
  */

typedef enum
{
    ADC_Average_Disable,    /*!< Усреднители не используются. */
    ADC_Average_2,          /*!< Усреднение по 2 измерениям. */
    ADC_Average_4,          /*!< Усреднение по 4 измерениям. */
    ADC_Average_8,          /*!< Усреднение по 8 измерениям. */
    ADC_Average_16,         /*!< Усреднение по 16 измерениям. */
    ADC_Average_32,         /*!< Усреднение по 32 измерениям. */
    ADC_Average_64,         /*!< Усреднение по 64 измерениям. */
}ADC_Average_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_Average_TypeDef.
  */

#define IS_ADC_AVERAGE(AVERAGE)  (((AVERAGE) == ADC_Average_Disable) || \
                                  ((AVERAGE) == ADC_Average_2)       || \
                                  ((AVERAGE) == ADC_Average_4)       || \
                                  ((AVERAGE) == ADC_Average_8)       || \
                                  ((AVERAGE) == ADC_Average_16)      || \
                                  ((AVERAGE) == ADC_Average_32)      || \
                                  ((AVERAGE) == ADC_Average_64))

/**
  * @brief  Выбор канала, подключаемого к цифровому компаратору.
  */

typedef enum
{
    ADC_DC_Channel_0,          /*!< Результат с канала 0 будет передан на компаратор. */
    ADC_DC_Channel_1,          /*!< Результат с канала 1 будет передан на компаратор. */
    ADC_DC_Channel_2,          /*!< Результат с канала 2 будет передан на компаратор. */
    ADC_DC_Channel_3,          /*!< Результат с канала 3 будет передан на компаратор. */
    ADC_DC_Channel_4,          /*!< Результат с канала 4 будет передан на компаратор. */
    ADC_DC_Channel_5,          /*!< Результат с канала 5 будет передан на компаратор. */
    ADC_DC_Channel_6,          /*!< Результат с канала 6 будет передан на компаратор. */
    ADC_DC_Channel_7,          /*!< Результат с канала 7 будет передан на компаратор. */
    ADC_DC_Channel_8,          /*!< Результат с канала 8 будет передан на компаратор. */
    ADC_DC_Channel_9,          /*!< Результат с канала 9 будет передан на компаратор. */
    ADC_DC_Channel_10,         /*!< Результат с канала 10 будет передан на компаратор. */
    ADC_DC_Channel_11,         /*!< Результат с канала 11 будет передан на компаратор. */
    ADC_DC_Channel_12,         /*!< Результат с канала 12 будет передан на компаратор. */
    ADC_DC_Channel_13,         /*!< Результат с канала 13 будет передан на компаратор. */
    ADC_DC_Channel_14,         /*!< Результат с канала 14 будет передан на компаратор. */
    ADC_DC_Channel_15,         /*!< Результат с канала 15 будет передан на компаратор. */
    ADC_DC_Channel_16,         /*!< Результат с канала 16 будет передан на компаратор. */
    ADC_DC_Channel_17,         /*!< Результат с канала 17 будет передан на компаратор. */
    ADC_DC_Channel_18,         /*!< Результат с канала 18 будет передан на компаратор. */
    ADC_DC_Channel_19,         /*!< Результат с канала 19 будет передан на компаратор. */
    ADC_DC_Channel_20,         /*!< Результат с канала 20 будет передан на компаратор. */
    ADC_DC_Channel_21,         /*!< Результат с канала 21 будет передан на компаратор. */
    ADC_DC_Channel_22,         /*!< Результат с канала 22 будет передан на компаратор. */
    ADC_DC_Channel_23,         /*!< Результат с канала 23 будет передан на компаратор. */
    ADC_DC_Channel_None,       /*!< Ни один из каналов не подключен к компаратору. */
}ADC_DC_Channel_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_DC_Channel_TypeDef.
  */

#define IS_ADC_DC_CHANNEL(CHANNEL)  (((CHANNEL) == ADC_DC_Channel_0)  || \
                                     ((CHANNEL) == ADC_DC_Channel_1)  || \
                                     ((CHANNEL) == ADC_DC_Channel_2)  || \
                                     ((CHANNEL) == ADC_DC_Channel_3)  || \
                                     ((CHANNEL) == ADC_DC_Channel_4)  || \
                                     ((CHANNEL) == ADC_DC_Channel_5)  || \
                                     ((CHANNEL) == ADC_DC_Channel_6)  || \
                                     ((CHANNEL) == ADC_DC_Channel_7)  || \
                                     ((CHANNEL) == ADC_DC_Channel_8)  || \
                                     ((CHANNEL) == ADC_DC_Channel_9)  || \
                                     ((CHANNEL) == ADC_DC_Channel_10) || \
                                     ((CHANNEL) == ADC_DC_Channel_11) || \
                                     ((CHANNEL) == ADC_DC_Channel_12) || \
                                     ((CHANNEL) == ADC_DC_Channel_13) || \
                                     ((CHANNEL) == ADC_DC_Channel_14) || \
                                     ((CHANNEL) == ADC_DC_Channel_15) || \
                                     ((CHANNEL) == ADC_DC_Channel_16) || \
                                     ((CHANNEL) == ADC_DC_Channel_17) || \
                                     ((CHANNEL) == ADC_DC_Channel_18) || \
                                     ((CHANNEL) == ADC_DC_Channel_19) || \
                                     ((CHANNEL) == ADC_DC_Channel_20) || \
                                     ((CHANNEL) == ADC_DC_Channel_21) || \
                                     ((CHANNEL) == ADC_DC_Channel_22) || \
                                     ((CHANNEL) == ADC_DC_Channel_23) || \
                                     ((CHANNEL) == ADC_DC_Channel_None))

/**
  * @brief  Режим срабатывания компаратора.
  */

typedef enum
{
    ADC_DC_Mode_Multiple,          /*!< Многократный. */
    ADC_DC_Mode_Single,            /*!< Однократный. */
    ADC_DC_Mode_MultipleHyst,      /*!< Многократный с гистерезисом. */
    ADC_DC_Mode_SingleHyst,        /*!< Однократный с гистерезисом. */ 
}ADC_DC_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_DC_Mode_TypeDef.
  */

#define IS_ADC_DC_MODE(MODE)  (((MODE) == ADC_DC_Mode_Single)     || \
                               ((MODE) == ADC_DC_Mode_Multiple)   || \
                               ((MODE) == ADC_DC_Mode_SingleHyst) || \
                               ((MODE) == ADC_DC_Mode_MultipleHyst))

/**
  * @brief  Условие срабатывания компаратора.
  */

typedef enum
{
    ADC_DC_Condition_Low    = ((uint32_t)0),    /*!< Результат меньше либо равен нижней границе. */
    ADC_DC_Condition_Window = ((uint32_t)1),    /*!< Результат внутри диапазона, задаваемого границами, либо равен одной из них. */
    ADC_DC_Condition_High   = ((uint32_t)3),    /*!< Результат выше либо равен верхней границе. */
}ADC_DC_Condition_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_DC_Condition_TypeDef.
  */

#define IS_ADC_DC_CONDITION(CONDITION)  (((CONDITION) == ADC_DC_Condition_Low)    || \
                                         ((CONDITION) == ADC_DC_Condition_Window) || \
                                         ((CONDITION) == ADC_DC_Condition_High))

/**
  * @brief  Количество результатов измерений записанных в буфер секвенсора, по достижению которого вызывается DMA.
  */

typedef enum
{
    ADC_SEQ_FIFOLevel_1  = ((uint32_t)1),    /*!< Запрос DMA после заполнения 1 ячейки в буффере. */
    ADC_SEQ_FIFOLevel_2  = ((uint32_t)2),    /*!< Запрос DMA после заполнения 2 ячеек в буффере. */
    ADC_SEQ_FIFOLevel_4  = ((uint32_t)3),    /*!< Запрос DMA после заполнения 4 ячеек в буффере. */
    ADC_SEQ_FIFOLevel_8  = ((uint32_t)4),    /*!< Запрос DMA после заполнения 8 ячеек в буффере. */
    ADC_SEQ_FIFOLevel_16 = ((uint32_t)5),    /*!< Запрос DMA после заполнения 16 ячеек в буффере. */
    ADC_SEQ_FIFOLevel_32 = ((uint32_t)6),    /*!< Запрос DMA после заполнения 32 ячеек в буффере. */
}ADC_SEQ_FIFOLevel_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_SEQ_FIFOLevel_TypeDef.
  */

#define IS_ADC_SEQ_FIFO_LEVEL(FIFO_LEVEL)  (((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_1)  || \
                                            ((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_2)  || \
                                            ((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_4)  || \
                                            ((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_8)  || \
                                            ((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_16) || \
                                            ((FIFO_LEVEL) == ADC_SEQ_FIFOLevel_32))

/**
  * @brief  Выбор модуля цифрового компаратора.
  */

typedef enum
{
    ADC_DC_Module_0,          /*!< Модуль цифрового компаратора 0. */
    ADC_DC_Module_1,          /*!< Модуль цифрового компаратора 1 */
    ADC_DC_Module_2,          /*!< Модуль цифрового компаратора 2 */
    ADC_DC_Module_3,          /*!< Модуль цифрового компаратора 3 */
    ADC_DC_Module_4,          /*!< Модуль цифрового компаратора 4 */
    ADC_DC_Module_5,          /*!< Модуль цифрового компаратора 5 */
    ADC_DC_Module_6,          /*!< Модуль цифрового компаратора 6 */
    ADC_DC_Module_7,          /*!< Модуль цифрового компаратора 7 */
    ADC_DC_Module_8,          /*!< Модуль цифрового компаратора 8 */
    ADC_DC_Module_9,          /*!< Модуль цифрового компаратора 9 */
    ADC_DC_Module_10,         /*!< Модуль цифрового компаратора 10 */
    ADC_DC_Module_11,         /*!< Модуль цифрового компаратора 11 */
    ADC_DC_Module_12,         /*!< Модуль цифрового компаратора 12 */
    ADC_DC_Module_13,         /*!< Модуль цифрового компаратора 13 */
    ADC_DC_Module_14,         /*!< Модуль цифрового компаратора 14 */
    ADC_DC_Module_15,         /*!< Модуль цифрового компаратора 15 */
    ADC_DC_Module_16,         /*!< Модуль цифрового компаратора 16 */
    ADC_DC_Module_17,         /*!< Модуль цифрового компаратора 17 */
    ADC_DC_Module_18,         /*!< Модуль цифрового компаратора 18 */
    ADC_DC_Module_19,         /*!< Модуль цифрового компаратора 19 */
    ADC_DC_Module_20,         /*!< Модуль цифрового компаратора 20 */
    ADC_DC_Module_21,         /*!< Модуль цифрового компаратора 21 */
    ADC_DC_Module_22,         /*!< Модуль цифрового компаратора 22 */
    ADC_DC_Module_23,         /*!< Модуль цифрового компаратора 23 */
}ADC_DC_Module_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_DC_Module_TypeDef.
  */

#define IS_ADC_DC_MODULE(MODULE)  (((MODULE) == ADC_DC_Module_0)  || \
                                   ((MODULE) == ADC_DC_Module_1)  || \
                                   ((MODULE) == ADC_DC_Module_2)  || \
                                   ((MODULE) == ADC_DC_Module_3)  || \
                                   ((MODULE) == ADC_DC_Module_4)  || \
                                   ((MODULE) == ADC_DC_Module_5)  || \
                                   ((MODULE) == ADC_DC_Module_6)  || \
                                   ((MODULE) == ADC_DC_Module_7)  || \
                                   ((MODULE) == ADC_DC_Module_8)  || \
                                   ((MODULE) == ADC_DC_Module_9)  || \
                                   ((MODULE) == ADC_DC_Module_10) || \
                                   ((MODULE) == ADC_DC_Module_11) || \
                                   ((MODULE) == ADC_DC_Module_12) || \
                                   ((MODULE) == ADC_DC_Module_13) || \
                                   ((MODULE) == ADC_DC_Module_14) || \
                                   ((MODULE) == ADC_DC_Module_15) || \
                                   ((MODULE) == ADC_DC_Module_16) || \
                                   ((MODULE) == ADC_DC_Module_17) || \
                                   ((MODULE) == ADC_DC_Module_18) || \
                                   ((MODULE) == ADC_DC_Module_19) || \
                                   ((MODULE) == ADC_DC_Module_20) || \
                                   ((MODULE) == ADC_DC_Module_21) || \
                                   ((MODULE) == ADC_DC_Module_22) || \
                                   ((MODULE) == ADC_DC_Module_23))

/**
  * @brief  Выбор модуля секвенсора.
  */

typedef enum
{
    ADC_SEQ_Module_0,          /*!< Севенсор 0.*/
    ADC_SEQ_Module_1,          /*!< Севенсор 1 */
    ADC_SEQ_Module_2,          /*!< Севенсор 2 */
    ADC_SEQ_Module_3,          /*!< Севенсор 3 */
    ADC_SEQ_Module_4,          /*!< Севенсор 4 */
    ADC_SEQ_Module_5,          /*!< Севенсор 5 */
    ADC_SEQ_Module_6,          /*!< Севенсор 6 */
    ADC_SEQ_Module_7,          /*!< Севенсор 7 */
}ADC_SEQ_Module_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_SEQ_Module_TypeDef.
  */

#define IS_ADC_SEQ_MODULE(MODULE)  (((MODULE) == ADC_SEQ_Module_0)  || \
                                    ((MODULE) == ADC_SEQ_Module_1)  || \
                                    ((MODULE) == ADC_SEQ_Module_2)  || \
                                    ((MODULE) == ADC_SEQ_Module_3)  || \
                                    ((MODULE) == ADC_SEQ_Module_4)  || \
                                    ((MODULE) == ADC_SEQ_Module_5)  || \
                                    ((MODULE) == ADC_SEQ_Module_6)  || \
                                    ((MODULE) == ADC_SEQ_Module_7))

/**
  * @brief  Выбор модуля АЦП.
  */

typedef enum
{
    ADC_Module_0,          /*!< Модуль АЦП 0. */
    ADC_Module_1,          /*!< Модуль АЦП 1 */
    ADC_Module_2,          /*!< Модуль АЦП 2 */
    ADC_Module_3,          /*!< Модуль АЦП 3 */
    ADC_Module_4,          /*!< Модуль АЦП 4 */
    ADC_Module_5,          /*!< Модуль АЦП 5 */
    ADC_Module_6,          /*!< Модуль АЦП 6 */
    ADC_Module_7,          /*!< Модуль АЦП 7 */
    ADC_Module_8,          /*!< Модуль АЦП 8 */
    ADC_Module_9,          /*!< Модуль АЦП 9 */
    ADC_Module_10,         /*!< Модуль АЦП 10 */
    ADC_Module_11,         /*!< Модуль АЦП 11 */
}ADC_Module_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_Module_TypeDef.
  */

#define IS_ADC_MODULE(MODULE)  (((MODULE) == ADC_Module_0)  || \
                                ((MODULE) == ADC_Module_1)  || \
                                ((MODULE) == ADC_Module_2)  || \
                                ((MODULE) == ADC_Module_3)  || \
                                ((MODULE) == ADC_Module_4)  || \
                                ((MODULE) == ADC_Module_5)  || \
                                ((MODULE) == ADC_Module_6)  || \
                                ((MODULE) == ADC_Module_7)  || \
                                ((MODULE) == ADC_Module_8)  || \
                                ((MODULE) == ADC_Module_9)  || \
                                ((MODULE) == ADC_Module_10) || \
                                ((MODULE) == ADC_Module_11))

/**
  * @brief  Выбор разрядности модуля АЦП.
  */

typedef enum
{
    ADC_Resolution_12bit,          /*!< Разрядность модуля 12 бит. */
    ADC_Resolution_10bit,          /*!< Разрядность модуля 10 бит */
}ADC_Resolution_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_Resolution_TypeDef.
  */

#define IS_ADC_RESOLUTION(RESOLUTION)  (((RESOLUTION) == ADC_Resolution_12bit) || \
                                        ((RESOLUTION) == ADC_Resolution_10bit))

/**
  * @brief  Выбор режима работы АЦП.
  */

typedef enum
{
    ADC_Measure_Single,         /*!< Однополярный режим измерения по каналу. */
    ADC_Measure_Diff,           /*!< Дифференциальный режим с противоположным каналом. */
}ADC_Measure_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_Measure_TypeDef.
  */

#define IS_ADC_MEASURE(MEASURE)  (((MEASURE) == ADC_Measure_Single) || \
                                  ((MEASURE) == ADC_Measure_Diff))

/**
  * @brief  Выбор режима работы АЦП.
  */

typedef enum
{
    ADC_Mode_Powerdown = ((uint32_t)0),     /*!< Модуль выключен. */
    ADC_Mode_StandBy   = ((uint32_t)1),     /*!< Режим ожидания. */
    ADC_Mode_Active    = ((uint32_t)3),     /*!< Модуль включен. */
}ADC_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref ADC_Mode_TypeDef.
  */

#define IS_ADC_MODE(MODE)  (((MODE) == ADC_Mode_Powerdown) || \
                            ((MODE) == ADC_Mode_StandBy) || \
                            ((MODE) == ADC_Mode_Active))

/**
  * @brief  Структура инициализации модулей АЦП
  * @attention Нельзя устанавливать оба канала в дифференциальный режим (параметры @ref ADC_Measure_A и @ref ADC_Measure_B).
  */

typedef struct
{
    ADC_Resolution_TypeDef ADC_Resolution;  /*!< Определяет разрядность модуля АЦП.
                                                Параметр может принимать любое значение из @ref ADC_Resolution_TypeDef. */
    ADC_Measure_TypeDef ADC_Measure_A;      /*!< Определяет режим измерения по каналу A: однополярный и дифференциальный (A-B).
                                                Параметр может принимать любое значение из @ref ADC_Measure_TypeDef. */
    ADC_Measure_TypeDef ADC_Measure_B;      /*!< Определяет режим измерения по каналу B: однополярный и дифференциальный (B-A).
                                                Параметр может принимать любое значение из @ref ADC_Measure_TypeDef. */
    uint32_t ADC_Phase;                     /*!< Фазовая задержка начала преобразования модулем АЦП после запуска модуля секвенсором.
                                                Параметр может принимать любое значение из диапазона 0 - 4095. */
    ADC_Average_TypeDef ADC_Average;        /*!< Количество измерений, используемых для получения результата преобразования.
                                                Параметр может принимать любое значение из @ref ADC_Average_TypeDef. */
    ADC_Mode_TypeDef ADC_Mode;              /*!< Определяет режим работы модуля АЦП.
                                                Параметр может принимать любое значение из @ref ADC_Mode_TypeDef. */
}ADC_Init_TypeDef;

/**
  * @brief  Структура инициализации цифровых компараторов.
  * @attention
  *   - Условие срабатывания по попаданию в диапазон не работает с гистерезисными режимами работы.
  *   - Должно всегда выполнятся условие ADC_DC_ThresholdLow <= ADC_DC_ThresholdHigh.
  */

typedef struct
{
    uint32_t ADC_DC_ThresholdLow;               /*!< Нижний порог срабатывания компаратора.
                                                    Параметр может принимать любое значение из диапазона 0 - 4095. */
    uint32_t ADC_DC_ThresholdHigh;              /*!< Верхний порог срабатывания компаратора.
                                                    Параметр может принимать любое значение из диапазона 0 - 4095. */
    ADC_DC_Channel_TypeDef ADC_DC_Channel;      /*!< Выбирает канал, результат измерения которого будет передан на компаратор.
                                                    Параметр может принимать любое значение из @ref ADC_DC_Channel_TypeDef. */
    ADC_DC_Mode_TypeDef ADC_DC_Mode;            /*!< Выбирает режим срабатывания компаратора.
                                                    Параметр может принимать любое значение из @ref ADC_DC_Mode_TypeDef. */
    ADC_DC_Condition_TypeDef ADC_DC_Condition;  /*!< Выбирает условие срабатывания компаратора.
                                                    Параметр может принимать любое значение из @ref ADC_DC_Condition_TypeDef. */
}ADC_DC_Init_TypeDef;

/**
  * @brief  Структура инициализации секвенсоров.
  */

typedef struct
{
    ADC_SEQ_StartEvent_TypeDef ADC_SEQ_StartEvent;  /*!< Определяет cобытие запуска секвенсора.
                                                        Параметр может принимать любое значение из @ref ADC_SEQ_StartEvent_TypeDef. */
    FunctionalState ADC_SEQ_SWReqEn;                /*!< Разрешает секвенсору запускаться по программному запросу.
                                                        Параметр может принимать любое значение из @ref FunctionalState. */
    uint32_t ADC_Channels;                          /*!< Выбор каналов для измерений.
                                                        Параметр может принимать любую совокупность значений из @ref ADC_Exported_Constants_Сhan. */
    uint32_t ADC_SEQ_ConversionCount;               /*!< Задание количества перезапусков модулей АЦП секвенсором после его запуска по событию.
                                                        Параметр может принимать любое значение из диапазона 1 - 256. */
    uint32_t ADC_SEQ_ConversionDelay;               /*!< Задание задержки запуска модуля АЦП.
                                                        Параметр может принимать любое значение из диапазона 0x00000000 - 0x00FFFFFF. */
    uint32_t ADC_SEQ_DC;                            /*!< Разрешение работы цифрового компаратора секвенсором.
                                                        Параметр может принимать любую совокупность значений из @ref ADC_Exported_Constants_DC. */
}ADC_SEQ_Init_TypeDef;

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions Функции
  * @{
  */

/** @defgroup ADC_Exported_Functions_Init Инциализация
  * @{
  */

/** @defgroup ADC_Exported_Functions_Init_ADC Модули АЦП
  * @{
  */

void ADC_DeInit(ADC_Module_TypeDef ADC_Module);
void ADC_Init(ADC_Module_TypeDef ADC_Module, ADC_Init_TypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_Init_TypeDef* ADC_InitStruct);

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Init_DC Цифровые компараторы
  * @{
  */


void ADC_DC_DeInit(ADC_DC_Module_TypeDef ADC_DC_Module);
void ADC_DC_Init(ADC_DC_Module_TypeDef ADC_DC_Module, ADC_DC_Init_TypeDef* ADC_DC_InitStruct);
void ADC_DC_StructInit(ADC_DC_Init_TypeDef* ADC_DC_InitStruct);

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Init_SEQ Секвенсоры
  * @{
  */

void ADC_SEQ_DeInit(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_Init(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, ADC_SEQ_Init_TypeDef* ADC_SEQ_InitStruct);
void ADC_SEQ_StructInit(ADC_SEQ_Init_TypeDef* ADC_SEQ_InitStruct);

/**
  * @}
  */

/**
  * @}
  */

void ADC_Cmd(ADC_Module_TypeDef ADC_Module, FunctionalState State);
void ADC_SEQ_Cmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State);
void ADC_SEQ_SWReq(void);
uint32_t ADC_SEQ_GetFIFOData(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
uint32_t ADC_SEQ_GetConversionCount(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
uint32_t ADC_SEQ_GetFIFOLoad(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
FlagStatus ADC_SEQ_FIFOFullStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_FIFOFullStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
FlagStatus ADC_SEQ_FIFOEmptyStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_FIFOEmptyStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);

void ADC_DC_Cmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State);
FlagStatus ADC_DC_TrigStatus(ADC_DC_Module_TypeDef ADC_DC_Module);
void ADC_DC_TrigStatusClear(ADC_DC_Module_TypeDef ADC_DC_Module);
uint32_t ADC_DC_GetLastData(ADC_DC_Module_TypeDef ADC_DC_Module);

/** @defgroup ADC_Exported_Functions_DMA Конфигурация секвенсоров для DMA
  * @{
  */

void ADC_SEQ_DMAConfig(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, ADC_SEQ_FIFOLevel_TypeDef ADC_SEQ_FIFOLevel);
void ADC_SEQ_DMACmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State);
FlagStatus ADC_SEQ_DMAErrorStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_DMAErrorStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Int Конфигурация прерываний
  * @{
  */

/** @defgroup ADC_Exported_Functions_Int_DC Цифровые компараторы
  * @{
  */

void ADC_DC_ITCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State);
void ADC_DC_ITConfig(ADC_DC_Module_TypeDef ADC_DC_Module, ADC_DC_Mode_TypeDef ADC_DC_Mode, ADC_DC_Condition_TypeDef ADC_DC_Condition);
void ADC_DC_ITGenCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State);
void ADC_DC_ITMaskCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State);
FlagStatus ADC_DC_ITRawStatus(ADC_DC_Module_TypeDef ADC_DC_Module);
FlagStatus ADC_DC_ITMaskedStatus(ADC_DC_Module_TypeDef ADC_DC_Module);
void ADC_DC_ITStatusClear(ADC_DC_Module_TypeDef ADC_DC_Module);

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Int_SEQ Секвенсоры
  * @{
  */

void ADC_SEQ_ITCmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State);
void ADC_SEQ_ITConfig(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, uint32_t ADC_SEQ_ITRate, FunctionalState ADC_SEQ_ITCountSEQRst);
uint32_t ADC_SEQ_GetITCount(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_ITCountRst(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
FlagStatus ADC_SEQ_ITRawStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
FlagStatus ADC_SEQ_ITMaskedStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);
void ADC_SEQ_ITStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_ADC_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
