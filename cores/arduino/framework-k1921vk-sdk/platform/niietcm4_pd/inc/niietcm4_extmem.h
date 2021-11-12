/**
  ******************************************************************************
  * @file    niietcm4_extmem.h
  *
  * @brief   Файл содержит все прототипы функций для интерфейса внешней памяти.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    08.12.2015
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
#ifndef __NIIETCM4_EXTMEM_H
#define __NIIETCM4_EXTMEM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup EXTMEM
  * @{
  */

/** @defgroup EXTMEM_Exported_Constants Константы
  * @{
  */

/** @defgroup EXTMEM_Exported_Constants_CE_Mask Маски адреса
  * @{
  */

#define EXTMEM_CEMask_Addr_11      ((uint32_t)0x0001)  /*!< Маска бита 11 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_12      ((uint32_t)0x0002)  /*!< Маска бита 12 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_13      ((uint32_t)0x0004)  /*!< Маска бита 13 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_14      ((uint32_t)0x0008)  /*!< Маска бита 14 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_15      ((uint32_t)0x0010)  /*!< Маска бита 15 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_16      ((uint32_t)0x0020)  /*!< Маска бита 16 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_17      ((uint32_t)0x0040)  /*!< Маска бита 17 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_18      ((uint32_t)0x0080)  /*!< Маска бита 18 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_19      ((uint32_t)0x0100)  /*!< Маска бита 19 адреса контроллера внешней памяти. */
#define EXTMEM_CEMask_Addr_11_19   ((uint32_t)0x01FF)  /*!< Маски [19:11] битов адреса контроллера внешней памяти. */

/**
   * @brief  Макрос проверки соответсвия маски адреса разрешенному диапазону.
   */

#define IS_EXTMEM_CE_MASK(CE_MASK) (((CE_MASK) & ((uint32_t)0xFFFFFE00)) == ((uint32_t)0x00))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup EXTMEM_Exported_Types Типы
  * @{
  */

/**
  * @brief  Разрядность контроллера внешней памяти.
  */

typedef enum
{
    EXTMEM_Width_8bit,      /*!< 8-разрядный режим работы. */
    EXTMEM_Width_16bit      /*!< 16-разрядный режим работы. */
}EXTMEM_Width_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref EXTMEM_Width_TypeDef.
  */

#define IS_EXTMEM_WIDTH(WIDTH) (((WIDTH) == EXTMEM_Width_8bit) || \
                                ((WIDTH) == EXTMEM_Width_16bit))

/**
  * @brief  Длительность цикла переключения шины в системных тактах.
  */

typedef enum
{
    EXTMEM_RWWaitState_1,      /*!< 1 цикл ожидания. */
    EXTMEM_RWWaitState_2,      /*!< 2 цикла ожидания. */
    EXTMEM_RWWaitState_3,      /*!< 3 цикла ожидания. */
    EXTMEM_RWWaitState_4,      /*!< 4 цикла ожидания. */
    EXTMEM_RWWaitState_5,      /*!< 5 циклов ожидания. */
    EXTMEM_RWWaitState_6,      /*!< 6 циклов ожидания. */
    EXTMEM_RWWaitState_7,      /*!< 7 циклов ожидания. */
    EXTMEM_RWWaitState_8,      /*!< 8 циклов ожидания. */
}EXTMEM_RWWaitState_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref EXTMEM_RWWaitState_TypeDef.
  */

#define IS_EXTMEM_RW_WAITSTATE(WAITSTATE) (((WAITSTATE) == EXTMEM_RWWaitState_1) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_2) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_3) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_4) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_5) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_6) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_7) || \
                                           ((WAITSTATE) == EXTMEM_RWWaitState_8))

/**
  * @brief  Длительность цикла записи слова данных в системных тактах.
  */

