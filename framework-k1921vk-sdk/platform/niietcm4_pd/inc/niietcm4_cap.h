/**
  ******************************************************************************
  * @file    niietcm4_cap.h
  *
  * @brief   Файл содержит все прототипы функций для блоков захвата
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    18.01.2016
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
  * <h2><center>&copy; 2016 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_CAP_H
#define __NIIETCM4_CAP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup CAP
  * @{
  */

/** @defgroup CAP_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор фронта захвата.
  */

typedef enum
{
    CAP_Capture_Polarity_PosEdge,      /*!< Захват по переднему фронту. */
    CAP_Capture_Polarity_NegEdge       /*!< Захват по заднему фронту. */
}CAP_Capture_Polarity_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_Capture_Polarity_TypeDef.
  */

#define IS_CAP_CAPTURE_POLARITY(CAPTURE_POLARITY) (((CAPTURE_POLARITY) == CAP_Capture_Polarity_PosEdge) || \
                                                   ((CAPTURE_POLARITY) == CAP_Capture_Polarity_NegEdge))

/**
  * @brief  Выбор режима остановки таймера при отладке.
  */

typedef enum
{
    CAP_Halt_Stop,         /*!< Мгновенная остановка таймера при отладке. */
    CAP_Halt_StopOnZero,   /*!< Остановка таймера при переполнении или сбросе (событие достижения 0). */
    CAP_Halt_Free          /*!< Нормальный режим. */
}CAP_Halt_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_Halt_TypeDef.
  */

#define IS_CAP_HALT(HALT) (((HALT) == CAP_Halt_Stop)        || \
                           ((HALT) == CAP_Halt_StopOnZero)  || \
                           ((HALT) == CAP_Halt_Free))

/**
  * @brief  Выбор источника выходного сигнала синхронизации.
  */

typedef enum
{
    CAP_SyncOut_Bypass,            /*!< Пропуск синхросигнала со входа на выход. */
    CAP_SyncOut_TimerEqPeriod,     /*!< Передача события равенства таймера и значения периода в качестве выходного сигнала синхронизации. */
    CAP_SyncOut_Disable            /*!< Выходной сигнал синхронизации запрещен. */
}CAP_SyncOut_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_SyncOut_TypeDef.
  */

#define IS_CAP_SYNC_OUT(SYNC_OUT) (((SYNC_OUT) == CAP_SyncOut_Bypass)        || \
                                   ((SYNC_OUT) == CAP_SyncOut_TimerEqPeriod) || \
                                   ((SYNC_OUT) == CAP_SyncOut_Disable))

/**
  * @brief  Выбор режима работы захвата.
  */

typedef enum
{
    CAP_Capture_Mode_Cycle,     /*!< Цикличный захват. */
    CAP_Capture_Mode_Single     /*!< Однократный захват. */
}CAP_Capture_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_Capture_Mode_TypeDef.
  */

#define IS_CAP_CAPTURE_MODE(CAPTURE_MODE) (((CAPTURE_MODE) == CAP_Capture_Mode_Single) || \
                                           ((CAPTURE_MODE) == CAP_Capture_Mode_Cycle))

/**
  * @brief  Выбор активного уровня в режиме ШИМ.
  */

typedef enum
{
    CAP_PWM_Polarity_Pos,      /*!< Высокий уровень является активным. */
    CAP_PWM_Polarity_Neg       /*!< Низкий уровень является активным. */
}CAP_PWM_Polarity_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_PWM_Polarity_TypeDef.
  */

#define IS_CAP_PWM_POLARITY(PWM_POLARITY) (((PWM_POLARITY) == CAP_PWM_Polarity_Pos) || \
                                           ((PWM_POLARITY) == CAP_PWM_Polarity_Neg))

/**
  * @brief  Выбор режима работы блока захвата.
  */

typedef enum
{
    CAP_Mode_Capture,  /*!< Режим захвата. */
    CAP_Mode_PWM       /*!< Режим ШИМ. */
}CAP_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref CAP_Mode_TypeDef.
  */

#define IS_CAP_MODE(MODE) (((MODE) == CAP_Mode_Capture) || \
                           ((MODE) == CAP_Mode_PWM))

/**
  * @brief  Структура инициализации блока захвата в целом.
  */

typedef struct
{
    CAP_Halt_TypeDef CAP_Halt;                     /*!< Выбор режима остановки таймера при отладке.
                                                       Параметр может принимать любое значение из @ref CAP_Halt_TypeDef. */
    FunctionalState CAP_SyncCmd;                   /*!< Определеяет возможность синхронизации.
                                                           Параметр может принимать любое значение из @ref FunctionalState. */
    CAP_SyncOut_TypeDef CAP_SyncOut;               /*!< Выбор источника выходного сигнала синхронизации.
                                                       Параметр может принимать любое значение из @ref CAP_SyncOut_TypeDef. */
    CAP_Mode_TypeDef CAP_Mode;                     /*!< Выбор режима работы блока захвата.
                                                       Параметр может принимать любое значение из @ref CAP_Mode_TypeDef. */
}CAP_Init_TypeDef;

