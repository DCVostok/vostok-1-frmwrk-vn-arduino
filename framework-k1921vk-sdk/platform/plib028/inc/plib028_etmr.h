/**
  ******************************************************************************
  * @file    plib028_etmr.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          ETMR, а также сопутствующие макроопределения и перечисления
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
  * <h2><center>&copy; 2019 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB028_ETMR_H
#define __PLIB028_ETMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup ETMR
  * @brief Драйвер для работы с ETMR
  * @{
  */

/** @defgroup ETMR_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup ETMR_Exported_Types Типы
  * @{
  */

/**
  * @brief  Настройка способа счёта таймера
  */
typedef enum {
    ETMR_Mode_Free = ETMR_CTRL_PERMODE_FreeRun,         /*!< Свободный счёт */
    ETMR_Mode_Periodic = ETMR_CTRL_PERMODE_PeriodicRun, /*!< Периодичный счёт */
} ETMR_Mode_TypeDef;
#define IS_ETMR_MODE(VALUE) (((VALUE) == ETMR_Mode_Free) || \
                             ((VALUE) == ETMR_Mode_Periodic))

/**
  * @brief  Настройка разрядности таймера
  */
typedef enum {
    ETMR_Size_16bit = ETMR_CTRL_SIZE32_16bit, /*!< 16-битный счёт */
    ETMR_Size_32bit = ETMR_CTRL_SIZE32_32bit, /*!< 32-битный счёт */
} ETMR_Size_TypeDef;
#define IS_ETMR_SIZE(VALUE) (((VALUE) == ETMR_Size_16bit) || \
                             ((VALUE) == ETMR_Size_32bit))

/**
  * @brief  Настройка предделителя таймера
  */
typedef enum {
    ETMR_Prescaler_1 = ETMR_CTRL_PRESC_Div1,     /*!< PCLK/1 */
    ETMR_Prescaler_16 = ETMR_CTRL_PRESC_Div16,   /*!< PCLK/16 */
    ETMR_Prescaler_256 = ETMR_CTRL_PRESC_Div256, /*!< PCLK/256 */
} ETMR_Prescaler_TypeDef;
#define IS_ETMR_PRESCALER(VALUE) (((VALUE) == ETMR_Prescaler_1) ||  \
                                  ((VALUE) == ETMR_Prescaler_16) || \
                                  ((VALUE) == ETMR_Prescaler_256))

/**
  * @}
  */

/** @defgroup ETMR_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы выбранного таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ETMR_Cmd(ETMR_TypeDef* ETMRx, FunctionalState State)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ETMRx->CTRL_bit.ON, State);
}

/**
  * @brief   Установка значения перезагрузки
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   LoadVal  Значение перезагрузки
  * @retval  void
  */
__STATIC_INLINE void ETMR_SetLoad(ETMR_TypeDef* ETMRx, uint32_t LoadVal)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    WRITE_REG(ETMRx->LOAD, LoadVal);
}

/**
  * @brief   Установка теневого значения перезагрузки
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   LoadVal  Значение перезагрузки
  * @retval  void
  */
__STATIC_INLINE void ETMR_SetShadowLoad(ETMR_TypeDef* ETMRx, uint32_t LoadVal)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    WRITE_REG(ETMRx->BGLOAD, LoadVal);
}

/**
  * @brief   Получение текущего значения перезагрузки
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Val  Значение перезагрузки
  */
__STATIC_INLINE uint32_t ETMR_GetLoad(ETMR_TypeDef* ETMRx)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    return READ_REG(ETMRx->LOAD);
}

/**
  * @brief   Получение текущего значения счетчика.
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Val  Значение счетчика
  */
__STATIC_INLINE uint32_t ETMR_GetCounter(ETMR_TypeDef* ETMRx)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    return READ_REG(ETMRx->VALUE);
}

/**
  * @brief   Настройка режима счета
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void ETMR_ModeConfig(ETMR_TypeDef* ETMRx, ETMR_Mode_TypeDef Mode)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_ETMR_MODE(Mode));

    WRITE_REG(ETMRx->CTRL_bit.PERMODE, Mode);
}

/**
  * @brief   Настройка разрядности таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   Size  Выбор разрядности
  * @retval  void
  */
__STATIC_INLINE void ETMR_SizeConfig(ETMR_TypeDef* ETMRx, ETMR_Size_TypeDef Size)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_ETMR_SIZE(Size));

    WRITE_REG(ETMRx->CTRL_bit.SIZE32, Size);
}

/**
  * @brief   Настройка предделителя таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   Prescaler  Выбор предделителя
  * @retval  void
  */
__STATIC_INLINE void ETMR_PrescalerConfig(ETMR_TypeDef* ETMRx, ETMR_Prescaler_TypeDef Prescaler)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_ETMR_PRESCALER(Prescaler));

    WRITE_REG(ETMRx->CTRL_bit.PRESC, Prescaler);
}

/**
  * @brief   Разрешение однократного счёта
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   Size  Выбор разрядности
  * @retval  void
  */
__STATIC_INLINE void ETMR_OneShotCmd(ETMR_TypeDef* ETMRx, FunctionalState State)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ETMRx->CTRL_bit.ONESH, State);
}

/**
  * @brief   Разрешение работы прерывания выбранного таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ETMR_ITCmd(ETMR_TypeDef* ETMRx, FunctionalState State)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ETMRx->CTRL_bit.INTEN, State);
}

/**
  * @brief   Чтение немаскированного татуса прерывания выбранного таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus ETMR_ITRawStatus(ETMR_TypeDef* ETMRx)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    return (FlagStatus)READ_BIT(ETMRx->RIS, ETMR_RIS_RINT_Msk);
}

/**
  * @brief   Чтение маскированного татуса прерывания выбранного таймера
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus ETMR_ITMaskedStatus(ETMR_TypeDef* ETMRx)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    return (FlagStatus)READ_BIT(ETMRx->MIS, ETMR_MIS_INT_Msk);
}

/**
  * @brief   Очищение статусного бита прерывания выбранного таймера.
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3.
  * @retval  void
  */
__STATIC_INLINE void ETMR_ITStatusClear(ETMR_TypeDef* ETMRx)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));

    WRITE_REG(ETMRx->INTCLR, ETMR_INTCLR_INTCLR_Msk);
}

/**
  * @brief   Разрешение генерации запросов к DMA
  * @param   ETMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void ETMR_DMAReqCmd(ETMR_TypeDef* ETMRx, FunctionalState State)
{
    assert_param(IS_ETMR_PERIPH(ETMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(ETMRx->DMAREQ_bit.EN, State);
}

void ETMR_PeriodConfig(ETMR_TypeDef* ETMRx, uint32_t TimerClkFreq, uint32_t TimerPeriod);
void ETMR_FreqConfig(ETMR_TypeDef* ETMRx, uint32_t TimerClkFreq, uint32_t TimerFreq);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_ETMR_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
