/**
  ******************************************************************************
  * @file    plib035_adc.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          ADC, а также сопутствующие макроопределения и перечисления
  *
  * @author  НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
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
  * <h2><center>&copy; 2018 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB035_ADC_H
#define __PLIB035_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup ADC
  * @brief Драйвер для работы с ADC
  * @{
  */

/** @defgroup ADC_Exported_Defines Константы
  * @{
  */

#define ADC_SEQ_Total 2UL
#define ADC_SEQ_Req_Total 4UL
#define ADC_DC_Total 4UL
#define ADC_CH_Total 4UL

/**
  * @}
  */

/** @defgroup ADC_Exported_Types Типы
  * @{
  */

/**
  * @brief  Номер секвенсора
  */
typedef enum {
    ADC_SEQ_Num_0, /*!< Севенсор 0 */
    ADC_SEQ_Num_1  /*!< Севенсор 1 */
} ADC_SEQ_Num_TypeDef;
#define IS_ADC_SEQ_NUM(VALUE) (((VALUE) == ADC_SEQ_Num_0) || \
                               ((VALUE) == ADC_SEQ_Num_1))

/**
  * @brief  Номер запроса в очереди секвенсора
  */
typedef enum {
    ADC_SEQ_ReqNum_0, /*!< Запрос 0 */
    ADC_SEQ_ReqNum_1, /*!< Запрос 1 */
    ADC_SEQ_ReqNum_2, /*!< Запрос 2 */
    ADC_SEQ_ReqNum_3  /*!< Запрос 3 */
} ADC_SEQ_ReqNum_TypeDef;
#define IS_ADC_SEQ_REQ_NUM(VALUE) (((VALUE) == ADC_SEQ_ReqNum_0) || \
                                   ((VALUE) == ADC_SEQ_ReqNum_1) || \
                                   ((VALUE) == ADC_SEQ_ReqNum_2) || \
                                   ((VALUE) == ADC_SEQ_ReqNum_3))

/**
  * @brief  События запуска секвенсоров
  */
typedef enum {
    ADC_SEQ_StartEvent_SwReq = ADC_EMUX_EM0_SwReq,     /*!< Запуск по программному запросу */
    ADC_SEQ_StartEvent_GPIOA = ADC_EMUX_EM0_GPIOA,     /*!< Сигнал от GPIOA */
    ADC_SEQ_StartEvent_GPIOB = ADC_EMUX_EM0_GPIOB,     /*!< Сигнал от GPIOB */
    ADC_SEQ_StartEvent_TMR0 = ADC_EMUX_EM0_TMR0,       /*!< Сигнал от таймера 0 */
    ADC_SEQ_StartEvent_TMR1 = ADC_EMUX_EM0_TMR1,       /*!< Сигнал от таймера 1 */
    ADC_SEQ_StartEvent_TMR2 = ADC_EMUX_EM0_TMR2,       /*!< Сигнал от таймера 2 */
    ADC_SEQ_StartEvent_TMR3 = ADC_EMUX_EM0_TMR3,       /*!< Сигнал от таймера 3 */
    ADC_SEQ_StartEvent_PWM012A = ADC_EMUX_EM0_PWM012A, /*!< Сигналы A от блоков ШИМ 0, 1, 2 */
    ADC_SEQ_StartEvent_PWM012B = ADC_EMUX_EM0_PWM012B, /*!< Сигналы B от блоков ШИМ 0, 1, 2 */
    ADC_SEQ_StartEvent_Cycle = ADC_EMUX_EM0_Cycle,     /*!< Циклическая работа сразу после запуска секвенсора */
} ADC_SEQ_StartEvent_TypeDef;
#define IS_ADC_SEQ_START_EVENT(VALUE) (((VALUE) == ADC_SEQ_StartEvent_SwReq) ||   \
                                       ((VALUE) == ADC_SEQ_StartEvent_GPIOA) ||   \
                                       ((VALUE) == ADC_SEQ_StartEvent_GPIOB) ||   \
                                       ((VALUE) == ADC_SEQ_StartEvent_TMR0) ||    \
                                       ((VALUE) == ADC_SEQ_StartEvent_TMR1) ||    \
                                       ((VALUE) == ADC_SEQ_StartEvent_TMR2) ||    \
                                       ((VALUE) == ADC_SEQ_StartEvent_TMR3) ||    \
                                       ((VALUE) == ADC_SEQ_StartEvent_PWM012A) || \
                                       ((VALUE) == ADC_SEQ_StartEvent_PWM012B) || \
                                       ((VALUE) == ADC_SEQ_StartEvent_Cycle))

/**
  * @brief  Количество измерений для усреднения
  */
