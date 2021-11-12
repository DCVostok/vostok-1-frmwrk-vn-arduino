/**
  ******************************************************************************
  * @file    niietcm4_dma.h
  *
  * @brief   Файл содержит все прототипы функций для DMA.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_DMA_H
#define __NIIETCM4_DMA_H

/* Start of section using anonymous unions */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#endif

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** @defgroup DMA_Exported_Defines Константы
  * @{
  */

/** @defgroup DMA_Exported_Defines_CHANNEL_CFG Маски для CHANNEL_CFG
 *  @brief  Битовые позиции и маски регистра CHANNEL_CFG в @ref DMA_Channel_TypeDef
  * @{
  */

#define CHANNEL_CFG_CYCLE_CTRL_Pos      0      /*!< Поле задания типа цикла DMA */
#define CHANNEL_CFG_NEXT_USEBURST_Pos   3      /*!< Контролирует установку соответсвующего каналу бита в регистре NT_DMA->CHNL_USEBURST_SET */
#define CHANNEL_CFG_N_MINUS_1_Pos       4      /*!< Общее количество передач в цикле работы */
#define CHANNEL_CFG_R_POWER_Pos         14     /*!< Количество передач до выполнения переарбитрации */
#define CHANNEL_CFG_SRC_PROT_CTRL_Pos   18     /*!< Защита шины AHB-Lite при чтении данных из источника */
#define CHANNEL_CFG_DST_PROT_CTRL_Pos   21     /*!< Защита шины AHB-Lite при записи данных в приемник */
#define CHANNEL_CFG_SRC_SIZE_Pos        24     /*!< Разрядность данных источника */
#define CHANNEL_CFG_SRC_INC_Pos         26     /*!< Шаг инкремента адреса источника */
#define CHANNEL_CFG_DST_SIZE_Pos        28     /*!< Разрядность данных приемника */
#define CHANNEL_CFG_DST_INC_Pos         30     /*!< Шаг инкремента адреса приемника */

#define CHANNEL_CFG_CYCLE_CTRL_Msk      ((uint32_t)0x00000007)     /*!< Поле задания типа цикла DMA */
#define CHANNEL_CFG_NEXT_USEBURST_Msk   ((uint32_t)0x00000008)     /*!< Контролирует установку соответсвующего каналу бита в регистре NT_DMA->CHNL_USEBURST_SET */
#define CHANNEL_CFG_N_MINUS_1_Msk       ((uint32_t)0x00003FF0)     /*!< Общее количество передач в цикле работы */
#define CHANNEL_CFG_R_POWER_Msk         ((uint32_t)0x0003C000)     /*!< Количество передач до выполнения переарбитрации */
#define CHANNEL_CFG_SRC_PROT_CTRL_Msk   ((uint32_t)0x001C0000)     /*!< Защита шины AHB-Lite при чтении данных из источника */
#define CHANNEL_CFG_DST_PROT_CTRL_Msk   ((uint32_t)0x00E00000)     /*!< Защита шины AHB-Lite при записи данных в приемник */
#define CHANNEL_CFG_SRC_SIZE_Msk        ((uint32_t)0x03000000)     /*!< Разрядность данных источника */
#define CHANNEL_CFG_SRC_INC_Msk         ((uint32_t)0x0C000000)     /*!< Шаг инкремента адреса источника */
#define CHANNEL_CFG_DST_SIZE_Msk        ((uint32_t)0x30000000)     /*!< Разрядность данных приемника */
#define CHANNEL_CFG_DST_INC_Msk         ((uint32_t)0xC0000000)     /*!< Шаг инкремента адреса приемника */

/**
  * @}
  */

 /** @defgroup DMA_Exported_Defines_Channels Маски каналов DMA
   * @{
   */

#define DMA_Channel_All           ((uint32_t)0x00FFFFFF)  /*!< Все каналы DMA */

/** @defgroup DMA_Exported_Defines_Channels_Num Маски каналов по номеру
  * @{
  */

#define DMA_Channel_0             ((uint32_t)0x00000001)  /*!< Канал DMA 0 */
#define DMA_Channel_1             ((uint32_t)0x00000002)  /*!< Канал DMA 1 */
#define DMA_Channel_2             ((uint32_t)0x00000004)  /*!< Канал DMA 2 */
#define DMA_Channel_3             ((uint32_t)0x00000008)  /*!< Канал DMA 3 */
#define DMA_Channel_4             ((uint32_t)0x00000010)  /*!< Канал DMA 4 */
#define DMA_Channel_5             ((uint32_t)0x00000020)  /*!< Канал DMA 5 */
#define DMA_Channel_6             ((uint32_t)0x00000040)  /*!< Канал DMA 6 */
#define DMA_Channel_7             ((uint32_t)0x00000080)  /*!< Канал DMA 7 */
#define DMA_Channel_8             ((uint32_t)0x00000100)  /*!< Канал DMA 8 */
#define DMA_Channel_9             ((uint32_t)0x00000200)  /*!< Канал DMA 9 */
#define DMA_Channel_10            ((uint32_t)0x00000400)  /*!< Канал DMA 10 */
#define DMA_Channel_11            ((uint32_t)0x00000800)  /*!< Канал DMA 11 */
#define DMA_Channel_12            ((uint32_t)0x00001000)  /*!< Канал DMA 12 */
#define DMA_Channel_13            ((uint32_t)0x00002000)  /*!< Канал DMA 13 */
#define DMA_Channel_14            ((uint32_t)0x00004000)  /*!< Канал DMA 14 */
#define DMA_Channel_15            ((uint32_t)0x00008000)  /*!< Канал DMA 15 */
#define DMA_Channel_16            ((uint32_t)0x00010000)  /*!< Канал DMA 16 */
#define DMA_Channel_17            ((uint32_t)0x00020000)  /*!< Канал DMA 17 */
#define DMA_Channel_18            ((uint32_t)0x00040000)  /*!< Канал DMA 18 */
#define DMA_Channel_19            ((uint32_t)0x00080000)  /*!< Канал DMA 19 */
#define DMA_Channel_20            ((uint32_t)0x00100000)  /*!< Канал DMA 20 */
#define DMA_Channel_21            ((uint32_t)0x00200000)  /*!< Канал DMA 21 */
#define DMA_Channel_22            ((uint32_t)0x00400000)  /*!< Канал DMA 22 */
#define DMA_Channel_23            ((uint32_t)0x00800000)  /*!< Канал DMA 23 */

/**
   * @}
   */

/** @defgroup DMA_Exported_Defines_Channels_Name Маски каналов по имени
  * @{
  */

#define DMA_Channel_UART0_TX      DMA_Channel_0   /*!< Канал DMA по передаче от UART0 */
#define DMA_Channel_UART1_TX      DMA_Channel_1   /*!< Канал DMA по передаче от UART1 */
#define DMA_Channel_UART2_TX      DMA_Channel_2   /*!< Канал DMA по передаче от UART2 */
#define DMA_Channel_UART3_TX      DMA_Channel_3   /*!< Канал DMA по передаче от UART3 */
#define DMA_Channel_UART0_RX      DMA_Channel_4   /*!< Канал DMA по приему от UART0 */
#define DMA_Channel_UART1_RX      DMA_Channel_5   /*!< Канал DMA по приему от UART1 */
#define DMA_Channel_UART2_RX      DMA_Channel_6   /*!< Канал DMA по приему от UART2 */
#define DMA_Channel_UART3_RX      DMA_Channel_7   /*!< Канал DMA по приему от UART3 */
#define DMA_Channel_ADCSEQ0       DMA_Channel_8   /*!< Канал DMA секвенсора 0 АЦП */
#define DMA_Channel_ADCSEQ1       DMA_Channel_9   /*!< Канал DMA секвенсора 1 АЦП */
#define DMA_Channel_ADCSEQ2       DMA_Channel_10  /*!< Канал DMA секвенсора 2 АЦП */
#define DMA_Channel_ADCSEQ3       DMA_Channel_11  /*!< Канал DMA секвенсора 3 АЦП */
#define DMA_Channel_ADCSEQ4       DMA_Channel_12  /*!< Канал DMA секвенсора 4 АЦП */
#define DMA_Channel_ADCSEQ5       DMA_Channel_13  /*!< Канал DMA секвенсора 5 АЦП */
#define DMA_Channel_ADCSEQ6       DMA_Channel_14  /*!< Канал DMA секвенсора 6 АЦП */
#define DMA_Channel_ADCSEQ7       DMA_Channel_15  /*!< Канал DMA секвенсора 7 АЦП */
#define DMA_Channel_SPI0_TX       DMA_Channel_16  /*!< Канал DMA по передаче от SPI0 */
#define DMA_Channel_SPI1_TX       DMA_Channel_17  /*!< Канал DMA по передаче от SPI1 */
#define DMA_Channel_SPI2_TX       DMA_Channel_18  /*!< Канал DMA по передаче от SPI2 */
#define DMA_Channel_SPI3_TX       DMA_Channel_19  /*!< Канал DMA по передаче от SPI3 */
#define DMA_Channel_SPI0_RX       DMA_Channel_20  /*!< Канал DMA по приему от SPI0 */
#define DMA_Channel_SPI1_RX       DMA_Channel_21  /*!< Канал DMA по приему от SPI1 */
#define DMA_Channel_SPI2_RX       DMA_Channel_22  /*!< Канал DMA по приему от SPI2 */
#define DMA_Channel_SPI3_RX       DMA_Channel_23  /*!< Канал DMA по приему от SPI3 */

/**
  * @}
  */

/**
  * @brief Макрос проверки маски каналов на попадание в допустимый диапазон.
  */

#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) != (uint32_t)0x000000) && (((CHANNEL) & (uint32_t)0xFF000000) == ((uint32_t)0x0000)))


/**
  * @brief Макрос проверки маски канала при работе с каналами по отдельности.
  */

#define IS_GET_DMA_CHANNEL(CHANNEL) (((CHANNEL) == (DMA_Channel_0)) || \
                                     ((CHANNEL) == (DMA_Channel_1)) || \
                                     ((CHANNEL) == (DMA_Channel_2)) || \
                                     ((CHANNEL) == (DMA_Channel_3)) || \
                                     ((CHANNEL) == (DMA_Channel_4)) || \
                                     ((CHANNEL) == (DMA_Channel_5)) || \
                                     ((CHANNEL) == (DMA_Channel_6)) || \
                                     ((CHANNEL) == (DMA_Channel_7)) || \
                                     ((CHANNEL) == (DMA_Channel_8)) || \
                                     ((CHANNEL) == (DMA_Channel_9)) || \
                                     ((CHANNEL) == (DMA_Channel_10)) || \
                                     ((CHANNEL) == (DMA_Channel_11)) || \
                                     ((CHANNEL) == (DMA_Channel_12)) || \
                                     ((CHANNEL) == (DMA_Channel_13)) || \
                                     ((CHANNEL) == (DMA_Channel_14)) || \
                                     ((CHANNEL) == (DMA_Channel_15)) || \
                                     ((CHANNEL) == (DMA_Channel_16)) || \
                                     ((CHANNEL) == (DMA_Channel_17)) || \
                                     ((CHANNEL) == (DMA_Channel_18)) || \
                                     ((CHANNEL) == (DMA_Channel_10)) || \
                                     ((CHANNEL) == (DMA_Channel_20)) || \
                                     ((CHANNEL) == (DMA_Channel_21)) || \
                                     ((CHANNEL) == (DMA_Channel_22)) || \
                                     ((CHANNEL) == (DMA_Channel_23)))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup DMA_Exported_Types Типы
  * @{
  */

/**
  * @brief Битовый доступ к регистру CHANNEL_CFG в @ref DMA_Channel_TypeDef
  */

typedef struct {
    uint32_t CYCLE_CTRL             :3;     /*!< Выбор режима работы DMA */
    uint32_t NEXT_USEBURST          :1;     /*!< Контроль установки соответсвующего каналу бита в регистре NT_DMA->CHNL_USEBURST_SET */
    uint32_t N_MINUS_1              :10;    /*!< Общее количество передач N (в поле пишется значение N-1) */
    uint32_t R_POWER                :4;     /*!< Выбор количества передач до выполнения переарбитрации */
    uint32_t SRC_PROT_PRIVILEGED    :1;     /*!< Защита шины при чтении из источника: привелегированный доступ */
    uint32_t SRC_PROT_BUFFERABLE    :1;     /*!< Защита шины при чтении из источника: буфферизация */
    uint32_t SRC_PROT_CACHEABLE     :1;     /*!< Защита шины при чтении из источника: кэширование */
    uint32_t DST_PROT_PRIVILEGED    :1;     /*!< Защита шины при записи в приемник: привелегированный доступ */
    uint32_t DST_PROT_BUFFERABLE    :1;     /*!< Защита шины при записи в приемник: буфферизация */
    uint32_t DST_PROT_CACHEABLE     :1;     /*!< Защита шины при записи в приемник: кэширование */
    uint32_t SRC_SIZE               :2;     /*!< Разрядность данных источника */
    uint32_t SRC_INC                :2;     /*!< Шаг инкремента адреса источника при чтении */
    uint32_t DST_SIZE               :2;     /*!< Разрядность данных приемника */
    uint32_t DST_INC                :2;     /*!< Шаг инкремента адреса приемника при записи */
}_CHANNEL_CFG_bits;

/**
  * @brief Тип, описывающий структуру канала DMA.
  */

typedef struct
{
    uint32_t SRC_DATA_END; /*!< Адрес конца данных источника */
    uint32_t DST_DATA_END; /*!< Адрес конца данных приемника */
    union
    {
        uint32_t CHANNEL_CFG;             /*!< Настройка канала */
        _CHANNEL_CFG_bits CHANNEL_CFG_bit; /*!< Настройка канала: побитовый доступ */
    };
            uint32_t  RESERVED;
}DMA_Channel_TypeDef;

/**
  * @brief Управляющая структура данных DMA.
  */

typedef struct
{
    DMA_Channel_TypeDef CH[24];  /*!< Совокупность из общего количества каналов DMA */
}DMA_ConfigStruct_TypeDef;

/**
  * @brief Совокупность из основной и управляющей структур DMA. Общий размер 1 кБ.
  * @attention Экземпляры этой структуры требуют обязательного выравнивания по
  *   1024 байтам в адресном пространстве! Разрешенные адреса: 0xXXXXX000,
  *   0xXXXXX400, 0xXXXXX800, 0xXXXXXC00.
  */

typedef struct
{
    DMA_ConfigStruct_TypeDef PRM_DATA;  /*!< Основная управляющая структура */
    uint32_t  RESERVED0[32];            /*!< Пустышка для неиспользованных 8 каналов DMA */
    DMA_ConfigStruct_TypeDef ALT_DATA;  /*!< Альтернативная управляющая структура */
    uint32_t  RESERVED1[32];            /*!< Пустышка для неиспользованных 8 каналов DMA */
}DMA_ConfigData_TypeDef;

/**
  * @brief Выбор режима работы DMA.
  */

typedef enum
{
    DMA_Mode_Disable,           /*!< Неактивное состояние */
    DMA_Mode_Basic,             /*!< Основной режим передачи */
    DMA_Mode_AutoReq,           /*!< Режим передачи с авто-запросом */
    DMA_Mode_PingPong,          /*!< Режим передачи "пинг-понг" */
    DMA_Mode_PrmMemScatGath,    /*!< Работа с памятью в режиме "разборка-сборка" с использованием первичной управляющей структуры */
    DMA_Mode_AltMemScatGath,    /*!< Работа с памятью в режиме "разборка-сборка" с использованием альтернативной управляющей структуры */
    DMA_Mode_PrmPeriphScatGath, /*!< Работа с периферией в режиме "разборка-сборка" с использованием первичной управляющей структуры */
    DMA_Mode_AltPeriphScatGath  /*!< Работа с периферией в режиме "разборка-сборка" с использованием альтернативной управляющей структуры */
}DMA_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref DMA_Mode_TypeDef.
  */

#define IS_DMA_MODE(MODE) (((MODE) == DMA_Mode_Disable) || \
                           ((MODE) == DMA_Mode_Basic) || \
                           ((MODE) == DMA_Mode_AutoReq) || \
                           ((MODE) == DMA_Mode_PingPong) || \
                           ((MODE) == DMA_Mode_PrmMemScatGath) || \
                           ((MODE) == DMA_Mode_AltMemScatGath) || \
                           ((MODE) == DMA_Mode_PrmPeriphScatGath) || \
                           ((MODE) == DMA_Mode_AltPeriphScatGath))

 /**
   * @brief Выбор количества передач до выполнения переарбитрации.
   */

