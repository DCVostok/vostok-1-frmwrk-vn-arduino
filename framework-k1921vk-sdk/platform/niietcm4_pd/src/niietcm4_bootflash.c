/**
  ******************************************************************************
  * @file    niietcm4_bootflash.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с загрузочной
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
#include "niietcm4_bootflash.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup BOOTFLASH
  * @brief Драйвер для загрузочной флеш-памяти.
  *
  * @attention Для контроллера К1921ВК01Т необходимо вызывать функции записи и
  *   стирания только из другой функции, расположенной в ОЗУ.
  *
  *  Общий вид процесса инициализации:
  *  - обязательно инициализируем контроллер загрузочной памяти @ref BOOTFLASH_Init(),
  *    передав в функцию значение текущей системной частоты;
  *  - включаем прерывание если необходимо - @ref BOOTFLASH_ITCmd;
  *  - контроллер загрузочной флеш-памяти готов к работе.
  *
  * Более подробно инициализация и использование BOOTFLASH показаны в приложенных к драйверу примерах.
  * @{
  */ 

/** @defgroup BOOTFLASH_Private Приватные данные
  * @{
  */

/** @defgroup BOOTFLASH_Private_Defines Приватные константы
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

/** @defgroup BOOTFLASH_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Инициализирует тайминги доступа для контроллера загрузочной флеш.
  * @param  SysClkFreq  Текущая системная частота в Гц.
  * @retval Нет
  */

void BOOTFLASH_Init(uint32_t SysClkFreq)
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

    NT_BOOTFLASH->T_ACC     = Tacc;
    NT_BOOTFLASH->T_PROG    = (uint32_t)(SysClkFreq * 0.00003F);
    NT_BOOTFLASH->T_ERASE   = (uint32_t)(SysClkFreq * 0.03F);
    NT_BOOTFLASH->T_ME      = (uint32_t)(SysClkFreq * 0.03F);
}

