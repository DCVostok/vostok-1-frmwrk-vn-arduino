/**
  ******************************************************************************
  * @file    niietcm4_timer.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с таймерами
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    03.12.2015
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

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_timer.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup TIMER
  * @brief Драйвер для таймеров
  * @{
  */ 

/** @defgroup TIMER_Private Приватные данные
  * @{
  */

/** @defgroup TIMER_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Разрешение работы выбранного таймера.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void TIMER_Cmd(NT_TIMER_TypeDef* TIMERx, FunctionalState State)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    TIMERx->CTRL_bit.ON = (uint32_t)State;
}

/**
  * @brief  Настройка периода опустошения выбранного таймера.
  * @attention В качестве альтернативы может применяться как ручное заполнение
  *   регистра перезагрузки @ref TIMER_SetReload так и автоматический расчет,
  *   исходя из желаемой частоты опустошения таймера @ref TIMER_FreqConfig.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  TimerClkFreq  Частота в Гц, которой тактируется таймер.
  * @param  TimerPeriod   Период опустошения таймера в мкс.
  * @retval Нет
  */

void TIMER_PeriodConfig(NT_TIMER_TypeDef* TIMERx, uint32_t TimerClkFreq, uint32_t TimerPeriod)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->RELOAD = TimerPeriod * (TimerClkFreq / 1000000);
}

/**
  * @brief  Настройка частоты опустошения выбранного таймера.
  * @attention В качестве альтернативы может применяться как ручное заполнение
  *   регистра перезагрузки @ref TIMER_SetReload так и автоматический расчет,
  *   исходя из желаемого периода опустошения таймера @ref TIMER_PeriodConfig.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  TimerClkFreq  Частота в Гц, которой тактируется таймер.
  * @param  TimerFreq   Частота опустошения таймера в Гц.
  * @retval Нет
  */

void TIMER_FreqConfig(NT_TIMER_TypeDef* TIMERx, uint32_t TimerClkFreq, uint32_t TimerFreq)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->RELOAD = TimerClkFreq / TimerFreq;
}

/**
  * @brief  Установка значения перезагрузки.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  ReloadVal  Значение перезагрузки.
  * @retval Нет
  */

void TIMER_SetReload(NT_TIMER_TypeDef* TIMERx, uint32_t ReloadVal)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->RELOAD = ReloadVal;
}

/**
  * @brief  Получение текущего значения перезагрузки.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @retval ReloadVal  Значение перезагрузки.
  */

uint32_t TIMER_GetReload(NT_TIMER_TypeDef* TIMERx)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return TIMERx->RELOAD;
}

/**
  * @brief  Установка значения счетчика.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  CounterVal  Значение счетчика.
  * @retval Нет
  */

void TIMER_SetCounter(NT_TIMER_TypeDef* TIMERx, uint32_t CounterVal)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->VALUE = CounterVal;
}

/**
  * @brief  Получение текущего значения счетчика.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @retval CounterVal  Значение счетчика.
  */

uint32_t TIMER_GetCounter(NT_TIMER_TypeDef* TIMERx)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return TIMERx->VALUE;
}

/**
  * @brief  Выбор режима работы входа внешнего тактирования.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  TIMER_ExtInput  Выбор режима работы.
  *   Параметр принимает любое значение из @ref TIMER_ExtInput_TypeDef.
  * @retval Нет
  */

void TIMER_ExtInputConfig(NT_TIMER_TypeDef* TIMERx, TIMER_ExtInput_TypeDef TIMER_ExtInput)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_TIMER_EXT_INPUT(TIMER_ExtInput));

    if (TIMER_ExtInput == TIMER_ExtInput_CountEn)
    {
        TIMERx->CTRL_bit.EXTINPUT_EN = 1;
    }
    else if (TIMER_ExtInput == TIMER_ExtInput_CountClk)
    {
        TIMERx->CTRL_bit.EXTINPUT_CLK = 1;
        TIMERx->CTRL_bit.EXTINPUT_EN = 1;
    }
    else /* (TIMER_ExtInput == TIMER_ExtInput_Disable) */
    {
        TIMERx->CTRL_bit.EXTINPUT_CLK = 0;
        TIMERx->CTRL_bit.EXTINPUT_EN = 0;
    }
}

/**
  * @brief  Разрешение работы прерывания выбранного таймера.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void TIMER_ITCmd(NT_TIMER_TypeDef* TIMERx, FunctionalState State)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    TIMERx->CTRL_bit.INTEN = (uint32_t)State;
}

/**
  * @brief  Чтение статуса прерывания выбранного таймера.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @retval Status Статус прерывания.
  */

FlagStatus TIMER_ITStatus(NT_TIMER_TypeDef* TIMERx)
{
    FlagStatus Status;

    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    if (TIMERx->INTSTATUS_INTCLEAR_bit.INT)
    {
        Status = Flag_SET;
    }
    else /* (TIMERx->INTSTATUS_INTCLEAR_bit.INT) */
    {
        Status = Flag_CLEAR;
    }

    return Status;
}

/**
  * @brief  Очищение статусного бита прерывания выбранного таймера.
  * @param  TIMERx  Выбор таймера, где x лежит в диапазоне 0-2.
  * @retval Нет
  */

void TIMER_ITStatusClear(NT_TIMER_TypeDef* TIMERx)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->INTSTATUS_INTCLEAR_bit.INT = 1;
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

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
