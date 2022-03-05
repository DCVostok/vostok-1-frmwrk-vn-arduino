/**
  ******************************************************************************
  * @file    plib028_sdfm.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          SDFM, а также сопутствующие макроопределения и перечисления
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
  * <h2><center>&copy; 2019 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB028_SDFM_H
#define __PLIB028_SDFM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup SDFM
  * @brief Драйвер для работы с SDFM
  * @{
  */

/** @defgroup SDFM_Exported_Defines Константы
  * @{
  */

#define SDFM_CH_Total 4UL

/** @defgroup SDFM_CMP_Status_Define Флаги компаратора
  * @{
  */

#define SDFM_CMP_Status_HighEvent SDFM_CFLG_CFH0_Msk   /*!< Статус события "результат >= CMPH"  */
#define SDFM_CMP_Status_HighZEvent SDFM_CFLG_CFHZ0_Msk /*!< Статус события "результат >= CMPHZ"  */
#define SDFM_CMP_Status_LowEvent SDFM_CFLG_CFL0_Msk    /*!< Статус события "результат <= CMPL"  */
#define SDFM_CMP_Status_All (SDFM_CMP_Status_HighEvent |  \
                             SDFM_CMP_Status_HighZEvent | \
                             SDFM_CMP_Status_LowEvent) /*!< Все статусы выбраны */

#define IS_SDFM_CMP_STATUS(VALUE) (((VALUE) & ~SDFM_CMP_Status_All) == 0)

/**
  * @}
  */

/** @defgroup SDFM_ITStatus_Define Флаги прерываний демодулятора
  * @{
  */

#define SDFM_ITStatus_CMPHighEvent SDFM_IFLG_IFH0_Msk     /*!< Статус прерывания по событию "результат >= CMPH"  */
#define SDFM_ITStatus_CMPHighZEvent SDFM_IFLG_IFHZ0_Msk   /*!< Статус прерывания по событию "результат >= CMPHZ" */
#define SDFM_ITStatus_CMPLowEvent SDFM_IFLG_IFL0_Msk      /*!< Статус прерывания по событию "результат <= CMPL" */
#define SDFM_ITStatus_ModulatorFailture SDFM_IFLG_MF0_Msk /*!< Статус прерывания по ошибке модулятора/демодулятора */
#define SDFM_ITStatus_DFFIFOLevel SDFM_IFLG_FDR0_Msk      /*!< Статус прерывания по заполнению FIFO фильтра данных */
#define SDFM_ITStatus_DFFIFOOverflow SDFM_IFLG_OV0_Msk    /*!< Статус прерывания по переполнению FIFO фильтра данных */
#define SDFM_ITStatus_DFAckData SDFM_IFLG_AF0_Msk         /*!< Статус прерывания по получению новых данных на фильтре данных */
#define SDFM_ITStatus_All (SDFM_ITStatus_CMPHighEvent |      \
                           SDFM_ITStatus_CMPHighZEvent |     \
                           SDFM_ITStatus_CMPLowEvent |       \
                           SDFM_ITStatus_ModulatorFailture | \
                           SDFM_ITStatus_DFFIFOLevel |       \
                           SDFM_ITStatus_DFFIFOOverflow |    \
                           SDFM_ITStatus_DFAckData) /*!< Все статусы выбраны */

#define IS_SDFM_IT_STATUS(VALUE) (((VALUE) & ~SDFM_ITStatus_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SDFM_Exported_Types Типы
  * @{
  */

/**
  * @brief  Номер канала демодуляции
  */
typedef enum {
    SDFM_ChannelNum_0, /*!< Канал 0 */
    SDFM_ChannelNum_1, /*!< Канал 1 */
    SDFM_ChannelNum_2, /*!< Канал 2 */
    SDFM_ChannelNum_3, /*!< Канал 3 */
} SDFM_ChannelNum_TypeDef;
#define IS_SDFM_CHANNEL_NUM(VALUE) (((VALUE) == SDFM_ChannelNum_0) || \
                                    ((VALUE) == SDFM_ChannelNum_1) || \
                                    ((VALUE) == SDFM_ChannelNum_2) || \
                                    ((VALUE) == SDFM_ChannelNum_3))

/**
  * @brief  Режим декодирования канала
  */