typedef enum
{
    DMA_ArbitrationRate_1,      /*!< Переарбитрация каждую передачу DMA */
    DMA_ArbitrationRate_2,      /*!< Переарбитрация каждые 2 передачи DMA */
    DMA_ArbitrationRate_4,      /*!< Переарбитрация каждые 4 передачи DMA */
    DMA_ArbitrationRate_8,      /*!< Переарбитрация каждые 8 передач DMA */
    DMA_ArbitrationRate_16,     /*!< Переарбитрация каждые 16 передач DMA */
    DMA_ArbitrationRate_32,     /*!< Переарбитрация каждые 32 передачи DMA */
    DMA_ArbitrationRate_64,     /*!< Переарбитрация каждые 64 передачи DMA */
    DMA_ArbitrationRate_128,    /*!< Переарбитрация каждые 128 передач DMA */
    DMA_ArbitrationRate_256,    /*!< Переарбитрация каждые 256 передач DMA */
    DMA_ArbitrationRate_512,    /*!< Переарбитрация каждые 512 передач DMA */
    DMA_ArbitrationRate_1024    /*!< Переарбитрация каждые 1024 передачи DMA */
}DMA_ArbitrationRate_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref DMA_ArbitrationRate_TypeDef.
  */

#define IS_DMA_ARBITRATION_RATE(ARBITRATION_RATE) (((ARBITRATION_RATE) == DMA_ArbitrationRate_1) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_2) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_4) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_8) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_16) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_32) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_64) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_128) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_256) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_512) || \
                                                   ((ARBITRATION_RATE) == DMA_ArbitrationRate_1024))

