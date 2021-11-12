/**
  ******************************************************************************
  * @file    plib035_spi.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          SPI, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_SPI_H
#define __PLIB035_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

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

#define SPI_Flag_Busy SPI_SR_BSY_Msk           /*!< Флаг занятости блока SPI */
#define SPI_Flag_RxFIFONotEmpty SPI_SR_RNE_Msk /*!< Флаг наличия данных в буффере приемника данных */
#define SPI_Flag_RxFIFOFull SPI_SR_RFF_Msk     /*!< Флаг заполнения буффера приемника */
#define SPI_Flag_TxFIFONotFull SPI_SR_TNF_Msk  /*!< Флаг наличия свободного места в буффере передатчика */
#define SPI_Flag_TxFIFOEmpty SPI_SR_TFE_Msk    /*!< Флаг пустоты буффера передатчика */
#define SPI_Flag_All (SPI_SR_BSY_Msk | \
                      SPI_SR_RNE_Msk | \
                      SPI_SR_RFF_Msk | \
                      SPI_SR_TNF_Msk | \
                      SPI_SR_TFE_Msk) /*!< Все флаги выбраны */

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
    SPI_FrameFormat_SPI = SPI_CR0_FRF_SPI,             /*!< Режим SPI от Motorola */
    SPI_FrameFormat_SSI = SPI_CR0_FRF_SSI,             /*!< Режим SSI от Texas Instruments */
    SPI_FrameFormat_Microwire = SPI_CR0_FRF_Microwire, /*!< Режим Microwire от National Semiconductor */
} SPI_FrameFormat_TypeDef;
#define IS_SPI_FRAME_FORMAT(VALUE) (((VALUE) == SPI_FrameFormat_SPI) || \
                                    ((VALUE) == SPI_FrameFormat_SSI) || \
                                    ((VALUE) == SPI_FrameFormat_Microwire))

/**
  * @brief  Размер слова данных
  */
typedef enum {
    SPI_DataWidth_4 = SPI_CR0_DSS_4bit,   /*!< Длина информационного слова 4 бит */
    SPI_DataWidth_5 = SPI_CR0_DSS_5bit,   /*!< Длина информационного слова 5 бит */
    SPI_DataWidth_6 = SPI_CR0_DSS_6bit,   /*!< Длина информационного слова 6 бит */
    SPI_DataWidth_7 = SPI_CR0_DSS_7bit,   /*!< Длина информационного слова 7 бит */
    SPI_DataWidth_8 = SPI_CR0_DSS_8bit,   /*!< Длина информационного слова 8 бит */
    SPI_DataWidth_9 = SPI_CR0_DSS_9bit,   /*!< Длина информационного слова 9 бит */
    SPI_DataWidth_10 = SPI_CR0_DSS_10bit, /*!< Длина информационного слова 10 бит */
    SPI_DataWidth_11 = SPI_CR0_DSS_11bit, /*!< Длина информационного слова 11 бит */
    SPI_DataWidth_12 = SPI_CR0_DSS_12bit, /*!< Длина информационного слова 12 бит */
    SPI_DataWidth_13 = SPI_CR0_DSS_13bit, /*!< Длина информационного слова 13 бит */
    SPI_DataWidth_14 = SPI_CR0_DSS_14bit, /*!< Длина информационного слова 14 бит */
    SPI_DataWidth_15 = SPI_CR0_DSS_15bit, /*!< Длина информационного слова 15 бит */
    SPI_DataWidth_16 = SPI_CR0_DSS_16bit, /*!< Длина информационного слова 16 бит */
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
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPI->CR1_bit.SSE, State);
}

/**
  * @brief   Отключение выхода данных в режиме ведомого
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_SlaveOutputDisCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPI->CR1_bit.SOD, State);
}

/**
  * @brief   Настройка полярности и фазы SCK в режиме SPI Motorola
  * @param   SCKPhase  Режим фазы
  * @param   SCKPhase  Режим полярности
  * @retval  void
  */
__STATIC_INLINE void SPI_SCKConfig(SPI_SCKPhase_TypeDef SCKPhase, SPI_SCKPolarity_TypeDef SCKPolarity)
{
    assert_param(IS_SPI_SCK_PHASE(SCKPhase));
    assert_param(IS_SPI_SCK_POLARITY(SCKPolarity));

    MODIFY_REG(SPI->CR0, SPI_CR0_SPH_Msk | SPI_CR0_SPO_Msk,
               ((SCKPhase << SPI_CR0_SPH_Pos) |
                (SCKPolarity << SPI_CR0_SPO_Pos)));
}

/**
  * @brief   Настройка ширины слова данных
  * @param   DataWidth  Значение разрядности слова
  * @retval  void
  */
__STATIC_INLINE void SPI_DataWidthConfig(SPI_DataWidth_TypeDef DataWidth)
{
    assert_param(IS_SPI_DATA_WIDTH(DataWidth));

    WRITE_REG(SPI->CR0_bit.DSS, DataWidth);
}

