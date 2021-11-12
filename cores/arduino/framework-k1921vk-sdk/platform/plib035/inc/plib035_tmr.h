/**
  ******************************************************************************
  * @file    plib035_tmr.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          TMR, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_TMR_H
#define __PLIB035_TMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup TMR
  * @brief Драйвер для работы с TMR
  * @{
  */

/** @defgroup TMR_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup TMR_Exported_Types Типы
  * @{
  */

/**
  * @brief  Настройка внешнего тактирования таймера
  */
typedef enum {
    TMR_ExtInput_Disable = 0x0UL,                                         /*!< Внешнее тактирование не используется */
    TMR_ExtInput_CountClk = TMR_CTRL_EXTINEN_Msk | TMR_CTRL_EXTINCLK_Msk, /*!< Таймер считает по внешнему тактовому сигналу */
    TMR_ExtInput_CountEn = TMR_CTRL_EXTINEN_Msk                           /*!< Таймер считает по внутреннему тактовому сигналу и только тогда, когда на выводе "1" */
} TMR_ExtInput_TypeDef;
#define IS_TMR_EXT_INPUT(VALUE) (((VALUE) == TMR_ExtInput_Disable) ||  \
                                 ((VALUE) == TMR_ExtInput_CountClk) || \
                                 ((VALUE) == TMR_ExtInput_CountEn))
/**
  * @}
  */

/** @defgroup TMR_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы выбранного таймера
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TMR_Cmd(TMR_TypeDef* TMRx, FunctionalState State)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TMRx->CTRL_bit.ON, State);
}

/**
  * @brief   Установка значения перезагрузки
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   LoadVal  Значение перезагрузки
  * @retval  void
  */
__STATIC_INLINE void TMR_SetLoad(TMR_TypeDef* TMRx, uint32_t LoadVal)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    WRITE_REG(TMRx->LOAD, LoadVal);
}

/**
  * @brief   Получение текущего значения перезагрузки
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Val  Значение перезагрузки
  */
__STATIC_INLINE uint32_t TMR_GetLoad(TMR_TypeDef* TMRx)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    return READ_REG(TMRx->LOAD);
}

/**
  * @brief   Установка значения счетчика
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   CounterVal  Значение счетчика
  * @retval  void
  */
__STATIC_INLINE void TMR_SetCounter(TMR_TypeDef* TMRx, uint32_t CounterVal)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    WRITE_REG(TMRx->VALUE, CounterVal);
}

/**
  * @brief   Получение текущего значения счетчика.
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Val  Значение счетчика
  */
__STATIC_INLINE uint32_t TMR_GetCounter(TMR_TypeDef* TMRx)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    return READ_REG(TMRx->VALUE);
}

/**
  * @brief   Выбор режима работы входа внешнего тактирования.
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   TMR_ExtInput  Выбор режима работы
  * @retval  void
  */

__STATIC_INLINE void TMR_ExtInputConfig(TMR_TypeDef* TMRx, TMR_ExtInput_TypeDef ExtInput)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_EXT_INPUT(ExtInput));

    MODIFY_REG(TMRx->CTRL, TMR_CTRL_EXTINEN_Msk | TMR_CTRL_EXTINCLK_Msk, ExtInput);
}

/**
  * @brief   Разрешение работы прерывания выбранного таймера
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TMR_ITCmd(TMR_TypeDef* TMRx, FunctionalState State)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TMRx->CTRL_bit.INTEN, State);
}

/**
  * @brief   Чтение статуса прерывания выбранного таймера
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus TMR_ITStatus(TMR_TypeDef* TMRx)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    return (FlagStatus)READ_BIT(TMRx->INTSTATUS, TMR_INTSTATUS_INT_Msk);
}

/**
  * @brief   Очищение статусного бита прерывания выбранного таймера.
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3.
  * @retval  void
  */
__STATIC_INLINE void TMR_ITStatusClear(TMR_TypeDef* TMRx)
{
    assert_param(IS_TMR_PERIPH(TMRx));

    WRITE_REG(TMRx->INTSTATUS, TMR_INTSTATUS_INT_Msk);
}

void TMR_PeriodConfig(TMR_TypeDef* TMRx, uint32_t TimerClkFreq, uint32_t TimerPeriod);
void TMR_FreqConfig(TMR_TypeDef* TMRx, uint32_t TimerClkFreq, uint32_t TimerFreq);

/**
  * @brief   Разрешение генерации запросов к DMA
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TMR_DMAReqCmd(TMR_TypeDef* TMRx, FunctionalState State)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TMRx->DMAREQ_bit.EN, State);
}

/**
  * @brief   Разрешение генерации сигналов запуска АЦП
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TMR_ADCSOCCmd(TMR_TypeDef* TMRx, FunctionalState State)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TMRx->ADCSOC_bit.EN, State);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_TMR_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
