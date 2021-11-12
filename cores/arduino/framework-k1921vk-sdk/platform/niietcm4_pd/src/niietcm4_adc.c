/**
  ******************************************************************************
  * @file    niietcm4_adc.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с модулями АЦП, 
  *          секвенсорами, цифровыми компараторами.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    10.12.2015
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
  * <h2><center>&copy; 2015 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_adc.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup ADC 
  * @brief Драйвер для модулей АЦП, связанных  с ними секвенсоров, а также
  *   цифровых компараторов.
  *
  * @attention Драйвер позволяет управлять только внутренними настройками модулей АЦП.
  *            Системное тактирование необходимо настраивать отдельно
  *            с помощью модуля @ref RCC :
  *            <br>- @ref RCC_CLK_Config_ADC.
  *
  * @attention Для корректного функционирования АЦП, перед началом его работы необходимо записать записать во все поля выбора канала,
  *  подключаемого к цифровому компаратору, запрещенное значение 0x18-0x1F.
  *  С точки зрения драйвера, это проще всего сделать, вызвав функцию  @ref ADC_DC_DeInit() для
  *  каждого компаратора.
  *
  * @attention Драйвер по умолчанию устанавливает отличную от нуля задержку перезапуска модулей АЦП секвенсорами.
  *   Минимальная рекомендуемая величина задержки равна 2. Если используется один секвенсор, либо несколько,
  *   запускающиеся только синхронно - данную задержку можно убрать. Если используется больше одного
  *   секвенсора и начинают измерения они асинхронно, то каждый из них должен иметь задержку как минимум
  *   в 2 такта между перезапусками.
  *
  * @attention Настоятельно рекомендуется использовать только один секвенсор, либо несколько секвенсоров,
  *   но работающих только синхронно (один источник запуска, одинаковые задержки перезапуска).
  *
  *  Общий вид процесса инициализации:
  *  - для всех компараторов вызываем функцию деинициализации @ref ADC_DC_DeInit(),
  *    чтобы записать в регистр выбора канала, подключаемого к компаратору, запрещенное значение;
  *  - (опционально) инициализируем цифровые компараторы (@ref ADC_Exported_Functions_Init >> @ref ADC_Exported_Functions_Init_DC);
  *  - инициализируем необходимые модули АЦП (@ref ADC_Exported_Functions_Init >> @ref ADC_Exported_Functions_Init_ADC);
  *  - инициализируем нужное количество секвенсоров (@ref ADC_Exported_Functions_Init >> @ref ADC_Exported_Functions_Init_SEQ);
  *  - (опционально) настравиваем и вкючаем функцию работы с DMA для секвенсоров с помощью @ref ADC_Exported_Functions_DMA;
  *  - (опционально) настраиваем и включаем прерывания цифровых компараторов и секвенсоров через @ref ADC_Exported_Functions_Int;
  *  - включаем секвенсоры;
  *  - АЦП готов выполнять измерения по запросам.
  *
  *  Более подробно инициализация и использование АЦП показаны в приложенных к драйверу примерах.
  * @{
  */ 

/** @defgroup ADC_Private Приватные данные
  * @{
  */

/** @defgroup ADC_Private_Defines Приватные константы
  * @{
  */

/** @defgroup ADC_regs_reset_define Начальные значения регистров
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Включение модуля АЦП.
  * @param  ADC_Module  Выбор АЦП.
  *   Параметр принимает любое значение из @ref ADC_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_Cmd(ADC_Module_TypeDef ADC_Module, FunctionalState State)
{
    assert_param(IS_ADC_MODULE(ADC_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_ADC->PP_bit[(uint32_t)ADC_Module].ENA = (uint32_t)State;
}

/**
  * @brief  Устанавливает все регистры модуля АЦП значениями по умолчанию.
  * @param  ADC_Module  Выбор модуля АЦП.
  *   Параметр принимает любое значение из @ref ADC_Module_TypeDef.
  * @retval Нет
  */

