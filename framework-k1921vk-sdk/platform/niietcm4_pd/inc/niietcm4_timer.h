/**
  ******************************************************************************
  * @file    niietcm4_timer.h
  *
  * @brief   Файл содержит все прототипы функций для таймеров
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_TIMER_H
#define __NIIETCM4_TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup TIMER
  * @{
  */

/** @defgroup TIMER_Exported_Types Типы
  * @{
  */

/**
  * @brief  Настройка внешнего тактирования таймера.
  */

typedef enum
{
    TIMER_ExtInput_Disable,    /*!< Внешнее тактирование не используется. */
    TIMER_ExtInput_CountClk,   /*!< Таймер считает по внешнему тактовому сигналу. */
    TIMER_ExtInput_CountEn     /*!< Таймер считает по внутреннему тактовому сигналу и только тогда, когда на выводе "1". */
}TIMER_ExtInput_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref TIMER_ExtInput_TypeDef.
  */

#define IS_TIMER_EXT_INPUT(EXT_INPUT)  (((EXT_INPUT) == TIMER_ExtInput_Disable) || \
                                        ((EXT_INPUT) == TIMER_ExtInput_CountClk) || \
                                        ((EXT_INPUT) == TIMER_ExtInput_CountEn))

/**
 * @}
 */

/** @defgroup TIMER_Exported_Constants Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup TIMER_Exported_Functions Функции
  * @{
  */

/** @defgroup TIMER_Config Конфигурация
  * @{
  */

void TIMER_Cmd(NT_TIMER_TypeDef* TIMERx, FunctionalState State);
void TIMER_PeriodConfig(NT_TIMER_TypeDef* TIMERx, uint32_t TimerClkFreq, uint32_t TimerPeriod);
void TIMER_FreqConfig(NT_TIMER_TypeDef* TIMERx, uint32_t TimerClkFreq, uint32_t TimerFreq);
void TIMER_SetReload(NT_TIMER_TypeDef* TIMERx, uint32_t ReloadVal);
uint32_t TIMER_GetReload(NT_TIMER_TypeDef* TIMERx);
void TIMER_SetCounter(NT_TIMER_TypeDef* TIMERx, uint32_t CounterVal);
uint32_t TIMER_GetCounter(NT_TIMER_TypeDef* TIMERx);
void TIMER_ExtInputConfig(NT_TIMER_TypeDef* TIMERx, TIMER_ExtInput_TypeDef TIMER_ExtInput);

/**
  * @}
  */

/** @defgroup TIMER_IT Прерывания
  * @{
  */

void TIMER_ITCmd(NT_TIMER_TypeDef* TIMERx, FunctionalState State);
FlagStatus TIMER_ITStatus(NT_TIMER_TypeDef* TIMERx);
void TIMER_ITStatusClear(NT_TIMER_TypeDef* TIMERx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_TIMER_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
