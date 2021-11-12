/**
  ******************************************************************************
  * @file    niietcm4_rtc.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с RTC.
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

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_rtc.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup RTC
  * @brief Драйвер для модуля часов реального времени.
  * @{
  */ 

/** @defgroup RTC_Private Приватные данные
  * @{
  */

/** @defgroup RTC_Private_Functions Приватные функции
  * @{
  */

uint32_t bcd2hex (uint32_t a)
{
    if ((a&0x000000F0) == 0) return (a&0x0000000F);
    else return ((a&0x0000000F)+ 10*((a&0x000000F0)>>4));
}

uint32_t hex2bcd (uint32_t x)
{
    uint32_t y;
    y = (x / 10) << 4;
    y = y | (x % 10);
    return (y);
}

void RTC_ShadowUpd(FunctionalState State)
{
    NT_RTC->SHDW_bit.UPDTEN = (uint32_t)State;
}

void RTC_GetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time)
{
    uint32_t time;

    RTC_ShadowUpd(DISABLE);
    time = NT_RTC->TIME;
    RTC_ShadowUpd(ENABLE);

    if (RTC_Format == RTC_Format_BIN)
    {
        RTC_Time->RTC_Hour    = bcd2hex((uint32_t)((time & RTC_TIME_HOUR_Msk) >> RTC_TIME_HOUR_Pos));
        RTC_Time->RTC_Minute  = bcd2hex((uint32_t)((time & RTC_TIME_MINUTE_Msk) >> RTC_TIME_MINUTE_Pos));
        RTC_Time->RTC_Second  = bcd2hex((uint32_t)((time & RTC_TIME_SECOND_Msk) >> RTC_TIME_SECOND_Pos));
        RTC_Time->RTC_Psecond = bcd2hex((uint32_t)((time & RTC_TIME_SPLIT_SEC_Msk) >> RTC_TIME_SPLIT_SEC_Pos));
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        RTC_Time->RTC_Hour    = (uint32_t)((time & RTC_TIME_HOUR_Msk) >> RTC_TIME_HOUR_Pos);
        RTC_Time->RTC_Minute  = (uint32_t)((time & RTC_TIME_MINUTE_Msk) >> RTC_TIME_MINUTE_Pos);
        RTC_Time->RTC_Second  = (uint32_t)((time & RTC_TIME_SECOND_Msk) >> RTC_TIME_SECOND_Pos);
        RTC_Time->RTC_Psecond = (uint32_t)((time & RTC_TIME_SPLIT_SEC_Msk) >> RTC_TIME_SPLIT_SEC_Pos);
    }

}

void RTC_GetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date)
{
    RTC_ShadowUpd(DISABLE);
    if (RTC_Format == RTC_Format_BIN)
    {
        RTC_Date->RTC_Weekday = (RTC_Weekday_TypeDef)bcd2hex(NT_RTC->WDAY);
        RTC_Date->RTC_Day     = bcd2hex(NT_RTC->DAY);
        RTC_Date->RTC_Month   = bcd2hex(NT_RTC->MONTH);
        RTC_Date->RTC_Year    = bcd2hex(NT_RTC->YEAR);
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        RTC_Date->RTC_Weekday = (RTC_Weekday_TypeDef)NT_RTC->WDAY;
        RTC_Date->RTC_Day     = NT_RTC->DAY;
        RTC_Date->RTC_Month   = NT_RTC->MONTH;
        RTC_Date->RTC_Year    = NT_RTC->YEAR;
    }
    RTC_ShadowUpd(ENABLE);
}

void RTC_SetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time)
{
    assert_param(IS_RTC_PSECOND(RTC_Time->RTC_Psecond));
    if (RTC_Format == RTC_Format_BIN)
    {
        assert_param(IS_RTC_SECOND(RTC_Time->RTC_Second));
        assert_param(IS_RTC_MINUTE(RTC_Time->RTC_Minute));
        assert_param(IS_RTC_HOUR(RTC_Time->RTC_Hour));
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        assert_param(IS_RTC_SECOND(bcd2hex(RTC_Time->RTC_Second)));
        assert_param(IS_RTC_MINUTE(bcd2hex(RTC_Time->RTC_Minute)));
        assert_param(IS_RTC_HOUR(bcd2hex(RTC_Time->RTC_Hour)));
    }

    if (RTC_Format == RTC_Format_BIN)
    {
        NT_RTC->HOUR     = hex2bcd(RTC_Time->RTC_Hour);
        NT_RTC->MINUTE   = hex2bcd(RTC_Time->RTC_Minute);
        NT_RTC->SECOND   = hex2bcd(RTC_Time->RTC_Second);
        NT_RTC->PSECONDS = hex2bcd(RTC_Time->RTC_Psecond);
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        NT_RTC->HOUR    = RTC_Time->RTC_Hour;
        NT_RTC->MINUTE   = RTC_Time->RTC_Minute;
        NT_RTC->SECOND   = RTC_Time->RTC_Second;
        NT_RTC->PSECONDS = RTC_Time->RTC_Psecond;
    }
}

void RTC_SetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date)
{
    if (RTC_Format == RTC_Format_BIN)
    {
        assert_param(IS_RTC_WEEKDAY(RTC_Date->RTC_Weekday));
        assert_param(IS_RTC_DAY(RTC_Date->RTC_Day));
        assert_param(IS_RTC_MONTH(RTC_Date->RTC_Month));
        assert_param(IS_RTC_YEAR(RTC_Date->RTC_Year));
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        assert_param(IS_RTC_WEEKDAY(bcd2hex(RTC_Date->RTC_Weekday)));
        assert_param(IS_RTC_DAY(bcd2hex(RTC_Date->RTC_Day)));
        assert_param(IS_RTC_MONTH(bcd2hex(RTC_Date->RTC_Month)));
        assert_param(IS_RTC_YEAR(bcd2hex(RTC_Date->RTC_Year)));
    }

    if (RTC_Format == RTC_Format_BIN)
    {
        NT_RTC->WDAY  = hex2bcd(RTC_Date->RTC_Weekday);
        NT_RTC->DAY   = hex2bcd(RTC_Date->RTC_Day);
        NT_RTC->MONTH = hex2bcd(RTC_Date->RTC_Month);
        NT_RTC->YEAR  = hex2bcd(RTC_Date->RTC_Year);
    }
    else /* (RTC_Format == RTC_Format_BCD) */
    {
        NT_RTC->WDAY  = RTC_Date->RTC_Weekday;
        NT_RTC->DAY   = RTC_Date->RTC_Day;
        NT_RTC->MONTH = RTC_Date->RTC_Month;
        NT_RTC->YEAR  = RTC_Date->RTC_Year;
    }
}

/**
  * @}
  */

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