void ADC_DeInit(ADC_Module_TypeDef ADC_Module)
{
    assert_param(IS_ADC_MODULE(ADC_Module));

    if (ADC_Module == ADC_Module_0)
    {
        NT_ADC->SPC0_bit.PHASE0 = 0;
        NT_ADC->SAC_bit.AVG0 = 0;
    }
    else if (ADC_Module == ADC_Module_1)
    {
        NT_ADC->SPC0_bit.PHASE1 = 0;
        NT_ADC->SAC_bit.AVG1 = 0;
    }
    else if (ADC_Module == ADC_Module_2)
    {
        NT_ADC->SPC1_bit.PHASE2 = 0;
        NT_ADC->SAC_bit.AVG2 = 0;
    }
    else if (ADC_Module == ADC_Module_3)
    {
        NT_ADC->SPC1_bit.PHASE3 = 0;
        NT_ADC->SAC_bit.AVG3 = 0;
    }
    else if (ADC_Module == ADC_Module_4)
    {
        NT_ADC->SPC2_bit.PHASE4 = 0;
        NT_ADC->SAC_bit.AVG4 = 0;
    }
    else if (ADC_Module == ADC_Module_5)
    {
        NT_ADC->SPC2_bit.PHASE5 = 0;
        NT_ADC->SAC_bit.AVG5 = 0;
    }
    else if (ADC_Module == ADC_Module_6)
    {
        NT_ADC->SPC3_bit.PHASE6 = 0;
        NT_ADC->SAC_bit.AVG6 = 0;
    }
    else if (ADC_Module == ADC_Module_7)
    {
        NT_ADC->SPC3_bit.PHASE7 = 0;
        NT_ADC->SAC_bit.AVG7 = 0;
    }
    else if (ADC_Module == ADC_Module_8)
    {
        NT_ADC->SPC4_bit.PHASE8 = 0;
        NT_ADC->RICNT_bit.AVG8 = 0;
    }
    else if (ADC_Module == ADC_Module_9)
    {
        NT_ADC->SPC4_bit.PHASE9 = 0;
        NT_ADC->RICNT_bit.AVG9 = 0;
    }
    else if (ADC_Module == ADC_Module_10)
    {
        NT_ADC->SPC5_bit.PHASE10 = 0;
        NT_ADC->RICNT_bit.AVG10 = 0;
    }
    else if (ADC_Module == ADC_Module_11)
    {
        NT_ADC->SPC5_bit.PHASE11 = 0;
        NT_ADC->RICNT_bit.AVG11 = 0;
    }

    NT_ADC->PP_bit[(uint32_t)ADC_Module].OM = 0;
}

/**
  * @brief  Инициализирует выбранный модуль АЦП согласно параметрам структуры ADC_InitStruct.
  * @param  ADC_Module  Выбор модуля АЦП.
  *   Параметр принимает любое значение из @ref ADC_Module_TypeDef.
  * @param  ADC_InitStruct Указатель на структуру типа @ref ADC_Init_TypeDef,
  *   которая содержит конфигурационную информацию.
  */

