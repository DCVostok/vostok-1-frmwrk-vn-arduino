/**
  ******************************************************************************
  * @file    plib035_mflash.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          MFLASH, а также сопутствующие макроопределения и перечисления
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
  * <h2><center>&copy; 2018 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB035_MFLASH_H
#define __PLIB035_MFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup MFLASH
  * @brief Драйвер для работы с MFLASH
  * @{
  */

/** @defgroup MFLASH_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup MFLASH_Exported_Types Типы
  * @{
  */

/**
  * @brief  Команды контроллера флеш-памяти
  */
typedef enum {
    MFLASH_Cmd_Read = MFLASH_CMD_RD_Msk,         /*!< Команда чтения */
    MFLASH_Cmd_Write = MFLASH_CMD_WR_Msk,        /*!< Команда записи */
    MFLASH_Cmd_EraseFull = MFLASH_CMD_ERALL_Msk, /*!< Команда стирания всей памяти */
    MFLASH_Cmd_ErasePage = MFLASH_CMD_ERSEC_Msk, /*!< Команда стирания страницы */
} MFLASH_Cmd_TypeDef;
#define IS_MFLASH_CMD(VALUE) (((VALUE) == MFLASH_Cmd_Read) ||      \
                              ((VALUE) == MFLASH_Cmd_Write) ||     \
                              ((VALUE) == MFLASH_Cmd_EraseFull) || \
                              ((VALUE) == MFLASH_Cmd_ErasePage))

/**
  * @brief  Выбор региона флеш-памяти для исполнения команд
  */
typedef enum {
    MFLASH_Region_Main = 0UL,                 /*!< Основная область */
    MFLASH_Region_NVR = MFLASH_CMD_NVRON_Msk, /*!< NVR область (загрузочная) */
} MFLASH_Region_TypeDef;
#define IS_MFLASH_REGION(VALUE) (((VALUE) == MFLASH_Region_Main) || \
                                 ((VALUE) == MFLASH_Region_NVR))

#define IS_MFLASH_MAIN_ADDR(MAIN_ADDR) (MAIN_ADDR < MEM_MFLASH_SIZE)
#define IS_MFLASH_MAIN_PAGE_NUM(MAIN_PAGE_NUM) (MAIN_PAGE_NUM < MEM_MFLASH_PAGE_TOTAL)
#define IS_MFLASH_NVR_ADDR(NVR_ADDR) (NVR_ADDR < MEM_MFLASH_NVR_SIZE)
#define IS_MFLASH_NVR_PAGE_NUM(NVR_PAGE_NUM) (NVR_PAGE_NUM < MEM_MFLASH_NVR_PAGE_TOTAL)
#define IS_MFLASH_DATA_NUM(DATA_NUM) (DATA_NUM < MEM_MFLASH_BUS_WIDTH_WORDS)
#define IS_MFLASH_LATENCY(LATENCY) (LATENCY < 15)

/**
  * @}
  */

/** @defgroup MFLASH_Exported_Functions Функции
  * @{
  */

/** @defgroup MFLASH_Cmd Управление контроллером флеш-памяти
  * @{
  */

/**
  * @brief   Установка значения адреса
  * @param   AddrVal  Значение адреса
  * @retval  void
  */
__STATIC_INLINE void MFLASH_SetAddr(uint32_t AddrVal)
{
    WRITE_REG(MFLASH->ADDR, AddrVal);
}

/**
  * @brief   Установка выбранного слова данных
  * @param   DataNum  Номер слова данных
  * @param   DataVal  Значение слова данных
  * @retval  void
  */
__STATIC_INLINE void MFLASH_SetData(uint32_t DataNum, uint32_t DataVal)
{
    assert_param(IS_MFLASH_DATA_NUM(DataNum));

    WRITE_REG(MFLASH->DATA[DataNum].DATA, DataVal);
}

/**
  * @brief   Получение выбранного слова данных
  * @param   DataNum  Номер слова данных
  * @retval  Val  Значение слова данных
  */
__STATIC_INLINE uint32_t MFLASH_GetData(uint32_t DataNum)
{
    assert_param(IS_MFLASH_DATA_NUM(DataNum));

    return READ_REG(MFLASH->DATA[DataNum].DATA);
}

/**
  * @brief   Передача команды контроллеру флеш-памяти
  * @param   Cmd  Команда
  * @param   Region  Область
  * @retval  void
  */
