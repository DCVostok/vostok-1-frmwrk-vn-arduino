/**
  ******************************************************************************
  * @file    plib035_uart.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          UART, а также сопутствующие макроопределения и перечисления
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB035_UART_H
#define __PLIB035_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup UART
  * @brief Драйвер для работы с UART
  * @{
  */

/** @defgroup UART_Exported_Defines Константы
  * @{
  */

/** @defgroup UART_ITSource_Define Источники прерываний UART
  * @{
  */

#define UART_ITSource_RxFIFOLevel UART_IMSC_RXIM_Msk    /*!< Порог переполнения буфера приемника */
#define UART_ITSource_TxFIFOLevel UART_IMSC_TXIM_Msk    /*!< Порог опустошения буфера передатчика */
#define UART_ITSource_RecieveTimeout UART_IMSC_RTIM_Msk /*!< Таймаут приема данных */
#define UART_ITSource_ErrorFrame UART_IMSC_FERIM_Msk    /*!< Ошибка в структуре кадра */
#define UART_ITSource_ErrorParity UART_IMSC_PERIM_Msk   /*!< Ошибка контроля четности */
#define UART_ITSource_ErrorBreak UART_IMSC_BERIM_Msk    /*!< Разрыв линии */
#define UART_ITSource_ErrorOverflow UART_IMSC_OERIM_Msk /*!< Переполнение буффера приемника */
#define UART_ITSource_TransmitDone UART_IMSC_TDIM_Msk   /*!< Окончание передачи в линии */
#define UART_ITSource_All (UART_IMSC_RXIM_Msk |  \
                           UART_IMSC_TXIM_Msk |  \
                           UART_IMSC_RTIM_Msk |  \
                           UART_IMSC_FEIM_Msk | \
                           UART_IMSC_PEIM_Msk | \
                           UART_IMSC_BEIM_Msk | \
                           UART_IMSC_OEIM_Msk | \
                           UART_IMSC_TDIM_Msk) /*!< Все источники выбраны */

#define IS_UART_IT_SOURCE(VALUE) (((VALUE) & ~UART_ITSource_All) == 0)

/**
   * @}
   */

/** @defgroup UART_Flag_Define Флаги работы UART
  * @{
  */

#define UART_Flag_Busy UART_FR_BUSY_Msk        /*!< Флаг занятости блока UART */
#define UART_Flag_RxFIFOEmpty UART_FR_RXFE_Msk /*!< Флаг пустоты буффера приемника */
#define UART_Flag_TxFIFOFull UART_FR_TXFF_Msk  /*!< Флаг заполнения буффера передатчика */
#define UART_Flag_RxFIFOFull UART_FR_RXFF_Msk  /*!< Флаг заполнения буффера приемника */
#define UART_Flag_TxFIFOEmpty UART_FR_TXFE_Msk /*!< Флаг пустоты буффера передатчика */
#define UART_Flag_All (UART_FR_BUSY_Msk | \
                       UART_FR_RXFE_Msk | \
                       UART_FR_TXFF_Msk | \
                       UART_FR_RXFF_Msk | \
                       UART_FR_TXFE_Msk) /*!< Все флаги выбраны */

#define IS_UART_FLAG(VALUE) (((VALUE) & ~UART_Flag_All) == 0)

/**
  * @}
  */

/** @defgroup UART_Error_Define Ошибки приемника UART
   * @{
   */

#define UART_Error_Frame UART_RSR_FE_Msk    /*!< Флаг ошибки в структуре кадра */
#define UART_Error_Parity UART_RSR_PE_Msk   /*!< Флаг ошибки контроля четности */
#define UART_Error_Break UART_RSR_BE_Msk    /*!< Флаг разрыва линии */
#define UART_Error_Overflow UART_RSR_OE_Msk /*!< Флаг переполнения буффера приемника */
#define UART_Error_All (UART_RSR_FE_Msk | \
                        UART_RSR_PE_Msk | \
                        UART_RSR_BE_Msk | \
                        UART_RSR_OE_Msk) /*!< Все флаги ошибок выбраны */

