/**
  ******************************************************************************
  * @file    niietcm4_uart.h
  *
  * @brief   Файл содержит все прототипы функций для UART
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_UART_H
#define __NIIETCM4_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Exported_Types Типы
  * @{
  */

/**
  * @brief Макрос проверки соответсвия величины целой части делителя baudrate UART диапазону.
  */

#define IS_UART_INT_DIV(INT_DIV) (((INT_DIV) > ((uint32_t)0x0)) && ((INT_DIV) < ((uint32_t)0x10000)))

/**
  * @brief Макрос проверки соответсвия величины дробной части делителя baudrate UART диапазону.
  */

#define IS_UART_FRAC_DIV(FRAC_DIV) ((FRAC_DIV) < ((uint32_t)0x40))

/**
  * @brief Макрос проверки корректности передаваемых данных.
  */

#define IS_UART_DATA(DATA) ((DATA) < ((uint32_t)0x100))

/**
  * @brief  Направления передачи UART.
  */

typedef enum
{
    UART_Dir_Rx,        /*!< Передача. */
    UART_Dir_Tx         /*!< Прием. */
}UART_Dir_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref UART_Dir_Typedef.
  */

#define IS_UART_DIR(DIR)  (((DIR) == UART_Dir_Rx) || \
                           ((DIR) == UART_Dir_Tx))

/**
  * @brief  Выбор режима передачи стопового бита.
  */

typedef enum
{
    UART_StopBit_1,        /*!< Один стоповый бит. */
    UART_StopBit_2         /*!< Два стоповых бита. */
}UART_StopBit_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref UART_StopBit_TypeDef.
  */

#define IS_UART_STOP_BIT(STOP_BIT)  (((STOP_BIT) == UART_StopBit_1) || \
                                     ((STOP_BIT) == UART_StopBit_2))

/**
  * @brief  Выбор режима бита четности.
  */

typedef enum
{
    UART_ParityBit_Disable,     /*!< Не передается, не проверяется. */
    UART_ParityBit_Odd,         /*!< Проверка нечетности данных. */
    UART_ParityBit_Even,        /*!< Проверка четности данных. */
    UART_ParityBit_High,        /*!< Бит четности постоянно равен единице. */
    UART_ParityBit_Low          /*!< Бит четности постоянно равен нулю. */
}UART_ParityBit_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref UART_ParityBit_TypeDef.
  */

#define IS_UART_PARITY_BIT(PARITY_BIT)  (((PARITY_BIT) == UART_ParityBit_Disable) || \
                                         ((PARITY_BIT) == UART_ParityBit_Odd) || \
                                         ((PARITY_BIT) == UART_ParityBit_Even) || \
                                         ((PARITY_BIT) == UART_ParityBit_High) || \
                                         ((PARITY_BIT) == UART_ParityBit_Low))

/**
  * @brief  Количество передаваемых/принимаемых информационных бит.
  */

typedef enum
{
    UART_DataWidth_5,       /*!< Длина информационного слова 5 бит. */
    UART_DataWidth_6,       /*!< Длина информационного слова 6 бит. */
    UART_DataWidth_7,       /*!< Длина информационного слова 7 бит. */
    UART_DataWidth_8        /*!< Длина информационного слова 8 бит. */
}UART_DataWidth_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref UART_DataWidth_TypeDef.
  */

#define IS_UART_DATA_WIDTH(DATA_WIDTH)  (((DATA_WIDTH) == UART_DataWidth_5) || \
                                         ((DATA_WIDTH) == UART_DataWidth_6) || \
                                         ((DATA_WIDTH) == UART_DataWidth_7) || \
                                         ((DATA_WIDTH) == UART_DataWidth_8))

/**
  * @brief  Порог заполнения буфера приемника/передатчика, по достижению которого
  *   будет генерироваться прерывание
  */

typedef enum
{
    UART_FIFOLevel_1_8,     /*!< Заполнение FIFO на 1/8. */
    UART_FIFOLevel_1_4,     /*!< Заполнение FIFO на 1/4. */
    UART_FIFOLevel_1_2,     /*!< Заполнение FIFO на 1/2. */
    UART_FIFOLevel_3_4,     /*!< Заполнение FIFO на 3/4. */
    UART_FIFOLevel_7_8      /*!< Заполнение FIFO на 7/8. */
}UART_FIFOLevel_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref UART_FIFOLevel_TypeDef.
  */

#define IS_UART_FIFO_LEVEL(FIFO_LEVEL)  (((FIFO_LEVEL) == UART_FIFOLevel_1_8) || \
                                         ((FIFO_LEVEL) == UART_FIFOLevel_1_4) || \
                                         ((FIFO_LEVEL) == UART_FIFOLevel_1_2) || \
                                         ((FIFO_LEVEL) == UART_FIFOLevel_3_4) || \
                                         ((FIFO_LEVEL) == UART_FIFOLevel_7_8))