typedef enum {
    ADC_SEQ_Average_2 = ADC_SEQ_SRQCTL_QAVGVAL_Average2,   /*!< Усреднение по 2 измерениям */
    ADC_SEQ_Average_4 = ADC_SEQ_SRQCTL_QAVGVAL_Average4,   /*!< Усреднение по 4 измерениям */
    ADC_SEQ_Average_8 = ADC_SEQ_SRQCTL_QAVGVAL_Average8,   /*!< Усреднение по 8 измерениям */
    ADC_SEQ_Average_16 = ADC_SEQ_SRQCTL_QAVGVAL_Average16, /*!< Усреднение по 16 измерениям */
    ADC_SEQ_Average_32 = ADC_SEQ_SRQCTL_QAVGVAL_Average32, /*!< Усреднение по 32 измерениям */
    ADC_SEQ_Average_64 = ADC_SEQ_SRQCTL_QAVGVAL_Average64, /*!< Усреднение по 64 измерениям */
} ADC_SEQ_Average_TypeDef;
#define IS_ADC_SEQ_AVERAGE(VALUE) (((VALUE) == ADC_SEQ_Average_2) ||  \
                                   ((VALUE) == ADC_SEQ_Average_4) ||  \
                                   ((VALUE) == ADC_SEQ_Average_8) ||  \
                                   ((VALUE) == ADC_SEQ_Average_16) || \
                                   ((VALUE) == ADC_SEQ_Average_32) || \
                                   ((VALUE) == ADC_SEQ_Average_64))

/**
  * @brief  Количество результатов измерений записанных в буфер секвенсора, по достижению которого вызывается DMA
  */
typedef enum {
    ADC_SEQ_DMAFIFOLevel_1 = ADC_SEQ_SDMACTL_WMARK_Level1,   /*!< Запрос DMA после заполнения 1 ячейки в буффере */
    ADC_SEQ_DMAFIFOLevel_2 = ADC_SEQ_SDMACTL_WMARK_Level2,   /*!< Запрос DMA после заполнения 2 ячеек в буффере */
    ADC_SEQ_DMAFIFOLevel_4 = ADC_SEQ_SDMACTL_WMARK_Level4,   /*!< Запрос DMA после заполнения 4 ячеек в буффере */
    ADC_SEQ_DMAFIFOLevel_8 = ADC_SEQ_SDMACTL_WMARK_Level8,   /*!< Запрос DMA после заполнения 8 ячеек в буффере */
    ADC_SEQ_DMAFIFOLevel_16 = ADC_SEQ_SDMACTL_WMARK_Level16, /*!< Запрос DMA после заполнения 16 ячеек в буффере */
    ADC_SEQ_DMAFIFOLevel_32 = ADC_SEQ_SDMACTL_WMARK_Level32, /*!< Запрос DMA после заполнения 32 ячеек в буффере */
} ADC_SEQ_DMAFIFOLevel_TypeDef;
#define IS_ADC_SEQ_DMA_FIFO_LEVEL(VALUE) (((VALUE) == ADC_SEQ_DMAFIFOLevel_1) ||  \
                                          ((VALUE) == ADC_SEQ_DMAFIFOLevel_2) ||  \
                                          ((VALUE) == ADC_SEQ_DMAFIFOLevel_4) ||  \
                                          ((VALUE) == ADC_SEQ_DMAFIFOLevel_8) ||  \
                                          ((VALUE) == ADC_SEQ_DMAFIFOLevel_16) || \
                                          ((VALUE) == ADC_SEQ_DMAFIFOLevel_32))

/**
  * @brief Номер цифрового компаратора
  */
typedef enum {
    ADC_DC_Num_0, /*!< Модуль цифрового компаратора 0 */
    ADC_DC_Num_1, /*!< Модуль цифрового компаратора 1 */
    ADC_DC_Num_2, /*!< Модуль цифрового компаратора 2 */
    ADC_DC_Num_3, /*!< Модуль цифрового компаратора 3 */
} ADC_DC_Num_TypeDef;
#define IS_ADC_DC_NUM(VALUE) (((VALUE) == ADC_DC_Num_0) || \
                              ((VALUE) == ADC_DC_Num_1) || \
                              ((VALUE) == ADC_DC_Num_2) || \
                              ((VALUE) == ADC_DC_Num_3))

/**
  * @brief  Режим срабатывания цифрового компаратора
  */
typedef enum {
    ADC_DC_Mode_Multiple = ADC_DC_DCTL_CIM_Multiple,         /*!< Многократный */
    ADC_DC_Mode_Single = ADC_DC_DCTL_CIM_Single,             /*!< Однократный */
    ADC_DC_Mode_MultipleHyst = ADC_DC_DCTL_CIM_MultipleHyst, /*!< Многократный с гистерезисом */
    ADC_DC_Mode_SingleHyst = ADC_DC_DCTL_CIM_SingleHyst,     /*!< Однократный с гистерезисом */
} ADC_DC_Mode_TypeDef;
#define IS_ADC_DC_MODE(VALUE) (((VALUE) == ADC_DC_Mode_Single) ||     \
                               ((VALUE) == ADC_DC_Mode_Multiple) ||   \
                               ((VALUE) == ADC_DC_Mode_SingleHyst) || \
                               ((VALUE) == ADC_DC_Mode_MultipleHyst))

