/**
  ******************************************************************************
  * @file    plib035_pwm.c
  *
  * @brief   Файл содержит реализацию функций для работы с PWM
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
#include "plib035_pwm.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup PWM
  * @{
  */

/** @defgroup PWM_Private Приватные данные
  * @{
  */

/** @defgroup PWM_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup PWM_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Устанавливает все регистры PWM значениями по умолчанию
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @retval  void
  */
void PWM_DeInit(PWM_TypeDef* PWMx)
{
    uint32_t PWM_rst;

    assert_param(IS_PWM_PERIPH(PWMx));

    if (PWMx == PWM0)
        PWM_rst = RCU_APBRst_PWM0;
    else if (PWMx == PWM1)
        PWM_rst = RCU_APBRst_PWM1;
    else /* (PWMx == PWM2) */
        PWM_rst = RCU_APBRst_PWM2;

    RCU_APBRstCmd(PWM_rst, DISABLE);
    RCU_APBRstCmd(PWM_rst, ENABLE);
}

/**
  * @brief   Инициализирует таймер PWMx согласно параметрам структуры InitStruct
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_TB_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_TB_Init(PWM_TypeDef* PWMx, PWM_TB_Init_TypeDef* InitStruct)
{
    PWM_TB_HaltConfig(PWMx, InitStruct->Halt);
    PWM_TB_PhaseSyncCmd(PWMx, InitStruct->PhaseSync);
    PWM_TB_PhaseSyncDirConfig(PWMx, InitStruct->PhaseSyncDir);
    PWM_TB_ClkDivConfig(PWMx, InitStruct->ClkDiv, InitStruct->ClkDivExtra);
    PWM_TB_SyncOutConfig(PWMx, InitStruct->SyncOut);
    PWM_TB_PeriodDirectLoadCmd(PWMx, InitStruct->PeriodDirectLoad);
    PWM_TB_ModeConfig(PWMx, InitStruct->Mode);
    PWM_TB_SetPhase(PWMx, InitStruct->Phase);
    PWM_TB_SetPeriod(PWMx, InitStruct->Period);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_TB_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_TB_StructInit(PWM_TB_Init_TypeDef* InitStruct)
{
    InitStruct->ClkDiv = PWM_TB_ClkDiv_1;
    InitStruct->ClkDivExtra = PWM_TB_ClkDivExtra_1;
    InitStruct->Mode = PWM_TB_Mode_Up;
    InitStruct->Halt = PWM_TB_Halt_StopOnTBCLK;
    InitStruct->PeriodDirectLoad = DISABLE;
    InitStruct->PhaseSync = DISABLE;
    InitStruct->PhaseSyncDir = PWM_TB_Dir_Down;
    InitStruct->SyncOut = PWM_TB_SyncOut_SyncIn;
    InitStruct->Phase = 0;
    InitStruct->Period = 0;
}

/**
  * @brief   Инициализирует действия на выводах PWMx согласно параметрам структуры InitStruct
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_AQ_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_AQ_Init(PWM_TypeDef* PWMx, PWM_AQ_Init_TypeDef* InitStruct)
{
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqZero, InitStruct->ActionA_CTREqZero);
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqPeriod, InitStruct->ActionA_CTREqPeriod);
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqCMPAUp, InitStruct->ActionA_CTREqCMPAUp);
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqCMPADown, InitStruct->ActionA_CTREqCMPADown);
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqCMPBUp, InitStruct->ActionA_CTREqCMPBUp);
    PWM_AQ_ActionAConfig(PWMx, PWM_AQ_Event_CTREqCMPBDown, InitStruct->ActionA_CTREqCMPBDown);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqZero, InitStruct->ActionB_CTREqZero);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqPeriod, InitStruct->ActionB_CTREqPeriod);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqCMPAUp, InitStruct->ActionB_CTREqCMPAUp);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqCMPADown, InitStruct->ActionB_CTREqCMPADown);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqCMPBUp, InitStruct->ActionB_CTREqCMPBUp);
    PWM_AQ_ActionBConfig(PWMx, PWM_AQ_Event_CTREqCMPBDown, InitStruct->ActionB_CTREqCMPBDown);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_AQ_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_AQ_StructInit(PWM_AQ_Init_TypeDef* InitStruct)
{
    InitStruct->ActionA_CTREqZero = PWM_AQ_Action_None;
    InitStruct->ActionA_CTREqPeriod = PWM_AQ_Action_None;
    InitStruct->ActionA_CTREqCMPAUp = PWM_AQ_Action_None;
    InitStruct->ActionA_CTREqCMPADown = PWM_AQ_Action_None;
    InitStruct->ActionA_CTREqCMPBUp = PWM_AQ_Action_None;
    InitStruct->ActionA_CTREqCMPBDown = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqZero = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqPeriod = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqCMPAUp = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqCMPADown = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqCMPBUp = PWM_AQ_Action_None;
    InitStruct->ActionB_CTREqCMPBDown = PWM_AQ_Action_None;
}

/**
  * @brief   Инициализирует компараторы PWMx согласно параметрам структуры PWM_CMP_Init_TypeDef
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_CMP_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_CMP_Init(PWM_TypeDef* PWMx, PWM_CMP_Init_TypeDef* InitStruct)
{
    PWM_CMP_CmpALoadEventConfig(PWMx, InitStruct->LoadEventCmpA);
    PWM_CMP_CmpADirectLoadCmd(PWMx, InitStruct->CmpADirectLoad);
    PWM_CMP_SetCmpA(PWMx, InitStruct->CmpA);
    PWM_CMP_CmpALoadEventConfig(PWMx, InitStruct->LoadEventCmpB);
    PWM_CMP_CmpADirectLoadCmd(PWMx, InitStruct->CmpBDirectLoad);
    PWM_CMP_SetCmpB(PWMx, InitStruct->CmpB);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_CMPInit_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_CMP_StructInit(PWM_CMP_Init_TypeDef* InitStruct)
{
    InitStruct->LoadEventCmpA = PWM_CMP_LoadEvent_CTREqZero;
    InitStruct->CmpADirectLoad = DISABLE;
    InitStruct->CmpA = 0;
    InitStruct->LoadEventCmpB = PWM_CMP_LoadEvent_CTREqZero;
    InitStruct->CmpBDirectLoad = DISABLE;
    InitStruct->CmpB = 0;
}

/**
  * @brief   Инициализирует пороговый выключатель PWMx согласно параметрам структуры PWM_HD_Init_TypeDef
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_HD_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_HD_Init(PWM_TypeDef* PWMx, PWM_HD_Init_TypeDef* InitStruct)
{
    PWM_HD_ActionAConfig(PWMx, InitStruct->ActionA);
    PWM_HD_ActionBConfig(PWMx, InitStruct->ActionB);
    PWM_HD_SourceCmd(PWMx, InitStruct->Source, ENABLE);
    PWM_HD_CycleCmd(PWMx, InitStruct->Cycle);
    PWM_HD_OneShotCmd(PWMx, InitStruct->OneShot);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_HD_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_HD_StructInit(PWM_HD_Init_TypeDef* InitStruct)
{
    InitStruct->ActionA = PWM_HD_Action_ToOne;
    InitStruct->ActionB = PWM_HD_Action_ToOne;
    InitStruct->Source = 0;
    InitStruct->Cycle = DISABLE;
    InitStruct->OneShot = DISABLE;
}

/**
  * @brief   Инициализирует блок "мертвого времени" PWMx согласно параметрам структуры InitStruct
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_DB_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_DB_Init(PWM_TypeDef* PWMx, PWM_DB_Init_TypeDef* InitStruct)
{
    PWM_DB_InConfig(PWMx, InitStruct->In);
    PWM_DB_OutConfig(PWMx, InitStruct->Out);
    PWM_DB_PolarityConfig(PWMx, InitStruct->Polarity);
    PWM_DB_SetRiseDelay(PWMx, InitStruct->RiseDelay);
    PWM_DB_SetFallDelay(PWMx, InitStruct->FallDelay);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_DB_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_DB_StructInit(PWM_DB_Init_TypeDef* InitStruct)
{
    InitStruct->In = PWM_DB_In_A;
    InitStruct->Out = PWM_DB_Out_BypassAB;
    InitStruct->Polarity = PWM_DB_Polarity_ActiveHigh;
    InitStruct->RiseDelay = 0;
    InitStruct->FallDelay = 0;
}

/**
  * @brief   Инициализирует обработчик сигналов аварии PWMx согласно параметрам структуры PWM_TZ_Init_TypeDef
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_TZ_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_TZ_Init(PWM_TypeDef* PWMx, PWM_TZ_Init_TypeDef* InitStruct)
{
    PWM_TZ_ActionAConfig(PWMx, InitStruct->ActionA);
    PWM_TZ_ActionBConfig(PWMx, InitStruct->ActionB);
    PWM_TZ_CycleCmd(PWMx, InitStruct->Cycle);
    PWM_TZ_OneShotCmd(PWMx, InitStruct->OneShot);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_TZ_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_TZ_StructInit(PWM_TZ_Init_TypeDef* InitStruct)
{
    InitStruct->ActionA = PWM_TZ_Action_ToZ;
    InitStruct->ActionB = PWM_TZ_Action_ToZ;
    InitStruct->Cycle = DISABLE;
    InitStruct->OneShot = DISABLE;
}

/**
  * @brief   Инициализирует блок "триггера событий" PWMx, согласно параметрам структуры InitStruct
  * @param   PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-2
  * @param   InitStruct  Указатель на структуру типа @ref PWM_ET_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void PWM_ET_Init(PWM_TypeDef* PWMx, PWM_ET_Init_TypeDef* InitStruct)
{
    PWM_ET_SOCAEventConfig(PWMx, InitStruct->EventSOCA);
    PWM_ET_SOCAPeriodConfig(PWMx, InitStruct->PeriodSOCA);
    PWM_ET_SOCACmd(PWMx, InitStruct->SOCA);
    PWM_ET_SOCBEventConfig(PWMx, InitStruct->EventSOCB);
    PWM_ET_SOCBPeriodConfig(PWMx, InitStruct->PeriodSOCB);
    PWM_ET_SOCBCmd(PWMx, InitStruct->SOCB);
    PWM_ET_DRQAEventConfig(PWMx, InitStruct->EventDRQA);
    PWM_ET_DRQAPeriodConfig(PWMx, InitStruct->PeriodDRQA);
    PWM_ET_DRQACmd(PWMx, InitStruct->DRQA);
    PWM_ET_DRQBEventConfig(PWMx, InitStruct->EventDRQB);
    PWM_ET_DRQBPeriodConfig(PWMx, InitStruct->PeriodDRQB);
    PWM_ET_DRQBCmd(PWMx, InitStruct->DRQB);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref PWM_ET_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void PWM_ET_StructInit(PWM_ET_Init_TypeDef* InitStruct)
{
    InitStruct->EventSOCA = PWM_ET_Event_CTREqZero;
    InitStruct->PeriodSOCA = 0;
    InitStruct->SOCA = DISABLE;
    InitStruct->EventSOCB = PWM_ET_Event_CTREqZero;
    InitStruct->PeriodSOCB = 0;
    InitStruct->SOCB = DISABLE;
    InitStruct->EventDRQA = PWM_ET_Event_CTREqZero;
    InitStruct->PeriodDRQA = 0;
    InitStruct->DRQA = DISABLE;
    InitStruct->EventDRQB = PWM_ET_Event_CTREqZero;
    InitStruct->PeriodDRQB = 0;
    InitStruct->DRQB = DISABLE;
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
