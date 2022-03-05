/**
  ******************************************************************************
  * @file    niietcm4_pwm.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с блоками ШИМ
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    23.08.2016
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
#include "niietcm4_pwm.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup PWM
  * @brief Драйвер для блоков ШИМ
  *
  * @attention Драйвер позволяет управлять только внутренними настройками модулей PWM, а также их межблоковой синхронизацией.
  *            Соотвестствующие порты ввода-вывода, а также системное тактирование и сброс блоков необходимо настраивать отдельно.
  *            <br>@ref GPIO : @ref GPIO_Init_Deinit.
  *            <br>@ref RCC : @ref RCC_CLK_Config, @ref RCC_RST_Config.
  *
  * Драйвер разбит на несколько субмодулей:
  * - @ref PWM_Exported_Functions_CTR
  * - @ref PWM_Exported_Functions_CMP
  * - @ref PWM_Exported_Functions_HighResolution
  * - @ref PWM_Exported_Functions_HoldDetector
  * - @ref PWM_Exported_Functions_DeadBand
  * - @ref PWM_Exported_Functions_PWM_Chopper
  * - @ref PWM_Exported_Functions_TripZone
  * - @ref PWM_Exported_Functions_EventTrigger
  * - @ref PWM_Exported_Functions_IT
  *
  * Общий вид процесса инициализации, после вывода блока из сброса, включения тактирования
  * и настройки портов ввода-вывода:
  * - настраиваем счетчик (@ref PWM_Exported_Functions_CTR);
  * - настраиваем компараторы (@ref PWM_Exported_Functions_CMP);
  * - включаем прерывание по счетчику, если необходимо (@ref PWM_Exported_Functions_IT);
  * - настраиваем другие субмодули, если необходим их функционал;
  * - модули @ref PWM_Exported_Functions_TripZone и @ref PWM_Exported_Functions_HoldDetector имеют
  *   по собственному вектору прерываний, если необходимо активируем и их прерывания;
  * - включаем предделители нужных блоков ШИМ (@ref PWM_PrescCmd);
  * - если все было сделано верно, то счетчики начинают считать, а на портах генерируются,
  *   в соответствии с заданными правилами, ШИМ-сигналы.
  *
  * Более подробно инициализация и использование PWM показаны в приложенных к драйверу примерах.
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
  * @brief  Управление предделителями тактирования таймеров блоков ШИМ.
  * @param  Presc Выбор предделителей блоков.
  *   Параметр принимает любою совокупность значений из @ref PWM_Exported_Constants_Presc.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_PrescCmd(uint32_t Presc, FunctionalState State)
{
    assert_param(IS_PWM_PRESC(Presc));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == DISABLE)
    {
        NT_COMMON_REG->PWM_SYNC &= ~Presc;
    }
    else if (State == ENABLE)
    {
        NT_COMMON_REG->PWM_SYNC |= Presc;
    }
}

/**
  * @brief  Выбор схемы синхронизации блоков ШИМ.
  * @param  SyncSelect  Выбор схемы.
  *   Параметр принимает любое значение из @ref PWM_Sync_TypeDef.
  * @retval Нет
  */

void PWM_SyncConfig(PWM_Sync_TypeDef SyncSelect)
{
    assert_param(IS_PWM_SYNC(SyncSelect));

    NT_COMMON_REG->PWM_CTRL_bit.SYNCSELECT = (uint32_t)SyncSelect;
}

/**
  * @brief  Устанавливает все регистры блока ШИМ значениями по умолчанию.
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-8
  * @retval Нет
  */

void PWM_DeInit(NT_PWM_TypeDef* PWMx)
{
    RCC_PeriphRst_TypeDef PWMRst;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx == NT_PWM0)
    {
        PWMRst = RCC_PeriphRst_PWM0;
    }
    else if (PWMx == NT_PWM1)
    {
        PWMRst = RCC_PeriphRst_PWM1;
    }
    else if (PWMx == NT_PWM2)
    {
        PWMRst = RCC_PeriphRst_PWM2;
    }
    else if (PWMx == NT_PWM3)
    {
        PWMRst = RCC_PeriphRst_PWM3;
    }
    else if (PWMx == NT_PWM4)
    {
        PWMRst = RCC_PeriphRst_PWM4;
    }
    else if (PWMx == NT_PWM5)
    {
        PWMRst = RCC_PeriphRst_PWM5;
    }
    else if (PWMx == NT_PWM6)
    {
        PWMRst = RCC_PeriphRst_PWM6;
    }
    else if (PWMx == NT_PWM7)
    {
        PWMRst = RCC_PeriphRst_PWM7;
    }
    else /* (PWMx == NT_PWM8) */
    {
        PWMRst = RCC_PeriphRst_PWM8;
    }

    RCC_PeriphRstCmd(PWMRst, DISABLE);
    RCC_PeriphRstCmd(PWMRst, ENABLE);
}

/**
  * @brief  Программное задание продолжительного воздейсвия на канал(ы) PWM.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  Channel  Выбор канала.
  *     Параметр может принимать любое значение из @ref PWM_Channel_TypeDef.
  * @param  ChActionA  Тип воздействия на канал А.
  *     Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef.
  * @param  ChActionB  Тип воздействия на канал B.
  *     Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef.
  * @retval Нет
  */