/**
  * @brief  Защита шины при чтении из источника или записи в приемник через DMA.
  */

typedef struct
{
    FunctionalState PRIVELGED;  /*!< Управление привелегированным доступом */
    FunctionalState BUFFERABLE; /*!< Управление буфферизацией доступа */
    FunctionalState CACHEABLE;  /*!< Управление кэшированием доступа */
}DMA_Protect_TypeDef;

/**
  * @brief  Разрядность данных источника или приемника
  */

typedef enum
{
    DMA_DataSize_8,             /*!< Разрядность данных 8 бит */
    DMA_DataSize_16,            /*!< Разрядность данных 16 бит */
    DMA_DataSize_32             /*!< Разрядность данных 32 бит */
}DMA_DataSize_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref DMA_DataSize_TypeDef.
  */

#define IS_DMA_DATA_SIZE(DATA_SIZE) (((DATA_SIZE) == DMA_DataSize_8) || \
                                     ((DATA_SIZE) == DMA_DataSize_16) || \
                                     ((DATA_SIZE) == DMA_DataSize_32))

/**
  * @brief  Шаг инкремента адреса источника при чтении или приемника при записи
  */

typedef enum
{
    DMA_DataInc_8,              /*!< Инкремент данных 8 бит */
    DMA_DataInc_16,             /*!< Инкремент данных 16 бит */
    DMA_DataInc_32,             /*!< Инкремент данных 32 бит */
    DMA_DataInc_Disable         /*!< Инкремент отсутствует */
}DMA_DataInc_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref DMA_DataSize_TypeDef.
  */

