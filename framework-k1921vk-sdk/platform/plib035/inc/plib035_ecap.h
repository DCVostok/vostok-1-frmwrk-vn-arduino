/**
  ******************************************************************************
  * @file    plib035_ecap.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          ECAP, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_ECAP_H
#define __PLIB035_ECAP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup ECAP
  * @brief Драйвер для работы с ECAP
  * @{
  */

/** @defgroup ECAP_Exported_Defines Константы
  * @{
  */

/** @defgroup ECAP_ITStatus_Define Флаги прерываний
  * @{
  */

#define ECAP_ITStatus_GeneralInt ECAP_ECFLG_INT_Msk        /*!< Общее прерывание */
#define ECAP_ITStatus_CapEvt0 ECAP_ECFLG_CEVT0_Msk         /*!< Событие захвата 0 */
#define ECAP_ITStatus_CapEvt1 ECAP_ECFLG_CEVT1_Msk         /*!< Событие захвата 1 */
#define ECAP_ITStatus_CapEvt2 ECAP_ECFLG_CEVT2_Msk         /*!< Событие захвата 2 */
#define ECAP_ITStatus_CapEvt3 ECAP_ECFLG_CEVT3_Msk         /*!< Событие захвата 3 */
#define ECAP_ITStatus_TimerOvf ECAP_ECFLG_CTROVF_Msk       /*!< Переполнение счетчика таймера */
#define ECAP_ITStatus_TimerEqPeriod ECAP_ECFLG_CTRPRD_Msk  /*!< Счетчик таймера равен периоду (в режиме ШИМ) */
#define ECAP_ITStatus_TimerEqCompare ECAP_ECFLG_CTRCMP_Msk /*!< Счетчик таймера равен значению сравнения (в режиме ШИМ) */
#define ECAP_ITStatus_All (ECAP_ITStatus_GeneralInt |    \
                           ECAP_ITStatus_CapEvt0 |       \
                           ECAP_ITStatus_CapEvt1 |       \
                           ECAP_ITStatus_CapEvt2 |       \
                           ECAP_ITStatus_CapEvt3 |       \
                           ECAP_ITStatus_TimerOvf |      \
                           ECAP_ITStatus_TimerEqPeriod | \
                           ECAP_ITStatus_TimerEqCompare) /*!< Все флаги выбраны */

#define IS_ECAP_IT_STATUS(VALUE) (((VALUE) & ~ECAP_ITStatus_All) == 0)

/**
  * @}
  */

/** @defgroup ECAP_ITSource_Define Маски источников прерываний
  * @{
  */

#define ECAP_ITSource_CapEvt0 ECAP_ECEINT_CEVT0_Msk         /*!< Событие захвата 0 */
#define ECAP_ITSource_CapEvt1 ECAP_ECEINT_CEVT1_Msk         /*!< Событие захвата 1 */
#define ECAP_ITSource_CapEvt2 ECAP_ECEINT_CEVT2_Msk         /*!< Событие захвата 2 */
#define ECAP_ITSource_CapEvt3 ECAP_ECEINT_CEVT3_Msk         /*!< Событие захвата 3 */
#define ECAP_ITSource_TimerOvf ECAP_ECEINT_CTROVF_Msk       /*!< Переполнение счетчика таймера */
#define ECAP_ITSource_TimerEqPeriod ECAP_ECEINT_CTRPRD_Msk  /*!< Счетчик таймера равен периоду (в режиме ШИМ) */
#define ECAP_ITSource_TimerEqCompare ECAP_ECEINT_CTRCMP_Msk /*!< Счетчик таймера равен значению сравнения (в режиме ШИМ) */
#define ECAP_ITSource_All (ECAP_ITSource_CapEvt0 |       \
                           ECAP_ITSource_CapEvt1 |       \
                           ECAP_ITSource_CapEvt2 |       \
                           ECAP_ITSource_CapEvt3 |       \
                           ECAP_ITSource_TimerOvf |      \
                           ECAP_ITSource_TimerEqPeriod | \
                           ECAP_ITSource_TimerEqCompare) /*!< Все источники выбраны */

#define IS_ECAP_IT_SOURCE(VALUE) (((VALUE) & ~ECAP_ITSource_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ECAP_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор фронта захвата
  */
typedef enum {
    ECAP_Capture_Polarity_PosEdge, /*!< Захват по переднему фронту */
    ECAP_Capture_Polarity_NegEdge  /*!< Захват по заднему фронту */
} ECAP_Capture_Polarity_TypeDef;
#define IS_ECAP_CAPTURE_POLARITY(VALUE) (((VALUE) == ECAP_Capture_Polarity_PosEdge) || \
                                         ((VALUE) == ECAP_Capture_Polarity_NegEdge))