void ADC_Init(ADC_Module_TypeDef ADC_Module, ADC_Init_TypeDef* ADC_InitStruct)
{
    assert_param(IS_ADC_MODULE(ADC_Module));
    assert_param(IS_ADC_RESOLUTION(ADC_InitStruct->ADC_Resolution));
    assert_param(IS_ADC_MEASURE(ADC_InitStruct->ADC_Measure_A));
    assert_param(IS_ADC_MEASURE(ADC_InitStruct->ADC_Measure_B));
    assert_param(IS_ADC_PHASE(ADC_InitStruct->ADC_Phase));
    assert_param(IS_ADC_AVERAGE(ADC_InitStruct->ADC_Average));
    assert_param(IS_ADC_MODE(ADC_InitStruct->ADC_Mode));

    if (ADC_Module == ADC_Module_0)
    {
        NT_ADC->SPC0_bit.PHASE0 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG0 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_1)
    {
        NT_ADC->SPC0_bit.PHASE1 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG1 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_2)
    {
        NT_ADC->SPC1_bit.PHASE2 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG2 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_3)
    {
        NT_ADC->SPC1_bit.PHASE3 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG3 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_4)
    {
        NT_ADC->SPC2_bit.PHASE4 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG4 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_5)
    {
        NT_ADC->SPC2_bit.PHASE5 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG5 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_6)
    {
        NT_ADC->SPC3_bit.PHASE6 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG6 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_7)
    {
        NT_ADC->SPC3_bit.PHASE7 = ADC_InitStruct->ADC_Phase;
        NT_ADC->SAC_bit.AVG7 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_8)
    {
        NT_ADC->SPC4_bit.PHASE8 = ADC_InitStruct->ADC_Phase;
        NT_ADC->RICNT_bit.AVG8 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_9)
    {
        NT_ADC->SPC4_bit.PHASE9 = ADC_InitStruct->ADC_Phase;
        NT_ADC->RICNT_bit.AVG9 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_10)
    {
        NT_ADC->SPC5_bit.PHASE10 = ADC_InitStruct->ADC_Phase;
        NT_ADC->RICNT_bit.AVG10 = ADC_InitStruct->ADC_Average;
    }
    else if (ADC_Module == ADC_Module_11)
    {
        NT_ADC->SPC5_bit.PHASE11 = ADC_InitStruct->ADC_Phase;
        NT_ADC->RICNT_bit.AVG11 = ADC_InitStruct->ADC_Average;
    }

    NT_ADC->PP_bit[(uint32_t)ADC_Module].OM = (((uint32_t)ADC_InitStruct->ADC_Measure_B)<<6)  |
                                              (((uint32_t)ADC_InitStruct->ADC_Measure_A)<<4)  |
                                              (((uint32_t)ADC_InitStruct->ADC_Resolution)<<3) |
                                              (((uint32_t)ADC_InitStruct->ADC_Mode)<<0);
}

/**
  * @brief  Заполнение каждого члена структуры ADC_InitStruct значениями по умолчанию.
  * @param  ADC_InitStruct Указатель на структуру типа @ref ADC_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void ADC_StructInit(ADC_Init_TypeDef* ADC_InitStruct)
{
    ADC_InitStruct->ADC_Resolution = ADC_Resolution_12bit;
    ADC_InitStruct->ADC_Measure_A = ADC_Measure_Single;
    ADC_InitStruct->ADC_Measure_B = ADC_Measure_Single;
    ADC_InitStruct->ADC_Phase = 0;
    ADC_InitStruct->ADC_Average = ADC_Average_Disable;
    ADC_InitStruct->ADC_Mode = ADC_Mode_Powerdown;
}

/**
  * @brief  Устанавливает все регистры выбранного цифрового компаратора значениями по умолчанию.
  * @param  ADC_DC_Module  Выбор модуля цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval Нет
  */

void ADC_DC_DeInit(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    NT_ADC->DCCMP_bit[(uint32_t)ADC_DC_Module].COMP0 = 0;
    NT_ADC->DCCMP_bit[(uint32_t)ADC_DC_Module].COMP1 = 0;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CHNL = 0x1F; // т.к. 0 = выбран нулевой канал, то нужно перевести в запрещенное состояние
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CTC = 0;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CTM = 0;
}

/**
  * @brief  Инициализирует выбранный модуль цифрового компаратора согласно параметрам структуры ADC_DC_InitStruct.
  * @param  ADC_DC_Module  Выбор модуля цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  ADC_DC_InitStruct Указатель на структуру типа @ref ADC_DC_Init_TypeDef,
  *   которая содержит конфигурационную информацию.
  */