/**
  * @brief  Структура инициализации режима захвата.
  */

typedef struct
{
    uint32_t CAP_Capture_Prescale;                     /*!< Предварительный делитель событий.
                                                           Параметр может принимать любое значение из диапазона 0-63. 0 - делитель выключен. */
    CAP_Capture_Mode_TypeDef CAP_CaptureMode;          /*!< Определеяет режим работы захвата.
                                                           Параметр может принимать любое значение из @ref CAP_Capture_Mode_TypeDef. */
    uint32_t CAP_Capture_StopVal;                      /*!< Значение счетчика событий для остановки одиночного режима захвата.
                                                           Параметр может принимать любое значение из диапазона 0-3. */
    FunctionalState CAP_Capture_RstEvent0;             /*!< Определеяет сброс таймера после события захвата 0.
                                                           Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState CAP_Capture_RstEvent1;             /*!< Определеяет сброс таймера после события захвата 1.
                                                           Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState CAP_Capture_RstEvent2;             /*!< Определеяет сброс таймера после события захвата 2.
                                                           Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState CAP_Capture_RstEvent3;             /*!< Определеяет сброс таймера после события захвата 3.
                                                           Параметр может принимать любое значение из @ref FunctionalState. */
    CAP_Capture_Polarity_TypeDef CAP_Capture_PolarityEvent0;   /*!< Определеяет фронт события захвата 0.
                                                                   Параметр может принимать любое значение из @ref CAP_Polarity_TypeDef. */
    CAP_Capture_Polarity_TypeDef CAP_Capture_PolarityEvent1;   /*!< Определеяет фронт события захвата 1.
                                                                   Параметр может принимать любое значение из @ref CAP_Polarity_TypeDef. */
    CAP_Capture_Polarity_TypeDef CAP_Capture_PolarityEvent2;   /*!< Определеяет фронт события захвата 2.
                                                                   Параметр может принимать любое значение из @ref CAP_Polarity_TypeDef. */
    CAP_Capture_Polarity_TypeDef CAP_Capture_PolarityEvent3;   /*!< Определеяет фронт события захвата 3.
                                                                   Параметр может принимать любое значение из @ref CAP_Polarity_TypeDef. */
}CAP_Capture_Init_TypeDef;

/**
  * @brief Проверка значения предварительного делителя событий на попадание в допустимый диапазон.
  */

#define IS_CAP_CAPTURE_PRESCALE(PRESCALE) ((PRESCALE) < ((uint32_t)0x40))

/**
  * @brief Проверка значения счетчика событий для остановки одиночного режима захвата
  *   на попадание в допустимый диапазон.
  */

#define IS_CAP_CAPTURE_STOP_VAL(STOP_VAL) ((STOP_VAL) < ((uint32_t)4))

/**
  * @brief  Структура инициализации режима ШИМ.
  */

typedef struct
{
    uint32_t CAP_PWM_Period;                       /*!< Значение периода ШИМ.
                                                       Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    uint32_t CAP_PWM_Compare;                      /*!< Значение сравнения ШИМ.
                                                       Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    CAP_PWM_Polarity_TypeDef CAP_PWM_Polarity;     /*!< Выбор полярности ШИМ сигнала.
                                                       Параметр может принимать любое значение из @ref CAP_PWM_Polarity_TypeDef. */
}CAP_PWM_Init_TypeDef;


/**
 * @}
 */

/** @defgroup CAP_Exported_Constants Константы
  * @{
  */

/** @defgroup CAP_Exported_Constants_ITSource Маски источников прерываний
  * @{
  */

#define CAP_ITSource_GeneralInt        ((uint32_t)0x01)    /*!< Общее прерывание. */
#define CAP_ITSource_CapEvent0         ((uint32_t)0x02)    /*!< Событие захвата 0. */
#define CAP_ITSource_CapEvent1         ((uint32_t)0x04)    /*!< Событие захвата 1. */
#define CAP_ITSource_CapEvent2         ((uint32_t)0x08)    /*!< Событие захвата 2. */
#define CAP_ITSource_CapEvent3         ((uint32_t)0x10)    /*!< Событие захвата 3. */
#define CAP_ITSource_TimerOvf          ((uint32_t)0x20)    /*!< Переполнение счетчика таймера. */
#define CAP_ITSource_TimerEqPeriod     ((uint32_t)0x40)    /*!< Счетчик таймера равен периоду (в режиме ШИМ). */
#define CAP_ITSource_TimerEqCompare    ((uint32_t)0x80)    /*!< Счетчик таймера равен значению сравнения (в режиме ШИМ). */
#define CAP_ITSource_All               ((uint32_t)0xFF)    /*!< Все источники выбраны. */