void PWM_ChForceContCmd(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel, PWM_ChAction_TypeDef ChActionA, PWM_ChAction_TypeDef ChActionB)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CHANNEL(Channel));
    assert_param(IS_PWM_CH_ACTION(ChActionA));
    assert_param(IS_PWM_CH_ACTION(ChActionB));

    if (Channel == PWM_Channel_A)
    {
        PWMx->AQCSFRC_bit.CSFA = (uint32_t)ChActionA;
    }
    else if (Channel == PWM_Channel_B)
    {
        PWMx->AQCSFRC_bit.CSFB = (uint32_t)ChActionB;
    }
    else /* if (Channel == PWM_Channel_AB) */
    {
        PWMx->AQCSFRC = ((uint32_t)ChActionA<<PWM_AQCSFRC_CSFA_Pos) |
                        ((uint32_t)ChActionB<<PWM_AQCSFRC_CSFB_Pos);
    }
}

/**
  * @brief  Настройка типа однократного программного воздейсвия на канал(ы) PWM.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  Channel  Выбор канала.
  *     Параметр может принимать любое значение из @ref PWM_Channel_TypeDef.
  * @param  ChActionA  Тип воздействия на канал А.
  *     Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef.
  * @param  ChActionB  Тип воздействия на канал B.
  *     Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef.
  * @retval Нет
  */

void PWM_ChForceConfig(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel, PWM_ChAction_TypeDef ChActionA, PWM_ChAction_TypeDef ChActionB)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CHANNEL(Channel));
    assert_param(IS_PWM_CH_ACTION(ChActionA));
    assert_param(IS_PWM_CH_ACTION(ChActionB));

    if (Channel == PWM_Channel_A)
    {
        PWMx->AQSFRC_bit.ACTSFA = (uint32_t)ChActionA;
    }
    else if (Channel == PWM_Channel_B)
    {
        PWMx->AQSFRC_bit.ACTSFB = (uint32_t)ChActionB;
    }
    else /* if (Channel == PWM_Channel_AB) */
    {
        PWMx->AQSFRC = ((uint32_t)ChActionA<<PWM_AQSFRC_ACTSFA_Pos) |
                       ((uint32_t)ChActionB<<PWM_AQSFRC_ACTSFB_Pos);
    }
}

/**
  * @brief  Применение выбранного однократного программного воздейсвия на канал(ы) PWM.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  Channel  Выбор канала.
  *     Параметр может принимать любое значение из @ref PWM_Channel_TypeDef.
  * @retval Нет
  */

void PWM_ChForceCmd(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CHANNEL(Channel));

    if (Channel == PWM_Channel_A)
    {
        PWMx->AQSFRC_bit.OTSFA = 1;
    }
    else if (Channel == PWM_Channel_B)
    {
        PWMx->AQSFRC_bit.OTSFB = 1;
    }
    else /* if (Channel == PWM_Channel_AB) */
    {
        PWMx->AQSFRC |= (1<<PWM_AQSFRC_OTSFA_Pos) |
                        (1<<PWM_AQSFRC_OTSFB_Pos);
    }
}

/**
  * @brief  Инициализирует таймер PWMx согласно параметрам структуры PWM_TimerInitStruct.
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-8
  * @param  PWM_TimerInitStruct Указатель на структуру типа @ref PWM_TimerInit_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void PWM_CTR_Init(NT_PWM_TypeDef* PWMx, PWM_CTR_Init_TypeDef* PWM_CTR_InitStruct)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CH_ACTION(PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_A));
    assert_param(IS_PWM_CH_ACTION(PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_B));
    assert_param(IS_PWM_CH_ACTION(PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_A));
    assert_param(IS_PWM_CH_ACTION(PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_B));
    assert_param(IS_PWM_CLK_DIV(PWM_CTR_InitStruct->PWM_ClkDiv));
    assert_param(IS_PWM_CLK_DIV_EXTRA(PWM_CTR_InitStruct->PWM_ClkDivExtra));
    assert_param(IS_PWM_CTR_MODE(PWM_CTR_InitStruct->PWM_CTR_Mode));
    assert_param(IS_PWM_CTR_HALT(PWM_CTR_InitStruct->PWM_CTR_Halt));
    assert_param(IS_PWM_LOAD_MODE(PWM_CTR_InitStruct->PWM_LoadMode_Period));
    assert_param(IS_FUNCTIONAL_STATE(PWM_CTR_InitStruct->PWM_PhaseEn));
    assert_param(IS_PWM_CTR_DIR(PWM_CTR_InitStruct->PWM_CTR_Dir_Phase));
    assert_param(IS_PWM_CTR_SYNC_OUT(PWM_CTR_InitStruct->PWM_CTR_SyncOut));

    PWM_CTR_SetPhase(PWMx, PWM_CTR_InitStruct->PWM_Phase);

    PWMx->AQCTLA_bit.ZRO = (uint32_t)PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_A;
    PWMx->AQCTLA_bit.PRD = (uint32_t)PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_A;
    PWMx->AQCTLB_bit.ZRO = (uint32_t)PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_B;
    PWMx->AQCTLB_bit.PRD = (uint32_t)PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_B;

    PWMx->TBCTL_bit.PHSDIR = (uint32_t)PWM_CTR_InitStruct->PWM_CTR_Dir_Phase;
    PWMx->TBCTL_bit.CLKDIV = (uint32_t)PWM_CTR_InitStruct->PWM_ClkDiv;
    PWMx->TBCTL_bit.HSPCLKDIV = (uint32_t)PWM_CTR_InitStruct->PWM_ClkDivExtra;
    PWMx->TBCTL_bit.SYNCOSEL = (uint32_t)PWM_CTR_InitStruct->PWM_CTR_SyncOut;
    PWMx->TBCTL_bit.PRDLD = (uint32_t)PWM_CTR_InitStruct->PWM_LoadMode_Period;
    PWMx->TBCTL_bit.PHSEN = (uint32_t)PWM_CTR_InitStruct->PWM_PhaseEn;
    PWMx->TBCTL_bit.CTRMODE = (uint32_t)PWM_CTR_InitStruct->PWM_CTR_Mode;

    PWM_CTR_SetPeriod(PWMx, PWM_CTR_InitStruct->PWM_Period);
}

/**
  * @brief  Заполнение каждого члена структуры PWM_TimerInitStruct значениями по умолчанию.
  * @param  PWM_TimerInitStruct Указатель на структуру типа @ref PWM_TimerInit_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void PWM_CTR_StructInit(PWM_CTR_Init_TypeDef* PWM_CTR_InitStruct)
{
    PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_A = PWM_ChAction_None;
    PWM_CTR_InitStruct->PWM_ChAction_CTREqPeriod_B = PWM_ChAction_None;
    PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_A = PWM_ChAction_None;
    PWM_CTR_InitStruct->PWM_ChAction_CTREqZero_B = PWM_ChAction_None;
    PWM_CTR_InitStruct->PWM_ClkDiv = PWM_ClkDiv_1;
    PWM_CTR_InitStruct->PWM_ClkDivExtra = PWM_ClkDivExtra_1;
    PWM_CTR_InitStruct->PWM_CTR_Mode = PWM_CTR_Mode_Up;
    PWM_CTR_InitStruct->PWM_CTR_Halt = PWM_CTR_Halt_StopOnTBCLK;
    PWM_CTR_InitStruct->PWM_LoadMode_Period = PWM_LoadMode_Shadow;
    PWM_CTR_InitStruct->PWM_Period = 0;
    PWM_CTR_InitStruct->PWM_Phase = 0;
    PWM_CTR_InitStruct->PWM_PhaseEn = DISABLE;
    PWM_CTR_InitStruct->PWM_CTR_Dir_Phase = PWM_CTR_Dir_Down;
    PWM_CTR_InitStruct->PWM_CTR_SyncOut = PWM_CTR_SyncOut_SyncIn;
}

/**
  * @brief  Чтение статуса флага состояния таймера PWM.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TimerStatus Выбор флагов.
  *   Параметр принимает любою совокупность значений из @ref PWM_Exported_Constants_CTR_Status.
  * @retval Status Статус прерывания. Если выбрано несколько флагов,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus PWM_CTR_Status(NT_PWM_TypeDef* PWMx, uint32_t CTR_Status)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CTR_STATUS(CTR_Status));

    if (PWMx->TBSTS & CTR_Status)
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
  * @brief  Сброс флагов статусов таймера PWM.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TimerStatus Выбор флагов.
  *   Параметр принимает любою совокупность значений из @ref PWM_Exported_Constants_TimerStatus.
  * @retval Нет
  */