/**
  * @brief  Полная очистка основной области загрузочной флеш.
  * @retval Status Статус работы.
  *   Параметр передает BOOTFLASH_Status_Complete или BOOTFLASH_Status_Error из @ref BOOTFLASH_Status_TypeDef.
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_FullErase()
{
    BOOTFLASH_Status_TypeDef Status;

    Status = BOOTFLASH_Status_None;

    NT_BOOTFLASH->FCIC = BOOTFLASH_FCIC_CLR_OPCMLT_Msk | BOOTFLASH_FCIC_CLR_OPERROR_Msk;
    NT_BOOTFLASH->FMC = BOOTFLASH_MAGIC_KEY | BOOTFLASH_FMC_FULL_ERASE_Msk;

    while (Status == BOOTFLASH_Status_None)
    {
        Status = (BOOTFLASH_Status_TypeDef)(NT_BOOTFLASH->FCIS & (BOOTFLASH_FCIS_OP_CMLT_Msk | BOOTFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Запись 128 бит информации в основную область загрузочной флеш,
  *   начиная с указанного адреса.
  * @param  Address  Стартовый адрес.
  * @param  Data0  Нулевое (младшее) 32-битное слово данных.
  * @param  Data1  Первое 32-битное слово данных.
  * @param  Data2  Второе 32-битное слово данных.
  * @param  Data3  Третье (старшее) 32-битное слово данных.
  * @retval Status Статус работы.
  *   Параметр передает BOOTFLASH_Status_Complete или BOOTFLASH_Status_Error из @ref BOOTFLASH_Status_TypeDef.
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Write(uint32_t Address, uint32_t Data0, uint32_t Data1, uint32_t Data2, uint32_t Data3)
{
    BOOTFLASH_Status_TypeDef Status;

    Status = BOOTFLASH_Status_None;

    NT_BOOTFLASH->FCIC = BOOTFLASH_FCIC_CLR_OPCMLT_Msk | BOOTFLASH_FCIC_CLR_OPERROR_Msk;
    NT_BOOTFLASH->FMA = Address;
    NT_BOOTFLASH->FMD0 = Data0;
    NT_BOOTFLASH->FMD1 = Data1;
    NT_BOOTFLASH->FMD2 = Data2;
    NT_BOOTFLASH->FMD3 = Data3;
    NT_BOOTFLASH->FMC = BOOTFLASH_MAGIC_KEY | BOOTFLASH_FMC_WRITE_Msk;

    while (Status == BOOTFLASH_Status_None)
    {
        Status = (BOOTFLASH_Status_TypeDef)(NT_BOOTFLASH->FCIS & (BOOTFLASH_FCIS_OP_CMLT_Msk | BOOTFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Стирание указнной страницы основной области загрузочной флеш.
  * @param  PageNum  Номер страницы.
  * @retval Status Статус работы.
  *   Параметр передает BOOTFLASH_Status_Complete или BOOTFLASH_Status_Error из @ref BOOTFLASH_Status_TypeDef.
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_PageErase(uint32_t PageNum)
{
    assert_param(IS_BOOTFLASH_PAGE_NUM(PageNum));

    BOOTFLASH_Status_TypeDef Status;

    Status = BOOTFLASH_Status_None;

    NT_BOOTFLASH->FCIC = BOOTFLASH_FCIC_CLR_OPCMLT_Msk | BOOTFLASH_FCIC_CLR_OPERROR_Msk;
    NT_BOOTFLASH->FMA = PageNum * BOOTFLASH_PAGE_SIZE_BYTES;
    NT_BOOTFLASH->FMC = BOOTFLASH_MAGIC_KEY | BOOTFLASH_FMC_PAGE_ERASE_Msk;

    while (Status == BOOTFLASH_Status_None)
    {
        Status = (BOOTFLASH_Status_TypeDef)(NT_BOOTFLASH->FCIS & (BOOTFLASH_FCIS_OP_CMLT_Msk | BOOTFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Запись 128 бит информации в информационную область загрузочной флеш,
  *   начиная с указанного адреса.
  * @param  Address  Стартовый адрес.
  * @param  Data0  Нулевое (младшее) 32-битное слово данных.
  * @param  Data1  Первое 32-битное слово данных.
  * @param  Data2  Второе 32-битное слово данных.
  * @param  Data3  Третье (старшее) 32-битное слово данных.
  * @retval Status Статус работы.
  *   Параметр передает BOOTFLASH_Status_Complete или BOOTFLASH_Status_Error из @ref BOOTFLASH_Status_TypeDef.
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Info_Write(uint32_t Address, uint32_t Data0, uint32_t Data1, uint32_t Data2, uint32_t Data3)
{
    BOOTFLASH_Status_TypeDef Status;

    Status = BOOTFLASH_Status_None;

    NT_BOOTFLASH->FCIC = BOOTFLASH_FCIC_CLR_OPCMLT_Msk | BOOTFLASH_FCIC_CLR_OPERROR_Msk;
    NT_BOOTFLASH->FMA = Address;
    NT_BOOTFLASH->FMD0 = Data0;
    NT_BOOTFLASH->FMD1 = Data1;
    NT_BOOTFLASH->FMD2 = Data2;
    NT_BOOTFLASH->FMD3 = Data3;
    NT_BOOTFLASH->FMC = BOOTFLASH_MAGIC_KEY | BOOTFLASH_FMC_WRITE_IFB_Msk;

    while (Status == BOOTFLASH_Status_None)
    {
        Status = (BOOTFLASH_Status_TypeDef)(NT_BOOTFLASH->FCIS & (BOOTFLASH_FCIS_OP_CMLT_Msk | BOOTFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Стирание указнной страницы информационной области загрузочной флеш.
  * @param  PageNum  Номер страницы.
  * @retval Status Статус работы.
  *   Параметр передает BOOTFLASH_Status_Complete или BOOTFLASH_Status_Error из @ref BOOTFLASH_Status_TypeDef.
  */

__RAMFUNC BOOTFLASH_Status_TypeDef BOOTFLASH_Info_PageErase(uint32_t PageNum)
{
    assert_param(IS_BOOTFLASH_INFO_PAGE_NUM(PageNum));

    BOOTFLASH_Status_TypeDef Status;

    Status = BOOTFLASH_Status_None;

    NT_BOOTFLASH->FCIC = BOOTFLASH_FCIC_CLR_OPCMLT_Msk | BOOTFLASH_FCIC_CLR_OPERROR_Msk;
    NT_BOOTFLASH->FMA = PageNum * BOOTFLASH_PAGE_SIZE_BYTES;
    NT_BOOTFLASH->FMC = BOOTFLASH_MAGIC_KEY | BOOTFLASH_FMC_PAGEERASE_IFB_Msk;

    while (Status == BOOTFLASH_Status_None)
    {
        Status = (BOOTFLASH_Status_TypeDef)(NT_BOOTFLASH->FCIS & (BOOTFLASH_FCIS_OP_CMLT_Msk | BOOTFLASH_FCIS_OP_ERROR_Msk));
    }

    return Status;
}

/**
  * @brief  Включение прерывания по завершению чтении/записи/стирания.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void BOOTFLASH_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_BOOTFLASH->FCIM_bit.MASK_OPCMLT = (uint32_t)State;
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
