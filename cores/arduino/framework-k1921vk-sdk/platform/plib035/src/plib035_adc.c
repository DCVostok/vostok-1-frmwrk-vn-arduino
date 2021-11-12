/**
  ******************************************************************************
  * @file    plib035_adc.c
  *
  * @brief   Файл содержит реализацию функций для работы с ADC
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
#include "plib035_adc.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Private Приватные данные
  * @{
  */

/** @defgroup ADC_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры ADC значениями по умолчанию
  * @retval  void
  */
void ADC_DeInit(void)
{
    RCU_ADCRstCmd(DISABLE);
    RCU_ADCRstCmd(ENABLE);
}

/**
  * @brief   Инициализирует секвенсоры АЦП согласно параметрам структуры InitStruct
  * @param   SEQ_Num  Выбор секвенсора
  * @param   InitStruct  Указатель на структуру типа @ref ADC_SEQ_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void ADC_SEQ_Init(ADC_SEQ_Num_TypeDef SEQ_Num, ADC_SEQ_Init_TypeDef* InitStruct)
{
    ADC_SEQ_StartEventConfig(SEQ_Num, InitStruct->StartEvent);
    ADC_SEQ_SwStartEnCmd(SEQ_Num, InitStruct->SWStartEn);
    for (uint32_t i = 0; i < ADC_SEQ_Req_Total; i++) {
        ADC_SEQ_ReqConfig(SEQ_Num, (ADC_SEQ_ReqNum_TypeDef)i, InitStruct->Req[i]);
    }
    ADC_SEQ_ReqMaxConfig(SEQ_Num, InitStruct->ReqMax);
    ADC_SEQ_ReqAverageConfig(SEQ_Num, InitStruct->ReqAverage);
    ADC_SEQ_ReqAverageCmd(SEQ_Num, InitStruct->ReqAverageEn);
    ADC_SEQ_RestartConfig(SEQ_Num, InitStruct->RestartCount);
    ADC_SEQ_RestartAverageCmd(SEQ_Num, InitStruct->RestartAverageEn);
    ADC_SEQ_SetRestartTimer(SEQ_Num, InitStruct->RestartTimer);
    for (uint32_t i = 0; i < ADC_DC_Total; i++) {
        ADC_SEQ_DCEnableCmd(SEQ_Num, (ADC_DC_Num_TypeDef)i, InitStruct->DCEn[i]);
    }
    ADC_SEQ_DMAConfig(SEQ_Num, InitStruct->DMAFIFOLevel);
    ADC_SEQ_DMACmd(SEQ_Num, InitStruct->DMAEn);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref ADC_SEQ_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void ADC_SEQ_StructInit(ADC_SEQ_Init_TypeDef* InitStruct)
{
    InitStruct->StartEvent = ADC_SEQ_StartEvent_SwReq;
    InitStruct->SWStartEn = DISABLE;
    for (uint32_t i = 0; i < ADC_SEQ_Req_Total; i++) {
        InitStruct->Req[i] = ADC_CH_Num_0;
    }
    InitStruct->ReqMax = ADC_SEQ_ReqNum_0;
    InitStruct->ReqAverage = ADC_SEQ_Average_2;
    InitStruct->ReqAverageEn = DISABLE;
    InitStruct->RestartCount = 0;
    InitStruct->RestartAverageEn = DISABLE;
    InitStruct->RestartTimer = 0;
    for (uint32_t i = 0; i < ADC_DC_Total; i++) {
        InitStruct->DCEn[i] = DISABLE;
    }
    InitStruct->DMAFIFOLevel = ADC_SEQ_DMAFIFOLevel_1;
    InitStruct->DMAEn = DISABLE;
}

/**
  * @brief   Инициализирует цифровые компараторы АЦП согласно параметрам структуры InitStruct
  * @param   DC_Num  Выбор компаратора
  * @param   InitStruct  Указатель на структуру типа @ref ADC_DC_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void ADC_DC_Init(ADC_DC_Num_TypeDef DC_Num, ADC_DC_Init_TypeDef* InitStruct)
{
    ADC_DC_OutputCmd(DC_Num, InitStruct->DCOutput);
    ADC_DC_SetThresholdLow(DC_Num, InitStruct->ThresholdLow);
    ADC_DC_SetThresholdHigh(DC_Num, InitStruct->ThresholdHigh);
    ADC_DC_SourceConfig(DC_Num, InitStruct->Source);
    ADC_DC_ChannelConfig(DC_Num, InitStruct->Channel);
    ADC_DC_Config(DC_Num, InitStruct->Mode, InitStruct->Condition);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref ADC_DC_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void ADC_DC_StructInit(ADC_DC_Init_TypeDef* InitStruct)
{
    InitStruct->DCOutput = DISABLE;
    InitStruct->ThresholdLow = 0;
    InitStruct->ThresholdHigh = 0;
    InitStruct->Source = ADC_DC_Source_EOC;
    InitStruct->Channel = ADC_CH_Num_0;
    InitStruct->Mode = ADC_DC_Mode_Multiple;
    InitStruct->Condition = ADC_DC_Condition_Low;
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
