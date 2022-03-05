/**
  ******************************************************************************
  * @file    niietcm4_gpio.h
  *
  * @brief   Файл содержит все прототипы функций для GPIO
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    26.10.2015
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
#ifndef __NIIETCM4_GPIO_H
#define __NIIETCM4_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/** @defgroup GPIO_Exported_Types Типы
  * @{
  */

/**
   * @brief Макрос проверки соответсвия величины периода фильтрации разрешенному диапазону.
   */

#define IS_GPIO_QUAL_PERIOD(PERIOD) (((PERIOD) & ((uint32_t)0xFFFFFF00)) == ((uint32_t)0x00))

/**
  * @brief  Тип, определяющий состояния бита.
  */

typedef enum
{
    Bit_CLEAR = 0,    /*!< Бит очищен. */
    Bit_SET           /*!< Бит установлен. */
}BitAction;

/**
  * @brief Макрос проверки аргументов типа @ref BitAction.
  */

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_CLEAR) || ((ACTION) == Bit_SET))

/**
  * @brief  Выбор направления работы пина.
  */

typedef enum
{
    GPIO_Dir_In,         /*!< Пин настроен на вход. */
    GPIO_Dir_Out         /*!< Пин настроен на выход. */
}GPIO_Dir_TypeDef;

/**
   * @brief Макрос проверки аргументов типа @ref GPIO_Dir_TypeDef.
   */

#define IS_GPIO_DIR(DIR) (((DIR) == GPIO_Dir_In) || \
                           ((DIR) == GPIO_Dir_Out))

/**
  * @brief  Выбор режима работы пина.
  */

typedef enum
{
    GPIO_Mode_IO,        /*!< Пин в режиме ввода-вывода. */
    GPIO_Mode_AltFunc    /*!< Пин в режиме альтернативной функции. */
}GPIO_Mode_TypeDef;

/**
   * @brief Макрос проверки аргументов типа @ref GPIO_Mode_TypeDef.
   */

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IO) || \
                            ((MODE) == GPIO_Mode_AltFunc))

/**
  * @brief  Выбор события для возникновения прерывания.
  */

typedef enum
{
    GPIO_IntType_Level,  /*!< Прерывание по уровню. */
    GPIO_IntType_Edge    /*!< Прерывание по перепаду. */
}GPIO_IntType_TypeDef;

/**
   * @brief Макрос проверки аргументов типа @ref GPIO_IntType_TypeDef.
   */

#define IS_GPIO_INT_TYPE(INT_TYPE) (((INT_TYPE) == GPIO_IntType_Level) || \
                                    ((INT_TYPE) == GPIO_IntType_Edge))

/**
  * @brief  Выбор полярности события для возникновения прерывания.
  */

typedef enum
{
    GPIO_IntPol_Neg,     /*!< Прерывание по низкому уровню или отрицательному фронту. */
    GPIO_IntPol_Pos      /*!< Прерывание по высокому уровню или положительному фронту. */
}GPIO_IntPol_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_IntPol_TypeDef.
  */

#define IS_GPIO_INT_POL(INT_POL) (((INT_POL) == GPIO_IntPol_Neg) || \
                                  ((INT_POL) == GPIO_IntPol_Pos))

/**
  * @brief  Включение выхода пина.
  */

typedef enum
{
    GPIO_Out_Dis,        /*!< Пин в третьем состоянии. */
    GPIO_Out_En          /*!< Пин работает как выход. */
}GPIO_Out_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_Out_TypeDef.
  */

#define IS_GPIO_OUT(OUT) (((OUT) == GPIO_Out_Dis) || \
                          ((OUT) == GPIO_Out_En))

/**
  * @brief  Выбор режима работы выходных каскадов.
  */

typedef enum
{
    GPIO_OutMode_PP,    /*!< Режим пуш-пулл. */
    GPIO_OutMode_OD     /*!< Режим открытого коллектора. */
}GPIO_OutMode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_OutMode_TypeDef.
  */

#define IS_GPIO_OUT_MODE(OUT_MODE) (((OUT_MODE) == GPIO_OutMode_PP) || \
                                    ((OUT_MODE) == GPIO_OutMode_OD))

/**
  * @brief  Включение подтяжки к питанию.
  */

typedef enum
{
    GPIO_PullUp_Dis,     /*!< Внутренняя подтяжка к питанию выключена. */
    GPIO_PullUp_En       /*!< Внутренняя подтяжка к питанию включена. */
}GPIO_PullUp_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_PullUp_TypeDef.
  */

#define IS_GPIO_PULLUP(PULLUP)  (((PULLUP) == GPIO_PullUp_Dis) || \
                                 ((PULLUP) == GPIO_PullUp_En))

/**
  * @brief  Включение режима пересинхронизации входов через 2 триггера-защелки.
  */

typedef enum
{
    GPIO_Sync_Dis,       /*!< Пересинхронизация входа выключена. */
    GPIO_Sync_En         /*!< Пересинхронизация входа включена. */
}GPIO_Sync_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_Sync_TypeDef.
  */