#define IS_DMA_DATA_INC(DATA_INC) (((DATA_INC) == DMA_DataInc_8) || \
                                   ((DATA_INC) == DMA_DataInc_16) || \
                                   ((DATA_INC) == DMA_DataInc_32) || \
                                   ((DATA_INC) == DMA_DataInc_Disable))

/**
  * @brief  Структура инициализации канала DMA
  */

typedef struct
{
    void *DMA_SrcDataEndPtr;                            /*!< Указатель конца данных источника. */
    void *DMA_DstDataEndPtr;                            /*!< Указатель конца данных приемника. */
    DMA_Mode_TypeDef DMA_Mode;                          /*!< Выбор режима работы DMA.
                                                            Параметр может принимать любое значение из @ref DMA_Mode_TypeDef. */
    FunctionalState DMA_NextUseburst;                   /*!< Контроль установки соответсвующего каналу бита в регистре NT_DMA->CHNL_USEBURST_SET.
                                                            Параметр может принимать любое значение из @ref FunctionalState. */
    uint32_t DMA_TransfersTotal;                        /*!< Общее количество передач DMA.
                                                            Параметр может принимать любое значение из диапазона 1-1024 */
    DMA_ArbitrationRate_TypeDef DMA_ArbitrationRate;    /*!< Выбор количества передач до выполнения переарбитрации.
                                                            Параметр может принимать любое значение из @ref DMA_ArbitrationRate_TypeDef. */
    DMA_Protect_TypeDef DMA_SrcProtect;                 /*!< Защита шины при чтении из источника через DMA
                                                            Параметр может принимать любое значение из @ref DMA_Protect_TypeDef.*/
    DMA_Protect_TypeDef DMA_DstProtect;                 /*!< Защита шины при записи в приемник через DMA
                                                            Параметр может принимать любое значение из @ref DMA_Protect_TypeDef.*/
    DMA_DataSize_TypeDef DMA_SrcDataSize;               /*!< Разрядность данных источника
                                                            Параметр может принимать любое значение из @ref DMA_DataSize_TypeDef.*/
    DMA_DataSize_TypeDef DMA_DstDataSize;               /*!< Разрядность данных приемника
                                                            Параметр может принимать любое значение из @ref DMA_DataSize_TypeDef.*/
    DMA_DataInc_TypeDef DMA_SrcDataInc;                 /*!< Шаг инкремента адреса источника при чтении
                                                            Параметр может принимать любое значение из @ref DMA_DataInc_TypeDef.*/
    DMA_DataInc_TypeDef DMA_DstDataInc;                 /*!< Шаг инкремента адреса приемника при записи
                                                            Параметр может принимать любое значение из @ref DMA_DataInc_TypeDef.*/
}DMA_ChannelInit_TypeDef;

