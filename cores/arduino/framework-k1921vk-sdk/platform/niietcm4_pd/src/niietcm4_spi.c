/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

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
void SPI_DeInit(NT_SPI_TypeDef* SPIx)
{
    assert_param(IS_SPI_PERIPH(SPIx));

    if (SPIx == NT_SPI0) {
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI0, DISABLE);
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI0, ENABLE);
    } else if (SPIx == NT_SPI1) {
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI1, DISABLE);
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI1, ENABLE);
    } else if (SPIx == NT_SPI2) {
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI2, DISABLE);
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI2, ENABLE);
    } else /*if (SPIx == SPI3)*/ {
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI3, DISABLE);
        RCC_PeriphRstCmd(RCC_PeriphRst_SPI3, ENABLE);
    }

    
}

/**
  * @brief   Инициализирует SPI согласно параметрам структуры InitStruct.
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref SPI_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void SPI_Init(NT_SPI_TypeDef* SPIx, SPI_Init_TypeDef* InitStruct)
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