/**
  * @brief  Выбор режима остановки таймера при отладке
  */
typedef enum {
    ECAP_Halt_Stop = ECAP_ECCTL0_FREESOFT_Stop,             /*!< Мгновенная остановка таймера при отладке */
    ECAP_Halt_StopOnZero = ECAP_ECCTL0_FREESOFT_StopAtZero, /*!< Остановка таймера при переполнении или сбросе (событие достижения 0) */
    ECAP_Halt_Free = ECAP_ECCTL0_FREESOFT_Free              /*!< Нормальный режим */
} ECAP_Halt_TypeDef;
#define IS_ECAP_HALT(VALUE) (((VALUE) == ECAP_Halt_Stop) ||       \
                             ((VALUE) == ECAP_Halt_StopOnZero) || \
                             ((VALUE) == ECAP_Halt_Free))

/**
  * @brief  Выбор источника выходного сигнала синхронизации
  */
typedef enum {
    ECAP_SyncOut_Bypass = ECAP_ECCTL1_SYNCOSEL_Bypass,          /*!< Пропуск синхросигнала со входа на выход */
    ECAP_SyncOut_TimerEqPeriod = ECAP_ECCTL1_SYNCOSEL_CTREqPrd, /*!< Передача события равенства таймера и значения периода в качестве выходного сигнала синхронизации */
    ECAP_SyncOut_Disable = ECAP_ECCTL1_SYNCOSEL_Disable         /*!< Выходной сигнал синхронизации запрещен */
} ECAP_SyncOut_TypeDef;
#define IS_ECAP_SYNC_OUT(VALUE) (((VALUE) == ECAP_SyncOut_Bypass) ||        \
                                 ((VALUE) == ECAP_SyncOut_TimerEqPeriod) || \
                                 ((VALUE) == ECAP_SyncOut_Disable))

/**
  * @brief  Выбор режима работы захвата
  */
typedef enum {
    ECAP_Capture_Mode_Cycle, /*!< Цикличный захват */
    ECAP_Capture_Mode_Single /*!< Однократный захват */
} ECAP_Capture_Mode_TypeDef;
#define IS_ECAP_CAPTURE_MODE(VALUE) (((VALUE) == ECAP_Capture_Mode_Single) || \
                                     ((VALUE) == ECAP_Capture_Mode_Cycle))

/**
  * @brief  Выбор активного уровня в режиме ШИМ
  */
typedef enum {
    ECAP_PWM_Polarity_Pos, /*!< Высокий уровень является активным */
    ECAP_PWM_Polarity_Neg  /*!< Низкий уровень является активным */
} ECAP_PWM_Polarity_TypeDef;
#define IS_ECAP_PWM_POLARITY(VALUE) (((VALUE) == ECAP_PWM_Polarity_Pos) || \
                                     ((VALUE) == ECAP_PWM_Polarity_Neg))

/**
  * @brief  Выбор режима работы блока захвата
  */
typedef enum {
    ECAP_Mode_Capture, /*!< Режим захвата */
    ECAP_Mode_PWM      /*!< Режим ШИМ */
} ECAP_Mode_TypeDef;
#define IS_ECAP_MODE(VALUE) (((VALUE) == ECAP_Mode_Capture) || \
                             ((VALUE) == ECAP_Mode_PWM))

/**
  * @brief  Структура инициализации блока захвата в целом
  */
typedef struct
{
    ECAP_Halt_TypeDef Halt;       /*!< Выбор режима остановки таймера при отладке */
    FunctionalState SyncEn;       /*!< Определеяет возможность синхронизации */
    ECAP_SyncOut_TypeDef SyncOut; /*!< Выбор источника выходного сигнала синхронизации */
    ECAP_Mode_TypeDef Mode;       /*!< Выбор режима работы блока захвата */
} ECAP_Init_TypeDef;

/**
  * @brief  Структура инициализации режима захвата
  */