/**
  * @brief  Структура инициализации модемного режима.
  */

typedef struct
{
    FunctionalState UART_InvDTR;           /*!< Управление инверсией сигнала на линии состояния модема DTR. Выключенная инверсия означает высокий уровень сигнала.
                                               Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState UART_InvRTS;           /*!< Управление инверсией сигнала на линии состояния модема RTS. Выключенная инверсия означает высокий уровень сигнала.
                                               Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState UART_RTSEn;            /*!< Разрешение аппаратного управления потоком данных по линии RTS.
                                               Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState UART_CTSEn;            /*!< Разрешение аппаратного управления потоком данных по линии CTS.
                                               Параметр может принимать любое значение из @ref FunctionalState. */
}UART_ModemInit_TypeDef;

/**
  * @brief  Структура инициализации UART.
  */

typedef struct
{
    UART_StopBit_TypeDef UART_StopBit;          /*!< Выбор режима передачи стопового бита.
                                                    Параметр может принимать любое значение из @ref UART_StopBit_TypeDef. */
    UART_ParityBit_TypeDef UART_ParityBit;      /*!< Выбор режима бита четности.
                                                    Параметр может принимать любое значение из @ref UART_ParityBit_TypeDef. */
    UART_DataWidth_TypeDef UART_DataWidth;      /*!< Количество передаваемых/принимаемых информационных бит.
                                                    Параметр может принимать любое значение из @ref UART_DataWidth_TypeDef. */
    uint32_t UART_ClkFreq;                      /*!< Значение текущей частоты в Гц, подведенной к блоку UART */
    uint32_t UART_BaudRate;                     /*!< Желаемая скорость передачи данных в бит/с
                                                    Максимальное значение 921600 */
    UART_FIFOLevel_TypeDef UART_FIFOLevelRx;    /*!< Порог заполнения буффера приемника при срабатывании.
                                                    Параметр может принимать любое значение из @ref UART_FIFOLevel_TypeDef. */
    UART_FIFOLevel_TypeDef UART_FIFOLevelTx;    /*!< Порог заполнения буффера передатчика при срабатывании.
                                                    Параметр может принимать любое значение из @ref UART_FIFOLevel_TypeDef. */
    FunctionalState UART_FIFOEn;                /*!< Разрешение режима FIFO буфера приемника и передатчика.
                                                    Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState UART_RxEn;                  /*!< Разрешение приема.
                                                    Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState UART_TxEn;                  /*!< Разрешение передачи.
                                                    Параметр может принимать любое значение из @ref FunctionalState. */
}UART_Init_TypeDef;

/**
 * @}
 */

/** @defgroup UART_Exported_Constants Константы
  * @{
  */

/** @defgroup UART_Exported_Constants_ITSource Источники прерываний UART
  * @{
  */

#define UART_ITSource_ChangeRI          ((uint32_t)0x00000001)      /*!< Изменение состояния линии UART_RI */
#define UART_ITSource_ChangeCTS         ((uint32_t)0x00000002)      /*!< Изменение состояния линии UART_CTS */
#define UART_ITSource_ChangeDCD         ((uint32_t)0x00000004)      /*!< Изменение состояния линии UART_DCD */
#define UART_ITSource_ChangeDSR         ((uint32_t)0x00000008)      /*!< Изменение состояния линии UART_DSR */
#define UART_ITSource_RxFIFOLevel       ((uint32_t)0x00000010)      /*!< Порог переполнения буфера приемника */
#define UART_ITSource_TxFIFOLevel       ((uint32_t)0x00000020)      /*!< Порог опустошения буфера передатчика */
#define UART_ITSource_RecieveTimeout    ((uint32_t)0x00000040)      /*!< Таймаут приема данных */
#define UART_ITSource_ErrorFrame        ((uint32_t)0x00000080)      /*!< Ошибка в структуре кадра */
#define UART_ITSource_ErrorParity       ((uint32_t)0x00000100)      /*!< Ошибка контроля четности */
#define UART_ITSource_ErrorBreak        ((uint32_t)0x00000200)      /*!< Разрыв линии */
#define UART_ITSource_ErrorOverflow     ((uint32_t)0x00000400)      /*!< Переполнение буффера приемника */
#define UART_ITSource_All               ((uint32_t)0x000007FF)      /*!< Все источники выбраны. */

/**
  * @brief Макрос проверки номеров источников прерываний на попадание в допустимый диапазон.
  */

#define IS_UART_IT_SOURCE(IT_SOURCE)  (((IT_SOURCE) & ~UART_ITSource_All) == 0)

 /**
   * @}
   */

/** @defgroup UART_Exported_Constants_Flag Флаги работы UART
  * @{
  */

