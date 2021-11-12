/**
  ******************************************************************************
  * @file    niietcm4_uart.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с модулями UART.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    18.11.2015
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
#include "niietcm4_uart.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup UART
  * @brief Драйвер для приемопередатчиков UART.
  * @attention Драйвер позволяет управлять только внутренними настройками модулей UART.
  *            Соотвестствующие порты ввода-вывода, а также системное тактирование и сброс блоков необходимо настраивать отдельно.
  *            <br>@ref GPIO : @ref GPIO_Init_Deinit.
  *            <br>@ref RCC : @ref RCC_CLK_Config_UART, @ref RCC_RST_Config.
  * @{
  */ 

/** @defgroup UART_Private Приватные данные
  * @{
  */

/** @defgroup UART_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Разрешение работы выбранного UART.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void UART_Cmd(NT_UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    UARTx->CR_bit.UARTEN =  (uint32_t)State;
}

/**
  * @brief  Ручная настройка делителя для реализации необходимой скорости передачи.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  IntDiv Целая часть делителя.
  *   Параметр принимает любое значение из диапазона 1-65535.
  * @param  FracDiv Дробная часть делителя.
  *   Параметр принимает любое значение из диапазона 0-63. В случае, если IntDiv
  *   равен 65535, значение FracDiv может быть только 0.
  * @retval Нет
  */

void UART_BaudRateDivConfig(NT_UART_TypeDef* UARTx, uint32_t IntDiv, uint32_t FracDiv)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_INT_DIV(IntDiv));
    assert_param(IS_UART_FRAC_DIV(FracDiv));

    UARTx->IBRD = IntDiv;
    UARTx->FBRD = FracDiv;
}

/**
  * @brief  Включение разрыва линии.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void UART_Break(NT_UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    UARTx->LCR_H_bit.BRK =  (uint32_t)State;
}

/**
  * @brief  Устанавливает все регистры UART значениями по умолчанию.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3
  * @retval Нет
  */

void UART_DeInit(NT_UART_TypeDef* UARTx)
{
    RCC_PeriphRst_TypeDef UartRst;
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    if (UARTx == NT_UART0)
    {
        UartRst = RCC_PeriphRst_UART0;

    }
    else if (UARTx == NT_UART1)
    {
        UartRst = RCC_PeriphRst_UART1;

    }
    else if (UARTx == NT_UART2)
    {
        UartRst = RCC_PeriphRst_UART2;

    }
    else /* (UARTx == NT_UART3) */
    {
        UartRst = RCC_PeriphRst_UART3;

    }

    RCC_PeriphRstCmd(UartRst, DISABLE);
    RCC_PeriphRstCmd(UartRst, ENABLE);
}

/**
  * @brief  Инициализирует UARTx согласно параметрам структуры UART_InitStruct.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3
  * @param  UART_InitStruct Указатель на структуру типа @ref UART_Init_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Status Статус результата инициализации.
  *   Параметр принимает любое значение из @ref OperationStatus.
  */

OperationStatus UART_Init(NT_UART_TypeDef* UARTx, UART_Init_TypeDef* UART_InitStruct)
{
    OperationStatus Status = ERROR;
    uint32_t IntDiv, FracDiv;

    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DATA_WIDTH(UART_InitStruct->UART_DataWidth));
    assert_param(IS_FUNCTIONAL_STATE(UART_InitStruct->UART_FIFOEn));
    assert_param(IS_UART_FIFO_LEVEL(UART_InitStruct->UART_FIFOLevelRx));
    assert_param(IS_UART_FIFO_LEVEL(UART_InitStruct->UART_FIFOLevelTx));
    assert_param(IS_UART_PARITY_BIT(UART_InitStruct->UART_ParityBit));
    assert_param(IS_FUNCTIONAL_STATE(UART_InitStruct->UART_RxEn));
    assert_param(IS_UART_STOP_BIT(UART_InitStruct->UART_StopBit));
    assert_param(IS_FUNCTIONAL_STATE(UART_InitStruct->UART_TxEn));

    if (((UART_InitStruct->UART_ClkFreq*5)/3) < (UART_InitStruct->UART_BaudRate*16))
    {
        return Status;
    }
    IntDiv = UART_InitStruct->UART_ClkFreq/(16*UART_InitStruct->UART_BaudRate);
    FracDiv = (uint32_t)((UART_InitStruct->UART_ClkFreq/(16.0*UART_InitStruct->UART_BaudRate)-IntDiv)*64.0+0.5);
    UART_BaudRateDivConfig(UARTx, IntDiv, FracDiv);
    UARTx->LCR_H_bit.WLEN = (uint32_t)UART_InitStruct->UART_DataWidth;
    UARTx->LCR_H_bit.STP2 = (uint32_t)UART_InitStruct->UART_StopBit;
    if (UART_InitStruct->UART_ParityBit == UART_ParityBit_Odd)
    {
        UARTx->LCR_H_bit.SPS = 0;
        UARTx->LCR_H_bit.EPS = 0;
        UARTx->LCR_H_bit.PEN = 1;
    }
    else if (UART_InitStruct->UART_ParityBit == UART_ParityBit_Even)
    {
        UARTx->LCR_H_bit.SPS = 0;
        UARTx->LCR_H_bit.EPS = 1;
        UARTx->LCR_H_bit.PEN = 1;
    }
    else if (UART_InitStruct->UART_ParityBit == UART_ParityBit_High)
    {
        UARTx->LCR_H_bit.SPS = 1;
        UARTx->LCR_H_bit.EPS = 0;
        UARTx->LCR_H_bit.PEN = 1;
    }
    else if (UART_InitStruct->UART_ParityBit == UART_ParityBit_Low)
    {
        UARTx->LCR_H_bit.SPS = 1;
        UARTx->LCR_H_bit.EPS = 1;
        UARTx->LCR_H_bit.PEN = 1;
    }
    else /* UART_InitStruct->UART_ParityBit == UART_ParityBit_Disable */
    {
        UARTx->LCR_H_bit.PEN = 0;
    }
    UARTx->LCR_H_bit.FEN = (uint32_t)UART_InitStruct->UART_FIFOEn;
    UARTx->IFLS_bit.RXIFLSEL = (uint32_t)UART_InitStruct->UART_FIFOLevelRx;
    UARTx->IFLS_bit.TXIFLSEL = (uint32_t)UART_InitStruct->UART_FIFOLevelTx;
    UARTx->CR_bit.TXE = (uint32_t)UART_InitStruct->UART_TxEn;
    UARTx->CR_bit.RXE = (uint32_t)UART_InitStruct->UART_RxEn;

    Status = OK;
    return Status;
}