void ADC_DC_Init(ADC_DC_Module_TypeDef ADC_DC_Module, ADC_DC_Init_TypeDef* ADC_DC_InitStruct)
{
    assert_param(IS_ADC_DC(ADC_DC_Module));
    assert_param(IS_ADC_DC_THRESHOLD(ADC_DC_InitStruct->ADC_DC_ThresholdLow));
    assert_param(IS_ADC_DC_THRESHOLD(ADC_DC_InitStruct->ADC_DC_ThresholdHigh));
    assert_param(IS_ADC_DC_CHANNEL(ADC_DC_InitStruct->ADC_DC_Channel));
    assert_param(IS_ADC_DC_MODE(ADC_DC_InitStruct->ADC_DC_Mode));
    assert_param(IS_ADC_DC_CONDITION(ADC_DC_InitStruct->ADC_DC_Condition));

    NT_ADC->DCCMP_bit[(uint32_t)ADC_DC_Module].COMP0 = ADC_DC_InitStruct->ADC_DC_ThresholdLow;
    NT_ADC->DCCMP_bit[(uint32_t)ADC_DC_Module].COMP1 = ADC_DC_InitStruct->ADC_DC_ThresholdHigh;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CHNL = (uint32_t)ADC_DC_InitStruct->ADC_DC_Channel;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CTC = (uint32_t)ADC_DC_InitStruct->ADC_DC_Condition;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CTM = (uint32_t)ADC_DC_InitStruct->ADC_DC_Mode;
}

/**
  * @brief  Заполнение каждого члена структуры ADC_DC_InitStruct значениями по умолчанию.
  * @param  ADC_DC_InitStruct Указатель на структуру типа @ref ADC_DC_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void ADC_DC_StructInit(ADC_DC_Init_TypeDef* ADC_DC_InitStruct)
{
    ADC_DC_InitStruct->ADC_DC_ThresholdLow = 0;
    ADC_DC_InitStruct->ADC_DC_ThresholdHigh = 0;
    ADC_DC_InitStruct->ADC_DC_Channel = ADC_DC_Channel_None;
    ADC_DC_InitStruct->ADC_DC_Mode = ADC_DC_Mode_Single;
    ADC_DC_InitStruct->ADC_DC_Condition = ADC_DC_Condition_Low;
}

/**
  * @brief  Устанавливает все регистры выбранного секвенсора значениями по умолчанию.
  * @param  ADC_SEQ_Module  Выбор модуля цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval Нет
  */

void ADC_SEQ_DeInit(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (ADC_SEQ_Module == ADC_SEQ_Module_0)
    {
        NT_ADC->EMUX_bit.EM0 = 0;
        NT_ADC->PSSI_bit.SS0 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_1)
    {
        NT_ADC->EMUX_bit.EM1 = 0;
        NT_ADC->PSSI_bit.SS1 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_2)
    {
        NT_ADC->EMUX_bit.EM2 = 0;
        NT_ADC->PSSI_bit.SS2 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_3)
    {
        NT_ADC->EMUX_bit.EM3 = 0;
        NT_ADC->PSSI_bit.SS3 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_4)
    {
        NT_ADC->EMUX_bit.EM4 = 0;
        NT_ADC->PSSI_bit.SS4 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_5)
    {
        NT_ADC->EMUX_bit.EM5 = 0;
        NT_ADC->PSSI_bit.SS5 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_6)
    {
        NT_ADC->EMUX_bit.EM6 = 0;
        NT_ADC->PSSI_bit.SS6 = 0;
    }
    else if (ADC_SEQ_Module == ADC_SEQ_Module_7)
    {
        NT_ADC->EMUX_bit.EM7 = 0;
        NT_ADC->PSSI_bit.SS7 = 0;
    }

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].CTL_bit.RCNT = 0;
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].TMR_bit.TMR = 2;
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].DCP = 0;
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].MUX = 0;
}

/**
  * @brief  Инициализирует выбранный секвенсор согласно параметрам структуры ADC_SEQ_InitStruct.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  ADC_SEQ_InitStruct Указатель на структуру типа @ref ADC_SEQ_Init_TypeDef,
  *   которая содержит конфигурационную информацию.
  * @retval Нет
  */

