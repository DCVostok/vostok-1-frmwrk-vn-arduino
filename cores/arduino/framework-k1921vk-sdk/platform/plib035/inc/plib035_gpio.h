/**
  ******************************************************************************
  * @file    plib035_gpio.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          GPIO, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_GPIO_H
#define __PLIB035_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup GPIO
  * @brief Драйвер для работы с GPIO
  * @{
  */

/** @defgroup GPIO_Exported_Defines Константы
  * @{
  */

/** @defgroup GPIO_Pin_Define Маски пинов
  * @{
  */

#define GPIO_Pin_0 0x0001UL           /*!< Пин 0 выбран */
#define GPIO_Pin_1 0x0002UL           /*!< Пин 1 выбран */
#define GPIO_Pin_2 0x0004UL           /*!< Пин 2 выбран */
#define GPIO_Pin_3 0x0008UL           /*!< Пин 3 выбран */
#define GPIO_Pin_4 0x0010UL           /*!< Пин 4 выбран */
#define GPIO_Pin_5 0x0020UL           /*!< Пин 5 выбран */
#define GPIO_Pin_6 0x0040UL           /*!< Пин 6 выбран */
#define GPIO_Pin_7 0x0080UL           /*!< Пин 7 выбран */
#define GPIO_Pin_8 0x0100UL           /*!< Пин 8 выбран */
#define GPIO_Pin_9 0x0200UL           /*!< Пин 9 выбран */
#define GPIO_Pin_10 0x0400UL          /*!< Пин 10 выбран */
#define GPIO_Pin_11 0x0800UL          /*!< Пин 11 выбран */
#define GPIO_Pin_12 0x1000UL          /*!< Пин 12 выбран */
#define GPIO_Pin_13 0x2000UL          /*!< Пин 13 выбран */
#define GPIO_Pin_14 0x4000UL          /*!< Пин 14 выбран */
#define GPIO_Pin_15 0x8000UL          /*!< Пин 15 выбран */
#define GPIO_Pin_0_3 0x000FUL         /*!< Пины 0-3 выбраны */
#define GPIO_Pin_3_0 GPIO_Pin_0_3     /*!< Пины 3-0 выбраны */
#define GPIO_Pin_4_7 0x00F0UL         /*!< Пины 4-7 выбраны */
#define GPIO_Pin_7_4 GPIO_Pin_4_7     /*!< Пины 7-4 выбраны */
#define GPIO_Pin_8_11 0x0F00UL        /*!< Пины 8-11 выбраны */
#define GPIO_Pin_11_8 GPIO_Pin_8_11   /*!< Пины 11-8 выбраны */
#define GPIO_Pin_12_15 0xF000UL       /*!< Пины 12-15 выбраны */
#define GPIO_Pin_15_12 GPIO_Pin_12_15 /*!< Пины 15-12 выбраны */
#define GPIO_Pin_0_7 0x00FFUL         /*!< Пины 0-7 выбраны */
#define GPIO_Pin_7_0 GPIO_Pin_0_7     /*!< Пины 7-0 выбраны */
#define GPIO_Pin_8_15 0xFF00UL        /*!< Пины 8-15 выбраны */
#define GPIO_Pin_15_8 GPIO_Pin_8_15   /*!< Пины 15-8 выбраны */
#define GPIO_Pin_All 0xFFFFUL         /*!< Все пины выбраны */

#define IS_GPIO_PIN(VALUE) (((VALUE) != 0) && (((VALUE)&0xFFFF0000) == 0))

