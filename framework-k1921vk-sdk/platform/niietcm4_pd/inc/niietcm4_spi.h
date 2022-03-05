#ifndef __NIIETCM4_SPI_H
#define __NIIETCM4_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup SPI
  * @brief Драйвер для работы с SPI
  * @{
  */

/** @defgroup SPI_Exported_Defines Константы
  * @{
  */

/** @defgroup SPI_ITSource_Define Источники прерываний SPI
  * @{
  */

#define SPI_ITSource_RecieveTimeout SPI_IMSC_RTIM_Msk  /*!< Таймаут приема данных */
#define SPI_ITSource_RecieveOverrun SPI_IMSC_RORIM_Msk /*!< Переполнение буфера приемника */
#define SPI_ITSource_RxFIFOLevel SPI_IMSC_RXIM_Msk     /*!< Порог переполнения буфера приемника */
#define SPI_ITSource_TxFIFOLevel SPI_IMSC_TXIM_Msk     /*!< Порог опустошения буфера передатчика */
#define SPI_ITSource_All (SPI_IMSC_RTIM_Msk |  \
                          SPI_IMSC_RORIM_Msk | \
                          SPI_IMSC_RXIM_Msk |  \
                          SPI_IMSC_TXIM_Msk) /*!< Все источники выбраны */

#define IS_SPI_IT_SOURCE(VALUE) (((VALUE) & ~SPI_ITSource_All) == 0)

/**
   * @}
   */

/** @defgroup SPI_Flag_Define Флаги работы SPI
  * @{
  */

#define SPI_Flag_Busy SPI_SPI_SR_BSY_Msk           /*!< Флаг занятости блока SPI */
#define SPI_Flag_RxFIFONotEmpty SPI_SPI_SR_RNE_Msk /*!< Флаг наличия данных в буффере приемника данных */
#define SPI_Flag_RxFIFOFull SPI_SPI_SR_RFF_Msk     /*!< Флаг заполнения буффера приемника */
#define SPI_Flag_TxFIFONotFull SPI_SPI_SR_TNF_Msk  /*!< Флаг наличия свободного места в буффере передатчика */
#define SPI_Flag_TxFIFOEmpty SPI_SPI_SR_TFE_Msk    /*!< Флаг пустоты буффера передатчика */
#define SPI_Flag_All (SPI_SPI_SR_BSY_Msk | \
                      SPI_SPI_SR_RNE_Msk | \
                      SPI_SPI_SR_RFF_Msk | \
                      SPI_SPI_SR_TNF_Msk | \
                      SPI_SPI_SR_TFE_Msk) /*!< Все флаги выбраны */

#define IS_SPI_FLAG(VALUE) (((VALUE) & ~SPI_Flag_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SPI_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор фазы сигнала SCK (только режим SPI)
  */
typedef enum {
    SPI_SCKPhase_CaptureRise, /*!< Захват данных по переднему фронту SCK, установка по заднему */
    SPI_SCKPhase_CaptureFall  /*!< Захват данных по заднему фронту SCK, установка по переднему */
} SPI_SCKPhase_TypeDef;
#define IS_SPI_SCK_PHASE(VALUE) (((VALUE) == SPI_SCKPhase_CaptureRise) || \
                                 ((VALUE) == SPI_SCKPhase_CaptureFall))

/**
  * @brief  Выбор полярности сигнала SCK (только режим SPI)
  */
typedef enum {
    SPI_SCKPolarity_SteadyLow, /*!< В режиме ожидания SCK удерживается в состоянии нуля */
    SPI_SCKPolarity_SteadyHigh /*!< В режиме ожидания SCK удерживается в состоянии единицы */
} SPI_SCKPolarity_TypeDef;
#define IS_SPI_SCK_POLARITY(VALUE) (((VALUE) == SPI_SCKPolarity_SteadyLow) || \
                                    ((VALUE) == SPI_SCKPolarity_SteadyHigh))

/**
  * @brief  Выбор формата кадра
  */
typedef enum {
    SPI_FrameFormat_SPI = 0x0UL,             /*!< Режим SPI от Motorola */
    SPI_FrameFormat_SSI = 0x1UL,             /*!< Режим SSI от Texas Instruments */
    SPI_FrameFormat_Microwire = 0x2UL, /*!< Режим Microwire от National Semiconductor */
} SPI_FrameFormat_TypeDef;
#define IS_SPI_FRAME_FORMAT(VALUE) (((VALUE) == SPI_FrameFormat_SPI) || \
                                    ((VALUE) == SPI_FrameFormat_SSI) || \
                                    ((VALUE) == SPI_FrameFormat_Microwire))

/**
  * @brief  Размер слова данных
  */
