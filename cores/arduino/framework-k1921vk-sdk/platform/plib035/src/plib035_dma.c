/**
  ******************************************************************************
  * @file    plib035_dma.c
  *
  * @brief   Файл содержит реализацию функций для работы с DMA
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
#include "plib035_dma.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** @defgroup DMA_Private Приватные данные
  * @{
  */

/** @defgroup DMA_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Деинициализация канала DMA
  * @param   ChannelStruct  Указатель на структуру типа @ref DMA_Channel_TypeDef,
  *                         которая содержит конфигурационную информацию канала
  * @retval  void
  */
void DMA_ChannelDeInit(DMA_Channel_TypeDef* ChannelStruct)
{
    ChannelStruct->SRC_DATA_END_PTR = 0;
    ChannelStruct->DST_DATA_END_PTR = 0;
    ChannelStruct->CHANNEL_CFG = 0;
}

/**
  * @brief   Инициализация канала DMA
  * @param   ChannelStruct Непосредственно сама структура канала
  * @param   ChannelInitStruct  Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *                             которая содержит конфигурационную информацию канала
  * @retval  void
  */
void DMA_ChannelInit(DMA_Channel_TypeDef* ChannelStruct, DMA_ChannelInit_TypeDef* ChannelInitStruct)
{
    assert_param(IS_DMA_MODE(ChannelInitStruct->Mode));
    assert_param(IS_DMA_ARBITRATION_RATE(ChannelInitStruct->ArbitrationRate));
    assert_param(IS_DMA_DATA_INC(ChannelInitStruct->DstDataInc));
    assert_param(IS_DMA_DATA_INC(ChannelInitStruct->SrcDataInc));
    assert_param(IS_DMA_DATA_SIZE(ChannelInitStruct->DstDataSize));
    assert_param(IS_DMA_DATA_SIZE(ChannelInitStruct->SrcDataSize));
    assert_param(IS_DMA_TRANSFERS_TOTAL(ChannelInitStruct->TransfersTotal));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->DstProtect.Bufferable));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->DstProtect.Cacheable));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->DstProtect.Priveleged));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->SrcProtect.Bufferable));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->SrcProtect.Cacheable));
    assert_param(IS_FUNCTIONAL_STATE(ChannelInitStruct->SrcProtect.Priveleged));

    /* источник */
    ChannelStruct->SRC_DATA_END_PTR = (uint32_t)ChannelInitStruct->SrcDataEndPtr;
    ChannelStruct->CHANNEL_CFG_bit.SRC_SIZE = ChannelInitStruct->SrcDataSize;
    ChannelStruct->CHANNEL_CFG_bit.SRC_INC = ChannelInitStruct->SrcDataInc;
    ChannelStruct->CHANNEL_CFG_bit.SRC_PROT_BUFF = ChannelInitStruct->SrcProtect.Bufferable;
    ChannelStruct->CHANNEL_CFG_bit.SRC_PROT_PRIV = ChannelInitStruct->SrcProtect.Priveleged;
    ChannelStruct->CHANNEL_CFG_bit.SRC_PROT_CACHE = ChannelInitStruct->SrcProtect.Cacheable;
    /* приемник */
    ChannelStruct->DST_DATA_END_PTR = (uint32_t)ChannelInitStruct->DstDataEndPtr;
    ChannelStruct->CHANNEL_CFG_bit.DST_SIZE = ChannelInitStruct->DstDataSize;
    ChannelStruct->CHANNEL_CFG_bit.DST_INC = ChannelInitStruct->DstDataInc;
    ChannelStruct->CHANNEL_CFG_bit.DST_PROT_BUFF = ChannelInitStruct->DstProtect.Bufferable;
    ChannelStruct->CHANNEL_CFG_bit.DST_PROT_PRIV = ChannelInitStruct->DstProtect.Priveleged;
    ChannelStruct->CHANNEL_CFG_bit.DST_PROT_CACHE = ChannelInitStruct->DstProtect.Cacheable;
    /* общее */
    ChannelStruct->CHANNEL_CFG_bit.NEXT_USEBURST = ChannelInitStruct->NextUseburst;
    ChannelStruct->CHANNEL_CFG_bit.R_POWER = ChannelInitStruct->ArbitrationRate;
    ChannelStruct->CHANNEL_CFG_bit.N_MINUS_1 = ChannelInitStruct->TransfersTotal - 1;
    ChannelStruct->CHANNEL_CFG_bit.CYCLE_CTRL = ChannelInitStruct->Mode;
}