#define UART_Flag_InvCTS        ((uint32_t)0x00000001)      /*!< Флаг инверсии сигнала на линии UART_CTS. */
#define UART_Flag_InvDSR        ((uint32_t)0x00000002)      /*!< Флаг инверсии сигнала на линии UART_DSR. */
#define UART_Flag_InvDCD        ((uint32_t)0x00000004)      /*!< Флаг инверсии сигнала на линии UART_DSR. */
#define UART_Flag_Busy          ((uint32_t)0x00000008)      /*!< Флаг занятости блока UART. */
#define UART_Flag_RxFIFOEmpty   ((uint32_t)0x00000010)      /*!< Флаг пустоты буффера приемника. */
#define UART_Flag_TxFIFOFull    ((uint32_t)0x00000020)      /*!< Флаг заполнения буффера передатчика. */
#define UART_Flag_RxFIFOFull    ((uint32_t)0x00000040)      /*!< Флаг заполнения буффера приемника. */
#define UART_Flag_TxFIFOEmpty   ((uint32_t)0x00000080)      /*!< Флаг пустоты буффера передатчика. */
#define UART_Flag_InvRI         ((uint32_t)0x00000100)      /*!< Флаг инверсии сигнала на линии UART_RI. */
#define UART_Flag_All           ((uint32_t)0x000001FF)      /*!< Все флаги выбраны. */

 /**
   * @brief Макрос проверки номеров флагов на попадание в допустимый диапазон.
   */

#define IS_UART_FLAG(FLAG)  (((FLAG) & ~UART_Flag_All) == 0)

/**
  * @}
  */

 /** @defgroup UART_Exported_Constants_Error Ошибки приемника UART
   * @{
   */

#define UART_Error_Frame        ((uint32_t)0x00000001)      /*!< Флаг ошибки в структуре кадра. */
#define UART_Error_Parity       ((uint32_t)0x00000002)      /*!< Флаг ошибки контроля четности. */
#define UART_Error_Break        ((uint32_t)0x00000004)      /*!< Флаг разрыва линии. */
#define UART_Error_Overflow     ((uint32_t)0x00000008)      /*!< Флаг переполнения буффера приемника. */
#define UART_Error_All          ((uint32_t)0x0000000F)      /*!< Все флаги ошибок выбраны. */

/**
  * @brief Макрос проверки номеров флагов ошибок на попадание в допустимый диапазон.
  */

#define IS_UART_ERROR(ERROR)  (((ERROR) & ~UART_Error_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup UART_Exported_Functions Функции
  * @{
  */

void UART_Cmd(NT_UART_TypeDef* UARTx, FunctionalState State);
void UART_BaudRateDivConfig(NT_UART_TypeDef* UARTx, uint32_t IntDiv, uint32_t FracDiv);
void UART_Break(NT_UART_TypeDef* UARTx, FunctionalState State);

/** @defgroup UART_Init_Deinit Инициализация и деинициализация
  * @{
  */

void UART_DeInit(NT_UART_TypeDef* UARTx);
OperationStatus UART_Init(NT_UART_TypeDef* UARTx, UART_Init_TypeDef* UART_InitStruct);
void UART_StructInit(UART_Init_TypeDef* UART_InitStruct);

/**
  * @}
  */

/** @defgroup UART_SendRecieve Прием и передача
  * @{
  */

void UART_SendData(NT_UART_TypeDef* UARTx, uint32_t Data);
uint32_t UART_RecieveData(NT_UART_TypeDef* UARTx);
FlagStatus UART_FlagStatus(NT_UART_TypeDef* UARTx, uint32_t UART_Flag);
FlagStatus UART_ErrorStatus(NT_UART_TypeDef* UARTx, uint32_t UART_Error);
void UART_ErrorStatusClear(NT_UART_TypeDef* UARTx, uint32_t UART_Error);

/**
  * @}
  */

/** @defgroup UART_ModemInit Режим модема
  * @{
  */

void UART_ModemConfig(NT_UART_TypeDef* UARTx, UART_ModemInit_TypeDef* UART_ModemInitStruct);
void UART_ModemStructInit(UART_ModemInit_TypeDef* UART_ModemInitStruct);

/**
  * @}
  */

/** @defgroup UART_IT Прерывания
  * @{
  */

void UART_ITFIFOLevelConfig(NT_UART_TypeDef* UARTx, UART_Dir_Typedef UART_Dir,  UART_FIFOLevel_TypeDef UART_FIFOLevel);
void UART_ITCmd(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource,  FunctionalState State);
FlagStatus UART_ITRawStatus(NT_UART_TypeDef *UARTx, uint32_t UART_ITSource);
FlagStatus UART_ITMaskedStatus(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource);
void UART_ITStatusClear(NT_UART_TypeDef* UARTx, uint32_t UART_ITSource);

/**
  * @}
  */

/** @defgroup UART_DMA Настройка DMA
  * @{
  */

void UART_DMABlkOnErrCmd(NT_UART_TypeDef* UARTx,  FunctionalState State);
void UART_DMACmd(NT_UART_TypeDef* UARTx, UART_Dir_Typedef UART_Dir,  FunctionalState State);

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_UART_H */



/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
