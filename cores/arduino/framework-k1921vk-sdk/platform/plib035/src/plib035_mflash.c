/**
  ******************************************************************************
  * @file    plib035_mflash.c
  *
  * @brief   Файл содержит реализацию функций для работы с MFLASH
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

/* Includes ------------------------------------------------------------------*/
#include "plib035_mflash.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup MFLASH
  * @{
  */

/** @defgroup MFLASH_Private Приватные данные
  * @{
  */

/** @defgroup MFLASH_Private_Defines Приватные определения
  * @{
  */

#define __NOP5() \
    __NOP();     \
    __NOP();     \
    __NOP();     \
    __NOP();     \
    __NOP()

/**
  * @}
  */

/** @defgroup MFLASH_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Чтение информации из выбранной области флеш, начиная с указанного адреса
  * @param   AddrVal  Стартовый адрес
  * @param   DataArr  Указатель на массив, в который будут переданы 2 32-битных слова данных
  * @param   Region  Выбор области
  * @retval  void
  */
void MFLASH_ReadData(uint32_t AddrVal, uint32_t* DataArr, MFLASH_Region_TypeDef Region)
{
    assert_param(IS_MFLASH_REGION(Region));
    if (Region == MFLASH_Region_Main)
        assert_param(IS_MFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == MFLASH_Region_NVR) */
        assert_param(IS_MFLASH_NVR_ADDR(AddrVal));

    MFLASH_SetAddr(AddrVal);
    MFLASH_SetCmd(MFLASH_Cmd_Read, Region);
    __NOP5();
    while (MFLASH_BusyStatus()) {
    };
    for (uint32_t i = 0; i < MEM_MFLASH_BUS_WIDTH_WORDS; i++) {
        DataArr[i] = MFLASH_GetData(i);
    }
}

/**
  * @brief   Запись информации в выбранную область флеш, начиная с указанного адреса
  * @param   AddrVal  Стартовый адрес
  * @param   DataArr  Указатель на массив, из которого будут взяты 2 32-битных слова данных
  * @param   Region  Выбор области
  * @retval  void
  */
void MFLASH_WriteData(uint32_t AddrVal, uint32_t* DataArr, MFLASH_Region_TypeDef Region)
{
    assert_param(IS_MFLASH_REGION(Region));
    if (Region == MFLASH_Region_Main)
        assert_param(IS_MFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == MFLASH_Region_NVR) */
        assert_param(IS_MFLASH_NVR_ADDR(AddrVal));

    MFLASH_SetAddr(AddrVal);
    for (uint32_t i = 0; i < MEM_MFLASH_BUS_WIDTH_WORDS; i++) {
        MFLASH_SetData(i, DataArr[i]);
    }
    MFLASH_SetCmd(MFLASH_Cmd_Write, Region);
    __NOP5();
    while (MFLASH_BusyStatus()) {
    };
}

/**
  * @brief   Стирание выбранной страницы флеш
  * @param   AddrVal  Начальный адрес страницы
  * @param   Region  Выбор области
  * @retval  void
  */
void MFLASH_ErasePage(uint32_t AddrVal, MFLASH_Region_TypeDef Region)
{
    assert_param(IS_MFLASH_REGION(Region));
    if (Region == MFLASH_Region_Main)
        assert_param(IS_MFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == MFLASH_Region_NVR) */
        assert_param(IS_MFLASH_NVR_ADDR(AddrVal));

    MFLASH_SetAddr(AddrVal);
    MFLASH_SetCmd(MFLASH_Cmd_ErasePage, Region);
    __NOP5();
    while (MFLASH_BusyStatus()) {
    };
}

/**
  * @brief   Стирание области флеш полностью
  * @param   Region  Выбор области
  * @retval  void
  */
void MFLASH_EraseFull(MFLASH_Region_TypeDef Region)
{
    assert_param(IS_MFLASH_REGION(Region));

    MFLASH_SetCmd(MFLASH_Cmd_EraseFull, Region);
    __NOP5();
    while (MFLASH_BusyStatus()) {
    };
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

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