__STATIC_INLINE void MFLASH_SetCmd(MFLASH_Cmd_TypeDef Cmd, MFLASH_Region_TypeDef Region)
{
    WRITE_REG(MFLASH->CMD, ((uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos) | (uint32_t)Region | (uint32_t)Cmd);
}

/**
  * @brief   Получение статуса занятости контроллера флеш-памяти
  * @retval  Status
  */
__STATIC_INLINE FlagStatus MFLASH_BusyStatus(void)
{
    return (FlagStatus)READ_BIT(MFLASH->STAT, MFLASH_STAT_BUSY_Msk);
}

void MFLASH_ReadData(uint32_t AddrVal, uint32_t* DataArr, MFLASH_Region_TypeDef Region);
void MFLASH_WriteData(uint32_t AddrVal, uint32_t* DataArr, MFLASH_Region_TypeDef Region);
void MFLASH_ErasePage(uint32_t AddrVal, MFLASH_Region_TypeDef Region);
void MFLASH_EraseFull(MFLASH_Region_TypeDef Region);

/**
  * @}
  */

/** @defgroup MFLASH_ExecCtrl Настройка исполнения программ
  * @{
  */

/**
  * @brief   Настройка количества тактов ожидания чтения из флеш
  * @param   LatencyVal  Значение
  * @retval  void
  */
__STATIC_INLINE void MFLASH_LatencyConfig(uint32_t LatencyVal)
{
    assert_param(IS_MFLASH_LATENCY(LatencyVal));

    WRITE_REG(MFLASH->CTRL_bit.LAT, LatencyVal);
}

/**
  * @brief   Разрешение работы кэша инструкций
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_ICacheCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(MFLASH->CTRL_bit.ICEN, State);
}

/**
  * @brief   Очистка кэша инструкций
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_ICacheFlushCmd(void)
{
    WRITE_REG(MFLASH->CTRL_bit.IFLUSH, 1);
}

/**
  * @brief   Получение статуса занятости очистки кэша инструкций
  * @retval  Status
  */
__STATIC_INLINE FlagStatus MFLASH_ICacheBusyStatus(void)
{
    return (FlagStatus)READ_BIT(MFLASH->ICSTAT, MFLASH_ICSTAT_BUSY_Msk);
}

/**
  * @brief   Разрешение работы кэша данных
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_DCacheCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(MFLASH->CTRL_bit.DCEN, State);
}

/**
  * @brief   Очистка кэша данных
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_DCacheFlushCmd(void)
{
    WRITE_REG(MFLASH->CTRL_bit.DFLUSH, 1);
}

/**
  * @brief   Получение статуса занятости очистки кэша данных
  * @retval  Status
  */
__STATIC_INLINE FlagStatus MFLASH_DCacheBusyStatus(void)
{
    return (FlagStatus)READ_BIT(MFLASH->DCSTAT, MFLASH_DCSTAT_BUSY_Msk);
}

/**
  * @brief   Разрешение работы предвыборки
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_PrefetchCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(MFLASH->CTRL_bit.PEN, State);
}

/**
  * @brief   Отключение старта из загрузчоной памяти после следующего программного сброса.
  *          Оказывает влияние только если в CFGWORD активирован старт из загрузочной области.
  * @retval  void
  */
__STATIC_INLINE void MFLASH_BootDisableCmd(void)
{
    WRITE_REG(MFLASH->BDIS, MFLASH_BDIS_BMDIS_Msk);
}

/**
  * @}
  */

/** @defgroup MFLASH_IRQ Прерывания
  * @{
  */

/**
  * @brief   Разрешение работы прерывания MFLASH
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void MFLASH_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(MFLASH->CTRL_bit.IRQEN, State);
}

/**
  * @brief   Получение статуса прерывания
  * @retval  Status
  */
__STATIC_INLINE FlagStatus MFLASH_ITStatus(void)
{
    return (FlagStatus)READ_BIT(MFLASH->STAT, MFLASH_STAT_IRQF_Msk);
}

/**
  * @brief   Сброс статуса прерывания
  * @retval  void
  */
__STATIC_INLINE void MFLASH_ITStatusClear(void)
{
    WRITE_REG(MFLASH->STAT, MFLASH_STAT_IRQF_Msk);
}

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_MFLASH_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