typedef struct
{
    uint32_t Prescale;                          /*!< Предварительный делитель событий.
                                                     Параметр может принимать любое значение из диапазона 0-63. 0 - делитель выключен. */
    ECAP_Capture_Mode_TypeDef Mode;             /*!< Определеяет режим работы захвата */
    uint32_t StopVal;                           /*!< Значение счетчика событий для остановки одиночного режима захвата.
                                                     Параметр может принимать любое значение из диапазона 0-3. */
    FunctionalState RstEvt0;                    /*!< Определеяет сброс таймера после события захвата 0 */
    FunctionalState RstEvt1;                    /*!< Определеяет сброс таймера после события захвата 1 */
    FunctionalState RstEvt2;                    /*!< Определеяет сброс таймера после события захвата 2 */
    FunctionalState RstEvt3;                    /*!< Определеяет сброс таймера после события захвата 3 */
    ECAP_Capture_Polarity_TypeDef PolarityEvt0; /*!< Определеяет фронт события захвата 0 */
    ECAP_Capture_Polarity_TypeDef PolarityEvt1; /*!< Определеяет фронт события захвата 1 */
    ECAP_Capture_Polarity_TypeDef PolarityEvt2; /*!< Определеяет фронт события захвата 2 */
    ECAP_Capture_Polarity_TypeDef PolarityEvt3; /*!< Определеяет фронт события захвата 3 */
} ECAP_Capture_Init_TypeDef;
#define IS_ECAP_CAPTURE_PRESCALE(VALUE) ((VALUE) < 0x40)
#define IS_ECAP_CAPTURE_STOP(VALUE) ((VALUE) < 0x4)

/**
  * @brief  Структура инициализации режима ШИМ
  */
typedef struct
{
    uint32_t Period;                    /*!< Значение периода ШИМ.
                                             Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    uint32_t Compare;                   /*!< Значение сравнения ШИМ.
                                             Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    ECAP_PWM_Polarity_TypeDef Polarity; /*!< Выбор полярности ШИМ сигнала */
} ECAP_PWM_Init_TypeDef;

/**
  * @}
  */

/** @defgroup ECAP_Exported_Functions Функции
  * @{
  */

/** @defgroup CAP_Config Конфигурация
  * @{
  */

void ECAP_DeInit(ECAP_TypeDef* ECAPx);
void ECAP_Init(ECAP_TypeDef* ECAPx, ECAP_Init_TypeDef* InitStruct);
void ECAP_StructInit(ECAP_Init_TypeDef* InitStruct);

/**
  * @brief   Разрешение работы вывода блока захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_RemapCmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (ECAPx == ECAP0)
        WRITE_REG(SIU->REMAPAF_bit.ECAP0EN, State);
    else if (ECAPx == ECAP1)
        WRITE_REG(SIU->REMAPAF_bit.ECAP1EN, State);
    else /* (ECAPx == ECAP2) */
        WRITE_REG(SIU->REMAPAF_bit.ECAP2EN, State);
}

/**
  * @brief   Настройка режима остановки таймера при отладке
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Halt  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_HaltConfig(ECAP_TypeDef* ECAPx, ECAP_Halt_TypeDef Halt)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_HALT(Halt));

    WRITE_REG(ECAPx->ECCTL0_bit.FREESOFT, Halt);
}

/**
  * @brief   Настройка режима работы блока захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_ModeConfig(ECAP_TypeDef* ECAPx, ECAP_Mode_TypeDef Mode)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_MODE(Mode));

    WRITE_REG(ECAPx->ECCTL1_bit.CAPAPWM, Mode);
}

/**
  * @brief   Разрешение работы таймера, выбранного блока захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_TimerCmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL1_bit.TSCTRSTOP, State);
}

/**
  * @brief   Установка текущего значения счетчика напрямую
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   TimerVal  Значение таймера
  * @retval  void
  */
__STATIC_INLINE void ECAP_SetTimer(ECAP_TypeDef* ECAPx, uint32_t TimerVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->TSCTR, TimerVal);
}

/**
  * @brief   Установка теневого значения таймера для отложенной записи
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   TimerVal  Значение таймера
  * @retval  void
  */
__STATIC_INLINE void ECAP_SetShadowTimer(ECAP_TypeDef* ECAPx, uint32_t TimerVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CTRPHS, TimerVal);
}

/**
  * @brief   Получение текущего значения таймера
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение таймера
  */
__STATIC_INLINE uint32_t ECAP_GetTimer(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->TSCTR);
}

/**
  * @brief   Получение отложенного значения таймера
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение таймера
  */
__STATIC_INLINE uint32_t ECAP_GetShadowTimer(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CTRPHS);
}