/**
  * @brief  Условие срабатывания компаратора
  */
typedef enum {
    ADC_DC_Condition_Low = ADC_DC_DCTL_CIC_Low,       /*!< Результат меньше либо равен нижней границе */
    ADC_DC_Condition_Window = ADC_DC_DCTL_CIC_Window, /*!< Результат внутри диапазона, задаваемого границами, либо равен одной из них */
    ADC_DC_Condition_High = ADC_DC_DCTL_CIC_High,     /*!< Результат больше либо равен верхней границе */
} ADC_DC_Condition_TypeDef;
#define IS_ADC_DC_CONDITION(VALUE) (((VALUE) == ADC_DC_Condition_Low) ||    \
                                    ((VALUE) == ADC_DC_Condition_Window) || \
                                    ((VALUE) == ADC_DC_Condition_High))

/**
  * @brief  Источник данных для компаратора
  */
typedef enum {
    ADC_DC_Source_EOC,  /*!< Ококнчание измерения АЦП */
    ADC_DC_Source_FIFO, /*!< Запись результатат в FIFO */
} ADC_DC_Source_TypeDef;
#define IS_ADC_DC_SOURCE(VALUE) (((VALUE) == ADC_DC_Source_EOC) || \
                                 ((VALUE) == ADC_DC_Source_FIFO))

/**
  * @brief  Номер канала
  */
typedef enum {
    ADC_CH_Num_0, /*!< Канал 0 */
    ADC_CH_Num_1, /*!< Канал 1 */
    ADC_CH_Num_2, /*!< Канал 2 */
    ADC_CH_Num_3, /*!< Канал 3 */
} ADC_CH_Num_TypeDef;
#define IS_ADC_CH_NUM(VALUE) (((VALUE) == ADC_CH_Num_0) || \
                              ((VALUE) == ADC_CH_Num_1) || \
                              ((VALUE) == ADC_CH_Num_2) || \
                              ((VALUE) == ADC_CH_Num_3))

/**
  * @brief  Выбор приоритета канала
  */
typedef enum {
    ADC_CH_Priority_Normal, /*!< Обычный уровень приоритета */
    ADC_CH_Priority_High,   /*!< Высокий уровень приоритета */
} ADC_CH_Priority_TypeDef;
#define IS_ADC_CH_PRIORITY(VALUE) (((VALUE) == ADC_CH_Priority_Normal) || \
                                   ((VALUE) == ADC_CH_Priority_High))

/**
  * @brief  Структура инициализации цифровых компараторов
  */
typedef struct
{
    FunctionalState DCOutput;           /*!< Разрешает работу выходному триггеру компаратора */
    uint32_t ThresholdLow;              /*!< Нижний порог срабатывания компаратора.
                                             Параметр может принимать любое значение из диапазона 0 - 4095. */
    uint32_t ThresholdHigh;             /*!< Верхний порог срабатывания компаратора.
                                             Параметр может принимать любое значение из диапазона 0 - 4095. */
    ADC_DC_Source_TypeDef Source;       /*!< Выбирает источник получения измерения */
    ADC_CH_Num_TypeDef Channel;         /*!< Выбирает канал, результат измерения которого будет передан на компаратор */
    ADC_DC_Mode_TypeDef Mode;           /*!< Выбирает режим срабатывания компаратора */
    ADC_DC_Condition_TypeDef Condition; /*!< Выбирает условие срабатывания компаратора */
} ADC_DC_Init_TypeDef;

#define IS_ADC_DC_THRESHOLD(VALUE) ((VALUE) < 0x1000)

/**
  * @brief  Структура инициализации секвенсоров
  */
typedef struct
{
    ADC_SEQ_StartEvent_TypeDef StartEvent;     /*!< Определяет cобытие запуска секвенсора */
    FunctionalState SWStartEn;                 /*!< Разрешает секвенсору запускаться по программному запросу */
    ADC_CH_Num_TypeDef Req[ADC_SEQ_Req_Total]; /*!< Выбор каналов для запросов секвенсора */
    ADC_SEQ_ReqNum_TypeDef ReqMax;             /*!< Настройка глубины очереди запросов */
    ADC_SEQ_Average_TypeDef ReqAverage;        /*!< Настройка усреднения сканированием очереди запросов */
    FunctionalState ReqAverageEn;              /*!< Разрешение усреднения сканированием очереди запросов */
    uint32_t RestartCount;                     /*!< Задание количества перезапусков модулей АЦП секвенсором после его запуска по событию.
                                                         0x00 - без перезапусков, 0x01 - 1 перезапуск, 0xFF - 255 перезапусков. */
    FunctionalState RestartAverageEn;          /*!< Разрешение усреднения по перезапускам */
    uint32_t RestartTimer;                     /*!< Задание задержки запуска модуля АЦП.
                                                         Параметр может принимать любое значение из диапазона 0x00000000 - 0x00FFFFFF. */
    FunctionalState DCEn[ADC_DC_Total];        /*!< Разрешение работы цифровых компараторов секвенсором */
    ADC_SEQ_DMAFIFOLevel_TypeDef DMAFIFOLevel; /*!< Настройка уровня заполненности буфера для генерации запросов DMA */
    FunctionalState DMAEn;                     /*!< Разрешение генерации запросов DMA */
} ADC_SEQ_Init_TypeDef;

