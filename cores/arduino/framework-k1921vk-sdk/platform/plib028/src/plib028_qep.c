/**
  ******************************************************************************
  * @file    plib028_qep.c
  *
  * @brief   Файл содержит реализацию функций для работы с QEP
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
#include "plib028_qep.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup QEP
  * @{
  */

/** @defgroup QEP_Private Приватные данные
  * @{
  */

/** @defgroup QEP_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup QEP_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры QEP значениями по умолчанию
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  void
  */
void QEP_DeInit(QEP_TypeDef* QEPx)
{
    uint32_t APBRst;
    assert_param(IS_QEP_PERIPH(QEPx));

    if (QEPx == QEP0) {
        APBRst = RCU_APBRst1_QEP0;
    } else if (QEPx == QEP1) {
        APBRst = RCU_APBRst1_QEP1;
    } else if (QEPx == QEP2) {
        APBRst = RCU_APBRst1_QEP2;
    } else /*if (QEPx == QEP3)*/ {
        APBRst = RCU_APBRst1_QEP3;
    }

    RCU_APBRst1Cmd(APBRst, DISABLE);
    RCU_APBRst1Cmd(APBRst, ENABLE);
}

/**
  * @brief   Инициализирует счетчик позиции QEP согласно параметрам структуры InitStruct
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref QEP_PC_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void QEP_PC_Init(QEP_TypeDef* QEPx, QEP_PC_Init_TypeDef* InitStruct)
{
    QEP_PC_ModeConfig(QEPx, InitStruct->Mode);
    QEP_PC_CountRateConfig(QEPx, InitStruct->CountRate);
    QEP_PC_ResetEventConfig(QEPx, InitStruct->ResetEvent);
    QEP_PC_InitEventSConfig(QEPx, InitStruct->InitEventS);
    QEP_PC_InitEventIConfig(QEPx, InitStruct->InitEventI);
    QEP_PC_LatchEventSConfig(QEPx, InitStruct->LatchEventS);
    QEP_PC_LatchEventIConfig(QEPx, InitStruct->LatchEventI);
    QEP_PC_SetCount(QEPx, InitStruct->Count);
    QEP_PC_SetCountInit(QEPx, InitStruct->CountInit);
    QEP_PC_SetCountMax(QEPx, InitStruct->CountMax);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref QEP_PC_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void QEP_PC_StructInit(QEP_PC_Init_TypeDef* InitStruct)
{
    InitStruct->Mode = QEP_PC_Mode_Quad;
    InitStruct->CountRate = QEP_PC_CountRate_Single;
    InitStruct->ResetEvent = QEP_PC_ResetEvent_Index;
    InitStruct->InitEventS = QEP_PC_InitEventS_None;
    InitStruct->InitEventI = QEP_PC_InitEventI_None;
    InitStruct->LatchEventS = QEP_PC_LatchEventS_Rise;
    InitStruct->LatchEventI = QEP_PC_LatchEventI_None;
    InitStruct->Count = 0;
    InitStruct->CountInit = 0;
    InitStruct->CountMax = 0;
}

/**
  * @brief   Инициализирует компаратор счетчика позиции QEP согласно параметрам структуры InitStruct
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref QEP_CMP_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void QEP_CMP_Init(QEP_TypeDef* QEPx, QEP_CMP_Init_TypeDef* InitStruct)
{
    QEP_CMP_ShadowLoadCmd(QEPx, InitStruct->ShadowLoad);
    QEP_CMP_LoadEventConfig(QEPx, InitStruct->LoadEvent);
    QEP_CMP_OutConfig(QEPx, InitStruct->Out);
    QEP_CMP_OutCmd(QEPx, InitStruct->OutEn);
    QEP_CMP_OutPolarityConfig(QEPx, InitStruct->OutPolarity);
    QEP_CMP_SetOutWidth(QEPx, InitStruct->OutWidth);
    QEP_CMP_SetComp(QEPx, InitStruct->Comp);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref QEP_CMP_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void QEP_CMP_StructInit(QEP_CMP_Init_TypeDef* InitStruct)
{
    InitStruct->ShadowLoad = DISABLE;
    InitStruct->LoadEvent = QEP_CMP_LoadEvent_PCCountEqZero;
    InitStruct->Out = QEP_CMP_Out_S;
    InitStruct->OutEn = DISABLE;
    InitStruct->OutPolarity = QEP_CMP_OutPolarity_ActiveHigh;
    InitStruct->OutWidth = 0;
    InitStruct->Comp = 0;
}

/**
  * @brief   Инициализирует модуль захвата времени QEP согласно параметрам структуры InitStruct
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref QEP_CAP_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void QEP_CAP_Init(QEP_TypeDef* QEPx, QEP_CAP_Init_TypeDef* InitStruct)
{
    QEP_CAP_DivShadowLoadCmd(QEPx, InitStruct->DivShadowLoad);
    QEP_CAP_ResetEventConfig(QEPx, InitStruct->ResetEvent);
    QEP_CAP_DivConfig(QEPx, InitStruct->PCLKDiv, InitStruct->QCLKDiv);
    QEP_CAP_LatchEventConfig(QEPx, InitStruct->LatchEvent);
    QEP_CAP_SetCount(QEPx, InitStruct->Count);
    QEP_CAP_SetPeriod(QEPx, InitStruct->Period);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref QEP_CAP_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void QEP_CAP_StructInit(QEP_CAP_Init_TypeDef* InitStruct)
{
    InitStruct->DivShadowLoad = DISABLE;
    InitStruct->ResetEvent = QEP_CAP_ResetEvent_QCLKDiv;
    InitStruct->PCLKDiv = QEP_CAP_PCLKDiv_1;
    InitStruct->QCLKDiv = QEP_CAP_QCLKDiv_1;
    InitStruct->LatchEvent = QEP_CAP_LatchEvent_ReadPCCount;
    InitStruct->Count = 0;
    InitStruct->Period = 0;
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