void PWM_CTR_StatusClear(NT_PWM_TypeDef* PWMx, uint32_t CTR_Status)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CTR_STATUS(CTR_Status));

    PWMx->TBSTS = CTR_Status;
}

/**
  * @brief  Установка значения счетчика ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  CounterVal  Значение счетчика.
  * @retval Нет
  */

void PWM_CTR_SetValue(NT_PWM_TypeDef* PWMx, uint32_t CTR_Val)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_COUNTER_VAL(CTR_Val));

    PWMx->TBCTR = CTR_Val;
}

/**
  * @brief  Установка значения периода ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  PeriodVal  Значение периода.
  * @retval Нет
  */

void PWM_CTR_SetPeriod(NT_PWM_TypeDef* PWMx, uint32_t CTR_PeriodVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_PERIOD_VAL(CTR_PeriodVal));

    PWMx->TBPRD = CTR_PeriodVal;
}

/**
  * @brief  Установка значения фазы ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  PhaseVal  Значение фазы.
  * @retval Нет
  */

void PWM_CTR_SetPhase(NT_PWM_TypeDef* PWMx, uint32_t CTR_PhaseVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_PHASE_VAL(CTR_PhaseVal));

    PWMx->TBPHS_bit.TBPHS = CTR_PhaseVal;
}

/**
  * @brief  Получение текущего значения счетчика ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval CounterVal  Значение счетчика.
  */

uint32_t PWM_CTR_GetValue(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->TBCTR;
}

/**
  * @brief  Получение текущего значения периода ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval PeriodVal  Значение периода.
  */

uint32_t PWM_CTR_GetPeriod(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->TBPRD;
}

/**
  * @brief  Получение текущего значения фазы ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval PhaseVal  Значение фазы.
  */

uint32_t PWM_CTR_GetPhase(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->TBPHS_bit.TBPHS;
}

/**
  * @brief  Программный запуск входного синхроимпульса SYNCI.
  * @retval нет
  */

void PWM_CTR_SWSyncInCmd(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->TBCTL_bit.SWFSYNC = 1;
}