#define IS_GET_GPIO_PIN(VALUE) (((VALUE) == GPIO_Pin_0) ||  \
                                ((VALUE) == GPIO_Pin_1) ||  \
                                ((VALUE) == GPIO_Pin_2) ||  \
                                ((VALUE) == GPIO_Pin_3) ||  \
                                ((VALUE) == GPIO_Pin_4) ||  \
                                ((VALUE) == GPIO_Pin_5) ||  \
                                ((VALUE) == GPIO_Pin_6) ||  \
                                ((VALUE) == GPIO_Pin_7) ||  \
                                ((VALUE) == GPIO_Pin_8) ||  \
                                ((VALUE) == GPIO_Pin_9) ||  \
                                ((VALUE) == GPIO_Pin_10) || \
                                ((VALUE) == GPIO_Pin_11) || \
                                ((VALUE) == GPIO_Pin_12) || \
                                ((VALUE) == GPIO_Pin_13) || \
                                ((VALUE) == GPIO_Pin_14) || \
                                ((VALUE) == GPIO_Pin_15))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIO_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор режима работы пина
  */
typedef enum {
    GPIO_Mode_IO,     /*!< Пин в режиме ввода-вывода */
    GPIO_Mode_AltFunc /*!< Пин в режиме альтернативной функции */
} GPIO_Mode_TypeDef;
#define IS_GPIO_MODE(VALUE) (((VALUE) == GPIO_Mode_IO) || \
                             ((VALUE) == GPIO_Mode_AltFunc))

/**
  * @brief  Выбор события для возникновения прерывания
  */
typedef enum {
    GPIO_IntType_Level, /*!< Прерывание по уровню */
    GPIO_IntType_Edge   /*!< Прерывание по перепаду */
} GPIO_IntType_TypeDef;
#define IS_GPIO_INT_TYPE(VALUE) (((VALUE) == GPIO_IntType_Level) || \
                                 ((VALUE) == GPIO_IntType_Edge))

/**
  * @brief  Выбор полярности события для возникновения прерывания
  */
typedef enum {
    GPIO_IntPol_Negative, /*!< Прерывание по низкому уровню или отрицательному фронту */
    GPIO_IntPol_Positive  /*!< Прерывание по высокому уровню или положительному фронту */
} GPIO_IntPol_TypeDef;
#define IS_GPIO_INT_POL(VALUE) (((VALUE) == GPIO_IntPol_Negative) || \
                                ((VALUE) == GPIO_IntPol_Positive))

/**
  * @brief  Выбор количества фронтов, ипользуемых в генерации прерывания по фронту
  */
typedef enum {
    GPIO_IntEdge_Polarity, /*!< Прерывание согласно выбранной полярности фронта */
    GPIO_IntEdge_Any       /*!< Прерывание по обоим фронтам */
} GPIO_IntEdge_TypeDef;
#define IS_GPIO_INT_EDGE(VALUE) (((VALUE) == GPIO_IntEdge_Polarity) || \
                                 ((VALUE) == GPIO_IntEdge_Any))

/**
  * @brief  Выбор режима работы выходных каскадов
  */
typedef enum {
    GPIO_OutMode_PP = GPIO_OUTMODE_PIN0_PP, /*!< Режим push-pull */
    GPIO_OutMode_OD = GPIO_OUTMODE_PIN0_OD, /*!< Режим open-drain */
    GPIO_OutMode_OS = GPIO_OUTMODE_PIN0_OS  /*!< Режим open-source */
} GPIO_OutMode_TypeDef;
#define IS_GPIO_OUT_MODE(VALUE) (((VALUE) == GPIO_OutMode_PP) || \
                                 ((VALUE) == GPIO_OutMode_OD) || \
                                 ((VALUE) == GPIO_OutMode_OS))

/**
  * @brief  Выбор режима работы входа
  */
typedef enum {
    GPIO_InMode_Schmitt = GPIO_INMODE_PIN0_Schmitt, /*!< Режим push-pull */
    GPIO_InMode_CMOS = GPIO_INMODE_PIN0_CMOS,       /*!< Режим open-drain */
    GPIO_InMode_Disable = GPIO_INMODE_PIN0_Disable  /*!< Режим open-source */
} GPIO_InMode_TypeDef;
#define IS_GPIO_IN_MODE(VALUE) (((VALUE) == GPIO_InMode_Schmitt) || \
                                ((VALUE) == GPIO_InMode_CMOS) ||    \
                                ((VALUE) == GPIO_InMode_Disable))