/**
  * @brief  Заполнение каждого члена структуры UART_InitStruct значениями по умолчанию.
  * @param  UART_InitStruct Указатель на структуру типа @ref UART_Init_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void UART_StructInit(UART_Init_TypeDef* UART_InitStruct)
{
    UART_InitStruct->UART_BaudRate = 9600;
    UART_InitStruct->UART_ClkFreq = EXT_OSC_VALUE;
    UART_InitStruct->UART_DataWidth = UART_DataWidth_8;
    UART_InitStruct->UART_FIFOLevelRx = UART_FIFOLevel_1_2;
    UART_InitStruct->UART_FIFOLevelTx = UART_FIFOLevel_1_2;
    UART_InitStruct->UART_FIFOEn = DISABLE;
    UART_InitStruct->UART_ParityBit = UART_ParityBit_Disable;
    UART_InitStruct->UART_StopBit = UART_StopBit_1;
    UART_InitStruct->UART_RxEn = ENABLE;
    UART_InitStruct->UART_TxEn = ENABLE;
}

/**
  * @brief  Передача слова данных.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  Data   Слово данных.
  * @retval Нет
  */

void UART_SendData(NT_UART_TypeDef* UARTx, uint32_t Data)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DATA(Data));

    /*
     * В младшем байте Data находятся данные для передачи в линию.
     * Все остальные биты при записи в регистр данных аппартно игнорируются.
     * Запись в регистр DR идет напрямую, а не через поле DR_bit.DATA,
     * т.к. запись в поле развернется в процедуру Чтение-Модификация-Запись,
     * которая может привести к ошибкам, когда происходит одновременный прием данных и передача.
     */
    UARTx->DR = Data;
}

/**
  * @brief  Прием слова данных.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @retval  Data  Слово данных.
  */

uint32_t UART_RecieveData(NT_UART_TypeDef* UARTx)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    return(UARTx->DR_bit.DATA);
}

/**
  * @brief  Запрос состояния выбранного флага.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_Flag  Выбор флагов.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_Flag.
  * @retval Status  Состояние флага. Если выбрано несколько флагов,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus UART_FlagStatus(NT_UART_TypeDef* UARTx, uint32_t UART_Flag)
{
    FlagStatus Status;
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(UART_Flag));

    if (UARTx->FR & UART_Flag)
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
  * @brief  Запрос состояния выбранного флага ошибки.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_Error  Выбор флагов ошибки.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_Error.
  * @retval Status  Состояние флага. Если выбрано несколько флагов,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus UART_ErrorStatus(NT_UART_TypeDef* UARTx, uint32_t UART_Error)
{
    FlagStatus Status;
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_ERROR(UART_Error));

    if (UARTx->RSR_ECR & UART_Error)
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
  * @brief  Очистка флагов ошибки.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_Error  Выбор флагов ошибки.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_Error.
  * @retval Нет
  */

void UART_ErrorStatusClear(NT_UART_TypeDef* UARTx, uint32_t UART_Error)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_ERROR(UART_Error));

    UARTx->RSR_ECR = UART_Error;
}