#define IS_UART_ERROR(VALUE) (((VALUE) & ~UART_Error_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup UART_Exported_Types Типы
  * @{
  */

#define IS_UART_INT_DIV(VALUE) (((VALUE) > 0) && ((VALUE) < 0x10000))
#define IS_UART_FRAC_DIV(VALUE) ((VALUE) < 0x40)
#define IS_UART_DATA(VALUE) ((VALUE) < 0x100)

/**
  * @brief  Выбор режима передачи стопового бита
  */
typedef enum {
    UART_StopBit_1, /*!< Один стоповый бит */
    UART_StopBit_2  /*!< Два стоповых бита */
} UART_StopBit_TypeDef;
#define IS_UART_STOP_BIT(VALUE) (((VALUE) == UART_StopBit_1) || \
                                 ((VALUE) == UART_StopBit_2))

/**
  * @brief  Выбор режима бита четности
  */
typedef enum {
    UART_ParityBit_Disable = 0,                                                    /*!< Не передается, не проверяется */
    UART_ParityBit_Odd = UART_LCRH_PEN_Msk,                                        /*!< Проверка нечетности данных */
    UART_ParityBit_Even = UART_LCRH_PEN_Msk | UART_LCRH_EPS_Msk,                   /*!< Проверка четности данных */
    UART_ParityBit_High = UART_LCRH_PEN_Msk | UART_LCRH_SPS_Msk,                   /*!< Бит четности постоянно равен единице */
    UART_ParityBit_Low = UART_LCRH_PEN_Msk | UART_LCRH_SPS_Msk | UART_LCRH_EPS_Msk /*!< Бит четности постоянно равен нулю */
} UART_ParityBit_TypeDef;
#define IS_UART_PARITY_BIT(VALUE) (((VALUE) == UART_ParityBit_Disable) || \
                                   ((VALUE) == UART_ParityBit_Odd) ||     \
                                   ((VALUE) == UART_ParityBit_Even) ||    \
                                   ((VALUE) == UART_ParityBit_High) ||    \
                                   ((VALUE) == UART_ParityBit_Low))

/**
  * @brief  Количество передаваемых/принимаемых информационных бит
  */
typedef enum {
    UART_DataWidth_5 = UART_LCRH_WLEN_5bit, /*!< Длина информационного слова 5 бит */
    UART_DataWidth_6 = UART_LCRH_WLEN_6bit, /*!< Длина информационного слова 6 бит */
    UART_DataWidth_7 = UART_LCRH_WLEN_7bit, /*!< Длина информационного слова 7 бит */
    UART_DataWidth_8 = UART_LCRH_WLEN_8bit  /*!< Длина информационного слова 8 бит */
} UART_DataWidth_TypeDef;
#define IS_UART_DATA_WIDTH(VALUE) (((VALUE) == UART_DataWidth_5) || \
                                   ((VALUE) == UART_DataWidth_6) || \
                                   ((VALUE) == UART_DataWidth_7) || \
                                   ((VALUE) == UART_DataWidth_8))

/**
  * @brief  Порог заполнения/опустошения буфера приемника/передатчика, по достижению которого
  *   будет генерироваться прерывание
  */
typedef enum {
    UART_FIFOLevel_1_8 = UART_IFLS_TXIFLSEL_Lvl18, /*!< Заполнение/опустошение FIFO на 1/8 */
    UART_FIFOLevel_1_4 = UART_IFLS_TXIFLSEL_Lvl14, /*!< Заполнение/опустошение FIFO на 1/4 */
    UART_FIFOLevel_1_2 = UART_IFLS_TXIFLSEL_Lvl12, /*!< Заполнение/опустошение FIFO на 1/2 */
    UART_FIFOLevel_3_4 = UART_IFLS_TXIFLSEL_Lvl34, /*!< Заполнение/опустошение FIFO на 3/4 */
    UART_FIFOLevel_7_8 = UART_IFLS_TXIFLSEL_Lvl78  /*!< Заполнение/опустошение FIFO на 7/8 */
} UART_FIFOLevel_TypeDef;
#define IS_UART_FIFO_LEVEL(VALUE) (((VALUE) == UART_FIFOLevel_1_8) || \
                                   ((VALUE) == UART_FIFOLevel_1_4) || \
                                   ((VALUE) == UART_FIFOLevel_1_2) || \
                                   ((VALUE) == UART_FIFOLevel_3_4) || \
                                   ((VALUE) == UART_FIFOLevel_7_8))