typedef enum
{
    EXTMEM_WriteWaitState_1,      /*!< 1 цикл ожидания. */
    EXTMEM_WriteWaitState_2,      /*!< 2 цикла ожидания. */
    EXTMEM_WriteWaitState_3,      /*!< 3 цикла ожидания. */
    EXTMEM_WriteWaitState_4,      /*!< 4 цикла ожидания. */
    EXTMEM_WriteWaitState_5,      /*!< 5 циклов ожидания. */
    EXTMEM_WriteWaitState_6,      /*!< 6 циклов ожидания. */
    EXTMEM_WriteWaitState_7,      /*!< 7 циклов ожидания. */
    EXTMEM_WriteWaitState_8,      /*!< 8 циклов ожидания. */
}EXTMEM_WriteWaitState_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref EXTMEM_WriteWaitState_TypeDef.
  */

#define IS_EXTMEM_WRITE_WAITSTATE(WAITSTATE) (((WAITSTATE) == EXTMEM_WriteWaitState_1) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_2) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_3) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_4) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_5) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_6) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_7) || \
                                              ((WAITSTATE) == EXTMEM_WriteWaitState_8))

/**
  * @brief  Длительность цикла чтения слова данных в системных тактах.
  */

typedef enum
{
    EXTMEM_ReadWaitState_1,      /*!< 1 цикл ожидания. */
    EXTMEM_ReadWaitState_2,      /*!< 2 цикла ожидания. */
    EXTMEM_ReadWaitState_3,      /*!< 3 цикла ожидания. */
    EXTMEM_ReadWaitState_4,      /*!< 4 цикла ожидания. */
    EXTMEM_ReadWaitState_5,      /*!< 5 циклов ожидания. */
    EXTMEM_ReadWaitState_6,      /*!< 6 циклов ожидания. */
    EXTMEM_ReadWaitState_7,      /*!< 7 циклов ожидания. */
    EXTMEM_ReadWaitState_8,      /*!< 8 циклов ожидания. */
}EXTMEM_ReadWaitState_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref EXTMEM_ReadWaitState_TypeDef.
  */

#define IS_EXTMEM_READ_WAITSTATE(WAITSTATE) (((WAITSTATE) == EXTMEM_ReadWaitState_1) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_2) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_3) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_4) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_5) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_6) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_7) || \
                                             ((WAITSTATE) == EXTMEM_ReadWaitState_8))

/**
  * @brief  Структура инициализации внешней памяти.
  */

typedef struct
{
    EXTMEM_Width_TypeDef EXTMEM_Width;                      /*!< Разрядность контроллера внешней памяти.
                                                                Параметр может принимать любое значение из @ref EXTMEM_Width_TypeDef. */
    EXTMEM_RWWaitState_TypeDef EXTMEM_RWWaitState;          /*!< Длительность цикла переключения шины в системных тактах.
                                                                Параметр может принимать любое значение из @ref EXTMEM_RWWaitState_TypeDef. */
    EXTMEM_WriteWaitState_TypeDef EXTMEM_WriteWaitState;    /*!< Длительность цикла записи слова данных в системных тактах.
                                                                Параметр может принимать любое значение из @ref EXTMEM_WriteWaitState_TypeDef. */
    EXTMEM_ReadWaitState_TypeDef EXTMEM_ReadWaitState;      /*!< Длительность цикла чтения слова данных в системных тактах.
                                                                Параметр может принимать любое значение из @ref EXTMEM_ReadWaitState_TypeDef. */
    uint32_t CEMask;                                        /*!< Маска адреса для генерации сигналов Cen и Oen.
                                                                Параметр может принимать любое значение из диапазона 0-511. */
}EXTMEM_Init_TypeDef;

/**
 * @}
 */

/** @defgroup EXTMEM_Exported_Functions Функции
  * @{
  */

void EXTMEM_DeInit(void);
void EXTMEM_Init(EXTMEM_Init_TypeDef* EXTMEM_InitStruct);
void EXTMEM_StructInit(EXTMEM_Init_TypeDef* EXTMEM_InitStruct);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_EXTMEM_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