/**
  * @brief  Выбор режима работы подтяжки
  */
typedef enum {
    GPIO_PullMode_Disable = GPIO_PULLMODE_PIN0_Disable, /*!< Внутренняя подтяжка выключена */
    GPIO_PullMode_PU = GPIO_PULLMODE_PIN0_PU,           /*!< Внутренняя подтяжка к питанию выключена */
    GPIO_PullMode_PD = GPIO_PULLMODE_PIN0_PD            /*!< Внутренняя подтяжка к земле включена */
} GPIO_PullMode_TypeDef;
#define IS_GPIO_PULL_MODE(VALUE) (((VALUE) == GPIO_PullMode_Disable) || \
                                  ((VALUE) == GPIO_PullMode_PU) ||      \
                                  ((VALUE) == GPIO_PullMode_PD))

/**
  * @brief  Выбор нагрузочной способности и скорости переключения пина
  */
typedef enum {
    GPIO_DriveMode_HighFast = GPIO_DRIVEMODE_PIN0_HF, /*!< Высокая нагрузочная способность и высокая скорость переключения */
    GPIO_DriveMode_HighSlow = GPIO_DRIVEMODE_PIN0_HS, /*!< Высокая нагрузочная способность и низкая скорость переключения */
    GPIO_DriveMode_LowFast = GPIO_DRIVEMODE_PIN0_LF,  /*!< Низкая нагрузочная способность и высокая скорость переключения */
    GPIO_DriveMode_LowSlow = GPIO_DRIVEMODE_PIN0_LS   /*!< Низкая нагрузочная способность и низкая скорость переключения */
} GPIO_DriveMode_TypeDef;
#define IS_GPIO_DRIVE_MODE(VALUE) (((VALUE) == GPIO_DriveMode_HighFast) || \
                                   ((VALUE) == GPIO_DriveMode_HighSlow) || \
                                   ((VALUE) == GPIO_DriveMode_LowFast) ||  \
                                   ((VALUE) == GPIO_DriveMode_LowSlow))

/**
  * @brief  Выбор режима работы входного фильтра пина
  */
typedef enum {
    GPIO_QualMode_3Sample, /*!< Используется 3 отсчета для фильтрации */
    GPIO_QualMode_6Sample  /*!< Используется 6 отсчетов для фильтрации */
} GPIO_QualMode_TypeDef;
#define IS_GPIO_QUAL_MODE(VALUE) (((VALUE) == GPIO_QualMode_3Sample) || \
                                  ((VALUE) == GPIO_QualMode_6Sample))

#define IS_GPIO_QUAL_PERIOD(VALUE) (((VALUE)&0xFFFFFF00) == 0)
#define IS_GPIO_MASK(VALUE) (((VALUE)&0xFFFFFF00) == 0)
#define IS_GPIO_VAL(VALUE) (((VALUE)&0xFFFF0000) == 0)

/**
  * @brief  Структура инициализации GPIO
  */
typedef struct
{
    uint32_t Pin;                     /*!< Определяет пины, которые будут настроены.
                                           Параметр может принимать любое значение из @ref GPIO_Pin_Define. */
    FunctionalState Out;              /*!< Определяет включение выхода выбранных пинов */
    FunctionalState AltFunc;          /*!< Определяет режим работы периферийной функции пинов */
    FunctionalState Digital;          /*!< Определяет включение цифровой функции порта */
    GPIO_OutMode_TypeDef OutMode;     /*!< Определяет режим работы выходных каскадов выбранных пинов */
    GPIO_InMode_TypeDef InMode;       /*!< Определяет режим работы входов выбранных пинов */
    GPIO_PullMode_TypeDef PullMode;   /*!< Определяет режим работы подтяжки выбранных пинов */
    GPIO_DriveMode_TypeDef DriveMode; /*!< Определяет нагрузочную способность и скорость переключения выбранных пинов */
} GPIO_Init_TypeDef;

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions Функции
  * @{
  */

/** @defgroup GPIO_Init_Deinit Инициализация и деинициализация
  * @{
  */

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Init_TypeDef* InitStruct);
void GPIO_StructInit(GPIO_Init_TypeDef* InitStruct);