typedef enum {
    SDFM_Decoder_SDR = SDFM_SD_CTLPARM_MOD_Mode0SDR,               /*!< Режим SDR */
    SDFM_Decoder_DDR = SDFM_SD_CTLPARM_MOD_Mode1DDR,               /*!< Режим DDR */
    SDFM_Decoder_Manchester = SDFM_SD_CTLPARM_MOD_Mode2Manchester, /*!< Режим Манчестерского кода */
    SDFM_Decoder_HDR = SDFM_SD_CTLPARM_MOD_Mode3HDR,               /*!< Режим HDR */
} SDFM_Decoder_TypeDef;
#define IS_SDFM_DECODER(VALUE) (((VALUE) == SDFM_Decoder_SDR) ||        \
                                ((VALUE) == SDFM_Decoder_DDR) ||        \
                                ((VALUE) == SDFM_Decoder_Manchester) || \
                                ((VALUE) == SDFM_Decoder_HDR))

/**
  * @brief  Выбор режима работы фильтра
  */
typedef enum {
    SDFM_Mode_FastSinc = SDFM_SD_DFPARM_SST_FastSinc, /*!< Режим FastSinc */
    SDFM_Mode_Sinc1 = SDFM_SD_DFPARM_SST_Sinc1,       /*!< Режим Sinc1 */
    SDFM_Mode_Sinc2 = SDFM_SD_DFPARM_SST_Sinc2,       /*!< Режим Sinc2 */
    SDFM_Mode_Sinc3 = SDFM_SD_DFPARM_SST_Sinc3,       /*!< Режим Sinc3 */
    SDFM_Mode_Sinc4 = SDFM_SD_DFPARM_SST_Sinc4,       /*!< Режим Sinc4 */
    SDFM_Mode_Sinc5 = SDFM_SD_DFPARM_SST_Sinc5,       /*!< Режим Sinc5 */
} SDFM_Mode_TypeDef;
#define IS_SDFM_MODE(VALUE) (((VALUE) == SDFM_Mode_FastSinc) || \
                             ((VALUE) == SDFM_Mode_Sinc1) ||    \
                             ((VALUE) == SDFM_Mode_Sinc2) ||    \
                             ((VALUE) == SDFM_Mode_Sinc3) ||    \
                             ((VALUE) == SDFM_Mode_Sinc4) ||    \
                             ((VALUE) == SDFM_Mode_Sinc5))

/**
  * @brief  Выбор источника прерывания фильтра данных
  */
typedef enum {
    SDFM_DF_ITSource_AckData = SDFM_SD_FFCTL_DRISEL_AckData,    /*!< По получению новых данных */
    SDFM_DF_ITSource_FIFOLevel = SDFM_SD_FFCTL_DRISEL_FIFOData, /*!< По уровню данных в FIFO */
} SDFM_DF_ITSource_TypeDef;
#define IS_SDFM_DF_IT_SOURCE(VALUE) (((VALUE) == SDFM_DF_ITSource_AckData) || \
                                     ((VALUE) == SDFM_DF_ITSource_FIFOLevel))

/**
  * @brief  Выбор источника синхронизации фильтра данных
  */
typedef enum {
    SDFM_DF_SyncSource_PWM012A = SDFM_SD_SYNC_SRC_PWM012A,   /*!< PWM0,1,2 канал A */
    SDFM_DF_SyncSource_PWM012B = SDFM_SD_SYNC_SRC_PWM012B,   /*!< PWM0,1,2 канал B */
    SDFM_DF_SyncSource_PWM345A = SDFM_SD_SYNC_SRC_PWM345A,   /*!< PWM3,4,5 канал A */
    SDFM_DF_SyncSource_PWM345B = SDFM_SD_SYNC_SRC_PWM345B,   /*!< PWM3,4,5 канал B */
    SDFM_DF_SyncSource_PWM6789A = SDFM_SD_SYNC_SRC_PWM6789A, /*!< PWM6,7,8,9 канал A */
    SDFM_DF_SyncSource_PWM6789B = SDFM_SD_SYNC_SRC_PWM6789B, /*!< PWM6,7,8,9 канал B */
    SDFM_DF_SyncSource_TMR0 = SDFM_SD_SYNC_SRC_TMR0,         /*!< TMR0 */
    SDFM_DF_SyncSource_TMR1 = SDFM_SD_SYNC_SRC_TMR1,         /*!< TMR1 */
} SDFM_DF_SyncSource_TypeDef;
#define IS_SDFM_DF_SYNC_SOURCE(VALUE) (((VALUE) == SDFM_DF_SyncSource_PWM012A) ||  \
                                       ((VALUE) == SDFM_DF_SyncSource_PWM012B) ||  \
                                       ((VALUE) == SDFM_DF_SyncSource_PWM345A) ||  \
                                       ((VALUE) == SDFM_DF_SyncSource_PWM345B) ||  \
                                       ((VALUE) == SDFM_DF_SyncSource_PWM6789A) || \
                                       ((VALUE) == SDFM_DF_SyncSource_PWM6789B) || \
                                       ((VALUE) == SDFM_DF_SyncSource_TMR0) ||     \
                                       ((VALUE) == SDFM_DF_SyncSource_TMR1))

