/**
  ******************************************************************************
  * @file    plib028_bflash.c
  *
  * @brief   Файл содержит реализацию функций для работы с BFLASH
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

/* Includes ------------------------------------------------------------------*/
#include "plib028_bflash.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup BFLASH
  * @{
  */

/** @defgroup BFLASH_Private Приватные данные
  * @{
  */

/** @defgroup BFLASH_Private_Defines Приватные определения
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

/** @defgroup BFLASH_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Чтение информации из выбранной области флеш, начиная с указанного адреса
  * @param   AddrVal  Стартовый адрес
  * @param   DataArr  Указатель на массив, в который будут переданы 4 32-битных слова данных
  * @param   Region  Выбор области
  * @retval  void
  */
void BFLASH_ReadData(uint32_t AddrVal, uint32_t* DataArr, BFLASH_Region_TypeDef Region)
{
    assert_param(IS_BFLASH_REGION(Region));
    if (Region == BFLASH_Region_Main)
        assert_param(IS_BFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == BFLASH_Region_NVR) */
        assert_param(IS_BFLASH_NVR_ADDR(AddrVal));

    BFLASH_SetAddr(AddrVal);
    BFLASH_SetCmd(BFLASH_Cmd_Read, Region);
    __NOP5();
    while (BFLASH_BusyStatus()) {
    };
    for (uint32_t i = 0; i < MEM_BFLASH_BUS_WIDTH_WORDS; i++) {
        DataArr[i] = BFLASH_GetData(i);
    }
}

/**
  * @brief   Запись информации в выбранную область флеш, начиная с указанного адреса
  * @param   AddrVal  Стартовый адрес
  * @param   DataArr  Указатель на массив, из которого будут взяты 4 32-битных слова данных
  * @param   Region  Выбор области
  * @retval  void
  */
void BFLASH_WriteData(uint32_t AddrVal, uint32_t* DataArr, BFLASH_Region_TypeDef Region)
{
    assert_param(IS_BFLASH_REGION(Region));
    if (Region == BFLASH_Region_Main)
        assert_param(IS_BFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == BFLASH_Region_NVR) */
        assert_param(IS_BFLASH_NVR_ADDR(AddrVal));

    BFLASH_SetAddr(AddrVal);
    for (uint32_t i = 0; i < MEM_BFLASH_BUS_WIDTH_WORDS; i++) {
        BFLASH_SetData(i, DataArr[i]);
    }
    BFLASH_SetCmd(BFLASH_Cmd_Write, Region);
    __NOP5();
    while (BFLASH_BusyStatus()) {
    };
}

/**
  * @brief   Стирание выбранной страницы флеш
  * @param   AddrVal  Начальный адрес страницы
  * @param   Region  Выбор области
  * @retval  void
  */
void BFLASH_ErasePage(uint32_t AddrVal, BFLASH_Region_TypeDef Region)
{
    assert_param(IS_BFLASH_REGION(Region));
    if (Region == BFLASH_Region_Main)
        assert_param(IS_BFLASH_MAIN_ADDR(AddrVal));
    else /* (Region == BFLASH_Region_NVR) */
        assert_param(IS_BFLASH_NVR_ADDR(AddrVal));

    BFLASH_SetAddr(AddrVal);
    BFLASH_SetCmd(BFLASH_Cmd_ErasePage, Region);
    __NOP5();
    while (BFLASH_BusyStatus()) {
    };
}

/**
  * @brief   Стирание области флеш полностью
  * @attention Полное стирание NVR области влечёт за собой полное стирание основной области!
  *            При этом, операция стирания основной области не вылияет на состояние NVR.
  * @param   Region  Выбор области
  * @retval  void
  */
void BFLASH_EraseFull(BFLASH_Region_TypeDef Region)
{
    assert_param(IS_BFLASH_REGION(Region));

    BFLASH_SetCmd(BFLASH_Cmd_EraseFull, Region);
    __NOP5();
    while (BFLASH_BusyStatus()) {
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

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