/**
  * @}
  */

/** @defgroup GPIO_Config Конфигурация
  * @{
  */

/**
  * @brief   Включение цифровой работы (вход или выход) выбранных пинов
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_DigitalCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->DENSET, Pin);
    else
        WRITE_REG(GPIOx->DENCLR, Pin);
}

/**
  * @brief   Включение выхода выбранных пинов
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_OutCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->OUTENSET, Pin);
    else
        WRITE_REG(GPIOx->OUTENCLR, Pin);
}

/**
  * @brief   Включение периферийной функции выбранных пинов
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_AltFuncCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->ALTFUNCSET, Pin);
    else
        WRITE_REG(GPIOx->ALTFUNCCLR, Pin);
}

void GPIO_OutModeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_OutMode_TypeDef OutMode);
void GPIO_InModeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_InMode_TypeDef InMode);
void GPIO_PullModeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_PullMode_TypeDef PullMode);
void GPIO_DriveModeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_DriveMode_TypeDef DriveMode);

/**
  * @}
  */

/** @defgroup GPIO_Read_Write Чтение и запись
  * @{
  */

/** @defgroup GPIO_Read Чтение
  * @{
  */

/**
  * @brief   Чтение состояния выбранного пина
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   Pin  Выбор пина
  * @retval  State  Состояние Если выбрано несколько пинов, то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE BitState GPIO_ReadBit(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(Pin));

    return (BitState)READ_BIT(GPIOx->DATA, (uint32_t)Pin);
}

/**
  * @brief   Чтение состояния выбранного порта
  * @param   GPIOx  Выбор порта, где x=A|B
  * @retval  Val  Состояние
  */
__STATIC_INLINE uint32_t GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));

    return READ_REG(GPIOx->DATA);
}

/**
  * @brief   Чтение состояния младшего байта порта c использованием маски
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   MaskVal  Значение маски чтения
  * @retval  Val  Состояние находится в битах 7:0
  */
__STATIC_INLINE uint32_t GPIO_ReadLowMask(GPIO_TypeDef* GPIOx, uint32_t MaskVal)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_MASK(MaskVal));

    return READ_REG(GPIOx->MASKLB[MaskVal].MASKLB);
}

/**
  * @brief   Чтение состояния старшего байта порта c использованием маски
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   MaskVal  Значение маски чтения
  * @retval  Val  Состояние находится в битах 15:8
  */
__STATIC_INLINE uint32_t GPIO_ReadHighMask(GPIO_TypeDef* GPIOx, uint32_t MaskVal)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_MASK(MaskVal));

    return READ_REG(GPIOx->MASKHB[MaskVal].MASKHB);
}

/**
  * @}
  */

/** @defgroup GPIO_Write Запись
  * @{
  */

/**
  * @brief   Запись выбранного пина
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   Pin  Выбор пина
  * @retval  void
  */
__STATIC_INLINE void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint32_t Pin, BitState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(Pin));
    assert_param(IS_BIT_STATE(State));

    MODIFY_REG(GPIOx->DATAOUT, Pin, State ? (uint32_t)Pin : 0);
}

/**
  * @brief   Запись выбранного порта
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   PortVal  Значение которое будет записано
  * @retval  void
  */
__STATIC_INLINE void GPIO_WritePort(GPIO_TypeDef* GPIOx, uint32_t PortVal)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_VAL(PortVal));

    WRITE_REG(GPIOx->DATAOUT, PortVal);
}

/**
  * @brief   Запись младшего байта порта c использованием маски
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   MaskVal  Значение маски
  * @param   PortVal  Значение которое будет записано (биты 7:0)
  * @retval  void
  */
