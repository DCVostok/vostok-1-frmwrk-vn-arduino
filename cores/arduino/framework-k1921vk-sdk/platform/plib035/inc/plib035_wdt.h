/**
  ******************************************************************************
  * @file    plib035_wdt.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          WDT, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_WDT_H
#define __PLIB035_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup WDT
  * @brief Драйвер для работы с WDT
  * @{
  */

/** @defgroup WDT_Exported_Defines Константы
  * @{
  */

#define WDT_LOCK_VAL 0xDEADC0DEUL   /*!< Любое значение для блокировки записи в регистры таймера */
#define WDT_UNLOCK_VAL 0x1ACCE551UL /*!< Значение для разблокировки записи в регистры таймера */

/**
  * @}
  */

/** @defgroup WDT_Exported_Types Типы
  * @{
  */

#define IS_WDT_LOAD(VALUE) ((VALUE) > 0)

/**
  * @}
  */

/** @defgroup WDT_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение счета сторожевого таймера и маскирование (включение) его прерывания
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void WDT_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(WDT->CTRL_bit.INTEN, State);
}

/**
  * @brief   Установка значения перезагрузки
  * @param   LoadVal  Значение перезагрузки (0x1 - 0xFFFFFFFF)
  * @retval  void
  */
__STATIC_INLINE void WDT_SetLoad(uint32_t LoadVal)
{
    assert_param(IS_WDT_LOAD(LoadVal));

    WRITE_REG(WDT->LOAD, LoadVal);
}

/**
  * @brief   Получение текущего значения перезагрузки
  * @retval  Val  Значение перезагрузки
  */
__STATIC_INLINE uint32_t WDT_GetLoad()
{
    return READ_REG(WDT->LOAD);
}

/**
  * @brief   Получение текущего значения счетчика
  * @retval  Val  Значение счетчика
  */
__STATIC_INLINE uint32_t WDT_GetCounter()
{
    return READ_REG(WDT->VALUE);
}

/**
  * @brief   Разрешение сброса по сторожевому таймеру.
  *          Сброс будет произведен когда счетчик досчитает до нуля при установленном
  *          ранее и несброшенном флаге прерывания
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void WDT_RstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(WDT->CTRL_bit.RESEN, State);
}

/**
  * @brief   Запрещение записи во все регистры сторожевого таймера для
  *          предотвращения его отключения сбойными программами
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void WDT_LockCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == DISABLE) {
        WRITE_REG(WDT->LOCK, WDT_UNLOCK_VAL);
    } else {
        WRITE_REG(WDT->LOCK, WDT_LOCK_VAL);
    }
}

/**
  * @brief   Чтение немаскированного флага прерывания сторожевого таймера
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus WDT_ITRawStatus()
{
    return (FlagStatus)READ_BIT(WDT->RIS, WDT_RIS_RAWWDTINT_Msk);
}

/**
  * @brief  Чтение маскированного флага прерывания сторожевого таймера
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus WDT_ITMaskedStatus()
{
    return (FlagStatus)READ_BIT(WDT->MIS, WDT_MIS_WDTINT_Msk);
}

/**
  * @brief   Очищение статусного бита прерывания сторожевого таймера
  * @retval  void
  */
__STATIC_INLINE void WDT_ITStatusClear()
{
    WRITE_REG(WDT->INTCLR, WDT_INTCLR_WDTCLR_Msk);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_WDT_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