typedef enum {
    SPI_DataWidth_4 = 0x3UL,   /*!< Длина информационного слова 4 бит */
    SPI_DataWidth_5 = 0x4UL,   /*!< Длина информационного слова 5 бит */
    SPI_DataWidth_6 = 0x5UL,   /*!< Длина информационного слова 6 бит */
    SPI_DataWidth_7 = 0x6UL,   /*!< Длина информационного слова 7 бит */
    SPI_DataWidth_8 = 0x7UL,   /*!< Длина информационного слова 8 бит */
    SPI_DataWidth_9 = 0x8UL,   /*!< Длина информационного слова 9 бит */
    SPI_DataWidth_10 = 0x9UL, /*!< Длина информационного слова 10 бит */
    SPI_DataWidth_11 = 0xAUL, /*!< Длина информационного слова 11 бит */
    SPI_DataWidth_12 = 0xBUL, /*!< Длина информационного слова 12 бит */
    SPI_DataWidth_13 = 0xCUL, /*!< Длина информационного слова 13 бит */
    SPI_DataWidth_14 = 0xDUL, /*!< Длина информационного слова 14 бит */
    SPI_DataWidth_15 = 0xEUL, /*!< Длина информационного слова 15 бит */
    SPI_DataWidth_16 = 0xFUL, /*!< Длина информационного слова 16 бит */
} SPI_DataWidth_TypeDef;
#define IS_SPI_DATA_WIDTH(VALUE) (((VALUE) == SPI_DataWidth_4) ||  \
                                  ((VALUE) == SPI_DataWidth_5) ||  \
                                  ((VALUE) == SPI_DataWidth_6) ||  \
                                  ((VALUE) == SPI_DataWidth_7) ||  \
                                  ((VALUE) == SPI_DataWidth_8) ||  \
                                  ((VALUE) == SPI_DataWidth_9) ||  \
                                  ((VALUE) == SPI_DataWidth_10) || \
                                  ((VALUE) == SPI_DataWidth_11) || \
                                  ((VALUE) == SPI_DataWidth_12) || \
                                  ((VALUE) == SPI_DataWidth_13) || \
                                  ((VALUE) == SPI_DataWidth_14) || \
                                  ((VALUE) == SPI_DataWidth_15) || \
                                  ((VALUE) == SPI_DataWidth_16))

/**
  * @brief  Выбор режима работы
  */
typedef enum {
    SPI_Mode_Master, /*!< Мастер */
    SPI_Mode_Slave   /*!< Ведомый */
} SPI_Mode_TypeDef;
#define IS_SPI_MODE(VALUE) (((VALUE) == SPI_Mode_Master) || \
                            ((VALUE) == SPI_Mode_Slave))

/**
  * @brief  Структура инициализации SPI
  */
typedef struct
{
    SPI_Mode_TypeDef Mode;               /*!< Выбор режима работы */
    SPI_FrameFormat_TypeDef FrameFormat; /*!< Выбор формата кадра */
    SPI_DataWidth_TypeDef DataWidth;     /*!< Количество передаваемых/принимаемых информационных бит */
    uint32_t SCKDiv;                     /*!< Коэффициент базового деления частоты.
                                              Параметр может принимать любое значение из диапазона: 0-255. */
    uint32_t SCKDivExtra;                /*!< Коэффициент дополнительного деления частоты.
                                              Параметр может принимать любые четные значения из диапазона: 2-254.
                                              Результирующий коэффциент = SCKDivExtra * (1 + SCKDiv). */
} SPI_Init_TypeDef;

#define IS_SPI_SCK_DIV(VALUE) (((VALUE) > 0) && ((VALUE) < 0x100))
#define IS_SPI_SCK_DIV_EXTRA(VALUE) (((VALUE) > 1) && ((VALUE) < 0xFF))
#define IS_SPI_DATA(VALUE) ((VALUE) < 0x10000)
#define IS_SPI_FIFO_LEVEL(VALUE) ((VALUE) < 9)

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы приемопередатчика SPI
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_Cmd(NT_SPI_TypeDef* SPIx, FunctionalState State)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPIx->SPI_CR1_bit.SSE, State);
}

/**
  * @brief   Отключение выхода данных в режиме ведомого
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_SlaveOutputDisCmd(NT_SPI_TypeDef* SPIx, FunctionalState State)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPIx->SPI_CR1_bit.SOD, State);
}

/**
  * @brief   Настройка полярности и фазы SCK в режиме SPI Motorola
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   SCKPhase  Режим фазы
  * @param   SCKPhase  Режим полярности
  * @retval  void
  */
__STATIC_INLINE void SPI_SCKConfig(NT_SPI_TypeDef* SPIx, SPI_SCKPhase_TypeDef SCKPhase, SPI_SCKPolarity_TypeDef SCKPolarity)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_SCK_PHASE(SCKPhase));
    assert_param(IS_SPI_SCK_POLARITY(SCKPolarity));

    MODIFY_REG(SPIx->SPI_CR0, SPI_SPI_CR0_SPH_Msk | SPI_SPI_CR0_SPO_Msk,
               ((SCKPhase << SPI_SPI_CR0_SPH_Pos) |
                (SCKPolarity << SPI_SPI_CR0_SPO_Pos)));
}

