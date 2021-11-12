/**
  ******************************************************************************
  * @file    plib028_bflash.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          BFLASH, а также сопутствующие макроопределения и перечисления
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB028_BFLASH_H
#define __PLIB028_BFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup BFLASH
  * @brief Драйвер для работы с BFLASH
  * @{
  */

/** @defgroup BFLASH_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup BFLASH_Exported_Types Типы
  * @{
  */

/**
  * @brief  Команды контроллера флеш-памяти
  */
typedef enum {
    BFLASH_Cmd_Read = BFLASH_CMD_RD_Msk,                                 /*!< Команда чтения */
    BFLASH_Cmd_Write = BFLASH_CMD_WR_Msk,                                /*!< Команда записи */
    BFLASH_Cmd_EraseFull = BFLASH_CMD_ERSEC_Msk | BFLASH_CMD_ALLSEC_Msk, /*!< Команда стирания всей памяти */
    BFLASH_Cmd_ErasePage = BFLASH_CMD_ERSEC_Msk,                         /*!< Команда стирания страницы */
} BFLASH_Cmd_TypeDef;
#define IS_BFLASH_CMD(VALUE) (((VALUE) == BFLASH_Cmd_Read) ||      \
                              ((VALUE) == BFLASH_Cmd_Write) ||     \
                              ((VALUE) == BFLASH_Cmd_EraseFull) || \
                              ((VALUE) == BFLASH_Cmd_ErasePage))

/**
  * @brief  Выбор региона флеш-памяти для исполнения команд
  */
typedef enum {
    BFLASH_Region_Main = 0UL,                 /*!< Основная область */
    BFLASH_Region_NVR = BFLASH_CMD_NVRON_Msk, /*!< NVR область (загрузочная) */
} BFLASH_Region_TypeDef;
#define IS_BFLASH_REGION(VALUE) (((VALUE) == BFLASH_Region_Main) || \
                                 ((VALUE) == BFLASH_Region_NVR))

#define IS_BFLASH_MAIN_ADDR(MAIN_ADDR) (MAIN_ADDR < MEM_BFLASH_SIZE)
#define IS_BFLASH_MAIN_PAGE_NUM(MAIN_PAGE_NUM) (MAIN_PAGE_NUM < MEM_BFLASH_PAGE_TOTAL)
#define IS_BFLASH_NVR_ADDR(NVR_ADDR) (NVR_ADDR < MEM_BFLASH_NVR_SIZE)
#define IS_BFLASH_NVR_PAGE_NUM(NVR_PAGE_NUM) (NVR_PAGE_NUM < MEM_BFLASH_NVR_PAGE_TOTAL)
#define IS_BFLASH_DATA_NUM(DATA_NUM) (DATA_NUM < MEM_BFLASH_BUS_WIDTH_WORDS)
#define IS_BFLASH_LATENCY(LATENCY) (LATENCY < 15)

/**
  * @}
  */

/** @defgroup BFLASH_Exported_Functions Функции
  * @{
  */

/** @defgroup BFLASH_Cmd Управление контроллером флеш-памяти
  * @{
  */

/**
  * @brief   Установка значения адреса
  * @param   AddrVal  Значение адреса
  * @retval  void
  */
__STATIC_INLINE void BFLASH_SetAddr(uint32_t AddrVal)
{
    WRITE_REG(BFLASH->ADDR, AddrVal);
}

/**
  * @brief   Установка выбранного слова данных
  * @param   DataNum  Номер слова данных
  * @param   DataVal  Значение слова данных
  * @retval  void
  */
__STATIC_INLINE void BFLASH_SetData(uint32_t DataNum, uint32_t DataVal)
{
    assert_param(IS_BFLASH_DATA_NUM(DataNum));

    WRITE_REG(BFLASH->DATA[DataNum].DATA, DataVal);
}

/**
  * @brief   Получение выбранного слова данных
  * @param   DataNum  Номер слова данных
  * @retval  Val  Значение слова данных
  */
__STATIC_INLINE uint32_t BFLASH_GetData(uint32_t DataNum)
{
    assert_param(IS_BFLASH_DATA_NUM(DataNum));

    return READ_REG(BFLASH->DATA[DataNum].DATA);
}

/**
  * @brief   Передача команды контроллеру флеш-памяти
  * @param   Cmd  Команда
  * @param   Region  Область
  * @retval  void
  */
__STATIC_INLINE void BFLASH_SetCmd(BFLASH_Cmd_TypeDef Cmd, BFLASH_Region_TypeDef Region)
{
    WRITE_REG(BFLASH->CMD, ((uint32_t)BFLASH_CMD_KEY_Access << BFLASH_CMD_KEY_Pos) | (uint32_t)Region | (uint32_t)Cmd);
}

/**
  * @brief   Получение статуса занятости контроллера флеш-памяти
  * @retval  Status
  */
__STATIC_INLINE FlagStatus BFLASH_BusyStatus(void)
{
    return (FlagStatus)READ_BIT(BFLASH->STAT, BFLASH_STAT_BUSY_Msk);
}

void BFLASH_ReadData(uint32_t AddrVal, uint32_t* DataArr, BFLASH_Region_TypeDef Region);
void BFLASH_WriteData(uint32_t AddrVal, uint32_t* DataArr, BFLASH_Region_TypeDef Region);
void BFLASH_ErasePage(uint32_t AddrVal, BFLASH_Region_TypeDef Region);
void BFLASH_EraseFull(BFLASH_Region_TypeDef Region);

/**
  * @}
  */

/** @defgroup BFLASH_ExecCtrl Настройка исполнения программ
  * @{
  */

/**
  * @brief   Настройка количества тактов ожидания чтения из флеш
  * @param   LatencyVal  Значение
  * @retval  void
  */
__STATIC_INLINE void BFLASH_LatencyConfig(uint32_t LatencyVal)
{
    assert_param(IS_BFLASH_LATENCY(LatencyVal));

    WRITE_REG(BFLASH->CTRL_bit.LAT, LatencyVal);
}

/**
  * @}
  */

/** @defgroup BFLASH_IRQ Прерывания
  * @{
  */

/**
  * @brief   Разрешение работы прерывания BFLASH
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void BFLASH_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(BFLASH->CTRL_bit.IRQEN, State);
}

/**
  * @brief   Получение статуса прерывания
  * @retval  Status
  */
__STATIC_INLINE FlagStatus BFLASH_ITStatus(void)
{
    return (FlagStatus)READ_BIT(BFLASH->STAT, BFLASH_STAT_IRQF_Msk);
}

/**
  * @brief   Сброс статуса прерывания
  * @retval  void
  */
__STATIC_INLINE void BFLASH_ITStatusClear(void)
{
    WRITE_REG(BFLASH->STAT, BFLASH_STAT_IRQF_Msk);
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

#endif /* __PLIB028_BFLASH_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
