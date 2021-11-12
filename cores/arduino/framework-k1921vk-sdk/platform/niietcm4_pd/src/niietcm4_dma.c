/**
  ******************************************************************************
  * @file    niietcm4_dma.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с DMA.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    10.11.2015
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
#include "niietcm4_dma.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup DMA
  * @brief Драйвер для работы с контроллером прямого доступа памяти.
  *
  * @attention Для работы драйвер требует наличия размещенной во внутреннем ОЗУ
  *   структуры типа @ref DMA_ConfigData_TypeDef - структуры первичных и альтернативных
  *   управляющих данных каналов. Размер этой стркутуры составляет 1кБ и она должна быть
  *   обязательно выравнена по 1024 байтам в адресном пространстве.
  *
  *   Общий вид процесса инициализации:
  *   - создаем структуру типа @ref DMA_ConfigData_TypeDef;
  *   - передаем адрес этой структуры контроллеру DMA - @ref DMA_BasePtrConfig;
  *   - инициализируем необходимые каналы (@ref DMA_Exported_Functions_Init_Channel);
  *   - инициализируем контроллер DMA (@ref DMA_Exported_Functions_Init или через
  *     отдельные функции @ref DMA_Exported_Functions_Config;
  *   - DMA готов к работе.
  *
  *   Более подробно инициализация и использование DMA показаны в приложенных к драйверу примерах.
  * @{
  */ 

/** @defgroup DMA_Private Приватные данные
  * @{
  */

/** @defgroup DMA_Private_Defines Приватные константы
  * @{
  */

/** @defgroup DMA_regs_reset_define Начальные значения регистров
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Деинициализация канала DMA.
  * @param  DMA_Channel Указатель на структуру типа @ref DMA_Channel_TypeDef,
  *         которая содержит конфигурационную информацию канала.
  * @retval Нет
  */

void DMA_ChannelDeInit(DMA_Channel_TypeDef* DMA_Channel)
{
    DMA_Channel->SRC_DATA_END = 0;
    DMA_Channel->DST_DATA_END = 0;
    DMA_Channel->CHANNEL_CFG = 0;
}

/**
  * @brief  Инициализация канала DMA.
  * @param  DMA_Channel Непосредственно сама структура канала.
  * @param  DMA_ChannelInitStruct Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *         которая содержит конфигурационную информацию канала.
  * @retval Нет
  */

