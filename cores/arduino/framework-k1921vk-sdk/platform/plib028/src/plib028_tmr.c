/**
  ******************************************************************************
  * @file    plib028_tmr.c
  *
  * @brief   Файл содержит реализацию функций для работы с TMR
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

/* Includes ------------------------------------------------------------------*/
#include "plib028_tmr.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup TMR
  * @{
  */

/** @defgroup TMR_Private Приватные данные
  * @{
  */

/** @defgroup TMR_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup TMR_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief      Настройка периода опустошения выбранного таймера.
  * @attention  В качестве альтернативы может применяться как ручное заполнение
  *             регистра перезагрузки @ref TMR_SetLoad так и автоматический расчет,
  *             исходя из желаемой частоты опустошения таймера @ref TMR_FreqConfig.
  * @param      TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param      TimerClkFreq  Частота в Гц, которой тактируется таймер
  * @param      TimerPeriod   Период опустошения таймера в мкс
  * @retval     void
  */
void TMR_PeriodConfig(TMR_TypeDef* TMRx, uint32_t TimerClkFreq, uint32_t TimerPeriod)
{
    TMR_SetLoad(TMRx, TimerPeriod * (TimerClkFreq / 1000000));
}

/**
  * @brief      Настройка частоты опустошения выбранного таймера.
  * @attention  В качестве альтернативы может применяться как ручное заполнение
  *             регистра перезагрузки @ref TMR_SetLoad так и автоматический расчет,
  *             исходя из желаемого периода опустошения таймера @ref TMR_PeriodConfig.
  * @param      TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param      TimerClkFreq  Частота в Гц, которой тактируется таймер
  * @param      TimerFreq   Частота опустошения таймера в Гц
  * @retval     void
  */
void TMR_FreqConfig(TMR_TypeDef* TMRx, uint32_t TimerClkFreq, uint32_t TimerFreq)
{
    TMR_SetLoad(TMRx, TimerClkFreq / TimerFreq);
}

/**
  * @brief   Выбор режима работы входа внешнего тактирования.
  * @param   TMRx  Выбор таймера, где x лежит в диапазоне 0-3
  * @param   TMR_ExtInput  Выбор режима работы
  * @retval  void
  */

void TMR_ExtInputConfig(TMR_TypeDef* TMRx, TMR_ExtInput_TypeDef ExtInput, TMR_ExtInputSel_TypeDef ExtInputSel)
{
    assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_EXT_INPUT(ExtInput));

    if (TMRx == TMR0) {
        MODIFY_REG(SIU->TMRMUX, SIU_TMRMUX_EXTINSEL0_Msk, ExtInputSel << SIU_TMRMUX_EXTINSEL0_Pos);
    } else if (TMRx == TMR1) {
        MODIFY_REG(SIU->TMRMUX, SIU_TMRMUX_EXTINSEL1_Msk, ExtInputSel << SIU_TMRMUX_EXTINSEL1_Pos);
    } else if (TMRx == TMR2) {
        MODIFY_REG(SIU->TMRMUX, SIU_TMRMUX_EXTINSEL2_Msk, ExtInputSel << SIU_TMRMUX_EXTINSEL2_Pos);
    } else /*if (TMRx == TMR3)*/ {
        MODIFY_REG(SIU->TMRMUX, SIU_TMRMUX_EXTINSEL3_Msk, ExtInputSel << SIU_TMRMUX_EXTINSEL3_Pos);
    }

    MODIFY_REG(TMRx->CTRL, TMR_CTRL_EXTINEN_Msk | TMR_CTRL_EXTINCLK_Msk, ExtInput);
    MODIFY_REG(SIU->TMRMUX, SIU_TMRMUX_EXTINSEL0_Msk, ExtInputSel);
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

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
