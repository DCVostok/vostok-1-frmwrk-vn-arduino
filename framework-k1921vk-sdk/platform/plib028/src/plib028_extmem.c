/**
  ******************************************************************************
  * @file    plib028_extmem.c
  *
  * @brief   Файл содержит реализацию функций для работы с внешней памятью
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
#include "plib028_extmem.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup EXTMEM
  * @{
  */

/** @defgroup EXTMEM_Private Приватные данные
  * @{
  */

/** @defgroup EXTMEM_Private_Defines Приватные константы
  * @{
  */

#define EXTMEM_WINCFG_RST_VAL 0x07070701UL /*!< Значение по сбросу регистра WINCFG */

/**
  * @}
  */

/** @defgroup EXTMEM_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры внешней памяти значениями по умолчанию
  * @retval  void
  */
void EXTMEM_DeInit(void)
{
    for (uint32_t i = 0; i < EXTMEM_WINDOW_Total; i++) {
        EXTMEM->WINCFG[i].WINCFG = EXTMEM_WINCFG_RST_VAL;
    }
}

/**
  * @brief   Инициализирует выбранное окно внешней памяти согласно параметрам структуры InitStruct
  * @param   WindowNum  Выбор окна внешней памяти
  * @param   InitStruct  Указатель на структуру типа @ref EXTMEM_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void EXTMEM_Init(EXTMEM_WindowNum_TypeDef WindowNum, EXTMEM_Init_TypeDef* InitStruct)
{
    EXTMEM_ModeConfig(WindowNum, InitStruct->Mode);
    EXTMEM_RDCycleConfig(WindowNum, InitStruct->RDCycle);
    EXTMEM_WRCycleConfig(WindowNum, InitStruct->WRCycle);
    EXTMEM_TACycleConfig(WindowNum, InitStruct->TACycle);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref EXTMEM_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void EXTMEM_StructInit(EXTMEM_Init_TypeDef* InitStruct)
{
    InitStruct->Mode = EXTMEM_Mode_16bit;
    InitStruct->RDCycle = 7;
    InitStruct->WRCycle = 7;
    InitStruct->TACycle = 7;
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