/**
  * @brief Макрос проверки источников прерываний на попадание в допустимый диапазон.
  */

#define IS_CAP_IT_SOURCE(IT_SOURCE) (((IT_SOURCE) & ~CAP_ITSource_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup CAP_Exported_Functions Функции
  * @{
  */

/** @defgroup CAP_Config Конфигурация
  * @{
  */

void CAP_DeInit(NT_CAP_TypeDef* CAPx);
void CAP_Init(NT_CAP_TypeDef* CAPx, CAP_Init_TypeDef* CAP_InitStruct);
void CAP_StructInit(CAP_Init_TypeDef* CAP_InitStruct);
void CAP_TimerCmd(NT_CAP_TypeDef* CAPx, FunctionalState State);
void CAP_SetTimer(NT_CAP_TypeDef* CAPx, uint32_t TimerVal);
void CAP_SetShadowTimer(NT_CAP_TypeDef* CAPx, uint32_t TimerVal);
uint32_t CAP_GetTimer(NT_CAP_TypeDef* CAPx);
uint32_t CAP_GetShadowTimer(NT_CAP_TypeDef* CAPx);
void CAP_SyncCmd(NT_CAP_TypeDef* CAPx, FunctionalState State);
void CAP_SwSync(NT_CAP_TypeDef* CAPx);

/**
  * @}
  */

/** @defgroup CAP_Config_PWM_Mode Режим ШИМ
  * @{
  */

void CAP_PWM_Init(NT_CAP_TypeDef* CAPx, CAP_PWM_Init_TypeDef* CAP_PWM_InitStruct);
void CAP_PWM_StructInit(CAP_PWM_Init_TypeDef* CAP_PWM_InitStruct);
void CAP_PWM_SetPeriod(NT_CAP_TypeDef* CAPx, uint32_t PeriodVal);
void CAP_PWM_SetCompare(NT_CAP_TypeDef* CAPx, uint32_t CompareVal);
void CAP_PWM_SetShadowPeriod(NT_CAP_TypeDef* CAPx, uint32_t PeriodVal);
void CAP_PWM_SetShadowCompare(NT_CAP_TypeDef* CAPx, uint32_t CompareVal);
uint32_t CAP_PWM_GetPeriod(NT_CAP_TypeDef* CAPx);
uint32_t CAP_PWM_GetCompare(NT_CAP_TypeDef* CAPx);
uint32_t CAP_PWM_GetShadowPeriod(NT_CAP_TypeDef* CAPx);
uint32_t CAP_PWM_GetShadowCompare(NT_CAP_TypeDef* CAPx);

/**
  * @}
  */

/** @defgroup CAP_Config_CAP_Mode Режим захвата
  * @{
  */

void CAP_Capture_Init(NT_CAP_TypeDef* CAPx, CAP_Capture_Init_TypeDef* CAP_Capture_InitStruct);
void CAP_Capture_StructInit(CAP_Capture_Init_TypeDef* CAP_Capture_InitStruct);
void CAP_Capture_Cmd(NT_CAP_TypeDef* CAPx, FunctionalState State);
void CAP_Capture_SetCap0(NT_CAP_TypeDef* CAPx, uint32_t Value);
void CAP_Capture_SetCap1(NT_CAP_TypeDef* CAPx, uint32_t Value);
void CAP_Capture_SetCap2(NT_CAP_TypeDef* CAPx, uint32_t Value);
void CAP_Capture_SetCap3(NT_CAP_TypeDef* CAPx, uint32_t Value);
uint32_t CAP_Capture_GetCap0(NT_CAP_TypeDef* CAPx);
uint32_t CAP_Capture_GetCap1(NT_CAP_TypeDef* CAPx);
uint32_t CAP_Capture_GetCap2(NT_CAP_TypeDef* CAPx);
uint32_t CAP_Capture_GetCap3(NT_CAP_TypeDef* CAPx);

/**
  * @}
  */

/** @defgroup CAP_IT Прерывания
  * @{
  */

void CAP_ITCmd(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource,  FunctionalState State);
void CAP_ITForceCmd(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource);
FlagStatus CAP_ITStatus(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource);
void CAP_ITStatusClear(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource);
FlagStatus CAP_ITPendStatus(NT_CAP_TypeDef* CAPx);
void CAP_ITPendClear(NT_CAP_TypeDef* CAPx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_CAP_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