/**
  * @brief   Настройка источника выходного сигнала синхронизации
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   SyncOut  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_SyncOutConfig(ECAP_TypeDef* ECAPx, ECAP_SyncOut_TypeDef SyncOut)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_SYNC_OUT(SyncOut));

    WRITE_REG(ECAPx->ECCTL1_bit.SYNCOSEL, SyncOut);
}

/**
  * @brief   Разрешение синхронизации
  * @param   ECAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_SyncCmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL1_bit.SYNCIEN, State);
}

/**
  * @brief   Проведение программной синхронизации
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void ECAP_SwSync(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->ECCTL1_bit.SWSYNC, 1);
}

/**
  * @}
  */

/** @defgroup CAP_Config_PWM_Mode Режим ШИМ
  * @{
  */

void ECAP_PWM_Init(ECAP_TypeDef* ECAPx, ECAP_PWM_Init_TypeDef* InitStruct);
void ECAP_PWM_StructInit(ECAP_PWM_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка полярности ШИМ сигнала
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_PWM_PolarityConfig(ECAP_TypeDef* ECAPx, ECAP_PWM_Polarity_TypeDef Polarity)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_PWM_POLARITY(Polarity));

    WRITE_REG(ECAPx->ECCTL1_bit.APWMPOL, Polarity);
}

/**
  * @brief   Установка значения периода ШИМ
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Значение периода
  * @retval  void
  */
__STATIC_INLINE void ECAP_PWM_SetPeriod(ECAP_TypeDef* ECAPx, uint32_t PeriodVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->PRD, PeriodVal);
}

/**
  * @brief   Установка значения сравнения ШИМ.
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   CompareVal  Значение сравнения.
  * @retval  void
  */
__STATIC_INLINE void ECAP_PWM_SetCompare(ECAP_TypeDef* ECAPx, uint32_t CompareVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CMP, CompareVal);
}

/**
  * @brief   Установка значения периода ШИМ для отложенной записи
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Значение периода
  * @retval  void
  */
__STATIC_INLINE void ECAP_PWM_SetShadowPeriod(ECAP_TypeDef* ECAPx, uint32_t PeriodVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->PRDSHDW, PeriodVal);
}

/**
  * @brief   Установка значения сравнения ШИМ для отложенной записи
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   CompareVal  Значение сравнения
  * @retval  void
  */
__STATIC_INLINE void ECAP_PWM_SetShadowCompare(ECAP_TypeDef* ECAPx, uint32_t CompareVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CMPSHDW, CompareVal);
}

/**
  * @brief   Получение текущего периода ШИМ
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение периода
  */
__STATIC_INLINE uint32_t ECAP_PWM_GetPeriod(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->PRD);
}

/**
  * @brief   Получение текущего значения сравнения ШИМ
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t ECAP_PWM_GetCompare(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CMP);
}

/**
  * @brief   Получение отложенного значения периода ШИМ
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение периода
  */
__STATIC_INLINE uint32_t ECAP_PWM_GetShadowPeriod(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->PRDSHDW);
}

/**
  * @brief   Получение отложенного значения сравнения ШИМ
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t ECAP_PWM_GetShadowCompare(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CMPSHDW);
}

/**
  * @}
  */

/** @defgroup CAP_Config_CAP_Mode Режим захвата
  * @{
  */

void ECAP_Capture_Init(ECAP_TypeDef* ECAPx, ECAP_Capture_Init_TypeDef* InitStruct);
void ECAP_Capture_StructInit(ECAP_Capture_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка режима захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_ModeConfig(ECAP_TypeDef* ECAPx, ECAP_Capture_Mode_TypeDef Mode)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_MODE(Mode));

    WRITE_REG(ECAPx->ECCTL1_bit.CONTOST, Mode);
}