#define IS_ADC_SEQ_RESTART_VAL(VALUE) ((VALUE) < 0x100)
#define IS_ADC_SEQ_RESTART_TIMER_VAL(VALUE) ((VALUE) < 0x1000000)
#define IS_ADC_SEQ_IT_COUNT_VAL(VALUE) ((VALUE) < 0x100)

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions Функции
  * @{
  */

void ADC_DeInit(void);

/**
  * @brief   Включение аналогового модуля АЦП
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_AM_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->ACTL_bit.ADCEN, State);
}

/**
  * @brief   Чтение статуса готовности аналогового модуля АЦП. Флаг становится активным после того,
  *          как модуль АЦП провел внутренние процедуры иницализации.
  * @retval  Status  Статус готовности
  */
__STATIC_INLINE FlagStatus ADC_AM_ReadyStatus(void)
{
    return (FlagStatus)READ_REG(ADC->ACTL_bit.ADCRDY);
}

/**
  * @brief   Чтение статуса занятости аналогового модуля АЦП. Флаг становится активным при
  *          проведении измерения.
  * @retval  Status  Статус занятости
  */
__STATIC_INLINE FlagStatus ADC_AM_BusyStatus(void)
{
    return (FlagStatus)READ_REG(ADC->BSTAT_bit.ADCBUSY);
}

/**
  * @brief   Настройка приоритета канала АЦП
  * @param   Channel_Num  Выбор канала
  * @param   Priority  Выбор приоритета
  * @retval  void
  */
__STATIC_INLINE void ADC_CH_PriorityConfig(ADC_CH_Num_TypeDef Channel_Num, ADC_CH_Priority_TypeDef Priority)
{
    assert_param(IS_ADC_CH_NUM(Channel_Num));
    assert_param(IS_ADC_CH_PRIORITY(Priority));

    WRITE_REG(ADC->CHCTL[Channel_Num].CHCTL_bit.PRIORITY, Priority);
}

/**
  * @brief   Получение текущего значения коэффициента коррекции ошибки усиления
  * @param   Channel_Num  Выбор канала
  * @retval  Val  Значение. Диапазон значений -256…255, величина в
                  дополнительном коде: 100h соответствует -256, 000h - 0, 0FFh - 255.
  */
__STATIC_INLINE uint32_t ADC_CH_GetGainTrim(ADC_CH_Num_TypeDef Channel_Num)
{
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    return READ_REG(ADC->CHCTL[Channel_Num].CHCTL_bit.GAINTRIM);
}

/**
  * @brief   Установка значения коэффициента коррекции ошибки усиления
  * @param   Channel_Num  Выбор канала
  * @param   Val  Значение. Диапазон значений -256…255, величина в
                  дополнительном коде: 100h соответствует -256, 000h - 0, 0FFh - 255.
  * @retval  void
  */
__STATIC_INLINE void ADC_CH_SetGainTrim(ADC_CH_Num_TypeDef Channel_Num, uint32_t Val)
{
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    WRITE_REG(ADC->CHCTL[Channel_Num].CHCTL_bit.GAINTRIM, Val);
}

/**
  * @brief   Получение текущего значения коэффициента коррекции ошибки смещения нуля
  * @param   Channel_Num  Выбор канала
  * @retval  Val  Значение. Диапазон значений -256…255, величина в
                  дополнительном коде: 100h соответствует -256, 000h - 0, 0FFh - 255.
  */
__STATIC_INLINE uint32_t ADC_CH_GetOffsetTrim(ADC_CH_Num_TypeDef Channel_Num)
{
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    return READ_REG(ADC->CHCTL[Channel_Num].CHCTL_bit.OFFTRIM);
}

/**
  * @brief   Установка значения коэффициента коррекции ошибки смещения нуля
  * @param   Channel_Num  Выбор канала
  * @param   Val  Значение. Диапазон значений -256…255, величина в
                  дополнительном коде: 100h соответствует -256, 000h - 0, 0FFh - 255.
  * @retval  void
  */
__STATIC_INLINE void ADC_CH_SetOffsetTrim(ADC_CH_Num_TypeDef Channel_Num, uint32_t Val)
{
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    WRITE_REG(ADC->CHCTL[Channel_Num].CHCTL_bit.OFFTRIM, Val);
}

/** @defgroup ADC_Exported_Functions_Init_SEQ Секвенсоры
  * @{
  */

void ADC_SEQ_Init(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_Init_TypeDef* InitStruct);
void ADC_SEQ_StructInit(ADC_SEQ_Init_TypeDef* InitStruct);

/**
  * @brief   Включение модуля секвенсора АЦП
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_Cmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ADC->SEQEN, 1 << (uint32_t)SEQ_Num, State << (uint32_t)SEQ_Num);
}

/**
  * @brief   Включение программного запуска секвенсора АЦП
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_SwStartEnCmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ADC->SEQSYNC, 1 << (uint32_t)SEQ_Num, State << (uint32_t)SEQ_Num);
}

/**
  * @brief   Генерация импульса программного запуска
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_SwStartCmd(void)
{
    WRITE_REG(ADC->SEQSYNC_bit.GSYNC, 1);
}

/**
  * @brief   Чтение статуса занятости секвенсора. Флаг становится активным при
  *          проведении запусков/перезапусков.
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Статус занятости
  */
__STATIC_INLINE FlagStatus ADC_SEQ_BusyStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->BSTAT, 1 << (uint32_t)SEQ_Num);
}