/**
  * @brief  Инициализирует компараторы PWMx согласно параметрам структуры PWM_CMP_InitStruct.
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-8
  * @param  PWM_CMP_InitStruct Указатель на структуру типа @ref PWM_CMP_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void PWM_CMP_Init(NT_PWM_TypeDef* PWMx, PWM_CMP_Init_TypeDef* PWM_CMP_InitStruct)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_A));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_A));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_A));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_A));
    assert_param(IS_PWM_LOAD_EVENT(PWM_CMP_InitStruct->PWM_LoadEvent_CMPA));
    assert_param(IS_PWM_LOAD_MODE(PWM_CMP_InitStruct->PWM_LoadMode_CMPA));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_B));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_B));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_B));
    assert_param(IS_PWM_CH_ACTION(PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_B));
    assert_param(IS_PWM_LOAD_EVENT(PWM_CMP_InitStruct->PWM_LoadEvent_CMPB));
    assert_param(IS_PWM_LOAD_MODE(PWM_CMP_InitStruct->PWM_LoadMode_CMPB));

    PWMx->CMPCTL_bit.LOADAMODE = (uint32_t)PWM_CMP_InitStruct->PWM_LoadEvent_CMPA;
    PWMx->CMPCTL_bit.LOADBMODE = (uint32_t)PWM_CMP_InitStruct->PWM_LoadEvent_CMPB;
    PWMx->CMPCTL_bit.SHDWAMODE = (uint32_t)PWM_CMP_InitStruct->PWM_LoadMode_CMPA;
    PWMx->CMPCTL_bit.SHDWBMODE = (uint32_t)PWM_CMP_InitStruct->PWM_LoadMode_CMPB;

    PWMx->AQCTLA_bit.CAD = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_A;
    PWMx->AQCTLA_bit.CAU = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_A;
    PWMx->AQCTLA_bit.CBD = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_A;
    PWMx->AQCTLA_bit.CBU = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_A;
    PWMx->AQCTLB_bit.CAD = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_B;
    PWMx->AQCTLB_bit.CAU = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_B;
    PWMx->AQCTLB_bit.CBD = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_B;
    PWMx->AQCTLB_bit.CBU = (uint32_t)PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_B;

    PWM_CMP_SetA(PWMx, PWM_CMP_InitStruct->PWM_CMPA);
    PWM_CMP_SetB(PWMx, PWM_CMP_InitStruct->PWM_CMPB);
}

/**
  * @brief  Заполнение каждого члена структуры PWM_CMPInitStruct значениями по умолчанию.
  * @param  PWM_CMPInitStruct Указатель на структуру типа @ref PWM_CMPInit_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void PWM_CMP_StructInit(PWM_CMP_Init_TypeDef* PWM_CMP_InitStruct)
{
    PWM_CMP_InitStruct->PWM_CMPA = 0;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_A = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_A = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_A = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_A = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_LoadEvent_CMPA = PWM_LoadEvent_CTREqZero;
    PWM_CMP_InitStruct->PWM_LoadMode_CMPA = PWM_LoadMode_Shadow;
    PWM_CMP_InitStruct->PWM_CMPB = 0;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Down_B = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPA_Up_B = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Down_B = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_ChAction_CTREqCMPB_Up_B = PWM_ChAction_None;
    PWM_CMP_InitStruct->PWM_LoadEvent_CMPB = PWM_LoadEvent_CTREqZero;
    PWM_CMP_InitStruct->PWM_LoadMode_CMPB = PWM_LoadMode_Shadow;
}


/**
  * @brief  Установка значения сравнения компаратора A ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  CMPAVal  Значение сравнения.
  * @retval Нет
  */

void PWM_CMP_SetA(NT_PWM_TypeDef* PWMx, uint32_t CMPAVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_VAL(CMPAVal));

    PWMx->CMPA_bit.CMPA = CMPAVal;
}

/**
  * @brief  Установка значения сравнения компаратора B ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  CMPBVal  Значение сравнения.
  * @retval Нет
  */

void PWM_CMP_SetB(NT_PWM_TypeDef* PWMx, uint32_t CMPBVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_VAL(CMPBVal));

    PWMx->CMPB_bit.CMPB = CMPBVal;
}

/**
  * @brief  Получение текущего значения сравнения компаратора A ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval CMPAVal  Значение сравнения.
  */

uint32_t PWM_CMP_GetA(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->CMPA_bit.CMPA;
}

/**
  * @brief  Получение текущего значения сравнения компаратора B ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval CMPBVal  Значение сравнения.
  */

uint32_t PWM_CMP_GetB(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->CMPB_bit.CMPB;
}

/**
  * @brief  Чтение статуса флага состояния компараторов PWM.
  *     Флаги установлены, если произошла запись в активный регистр значения сравнения из теневого.
  *     Сбрасываются флаги автоматически при каждой записи в теневой регистр.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  CMP_Status Выбор флагов.
  *   Параметр принимает любою совокупность значений из @ref PWM_Exported_Constants_CMP_Status.
  * @retval Status Статус флагов. Если выбрано несколько флагов,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus PWM_CMP_Status(NT_PWM_TypeDef* PWMx, uint32_t CMP_Status)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_STATUS(CMP_Status));

    if (PWMx->CMPCTL & CMP_Status)
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
  * @brief  Инициализирует режим высокого разрешения PWMx согласно параметрам структуры PWM_HR_InitStruct.
  * @attention
  *     - Режим доступен только для каналов А ШИМ0-5.
  *     - Настройку режима необходимо выполнять только после настройки счетчика и компараторов:
  *     @ref PWM_CTR_Init и @ref PWM_CMP_Init.
  *     - При задании задержки высокого разрешения через расширение регистра сравнения и его теневую запись,
  *     настройки события для теневой записи должны совпадать с настройками теневой записи регистра CMPA
  *     (@ref PWM_CMP_Init).
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-5.
  * @param  PWM_HR_InitStruct Указатель на структуру типа @ref PWM_HR_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void PWM_HR_Init(NT_PWM_TypeDef* PWMx, PWM_HR_Init_TypeDef* PWM_HR_InitStruct)
{
    assert_param(IS_PWM_HR_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HR_CMP_LOAD(PWM_HR_InitStruct->PWM_HR_CMPLoad));
    assert_param(IS_PWM_HR_MODE(PWM_HR_InitStruct->PWM_HR_Mode));
    assert_param(IS_PWM_HR_EDGE(PWM_HR_InitStruct->PWM_HR_Edge));

    PWMx->HRCNFG_bit.HR_LOAD = (uint32_t)PWM_HR_InitStruct->PWM_HR_CMPLoad;
    PWMx->HRCNFG_bit.CTLMODE = (uint32_t)PWM_HR_InitStruct->PWM_HR_Mode;
    PWMx->HRCNFG_bit.EDGMODE = (uint32_t)PWM_HR_InitStruct->PWM_HR_Edge;

    PWM_HR_SetCMP(PWMx, PWM_HR_InitStruct->PWM_HR_CMP);
    PWM_HR_SetPhase(PWMx, PWM_HR_InitStruct->PWM_HR_Phase);
}

/**
  * @brief  Заполнение каждого члена структуры PWM_HR_InitStruct значениями по умолчанию.
  * @param  PWM_HR_InitStruct Указатель на структуру типа @ref PWM_HR_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */


void PWM_HR_StructInit(PWM_HR_Init_TypeDef* PWM_HR_InitStruct)
{
    PWM_HR_InitStruct->PWM_HR_CMPLoad = PWM_HR_CMPLoad_CTREqZero;
    PWM_HR_InitStruct->PWM_HR_Mode = PWM_HR_Mode_CMP;
    PWM_HR_InitStruct->PWM_HR_Edge = PWM_HR_Edge_None;
    PWM_HR_InitStruct->PWM_HR_CMP = 0;
    PWM_HR_InitStruct->PWM_HR_Phase = 0;
}

/**
  * @brief  Установка расширенного значения сравнения компаратора A ШИМ высокого разрешения.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-5.
  * @param  HR_CMPVal  Значение сравнения.
  * @retval Нет
  */

void PWM_HR_SetCMP(NT_PWM_TypeDef* PWMx, uint32_t HR_CMPVal)
{
    assert_param(IS_PWM_HR_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HR_CMP_VAL(HR_CMPVal));

    PWMx->CMPA_bit.CMPAHR = HR_CMPVal;
}

/**
  * @brief  Установка расширенного значения фазы ШИМ высокого разрешения.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-5.
  * @param  HR_PhaseVal  Значение фазы.
  * @retval Нет
  */

void PWM_HR_SetPhase(NT_PWM_TypeDef* PWMx, uint32_t HR_PhaseVal)
{
    assert_param(IS_PWM_HR_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HR_PHASE_VAL(HR_PhaseVal));

    PWMx->TBPHS_bit.TBPHSHR = HR_PhaseVal;
}

/**
  * @brief  Получение текущего расширенного значения сравнения ШИМ высокого разрешения.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-5.
  * @retval HR_CMPVal  Значение сравнения.
  */

uint32_t PWM_HR_GetCMP(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_HR_ALL_PERIPH(PWMx));

    return PWMx->CMPA_bit.CMPAHR;
}

/**
  * @brief  Получение текущего расширенного значения фазы ШИМ высокого разрешения.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-5.
  * @retval HR_PhaseVal  Значение сравнения.
  */

uint32_t PWM_HR_GetPhase(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_HR_ALL_PERIPH(PWMx));

    return PWMx->TBPHS_bit.TBPHSHR;
}

/**
  * @brief  Настройка прерывания ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  PWM_Event_TypeDef  Выбор события для возникновения прерывания.
  *   Параметр принимает любое значение из @ref PWM_Event_TypeDef.
  * @param  ITPeriod  Выбор количества событий для возникновения прерывания.
  *   Параметр принимает любое значение из диапазона 0-3,
  *   где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval Нет
  */

void PWM_ITConfig(NT_PWM_TypeDef* PWMx, PWM_Event_TypeDef Event, uint32_t ITPeriod)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_EVENT(Event));
    assert_param(IS_PWM_IT_PERIOD(ITPeriod));

    PWMx->ETSEL_bit.INTSEL = (uint32_t)Event;
    PWMx->ETPS_bit.INTPRD = ITPeriod;
}

/**
  * @brief  Разрешение работы прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_ITCmd(NT_PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    PWMx->ETSEL_bit.INTEN = (uint32_t)State;
}

/**
  * @brief  Получение текущего значения счетчика событий, приводящих к прерыванию.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval EventCount  Значение.
  */

uint32_t PWM_GetITEventCount(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->ETPS_bit.INTCNT;
}

/**
  * @brief  Чтение статуса флага прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Status Статус прерывания.
  */

FlagStatus PWM_ITStatus(NT_PWM_TypeDef* PWMx)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx->ETFLG_bit.INT)
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
  * @brief  Сброс флага прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Нет
  */

void PWM_ITStatusClear(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->ETCLR_bit.INT = 1;
}

/**
  * @brief  Чтение статуса запроса прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Status Статус запроса прерывания.
  */

FlagStatus PWM_ITPendStatus(NT_PWM_TypeDef* PWMx)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx->INTCLR_bit.INT)
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
  * @brief  Сброс запроса прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Нет
  */

void PWM_ITPendClear(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->INTCLR_bit.INT = 1;
}

/**
  * @brief  Программный вызов прерывания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Нет
  */

void PWM_ITForce(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->ETFRC_bit.INT = 1;
}

