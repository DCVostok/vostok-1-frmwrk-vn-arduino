/**
  ******************************************************************************
  * @file    plib028_sdfm.c
  *
  * @brief   Файл содержит реализацию функций для работы с SDFM
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
#include "plib028_sdfm.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup SDFM
  * @{
  */

/** @defgroup SDFM_Private Приватные данные
  * @{
  */

/** @defgroup SDFM_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup SDFM_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры SDFM значениями по умолчанию
  * @retval  void
  */
void SDFM_DeInit()
{
    RCU_AHBRstCmd(RCU_AHBRst_SDFM, DISABLE);
    RCU_AHBRstCmd(RCU_AHBRst_SDFM, ENABLE);
}

/**
  * @brief   Инициализирует фильтр данных согласно параметрам структуры InitStruct
  * @param   ChannelNum  Выбор канала демодулятора
  * @param   InitStruct  Указатель на структуру типа @ref SDFM_DF_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void SDFM_DF_Init(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_DF_Init_TypeDef* InitStruct)
{
    SDFM_DF_OSRConfig(ChannelNum, InitStruct->OSR);
    SDFM_DF_ShiftConfig(ChannelNum, InitStruct->Shift);
    SDFM_DF_ModeConfig(ChannelNum, InitStruct->Mode);
    SDFM_DF_SyncConfig(ChannelNum, InitStruct->SyncSource);
    SDFM_DF_SyncCmd(ChannelNum, InitStruct->SyncEn);
    SDFM_DF_WaitSyncCmd(ChannelNum, InitStruct->WaitSyncEn);
    SDFM_DF_WaitSyncHWClearCmd(ChannelNum, InitStruct->WaitSyncHWClearEn);
    SDFM_DF_FIFOCmd(ChannelNum, InitStruct->FIFOEn);
    SDFM_DF_FIFOHWClearCmd(ChannelNum, InitStruct->FIFOHWClearEn);
    SDFM_DF_DMAConfig(ChannelNum, InitStruct->DMAFIFOLevel);
    SDFM_DF_DMACmd(ChannelNum, InitStruct->DMAEn);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref SDFM_DF_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void SDFM_DF_StructInit(SDFM_DF_Init_TypeDef* InitStruct)
{
    InitStruct->OSR = 0;
    InitStruct->Shift = 0;
    InitStruct->Mode = SDFM_Mode_Sinc1;
    InitStruct->SyncSource = SDFM_DF_SyncSource_PWM012A;
    InitStruct->SyncEn = DISABLE;
    InitStruct->WaitSyncEn = DISABLE;
    InitStruct->WaitSyncHWClearEn = DISABLE;
    InitStruct->FIFOEn = DISABLE;
    InitStruct->FIFOHWClearEn = DISABLE;
    InitStruct->DMAFIFOLevel = 0;
    InitStruct->DMAEn = DISABLE;
}

/**
  * @brief   Инициализирует компаратор согласно параметрам структуры InitStruct
  * @param   ChannelNum  Выбор канала демодулятора
  * @param   InitStruct  Указатель на структуру типа @ref SDFM_CMP_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void SDFM_CMP_Init(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_CMP_Init_TypeDef* InitStruct)
{
    SDFM_CMP_OSRConfig(ChannelNum, InitStruct->OSR);
    SDFM_CMP_ModeConfig(ChannelNum, InitStruct->Mode);
    SDFM_CMP_SetThresholdLow(ChannelNum, InitStruct->ThresholdLow);
    SDFM_CMP_SetThresholdHigh(ChannelNum, InitStruct->ThresholdHigh);
    SDFM_CMP_SetThresholdHighZ(ChannelNum, InitStruct->ThresholdHighZ);
    SDFM_CMP_HighEventHWClearCmd(ChannelNum, InitStruct->HighEventHWClearEn);
    SDFM_CMP_HighZEventHWClearCmd(ChannelNum, InitStruct->HighZEventHWClearEn);
    SDFM_CMP_LowEventHWClearCmd(ChannelNum, InitStruct->LowEventHWClearEn);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref SDFM_CMP_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void SDFM_CMP_StructInit(SDFM_CMP_Init_TypeDef* InitStruct)
{
    InitStruct->OSR = 0;
    InitStruct->Mode = SDFM_Mode_Sinc1;
    InitStruct->ThresholdLow = 0;
    InitStruct->ThresholdHigh = 0;
    InitStruct->ThresholdHighZ = 0;
    InitStruct->HighEventHWClearEn = DISABLE;
    InitStruct->HighZEventHWClearEn = DISABLE;
    InitStruct->LowEventHWClearEn = DISABLE;
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