/**
  * @brief  Структура инициализации фильтра данных
  */
typedef struct
{
    uint32_t OSR;                          /*!< Значение децимации. Результирующее значение деления определяется как OSR+1.
                                                Параметр принимает любое значение из диапазона 0x000-0xFFF. */
    uint32_t Shift;                        /*!< Значение сдвига вправо данных.
                                                Параметр принимает любое значение из диапазона 0-23. */
    SDFM_Mode_TypeDef Mode;                /*!< Выбор режима работы фильтра */
    SDFM_DF_SyncSource_TypeDef SyncSource; /*!< Настройка источника синхронизации */
    FunctionalState SyncEn;                /*!< Разрешение синхронизации */
    FunctionalState WaitSyncEn;            /*!< Разрешение режима "ожидание синхронизации" */
    FunctionalState WaitSyncHWClearEn;     /*!< Разрешение аппаратной очистки флага режима "ожидание синхронизации" */
    FunctionalState FIFOEn;                /*!< Разрешение работы FIFO */
    FunctionalState FIFOHWClearEn;         /*!< Разрешение аппаратной очистки FIFO по событию синхронизации */
    uint32_t DMAFIFOLevel;                 /*!< Настройка уровня заполненности FIFO для генерации запросов DMA.
                                                Параметр принимает любое значение из диапазона 0-8.*/
    FunctionalState DMAEn;                 /*!< Разрешение генерации запросов DMA */
} SDFM_DF_Init_TypeDef;

/**
  * @brief  Структура инициализации компаратора
  */
typedef struct
{
    uint32_t OSR;                        /*!< Значение децимации. Результирующее значение деления определяется как OSR+1.
                                                Параметр принимает любое значение из диапазона 0x000-0xFFF. */
    SDFM_Mode_TypeDef Mode;              /*!< Выбор режима работы компаратора */
    uint32_t ThresholdLow;               /*!< Порог срабатывания компаратора для события "результат <= CMPL".
                                              Диапазон зависит от OSR.*/
    uint32_t ThresholdHigh;              /*!< Порог срабатывания компаратора для события "результат >= CMPH".
                                              Диапазон зависит от OSR.*/
    uint32_t ThresholdHighZ;             /*!< Порог срабатывания компаратора для события "результат >= CMPHZ".
                                              Диапазон зависит от OSR.*/
    FunctionalState HighEventHWClearEn;  /*!< Разрешение аппаратной очистки флага "результат >= CMPH" компаратора */
    FunctionalState HighZEventHWClearEn; /*!< Разрешение аппаратной очистки флага "результат >= CMPHZ" компаратора */
    FunctionalState LowEventHWClearEn;   /*!< Разрешение аппаратной очистки флага "результат <= CMPL" компаратора */
} SDFM_CMP_Init_TypeDef;

#define IS_SDFM_HDR_DIV(VALUE) ((VALUE) < 0x100)
#define IS_SDFM_OSR(VALUE) ((VALUE) < 0x1000)
#define IS_SDFM_DF_SHIFT(VALUE) ((VALUE) < 24)
#define IS_SDFM_DF_FIFO_LEVEL(VALUE) ((VALUE) < 9)

/**
  * @}
  */

/** @defgroup SDFM_Exported_Functions Функции
  * @{
  */

void SDFM_DeInit(void);

/**
  * @brief   Включение демодулятора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->MFILEN_bit.MFE, State);
}

/**
  * @brief   Выбор режима декодирования канала
  * @param   ChannelNum  Номер канала
  * @param   Decoder  Выбор прежима
  * @retval  void
  */