/**
  * @brief   Чтение статуса заполнения буфера секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Статус заполнения буфера
  */
__STATIC_INLINE FlagStatus ADC_SEQ_FIFOFullStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_OV0_Pos));
}

/**
  * @brief   Сброс статуса заполнения буфера секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_FIFOFullStatusClear(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    WRITE_REG(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_OV0_Pos));
}

/**
  * @brief   Чтение статуса пустоты буфера секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Статус пустоты буфера
  */
__STATIC_INLINE FlagStatus ADC_SEQ_FIFOEmptyStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_UN0_Pos));
}

/**
  * @brief   Сброс статуса пустоты буфера секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_FIFOEmptyStatusClear(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    WRITE_REG(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_UN0_Pos));
}

/**
  * @brief   Настройка события запуска секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @param   StartEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_StartEventConfig(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_StartEvent_TypeDef StartEvent)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    MODIFY_REG(ADC->EMUX, 0xF << ((uint32_t)SEQ_Num * 4), StartEvent << ((uint32_t)SEQ_Num * 4));
}

/**
  * @brief   Выбор каналов для запроса секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @param   ReqNum  Выбор запроса
  * @param   Channel_Num  Выбор канала
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ReqConfig(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_ReqNum_TypeDef ReqNum, ADC_CH_Num_TypeDef Channel_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_REQ_NUM(ReqNum));
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    MODIFY_REG(ADC->SEQ[SEQ_Num].SRQSEL, 0x3 << ((uint32_t)ReqNum * 4), Channel_Num << ((uint32_t)ReqNum * 4));
}

/**
  * @brief   Настройка глубины очереди запросов
  * @param   SEQ_Num  Выбор секвенсора
  * @param   ReqNumMax  Номер последнего запроса
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ReqMaxConfig(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_ReqNum_TypeDef ReqNumMax)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_REQ_NUM(ReqNumMax));

    WRITE_REG(ADC->SEQ[SEQ_Num].SRQCTL_bit.RQMAX, ReqNumMax);
}

/**
  * @brief   Настройка усреднения сканированием очереди запросов
  * @param   SEQ_Num  Выбор секвенсора
  * @param   Average  Выбор режима усреднения
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ReqAverageConfig(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_Average_TypeDef Average)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_AVERAGE(Average));

    WRITE_REG(ADC->SEQ[SEQ_Num].SRQCTL_bit.QAVGVAL, Average);
}

/**
  * @brief   Включение усреднения сканированием очереди запросов
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ReqAverageCmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->SEQ[SEQ_Num].SRQCTL_bit.QAVGEN, State);
}

/**
  * @brief   Получение текущего номера запроса в очереди
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Номер запроса
  */
__STATIC_INLINE ADC_SEQ_ReqNum_TypeDef ADC_SEQ_GetReqCurrent(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (ADC_SEQ_ReqNum_TypeDef)READ_REG(ADC->SEQ[SEQ_Num].SRQSTAT_bit.RQPTR);
}

/**
  * @brief   Чтение статуса занятости запроса секвенсора. Флаг становится активным при
  *          выставленном запросе.
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Статус занятости
  */
__STATIC_INLINE FlagStatus ADC_SEQ_ReqBusyStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_REG(ADC->SEQ[SEQ_Num].SRQSTAT_bit.RQBUSY);
}