void ADC_SEQ_Init(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, ADC_SEQ_Init_TypeDef* ADC_SEQ_InitStruct)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_ADC_SEQ_START_EVENT(ADC_SEQ_InitStruct->ADC_SEQ_StartEvent));
    assert_param(IS_FUNCTIONAL_STATE(ADC_SEQ_InitStruct->ADC_SEQ_SWReqEn));
    assert_param(IS_ADC_CHANNEL(ADC_SEQ_InitStruct->ADC_Channels));
    assert_param(IS_ADC_SEQ_CONVERSION_COUNT(ADC_SEQ_InitStruct->ADC_SEQ_ConversionCount));
    assert_param(IS_ADC_SEQ_CONVERSION_DELAY(ADC_SEQ_InitStruct->ADC_SEQ_ConversionDelay));
    assert_param(IS_ADC_DC(ADC_SEQ_InitStruct->ADC_SEQ_DC));

    NT_ADC->EMUX &= ~(0xF<<((uint32_t)ADC_SEQ_Module*4));
    NT_ADC->EMUX |= ((uint32_t)ADC_SEQ_InitStruct->ADC_SEQ_StartEvent)<<((uint32_t)ADC_SEQ_Module*4);

    if (ADC_SEQ_InitStruct->ADC_SEQ_SWReqEn == ENABLE)
    {
        NT_ADC->PSSI |= 1<<((uint32_t)ADC_SEQ_Module);
    }
    else
    {
        NT_ADC->PSSI &= ~(1<<((uint32_t)ADC_SEQ_Module));
    }

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].CTL_bit.RCNT = (uint32_t)(ADC_SEQ_InitStruct->ADC_SEQ_ConversionCount-1);
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].TMR_bit.TMR = (uint32_t)ADC_SEQ_InitStruct->ADC_SEQ_ConversionDelay;
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].DCP = (uint32_t)ADC_SEQ_InitStruct->ADC_SEQ_DC;
    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].MUX = (uint32_t)ADC_SEQ_InitStruct->ADC_Channels;
}

/**
  * @brief  Заполнение каждого члена структуры ADC_SEQ_InitStruct значениями по умолчанию.
  * @param  ADC_SEQ_InitStruct Указатель на структуру типа @ref ADC_SEQ_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void ADC_SEQ_StructInit(ADC_SEQ_Init_TypeDef* ADC_SEQ_InitStruct)
{
    ADC_SEQ_InitStruct->ADC_SEQ_StartEvent = ADC_SEQ_StartEvent_SWReq;
    ADC_SEQ_InitStruct->ADC_SEQ_SWReqEn = ENABLE;
    ADC_SEQ_InitStruct->ADC_Channels = ADC_Channel_None;
    ADC_SEQ_InitStruct->ADC_SEQ_ConversionCount = 1;
    ADC_SEQ_InitStruct->ADC_SEQ_ConversionDelay = 2;
    ADC_SEQ_InitStruct->ADC_SEQ_DC = ADC_DC_None;
}

/**
  * @brief  Конфигуририрует выбранный секвенсор для работы с DMA.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  ADC_SEQ_FIFOLevel  Количество результатов измерений записанных в буфер секвенсора, по достижению которого вызывается DMA.
  *   Параметр принимает любое значение из @ref ADC_SEQ_FIFOLevel_TypeDef.
  * @retval Нет
  */

void ADC_SEQ_DMAConfig(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, ADC_SEQ_FIFOLevel_TypeDef ADC_SEQ_FIFOLevel)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_ADC_SEQ_FIFO_LEVEL(ADC_SEQ_FIFOLevel));

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].CTL_bit.WMARK = (uint32_t)ADC_SEQ_FIFOLevel;
}

/**
  * @brief  Включает для выбранного секвенсора генерирование запросов DMA.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void ADC_SEQ_DMACmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].CTL_bit.DMAEN = (uint32_t)State;
}

/**
  * @brief  Проверка статуса ошибки, когда при наличии двух обрабатываемых запросов DMA
  *   от выбранного секвенсора, пришел третий запрос, который не может быть обработан.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval FlagStatus Текущие состояние флага.
  */