__STATIC_INLINE void GPIO_WriteLowMask(GPIO_TypeDef* GPIOx, uint32_t MaskVal, uint32_t PortVal)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_VAL(PortVal));
    assert_param(IS_GPIO_MASK(MaskVal));

    WRITE_REG(GPIOx->MASKLB[MaskVal].MASKLB, PortVal);
}

/**
  * @brief   Запись старшего байта порта c использованием маски
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   MaskVal  Значение маски
  * @param   PortVal  Значение которое будет записано (биты 15:8)
  * @retval  void
  */
__STATIC_INLINE void GPIO_WriteHighMask(GPIO_TypeDef* GPIOx, uint32_t MaskVal, uint32_t PortVal)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_VAL(PortVal));
    assert_param(IS_GPIO_MASK(MaskVal));

    WRITE_REG(GPIOx->MASKHB[MaskVal].MASKHB, PortVal);
}

/**
  * @}
  */

/** @defgroup GPIO_Bit_Operations Битовые операции
  * @{
  */

/**
  * @brief   Установка пинов порта
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   Pin  Выбор пина
  * @retval  void
  */
__STATIC_INLINE void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(Pin));

    WRITE_REG(GPIOx->DATAOUTSET, Pin);
}

/**
  * @brief   Сброс пинов порта
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   Pin  Выбор пина
  * @retval  void
  */
__STATIC_INLINE void GPIO_ClearBits(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(Pin));

    WRITE_REG(GPIOx->DATAOUTCLR, Pin);
}

/**
  * @brief   Переключение пинов порта в противоположное состояние
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   Pin  Выбор пина
  * @retval  void
  */
__STATIC_INLINE void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(Pin));

    WRITE_REG(GPIOx->DATAOUTTGL, Pin);
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIO_Qualifier Фильтрация
  * @{
  */

/**
  * @brief   Настройка режима входного фильтра пина
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void GPIO_QualModeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_QualMode_TypeDef Mode)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_GPIO_QUAL_MODE(Mode));

    if (Mode == GPIO_QualMode_6Sample)
        WRITE_REG(GPIOx->QUALMODESET, Pin);
    else
        WRITE_REG(GPIOx->QUALMODECLR, Pin);
}

/**
  * @brief   Настройка времени сэмплирования
  * @param   GPIOx  Выбор порта, где x=A|B
  * @param   SamplePerod  Количество тактов системной частоты между отсчетами фильтра
  * @retval  void
  */
__STATIC_INLINE void GPIO_QualSampleConfig(GPIO_TypeDef* GPIOx, uint32_t SamplePerod)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_QUAL_PERIOD(SamplePerod));

    WRITE_REG(GPIOx->QUALSAMPLE, SamplePerod);
}

/**
  * @brief   Включение входных фильтров пинов
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_QualCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->QUALSET, Pin);
    else
        WRITE_REG(GPIOx->QUALCLR, Pin);
}

/**
  * @brief   Включение пересинхронизации входов через 2 триггера
  * @param   GPIOx  выбор порта, где x=A|B.
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_SyncCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->SYNCSET, Pin);
    else
        WRITE_REG(GPIOx->SYNCCLR, Pin);
}

/**
  * @}
  */

/** @defgroup GPIO_Interrupts Прерывания
  * @{
  */

/**
  * @brief   Настройка режима генерации сигналов прерываний и внешних сигналов запросов
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   IntType  Выбор режима генерации
  * @retval  void
  */
__STATIC_INLINE void GPIO_ITTypeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_IntType_TypeDef IntType)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_GPIO_INT_TYPE(IntType));

    if (IntType == GPIO_IntType_Edge)
        WRITE_REG(GPIOx->INTTYPESET, Pin);
    else
        WRITE_REG(GPIOx->INTTYPECLR, Pin);
}

/**
  * @brief   Настройка полярности генерации прерываний
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   IntPol  Выбор полярности
  * @retval  void
  */
