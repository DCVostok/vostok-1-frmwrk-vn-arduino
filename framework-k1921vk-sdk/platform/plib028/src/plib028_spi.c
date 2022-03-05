/**
  ******************************************************************************
  * @file    plib028_spi.c
  *
  * @brief   Файл содержит реализацию функций для работы с SPI
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
#include "plib028_spi.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup SPI
  * @{
  */

/** @defgroup SPI_Private Приватные данные
  * @{
  */

/** @defgroup SPI_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры SPI значениями по умолчанию
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @retval  void
  */
void SPI_DeInit(SPI_TypeDef* SPIx)
{
    SPI_Num_TypeDef SPIx_Num;
    assert_param(IS_SPI_PERIPH(SPIx));

    if (SPIx == SPI0) {
        SPIx_Num = SPI0_Num;
    } else if (SPIx == SPI1) {
        SPIx_Num = SPI1_Num;
    } else if (SPIx == SPI2) {
        SPIx_Num = SPI2_Num;
    } else /*if (SPIx == SPI3)*/ {
        SPIx_Num = SPI3_Num;
    }

    RCU_SPIRstCmd(SPIx_Num, DISABLE);
    RCU_SPIRstCmd(SPIx_Num, ENABLE);
}

/**
  * @brief   Инициализирует SPI согласно параметрам структуры InitStruct.
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref SPI_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void SPI_Init(SPI_TypeDef* SPIx, SPI_Init_TypeDef* InitStruct)
{
    assert_param(IS_SPI_PERIPH(SPIx));

    SPI_SCKDivConfig(SPIx, InitStruct->SCKDiv, InitStruct->SCKDivExtra);
    SPI_DataWidthConfig(SPIx, InitStruct->DataWidth);
    SPI_FrameFormatConfig(SPIx, InitStruct->FrameFormat);
    SPI_ModeConfig(SPIx, InitStruct->Mode);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию.
  * @param   InitStruct  Указатель на структуру типа @ref SPI_Init_TypeDef,
  *                      которую необходимо проинициализировать.
  * @retval  void
  */
void SPI_StructInit(SPI_Init_TypeDef* InitStruct)
{
    InitStruct->SCKDiv = 0;
    InitStruct->SCKDivExtra = 2;
    InitStruct->DataWidth = SPI_DataWidth_8;
    InitStruct->FrameFormat = SPI_FrameFormat_SPI;
    InitStruct->Mode = SPI_Mode_Master;
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