FlagStatus ADC_SEQ_DMAErrorStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (NT_ADC->OSTAT & (1<<((uint32_t)ADC_SEQ_Module + 16))) // в первых 16 - флаги заполнения буфера секвенсора
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
  * @brief  Сброс статуса ошибки DMA.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval нет
  */

void ADC_SEQ_DMAErrorStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    NT_ADC->OSTAT = 1<<((uint32_t)ADC_SEQ_Module + 16);
}

/**
  * @brief  Разрешает компаратору генерировать сигнал прерывания.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_DC_ITGenCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CIE = (uint32_t)State;
}

/**
  * @brief  Маскирование сигнала прерывания цифрового компаратора.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_DC_ITMaskCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_ADC->IM |= 1<<((uint32_t)ADC_DC_Module + 8); // первые 8 - это секвенсоры
    }
    else /* if (State == DISABLE) */
    {
        NT_ADC->IM &= ~(1<<((uint32_t)ADC_DC_Module + 8)); // первые 8 - это секвенсоры
    }
}

/**
  * @brief  Включение прерывания компаратора и одновременное маскирование сигнала этого прерывания.
  *   При этом, эти же действия можно выполнить путем ручного вызовова соответствующих функций:
  *   @ref ADC_DC_ITGenCmd и @ref ADC_DC_ITMaskCmd.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_DC_ITCmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    //разрешение/запрещение генерации сигнала прерывания компаратору
    ADC_DC_ITGenCmd(ADC_DC_Module, State);

    //маскирование сигнала прерывания для попадания внутрь NVIC
    ADC_DC_ITMaskCmd(ADC_DC_Module, State);
}

/**
  * @brief  Настройка условия вызова прерывания цифрового компаратора. Условия вызова
  *   прерывания и условия срабатывания выходного триггера компаратора могут не совпадать.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  ADC_DC_Mode  Режим срабатывания компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Mode_TypeDef.
  * @param  ADC_DC_Condition  Условие срабатывания компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Condition_TypeDef.
  * @retval нет
  */

void ADC_DC_ITConfig(ADC_DC_Module_TypeDef ADC_DC_Module, ADC_DC_Mode_TypeDef ADC_DC_Mode, ADC_DC_Condition_TypeDef ADC_DC_Condition)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));
    assert_param(IS_ADC_DC_MODE(ADC_DC_Mode));
    assert_param(IS_ADC_DC_CONDITION(ADC_DC_Condition));

    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CIC = (uint32_t)ADC_DC_Condition;
    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CIM = (uint32_t)ADC_DC_Mode;
}

/**
  * @brief  Проверка флагов немаскированных прерываний.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_DC_ITRawStatus(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    if (NT_ADC->RIS & (1<<((uint32_t)ADC_DC_Module + 8)))
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
  * @brief  Проверка флагов маскированных прерываний.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_DC_ITMaskedStatus(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    if (NT_ADC->ISC & (1<<((uint32_t)ADC_DC_Module + 8)))
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
  * @brief  Общий сброс флагов прерывания цифрового компаратора.
  *   Сбрасывает как маскированные, так и немаскированные флаги.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval нет
  */

void ADC_DC_ITStatusClear(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    NT_ADC->ISC = 1<<((uint32_t)ADC_DC_Module + 8); // первые 8 - это секвенсоры
}

/**
  * @brief  Включение прерывания секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_SEQ_ITCmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_ADC->IM |= 1<<((uint32_t)ADC_SEQ_Module); // первые 8 - это секвенсоры
    }
    else /* if (State == DISABLE) */
    {
        NT_ADC->IM &= ~(1<<((uint32_t)ADC_SEQ_Module)); // первые 8 - это секвенсоры
    }
}