__STATIC_INLINE void GPIO_ITPolConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_IntPol_TypeDef IntPol)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_GPIO_INT_POL(IntPol));

    if (IntPol == GPIO_IntPol_Positive)
        WRITE_REG(GPIOx->INTPOLSET, Pin);
    else
        WRITE_REG(GPIOx->INTPOLCLR, Pin);
}

/**
  * @brief   Настройка режима прерываний по перепадам
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   IntEdge  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void GPIO_ITEdgeConfig(GPIO_TypeDef* GPIOx, uint32_t Pin, GPIO_IntEdge_TypeDef IntEdge)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_GPIO_INT_EDGE(IntEdge));

    if (IntEdge == GPIO_IntEdge_Any)
        WRITE_REG(GPIOx->INTEDGESET, Pin);
    else
        WRITE_REG(GPIOx->INTEDGECLR, Pin);
}

/**
  * @brief   Разрешение генерации прерываний
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_ITCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->INTENSET, Pin);
    else
        WRITE_REG(GPIOx->INTENCLR, Pin);
}

/**
  * @brief   Получение статуса выбранного пина
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @retval  Status  Если выбрано несколько пинов, то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus GPIO_ITStatus(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));

    return (FlagStatus)READ_BIT(GPIOx->INTSTATUS, Pin);
}

/**
  * @brief   Сброс статуса выбранного флага прерывания
  * @param   Pin  Выбор пинов
  * @retval  void
  */
__STATIC_INLINE void GPIO_ITStatusClear(GPIO_TypeDef* GPIOx, uint32_t Pin)
{
    assert_param(IS_GPIO_PIN(Pin));

    WRITE_REG(GPIOx->INTSTATUS, Pin);
}

/**
  * @}
  */

/** @defgroup GPIO_ExternalRequests Генерация внешних запросов
  * @{
  */

/**
  * @brief   Разрешение генерации запросов к DMA
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_DMAReqCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->DMAREQSET, Pin);
    else
        WRITE_REG(GPIOx->DMAREQCLR, Pin);
}

/**
  * @brief   Разрешение генерации сигналов запуска АЦП
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_ADCSOCCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->ADCSOCSET, Pin);
    else
        WRITE_REG(GPIOx->ADCSOCCLR, Pin);
}

/**
  * @brief   Разрешение генерации события RXEV
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_RXEVCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->RXEVSET, Pin);
    else
        WRITE_REG(GPIOx->RXEVCLR, Pin);
}

/**
  * @}
  */

/** @defgroup GPIO_Lock Механизм защиты конфигурации
  * @{
  */
/**
  * @brief   Разрешение изменения состояния защиты пинов. Разрешение применяется спустя несколько тактов.
  * @param   GPIOx  выбор порта, где x=A|B
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void GPIO_LockKeyCmd(GPIO_TypeDef* GPIOx, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->LOCKKEY, (uint32_t)GPIO_LOCKKEY_VAL_UNLOCK);
    else
        WRITE_REG(GPIOx->LOCKKEY, (uint32_t)GPIO_LOCKKEY_VAL_LOCK);
}

/**
  * @brief      Управление защитой конфигурации пина от изменений.
  * @attention  По умолчанию, регистры используемые в функции находятся врежиме "только чтение".
  *             Чтобы разрешить их запись, необходимо воспользоваться функцией @ref GPIO_LockKeyCmd и подождать несколько тактов.
  * @param      GPIOx  выбор порта, где x=A|B
  * @param      Pin  Выбор пинов. Любая совокупность значений значений GPIO_Pin_x (@ref GPIO_Pin_Define).
  * @param      State  Выбор состояния
  * @retval     void
  */
__STATIC_INLINE void GPIO_LockCmd(GPIO_TypeDef* GPIOx, uint32_t Pin, FunctionalState State)
{
    assert_param(IS_GPIO_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(Pin));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
        WRITE_REG(GPIOx->LOCKSET, Pin);
    else
        WRITE_REG(GPIOx->LOCKCLR, Pin);
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

#endif /* __PLIB035_GPIO_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
