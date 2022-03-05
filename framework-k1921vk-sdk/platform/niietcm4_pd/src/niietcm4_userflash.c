/**
  ******************************************************************************
  * @file    niietcm4_userflash.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с пользовательской
  *          флеш.
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

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_userflash.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup USERFLASH
  * @brief Драйвер для пользовательской флеш-памяти.
  * @attention Перед использованием какой либо функции этого драйвера, следует
  *   обязательно произвести инициализацию контроллера памяти - @ref USERFLASH_Init().
  * @{
  */ 

/** @defgroup USERFLASH_Private Приватные данные
  * @{
  */

/** @defgroup USERFLASH_Private_Defines Приватные константы
  * @{
  */

/**
  * @brief Количество уровней системной частоты (Таблица 7.3).
  */

#define LEVELS_NUMBER 5

/**
  * @brief Макрос проверки допустимости значения системной частоты.
  */

#define IS_VALID_FREQ(SYS_FREQ) ((SYS_FREQ) <= 100000000)

/**
  * @}
  */

/** @defgroup USERFLASH_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Инициализирует тайминги доступа для контроллера пользовательской флеш.
  * @param  SysClkFreq  Текущая системная частота в Гц.
  * @retval Нет
  */

void USERFLASH_Init(uint32_t SysClkFreq)
{
    assert_param(IS_VALID_FREQ(SysClkFreq));

    /*
     * The cycle checks the levels. With the level up Tacc increases.
     */
    uint32_t Tacc = 1;

    /*
     * Таблица 7.3 – Значения параметра Tacc в зависимости от частоты.
     */
    const uint32_t Levels[LEVELS_NUMBER] = {15000000, 30000000, 48000000, 60000000, 80000000};

    for (uint32_t Index = 0; Index < LEVELS_NUMBER; Index++)
    {
        if (Levels[Index] < SysClkFreq)
        {
            Tacc++;
        }
        else
        {
            break;
        }
    }

    NT_USERFLASH->T_ACC     = Tacc;
    NT_USERFLASH->T_PROG    = (uint32_t)(SysClkFreq * 0.00003F);
    NT_USERFLASH->T_ERASE   = (uint32_t)(SysClkFreq * 0.03F);
    NT_USERFLASH->T_ME      = (uint32_t)(SysClkFreq * 0.03F);
}

/**
  * @brief  Полная очистка основной области пользовательской флеш.
  * @retval Status Статус работы.
  *   Параметр передает USERFLASH_Status_Complete или USERFLASH_Status_Error из @ref USERFLASH_Status_TypeDef.
  */

USERFLASH_Status_TypeDef USERFLASH_FullErase()
{
    USERFLASH_Status_TypeDef Status;

    Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_FULL_ERASE_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Чтение байта из основной области пользовательской флеш.
  * @param  Address  Адрес чтения.
  * @retval Data  Байт данных.
  */

uint32_t USERFLASH_Read(uint32_t Address)
{
    uint32_t timeout = USERFLASH_OPERATION_TIMEOUT;
    USERFLASH_Status_TypeDef Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = Address;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_READ_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));

        if (!timeout--)
        {
          break;
        }
    }

    return NT_USERFLASH->FMD;
}

/**
  * @brief  Запись байта в основную область пользовательской флеш по
  *   указанному адресу.
  * @param  Address  Адрес записи.
  * @param  Data  Байт данных.
  * @retval Status Статус работы.
  *   Параметр передает USERFLASH_Status_Complete или USERFLASH_Status_Error из @ref USERFLASH_Status_TypeDef.
  */

USERFLASH_Status_TypeDef USERFLASH_Write(uint32_t Address, uint32_t Data)
{
    USERFLASH_Status_TypeDef Status;

    Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = Address;
    NT_USERFLASH->FMD = Data;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_WRITE_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Стирание указнной страницы основной области пользовательской флеш.
  * @param  PageNum  Номер страницы.
  * @retval Status Статус работы.
  *   Параметр передает USERFLASH_Status_Complete или USERFLASH_Status_Error из @ref USERFLASH_Status_TypeDef.
  */

USERFLASH_Status_TypeDef USERFLASH_PageErase(uint32_t PageNum)
{
    assert_param(IS_USERFLASH_PAGE_NUM(PageNum));

    USERFLASH_Status_TypeDef Status;

    Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = PageNum * USERFLASH_PAGE_SIZE_BYTES;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_PAGE_ERASE_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Чтение байта из информационной области пользовательской флеш.
  * @param  Address  Адрес чтения.
  * @retval Data  Байт данных.
  */

uint32_t USERFLASH_Info_Read(uint32_t Address)
{
    uint32_t timeout = USERFLASH_OPERATION_TIMEOUT;
    USERFLASH_Status_TypeDef Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = Address;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_READ_IFB_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));

        if (!timeout--)
        {
          break;
        }
    }

    return NT_USERFLASH->FMD;
}

/**
  * @brief  Запись байта в информационную область пользовательской флеш по
  *   указанному адресу.
  * @param  Address  Адрес записи.
  * @param  Data  Байт данных.
  * @retval Status Статус работы.
  *   Параметр передает USERFLASH_Status_Complete или USERFLASH_Status_Error из @ref USERFLASH_Status_TypeDef.
  */

USERFLASH_Status_TypeDef USERFLASH_Info_Write(uint32_t Address, uint32_t Data)
{
    USERFLASH_Status_TypeDef Status;

    Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = Address;
    NT_USERFLASH->FMD = Data;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_WRITE_IFB_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Стирание указнной страницы информационной области пользовательской флеш.
  * @param  PageNum  Номер страницы.
  * @retval Status Статус работы.
  *   Параметр передает USERFLASH_Status_Complete или USERFLASH_Status_Error из @ref USERFLASH_Status_TypeDef.
  */

USERFLASH_Status_TypeDef USERFLASH_Info_PageErase(uint32_t PageNum)
{
    assert_param(IS_USERFLASH_INFO_PAGE_NUM(PageNum));

    USERFLASH_Status_TypeDef Status;

    Status = USERFLASH_Status_None;

    NT_USERFLASH->FCIC = USERFLASH_FCIC_CLR_OPCMLT_Msk | USERFLASH_FCIC_CLR_OPERROR_Msk;
    NT_USERFLASH->FMA = PageNum * USERFLASH_PAGE_SIZE_BYTES;
    NT_USERFLASH->FMC = USERFLASH_MAGIC_KEY | USERFLASH_FMC_PAGEERASE_IFB_Msk;

    while (Status == USERFLASH_Status_None)
    {
        Status = (USERFLASH_Status_TypeDef)(NT_USERFLASH->FCIS & (USERFLASH_FCIS_OP_CMLT_Msk | USERFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Включение прерывания по завершению чтении/записи/стирания.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void USERFLASH_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_USERFLASH->FCIM_bit.MASK_OPCMLT = (uint32_t)State;
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
