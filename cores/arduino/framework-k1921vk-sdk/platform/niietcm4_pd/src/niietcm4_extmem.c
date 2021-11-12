/**
  ******************************************************************************
  * @file    niietcm4_extmem.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с интерфейсом
  *          внешней памяти.
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

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_extmem.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup EXTMEM
  * @brief Драйвер для интерфейса внешней памяти.
  *
  * @attention Драйвер позволяет управлять только внутренними настройками интерфейса внешней памяти.
  *            Порты ввода-вывода настраиваются отдельно через @ref GPIO :
  *            <br>- @ref GPIO_Init_Deinit.
  *
  *   Общий вид процесса инициализации:
  *   - передаем параметры через структуру типа @ref EXTMEM_Init_TypeDef в функцию @ref EXTMEM_Init;
  *   - интерфейс внешней памяти готов к работе.
  *
  *   Более подробно инициализация и использование внешней памяти показаны в приложенных к драйверу примерах.
  * @{
  */ 

/** @defgroup EXTMEM_Private Приватные данные
  * @{
  */

/** @defgroup EXTMEM_Private_Defines Приватные константы
  * @{
  */

/** @defgroup EXTMEM_Private_Defines_Reset_Value Начальные значения регистров
  * @{
  */

#define EXT_MEM_CFG_Reset_Value        ((uint32_t)0x80000007)  /*!< Значение по сбросу регистра EXT_MEM_CFG */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup EXTMEM_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Инициализирует внешнюю память согласно параметрам структуры EXTMEM_InitStruct.
  * @param  EXTMEM_InitStruct Указатель на структуру типа @ref EXTMEM_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void EXTMEM_Init(EXTMEM_Init_TypeDef* EXTMEM_InitStruct)
{
    assert_param(IS_EXTMEM_CE_MASK(EXTMEM_InitStruct->CEMask));
    assert_param(IS_EXTMEM_WIDTH(EXTMEM_InitStruct->EXTMEM_Width));
    assert_param(IS_EXTMEM_RW_WAITSTATE(EXTMEM_InitStruct->EXTMEM_RWWaitState));
    assert_param(IS_EXTMEM_READ_WAITSTATE(EXTMEM_InitStruct->EXTMEM_ReadWaitState));
    assert_param(IS_EXTMEM_WRITE_WAITSTATE(EXTMEM_InitStruct->EXTMEM_WriteWaitState));

    NT_COMMON_REG->EXT_MEM_CFG_bit.BW = EXTMEM_InitStruct->EXTMEM_Width;
    NT_COMMON_REG->EXT_MEM_CFG_bit.RWWS = EXTMEM_InitStruct->EXTMEM_RWWaitState;
    NT_COMMON_REG->EXT_MEM_CFG_bit.ReadWS = EXTMEM_InitStruct->EXTMEM_ReadWaitState;
    NT_COMMON_REG->EXT_MEM_CFG_bit.WriteWS = EXTMEM_InitStruct->EXTMEM_WriteWaitState;
    NT_COMMON_REG->EXT_MEM_CFG_bit.CE_MASK = EXTMEM_InitStruct->CEMask;
}

/**
  * @brief  Заполнение каждого члена структуры EXTMEM_InitStruct значениями по умолчанию.
  * @param  EXTMEM_InitStruct Указатель на структуру типа @ref EXTMEM_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void EXTMEM_StructInit(EXTMEM_Init_TypeDef* EXTMEM_InitStruct)
{
    EXTMEM_InitStruct->EXTMEM_Width = EXTMEM_Width_16bit;
    EXTMEM_InitStruct->EXTMEM_RWWaitState = EXTMEM_RWWaitState_1;
    EXTMEM_InitStruct->EXTMEM_ReadWaitState = EXTMEM_ReadWaitState_8;
    EXTMEM_InitStruct->EXTMEM_WriteWaitState = EXTMEM_WriteWaitState_1;
    EXTMEM_InitStruct->CEMask = 0;
}

/**
  * @brief  Устанавливает все регистры контроллера внешней памяти значениями по умолчанию.
  * @retval Нет
  */

void EXTMEM_DeInit()
{
    NT_COMMON_REG->EXT_MEM_CFG = EXT_MEM_CFG_Reset_Value;
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
