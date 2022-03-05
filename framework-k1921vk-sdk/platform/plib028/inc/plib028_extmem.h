/**
  ******************************************************************************
  * @file    plib028_extmem.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          внешней памяти, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_EXTMEM_H
#define __PLIB028_EXTMEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup EXTMEM
  * @brief Драйвер для работы с EXTMEM
  * @{
  */

/** @defgroup EXTMEM_Exported_Defines Константы
  * @{
  */

#define EXTMEM_WINDOW_Total 8UL

/**
  * @}
  */

/** @defgroup EXTMEM_Exported_Types Типы
  * @{
  */

/**
  * @brief  Режим разрядности контроллера внешней памяти
  */
typedef enum {
    EXTMEM_Mode_8bit = EXTMEM_WINCFG_WINCFG_MODE_8bit,  /*!< 8-разрядный режим работы */
    EXTMEM_Mode_16bit = EXTMEM_WINCFG_WINCFG_MODE_16bit /*!< 16-разрядный режим работы */
} EXTMEM_Mode_TypeDef;
#define IS_EXTMEM_MODE(VALUE) (((VALUE) == EXTMEM_Mode_8bit) || \
                               ((VALUE) == EXTMEM_Mode_16bit))

/**
  * @brief  Номер окна внешней памяти
  */
typedef enum {
    EXTMEM_WindowNum_0, /*!< Окно 0 */
    EXTMEM_WindowNum_1, /*!< Окно 1 */
    EXTMEM_WindowNum_2, /*!< Окно 2 */
    EXTMEM_WindowNum_3, /*!< Окно 3 */
    EXTMEM_WindowNum_4, /*!< Окно 4 */
    EXTMEM_WindowNum_5, /*!< Окно 5 */
    EXTMEM_WindowNum_6, /*!< Окно 6 */
    EXTMEM_WindowNum_7, /*!< Окно 7 */
} EXTMEM_WindowNum_TypeDef;
#define IS_EXTMEM_WINDOW_NUM(VALUE) (((VALUE) == EXTMEM_WindowNum_0) || \
                                     ((VALUE) == EXTMEM_WindowNum_1) || \
                                     ((VALUE) == EXTMEM_WindowNum_2) || \
                                     ((VALUE) == EXTMEM_WindowNum_3) || \
                                     ((VALUE) == EXTMEM_WindowNum_4) || \
                                     ((VALUE) == EXTMEM_WindowNum_5) || \
                                     ((VALUE) == EXTMEM_WindowNum_6) || \
                                     ((VALUE) == EXTMEM_WindowNum_7))

#define IS_EXTMEM_CYCLE(VALUE) ((VALUE) < 0x10)

/**
  * @brief  Структура инициализации внешней памяти
  */
typedef struct
{
    EXTMEM_Mode_TypeDef Mode; /*!< Режим разрядности контроллера внешней памяти.
                                   Параметр может принимать любое значение из @ref EXTMEM_Mode_TypeDef. */
    uint32_t TACycle;         /*!< Длительность цикла переключения шины в системных тактах.
                                   Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов). */
    uint32_t WRCycle;         /*!< Длительность цикла записи слова данных в системных тактах.
                                   Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов). */
    uint32_t RDCycle;         /*!< Длительность цикла чтения слова данных в системных тактах.
                                   Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов). */
} EXTMEM_Init_TypeDef;

/**
  * @}
  */

/** @defgroup EXTMEM_Exported_Functions Функции
  * @{
  */

void EXTMEM_DeInit(void);
void EXTMEM_Init(EXTMEM_WindowNum_TypeDef WindowNum, EXTMEM_Init_TypeDef* EXTMEM_InitStruct);
void EXTMEM_StructInit(EXTMEM_Init_TypeDef* EXTMEM_InitStruct);

/**
  * @brief   Выбор режима разрядности выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Width  Разрядность
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_ModeConfig(EXTMEM_WindowNum_TypeDef WindowNum, EXTMEM_Mode_TypeDef Mode)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));
    assert_param(IS_EXTMEM_MODE(Mode));

    WRITE_REG(EXTMEM->WINCFG[(uint32_t)WindowNum].WINCFG_bit.MODE, Mode);
}

/**
  * @brief   Настройка длительностм цикла записи слова данных в системных тактах
  * @param   WindowNum  Выбор окна
  * @param   Val  Длительность цикла
  *               Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов).
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_WRCycleConfig(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Val)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));
    assert_param(IS_EXTMEM_CYCLE(Val));

    WRITE_REG(EXTMEM->WINCFG[(uint32_t)WindowNum].WINCFG_bit.WRCYC, Val);
}

/**
  * @brief   Настройка длительностм цикла чтения слова данных в системных тактах
  * @param   WindowNum  Выбор окна
  * @param   Val  Длительность цикла
  *               Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов).
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_RDCycleConfig(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Val)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));
    assert_param(IS_EXTMEM_CYCLE(Val));

    WRITE_REG(EXTMEM->WINCFG[(uint32_t)WindowNum].WINCFG_bit.RDCYC, Val);
}

/**
  * @brief   Настройка длительностм цикла переключения шины слова данных в системных тактах
  * @param   WindowNum  Выбор окна
  * @param   Val  Длительность цикла
  *               Параметр может принимать любое значение из диапазона 0 (1 такт) - 15 (16 тактов).
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_TACycleConfig(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Val)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));
    assert_param(IS_EXTMEM_CYCLE(Val));

    WRITE_REG(EXTMEM->WINCFG[(uint32_t)WindowNum].WINCFG_bit.TACYC, Val);
}

/**
  * @brief   Чтение 32-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @retval  Data  Данные
  */
__STATIC_INLINE uint32_t EXTMEM_Read32(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    return *(volatile uint32_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr);
}

/**
  * @brief   Чтение 16-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @retval  Data  Данные
  */
__STATIC_INLINE uint16_t EXTMEM_Read16(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    return *(volatile uint16_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr);
}

/**
  * @brief   Чтение 8-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @retval  Data  Данные
  */
__STATIC_INLINE uint8_t EXTMEM_Read8(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    return *(volatile uint8_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr);
}

/**
  * @brief   Запись 32-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @param   Data  Данные
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_Write32(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr, uint32_t Data)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    *(volatile uint32_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr) = Data;
}

/**
  * @brief   Запись 16-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @param   Data  Данные
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_Write16(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr, uint16_t Data)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    *(volatile uint16_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr) = Data;
}

/**
  * @brief   Запись 8-битного значения по адресу внутри выбранного окна
  * @param   WindowNum  Выбор окна
  * @param   Addr  Адрес
  * @param   Data  Данные
  * @retval  void
  */
__STATIC_INLINE void EXTMEM_Write8(EXTMEM_WindowNum_TypeDef WindowNum, uint32_t Addr, uint8_t Data)
{
    assert_param(IS_EXTMEM_WINDOW_NUM(WindowNum));

    *(volatile uint8_t*)(MEM_EXT0_BASE + WindowNum * MEM_EXT_SIZE + Addr) = Data;
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_EXTMEM_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
