/**
  ******************************************************************************
  * @file    niietcm4_rtc.h
  *
  * @brief   Файл содержит все прототипы функций для таймеров
  *
  * @author  НИИЭТ
  *             - Александр Дыхно (DAV), dykhno@niiet.ru
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    04.12.2015
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
#ifndef __NIIETCM4_RTC_H
#define __NIIETCM4_RTC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup RTC
  * @{
  */

/** @defgroup RTC_Exported_Types Типы
  * @{
  */

/**
  * @brief Макрос проверки попадания значений долей секунд в допустимый диапазон.
  */

#define IS_RTC_PSECOND(PSECOND) ((PSECOND) <= 0x3FF)

/**
  * @brief Макрос проверки попадания значений секунд в допустимый диапазон.
  */

#define IS_RTC_SECOND(SECOND) ((SECOND) <= 59)

/**
  * @brief Макрос проверки попадания значений минут в допустимый диапазон.
  */

#define IS_RTC_MINUTE(MINUTE) ((MINUTE) <= 59)

/**
  * @brief Макрос проверки попадания значений часов в допустимый диапазон.
  */

#define IS_RTC_HOUR(HOUR) ((HOUR) <= 23)

/**
  * @brief  Дни недели.
  */

typedef enum
{
    RTC_Weekday_Monday      =  ((uint32_t)0x01), /*!< Monday */
    RTC_Weekday_Tuesday     =  ((uint32_t)0x02), /*!< Tuesday */
    RTC_Weekday_Wednesday   =  ((uint32_t)0x03), /*!< Wednesday */
    RTC_Weekday_Thursday    =  ((uint32_t)0x04), /*!< Thursday */
    RTC_Weekday_Friday      =  ((uint32_t)0x05), /*!< Friday */
    RTC_Weekday_Saturday    =  ((uint32_t)0x06), /*!< Saturday */
    RTC_Weekday_Sunday      =  ((uint32_t)0x07)  /*!< Sunday */
}
RTC_Weekday_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RTC_Weekday_TypeDef.
  */

#define IS_RTC_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_Weekday_Monday)    || \
                                 ((WEEKDAY) == RTC_Weekday_Tuesday)   || \
                                 ((WEEKDAY) == RTC_Weekday_Wednesday) || \
                                 ((WEEKDAY) == RTC_Weekday_Thursday)  || \
                                 ((WEEKDAY) == RTC_Weekday_Friday)    || \
                                 ((WEEKDAY) == RTC_Weekday_Saturday)  || \
                                 ((WEEKDAY) == RTC_Weekday_Sunday))

/**
  * @brief Макрос проверки попадания значений дней в допустимый диапазон.
  */

#define IS_RTC_DAY(DAY) (((DAY) > 0) && ((DAY) <= 31))

/**
  * @brief  Месяцы.
  */

typedef enum
{
    RTC_Month_January   =  ((uint32_t)0x01), /*!< January */
    RTC_Month_February  =  ((uint32_t)0x02), /*!< February */
    RTC_Month_March     =  ((uint32_t)0x03), /*!< March */
    RTC_Month_April     =  ((uint32_t)0x04), /*!< April */
    RTC_Month_May       =  ((uint32_t)0x05), /*!< May */
    RTC_Month_June      =  ((uint32_t)0x06), /*!< June */
    RTC_Month_July      =  ((uint32_t)0x07), /*!< July */
    RTC_Month_August    =  ((uint32_t)0x08), /*!< August */
    RTC_Month_September =  ((uint32_t)0x09), /*!< September */
    RTC_Month_October   =  ((uint32_t)0x10), /*!< October */
    RTC_Month_November  =  ((uint32_t)0x11), /*!< November */
    RTC_Month_December  =  ((uint32_t)0x12)  /*!< December */
}
RTC_Month_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RTC_Month_TypeDef.
  */

#define IS_RTC_MONTH(MONTH) (((MONTH) == RTC_Month_January)     || \
                             ((MONTH) == RTC_Month_February)    || \
                             ((MONTH) == RTC_Month_March)       || \
                             ((MONTH) == RTC_Month_April)       || \
                             ((MONTH) == RTC_Month_May)         || \
                             ((MONTH) == RTC_Month_June)        || \
                             ((MONTH) == RTC_Month_July)        || \
                             ((MONTH) == RTC_Month_August)      || \
                             ((MONTH) == RTC_Month_September)   || \
                             ((MONTH) == RTC_Month_October)     || \
                             ((MONTH) == RTC_Month_November)    || \
                             ((MONTH) == RTC_Month_December))

/**
  * @brief Макрос проверки попадания значений лет в допустимый диапазон.
  */

#define IS_RTC_YEAR(YEAR) ((YEAR) <= 99)

/**
  * @brief Формат ввода/вывода времени и даты.
  */

typedef enum
{
  RTC_Format_BIN,   /*!< Бинарный формат  */
  RTC_Format_BCD    /*!< Двоично-десятичный формат */
}
RTC_Format_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref RTC_Format_TypeDef.
  */

#define IS_RTC_FORMAT(FORMAT) (((FORMAT) == RTC_Format_BIN) || \
                               ((FORMAT) == RTC_Format_BCD))

/**
  * @brief  Структура времени.
  *
  */

typedef struct
{
    uint32_t RTC_Psecond;     /*!< Значение долей секунд.
                                Параметр может принимать любое значение из диапазона 0-1023. */
    uint32_t RTC_Second;      /*!< Значение секунд.
                                Если выбран бинарный формат @ref RTC_Format_BIN,
                                    то допустимые значения от 0 до 59.
                                Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                    то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                                    0x30–0x39, 0x40–0x49, 0x50–0x59. */
    uint32_t RTC_Minute;      /*!< Значение минут.
                                Если выбран бинарный формат @ref RTC_Format_BIN,
                                    то допустимые значения от 0 до 59.
                                Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                    то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                                    0x30–0x39, 0x40–0x49, 0x50–0x59. */
    uint32_t RTC_Hour;        /*!< Значение часов.
                                Если выбран бинарный формат @ref RTC_Format_BIN,
                                    то допустимые значения от 0 до 23.
                                Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                    то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x23. */
}RTC_Time_TypeDef;

/**
  * @brief  Структура даты.
  *
  */

typedef struct
{
    RTC_Weekday_TypeDef RTC_Weekday;    /*!< Значение дней недели.
                                            Параметр может принимать любое значение из @ref RTC_Weekday_TypeDef. */
    uint32_t RTC_Day;                   /*!< Значение дней.
                                            Если выбран бинарный формат @ref RTC_Format_BIN,
                                                то допустимые значения от 1 до 31.
                                            Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                                то допустимые значения 0x01-0x09, 0x10–0x19, 0x20–0x29, 0x30–0x31. */
    uint32_t RTC_Month;                 /*!< Значение месяцев.
                                            Если выбран бинарный формат @ref RTC_Format_BIN,
                                                то допустимые значения от 1 до 12.
                                            Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                                то допустимые значения 0x01-0x09, 0x10–0x12. */
    uint32_t RTC_Year;                   /*!< Значение лет.
                                            Если выбран бинарный формат @ref RTC_Format_BIN,
                                                то допустимые значения от 0 до 99.
                                            Если выбран двоично-десятичный формат @ref RTC_Format_BCD,
                                                то допустимые значения 0x00-0x09, 0x10–0x19, 0x20–0x29,
                                                0x30–0x39, 0x40–0x49, 0x50–0x59, 0x60–0x69, 0x70–0x79,
                                                0x80–0x89, 0x90–0x99. */
}RTC_Date_TypeDef;

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
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_RTC_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