/**
   * @brief Макрос проверки соответсвия величины DMA_TransfersTotal из @ref DMA_ChannelInit_TypeDef разрешенному диапазону.
   */

#define IS_DMA_TRANSFERS_TOTAL(TRANSFERS_TOTAL) (((TRANSFERS_TOTAL) <= ((uint32_t)1024)) && ((TRANSFERS_TOTAL) >= ((uint32_t)1)))

/**
  * @brief  Структура инициализации контроллера DMA
  */

typedef struct
{
    uint32_t DMA_Channel;                   /*!< Определяет каналы, которые будут настроены.
                                               Параметр может принимать любое значение любой или комбинации масок из @ref DMA_Exported_Defines_Channels_Num. */
    DMA_Protect_TypeDef DMA_Protection;     /*!< Управление защитой шины при обращении DMA к управляющим данным. */
    FunctionalState DMA_UseBurst;           /*!< Установка пакетного обмена каналов DMA
                                                Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState DMA_ReqMask;            /*!< Маскирование (игнорирование) запросов от периферии на обслуживание каналов DMA.
                                                Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState DMA_PrmAlt;             /*!< Установка первичной/альтернативной управляющей структуры каналов DMA.
                                                Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState DMA_HighPriority;       /*!< Установка высокого приоритета каналов DMA.
                                                Параметр может принимать любое значение из @ref FunctionalState. */
    FunctionalState DMA_ChannelEnable;      /*!< Разрешение работы каналов DMA.
                                                Параметр может принимать любое значение из @ref FunctionalState. */
}DMA_Init_TypeDef;