/**
  * @brief  Настройка вызова прерывания секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  ADC_SEQ_ITRate  Значение количества перезапусков модулей АЦП секвенсором
  *   после которого генерируется прерывание.
  *   Параметр принимает любое значение из диапазона 1 - 256.
  * @param  ADC_SEQ_ITCountSEQRst  Разрешение сброса счетчика прерываний по запуску секвенсора.
  *   Если запретить, то счетчик можно будет сбрасывать только программно через @ref ADC_SEQ_ITCountRst.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_SEQ_ITConfig(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, uint32_t ADC_SEQ_ITRate, FunctionalState ADC_SEQ_ITCountSEQRst)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_ADC_SEQ_IT_RATE(ADC_SEQ_ITRate));
    assert_param(IS_FUNCTIONAL_STATE(ADC_SEQ_ITCountSEQRst));

    if (ADC_SEQ_ITCountSEQRst == ENABLE)
    {
         NT_ADC->RICNT |= 1<<((uint32_t)ADC_SEQ_Module + 16); // первые 16 - это усреднители 8-11
    }
    else /* if (State == DISABLE) */
    {
        NT_ADC->RICNT &= ~(1<<((uint32_t)ADC_SEQ_Module + 16)); // первые 16 - это усреднители 8-11
    }

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].CTL_bit.ICNT = ADC_SEQ_ITRate - 1;
}

/**
  * @brief  Текущее значение счетчика измерений, который используется для генерации прерывания секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval ITCount
  */

uint32_t ADC_SEQ_GetITCount(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    uint32_t ITCount;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    ITCount = NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].OP_bit.ICNT;

    return ITCount;
}

/**
  * @brief  Сброс счетчика прерываний секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval нет
  */

void ADC_SEQ_ITCountRst(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].OP_bit.ICNT = 1;
}

/**
  * @brief  Проверка флагов немаскированных прерываний.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_SEQ_ITRawStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (NT_ADC->RIS & (1<<((uint32_t)ADC_SEQ_Module)))
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
  * @brief  Проверка флагов маскированных прерываний.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_SEQ_ITMaskedStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (NT_ADC->ISC & (1<<((uint32_t)ADC_SEQ_Module)))
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
  * @brief  Общий сброс флагов прерывания секвенсора. Сбрасывает как маскированные, так и немаскированные флаги.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval нет
  */

void ADC_SEQ_ITStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    NT_ADC->ISC = 1<<((uint32_t)ADC_SEQ_Module);
}

/**
  * @brief  Включение секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_SEQ_Cmd(ADC_SEQ_Module_TypeDef ADC_SEQ_Module, FunctionalState State)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
         NT_ADC->ACTSS |= 1<<((uint32_t)ADC_SEQ_Module);
    }
    else /* if (State == DISABLE) */
    {
        NT_ADC->ACTSS &= ~(1<<((uint32_t)ADC_SEQ_Module));
    }
}

/**
  * @brief  Программный запуск измерений всех разрешенных секвенсоров.
  * @retval нет
  */

void ADC_SEQ_SWReq()
{
    NT_ADC->PSSI_bit.GSYNC = 1;
}

/**
  * @brief  Получение результата измерений из буффера секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval Data Результат измерения.
  */

uint32_t ADC_SEQ_GetFIFOData(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    uint32_t Data;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    Data = NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].FIFO_bit.DATA;

    return Data;
}

/**
  * @brief  Получение количества измерений, проведенных модулями АЦП с момента запуска секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval Data Результат измерения.
  */

uint32_t ADC_SEQ_GetConversionCount(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    uint32_t Count;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    Count = NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].OP_bit.RCNT;

    return Count;
}

/**
  * @brief  Получение количества измерений, сохраненных в буфере секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval Data Результат измерения.
  */

uint32_t ADC_SEQ_GetFIFOLoad(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    uint32_t Load;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    Load = NT_ADC->SEQ[(uint32_t)ADC_SEQ_Module].FSTAT_bit.FLOAD;

    return Load;
}

