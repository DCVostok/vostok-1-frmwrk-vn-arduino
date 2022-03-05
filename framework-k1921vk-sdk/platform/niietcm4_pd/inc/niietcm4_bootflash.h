/**
  ******************************************************************************
  * @file    niietcm4_bootflash.h
  *
  * @brief   Файл содержит все прототипы функций для загрузочной флеш.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    18.11.2015
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
#ifndef __NIIETCM4_BOOTFLASH_H
#define __NIIETCM4_BOOTFLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup BOOTFLASH
  * @{
  */

/** @defgroup BOOTFLASH_Exported_Constants Константы
  * @{
  */

/**
  * @brief Ключ для проведения операций с контроллером загрузочной флеш.
  */

#define BOOTFLASH_MAGIC_KEY             ((uint32_t)0xA4420000)

/** @defgroup BOOTFLASH_Exported_Constants_mainflash Основная область флеш
  * @{
  */

#define BOOTFLASH_PAGE_SIZE_BYTES       ((uint32_t)8192)    /*!< Размер страницы в байтах. */
#define BOOTFLASH_PAGE_TOTAL            ((uint32_t)128)     /*!< Общее количество страниц. */
#define BOOTFLASH_TOTAL_BYTES           (BOOTFLASH_PAGE_SIZE_BYTES*BOOTFLASH_PAGE_TOTAL)    /*!< Общий размер основной области. */

/**
  * @brief Макрос проверки номера страницы основной области загрузочной флеш на попадание в допустимый диапазон.
  */

#define IS_BOOTFLASH_PAGE_NUM(PAGE_NUM) (PAGE_NUM < BOOTFLASH_PAGE_TOTAL)

/**
  * @}
  */

/** @defgroup BOOTFLASH_Exported_Constants_infoflash Информационная область флеш
  * @{
  */

#define BOOTFLASH_INFO_PAGE_SIZE_BYTES   BOOTFLASH_PAGE_SIZE_BYTES  /*!< Размер страницы в байтах. */
#define BOOTFLASH_INFO_PAGE_TOTAL        ((uint32_t)1)              /*!< Общее количество страниц. */
#define BOOTFLASH_INFO_TOTAL_BYTES       (BOOTFLASH_PAGE_SIZE_BYTES*BOOTFLASH_PAGE_TOTAL)   /*!< Общий размер информационной области. */

/**
  * @brief Макрос проверки номера страницы информационной области загрузочной флеш на попадание в допустимый диапазон.
  */

#define IS_BOOTFLASH_INFO_PAGE_NUM(PAGE_NUM) (PAGE_NUM < BOOTFLASH_INFO_PAGE_TOTAL)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup BOOTFLASH_Exported_Types Типы
  * @{
  */

/**
  * @brief  Статус работы контроллера загрузочной флеш-памяти.
  */

typedef enum
{
    BOOTFLASH_Status_None       = ((uint32_t)0),    /*!< Операция выполняется или отсутствует. */
    BOOTFLASH_Status_Complete   = ((uint32_t)1),    /*!< Операция успешно завершена. */
    BOOTFLASH_Status_Error      = ((uint32_t)3)     /*!< Операция завершена с ошибкой. */
}BOOTFLASH_Status_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref BOOTFLASH_Status_TypeDef.
  */

#define IS_BOOTFLASH_STATUS(STATUS) (((STATUS) == BOOTFLASH_Status_None) || \
                                     ((STATUS) == BOOTFLASH_Status_Complete) || \
                                     ((STATUS) == BOOTFLASH_Status_Error))

/**
 * @}
 */

/** @defgroup BOOTFLASH_Exported_Functions Функции
  * @{
  */

void BOOTFLASH_Init(uint32_t SysClkFreq);
void BOOTFLASH_ITCmd(FunctionalState State);

/** @defgroup BOOTFLASH_Exported_Functions_mainflash Основная область флеш
  * @{
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Write(uint32_t Address, uint32_t Data0, uint32_t Data1, uint32_t Data2, uint32_t Data3);
__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_PageErase(uint32_t PageNum);
__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_FullErase(void);

/**
  * @}
  */

/** @defgroup BOOTFLASH_Exported_Functions_infoflash Информационная область флеш
  * @{
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Info_Write(uint32_t Address, uint32_t Data0, uint32_t Data1, uint32_t Data2, uint32_t Data3);
__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Info_PageErase(uint32_t PageNum);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_BOOTFLASH_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
