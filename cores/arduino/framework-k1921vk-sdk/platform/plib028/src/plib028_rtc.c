/**
  ******************************************************************************
  * @file    plib028_rtc.c
  *
  * @brief   Файл содержит реализацию функций для работы с RTC
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

/* Includes ------------------------------------------------------------------*/
#include "plib028_rtc.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup RTC
  * @{
  */

/** @defgroup RTC_Private Приватные данные
  * @{
  */

/** @defgroup RTC_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Private_Functions Приватные функции
  * @{
  */

uint32_t bcd2hex(uint32_t a)
{
    if ((a & 0x000000F0) == 0)
        return (a & 0x0000000F);
    else
        return ((a & 0x0000000F) + 10 * ((a & 0x000000F0) >> 4));
}

uint32_t hex2bcd(uint32_t x)
{
    uint32_t y;
    y = (x / 10) << 4;
    y = y | (x % 10);
    return (y);
}

void RTC_GetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time)
{
    uint32_t time;

    RTC_ShadowCmd(DISABLE);
    time = READ_REG(RTC->TIME);
    RTC_ShadowCmd(ENABLE);

    if (RTC_Format == RTC_Format_BIN) {
        RTC_Time->Hour = bcd2hex((uint32_t)((time & RTC_TIME_HOUR_Msk) >> RTC_TIME_HOUR_Pos));
        RTC_Time->Minute = bcd2hex((uint32_t)((time & RTC_TIME_MIN_Msk) >> RTC_TIME_MIN_Pos));
        RTC_Time->Second = bcd2hex((uint32_t)((time & RTC_TIME_SEC_Msk) >> RTC_TIME_SEC_Pos));
        RTC_Time->PSecond = bcd2hex((uint32_t)((time & RTC_TIME_POS_Msk) >> RTC_TIME_POS_Pos));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        RTC_Time->Hour = (uint32_t)((time & RTC_TIME_HOUR_Msk) >> RTC_TIME_HOUR_Pos);
        RTC_Time->Minute = (uint32_t)((time & RTC_TIME_MIN_Msk) >> RTC_TIME_MIN_Pos);
        RTC_Time->Second = (uint32_t)((time & RTC_TIME_SEC_Msk) >> RTC_TIME_SEC_Pos);
        RTC_Time->PSecond = (uint32_t)((time & RTC_TIME_POS_Msk) >> RTC_TIME_POS_Pos);
    }
}

void RTC_GetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date)
{
    RTC_ShadowCmd(DISABLE);
    if (RTC_Format == RTC_Format_BIN) {
        RTC_Date->Weekday = (RTC_Weekday_TypeDef)bcd2hex(READ_REG(RTC->DOW));
        RTC_Date->Day = bcd2hex(READ_REG(RTC->DAY));
        RTC_Date->Month = bcd2hex(READ_REG(RTC->MONTH));
        RTC_Date->Year = bcd2hex(READ_REG(RTC->YEAR));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        RTC_Date->Weekday = (RTC_Weekday_TypeDef)READ_REG(RTC->DOW);
        RTC_Date->Day = READ_REG(RTC->DAY);
        RTC_Date->Month = READ_REG(RTC->MONTH);
        RTC_Date->Year = READ_REG(RTC->YEAR);
    }
    RTC_ShadowCmd(ENABLE);
}

void RTC_SetTime(RTC_Format_TypeDef RTC_Format, RTC_Time_TypeDef* RTC_Time)
{
    assert_param(IS_RTC_PSECOND(RTC_Time->PSecond));
    if (RTC_Format == RTC_Format_BIN) {
        assert_param(IS_RTC_SECOND(RTC_Time->Second));
        assert_param(IS_RTC_MINUTE(RTC_Time->Minute));
        assert_param(IS_RTC_HOUR(RTC_Time->Hour));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        assert_param(IS_RTC_SECOND(bcd2hex(RTC_Time->Second)));
        assert_param(IS_RTC_MINUTE(bcd2hex(RTC_Time->Minute)));
        assert_param(IS_RTC_HOUR(bcd2hex(RTC_Time->Hour)));
    }

    if (RTC_Format == RTC_Format_BIN) {
        WRITE_REG(RTC->HOUR, hex2bcd(RTC_Time->Hour));
        WRITE_REG(RTC->MIN, hex2bcd(RTC_Time->Minute));
        WRITE_REG(RTC->SEC, hex2bcd(RTC_Time->Second));
        WRITE_REG(RTC->POS, hex2bcd(RTC_Time->PSecond));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        WRITE_REG(RTC->HOUR, RTC_Time->Hour);
        WRITE_REG(RTC->MIN, RTC_Time->Minute);
        WRITE_REG(RTC->SEC, RTC_Time->Second);
        WRITE_REG(RTC->POS, RTC_Time->PSecond);
    }
}

void RTC_SetDate(RTC_Format_TypeDef RTC_Format, RTC_Date_TypeDef* RTC_Date)
{
    if (RTC_Format == RTC_Format_BIN) {
        assert_param(IS_RTC_WEEKDAY(RTC_Date->Weekday));
        assert_param(IS_RTC_DAY(RTC_Date->Day));
        assert_param(IS_RTC_MONTH(RTC_Date->Month));
        assert_param(IS_RTC_YEAR(RTC_Date->Year));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        assert_param(IS_RTC_WEEKDAY(bcd2hex(RTC_Date->Weekday)));
        assert_param(IS_RTC_DAY(bcd2hex(RTC_Date->Day)));
        assert_param(IS_RTC_MONTH(bcd2hex(RTC_Date->Month)));
        assert_param(IS_RTC_YEAR(bcd2hex(RTC_Date->Year)));
    }

    if (RTC_Format == RTC_Format_BIN) {
        WRITE_REG(RTC->DOW, hex2bcd(RTC_Date->Weekday));
        WRITE_REG(RTC->DAY, hex2bcd(RTC_Date->Day));
        WRITE_REG(RTC->MONTH, hex2bcd(RTC_Date->Month));
        WRITE_REG(RTC->YEAR, hex2bcd(RTC_Date->Year));
    } else /* (RTC_Format == RTC_Format_BCD) */
    {
        WRITE_REG(RTC->DOW, RTC_Date->Weekday);
        WRITE_REG(RTC->DAY, RTC_Date->Day);
        WRITE_REG(RTC->MONTH, RTC_Date->Month);
        WRITE_REG(RTC->YEAR, RTC_Date->Year);
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

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
