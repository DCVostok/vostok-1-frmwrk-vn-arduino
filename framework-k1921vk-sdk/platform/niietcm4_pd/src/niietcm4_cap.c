/**
  ******************************************************************************
  * @file    niietcm4_cap.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с блоками захвата
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    18.01.2016
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
  * <h2><center>&copy; 2016 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_cap.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup CAP
  * @brief Драйвер для блоков захвата
  *
  * Драйвер разбит на 3 субмодуля: @ref CAP_Config, @ref CAP_Config_PWM_Mode, @ref CAP_Config_CAP_Mode.
  *
  * Вне зависимости от желаемого режима работы, сначала необходимо настроить блок в целом: @ref CAP_Init.
  * Затем выполнить настройку на нужный режим: @ref CAP_PWM_Init или @ref CAP_Capture_Init.
  * @{
  */ 

/** @defgroup CAP_Private Приватные данные
  * @{
  */

/** @defgroup CAP_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup CAP_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Устанавливает все регистры блока захвата значениями по умолчанию.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5
  * @retval Нет
  */

void CAP_DeInit(NT_CAP_TypeDef* CAPx)
{
    RCC_PeriphRst_TypeDef CAPRst;

    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    if (CAPx == NT_CAP0)
    {
        CAPRst = RCC_PeriphRst_CAP0;
    }
    else if (CAPx == NT_CAP1)
    {
        CAPRst = RCC_PeriphRst_CAP1;
    }
    else if (CAPx == NT_CAP2)
    {
        CAPRst = RCC_PeriphRst_CAP2;
    }
    else if (CAPx == NT_CAP3)
    {
        CAPRst = RCC_PeriphRst_CAP3;
    }
    else if (CAPx == NT_CAP4)
    {
        CAPRst = RCC_PeriphRst_CAP4;
    }
    else /* (CAPx == NT_CAP5) */
    {
        CAPRst = RCC_PeriphRst_CAP5;
    }

    RCC_PeriphRstCmd(CAPRst, DISABLE);
    RCC_PeriphRstCmd(CAPRst, ENABLE);
}

/**
  * @brief  Инициализирует CAPx согласно параметрам структуры CAP_InitStruct.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5
  * @param  CAP_InitStruct Указатель на структуру типа @ref CAP_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void CAP_Init(NT_CAP_TypeDef* CAPx, CAP_Init_TypeDef* CAP_InitStruct)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_HALT(CAP_InitStruct->CAP_Halt));
    assert_param(IS_CAP_SYNC_OUT(CAP_InitStruct->CAP_SyncOut));
    assert_param(IS_CAP_MODE(CAP_InitStruct->CAP_Mode));

    CAPx->ECCTL0_bit.FREE_SOFT = CAP_InitStruct->CAP_Halt;
    CAPx->ECCTL1_bit.SYNCO_SEL = CAP_InitStruct->CAP_SyncOut;
    CAPx->ECCTL1_bit.SYNCI_EN = CAP_InitStruct->CAP_SyncCmd;
    CAPx->ECCTL1_bit.CAP_APWM = CAP_InitStruct->CAP_Mode;
}

/**
  * @brief  Разрешение синхронизации.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void CAP_SyncCmd(NT_CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    CAPx->ECCTL1_bit.SYNCI_EN = (uint32_t)State;
}

/**
  * @brief  Заполнение каждого члена структуры CAP_InitStruct значениями по умолчанию.
  * @param  CAP_InitStruct Указатель на структуру типа @ref CAP_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void CAP_StructInit(CAP_Init_TypeDef* CAP_InitStruct)
{
    CAP_InitStruct->CAP_Halt = CAP_Halt_Stop;
    CAP_InitStruct->CAP_Mode = CAP_Mode_Capture;
    CAP_InitStruct->CAP_SyncCmd = DISABLE;
    CAP_InitStruct->CAP_SyncOut = CAP_SyncOut_Bypass;
}

/**
  * @brief  Разрешение работы таймера, выбранного блока захвата.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void CAP_TimerCmd(NT_CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    CAPx->ECCTL1_bit.TSCTRSTOP = (uint32_t)State;
}

/**
  * @brief  Установка текущего значения счетчика напрямую.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  TimerVal  Значение таймера.
  * @retval Нет
  */

void CAP_SetTimer(NT_CAP_TypeDef* CAPx, uint32_t TimerVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->TSCTR = TimerVal;
}

/**
  * @brief  Установка теневого значения таймера для отложенной записи.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  TimerVal  Значение таймера.
  * @retval Нет
  */