/**
  * @brief  Возможные состояния конечного автомата управления контроллером DMA.
  */

typedef enum
{
    DMA_State_Free,                /*!< В покое. */
    DMA_State_ReadConfigData,      /*!< Чтение управляющих данных канала. */
    DMA_State_ReadSrcDataEndPtr,   /*!< Чтение указателя конца данных источника. */
    DMA_State_ReadDstDataEndPtr,   /*!< Чтение указателя конца данных приемника. */
    DMA_State_ReadSrcData,         /*!< Чтение данных источника. */
    DMA_State_WriteDstData,        /*!< Запись данных в приемник. */
    DMA_State_WaitReq,             /*!< Ожидание запроса на выполнение прямого доступа. */
    DMA_State_WriteConfigData,     /*!< Запись управляющих данных канала. */
    DMA_State_Pause,               /*!< Приостановлен. */
    DMA_State_Done,                /*!< Выполнен. */
    DMA_State_PeriphScatGath,      /*!< Работа с периферией в режиме "разборка-сборка". */
}DMA_State_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref DMA_State_TypeDef.
  */

#define IS_DMA_STATE(STATE) (((STATE) == DMA_State_Free) || \
                             ((STATE) == DMA_State_ReadConfigData) || \
                             ((STATE) == DMA_State_ReadSrcDataEndPtr) || \
                             ((STATE) == DMA_State_ReadDstDataEndPtr) || \
                             ((STATE) == DMA_State_ReadSrcData) || \
                             ((STATE) == DMA_State_WriteDstData) || \
                             ((STATE) == DMA_State_WaitReq) || \
                             ((STATE) == DMA_State_Pause) || \
                             ((STATE) == DMA_State_Done) || \
                             ((STATE) == DMA_State_PeriphScatGath))