/**
  * @brief  Структура инициализации UART
  */

typedef struct
{
    UART_StopBit_TypeDef StopBit;     /*!< Выбор режима передачи стопового бита */
    UART_ParityBit_TypeDef ParityBit; /*!< Выбор режима бита четности */
    UART_DataWidth_TypeDef DataWidth; /*!< Количество передаваемых/принимаемых информационных бит */
    uint32_t BaudRate;                /*!< Желаемая скорость передачи данных в бит/с */
    FunctionalState FIFO;             /*!< Разрешение режима FIFO буфера приемника и передатчика */
    FunctionalState Rx;               /*!< Разрешение приема */
    FunctionalState Tx;               /*!< Разрешение передачи */
} UART_Init_TypeDef;

/**
 * @}
 */

/** @defgroup UART_Exported_Functions Функции
  * @{
  */

void UART_AutoBaudConfig(UART_TypeDef* UARTx, uint32_t BaudRate);

/**
  * @brief   Разрешение работы выбранного UART
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_Cmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->CR_bit.UARTEN, State);
}

/**
  * @brief   Настройка ширины слова данных
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   DataWidth  Значение разрядности слова
  * @retval  void
  */
__STATIC_INLINE void UART_DataWidthConfig(UART_TypeDef* UARTx, UART_DataWidth_TypeDef DataWidth)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_DATA_WIDTH(DataWidth));

    WRITE_REG(UARTx->LCRH_bit.WLEN, DataWidth);
}

/**
  * @brief   Настройка количества стоп-бит
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   StopBit  Количество стоп-бит
  * @retval  void
  */
__STATIC_INLINE void UART_StopBitConfig(UART_TypeDef* UARTx, UART_StopBit_TypeDef StopBit)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_STOP_BIT(StopBit));

    WRITE_REG(UARTx->LCRH_bit.STP2, StopBit);
}

/**
  * @brief   Настройка режима бита четности
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   ParityBit  Режим
  * @retval  void
  */
__STATIC_INLINE void UART_ParityBitConfig(UART_TypeDef* UARTx, UART_ParityBit_TypeDef ParityBit)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_PARITY_BIT(ParityBit));

    MODIFY_REG(UARTx->LCRH, UART_LCRH_PEN_Msk | UART_LCRH_SPS_Msk | UART_LCRH_EPS_Msk, ParityBit);
}

/**
  * @brief   Ручная настройка делителя для реализации необходимой скорости передачи
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   IntDiv  Целая часть делителя.
  *                  Параметр принимает любое значение из диапазона 1-65535.
  * @param   FracDiv  Дробная часть делителя.
  *                   Параметр принимает любое значение из диапазона 0-63. В случае, если IntDiv
  *                   равен 65535, значение FracDiv может быть только 0.
  * @retval  void
  */
__STATIC_INLINE void UART_BaudDivConfig(UART_TypeDef* UARTx, uint32_t IntDiv, uint32_t FracDiv)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_INT_DIV(IntDiv));
    assert_param(IS_UART_FRAC_DIV(FracDiv));

    WRITE_REG(UARTx->IBRD, IntDiv);
    WRITE_REG(UARTx->FBRD, FracDiv);
}

/**
  * @brief   Включение разрыва линии
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_BreakCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->LCRH_bit.BRK, State);
}

/**
  * @brief   Включение FIFO
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_FIFOCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->LCRH_bit.FEN, State);
}

/**
  * @brief   Разрешение приема
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_RxCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->CR_bit.RXE, State);
}

/**
  * @brief   Разрешение передачи
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_TxCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->CR_bit.TXE, State);
}

/** @defgroup UART_Init_Deinit Инициализация и деинициализация
  * @{
  */

void UART_DeInit(UART_TypeDef* UARTx);
void UART_Init(UART_TypeDef* UARTx, UART_Init_TypeDef* InitStruct);
void UART_StructInit(UART_Init_TypeDef* InitStruct);

/**
  * @}
  */

/** @defgroup UART_SendRecieve Прием и передача
  * @{
  */

/**
  * @brief   Передача слова данных
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   Data   Слово данных (биты 7-0)
  * @retval  void
  */