/**
  * @brief  Инициализирует блок "мертвого времени" PWMx согласно параметрам структуры PWM_DB_InitStruct.
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-8
  * @param  PWM_DB_InitStruct Указатель на структуру типа @ref PWM_DB_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void PWM_DB_Init(NT_PWM_TypeDef* PWMx, PWM_DB_Init_TypeDef* PWM_DB_InitStruct)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_DB_IN(PWM_DB_InitStruct->PWM_DB_In));
    assert_param(IS_PWM_DB_POL(PWM_DB_InitStruct->PWM_DB_Pol));
    assert_param(IS_PWM_DB_OUT(PWM_DB_InitStruct->PWM_DB_Out));

    PWMx->DBCTL_bit.IN_MODE = (uint32_t)PWM_DB_InitStruct->PWM_DB_In;
    PWMx->DBCTL_bit.POLSEL = (uint32_t)PWM_DB_InitStruct->PWM_DB_Pol;
    PWMx->DBCTL_bit.OUT_MODE = (uint32_t)PWM_DB_InitStruct->PWM_DB_Out;

    PWM_DB_SetRiseDelay(PWMx, PWM_DB_InitStruct->PWM_DB_RiseDelay);
    PWM_DB_SetFallDelay(PWMx, PWM_DB_InitStruct->PWM_DB_FallDelay);
}

/**
  * @brief  Заполнение каждого члена структуры PWM_DB_InitStruct значениями по умолчанию.
  * @param  PWM_DB_InitStruct Указатель на структуру типа @ref PWM_DB_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void PWM_DB_StructInit(PWM_DB_Init_TypeDef* PWM_DB_InitStruct)
{
    PWM_DB_InitStruct->PWM_DB_In = PWM_DB_In_A;
    PWM_DB_InitStruct->PWM_DB_Pol = PWM_DB_Pol_ActHigh;
    PWM_DB_InitStruct->PWM_DB_Out = PWM_DB_Out_BypassAB;
    PWM_DB_InitStruct->PWM_DB_RiseDelay = 0;
    PWM_DB_InitStruct->PWM_DB_FallDelay = 0;
}

/**
  * @brief  Установка значения величины задержки по переднему фронту.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  RiseDelayVal  Значение.
  * @retval Нет
  */

void PWM_DB_SetRiseDelay(NT_PWM_TypeDef* PWMx, uint32_t RiseDelayVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_DB_DELAY_VAL(RiseDelayVal));

    PWMx->DBRED = RiseDelayVal;
}

/**
  * @brief  Установка значения величины задержки по заднему фронту.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  FallDelayVal  Значение.
  * @retval Нет
  */

void PWM_DB_SetFallDelay(NT_PWM_TypeDef* PWMx, uint32_t FallDelayVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_DB_DELAY_VAL(FallDelayVal));

    PWMx->DBFED = FallDelayVal;
}

/**
  * @brief  Получение текущего значения величины задержки по переднему фронту.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval RiseDelayVal  Значение.
  */

uint32_t PWM_DB_GetRiseDelay(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->DBRED;
}

/**
  * @brief  Получение текущего значения величины задержки по заднему фронту.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval FallDelayVal  Значение.
  */

uint32_t PWM_DB_GetFallDelay(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    return PWMx->DBFED;
}

/**
  * @brief  Установка ширины фильтрации коротких импульсов.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  FilterVal  Значение.
  *     Параметр принимает любое значение из диапазона 0x00-0xFF,
  *     где 0 - фильтр выключен, а 0xFF - 25.6 мкс (шаг установки 0.1 мкс).
  * @retval Нет
  */

void PWM_FilterConfig(NT_PWM_TypeDef* PWMx, uint32_t FilterVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_FILTER(FilterVal));

    PWMx->FWDTH = FilterVal;
}

/**
  * @brief Настройка модулятора сигналов ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  DutyVal  Значение скважности второго и последующего импульсов.
  *     Параметр принимает любое значение из диапазона 0x0-0x6,
  *     где 0x0 - скважность 1/8, а 0x6 - 7/8.
  * @param  FreqDivVal  Значение делителя частоты второго и последующего импульсов.
  *     Параметр принимает любое значение из диапазона 0x0-0x7,
  *     где 0x0 - без деления, 0x1 - с коэф. 1/2, а 0x7 - 1/8.
  * @param  FirstWidthVal  Значение ширины первого импульса в тактах SysClk/8.
  *     Параметр принимает любое значение из диапазона 0x0-0xF,
  *     где 0x0 - 1 такт, а 0xF - 16 тактов.
  * @retval Нет
  */

void PWM_PC_Config(NT_PWM_TypeDef* PWMx, uint32_t DutyVal, uint32_t FreqDivVal, uint32_t FirstWidthVal)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_PC_DUTY(DutyVal));
    assert_param(IS_PWM_PC_FREQ_DIV(FreqDivVal));
    assert_param(IS_PWM_PC_FIRST_WIDTH(FirstWidthVal));

    PWMx->PCCTL_bit.CHPDUTY = DutyVal;
    PWMx->PCCTL_bit.SHRFREQ = FreqDivVal;
    PWMx->PCCTL_bit.OSHTWTH = FirstWidthVal;
}

/**
  * @brief  Включение модулятора блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_PC_Cmd(NT_PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    PWMx->PCCTL_bit.CHPEN = (uint32_t)State;
}

/**
  * @brief  Настройка поведения канала при поступлении сигнала аварии.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  TZ_ActionA  Выбор действия для канала A.
  *     Параметр может принимать любое значение из @ref PWM_TZ_Action_TypeDef.
  * @param  TZ_ActionB  Выбор действия для канала B.
  *     Параметр может принимать любое значение из @ref PWM_TZ_Action_TypeDef.
  * @retval Нет
  */

void PWM_TZ_ActionConfig(NT_PWM_TypeDef* PWMx, PWM_TZ_Action_TypeDef TZ_ActionA, PWM_TZ_Action_TypeDef TZ_ActionB)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_ACTION(TZ_ActionA));
    assert_param(IS_PWM_TZ_ACTION(TZ_ActionB));

    PWMx->TZCTL_bit.TZA = (uint32_t)TZ_ActionA;
    PWMx->TZCTL_bit.TZB = (uint32_t)TZ_ActionB;
}