void CAP_SetShadowTimer(NT_CAP_TypeDef* CAPx, uint32_t TimerVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CTRPHS = TimerVal;
}

/**
  * @brief  Получение текущего значения таймера.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval TimerVal  Значение таймера.
  */

uint32_t CAP_GetTimer(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->TSCTR;
}

/**
  * @brief  Получение отложенного значения таймера.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval TimerVal  Значение таймера.
  */

uint32_t CAP_GetShadowTimer(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CTRPHS;
}

/**
  * @brief  Проведение программной синхронизации.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5.
  * @retval Нет
  */

void CAP_SwSync(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->ECCTL1_bit.SWSYNC = 1;
}

/**
  * @brief  Инициализирует режим ШИМ блока CAPx согласно параметрам структуры CAP_PWM_InitStruct.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5
  * @param  CAP_PWM_InitStruct Указатель на структуру типа @ref CAP_PWM_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void CAP_PWM_Init(NT_CAP_TypeDef* CAPx, CAP_PWM_Init_TypeDef* CAP_PWM_InitStruct)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_PWM_POLARITY(CAP_PWM_InitStruct->CAP_PWM_Polarity));

    CAP_PWM_SetPeriod(CAPx, CAP_PWM_InitStruct->CAP_PWM_Period);
    CAP_PWM_SetCompare(CAPx, CAP_PWM_InitStruct->CAP_PWM_Compare);
    CAPx->ECCTL1_bit.APWM_POL = CAP_PWM_InitStruct->CAP_PWM_Polarity;
}

/**
  * @brief  Заполнение каждого члена структуры CAP_PWM_InitStruct значениями по умолчанию.
  * @param  CAP_PWM_InitStruct Указатель на структуру типа @ref CAP_PWM_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void CAP_PWM_StructInit(CAP_PWM_Init_TypeDef* CAP_PWM_InitStruct)
{
    CAP_PWM_InitStruct->CAP_PWM_Period = 0xFFFFFFFF;
    CAP_PWM_InitStruct->CAP_PWM_Compare = 0x00010000;
    CAP_PWM_InitStruct->CAP_PWM_Polarity = CAP_PWM_Polarity_Pos;
}

/**
  * @brief  Установка значения периода ШИМ.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  PeriodVal  Значение периода.
  * @retval Нет
  */

void CAP_PWM_SetPeriod(NT_CAP_TypeDef* CAPx, uint32_t PeriodVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP0 = PeriodVal;
}

/**
  * @brief  Установка значения сравнения ШИМ.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  CompareVal  Значение сравнения.
  * @retval Нет
  */

void CAP_PWM_SetCompare(NT_CAP_TypeDef* CAPx, uint32_t CompareVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP1 = CompareVal;
}

/**
  * @brief  Установка значения периода ШИМ для отложенной записи.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  PeriodVal  Значение периода.
  * @retval Нет
  */

void CAP_PWM_SetShadowPeriod(NT_CAP_TypeDef* CAPx, uint32_t PeriodVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP2 = PeriodVal;
}

/**
  * @brief  Установка значения сравнения ШИМ для отложенной записи.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  CompareVal  Значение сравнения.
  * @retval Нет
  */

void CAP_PWM_SetShadowCompare(NT_CAP_TypeDef* CAPx, uint32_t CompareVal)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP3 = CompareVal;
}

/**
  * @brief  Получение текущего периода ШИМ.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval PeriodVal  Значение периода.
  */

uint32_t CAP_PWM_GetPeriod(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP0;
}

/**
  * @brief  Получение текущего значения сравнения ШИМ.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval CompareVal  Значение сравнения.
  */

uint32_t CAP_PWM_GetCompare(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP1;
}

/**
  * @brief  Получение отложенного значения периода ШИМ.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval PeriodVal  Значение периода.
  */

uint32_t CAP_PWM_GetShadowPeriod(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP2;
}

/**
  * @brief  Получение отложенного значения сравнения ШИМ.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval CompareVal  Значение сравнения.
  */

uint32_t CAP_PWM_GetShadowCompare(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP3;
}