void DMA_ChannelInit(DMA_Channel_TypeDef* DMA_Channel, DMA_ChannelInit_TypeDef* DMA_ChannelInitStruct)
{
    assert_param(IS_DMA_MODE(DMA_ChannelInitStruct->DMA_Mode));
    assert_param(IS_DMA_ARBITRATION_RATE(DMA_ChannelInitStruct->DMA_ArbitrationRate));
    assert_param(IS_DMA_DATA_INC(DMA_ChannelInitStruct->DMA_DstDataInc));
    assert_param(IS_DMA_DATA_INC(DMA_ChannelInitStruct->DMA_SrcDataInc));
    assert_param(IS_DMA_DATA_SIZE(DMA_ChannelInitStruct->DMA_DstDataSize));
    assert_param(IS_DMA_DATA_SIZE(DMA_ChannelInitStruct->DMA_SrcDataSize));
    assert_param(IS_DMA_TRANSFERS_TOTAL(DMA_ChannelInitStruct->DMA_TransfersTotal));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_DstProtect.BUFFERABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_DstProtect.CACHEABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_DstProtect.PRIVELGED));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_SrcProtect.BUFFERABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_SrcProtect.CACHEABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_ChannelInitStruct->DMA_SrcProtect.PRIVELGED));

    /* источник */
    DMA_Channel->SRC_DATA_END = (uint32_t)DMA_ChannelInitStruct->DMA_SrcDataEndPtr;
    DMA_Channel->CHANNEL_CFG_bit.SRC_SIZE = DMA_ChannelInitStruct->DMA_SrcDataSize;
    DMA_Channel->CHANNEL_CFG_bit.SRC_INC = DMA_ChannelInitStruct->DMA_SrcDataInc;
    DMA_Channel->CHANNEL_CFG_bit.SRC_PROT_BUFFERABLE = DMA_ChannelInitStruct->DMA_SrcProtect.BUFFERABLE;
    DMA_Channel->CHANNEL_CFG_bit.SRC_PROT_PRIVILEGED = DMA_ChannelInitStruct->DMA_SrcProtect.PRIVELGED;
    DMA_Channel->CHANNEL_CFG_bit.SRC_PROT_CACHEABLE = DMA_ChannelInitStruct->DMA_SrcProtect.CACHEABLE;
    /* приемник */
    DMA_Channel->DST_DATA_END = (uint32_t)DMA_ChannelInitStruct->DMA_DstDataEndPtr;
    DMA_Channel->CHANNEL_CFG_bit.DST_SIZE = DMA_ChannelInitStruct->DMA_DstDataSize;
    DMA_Channel->CHANNEL_CFG_bit.DST_INC = DMA_ChannelInitStruct->DMA_DstDataInc;
    DMA_Channel->CHANNEL_CFG_bit.DST_PROT_BUFFERABLE = DMA_ChannelInitStruct->DMA_DstProtect.BUFFERABLE;
    DMA_Channel->CHANNEL_CFG_bit.DST_PROT_PRIVILEGED = DMA_ChannelInitStruct->DMA_DstProtect.PRIVELGED;
    DMA_Channel->CHANNEL_CFG_bit.DST_PROT_CACHEABLE = DMA_ChannelInitStruct->DMA_DstProtect.CACHEABLE;
    /* общее */
    DMA_Channel->CHANNEL_CFG_bit.NEXT_USEBURST = DMA_ChannelInitStruct->DMA_NextUseburst;
    DMA_Channel->CHANNEL_CFG_bit.R_POWER = DMA_ChannelInitStruct->DMA_ArbitrationRate;
    DMA_Channel->CHANNEL_CFG_bit.N_MINUS_1 = DMA_ChannelInitStruct->DMA_TransfersTotal - 1;
    DMA_Channel->CHANNEL_CFG_bit.CYCLE_CTRL = DMA_ChannelInitStruct->DMA_Mode;
}

/**
  * @brief  Заполнение каждого члена структуры DMA_ChannelInitStruct значениями по умолчанию.
  * @param  DMA_ChannelInitStruct Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void DMA_ChannelStructInit(DMA_ChannelInit_TypeDef* DMA_ChannelInitStruct)
{
    /* источник */
    DMA_ChannelInitStruct->DMA_SrcDataEndPtr = (uint32_t *)0x00000000;
    DMA_ChannelInitStruct->DMA_SrcDataSize = DMA_DataSize_8;
    DMA_ChannelInitStruct->DMA_SrcDataInc = DMA_DataInc_Disable;
    DMA_ChannelInitStruct->DMA_SrcProtect.BUFFERABLE = DISABLE;
    DMA_ChannelInitStruct->DMA_SrcProtect.PRIVELGED = DISABLE;
    DMA_ChannelInitStruct->DMA_SrcProtect.CACHEABLE = DISABLE;
    /* приемник */
    DMA_ChannelInitStruct->DMA_DstDataEndPtr = (uint32_t *)0x00000000;
    DMA_ChannelInitStruct->DMA_DstDataSize = DMA_DataSize_8;
    DMA_ChannelInitStruct->DMA_DstDataInc = DMA_DataInc_Disable;
    DMA_ChannelInitStruct->DMA_DstProtect.BUFFERABLE = DISABLE;
    DMA_ChannelInitStruct->DMA_DstProtect.PRIVELGED = DISABLE;
    DMA_ChannelInitStruct->DMA_DstProtect.CACHEABLE = DISABLE;
    /* общее */
    DMA_ChannelInitStruct->DMA_NextUseburst = DISABLE;
    DMA_ChannelInitStruct->DMA_ArbitrationRate = DMA_ArbitrationRate_1;
    DMA_ChannelInitStruct->DMA_TransfersTotal = 1;
    DMA_ChannelInitStruct->DMA_Mode = DMA_Mode_Disable;
}

/**
  * @brief  Деинициализация контроллера DMA.
  * @retval Нет
  */