/**
  * @brief  Включение циклической обработки сигнала аварии.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_Channel Выбор каналов аварии.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_Channel.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_TZ_CycleCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_Channel, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_CHANNEL(TZ_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        PWMx->TZSEL |= (uint32_t)TZ_Channel;
    }
    else
    {
        PWMx->TZSEL &= ~(uint32_t)TZ_Channel;
    }
}

/**
  * @brief  Включение однократной обработки сигнала аварии.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_Channel Выбор каналов аварии.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_Channel.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_TZ_OneShotCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_Channel, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_CHANNEL(TZ_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        PWMx->TZSEL |= ((uint32_t)TZ_Channel << 8);
    }
    else
    {
        PWMx->TZSEL &= ~((uint32_t)TZ_Channel << 8);
    }
}

/**
  * @brief  Включение прерывания по сигналу аварии.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_ITSource Выбор источника прерывания.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_ITSource.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_TZ_ITCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITSource, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_SOURCE(TZ_ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        PWMx->TZEINT |= (uint32_t)TZ_ITSource;
    }
    else
    {
        PWMx->TZEINT &= ~(uint32_t)TZ_ITSource;
    }
}

/**
  * @brief  Чтение статуса флага прерывания от обработчика сигналов аварии выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_ITStatus Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_ITStatus.
  * @retval Status Статус прерывания. Если выбрано несколько флагов,
  *     то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus PWM_TZ_ITStatus(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITStatus)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_STATUS(TZ_ITStatus));

    if (PWMx->TZFLG & TZ_ITStatus)
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
  * @brief  Сброс флага прерывания от обработчика сигналов аварии выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_ITStatus Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_ITStatus.
  * @retval Нет
  */

void PWM_TZ_ITStatusClear(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITStatus)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_STATUS(TZ_ITStatus));

    PWMx->TZCLR = TZ_ITStatus;
}

/**
  * @brief  Чтение статуса запроса прерывания от сигнала аварии выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Status Статус запроса прерывания.
  */

FlagStatus PWM_TZ_ITPendStatus(NT_PWM_TypeDef* PWMx)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx->TZINTCLR_bit.TZINT)
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
  * @brief  Сброс запроса прерывания от сигнала аварии выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Нет
  */

void PWM_TZ_ITPendClear(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->TZINTCLR_bit.TZINT = 1;
}

/**
  * @brief  Программный вызов прерывания от сигнала аварии выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  TZ_ITSource Выбор источника прерывания.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_TZ_ITSource
  * @retval Нет
  */

void PWM_TZ_ITForce(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITSource)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_SOURCE(TZ_ITSource));

    PWMx->TZFRC = TZ_ITSource;
}

/**
  * @brief  Инициализирует блок "триггера событий" PWMx, согласно параметрам структуры PWM_ET_InitStruct.
  * @param  PWMx  Выбор модуля PWM, где x лежит в диапазоне 0-8
  * @param  PWM_ET_InitStruct Указатель на структуру типа @ref PWM_ET_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void PWM_ET_Init(NT_PWM_TypeDef* PWMx, PWM_ET_Init_TypeDef* PWM_ET_InitStruct)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_EVENT(PWM_ET_InitStruct->PWM_ET_Event_A));
    assert_param(IS_PWM_ET_PERIOD(PWM_ET_InitStruct->PWM_ET_Period_A));
    assert_param(IS_PWM_EVENT(PWM_ET_InitStruct->PWM_ET_Event_B));
    assert_param(IS_PWM_ET_PERIOD(PWM_ET_InitStruct->PWM_ET_Period_B));

    PWMx->ETSEL_bit.SOCASEL = (uint32_t)PWM_ET_InitStruct->PWM_ET_Event_A;
    PWMx->ETSEL_bit.SOCBSEL = (uint32_t)PWM_ET_InitStruct->PWM_ET_Event_B;

    PWMx->ETPS_bit.SOCAPRD = PWM_ET_InitStruct->PWM_ET_Period_A;
    PWMx->ETPS_bit.SOCBPRD = PWM_ET_InitStruct->PWM_ET_Period_B;
}

/**
  * @brief  Заполнение каждого члена структуры PWM_ET_InitStruct значениями по умолчанию.
  * @param  PWM_ET_InitStruct Указатель на структуру типа @ref PWM_ET_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void PWM_ET_StructInit(PWM_ET_Init_TypeDef* PWM_ET_InitStruct)
{
    PWM_ET_InitStruct->PWM_ET_Event_A = PWM_Event_None;
    PWM_ET_InitStruct->PWM_ET_Event_B = PWM_Event_None;
    PWM_ET_InitStruct->PWM_ET_Period_A = 0;
    PWM_ET_InitStruct->PWM_ET_Period_B = 0;
}

/**
  * @brief  Включение генерации строба запуска АЦП по событию.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  ET_Channel Выбор канала-источника.
  *     Параметр принимает любое значение из @ref PWM_ET_Channel_TypeDef.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_ET_Cmd(NT_PWM_TypeDef* PWMx, PWM_ET_Channel_TypeDef ET_Channel, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_ET_CHANNEL(ET_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (ET_Channel == PWM_ET_Channel_A)
    {
        PWMx->ETSEL_bit.SOCAEN = (uint32_t)State;
    }
    else /* if (ET_Channel == PWM_ET_Channel_B) */
    {
        PWMx->ETSEL_bit.SOCBEN = (uint32_t)State;
    }
}

/**
  * @brief  Получение текущего значения счетчика событий, приводящего к генерации события запуска АЦП.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval EventCount  Значение.
  */