__STATIC_INLINE void SDFM_DecoderConfig(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_Decoder_TypeDef Decoder)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_DECODER(Decoder));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CTLPARM_bit.MOD, Decoder);
}

/**
  * @brief   Настройка делителя HCLK для режима декодирования HDR
  * @param   ChannelNum  Номер канала
  * @param   Div  Значение делителя. Результирующее значение деления определяется как 2*(Div+1).
  *               Параметр принимает любое значение из диапазона 0x00-0xFF.
  * @retval  void
  */
__STATIC_INLINE void SDFM_HDRDivConfig(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Div)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_HDR_DIV(Div));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CTLPARM_bit.CORM3, Div);
}

/**
  * @brief   Включение прерывания по ошибке модулятора/демодулятора
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_ITFailtureCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CTLPARM_bit.MFIE, State);
}

/** @defgroup SDFM_Exported_Functions_DataFilter Конфигурация фильтра данных
  * @{
  */

void SDFM_DF_Init(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_DF_Init_TypeDef* InitStruct);
void SDFM_DF_StructInit(SDFM_DF_Init_TypeDef* InitStruct);

/**
  * @brief   Получение результата измерения из буфера фильтра данных
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t SDFM_DF_GetData(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].DATA);
}

/**
  * @brief   Включение фильтра данных
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_Cmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DFPARM_bit.FEN, State);
}

/**
  * @brief   Настройка коэффициента децимации
  * @param   ChannelNum  Номер канала
  * @param   OSR  Значение децимации. Результирующее значение деления определяется как OSR+1.
  *               Параметр принимает любое значение из диапазона 0x000-0xFFF.
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_OSRConfig(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t OSR)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_OSR(OSR));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DFPARM_bit.DOSR, OSR);
}

/**
  * @brief   Настройка сдвига вправо данных фильтра данных
  * @param   ChannelNum  Номер канала
  * @param   Shift  Значение сдвига.
  *               Параметр принимает любое значение из диапазона 0-23.
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ShiftConfig(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Shift)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_DF_SHIFT(Shift));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DPARM_bit.SH, Shift);
}

/**
  * @brief   Настройка режима работы фильтра данных
  * @param   ChannelNum  Номер канала
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ModeConfig(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_Mode_TypeDef Mode)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_MODE(Mode));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DFPARM_bit.SST, Mode);
}

/**
  * @brief   Включение синхронизации
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_SyncCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DFPARM_bit.ENSYN, State);
}

/**
  * @brief   Настройка источника синхронизации
  * @param   ChannelNum  Номер канала
  * @param   Source  Выбор источника
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_SyncConfig(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_DF_SyncSource_TypeDef Source)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_DF_SYNC_SOURCE(Source));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].SYNC_bit.SRC, Source);
}

/**
  * @brief   Включение режима ожидания синхронизации
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_WaitSyncCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].SYNC_bit.WTSEN, State);
}

/**
  * @brief   Включение режима аппаратной очистки флага синхронизации (режим "ожидания синхронизации")
  *          по событию заполнения FIFO на определенную величину
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_WaitSyncHWClearCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].SYNC_bit.WTSCLREN, State);
}

/**
  * @brief   Чтение статуса флага синхронизации в режиме "ожидание синхронизации"
  * @param   ChannelNum  Номер канала
  * @retval  Status  Статус флага
  */
__STATIC_INLINE FlagStatus SDFM_DF_WaitSyncStatus(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return (FlagStatus)READ_BIT(SDFM->SD[(uint32_t)ChannelNum].SYNC, SDFM_SD_SYNC_WTSFLG_Msk);
}

/**
  * @brief   Сброс флага синхронизации в режиме "ожидание синхронизации"
  * @param   ChannelNum  Номер канала
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_WaitSyncStatusClear(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].SYNC_bit.WTSFLGCLR, 1);
}

/**
  * @brief   Включение FIFO фильтра данных
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_FIFOCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].FFCTL_bit.EN, State);
}

/**
  * @brief   Включение аппаратной очистки FIFO фильтра данных по событию синхронизации
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_FIFOHWClearCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].SYNC_bit.FFSCLREN, State);
}

/**
  * @brief   Получение текущего состояния заполненности FIFO
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение. Диапазон 0-8.
  */
__STATIC_INLINE uint32_t SDFM_DF_GetFIFOLevel(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].FFCTL_bit.STAT);
}

