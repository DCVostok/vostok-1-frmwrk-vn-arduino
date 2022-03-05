/**
  ******************************************************************************
  * @file    plib035_uart.c
  *
  * @brief   Файл содержит реализацию функций для работы с UART
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
#include "plib035_uart.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup UART
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
  * @brief   Автоматический расчёт и установка делителей для нужной скорости передачи
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
void UART_AutoBaudConfig(UART_TypeDef* UARTx, uint32_t BaudRate)
{
    UART_Num_TypeDef UARTx_Num;
    uint32_t uart_clk_freq, int_div, frac_div;

    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0) {
        UARTx_Num = UART0_Num;
    } else {
        UARTx_Num = UART1_Num;
    }

    uart_clk_freq = RCU_GetUARTClkFreq(UARTx_Num);
    int_div = uart_clk_freq / (16 * BaudRate);
    frac_div = (uint32_t)((uart_clk_freq / (16.0f * BaudRate) - int_div) * 64.0f + 0.5f);
    UART_BaudDivConfig(UARTx, int_div, frac_div);
}

/**
  * @brief   Устанавливает все регистры UART значениями по умолчанию
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @retval  void
  */
void UART_DeInit(UART_TypeDef* UARTx)
{
    UART_Num_TypeDef UARTx_Num;

    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0) {
        UARTx_Num = UART0_Num;
    } else {
        UARTx_Num = UART1_Num;
    }

    RCU_UARTRstCmd(UARTx_Num, DISABLE);
    RCU_UARTRstCmd(UARTx_Num, ENABLE);
}

/**
  * @brief   Инициализирует UARTx согласно параметрам структуры InitStruct.
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   InitStruct  Указатель на структуру типа @ref UART_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void UART_Init(UART_TypeDef* UARTx, UART_Init_TypeDef* InitStruct)
{
    UART_AutoBaudConfig(UARTx, InitStruct->BaudRate);
    UART_DataWidthConfig(UARTx, InitStruct->DataWidth);
    UART_StopBitConfig(UARTx, InitStruct->StopBit);
    UART_ParityBitConfig(UARTx, InitStruct->ParityBit);
    UART_FIFOCmd(UARTx, InitStruct->FIFO);
    UART_TxCmd(UARTx, InitStruct->Tx);
    UART_RxCmd(UARTx, InitStruct->Rx);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию.
  * @param   InitStruct  Указатель на структуру типа @ref UART_Init_TypeDef,
  *                      которую необходимо проинициализировать.
  * @retval  void
  */
void UART_StructInit(UART_Init_TypeDef* InitStruct)
{
    InitStruct->BaudRate = 9600;
    InitStruct->DataWidth = UART_DataWidth_8;
    InitStruct->FIFO = DISABLE;
    InitStruct->ParityBit = UART_ParityBit_Disable;
    InitStruct->StopBit = UART_StopBit_1;
    InitStruct->Rx = DISABLE;
    InitStruct->Tx = DISABLE;
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