/**
  * @brief  Инициализирует режим захвата блока CAPx согласно параметрам структуры CAP_Capture_InitStruct.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5
  * @param  CAP_Capture_InitStruct Указатель на структуру типа @ref CAP_Capture_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void CAP_Capture_Init(NT_CAP_TypeDef* CAPx, CAP_Capture_Init_TypeDef* CAP_Capture_InitStruct)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_MODE(CAP_Capture_InitStruct->CAP_CaptureMode));
    assert_param(IS_CAP_CAPTURE_POLARITY(CAP_Capture_InitStruct->CAP_Capture_PolarityEvent0));
    assert_param(IS_CAP_CAPTURE_POLARITY(CAP_Capture_InitStruct->CAP_Capture_PolarityEvent1));
    assert_param(IS_CAP_CAPTURE_POLARITY(CAP_Capture_InitStruct->CAP_Capture_PolarityEvent2));
    assert_param(IS_CAP_CAPTURE_POLARITY(CAP_Capture_InitStruct->CAP_Capture_PolarityEvent3));
    assert_param(IS_FUNCTIONAL_STATE(CAP_Capture_InitStruct->CAP_Capture_RstEvent0));
    assert_param(IS_FUNCTIONAL_STATE(CAP_Capture_InitStruct->CAP_Capture_RstEvent1));
    assert_param(IS_FUNCTIONAL_STATE(CAP_Capture_InitStruct->CAP_Capture_RstEvent2));
    assert_param(IS_FUNCTIONAL_STATE(CAP_Capture_InitStruct->CAP_Capture_RstEvent3));
    assert_param(IS_CAP_CAPTURE_PRESCALE(CAP_Capture_InitStruct->CAP_Capture_Prescale));
    assert_param(IS_CAP_CAPTURE_STOP_VAL(CAP_Capture_InitStruct->CAP_Capture_StopVal));

    CAPx->ECCTL1_bit.CONT_ONESHT = CAP_Capture_InitStruct->CAP_CaptureMode;
    CAPx->ECCTL1_bit.STOP_WRAP = CAP_Capture_InitStruct->CAP_Capture_StopVal;
    CAPx->ECCTL0_bit.PRESCALE = CAP_Capture_InitStruct->CAP_Capture_Prescale;
    CAPx->ECCTL0_bit.CAP0_POL = CAP_Capture_InitStruct->CAP_Capture_PolarityEvent0;
    CAPx->ECCTL0_bit.CAP1_POL = CAP_Capture_InitStruct->CAP_Capture_PolarityEvent1;
    CAPx->ECCTL0_bit.CAP2_POL = CAP_Capture_InitStruct->CAP_Capture_PolarityEvent2;
    CAPx->ECCTL0_bit.CAP3_POL = CAP_Capture_InitStruct->CAP_Capture_PolarityEvent3;
    CAPx->ECCTL0_bit.CTR_RST0 = CAP_Capture_InitStruct->CAP_Capture_RstEvent0;
    CAPx->ECCTL0_bit.CTR_RST1 = CAP_Capture_InitStruct->CAP_Capture_RstEvent1;
    CAPx->ECCTL0_bit.CTR_RST2 = CAP_Capture_InitStruct->CAP_Capture_RstEvent2;
    CAPx->ECCTL0_bit.CTR_RST3 = CAP_Capture_InitStruct->CAP_Capture_RstEvent3;
}

/**
  * @brief  Заполнение каждого члена структуры CAP_Capture_InitStruct значениями по умолчанию.
  * @param  CAP_Capture_InitStruct Указатель на структуру типа @ref CAP_Capture_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void CAP_Capture_StructInit(CAP_Capture_Init_TypeDef* CAP_Capture_InitStruct)
{
    CAP_Capture_InitStruct->CAP_CaptureMode = CAP_Capture_Mode_Single;
    CAP_Capture_InitStruct->CAP_Capture_StopVal = 0;
    CAP_Capture_InitStruct->CAP_Capture_Prescale = 0;
    CAP_Capture_InitStruct->CAP_Capture_PolarityEvent0 = CAP_Capture_Polarity_PosEdge;
    CAP_Capture_InitStruct->CAP_Capture_PolarityEvent1 = CAP_Capture_Polarity_PosEdge;
    CAP_Capture_InitStruct->CAP_Capture_PolarityEvent2 = CAP_Capture_Polarity_PosEdge;
    CAP_Capture_InitStruct->CAP_Capture_PolarityEvent3 = CAP_Capture_Polarity_PosEdge;
    CAP_Capture_InitStruct->CAP_Capture_RstEvent0 = DISABLE;
    CAP_Capture_InitStruct->CAP_Capture_RstEvent1 = DISABLE;
    CAP_Capture_InitStruct->CAP_Capture_RstEvent2 = DISABLE;
    CAP_Capture_InitStruct->CAP_Capture_RstEvent3 = DISABLE;
}

/**
  * @brief  Разрешение захвата для выбранного блока захвата.
  * @param  CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-5.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void CAP_Capture_Cmd(NT_CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        CAPx->ECCTL1_bit.REARM = 1;
    }

    CAPx->ECCTL0_bit.CAPLDEN = (uint32_t)State;
}

/**
  * @brief  Установка значения регистра захвата 0.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  Value  Значение.
  * @retval Нет
  */