/**
  * @}
  */


/** @defgroup DMA_Exported_Functions Функции
  * @{
  */

/** @defgroup DMA_Exported_Functions_Init_Channel Инициализация каналов DMA
  * @{
  */

void DMA_ChannelDeInit(DMA_Channel_TypeDef* DMA_Channel);
void DMA_ChannelInit(DMA_Channel_TypeDef* DMA_Channel, DMA_ChannelInit_TypeDef* DMA_ChannelInitStruct);
void DMA_ChannelStructInit(DMA_ChannelInit_TypeDef* DMA_ChannelInitStruct);

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Init Инициализация контроллера DMA
  * @{
  */

void DMA_DeInit(void);
void DMA_Init(DMA_Init_TypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_Init_TypeDef* DMA_InitStruct);

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Config Конфигурация контроллера DMA
  * @{
  */

void DMA_BasePtrConfig(uint32_t BasePtr);
void DMA_ProtectionConfig(DMA_Protect_TypeDef *DMA_Protection);
void DMA_MasterEnableCmd(FunctionalState State);
void DMA_SWRequestCmd(uint32_t DMA_Channel);
void DMA_UseBurstCmd(uint32_t DMA_Channel, FunctionalState State);
void DMA_ReqMaskCmd(uint32_t DMA_Channel, FunctionalState State);
void DMA_ChannelEnableCmd(uint32_t DMA_Channel, FunctionalState State);
void DMA_PrmAltCmd(uint32_t DMA_Channel, FunctionalState State);
void DMA_HighPriorityCmd(uint32_t DMA_Channel, FunctionalState State);

/**
  * @}
  */


/** @defgroup DMA_Exported_Functions_Status Статусная информация
  * @{
  */

DMA_State_TypeDef DMA_StateStatus(void);
FunctionalState DMA_MasterEnableStatus(void);
FunctionalState DMA_WaitOnReqStatus(uint32_t DMA_Channel);
OperationStatus DMA_ErrorStatus(void);
void DMA_ClearErrorStatus(void);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#endif

#endif /* __NIIETCM4_DMA_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