/**
  * @brief   Настройка счетчика событий для остановки одиночного режима захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   StopVal  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_StopConfig(ECAP_TypeDef* ECAPx, uint32_t StopVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_STOP(StopVal));

    WRITE_REG(ECAPx->ECCTL1_bit.STOPWRAP, StopVal);
}

/**
  * @brief   Настройка предварительного делителя событий
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   PrescaleVal  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_PrescaleConfig(ECAP_TypeDef* ECAPx, uint32_t PrescaleVal)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_PRESCALE(PrescaleVal));

    WRITE_REG(ECAPx->ECCTL0_bit.PRESCALE, PrescaleVal);
}

/**
  * @brief   Настройка фронта события захвата 0
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_PolarityEvt0Config(ECAP_TypeDef* ECAPx, ECAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(ECAPx->ECCTL0_bit.CAP0POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 1
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_PolarityEvt1Config(ECAP_TypeDef* ECAPx, ECAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(ECAPx->ECCTL0_bit.CAP1POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 2
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_PolarityEvt2Config(ECAP_TypeDef* ECAPx, ECAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(ECAPx->ECCTL0_bit.CAP2POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 3
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_PolarityEvt3Config(ECAP_TypeDef* ECAPx, ECAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(ECAPx->ECCTL0_bit.CAP3POL, Polarity);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 0
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_RstEvt0Cmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL0_bit.CTRRST0, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 1
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_RstEvt1Cmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL0_bit.CTRRST1, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 2
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_RstEvt2Cmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL0_bit.CTRRST2, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 3
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_RstEvt3Cmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL0_bit.CTRRST3, State);
}

/**
  * @brief   Разрешение захвата для выбранного блока захвата
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_Cmd(ECAP_TypeDef* ECAPx, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ECAPx->ECCTL1_bit.REARM, State);
    WRITE_REG(ECAPx->ECCTL0_bit.CAPLDEN, State);
}

/**
  * @brief   Установка значения регистра захвата 0
  * @param   ECAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_SetCap0(ECAP_TypeDef* ECAPx, uint32_t Value)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CAP0, Value);
}

/**
  * @brief   Установка значения регистра захвата 1
  * @param   ECAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_SetCap1(ECAP_TypeDef* ECAPx, uint32_t Value)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CAP1, Value);
}

/**
  * @brief   Установка значения регистра захвата 2
  * @param   ECAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_SetCap2(ECAP_TypeDef* ECAPx, uint32_t Value)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CAP2, Value);
}

/**
  * @brief   Установка значения регистра захвата 3
  * @param   ECAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void ECAP_Capture_SetCap3(ECAP_TypeDef* ECAPx, uint32_t Value)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->CAP3, Value);
}

/**
  * @brief   Получение текущего значения из регистра захвата 0
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ECAP_Capture_GetCap0(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CAP0);
}

/**
  * @brief   Получение текущего значения из регистра захвата 1
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ECAP_Capture_GetCap1(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CAP1);
}

/**
  * @brief   Получение текущего значения из регистра захвата 2
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ECAP_Capture_GetCap2(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CAP2);
}

/**
  * @brief   Получение текущего значения из регистра захвата 3
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t ECAP_Capture_GetCap3(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return READ_REG(ECAPx->CAP3);
}

/**
  * @}
  */

/** @defgroup CAP_IT Прерывания
  * @{
  */

/**
  * @brief   Разрешение генерации прерываний
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений ECAP_ITSource_x из @ref ECAP_ITSource_define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ECAP_ITCmd(ECAP_TypeDef* ECAPx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(ECAPx->ECEINT, ITSource, State ? (uint32_t)ITSource : 0);
}

/**
  * @brief   Принудительный вызов прерывания выбранного блока захвата
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений ECAP_ITSource_x из @ref ECAP_ITSource_define.
  * @retval  void
  */
__STATIC_INLINE void ECAP_ITForceCmd(ECAP_TypeDef* ECAPx, uint32_t ITSource)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_IT_SOURCE(ITSource));

    WRITE_REG(ECAPx->ECFRC, ITSource);
}

/**
  * @brief   Чтение статуса прерывания выбранного блока захвата
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений ECAP_ITStatus_x из @ref ECAP_ITStatus_define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus ECAP_ITStatus(ECAP_TypeDef* ECAPx, uint32_t ITStatus)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(ECAPx->ECFLG, ITStatus);
}

/**
  * @brief   Сброс статуса прерывания выбранного блока захвата
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений ECAP_ITStatus_x из @ref ECAP_ITStatus_define.
  * @retval  void
  */
__STATIC_INLINE void ECAP_ITStatusClear(ECAP_TypeDef* ECAPx, uint32_t ITStatus)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));
    assert_param(IS_ECAP_IT_STATUS(ITStatus));

    WRITE_REG(ECAPx->ECCLR, ITStatus);
}

/**
  * @brief   Чтение активного статуса прерывания выбранного блока захвата
  * @param   ECAPx  Выбор ECAP, где x лежит в диапазоне 0-2
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus ECAP_ITPendStatus(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    return (FlagStatus)READ_BIT(ECAPx->PEINT, ECAP_PEINT_PEINT_Msk);
}

/**
  * @brief   Сброс активности прерывания выбранного блока захвата.
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void ECAP_ITPendStatusClear(ECAP_TypeDef* ECAPx)
{
    assert_param(IS_ECAP_PERIPH(ECAPx));

    WRITE_REG(ECAPx->PEINT, ECAP_PEINT_PEINT_Msk);
}

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_ECAP_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