void DMA_DeInit()
{
    NT_DMA->CFG = 0;
    NT_DMA->CTRL_BASE_PTR = 0;
    NT_DMA->CHNL_ENABLE_CLR = 0xFFFFFFFF;
    NT_DMA->CHNL_PRIORITY_CLR = 0xFFFFFFFF;
    NT_DMA->CHNL_PRI_ALT_CLR = 0xFFFFFFFF;
    NT_DMA->CHNL_REQ_MASK_CLR = 0xFFFFFFFF;
    NT_DMA->CHNL_USEBURST_CLR = 0xFFFFFFFF;
}

/**
  * @brief  Инициализация контроллера DMA.
  * @attention Прежде чем инициализировать DMA, необходимо проинициализоровать каналы
  * с помощью @ref DMA_ChannelInit и сконфигурировать базовый адрес управляющей структуры
  * с помощью @ref DMA_BasePtrConfig.
  * @param  DMA_InitStruct Указатель на структуру типа @ref DMA_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void DMA_Init(DMA_Init_TypeDef* DMA_InitStruct)
{
    DMA_ProtectionConfig(&(DMA_InitStruct->DMA_Protection));
    DMA_UseBurstCmd(DMA_InitStruct->DMA_Channel, DMA_InitStruct->DMA_UseBurst);
    DMA_PrmAltCmd(DMA_InitStruct->DMA_Channel,  DMA_InitStruct->DMA_PrmAlt);
    DMA_HighPriorityCmd(DMA_InitStruct->DMA_Channel,  DMA_InitStruct->DMA_HighPriority);
    DMA_ReqMaskCmd(DMA_InitStruct->DMA_Channel,  DMA_InitStruct->DMA_ReqMask);
    DMA_ChannelEnableCmd(DMA_InitStruct->DMA_Channel,  DMA_InitStruct->DMA_ChannelEnable);
}

/**
  * @brief  Заполнение каждого члена структуры DMA_InitStruct значениями по умолчанию.
  * @param  DMA_InitStruct Указатель на структуру типа @ref DMA_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void DMA_StructInit(DMA_Init_TypeDef* DMA_InitStruct)
{
    DMA_InitStruct->DMA_Channel = 0xFFFFFF;
    DMA_InitStruct->DMA_ChannelEnable = DISABLE;
    DMA_InitStruct->DMA_HighPriority = DISABLE;
    DMA_InitStruct->DMA_PrmAlt = DISABLE;
    DMA_InitStruct->DMA_ReqMask = DISABLE;
    DMA_InitStruct->DMA_UseBurst = DISABLE;
    DMA_InitStruct->DMA_Protection.BUFFERABLE = DISABLE;
    DMA_InitStruct->DMA_Protection.CACHEABLE = DISABLE;
    DMA_InitStruct->DMA_Protection.PRIVELGED = DISABLE;
}

/**
  * @brief  Установка базового адреса управляющих каналов.
  * @param  BasePtr  Значение базового адреса.
  * @retval Нет
  */

void DMA_BasePtrConfig(uint32_t BasePtr)
{
    NT_DMA->CTRL_BASE_PTR = BasePtr;
}

/**
  * @brief  Управление защитой шины при обращении DMA к управляющим данным.
  * @param  DMA_Protection  Структура, содержащая конфигурацию защиты.
  *   Параметр принимает структуру типа @ref DMA_Protect_TypeDef.
  * @retval Нет
  */

void DMA_ProtectionConfig(DMA_Protect_TypeDef *DMA_Protection)
{
    assert_param(IS_FUNCTIONAL_STATE(DMA_Protection->BUFFERABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_Protection->CACHEABLE));
    assert_param(IS_FUNCTIONAL_STATE(DMA_Protection->PRIVELGED));

    if (DMA_Protection->PRIVELGED == ENABLE)
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL |= (1<<0);
    }
    else /* DMA_Protection->PRIVELGED == DISABLE */
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL &= ~(1<<0);
    }

    if (DMA_Protection->BUFFERABLE == ENABLE)
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL |= (1<<1);
    }
    else /* DMA_Protection->BUFFERABLE == DISABLE */
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL &= ~(1<<1);
    }

    if (DMA_Protection->CACHEABLE == ENABLE)
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL |= (1<<2);
    }
    else /* DMA_Protection->CACHEABLE == DISABLE */
    {
        NT_DMA->CFG_bit.CHNL_PROT_CTRL &= ~(1<<2);
    }
}