/**
  * @brief   Настройка генерации запросов DMA по определенному уровню заполнения FIFO
  * @param   ChannelNum  Номер канала
  * @param   Level  Уровень заполнения.
  *               Параметр принимает любое значение из диапазона 0-8.
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_DMAConfig(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Level)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_DF_FIFO_LEVEL(Level));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DMACTL_bit.LVL, Level);
}

/**
  * @brief   Включение генерации запросов DMA
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_DMACmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DMACTL_bit.EN, State);
}

/**
  * @brief   Выбор источника прерывания фильтра данных
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ITConfig(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_DF_ITSource_TypeDef ITSource)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_DF_IT_SOURCE(ITSource));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].FFCTL_bit.DRISEL, ITSource);
}

/**
  * @brief   Включение прерывания фильтра данных по поступлению новых данных
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ITAckDataCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].DFPARM_bit.AEN, State);
}

/**
  * @brief   Включение прерывания фильтра данных по переполнению FIFO
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ITFIFOOverflowCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].FFCTL_bit.OVFIEN, State);
}

/**
  * @brief   Включение прерывания фильтра данных по уровню заполнения FIFO
  * @param   ChannelNum  Номер канала
  * @param   Level  Уровень заполнения.
  *               Параметр принимает любое значение из диапазона 0-8.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_DF_ITFIFOLevelCmd(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Level, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));
    assert_param(IS_SDFM_DF_FIFO_LEVEL(Level));

    MODIFY_REG(SDFM->SD[(uint32_t)ChannelNum].FFCTL, SDFM_SD_FFCTL_IEN_Msk | SDFM_SD_FFCTL_IL_Msk,
               (((uint32_t)State << SDFM_SD_FFCTL_IEN_Pos) | (Level << SDFM_SD_FFCTL_IL_Pos)));
}

/**
  * @}
  */

/** @defgroup SDFM_Exported_Functions_Comparator Конфигурация компаратора
  * @{
  */

void SDFM_CMP_Init(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_CMP_Init_TypeDef* InitStruct);
void SDFM_CMP_StructInit(SDFM_CMP_Init_TypeDef* InitStruct);

/**
  * @brief   Включение компаратора
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_Cmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.CEN, State);
}

/**
  * @brief   Настройка коэффициента децимации компаратора
  * @param   ChannelNum  Номер канала
  * @param   OSR  Значение децимации. Результирующее значение деления определяется как OSR+1.
  *               Параметр принимает любое значение из диапазона 0x000-0xFFF.
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_OSRConfig(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t OSR)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_OSR(OSR));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.COSR, OSR);
}

/**
  * @brief   Настройка режима работы компаратора
  * @param   ChannelNum  Номер канала
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_ModeConfig(SDFM_ChannelNum_TypeDef ChannelNum, SDFM_Mode_TypeDef Mode)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_MODE(Mode));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.CS, Mode);
}

/**
  * @brief   Установка границы компаратора для события "результат <= CMPL"
  * @param   ChannelNum  Номер канала
  * @param   Val  Значение. Диапазон зависит от OSR.
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_SetThresholdLow(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Val)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CMPL, Val);
}

/**
  * @brief   Получение значения границы компаратора для события "результат <= CMPL"
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение. Диапазон зависит от OSR.
  */
__STATIC_INLINE uint32_t SDFM_CMP_GetThresholdLow(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].CMPL);
}

/**
  * @brief   Установка границы компаратора для события "результат >= CMPH"
  * @param   ChannelNum  Номер канала
  * @param   Val  Значение. Диапазон зависит от OSR.
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_SetThresholdHigh(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Val)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CMPH, Val);
}

/**
  * @brief   Получение значения границы компаратора для события "результат >= CMPH"
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение. Диапазон зависит от OSR.
  */
__STATIC_INLINE uint32_t SDFM_CMP_GetThresholdHigh(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].CMPH);
}

/**
  * @brief   Установка границы компаратора для события "результат >= CMPHZ"
  * @param   ChannelNum  Номер канала
  * @param   Val  Значение. Диапазон зависит от OSR.
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_SetThresholdHighZ(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Val)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CMPHZ, Val);
}

/**
  * @brief   Получение значения границы компаратора для события "результат >= CMPHZ"
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение. Диапазон зависит от OSR.
  */
__STATIC_INLINE uint32_t SDFM_CMP_GetThresholdHighZ(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].CMPHZ);
}