/**
  * @brief   Настройка генерации запросов DMA
  * @param   SEQ_Num  Выбор секвенсора
  * @param   DMAFIFOLevel  Выбор уровня заполнения буфера для генерации запросов DMA
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_DMAConfig(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_DMAFIFOLevel_TypeDef DMAFIFOLevel)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_DMA_FIFO_LEVEL(DMAFIFOLevel));

    WRITE_REG(ADC->SEQ[SEQ_Num].SDMACTL_bit.WMARK, DMAFIFOLevel);
}

/**
  * @brief   Включение генерации запросов DMA
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_DMACmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->SEQ[SEQ_Num].SDMACTL_bit.DMAEN, State);
}

/**
  * @brief   Чтение статуса ошибки генерации запросов DMA
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Статус ошибки
  */
__STATIC_INLINE FlagStatus ADC_SEQ_DMAErrorStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_DOV0_Pos));
}

/**
  * @brief   Сброс статуса ошибки генерации запросов DMA
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_DMAErrorStatusClear(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    WRITE_REG(ADC->FSTAT, 1 << ((uint32_t)SEQ_Num + ADC_FSTAT_DOV0_Pos));
}

/**
  * @brief   Настройка количества перезапусков очереди запросов
  * @param   SEQ_Num  Выбор секвенсора
  * @param   RestartVal  Количество. 0x00 - без перезапусков,
  *                      0x01 - 1 перезапуск, 0xFF - 255 перезапусков.
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_RestartConfig(ADC_SEQ_Num_TypeDef SEQ_Num, uint32_t RestartVal)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_RESTART_VAL(RestartVal));

    WRITE_REG(ADC->SEQ[SEQ_Num].SCCTL_bit.RCNT, RestartVal);
}

/**
  * @brief   Включение режима усреднения по перезапускам.
  *          При этом количество перезапусков должно равнятся 2^p - 1 (p=1..8).
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_RestartAverageCmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->SEQ[SEQ_Num].SCCTL_bit.RAVGEN, State);
}

/**
  * @brief   Получение текущего количества совершенных перезапусков
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Номер запроса
  */
__STATIC_INLINE uint32_t ADC_SEQ_GetRestartCurrent(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return READ_REG(ADC->SEQ[SEQ_Num].SCVAL_bit.RCNT);
}

/**
  * @brief   Разрешение поступления данных на выбранный цифровой компаратор
  * @param   SEQ_Num  Выбор секвенсора
  * @param   DC_Num  Выбор компаратора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_DCEnableCmd(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_DC_Num_TypeDef DC_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ADC->SEQ[SEQ_Num].SDC, 1 << ((uint32_t)DC_Num), State << ((uint32_t)DC_Num));
}

/**
  * @brief   Установка значения задержки перезапуска секвенсора в тактак ACLK
  * @param   SEQ_Num  Выбор секвенсора
  * @param   TimerVal  Значение. 0 - означает отсутствие задержки и немедленный перезапуск (если активен).
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_SetRestartTimer(ADC_SEQ_Num_TypeDef SEQ_Num, uint32_t TimerVal)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_RESTART_TIMER_VAL(TimerVal));

    WRITE_REG(ADC->SEQ[SEQ_Num].SRTMR_bit.VAL, TimerVal);
}
/**
  * @brief   Получение текущего значения задержки перезапуска секвенсора в тактак ACLK
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Значение. 0 - означает отсутствие задержки и немедленный перезапуск (если активен).
  */
__STATIC_INLINE uint32_t ADC_SEQ_GetRestartTimer(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return READ_REG(ADC->SEQ[SEQ_Num].SRTMR_bit.VAL);
}

/**
  * @brief   Разрешение обновления значения задержки по событиям перезапуска (по умолчанию, только по запускам)
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_RestartTimerUpdateCmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->SEQ[SEQ_Num].SRTMR_bit.NOWAIT, State);
}

/**
  * @brief   Получение текущего значения количества результатов в буфере секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ADC_SEQ_GetFIFOLoad(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return READ_REG(ADC->SEQ[SEQ_Num].SFLOAD_bit.VAL);
}

/**
  * @brief   Получение результата измерения из буфера секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ADC_SEQ_GetFIFOData(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return READ_REG(ADC->SEQ[SEQ_Num].SFIFO_bit.DATA);
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Init_DC Цифровые компараторы
  * @{
  */

void ADC_DC_Init(ADC_DC_Num_TypeDef DC_Num, ADC_DC_Init_TypeDef* InitStruct);
void ADC_DC_StructInit(ADC_DC_Init_TypeDef* InitStruct);