__STATIC_INLINE void UART_SendData(UART_TypeDef* UARTx, uint32_t Data)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_DATA(Data));

    WRITE_REG(UARTx->DR, Data);
}

/**
  * @brief   Прием слова данных
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @retval  Val  Слово данных
  */
__STATIC_INLINE uint32_t UART_RecieveData(UART_TypeDef* UARTx)
{
    assert_param(IS_UART_PERIPH(UARTx));

    return READ_REG(UARTx->DR_bit.DATA);
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений UART_Flag_x из @ref UART_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus UART_FlagStatus(UART_TypeDef* UARTx, uint32_t Flag)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(Flag));

    return (FlagStatus)READ_BIT(UARTx->FR, Flag);
}

/**
  * @brief   Запрос состояния выбранного флага ошибки
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   Error  Выбор флагов ошибки.
  *                 Параметр принимает любую совокупность значений UART_Error_x из @ref UART_Error_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus UART_ErrorStatus(UART_TypeDef* UARTx, uint32_t Error)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_ERROR(Error));

    return (FlagStatus)READ_BIT(UARTx->RSR, Error);
}

/**
  * @brief   Очистка флагов ошибки
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   Error  Выбор флагов ошибки.
  *                 Параметр принимает любую совокупность значений UART_Error_x из @ref UART_Error_Define.
  * @retval  void
  */
__STATIC_INLINE void UART_ErrorStatusClear(UART_TypeDef* UARTx, uint32_t Error)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_ERROR(Error));

    WRITE_REG(UARTx->RSR, Error);
}

/**
  * @}
  */

/** @defgroup UART_IT Прерывания
  * @{
  */

/**
  * @brief   Настройка порога заполнения FIFO при приёме для генерации прерывания
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   FIFOLevelRx  Порог
  * @retval  void
  */
__STATIC_INLINE void UART_ITFIFOLevelRxConfig(UART_TypeDef* UARTx, UART_FIFOLevel_TypeDef FIFOLevelRx)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_FIFO_LEVEL(FIFOLevelRx));

    WRITE_REG(UARTx->IFLS_bit.RXIFLSEL, FIFOLevelRx);
}

/**
  * @brief   Настройка порога опустошения FIFO при передаче для генерации прерывания
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   FIFOLevelTx  Порог
  * @retval  void
  */
__STATIC_INLINE void UART_ITFIFOLevelTxConfig(UART_TypeDef* UARTx, UART_FIFOLevel_TypeDef FIFOLevelTx)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_FIFO_LEVEL(FIFOLevelTx));

    WRITE_REG(UARTx->IFLS_bit.TXIFLSEL, FIFOLevelTx);
}

/**
  * @brief   Маскирование выбранных прерываний
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений UART_ITSource_x из @ref UART_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_ITCmd(UART_TypeDef* UARTx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(ITSource));

    MODIFY_REG(UARTx->IMSC, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Запрос немаскированного состояния прерывания
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений UART_ITSource_x из @ref UART_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus UART_ITRawStatus(UART_TypeDef* UARTx, uint32_t ITSource)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(UARTx->RIS, ITSource);
}

/**
  * @brief   Запрос маскированного состояния прерывания
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений UART_ITSource_x из @ref UART_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus UART_ITMaskedStatus(UART_TypeDef* UARTx, uint32_t ITSource)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(UARTx->MIS, ITSource);
}

/**
  * @brief   Сброс флагов состояния выбранных прерываний
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений UART_ITSource_x из @ref UART_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void UART_ITStatusClear(UART_TypeDef* UARTx, uint32_t ITSource)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_IT_SOURCE(ITSource));

    WRITE_REG(UARTx->ICR, ITSource);
}

/**
  * @}
  */

/** @defgroup UART_DMA Настройка DMA
  * @{
  */

/**
  * @brief   Управление блокированием запросов DMA от приемника в случае возникновения
  *          прерывания по ошибке
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_DMABlkOnErrCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->DMACR_bit.DMAONERR, State);
}

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера приемника
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_DMARxCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->DMACR_bit.RXDMAE, State);
}

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера передатчика
  * @param   UARTx  Выбор модуля UART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void UART_DMATxCmd(UART_TypeDef* UARTx, FunctionalState State)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(UARTx->DMACR_bit.TXDMAE, State);
}

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_UART_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