#define IS_GPIO_SYNC(SYNC) (((SYNC) == GPIO_Sync_Dis) || \
                            ((SYNC) == GPIO_Sync_En))

/**
  * @brief  Включение входного фильтра.
  */

typedef enum
{
    GPIO_Qual_Dis,       /*!< Входной фильтр выключен. */
    GPIO_Qual_En         /*!< Входной фильтр включен. */
}GPIO_Qual_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_Qual_TypeDef.
  */

#define IS_GPIO_QUAL(QUAL) (((QUAL) == GPIO_Qual_Dis) || \
                            ((QUAL) == GPIO_Qual_En))

/**
  * @brief  Выбор режима работы входного фильтра.
  */

typedef enum
{
    GPIO_QualMode_3sample,  /*!< Используется 3 отсчета для фильтрации. */
    GPIO_QualMode_6sample   /*!< Используется 6 отсчетов для фильтрации. */
}GPIO_QualMode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_QualMode_TypeDef.
  */

#define IS_GPIO_QUAL_MODE(QUAL_MODE) (((QUAL_MODE) == GPIO_QualMode_3sample) || \
                                       ((QUAL_MODE) == GPIO_QualMode_6sample))

/**
  * @brief  Выбор номера альтернативной функции пина.
  */

typedef enum
{
    GPIO_AltFunc_1,     /*!< Альтернативная функция 1. */
    GPIO_AltFunc_2,     /*!< Альтернативная функция 2. */
    GPIO_AltFunc_3      /*!< Альтернативная функция 3. */
}GPIO_AltFunc_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref GPIO_AltFunc_TypeDef.
  */

#define IS_GPIO_ALT_FUNC(ALT_FUNC) (((ALT_FUNC) == GPIO_AltFunc_1) || \
                                    ((ALT_FUNC) == GPIO_AltFunc_2) || \
                                    ((ALT_FUNC) == GPIO_AltFunc_3))

/**
  * @brief  Структура инициализации GPIO
  */

typedef struct
{
    uint32_t GPIO_Pin;                    /*!< Определяет пины, которые будут настроены.
                                               Параметр может принимать любое значение из @ref GPIO_pins_define. */
    GPIO_Dir_TypeDef GPIO_Dir;             /*!< Определеяет направление работы выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_Dir_TypeDef. */
    GPIO_Out_TypeDef GPIO_Out;             /*!< Определяет включение выхода выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_Out_TypeDef. */
    GPIO_Mode_TypeDef GPIO_Mode;           /*!< Определяет режим работы выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_Mode_TypeDef. */
    GPIO_AltFunc_TypeDef GPIO_AltFunc;    /*!< Определяет номер альтернативной функции выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_AltFunc_TypeDef. */
    GPIO_OutMode_TypeDef GPIO_OutMode;    /*!< Определяет режим работы выходных каскадов выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_OutMode_TypeDef. */
    GPIO_PullUp_TypeDef GPIO_PullUp;       /*!< Определяет включение внутренней подтяжки к питанию выбранных пинов.
                                               Параметр может принимать любое значение из @ref GPIO_PullUp_TypeDef. */
}GPIO_Init_TypeDef;

/**
  * @}
  */

/** @defgroup GPIO_Exported_Constants Константы
  * @{
  */

/** @defgroup GPIO_pins_define Маски пинов
  * @{
  */

#define GPIO_Pin_0                 ((uint32_t)0x0001)  /*!< Пин 0 выбран. */
#define GPIO_Pin_1                 ((uint32_t)0x0002)  /*!< Пин 1 выбран. */
#define GPIO_Pin_2                 ((uint32_t)0x0004)  /*!< Пин 2 выбран. */
#define GPIO_Pin_3                 ((uint32_t)0x0008)  /*!< Пин 3 выбран. */
#define GPIO_Pin_4                 ((uint32_t)0x0010)  /*!< Пин 4 выбран. */
#define GPIO_Pin_5                 ((uint32_t)0x0020)  /*!< Пин 5 выбран. */
#define GPIO_Pin_6                 ((uint32_t)0x0040)  /*!< Пин 6 выбран. */
#define GPIO_Pin_7                 ((uint32_t)0x0080)  /*!< Пин 7 выбран. */
#define GPIO_Pin_8                 ((uint32_t)0x0100)  /*!< Пин 8 выбран. */
#define GPIO_Pin_9                 ((uint32_t)0x0200)  /*!< Пин 9 выбран. */
#define GPIO_Pin_10                ((uint32_t)0x0400)  /*!< Пин 10 выбран. */
#define GPIO_Pin_11                ((uint32_t)0x0800)  /*!< Пин 11 выбран. */
#define GPIO_Pin_12                ((uint32_t)0x1000)  /*!< Пин 12 выбран. */
#define GPIO_Pin_13                ((uint32_t)0x2000)  /*!< Пин 13 выбран. */
#define GPIO_Pin_14                ((uint32_t)0x4000)  /*!< Пин 14 выбран. */
#define GPIO_Pin_15                ((uint32_t)0x8000)  /*!< Пин 15 выбран. */
#define GPIO_Pin_0_3               ((uint32_t)0x000F)  /*!< Пины 0-3 выбраны. */
#define GPIO_Pin_3_0               GPIO_Pin_0_3        /*!< Пины 3-0 выбраны. */
#define GPIO_Pin_4_7               ((uint32_t)0x00F0)  /*!< Пины 4-7 выбраны. */
#define GPIO_Pin_7_4               GPIO_Pin_4_7        /*!< Пины 7-4 выбраны. */
#define GPIO_Pin_8_11              ((uint32_t)0x0F00)  /*!< Пины 8-11 выбраны. */
#define GPIO_Pin_11_8              GPIO_Pin_8_11       /*!< Пины 11-8 выбраны. */
#define GPIO_Pin_12_15             ((uint32_t)0xF000)  /*!< Пины 12-15 выбраны. */
#define GPIO_Pin_15_12             GPIO_Pin_12_15      /*!< Пины 15-12 выбраны. */
#define GPIO_Pin_0_7               ((uint32_t)0x00FF)  /*!< Пины 0-7 выбраны. */
#define GPIO_Pin_7_0               GPIO_Pin_0_7        /*!< Пины 7-0 выбраны. */
#define GPIO_Pin_8_15              ((uint32_t)0xFF00)  /*!< Пины 8-15 выбраны. */
#define GPIO_Pin_15_8              GPIO_Pin_8_15       /*!< Пины 15-8 выбраны. */
#define GPIO_Pin_All               ((uint32_t)0xFFFF)  /*!< Все пины выбраны. */

