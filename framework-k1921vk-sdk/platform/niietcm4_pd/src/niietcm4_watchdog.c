/**
  ******************************************************************************
  * @file    niietcm4_watchdog.c
  *
  * @brief   Файл содержит реализацию всех функции для работы со сторожевым
  *          таймером.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    15.01.2016
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

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_watchdog.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup WATCHDOG
  * @brief Драйвер для сторожевого таймера
  * @{
  */ 

/** @defgroup WATCHDOG_Private Приватные данные
  * @{
  */

/** @defgroup WATCHDOG_Private_Defines Приватные константы
  * @{
  */

#define WATCHDOG_Lock_Value     ((uint32_t)0xDEADC0DE)  /*!< Любое значение для блокировки записи в регистры таймера */
#define WATCHDOG_Unlock_Value   ((uint32_t)0x1ACCE551)  /*!< Значение для разблокировки записи в регистры таймера */

/**
  * @}
  */

/** @defgroup WATCHDOG_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Разрешение счета сторожевого таймера и маскирование (включение)
  *   его прерывания.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void WATCHDOG_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_WDT->CTRL_bit.INTEN = (uint32_t)State;
}

/**
  * @brief  Установка значения перезагрузки.
  * @param  ReloadVal  Значение перезагрузки.
  *   Параметр принимает любое значение из диапазона 0x1 - 0xFFFFFFFF.
  * @retval Нет
  */

void WATCHDOG_SetReload(uint32_t ReloadVal)
{
    assert_param(IS_WATCHDOG_RELOAD(ReloadVal));

    NT_WDT->LOAD = ReloadVal;
}

/**
  * @brief  Получение текущего значения перезагрузки.
  * @retval ReloadVal  Значение перезагрузки.
  */

uint32_t WATCHDOG_GetReload()
{
    return NT_WDT->LOAD;
}

/**
  * @brief  Получение текущего значения счетчика.
  * @retval CounterVal  Значение счетчика.
  */

uint32_t WATCHDOG_GetCounter()
{
    return NT_WDT->VALUE;
}

/**
  * @brief  Разрешение сброса по сторожевому таймеру.
  *   Сброс будет произведен когда счетчик досчитает до нуля при установленном
  *   ранее и несброшенном флаге прерывания.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void WATCHDOG_RstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_WDT->CTRL_bit.RESEN = (uint32_t)State;
}

/**
  * @brief  Запрещение записи во все регистры сторожевого таймера для
  *   предотвращения отключения его сбойными программами.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void WATCHDOG_LockCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == DISABLE)
    {
        NT_WDT->LOCK = WATCHDOG_Unlock_Value;
    }
    else /* if (State == ENABLE) */
    {
        NT_WDT->LOCK = WATCHDOG_Lock_Value;
    }
}

/**
  * @brief  Чтение немаскированного флага прерывания сторожевого таймера.
  * @retval Status Статус прерывания.
  */

FlagStatus WATCHDOG_ITRawStatus()
{
    FlagStatus Status;

    if (NT_WDT->RIS_bit.RAWWDTINT)
    {
        Status = Flag_SET;
    }
    else
    {
        Status = Flag_CLEAR;
    }

    return Status;
}

/**
  * @brief  Чтение маскированного флага прерывания сторожевого таймера.
  * @retval Status Статус прерывания.
  */

FlagStatus WATCHDOG_ITMaskedStatus()
{
    FlagStatus Status;

    if (NT_WDT->MIS_bit.WDTINT)
    {
        Status = Flag_SET;
    }
    else
    {
        Status = Flag_CLEAR;
    }

    return Status;
}

/**
  * @brief  Очищение статусного бита прерывания сторожевого таймера.
  * @retval Нет
  */

void WATCHDOG_ITStatusClear()
{
    NT_WDT->INTCLR = 1;
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

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