/**
  * @brief   Разрешение работы цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_OutputCmd(ADC_DC_Num_TypeDef DC_Num, FunctionalState State)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->DC[DC_Num].DCTL_bit.CTE, State);
}

/**
  * @brief   Настройка источника данных цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Source  Выбор источника
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_SourceConfig(ADC_DC_Num_TypeDef DC_Num, ADC_DC_Source_TypeDef Source)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_DC_SOURCE(Source));

    WRITE_REG(ADC->DC[DC_Num].DCTL_bit.SRC, Source);
}

/**
  * @brief   Выбор канала АЦП для получения данных цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Source  Выбор источника
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_ChannelConfig(ADC_DC_Num_TypeDef DC_Num, ADC_CH_Num_TypeDef Channel_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_CH_NUM(Channel_Num));

    WRITE_REG(ADC->DC[DC_Num].DCTL_bit.CHNL, Channel_Num);
}

/**
  * @brief   Настройка режима и условия срабатывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Mode  Выбор режима
  * @param   Condition  Выбор условия
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_Config(ADC_DC_Num_TypeDef DC_Num, ADC_DC_Mode_TypeDef Mode, ADC_DC_Condition_TypeDef Condition)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_DC_MODE(Mode));
    assert_param(IS_ADC_DC_CONDITION(Condition));

    MODIFY_REG(ADC->DC[DC_Num].DCTL, ADC_DC_DCTL_CTC_Msk | ADC_DC_DCTL_CTM_Msk,
               ((Mode << ADC_DC_DCTL_CTM_Pos) |
                (Condition << ADC_DC_DCTL_CTC_Pos)));
}

/**
  * @brief   Установка значения нижней границы цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Val  Значение. Диапазон 0-0xFFF.
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_SetThresholdLow(ADC_DC_Num_TypeDef DC_Num, uint32_t Val)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_DC_THRESHOLD(Val));

    WRITE_REG(ADC->DC[DC_Num].DCMP_bit.CMPL, Val);
}

/**
  * @brief   Получение значения нижней границы цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Val  Значение. Диапазон 0-0xFFF.
  */
__STATIC_INLINE uint32_t ADC_DC_GetThresholdLow(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return READ_REG(ADC->DC[DC_Num].DCMP_bit.CMPL);
}

/**
  * @brief   Установка значения верхней границы цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Val  Значение. Диапазон 0-0xFFF.
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_SetThresholdHigh(ADC_DC_Num_TypeDef DC_Num, uint32_t Val)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_DC_THRESHOLD(Val));

    WRITE_REG(ADC->DC[DC_Num].DCMP_bit.CMPH, Val);
}

/**
  * @brief   Получение значения верхней границы цифрового компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Val  Значение. Диапазон 0-0xFFF.
  */
__STATIC_INLINE uint32_t ADC_DC_GetThresholdHigh(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return READ_REG(ADC->DC[DC_Num].DCMP_bit.CMPH);
}

/**
  * @brief   Чтение статуса события сравнения компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus ADC_DC_CmpEventStatus(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return (FlagStatus)READ_BIT(ADC->DCTRIG, 1 << ((uint32_t)DC_Num + ADC_DCTRIG_DCEV0_Pos));
}

/**
  * @brief   Сброс статуса события сравнения компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_CmpEventStatusClear(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    WRITE_REG(ADC->DCTRIG, 1 << ((uint32_t)DC_Num + ADC_DCTRIG_DCEV0_Pos));
}

/**
  * @brief   Чтение статуса выходного триггера компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus ADC_DC_TrigStatus(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return (FlagStatus)READ_BIT(ADC->DCTRIG, 1 << ((uint32_t)DC_Num + ADC_DCTRIG_TOS0_Pos));
}

/**
  * @brief   Сброс выходного триггера компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_TrigStatusClear(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    WRITE_REG(ADC->DCTRIG, 1 << ((uint32_t)DC_Num + ADC_DCTRIG_TOS0_Pos));
}

/**
  * @brief   Получение последнего значения, использованного для сравнения
  * @param   DC_Num  Выбор компаратора
  * @retval  Val  Значение. Диапазон 0-0xFFF.
  */
