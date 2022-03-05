/**
  ******************************************************************************
  * @file    plib035_ecap.c
  *
  * @brief   Файл содержит реализацию функций для работы с ECAP
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
#include "plib035_ecap.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup ECAP
  * @{
  */

/** @defgroup ECAP_Private Приватные данные
  * @{
  */

/** @defgroup ECAP_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup ECAP_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры блока захвата значениями по умолчанию
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @retval  void
  */
void ECAP_DeInit(ECAP_TypeDef* ECAPx)
{
    uint32_t ECAP_rst;

    assert_param(IS_ECAP_PERIPH(ECAPx));

    if (ECAPx == ECAP0)
        ECAP_rst = RCU_APBRst_ECAP0;
    else if (ECAPx == ECAP1)
        ECAP_rst = RCU_APBRst_ECAP1;
    else /* (ECAPx == ECAP2) */
        ECAP_rst = RCU_APBRst_ECAP2;

    RCU_APBRstCmd(ECAP_rst, DISABLE);
    RCU_APBRstCmd(ECAP_rst, ENABLE);
}

/**
  * @brief   Инициализирует ECAPx согласно параметрам структуры InitStruct.
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void ECAP_Init(ECAP_TypeDef* ECAPx, ECAP_Init_TypeDef* InitStruct)
{
    ECAP_HaltConfig(ECAPx, InitStruct->Halt);
    ECAP_SyncOutConfig(ECAPx, InitStruct->SyncOut);
    ECAP_SyncCmd(ECAPx, InitStruct->SyncEn);
    ECAP_ModeConfig(ECAPx, InitStruct->Mode);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void ECAP_StructInit(ECAP_Init_TypeDef* InitStruct)
{
    InitStruct->Halt = ECAP_Halt_Stop;
    InitStruct->Mode = ECAP_Mode_Capture;
    InitStruct->SyncEn = DISABLE;
    InitStruct->SyncOut = ECAP_SyncOut_Bypass;
}

/**
  * @brief   Инициализирует режим ШИМ блока ECAPx согласно параметрам структуры InitStruct.
  * @param   ECAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_PWM_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void ECAP_PWM_Init(ECAP_TypeDef* ECAPx, ECAP_PWM_Init_TypeDef* InitStruct)
{
    ECAP_PWM_SetPeriod(ECAPx, InitStruct->Period);
    ECAP_PWM_SetCompare(ECAPx, InitStruct->Compare);
    ECAP_PWM_PolarityConfig(ECAPx, InitStruct->Polarity);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию.
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_PWM_Init_TypeDef,
  *                      которую необходимо проинициализировать.
  * @retval  void
  */
void ECAP_PWM_StructInit(ECAP_PWM_Init_TypeDef* InitStruct)
{
    InitStruct->Period = 0xFFFFFFFF;
    InitStruct->Compare = 0x00010000;
    InitStruct->Polarity = ECAP_PWM_Polarity_Pos;
}

/**
  * @brief   Инициализирует режим захвата блока ECAPx согласно параметрам структуры InitStruct.
  * @param   ECAPx  Выбор модуля ECAP, где x лежит в диапазоне 0-5
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_Capture_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  void
  */
void ECAP_Capture_Init(ECAP_TypeDef* ECAPx, ECAP_Capture_Init_TypeDef* InitStruct)
{
    ECAP_Capture_ModeConfig(ECAPx, InitStruct->Mode);
    ECAP_Capture_StopConfig(ECAPx, InitStruct->StopVal);
    ECAP_Capture_PrescaleConfig(ECAPx, InitStruct->Prescale);
    ECAP_Capture_PolarityEvt0Config(ECAPx, InitStruct->PolarityEvt0);
    ECAP_Capture_PolarityEvt1Config(ECAPx, InitStruct->PolarityEvt1);
    ECAP_Capture_PolarityEvt2Config(ECAPx, InitStruct->PolarityEvt2);
    ECAP_Capture_PolarityEvt3Config(ECAPx, InitStruct->PolarityEvt3);
    ECAP_Capture_RstEvt0Cmd(ECAPx, InitStruct->RstEvt0);
    ECAP_Capture_RstEvt1Cmd(ECAPx, InitStruct->RstEvt1);
    ECAP_Capture_RstEvt2Cmd(ECAPx, InitStruct->RstEvt2);
    ECAP_Capture_RstEvt3Cmd(ECAPx, InitStruct->RstEvt3);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию.
  * @param   InitStruct  Указатель на структуру типа @ref ECAP_Capture_Init_TypeDef,
  *                      которую необходимо проинициализировать.
  * @retval  void
  */
void ECAP_Capture_StructInit(ECAP_Capture_Init_TypeDef* InitStruct)
{
    InitStruct->Mode = ECAP_Capture_Mode_Single;
    InitStruct->StopVal = 0;
    InitStruct->Prescale = 0;
    InitStruct->PolarityEvt0 = ECAP_Capture_Polarity_PosEdge;
    InitStruct->PolarityEvt1 = ECAP_Capture_Polarity_PosEdge;
    InitStruct->PolarityEvt2 = ECAP_Capture_Polarity_PosEdge;
    InitStruct->PolarityEvt3 = ECAP_Capture_Polarity_PosEdge;
    InitStruct->RstEvt0 = DISABLE;
    InitStruct->RstEvt1 = DISABLE;
    InitStruct->RstEvt2 = DISABLE;
    InitStruct->RstEvt3 = DISABLE;
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
