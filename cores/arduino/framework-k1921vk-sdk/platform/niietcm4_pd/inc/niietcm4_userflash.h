/**
  ******************************************************************************
  * @file    niietcm4_userflash.h
  *
  * @brief   Файл содержит все прототипы функций для пользовательской флеш.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    07.12.2015
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
#ifndef __NIIETCM4_USERFLASH_H
#define __NIIETCM4_USERFLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup USERFLASH
  * @{
  */

/** @defgroup USERFLASH_Exported_Constants Константы
  * @{
  */

/**
  * @brief Время ожидания выполнения операции с флеш.
  */

#define USERFLASH_OPERATION_TIMEOUT  ((uint32_t)10000000)

/**
  * @brief Ключ для проведения операций с контроллером пользовательской флеш.
  */

#define USERFLASH_MAGIC_KEY             ((uint32_t)0xA4420000)

/** @defgroup USERFLASH_Exported_Constants_mainflash Основная область флеш
  * @{
  */

#define USERFLASH_PAGE_SIZE_BYTES       ((uint32_t)256)    /*!< Размер страницы в байтах. */
#define USERFLASH_PAGE_TOTAL            ((uint32_t)256)    /*!< Общее количество страниц. */
#define USERFLASH_TOTAL_BYTES           (USERFLASH_PAGE_SIZE_BYTES*USERFLASH_PAGE_TOTAL)    /*!< Общий размер основной области. */

/**
  * @brief Макрос проверки номера страницы основной области пользовательской флеш на попадание в допустимый диапазон.
  */

#define IS_USERFLASH_PAGE_NUM(PAGE_NUM) (PAGE_NUM < USERFLASH_PAGE_TOTAL)

/**
  * @}
  */

/** @defgroup USERFLASH_Exported_Constants_infoflash Информационная область флеш
  * @{
  */

#define USERFLASH_INFO_PAGE_SIZE_BYTES   USERFLASH_PAGE_SIZE_BYTES  /*!< Размер страницы в байтах. */
#define USERFLASH_INFO_PAGE_TOTAL        ((uint32_t)2)              /*!< Общее количество страниц. */
#define USERFLASH_INFO_TOTAL_BYTES       (USERFLASH_PAGE_SIZE_BYTES*USERFLASH_PAGE_TOTAL)   /*!< Общий размер информационной области. */

/**
  * @brief Макрос проверки номера страницы информационной области пользовательской флеш на попадание в допустимый диапазон.
  */

#define IS_USERFLASH_INFO_PAGE_NUM(PAGE_NUM) (PAGE_NUM < USERFLASH_INFO_PAGE_TOTAL)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup USERFLASH_Exported_Types Типы
  * @{
  */

/**
  * @brief  Статус работы контроллера пользовательской флеш-памяти.
  */

typedef enum
{
    USERFLASH_Status_None       = ((uint32_t)0),    /*!< Операция выполняется или отсутствует. */
    USERFLASH_Status_Complete   = ((uint32_t)1),    /*!< Операция успешно завершена. */
    USERFLASH_Status_Error      = ((uint32_t)3)     /*!< Операция завершена с ошибкой. */
}USERFLASH_Status_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref USERFLASH_Status_TypeDef.
  */

#define IS_USERFLASH_STATUS(STATUS) (((STATUS) == USERFLASH_Status_None) || \
                                     ((STATUS) == USERFLASH_Status_Complete) || \
                                     ((STATUS) == USERFLASH_Status_Error))

/**
 * @}
 */

/** @defgroup USERFLASH_Exported_Functions Функции
  * @{
  */

void USERFLASH_Init(uint32_t SysClkFreq);
void USERFLASH_ITCmd(FunctionalState State);

/** @defgroup USERFLASH_Exported_Functions_mainflash Основная область флеш
  * @{
  */

uint32_t USERFLASH_Read(uint32_t Address);
USERFLASH_Status_TypeDef USERFLASH_Write(uint32_t Address, uint32_t Data);
USERFLASH_Status_TypeDef USERFLASH_PageErase(uint32_t PageNum);
USERFLASH_Status_TypeDef USERFLASH_FullErase(void);

/**
  * @}
  */

/** @defgroup USERFLASH_Exported_Functions_infoflash Информационная область флеш
  * @{
  */

uint32_t USERFLASH_Info_Read(uint32_t Address);
USERFLASH_Status_TypeDef USERFLASH_Info_Write(uint32_t Address, uint32_t Data);
USERFLASH_Status_TypeDef USERFLASH_Info_PageErase(uint32_t PageNum);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_USERFLASH_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