__STATIC_INLINE uint32_t ADC_DC_GetLastData(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return READ_REG(ADC->DC[DC_Num].DDATA);
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Int Конфигурация прерываний
  * @{
  */

/** @defgroup ADC_Exported_Functions_Int_DC Цифровые компараторы
  * @{
  */

/**
  * @brief   Включение генерации прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_ITCmd(ADC_DC_Num_TypeDef DC_Num, FunctionalState State)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ADC->DC[DC_Num].DCTL_bit.CIE, State);
}

/**
  * @brief   Настройка условий и режима работы для генерации прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   Mode  Выбор режима
  * @param   Condition  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_ITConfig(ADC_DC_Num_TypeDef DC_Num, ADC_DC_Mode_TypeDef Mode, ADC_DC_Condition_TypeDef Condition)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_ADC_DC_MODE(Mode));
    assert_param(IS_ADC_DC_CONDITION(Condition));

    MODIFY_REG(ADC->DC[DC_Num].DCTL, ADC_DC_DCTL_CIC_Msk | ADC_DC_DCTL_CIM_Msk,
               ((Mode << ADC_DC_DCTL_CIM_Pos) |
                (Condition << ADC_DC_DCTL_CIC_Pos)));
}

/**
  * @brief   Маскирование прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_ITMaskCmd(ADC_DC_Num_TypeDef DC_Num, FunctionalState State)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ADC->IM, 1 << ((uint32_t)DC_Num + ADC_IM_DCIM0_Pos), State << ((uint32_t)DC_Num + ADC_IM_DCIM0_Pos));
}

/**
  * @brief   Запрос немаскированного состояния прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Status  Состояние
  */
__STATIC_INLINE FlagStatus ADC_DC_ITRawStatus(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return (FlagStatus)READ_BIT(ADC->RIS, 1 << ((uint32_t)DC_Num + ADC_RIS_DCRIS0_Pos));
}

/**
  * @brief   Запрос маскированного состояния прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  Status  Состояние
  */
__STATIC_INLINE FlagStatus ADC_DC_ITMaskedStatus(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    return (FlagStatus)READ_BIT(ADC->MIS, 1 << ((uint32_t)DC_Num + ADC_MIS_DCMIS0_Pos));
}

/**
  * @brief   Сброс флага прерывания компаратора
  * @param   DC_Num  Выбор компаратора
  * @retval  void
  */
__STATIC_INLINE void ADC_DC_ITStatusClear(ADC_DC_Num_TypeDef DC_Num)
{
    assert_param(IS_ADC_DC_NUM(DC_Num));

    WRITE_REG(ADC->IC, 1 << ((uint32_t)DC_Num + ADC_IC_DCIC0_Pos));
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Int_SEQ Секвенсоры
  * @{
  */

/**
  * @brief   Маскирование прерывания секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ITCmd(ADC_SEQ_Num_TypeDef SEQ_Num, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ADC->IM, 1 << ((uint32_t)SEQ_Num + ADC_IM_SEQIM0_Pos), State << ((uint32_t)SEQ_Num + ADC_IM_SEQIM0_Pos));
}

/**
  * @brief   Настройка генерации прерывания секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @param   ITCount  Количество запросов модуля АЦП для генерации прерывания.
  *                   0 - по каждому запросу, 0xFF - каждые 256 запросов.
  * @param   ITCountNoRst  Активация режима, где счетчик прерывания не будет сбрасываться по запуску секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ITConfig(ADC_SEQ_Num_TypeDef SEQ_Num, uint32_t ITCount, FunctionalState ITCountNoRst)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));
    assert_param(IS_ADC_SEQ_IT_COUNT_VAL(ITCount));
    assert_param(IS_FUNCTIONAL_STATE(ITCountNoRst));

    WRITE_REG(ADC->SEQ[SEQ_Num].SCCTL_bit.ICNT, ITCount);
    MODIFY_REG(ADC->CICNT, 1 << ((uint32_t)SEQ_Num + ADC_CICNT_ICNT0_Pos), ITCountNoRst << ((uint32_t)SEQ_Num + ADC_CICNT_ICNT0_Pos));
}

/**
  * @brief   Получение текущего состояния счетчика запросов, используемого для генерации прерываний
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Val  Значение. Диапазон 0-0xFF.
  */
__STATIC_INLINE uint32_t ADC_SEQ_GetITCountCurrent(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return READ_REG(ADC->SEQ[SEQ_Num].SCVAL_bit.ICNT);
}

/**
  * @brief   Сброс счетчика запросов, используемого для генерации прерываний
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ITCountRst(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    WRITE_REG(ADC->SEQ[SEQ_Num].SCVAL_bit.ICLR, 1);
}

/**
  * @brief   Запрос немаскированного состояния прерывания секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Состояние
  */
__STATIC_INLINE FlagStatus ADC_SEQ_ITRawStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->RIS, 1 << ((uint32_t)SEQ_Num + ADC_RIS_SEQRIS0_Pos));
}

/**
  * @brief   Запрос маскированного состояния прерывания секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  Status  Состояние
  */
__STATIC_INLINE FlagStatus ADC_SEQ_ITMaskedStatus(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    return (FlagStatus)READ_BIT(ADC->MIS, 1 << ((uint32_t)SEQ_Num + ADC_MIS_SEQMIS0_Pos));
}

/**
  * @brief   Сброс флага прерывания секвенсора
  * @param   SEQ_Num  Выбор секвенсора
  * @retval  void
  */
__STATIC_INLINE void ADC_SEQ_ITStatusClear(ADC_SEQ_Num_TypeDef SEQ_Num)
{
    assert_param(IS_ADC_SEQ_NUM(SEQ_Num));

    WRITE_REG(ADC->IC, 1 << ((uint32_t)SEQ_Num + ADC_IC_SEQIC0_Pos));
}

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

#endif /* __PLIB035_ADC_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