void CAP_Capture_SetCap0(NT_CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP0 = Value;
}

/**
  * @brief  Установка значения регистра захвата 1.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  Value  Значение.
  * @retval Нет
  */

void CAP_Capture_SetCap1(NT_CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP1 = Value;
}

/**
  * @brief  Установка значения регистра захвата 2.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  Value  Значение.
  * @retval Нет
  */

void CAP_Capture_SetCap2(NT_CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP2 = Value;
}

/**
  * @brief  Установка значения регистра захвата 3.
  * @param  CAPx  Выбор таймера, где x лежит в диапазоне 0-5.
  * @param  Value  Значение.
  * @retval Нет
  */

void CAP_Capture_SetCap3(NT_CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->CAP3 = Value;
}

/**
  * @brief  Получение текущего значения из регистра захвата 0.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Value  Значение.
  */

uint32_t CAP_Capture_GetCap0(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP0;
}

/**
  * @brief  Получение текущего значения из регистра захвата 1.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Value  Значение.
  */

uint32_t CAP_Capture_GetCap1(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP1;
}

/**
  * @brief  Получение текущего значения из регистра захвата 2.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Value  Значение.
  */

uint32_t CAP_Capture_GetCap2(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP2;
}

/**
  * @brief  Получение текущего значения из регистра захвата 3.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Value  Значение.
  */

uint32_t CAP_Capture_GetCap3(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    return CAPx->CAP3;
}

/**
  * @brief  Разрешение работы прерывания выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @param  CAP_ITSource Выбор источников прерывания.
  *   Параметр принимает любою совокупность значений из @ref CAP_Exported_Constants_ITSource.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void CAP_ITCmd(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource,  FunctionalState State)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(CAP_ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        CAPx->ECEINT |= CAP_ITSource;
    }
    else /* if (State == DISABLE) */
    {
        CAPx->ECEINT &= ~CAP_ITSource;
    }
}

/**
  * @brief  Принудительный вызов прерывания выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @param  CAP_ITSource Выбор источников прерывания.
  *   Параметр принимает любою совокупность значений из @ref CAP_Exported_Constants_ITSource.
  * @retval Нет
  */

void CAP_ITForceCmd(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(CAP_ITSource));

    CAPx->ECFRC = CAP_ITSource;
}

/**
  * @brief  Чтение статуса флага источника прерывания выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @param  CAP_ITSource Выбор источников прерывания.
  *   Параметр принимает любою совокупность значений из @ref CAP_Exported_Constants_ITSource.
  * @retval Status Статус прерывания. Если выбрано несколько прерываний,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus CAP_ITStatus(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource)
{
    FlagStatus Status;

    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(CAP_ITSource));

    if (CAPx->ECFLG & CAP_ITSource)
    {
        Status = Flag_SET;
    }
    else
    {
        Status = Flag_CLEAR;
    }

    return Status;
}

/**
  * @brief  Сброс флагов источников прерываний выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @param  CAP_ITSource Выбор источников прерывания.
  *   Параметр принимает любою совокупность значений из @ref CAP_Exported_Constants_ITSource.
  * @retval Нет
  */

void CAP_ITStatusClear(NT_CAP_TypeDef* CAPx, uint32_t CAP_ITSource)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(CAP_ITSource));

    CAPx->ECCLR = CAP_ITSource;
}

/**
  * @brief  Чтение статуса прерывания выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Status Статус прерывания.
  */

FlagStatus CAP_ITPendStatus(NT_CAP_TypeDef* CAPx)
{
    FlagStatus Status;

    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    if (CAPx->PEINT)
    {
        Status = Flag_SET;
    }
    else
    {
        Status = Flag_CLEAR;
    }

    return Status;
}

/**
  * @brief  Сброс флага прерывания выбранного блока захвата.
  * @param  CAPx  Выбор CAP, где x лежит в диапазоне 0-5.
  * @retval Нет
  */

void CAP_ITPendClear(NT_CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_ALL_PERIPH(CAPx));

    CAPx->PEINT = 1;
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

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
