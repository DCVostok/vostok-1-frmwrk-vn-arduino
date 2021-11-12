/**
  ******************************************************************************
  * @file    plib028_rtc.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          RTC, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_RTC_H
#define __PLIB028_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup RTC
  * @brief Драйвер для работы с RTC
  * @{
  */

/** @defgroup RTC_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Exported_Types Типы
  * @{
  */

/**
  * @brief  Дни недели
  */
typedef enum {
    RTC_Weekday_Monday = 0x01UL,    /*!< Monday */
    RTC_Weekday_Tuesday = 0x02UL,   /*!< Tuesday */
    RTC_Weekday_Wednesday = 0x03UL, /*!< Wednesday */
    RTC_Weekday_Thursday = 0x04UL,  /*!< Thursday */
    RTC_Weekday_Friday = 0x05UL,    /*!< Friday */
    RTC_Weekday_Saturday = 0x06UL,  /*!< Saturday */
    RTC_Weekday_Sunday = 0x07UL     /*!< Sunday */
} RTC_Weekday_TypeDef;
#define IS_RTC_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_Weekday_Monday) ||    \
                                 ((WEEKDAY) == RTC_Weekday_Tuesday) ||   \
                                 ((WEEKDAY) == RTC_Weekday_Wednesday) || \
                                 ((WEEKDAY) == RTC_Weekday_Thursday) ||  \
                                 ((WEEKDAY) == RTC_Weekday_Friday) ||    \
                                 ((WEEKDAY) == RTC_Weekday_Saturday) ||  \
                                 ((WEEKDAY) == RTC_Weekday_Sunday))

/**
  * @brief  Месяцы
  */
typedef enum {
    RTC_Month_January = 0x01UL,   /*!< January */
    RTC_Month_February = 0x02UL,  /*!< February */
    RTC_Month_March = 0x03UL,     /*!< March */
    RTC_Month_April = 0x04UL,     /*!< April */
    RTC_Month_May = 0x05UL,       /*!< May */
    RTC_Month_June = 0x06UL,      /*!< June */
    RTC_Month_July = 0x07UL,      /*!< July */
    RTC_Month_August = 0x08UL,    /*!< August */
    RTC_Month_September = 0x09UL, /*!< September */
    RTC_Month_October = 0x10UL,   /*!< October */
    RTC_Month_November = 0x11UL,  /*!< November */
    RTC_Month_December = 0x12UL   /*!< December */
} RTC_Month_TypeDef;
#define IS_RTC_MONTH(MONTH) (((MONTH) == RTC_Month_January) ||   \
                             ((MONTH) == RTC_Month_February) ||  \
                             ((MONTH) == RTC_Month_March) ||     \
                             ((MONTH) == RTC_Month_April) ||     \
                             ((MONTH) == RTC_Month_May) ||       \
                             ((MONTH) == RTC_Month_June) ||      \
                             ((MONTH) == RTC_Month_July) ||      \
                             ((MONTH) == RTC_Month_August) ||    \
                             ((MONTH) == RTC_Month_September) || \
                             ((MONTH) == RTC_Month_October) ||   \
                             ((MONTH) == RTC_Month_November) ||  \
                             ((MONTH) == RTC_Month_December))

/**
  * @brief Формат ввода/вывода времени и даты
  */
typedef enum {
    RTC_Format_BIN, /*!< Бинарный формат  */
    RTC_Format_BCD  /*!< Двоично-десятичный формат */
} RTC_Format_TypeDef;
#define IS_RTC_FORMAT(FORMAT) (((FORMAT) == RTC_Format_BIN) || \
                               ((FORMAT) == RTC_Format_BCD))

#define IS_RTC_PSECOND(PSECOND) ((PSECOND) <= 0x3FF)
#define IS_RTC_SECOND(SECOND) ((SECOND) <= 59)
#define IS_RTC_MINUTE(MINUTE) ((MINUTE) <= 59)
#define IS_RTC_HOUR(HOUR) ((HOUR) <= 23)
#define IS_RTC_DAY(DAY) (((DAY) > 0) && ((DAY) <= 31))
#define IS_RTC_YEAR(YEAR) ((YEAR) <= 99)

/**
  * @brief  Структура времени
  *
  */
typedef struct
{
    uint32_t PSecond; /*!< Значение долей секунд.
                           Параметр может принимать любое значение из диапазона 0-1023. */
    uint32_t Second;  /*!< Значение секунд.
                           Если выбран бинарный формат @ref RTC_Format_BIN,
                               то допустимые значения от 0 до 59.
                           Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                               то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                               0x30–0x39, 0x40–0x49, 0x50–0x59. */
    uint32_t Minute;  /*!< Значение минут.
                           Если выбран бинарный формат @ref RTC_Format_BIN,
                               то допустимые значения от 0 до 59.
                           Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                               то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                               0x30–0x39, 0x40–0x49, 0x50–0x59. */
    uint32_t Hour;    /*!< Значение часов.
                           Если выбран бинарный формат @ref RTC_Format_BIN,
                               то допустимые значения от 0 до 23.
                           Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                               то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x23. */
} RTC_Time_TypeDef;

/**
  * @brief  Структура даты
  *
  */
typedef struct
{
    RTC_Weekday_TypeDef Weekday; /*!< Значение дней недели.
                                      Параметр может принимать любое значение из @ref RTC_Weekday_TypeDef. */
    uint32_t Day;                /*!< Значение дней.
                                      Если выбран бинарный формат @ref RTC_Format_BIN,
                                          то допустимые значения от 1 до 31.
                                      Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                          то допустимые значения 0x01-0x09, 0x10–0x19, 0x20–0x29, 0x30–0x31. */
    uint32_t Month;              /*!< Значение месяцев.
                                      Если выбран бинарный формат @ref RTC_Format_BIN,
                                          то допустимые значения от 1 до 12.
                                      Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                          то допустимые значения 0x01-0x09, 0x10–0x12. */
    uint32_t Year;               /*!< Значение лет.
                                      Если выбран бинарный формат @ref RTC_Format_BIN,
                                          то допустимые значения от 0 до 99.
                                      Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                          то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                                          0x30–0x39, 0x40–0x49, 0x50–0x59, 0x60–0x69, 0x70–0x79,
                                          0x80–0x89, 0x90–0x99. */
} RTC_Date_TypeDef;

/**
  * @}
  */

/** @defgroup RTC_Exported_Functions Функции
  * @{
  */

void RTC_GetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time);
void RTC_GetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date);
void RTC_SetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time);
void RTC_SetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date);

/**
  * @brief   Разрешение обновления теневых регистров
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RTC_ShadowCmd(FunctionalState State)
{
    WRITE_REG(RTC->SHDW_bit.UPDTEN, (uint32_t)State);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_RTC_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