/**
  * @brief   Заполнение каждого члена структуры ChannelInitStruct значениями по умолчанию
  * @param   ChannelInitStruct  Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *                             которую необходимо проинициализировать
  * @retval  void
  */
void DMA_ChannelStructInit(DMA_ChannelInit_TypeDef* ChannelInitStruct)
{
    /* источник */
    ChannelInitStruct->SrcDataEndPtr = (uint32_t*)0x00000000;
    ChannelInitStruct->SrcDataSize = DMA_DataSize_8;
    ChannelInitStruct->SrcDataInc = DMA_DataInc_Disable;
    ChannelInitStruct->SrcProtect.Bufferable = DISABLE;
    ChannelInitStruct->SrcProtect.Priveleged = DISABLE;
    ChannelInitStruct->SrcProtect.Cacheable = DISABLE;
    /* приемник */
    ChannelInitStruct->DstDataEndPtr = (uint32_t*)0x00000000;
    ChannelInitStruct->DstDataSize = DMA_DataSize_8;
    ChannelInitStruct->DstDataInc = DMA_DataInc_Disable;
    ChannelInitStruct->DstProtect.Bufferable = DISABLE;
    ChannelInitStruct->DstProtect.Priveleged = DISABLE;
    ChannelInitStruct->DstProtect.Cacheable = DISABLE;
    /* общее */
    ChannelInitStruct->NextUseburst = DISABLE;
    ChannelInitStruct->ArbitrationRate = DMA_ArbitrationRate_1;
    ChannelInitStruct->TransfersTotal = 1;
    ChannelInitStruct->Mode = DMA_Mode_Disable;
}

/**
  * @brief   Деинициализация контроллера DMA
  * @retval  void
  */
void DMA_DeInit()
{
    CLEAR_REG(DMA->CFG);
    CLEAR_REG(DMA->BASEPTR);
    WRITE_REG(DMA->ENCLR, DMA_Channel_All);
    WRITE_REG(DMA->PRIORITYCLR, DMA_Channel_All);
    WRITE_REG(DMA->PRIALTCLR, DMA_Channel_All);
    WRITE_REG(DMA->REQMASKCLR, DMA_Channel_All);
    WRITE_REG(DMA->USEBURSTCLR, DMA_Channel_All);
}

/**
  * @brief  Инициализация контроллера DMA
  * @attention  Прежде чем инициализировать DMA, необходимо проинициализоровать каналы
  *             с помощью @ref DMA_ChannelInit и сконфигурировать базовый адрес управляющей структуры
  *             с помощью @ref DMA_BasePtrConfig
  * @param   InitStruct  Указатель на структуру типа @ref DMA_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void DMA_Init(DMA_Init_TypeDef* InitStruct)
{
    DMA_ProtectConfig(&(InitStruct->CtrlProtect));
    DMA_UseBurstCmd(InitStruct->Channel, InitStruct->UseBurst);
    DMA_AltCtrlCmd(InitStruct->Channel, InitStruct->AltCtrl);
    DMA_HighPriorityCmd(InitStruct->Channel, InitStruct->HighPriority);
    DMA_ReqMaskCmd(InitStruct->Channel, InitStruct->ReqMask);
    DMA_ChannelEnableCmd(InitStruct->Channel, InitStruct->ChannelEnable);
}

/**
  * @brief   Заполнение каждого члена структуры DMA_InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref DMA_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void DMA_StructInit(DMA_Init_TypeDef* InitStruct)
{
    InitStruct->Channel = DMA_Channel_All;
    InitStruct->ChannelEnable = DISABLE;
    InitStruct->HighPriority = DISABLE;
    InitStruct->AltCtrl = DISABLE;
    InitStruct->ReqMask = DISABLE;
    InitStruct->UseBurst = DISABLE;
    InitStruct->CtrlProtect.Bufferable = DISABLE;
    InitStruct->CtrlProtect.Cacheable = DISABLE;
    InitStruct->CtrlProtect.Priveleged = DISABLE;
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