/**
  * @brief  Проверка флага заполнения буффера секвенсора.
  *   Если флаг установлен, то значит что буффер заполнен и все последующие записи
  *   в буффер будут блокироваться до появления как минимум одной свободной ячейки.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_SEQ_FIFOFullStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (NT_ADC->OSTAT & (1<<((uint32_t)ADC_SEQ_Module)))
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
  * @brief  Cброс флага заполнения буффера секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval нет
  */

void ADC_SEQ_FIFOFullStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    NT_ADC->OSTAT = 1<<((uint32_t)ADC_SEQ_Module);
}

/**
  * @brief  Проверка флага пустоты буффера секвенсора.
  *  Флаг установлен когда буфер полностью пуст.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval FlagStatus Текущее состояние флага.
  */

FlagStatus ADC_SEQ_FIFOEmptyStatus(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    if (NT_ADC->USTAT & (1<<((uint32_t)ADC_SEQ_Module)))
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
  * @brief  Cброс флага пустоты буффера секвенсора.
  * @param  ADC_SEQ_Module  Выбор секвенсора.
  *   Параметр принимает любое значение из @ref ADC_SEQ_Module_TypeDef.
  * @retval нет
  */

void ADC_SEQ_FIFOEmptyStatusClear(ADC_SEQ_Module_TypeDef ADC_SEQ_Module)
{
    assert_param(IS_ADC_SEQ_MODULE(ADC_SEQ_Module));

    NT_ADC->USTAT = 1<<((uint32_t)ADC_SEQ_Module);
}

/**
  * @brief  Включение выходного триггера цифрового компаратора.
  * @param  ADC_DC_Module  Выбор компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval нет
  */

void ADC_DC_Cmd(ADC_DC_Module_TypeDef ADC_DC_Module, FunctionalState State)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));
    assert_param(IS_FUNCTIONAL_STATE(State));

    NT_ADC->DCCTL_bit[(uint32_t)ADC_DC_Module].CTE = (uint32_t)State;
}

/**
  * @brief  Значение результата измерения, которое последним использовалось
  *   компаратором при проверке на соответствие условиям.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval Data Результат измерения.
  */

uint32_t ADC_DC_GetLastData(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    uint32_t Value;

    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    Value = NT_ADC->DCVAL_bit[(uint32_t)ADC_DC_Module].VAL;

    return Value;
}

/**
  * @brief  Проверка состояния выходного триггера компаратора.
  * @param  ADC_DC_Module  Выбор компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval FlagStatus Текущее состояние триггера.
  */

FlagStatus ADC_DC_TrigStatus(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    FlagStatus Status;

    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    if (NT_ADC->DCRTC & (1<<((uint32_t)ADC_DC_Module)))
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
  * @brief  Cброс выходного триггера цифрового компаратора.
  * @attention Одновременно со сбросом триггеров 0 и 1 компаратора сбрасываются
  *   триггеры 10 и 11 компаратора соответсвенно. То же самое справедливо и для обратного случая.
  *   Это проиходит аппаратно и программными методами не обходится.
  * @param  ADC_DC_Module  Выбор цифрового компаратора.
  *   Параметр принимает любое значение из @ref ADC_DC_Module_TypeDef.
  * @retval нет
  */

void ADC_DC_TrigStatusClear(ADC_DC_Module_TypeDef ADC_DC_Module)
{
    assert_param(IS_ADC_DC_MODULE(ADC_DC_Module));

    // чтобы сбросить 0 и 1 компараторы, нужно писать в биты 10 и 11 компараторов соответственно
    if ((ADC_DC_Module == ADC_DC_Module_0) |
        (ADC_DC_Module == ADC_DC_Module_1))
    {
        ADC_DC_Module = (ADC_DC_Module_TypeDef)((uint32_t)ADC_DC_Module + 10);
    }

    NT_ADC->DCRTC = 1<<((uint32_t)ADC_DC_Module + 8);
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

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