/**
  * @brief  Разрешения работы контроллера DMA.
  * @attention Прежде чем включать DMA, необходимо проинициализоровать каналы
  * с помощью @ref DMA_ChannelInit и сконфигурировать контроллер DMA через функцию
  * инициализации @ref DMA_Init или вручную - @ref DMA_Exported_Functions_Config.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_MasterEnableCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CFG_bit.MASTER_EN = 1;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CFG_bit.MASTER_EN = 0;
    }
}

/**
  * @brief  Программный запрос на осуществление передач DMA по выбранным каналам.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @retval Нет
  */

void DMA_SWRequestCmd(uint32_t DMA_Channel)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));

    NT_DMA->CHNL_SW_REQUEST = DMA_Channel;
}

/**
  * @brief  Установка пакетного обмена каналов DMA.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_UseBurstCmd(uint32_t DMA_Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CHNL_USEBURST_SET = DMA_Channel;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CHNL_USEBURST_CLR = DMA_Channel;
    }
}

/**
  * @brief  Маскирование каналов DMA.
  * @attention По маскированным каналам игнорируются запросы на передачи.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_ReqMaskCmd(uint32_t DMA_Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CHNL_REQ_MASK_SET = DMA_Channel;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CHNL_REQ_MASK_CLR = DMA_Channel;
    }
}

/**
  * @brief  Активация каналов DMA.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_ChannelEnableCmd(uint32_t DMA_Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CHNL_ENABLE_SET = DMA_Channel;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CHNL_ENABLE_CLR = DMA_Channel;
    }
}

/**
  * @brief  Установка первичной/альтернативной управляющей структуры каналов DMA.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_PrmAltCmd(uint32_t DMA_Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CHNL_PRI_ALT_SET = DMA_Channel;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CHNL_PRI_ALT_CLR = DMA_Channel;
    }
}

/**
  * @brief  Установка высокого приоритета каналов DMA.
  * @param  DMA_Channel  Выбор канала.
  *   Параметр принимает любую совокупность масок из @ref DMA_Exported_Defines_Channels_Num.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void DMA_HighPriorityCmd(uint32_t DMA_Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(DMA_Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_DMA->CHNL_PRIORITY_SET = DMA_Channel;
    }
    else /* State == DISABLE */
    {
        NT_DMA->CHNL_PRIORITY_CLR = DMA_Channel;
    }
}

/**
  * @brief  Доступ к текущему конечного автомата контроллера DMA.
  * @retval State Текущее состояние конечного автомата.
  */

DMA_State_TypeDef DMA_StateStatus()
{
    DMA_State_TypeDef State;

    State = (DMA_State_TypeDef)NT_DMA->STATUS_bit.STATE;

    return State;
}

/**
  * @brief  Состояние контроллера DMA.
  * @retval Status Текущее состояние контроллера DMA.
  */

FunctionalState DMA_MasterEnableStatus()
{
    FunctionalState Status;

    if (NT_DMA->STATUS_bit.MASTER_EN)
    {
        Status = ENABLE;
    }
    else
    {
        Status = DISABLE;
    }

    return Status;
}

/**
  * @brief  Показывает поддерживает ли канал одиночные SREQ запросы.
  * @retval Status Одно из значений @ref FunctionalState:
  *                 - ENABLE - поддерживаются SREQ (как и блочные BREQ);
  *                 - DISABLE - поддерживаются только блочные запросы BREQ.
  */

FunctionalState DMA_WaitOnReqStatus(uint32_t DMA_Channel)
{
    FunctionalState Status;

    assert_param(IS_GET_DMA_CHANNEL(DMA_Channel));

    if (NT_DMA->WAITONREQ_STATUS & DMA_Channel)
    {
        Status = ENABLE;
    }
    else
    {
        Status = DISABLE;
    }

    return Status;
}

/**
  * @brief  Показывает наличие ошибки на шине.
  * @retval Status Одно из значений @ref OperationStatus:
  *                 - OK - ошибок не было;
  *                 - ERROR - произошла ошибка.
  */

OperationStatus DMA_ErrorStatus()
{
    OperationStatus Status;

    if (NT_DMA->ERR_CLR)
    {
        Status = ERROR;
    }
    else
    {
        Status = OK;
    }

    return Status;
}

/**
  * @brief  Сброс флага ошибки на шине.
  * @retval Нет
  */

void DMA_ClearErrorStatus()
{
    NT_DMA->ERR_CLR = 1;
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
