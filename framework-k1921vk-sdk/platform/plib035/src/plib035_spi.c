/**
  ******************************************************************************
  * @file    plib035_spi.c
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
  * <h2><center>&copy; 2018 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "plib035_spi.h"

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
  * @retval  void
  */
void SPI_DeInit()
{
    RCU_SPIRstCmd(DISABLE);
    RCU_SPIRstCmd(ENABLE);
}

/**
  * @brief   Инициализирует SPI согласно параметрам структуры InitStruct.
  * @param   InitStruct  Указатель на структуру типа @ref SPI_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void SPI_Init(SPI_Init_TypeDef* InitStruct)
{

    SPI_SCKDivConfig(InitStruct->SCKDiv, InitStruct->SCKDivExtra);
    SPI_DataWidthConfig(InitStruct->DataWidth);
    SPI_FrameFormatConfig(InitStruct->FrameFormat);
    SPI_ModeConfig(InitStruct->Mode);
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

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
