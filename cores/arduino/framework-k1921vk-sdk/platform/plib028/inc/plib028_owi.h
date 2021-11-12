/**
  ******************************************************************************
  * @file    plib028_owi.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          OWI, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_OWI_H
#define __PLIB028_OWI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup OWI
  * @brief Драйвер для работы с OWI
  * @{
  */

/** @defgroup OWI_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup OWI_Exported_Types Типы
  * @{
  */

#define IS_OWI_START_DIV(VALUE) ((VALUE) < 0x10000)
#define IS_OWI_PRESENT_PERIOD(VALUE) ((VALUE) < 0x100)
#define IS_OWI_RESET_PERIOD(VALUE) ((VALUE) < 0x100)
#define IS_OWI_BIT_PERIOD(VALUE) ((VALUE) < 0x100)
#define IS_OWI_DATA(VALUE) ((VALUE) < 0x100)

/**
  * @}
  */

/** @defgroup OWI_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы выбранного блока
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void OWI_Cmd(OWI_TypeDef* OWIx, FunctionalState State)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(OWIx->CTRL0_bit.EN, State);
}

/**
  * @brief   Выполнение последовательности сброса линии
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  void
  */
__STATIC_INLINE void OWI_RstCmd(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    WRITE_REG(OWIx->CMD, OWI_CMD_RSTCMD_Msk);
}

/**
  * @brief   Выполнение последовательности чтения данных от ведомого устройства
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  void
  */
__STATIC_INLINE void OWI_ReadCmd(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    WRITE_REG(OWIx->CMD, OWI_CMD_RDCMD_Msk);
}

/**
  * @brief   Конфигурация коэффициента деления PCLK для формирования стартового импульса
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   Div  Значение делителя, в диапазоне 0-0xFFFF
  * @retval  void
  */
__STATIC_INLINE void OWI_StartDivConfig(OWI_TypeDef* OWIx, uint32_t Div)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_OWI_START_DIV(Div));

    WRITE_REG(OWIx->CTRL0_bit.DIV, Div);
}

/**
  * @brief   Конфигурация времени ожидания импульса присутствия от ведомого
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   Val  Значение периода, в единицах периода стартового импульса
  * @retval  void
  */
__STATIC_INLINE void OWI_PresentPeriodConfig(OWI_TypeDef* OWIx, uint32_t Val)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_OWI_PRESENT_PERIOD(Val));

    WRITE_REG(OWIx->CTRL1_bit.PRESPER, Val);
}

/**
  * @brief   Конфигурация времени последовательности сброса
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   Val  Значение периода, в единицах периода стартового импульса
  * @retval  void
  */
__STATIC_INLINE void OWI_ResetPeriodConfig(OWI_TypeDef* OWIx, uint32_t Val)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_OWI_RESET_PERIOD(Val));

    WRITE_REG(OWIx->CTRL1_bit.RSTPER, Val);
}

/**
  * @brief   Конфигурация времени одного принимаемого бита
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   Val  Значение периода, в единицах периода стартового импульса
  * @retval  void
  */
__STATIC_INLINE void OWI_BitPeriodConfig(OWI_TypeDef* OWIx, uint32_t Val)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_OWI_BIT_PERIOD(Val));

    WRITE_REG(OWIx->CTRL1_bit.OBPER, Val);
}

void OWI_TimingConfig(OWI_TypeDef* OWIx, uint32_t OWIClkFreq);

/**
  * @brief   Чтения флага статуса присутствия ведомого устройства
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  Статус
  */
__STATIC_INLINE FlagStatus OWI_PresentStatus(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    return (FlagStatus)READ_BIT(OWIx->STAT, OWI_STAT_PRES_Msk);
}

/**
  * @brief   Чтения флага статуса занятости контроллера интерфейса
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  Статус
  */
__STATIC_INLINE FlagStatus OWI_BusyStatus(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    return (FlagStatus)READ_BIT(OWIx->STAT, OWI_STAT_BUSY_Msk);
}

/**
  * @brief   Чтения флага завершения транзакции
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  Статус
  */
__STATIC_INLINE FlagStatus OWI_DoneStatus(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    return (FlagStatus)READ_BIT(OWIx->STAT, OWI_STAT_DONE_Msk);
}

/**
  * @brief   Очистка флага завершения транзакции
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  void
  */
__STATIC_INLINE void OWI_DoneStatusClear(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    WRITE_REG(OWIx->STAT, OWI_STAT_DONE_Msk);
}

/**
  * @brief   Передача байта данных
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   Data   Данные
  * @retval  void
  */
__STATIC_INLINE void OWI_SendData(OWI_TypeDef* OWIx, uint32_t Data)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_OWI_DATA(Data));

    WRITE_REG(OWIx->DATA, Data);
}

/**
  * @brief   Прием байта данных
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @retval  Val  Данные
  */
__STATIC_INLINE uint32_t OWI_ReceiveData(OWI_TypeDef* OWIx)
{
    assert_param(IS_OWI_PERIPH(OWIx));

    return READ_REG(OWIx->DATA);
}

/**
  * @brief   Разрешение работы прерывания выбранного интерфейса
  * @param   OWIx  Выбор блока, где x лежит в диапазоне 0-1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void OWI_ITCmd(OWI_TypeDef* OWIx, FunctionalState State)
{
    assert_param(IS_OWI_PERIPH(OWIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(OWIx->IRQ_bit.EN, State);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_OWI_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