uint32_t PWM_ET_GetEventCount(NT_PWM_TypeDef* PWMx, PWM_ET_Channel_TypeDef ET_Channel)
{
    uint32_t EventCount;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_ET_CHANNEL(ET_Channel));

    if (ET_Channel == PWM_ET_Channel_A)
    {
        EventCount = PWMx->ETPS_bit.SOCACNT;
    }
    else /* if (ET_Channel == PWM_ET_Channel_B) */
    {
        EventCount = PWMx->ETPS_bit.SOCBCNT;
    }

    return EventCount;
}

/**
  * @brief  Чтение статуса флага генерации события запуска АЦП выбранным блоком ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  ET_Status Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_ET_Status.
  * @retval Status Статус. Если выбрано несколько флагов,
  *     то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus PWM_ET_Status(NT_PWM_TypeDef* PWMx, uint32_t ET_Status)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(ET_Status));

    if (PWMx->ETFLG & ET_Status)
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
  * @brief  Сброс флага генерации события запуска АЦП выбранным блоком ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  ET_Status Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_ET_Status.
  * @retval Нет
  */

void PWM_ET_StatusClear(NT_PWM_TypeDef* PWMx, uint32_t ET_Status)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(ET_Status));

    PWMx->ETCLR = ET_Status;
}

/**
  * @brief  Программный вызов генерации события запуска АЦП выбранным блоком ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  ET_Status Выбор канала-источника.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_ET_Status
  * @retval Нет
  */

void PWM_ET_Force(NT_PWM_TypeDef* PWMx, uint32_t ET_Status)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(ET_Status));

    PWMx->ETFRC = ET_Status;
}

/**
  * @brief  Настройка поведения канала при поступлении события удержания.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  HD_ActionA  Выбор действия для канала A.
  *     Параметр может принимать любое значение из @ref PWM_HD_Action_TypeDef.
  * @param  HD_ActionB  Выбор действия для канала B.
  *     Параметр может принимать любое значение из @ref PWM_HD_Action_TypeDef.
  * @retval Нет
  */

void PWM_HD_ActionConfig(NT_PWM_TypeDef* PWMx, PWM_HD_Action_TypeDef HD_ActionA, PWM_HD_Action_TypeDef HD_ActionB)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HD_ACTION(HD_ActionA));
    assert_param(IS_PWM_HD_ACTION(HD_ActionB));

    PWMx->HDCTL_bit.HDA = (uint32_t)HD_ActionA;
    PWMx->HDCTL_bit.HDB = (uint32_t)HD_ActionB;
}

/**
  * @brief  Выбор каналов для генерации события удержания.
  * @param  PWMx  Выбор ШИМ, где x лежит в диапазоне 0-8.
  * @param  HD_Channel Выбор канала-источника.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_HD_Channel
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_HD_ChannelCmd(NT_PWM_TypeDef* PWMx, uint32_t HD_Channel, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HD_CHANNEL(HD_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        PWMx->HDSEL |= (uint32_t)HD_Channel;
    }
    else
    {
        PWMx->HDSEL &= ~(uint32_t)HD_Channel;
    }
}

/**
  * @brief  Включение циклической обработки сигнала удержания.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_HD_CycleCmd(NT_PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    PWMx->HDSEL_bit.CBC = (uint32_t)State;
}

/**
  * @brief  Включение однократной обработки сигнала удержания.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_HD_OneShotCmd(NT_PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    PWMx->HDSEL_bit.OSHT = (uint32_t)State;
}

/**
  * @brief  Включение прерывания по событию удержания.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  HD_ITSource Выбор источника прерывания.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_HD_ITSource.
  * @param  State  Выбор состояния.
  *     Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void PWM_HD_ITCmd(NT_PWM_TypeDef* PWMx, uint32_t HD_ITSource, FunctionalState State)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_SOURCE(HD_ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        PWMx->HDEINT |= (uint32_t)HD_ITSource;
    }
    else
    {
        PWMx->HDEINT &= ~(uint32_t)HD_ITSource;
    }
}

/**
  * @brief  Чтение статуса флага прерывания от обработчика событий удержания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  HD_ITStatus Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_HD_ITStatus.
  * @retval Status Статус прерывания. Если выбрано несколько флагов,
  *     то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus PWM_HD_ITStatus(NT_PWM_TypeDef* PWMx, uint32_t HD_ITStatus)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_STATUS(HD_ITStatus));

    if (PWMx->HDFLG & HD_ITStatus)
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
  * @brief  Сброс флага прерывания от обработчика событий удержания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  HD_ITStatus Выбор флагов.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_HD_ITStatus.
  * @retval Нет
  */

void PWM_HD_ITStatusClear(NT_PWM_TypeDef* PWMx, uint32_t HD_ITStatus)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_STATUS(HD_ITStatus));

    PWMx->HDCLR = HD_ITStatus;
}

/**
  * @brief  Чтение статуса запроса прерывания от обработчика событий удержания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Status Статус запроса прерывания.
  */

FlagStatus PWM_HD_ITPendStatus(NT_PWM_TypeDef* PWMx)
{
    FlagStatus Status;

    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWMx->HDINTCLR_bit.HDINT)
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
  * @brief  Сброс запроса прерывания от обработчика событий удержания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @retval Нет
  */

void PWM_HD_ITPendClear(NT_PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->HDINTCLR_bit.HDINT = 1;
}

/**
  * @brief  Программный вызов прерывания от обработчика событий удержания выбранного блока ШИМ.
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-8.
  * @param  HD_ITSource Выбор источника прерывания.
  *     Параметр принимает любую совокупность значений из @ref PWM_Exported_Constants_HD_ITSource
  * @retval Нет
  */

void PWM_HD_ITForce(NT_PWM_TypeDef* PWMx, uint32_t HD_ITSource)
{
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_SOURCE(HD_ITSource));

    PWMx->HDFRC = HD_ITSource;
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