/**
  * @brief   Включение аппаратной очистки флага "результат >= CMPH" компаратора
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_HighEventHWClearCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.HWHCLR, State);
}

/**
  * @brief   Включение аппаратной очистки флага "результат >= CMPHZ" компаратора
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_HighZEventHWClearCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.HWHZCLR, State);
}

/**
  * @brief   Включение аппаратной очистки флага "результат <= CMPL" компаратора
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_LowEventHWClearCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.HWLCLR, State);
}

/**
  * @brief   Получение последнего значения, использованного для сравнения
  * @param   ChannelNum  Номер канала
  * @retval  Val  Значение. Диапазон 0-0xFFF.
  */
__STATIC_INLINE uint32_t SDFM_CMP_GetLastData(SDFM_ChannelNum_TypeDef ChannelNum)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));

    return READ_REG(SDFM->SD[(uint32_t)ChannelNum].CDATA);
}

/**
  * @brief   Чтение флагов компаратора
  * @param   ChannelNum  Номер канала
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любую совокупность значений из @ref SDFM_CMP_Status_Define.
  * @retval  Status  Статус компаратора. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SDFM_CMP_Status(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Status)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_CMP_STATUS(Status));

    return (FlagStatus)READ_BIT(SDFM->CFLG, Status << ((uint32_t)ChannelNum));
}

/**
  * @brief   Сброс флагов компаратора
  * @param   ChannelNum  Номер канала
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любую совокупность значений из @ref SDFM_CMP_Status_Define.
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_StatusClear(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t Status)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_CMP_STATUS(Status));

    WRITE_REG(SDFM->CFLGCLR, Status << ((uint32_t)ChannelNum));
}

/**
  * @brief   Включение прерывания компаратора по условию "результат >= CMPH"
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_ITHighEventCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.IEH, State);
}

/**
  * @brief   Включение прерывания компаратора по условию "результат >= CMPHZ"
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_ITHighZEventCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.IEHZ, State);
}

/**
  * @brief   Включение прерывания компаратора по условию "результат <= CMPL"
  * @param   ChannelNum  Номер канала
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_CMP_ITLowEventCmd(SDFM_ChannelNum_TypeDef ChannelNum, FunctionalState State)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->SD[(uint32_t)ChannelNum].CPARM_bit.IEL, State);
}

/**
  * @}
  */

/** @defgroup SDFM_Exported_Functions_Int Конфигурация прерываний
  * @{
  */

/**
  * @brief   Включение прерывания демодулятора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SDFM_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SDFM->CTL_bit.MIE, State);
}

/**
  * @brief   Чтение флагов прерываний канала демодулятора
  * @param   ChannelNum  Номер канала
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref SDFM_IT_Status_Define.
  * @retval  Status  Статус флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SDFM_ITStatus(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t ITStatus)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(SDFM->IFLG, ITStatus << ((uint32_t)ChannelNum));
}

/**
  * @brief   Сброс флагов прерываний канала демодулятора
  * @param   ChannelNum  Номер канала
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref SDFM_IT_Status_Define.
  * @retval  void
  */
__STATIC_INLINE void SDFM_ITStatusClear(SDFM_ChannelNum_TypeDef ChannelNum, uint32_t ITStatus)
{
    assert_param(IS_SDFM_CHANNEL_NUM(ChannelNum));
    assert_param(IS_SDFM_IT_STATUS(ITStatus));

    WRITE_REG(SDFM->IFLGCLR, ITStatus << ((uint32_t)ChannelNum));
}

/**
  * @brief   Чтение флага комбинированного прерывания демодулятора - объединены по ИЛИ флаги всех каналов:
  *          - переполнение FIFO фильтра данных
  *          - ошибка модулятора/демодулятора
  *          - событие компаратора "результат >= CMPH"
  *          - событие компаратора "результат <= CMPL"
  * @retval  Status  Статус флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SDFM_ITCombinedStatus()
{
    return (FlagStatus)READ_BIT(SDFM->IFLG, SDFM_IFLG_MIF_Msk);
}

/**
  * @brief   Сброс флага комбинированного прерывания демодулятора
  * @retval  void
  */
__STATIC_INLINE void SDFM_ITCombinedStatusClear()
{
    WRITE_REG(SDFM->IFLGCLR, SDFM_IFLGCLR_MIF_Msk);
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

#endif /* __PLIB028_SDFM_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