/**
  * @brief Макрос проверки номеров пинов на попадание в допустимый диапазон.
  */

#define IS_GPIO_PIN(PIN) (((PIN) != (uint32_t)0x0000) && (((PIN) & (uint32_t)0xFFFF0000) == ((uint32_t)0x0000)))


/**
  * @brief Макрос проверки номера пина при работе с пинами по отдельности.
  */

#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || \
                              ((PIN) == GPIO_Pin_3) || \
                              ((PIN) == GPIO_Pin_4) || \
                              ((PIN) == GPIO_Pin_5) || \
                              ((PIN) == GPIO_Pin_6) || \
                              ((PIN) == GPIO_Pin_7) || \
                              ((PIN) == GPIO_Pin_8) || \
                              ((PIN) == GPIO_Pin_9) || \
                              ((PIN) == GPIO_Pin_10) || \
                              ((PIN) == GPIO_Pin_11) || \
                              ((PIN) == GPIO_Pin_12) || \
                              ((PIN) == GPIO_Pin_13) || \
                              ((PIN) == GPIO_Pin_14) || \
                              ((PIN) == GPIO_Pin_15))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions Функции
  * @{
  */

/** @defgroup GPIO_Init_Deinit Инициализация и деинициализация
  * @{
  */

void GPIO_DeInit(NT_GPIO_TypeDef* GPIOx);
void GPIO_Init(NT_GPIO_TypeDef* GPIOx, GPIO_Init_TypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_Init_TypeDef* GPIO_InitStruct);

/**
  * @}
  */

/** @defgroup GPIO_Config Конфигурация
  * @{
  */

void GPIO_AltFuncConfig(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIO_AltFunc_TypeDef GPIO_AltFunc);

/**
  * @}
  */

/** @defgroup GPIO_Read_Write Чтение и запись
  * @{
  */

/** @defgroup GPIO_Read Чтение
  * @{
  */

uint32_t GPIO_ReadBit(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
uint32_t GPIO_Read(NT_GPIO_TypeDef* GPIOx);
uint32_t GPIO_ReadMask(NT_GPIO_TypeDef* GPIOx, uint32_t MaskVal);

/**
  * @}
  */

/** @defgroup GPIO_Write Запись
  * @{
  */

void GPIO_WriteBit(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(NT_GPIO_TypeDef* GPIOx, uint32_t PortVal);
void GPIO_WriteMask(NT_GPIO_TypeDef* GPIOx, uint32_t MaskVal, uint32_t PortVal);

/**
  * @}
  */

/** @defgroup GPIO_Bit_Operations Битовые операции
  * @{
  */

void GPIO_SetBits(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_ClearBits(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_ToggleBits(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIO_Qualifier Фильтрация
  * @{
  */

void GPIO_QualConfig(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIO_QualMode_TypeDef Mode, uint32_t SamplePerod);
void GPIO_QualCmd(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, FunctionalState State);
void GPIO_SyncCmd(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, FunctionalState State);

/**
  * @}
  */

/** @defgroup GPIO_Interrupts Прерывания
  * @{
  */

void GPIO_ITConfig(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIO_IntType_TypeDef IntType, GPIO_IntPol_TypeDef IntPol);
void GPIO_ITCmd(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, FunctionalState State);
void GPIO_ITStatusClear(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
FlagStatus GPIO_ITStatus(NT_GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_GPIO_H */

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