/**
  * @brief  Инициализирует модемный режим UART согласно параметрам структуры UART_ModemInitStruct.
  * @param  UART_ModemInitStruct Указатель на структуру типа @ref UART_ModemInit_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void UART_ModemConfig(NT_UART_TypeDef* UARTx, UART_ModemInit_TypeDef* UART_ModemInitStruct)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(UART_ModemInitStruct->UART_InvDTR));
    assert_param(IS_FUNCTIONAL_STATE(UART_ModemInitStruct->UART_InvRTS));
    assert_param(IS_FUNCTIONAL_STATE(UART_ModemInitStruct->UART_CTSEn));
    assert_param(IS_FUNCTIONAL_STATE(UART_ModemInitStruct->UART_RTSEn));

    UARTx->CR_bit.DTR = (uint32_t)UART_ModemInitStruct->UART_InvDTR;
    UARTx->CR_bit.RTS = (uint32_t)UART_ModemInitStruct->UART_InvRTS;
    UARTx->CR_bit.CTSEN = (uint32_t)UART_ModemInitStruct->UART_CTSEn;
    UARTx->CR_bit.RTSEN = (uint32_t)UART_ModemInitStruct->UART_RTSEn;
}

/**
  * @brief  Заполнение каждого члена структуры UART_ModemInitStruct значениями по умолчанию.
  * @param  UART_ModemInitStruct Указатель на структуру типа @ref UART_ModemInit_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void UART_ModemStructInit(UART_ModemInit_TypeDef* UART_ModemInitStruct)
{
    UART_ModemInitStruct->UART_InvDTR = DISABLE;
    UART_ModemInitStruct->UART_InvRTS = DISABLE;
    UART_ModemInitStruct->UART_CTSEn = DISABLE;
    UART_ModemInitStruct->UART_RTSEn = DISABLE;
}

/**
  * @brief  Выбор порог заполнения буфера приемника/передатчика, по достижению которого
  *   будет генерироваться прерывание.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_Dir  Выбор между буффером приемника и передатчика.
  *   Параметр принимает любое из значений @ref UART_Dir_Typedef.
  * @param  UART_FIFOLevel  Выбор порога.
  *   Параметр принимает любое значение из @ref UART_FIFOLevel_TypeDef.
  * @retval Нет
  */

void UART_ITFIFOLevelConfig(NT_UART_TypeDef* UARTx, UART_Dir_Typedef UART_Dir, UART_FIFOLevel_TypeDef UART_FIFOLevel)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DIR(UART_Dir));
    assert_param(IS_UART_FIFO_LEVEL(UART_FIFOLevel));

    if (UART_Dir == UART_Dir_Rx)
    {
        UARTx->IFLS_bit.RXIFLSEL = (uint32_t)UART_FIFOLevel;
    }
    else /* if (UART_Dir == UART_Dir_Tx) */
    {
        UARTx->IFLS_bit.TXIFLSEL = (uint32_t)UART_FIFOLevel;
    }
}

/**
  * @brief  Маскирование выбранных прерываний.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_ITSource  Выбор прерываний.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_ITSource.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void UART_ITCmd(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource,  FunctionalState State)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(UART_ITSource));

    if (State == ENABLE)
    {
        UARTx->IMSC |= (uint32_t)UART_ITSource;
    }
    else
    {
        UARTx->IMSC &= ~(uint32_t)UART_ITSource;
    }
}

/**
  * @brief  Запрос немаскированного состояния прерывания.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_ITSource  Выбор прерываний.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_ITSource.
  * @retval Status  Состояние флага. Если выбрано несколько прерываний,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus UART_ITRawStatus(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource)
{
    FlagStatus Status;
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(UART_ITSource));

    if (UARTx->RIS & UART_ITSource)
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
  * @brief  Запрос маскированного состояния прерывания.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_ITSource  Выбор прерываний.
  *   Параметр принимает любое значение из @ref UART_Exported_Constants_ITSource.
  * @retval Status  Состояние флага. Если выбрано несколько прерываний,
  *   то результат соответсвует логическому ИЛИ их состояний.
  */

FlagStatus UART_ITMaskedStatus(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource)
{
    FlagStatus Status;
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(UART_ITSource));

    if (UARTx->MIS & UART_ITSource)
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
  * @brief  Сброс флагов состояния выбранных прерываний.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_ITSource  Выбор прерываний.
  *   Параметр принимает любую совокупность значений из @ref UART_Exported_Constants_ITSource.
  * @retval Нет
  */

void UART_ITStatusClear(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(UART_ITSource));

    UARTx->ICR = (uint32_t)UART_ITSource;
}

/**
  * @brief  Управление блокированием запросов DMA от приемника в случае возникновения
  *   прерывания по ошибке.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void UART_DMABlkOnErrCmd(NT_UART_TypeDef* UARTx,  FunctionalState State)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    UARTx->DMACR_bit.DMAONERR = (uint32_t)State;
}

/**
  * @brief  Разрешение формирования запросов DMA для обслуживания буфера передатчика/приемника
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  UART_Dir  Выбор направления (прием или передача) для конфигурации.
  *   Параметр принимает любое значение из @ref UART_Dir_Typedef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void UART_DMACmd(NT_UART_TypeDef* UARTx, UART_Dir_Typedef UART_Dir,  FunctionalState State)
{
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DIR(UART_Dir));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (UART_Dir == UART_Dir_Rx)
    {
        UARTx->DMACR_bit.RXDMAE = (uint32_t)State;
    }
    else /* if (UART_Dir == UART_Dir_Tx) */
    {
        UARTx->DMACR_bit.TXDMAE = (uint32_t)State;
    }
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