/**
  * @brief   Настройка режима работы SPI
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void SPI_ModeConfig(SPI_Mode_TypeDef Mode)
{
    assert_param(IS_SPI_MODE(Mode));

    WRITE_REG(SPI->CR1_bit.MS, Mode);
}

/**
  * @brief   Настройка режима формата кадра
  * @param   FrameFormat  Выбор формата
  * @retval  void
  */
__STATIC_INLINE void SPI_FrameFormatConfig(SPI_FrameFormat_TypeDef FrameFormat)
{
    assert_param(IS_SPI_FRAME_FORMAT(FrameFormat));

    WRITE_REG(SPI->CR0_bit.FRF, FrameFormat);
}

/**
  * @brief   Настройка делителя для получение нужной частоты SCK.
  *          Результирующий коэффциент деления = SCKDivExtra * (1 + SCKDiv).
  * @param   SCKDiv  Основной делитель.
  *                  Параметр принимает любое значение из диапазона 0-255.
  * @param   SCKDivExtra  Дополнительный делитель.
                          Параметр может принимать любые четные значения из диапазона: 2-254.

  * @retval  void
  */
__STATIC_INLINE void SPI_SCKDivConfig(uint32_t SCKDiv, uint32_t SCKDivExtra)
{
    assert_param(IS_SPI_SCK_DIV(SCKDiv));
    assert_param(IS_SPI_SCK_DIV_EXTRA(SCKDivExtra));

    WRITE_REG(SPI->CR0_bit.SCR, SCKDiv);
    WRITE_REG(SPI->CPSR, SCKDivExtra);
}

/** @defgroup SPI_Init_Deinit Инициализация и деинициализация
  * @{
  */

void SPI_DeInit(void);
void SPI_Init(SPI_Init_TypeDef* InitStruct);
void SPI_StructInit(SPI_Init_TypeDef* InitStruct);

/**
  * @}
  */

/** @defgroup SPI_SendRecieve Прием и передача
  * @{
  */

/**
  * @brief   Передача слова данных
  * @param   Data   Слово данных
  * @retval  void
  */
__STATIC_INLINE void SPI_SendData(uint32_t Data)
{
    assert_param(IS_SPI_DATA(Data));

    WRITE_REG(SPI->DR, Data);
}

/**
  * @brief   Прием слова данных
  * @retval  Val  Слово данных
  */
__STATIC_INLINE uint32_t SPI_RecieveData()
{
    return READ_REG(SPI->DR);
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений SPI_Flag_x из @ref SPI_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_FlagStatus(uint32_t Flag)
{
    assert_param(IS_SPI_FLAG(Flag));

    return (FlagStatus)READ_BIT(SPI->SR, Flag);
}

/**
  * @}
  */

/** @defgroup SPI_IT Прерывания
  * @{
  */

/**
  * @brief   Настройка порога заполнения FIFO при приёме для генерации прерывания
  * @param   FIFOLevelRx  Порог.
  *                       Параметр принимает любое значение из диапазона 0-8.
  * @retval  void
  */
__STATIC_INLINE void SPI_ITFIFOLevelRxConfig(uint32_t FIFOLevelRx)
{
    assert_param(IS_SPI_FIFO_LEVEL(FIFOLevelRx));

    WRITE_REG(SPI->CR1_bit.RXIFLSEL, FIFOLevelRx);
}

/**
  * @brief   Настройка порога опустошения FIFO при передаче для генерации прерывания
  * @param   FIFOLevelTx  Порог.
  *                       Параметр принимает любое значение из диапазона 0-8.
  * @retval  void
  */
__STATIC_INLINE void SPI_ITFIFOLevelTxConfig(uint32_t FIFOLevelTx)
{
    assert_param(IS_SPI_FIFO_LEVEL(FIFOLevelTx));

    WRITE_REG(SPI->CR1_bit.TXIFLSEL, FIFOLevelTx);
}

/**
  * @brief   Маскирование выбранных прерываний
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_ITCmd(uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    MODIFY_REG(SPI->IMSC, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Запрос немаскированного состояния прерывания
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_ITRawStatus(uint32_t ITSource)
{
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(SPI->RIS, ITSource);
}

/**
  * @brief   Запрос маскированного состояния прерывания
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus SPI_ITMaskedStatus(uint32_t ITSource)
{
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(SPI->MIS, ITSource);
}

/**
  * @brief   Сброс флагов состояния выбранных прерываний
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений SPI_ITSource_x из @ref SPI_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void SPI_ITStatusClear(uint32_t ITSource)
{
    assert_param(IS_SPI_IT_SOURCE(ITSource));

    WRITE_REG(SPI->ICR, ITSource);
}

/**
  * @}
  */

/** @defgroup SPI_DMA Настройка DMA
  * @{
  */

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера приемника
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_DMARxCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPI->DMACR_bit.RXDMAE, State);
}

/**
  * @brief   Разрешение формирования запросов DMA для обслуживания буфера передатчика
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void SPI_DMATxCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SPI->DMACR_bit.TXDMAE, State);
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

#endif /* __PLIB035_SPI_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
