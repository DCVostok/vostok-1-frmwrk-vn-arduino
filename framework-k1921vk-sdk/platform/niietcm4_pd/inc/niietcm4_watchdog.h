/**
  ******************************************************************************
  * @file    niietcm4_watchdog.h
  *
  * @brief   Файл содержит все прототипы функций для сторожевого таймера.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_WATCHDOG_H
#define __NIIETCM4_WATCHDOG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup WATCHDOG
  * @{
  */

/** @defgroup WATCHDOG_Exported_Types Типы
  * @{
  */

 /**
   * @brief Макрос проверки соответсвия величины значения перезагрузки диапазону.
   */

 #define IS_WATCHDOG_RELOAD(RELOAD) ((RELOAD) > ((uint32_t)0x0))

/**
 * @}
 */

/** @defgroup WATCHDOG_Exported_Constants Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup WATCHDOG_Exported_Functions Функции
  * @{
  */

/** @defgroup WATCHDOG_Config Конфигурация
  * @{
  */

void WATCHDOG_Cmd(FunctionalState State);
void WATCHDOG_SetReload(uint32_t ReloadVal);
uint32_t WATCHDOG_GetReload(void);
uint32_t WATCHDOG_GetCounter(void);
void WATCHDOG_RstCmd(FunctionalState State);
void WATCHDOG_LockCmd(FunctionalState State);

/**
  * @}
  */

/** @defgroup WATCHDOG_IT Прерывания
  * @{
  */

FlagStatus WATCHDOG_ITRawStatus(void);
FlagStatus WATCHDOG_ITMaskedStatus(void);
void WATCHDOG_ITStatusClear(void);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_WATCHDOG_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