/**
  * @brief   Настройка ширины слова данных
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   DataWidth  Значение разрядности слова
  * @retval  void
  */
__STATIC_INLINE void SPI_DataWidthConfig(NT_SPI_TypeDef* SPIx, SPI_DataWidth_TypeDef DataWidth)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_DATA_WIDTH(DataWidth));

    WRITE_REG(SPIx->SPI_CR0_bit.DSS, DataWidth);
}

/**
  * @brief   Настройка режима работы SPI
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void SPI_ModeConfig(NT_SPI_TypeDef* SPIx, SPI_Mode_TypeDef Mode)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_MODE(Mode));

    WRITE_REG(SPIx->SPI_CR1_bit.MS, Mode);
}

/**
  * @brief   Настройка режима формата кадра
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   FrameFormat  Выбор формата
  * @retval  void
  */
__STATIC_INLINE void SPI_FrameFormatConfig(NT_SPI_TypeDef* SPIx, SPI_FrameFormat_TypeDef FrameFormat)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_FRAME_FORMAT(FrameFormat));

    WRITE_REG(SPIx->SPI_CR0_bit.FRF, FrameFormat);
}

/**
  * @brief   Настройка делителя для получение нужной частоты SCK.
  *          Результирующий коэффциент деления = SCKDivExtra * (1 + SCKDiv).
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   SCKDiv  Основной делитель.
  *                  Параметр принимает любое значение из диапазона 0-255.
  * @param   SCKDivExtra  Дополнительный делитель.
                          Параметр может принимать любые четные значения из диапазона: 2-254.

  * @retval  void
  */
__STATIC_INLINE void SPI_SCKDivConfig(NT_SPI_TypeDef* SPIx, uint32_t SCKDiv, uint32_t SCKDivExtra)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_SCK_DIV(SCKDiv));
    assert_param(IS_SPI_SCK_DIV_EXTRA(SCKDivExtra));

    WRITE_REG(SPIx->SPI_CR0_bit.SCR, SCKDiv);
    WRITE_REG(SPIx->SPI_CPSR, SCKDivExtra);
}

/** @defgroup SPI_Init_Deinit Инициализация и деинициализация
  * @{
  */

void SPI_DeInit(NT_SPI_TypeDef* SPIx);
void SPI_Init(NT_SPI_TypeDef* SPIx, SPI_Init_TypeDef* InitStruct);
void SPI_StructInit(SPI_Init_TypeDef* InitStruct);

/**
  * @}
  */

/** @defgroup SPI_SendRecieve Прием и передача
  * @{
  */

/**
  * @brief   Передача слова данных
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   Data   Слово данных
  * @retval  void
  */
__STATIC_INLINE void SPI_SendData(NT_SPI_TypeDef* SPIx, uint32_t Data)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_DATA(Data));

    WRITE_REG(SPIx->SPI_DR, Data);
}

/**
  * @brief   Прием слова данных
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @retval  Val  Слово данных
  */
__STATIC_INLINE uint32_t SPI_RecieveData(NT_SPI_TypeDef* SPIx)
{
    assert_param(IS_SPI_PERIPH(SPIx));

    return READ_REG(SPIx->SPI_DR);
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений SPI_Flag_x из @ref SPI_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_FlagStatus(NT_SPI_TypeDef* SPIx, uint32_t Flag)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_FLAG(Flag));

    return (FlagStatus)READ_BIT(SPIx->SPI_SR, Flag);
}

/**
  * @}
  */

/** @defgroup SPI_IT Прерывания
  * @{
  */



/**
  * @brief   Маскирование выбранных прерываний
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_ITCmd(NT_SPI_TypeDef* SPIx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    MODIFY_REG(SPIx->SPI_IMSC, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Запрос немаскированного состояния прерывания
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_ITRawStatus(NT_SPI_TypeDef* SPIx, uint32_t ITSource)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(SPIx->SPI_RIS, ITSource);
}

/**
  * @brief   Запрос маскированного состояния прерывания
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_ITMaskedStatus(NT_SPI_TypeDef* SPIx, uint32_t ITSource)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(SPIx->SPI_MIS, ITSource);
}

/**
  * @brief   Сброс флагов состояния выбранных прерываний
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void SPI_ITStatusClear(NT_SPI_TypeDef* SPIx, uint32_t ITSource)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    WRITE_REG(SPIx->SPI_ICR, ITSource);
}

/**
  * @}
  */

/** @defgroup SPI_DMA Настройка DMA
  * @{
  */

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера приемника
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_DMARxCmd(NT_SPI_TypeDef* SPIx, FunctionalState State)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPIx->SPI_DMACR_bit.RXDMAE, State);
}

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера передатчика
  * @param   SPIx  Выбор модуля SPI, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_DMATxCmd(NT_SPI_TypeDef* SPIx, FunctionalState State)
{
    assert_param(IS_SPI_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPIx->SPI_DMACR_bit.TXDMAE, State);
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

#endif /* __NIIETCM4_SPI_H */
