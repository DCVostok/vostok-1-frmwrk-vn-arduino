/**
  ******************************************************************************
  * @file    plib035_rcu.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          RCU (Reset & Clock control Unit), а также сопутствующие
  *          макроопределения и перечисления
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
#ifndef __PLIB035_RCU_H
#define __PLIB035_RCU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup RCU
  * @brief Драйвер для работы с тактированием и сбросом периферийных блоков
  * @{
  */

/** @defgroup RCU_Exported_Defines Константы
  * @{
  */

/** @defgroup RCU_ClkStatus_Define Cтатусы источников тактового сигнала
  * @{
  */

#define RCU_ClkStatus_SysClkFail RCU_SYSCLKSTAT_SYSFAIL_Msk          /*!< Ошибка текущей системной частоты */
#define RCU_ClkStatus_OSEClkFail RCU_SYSCLKSTAT_OSECLKERR_Msk       /*!< Ошибка сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkFail RCU_SYSCLKSTAT_PLLCLKERR_Msk       /*!< Ошибка сигнала с PLL */
#define RCU_ClkStatus_PLLDivClkFail RCU_SYSCLKSTAT_PLLDIVCLKERR_Msk /*!< Ошибка сигнала с деленного выхода PLL */
#define RCU_ClkStatus_OSEClkGood RCU_SYSCLKSTAT_OSECLKOK_Msk       /*!< Нормальная работа сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkGood RCU_SYSCLKSTAT_PLLCLKOK_Msk       /*!< Нормальная работа сигнала с PLL */
#define RCU_ClkStatus_PLLDivClkGood RCU_SYSCLKSTAT_PLLDIVCLKOK_Msk /*!< Нормальная работа сигнала с деленного выхода PLL */

#define IS_RCU_CLK_STATUS(VALUE) (((VALUE) == RCU_ClkStatus_SysClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_OSEClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLDivClkFail) || \
                                  ((VALUE) == RCU_ClkStatus_OSEClkGood) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLClkGood) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLDivClkGood))
/**
  * @}
  */

/** @defgroup RCU_RstStatus_Define Источник, вызвавший последний сброс системы
  * @{
  */

#define RCU_RstStatus_POR RCU_SYSRSTSTAT_POR_Msk       /*!< Сброс от блока POR */
#define RCU_RstStatus_WDT RCU_SYSRSTSTAT_WDOG_Msk      /*!< Сброс от сторожевого таймера */
#define RCU_RstStatus_Sys RCU_SYSRSTSTAT_SYSRST_Msk    /*!< Системный сброс */
#define RCU_RstStatus_LockUp RCU_SYSRSTSTAT_LOCKUP_Msk /*!< Сброс по состоянию LockUp ядра */

#define IS_RCU_RST_STATUS(VALUE) (((VALUE) == RCU_RstStatus_POR) || \
                                  ((VALUE) == RCU_RstStatus_WDT) || \
                                  ((VALUE) == RCU_RstStatus_Sys) || \
                                  ((VALUE) == RCU_RstStatus_LockUp))
/**
  * @}
  */

/** @defgroup RCU_ITSource_Define Источники прерываний
  * @{
  */

#define RCU_ITSource_OSEClkFail RCU_INTEN_OSECLKERR_Msk       /*!< Произошла ошибка сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkFail RCU_INTEN_PLLCLKERR_Msk       /*!< Произошла ошибка сигнала с PLL */
#define RCU_ITSource_PLLDivClkFail RCU_INTEN_PLLDIVCLKERR_Msk /*!< Произошла ошибка сигнала с деленного выхода PLL */
#define RCU_ITSource_OSEClkGood RCU_INTEN_OSECLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkGood RCU_INTEN_PLLCLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала с PLL */
#define RCU_ITSource_PLLDivClkGood RCU_INTEN_PLLDIVCLKOK_Msk  /*!< Произошел переход к нормальной работе сигнала с деленного выхода PLL */
#define RCU_ITSource_PLLLock RCU_INTEN_PLLLOCK_Msk            /*!< Произошел захват частоты PLL */

#define IS_RCU_IT_SOURCE(VALUE) (((VALUE) == RCU_ITSource_OSEClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkFail) || \
                                 ((VALUE) == RCU_ITSource_OSEClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkGood) || \
                                 ((VALUE) == RCU_ITSource_PLLLock))

/**
  * @}
  */

/** @defgroup RCU_ITStatus_Define Статусы прерываний
  * @{
  */

#define RCU_ITStatus_OSEClkFail RCU_INTSTAT_OSECLKERR_Msk       /*!< Флаг ошибки сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkFail RCU_INTSTAT_PLLCLKERR_Msk       /*!< Флаг ошибки сигнала с PLL */
#define RCU_ITStatus_PLLDivClkFail RCU_INTSTAT_PLLDIVCLKERR_Msk /*!< Флаг ошибки сигнала с деленного выхода PLL */
#define RCU_ITStatus_OSEClkGood RCU_INTSTAT_OSECLKOK_Msk       /*!< Флаг перехода к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkGood RCU_INTSTAT_PLLCLKOK_Msk       /*!< Флаг перехода к нормальной работе сигнала с PLL */
#define RCU_ITStatus_PLLDivClkGood RCU_INTSTAT_PLLDIVCLKOK_Msk /*!< Флаг перехода к нормальной работе сигнала с деленного выхода PLL */
#define RCU_ITStatus_PLLLock RCU_INTSTAT_PLLLOCK_Msk             /*!< Флаг захвата частоты PLL */
#define RCU_ITStatus_SysFail RCU_INTSTAT_SYSFAIL_Msk             /*!< Флаг сбоя системной частоты */

#define IS_RCU_IT_STATUS(VALUE) (((VALUE) == RCU_ITStatus_OSEClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLDivClkFail) || \
                                 ((VALUE) == RCU_ITStatus_OSEClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLDivClkGood) || \
                                 ((VALUE) == RCU_ITStatus_PLLLock) ||       \
                                 ((VALUE) == RCU_ITStatus_SysFail))

/**
  * @}
  */

/** @defgroup RCU_APBClk_Define Управление тактированием периферийных блоков APB
  * @{
  */

#define RCU_APBClk_TMR0 RCU_PCLKCFG_TMR0EN_Msk   /*!< Управление тактированием блока TMR 0 */
#define RCU_APBClk_TMR1 RCU_PCLKCFG_TMR1EN_Msk   /*!< Управление тактированием блока TMR 1 */
#define RCU_APBClk_TMR2 RCU_PCLKCFG_TMR2EN_Msk   /*!< Управление тактированием блока TMR 2 */
#define RCU_APBClk_TMR3 RCU_PCLKCFG_TMR3EN_Msk   /*!< Управление тактированием блока TMR 3 */
#define RCU_APBClk_PWM0 RCU_PCLKCFG_PWM0EN_Msk   /*!< Управление тактированием блока PWM 0 */
#define RCU_APBClk_PWM1 RCU_PCLKCFG_PWM1EN_Msk   /*!< Управление тактированием блока PWM 1 */
#define RCU_APBClk_PWM2 RCU_PCLKCFG_PWM2EN_Msk   /*!< Управление тактированием блока PWM 2 */
#define RCU_APBClk_I2C RCU_PCLKCFG_I2CEN_Msk     /*!< Управление тактированием блока I2C */
#define RCU_APBClk_QEP RCU_PCLKCFG_QEPEN_Msk     /*!< Управление тактированием блока QEP */
#define RCU_APBClk_ECAP0 RCU_PCLKCFG_ECAP0EN_Msk /*!< Управление тактированием блока ECAP 0 */
#define RCU_APBClk_ECAP1 RCU_PCLKCFG_ECAP1EN_Msk /*!< Управление тактированием блока ECAP 1 */
#define RCU_APBClk_ECAP2 RCU_PCLKCFG_ECAP2EN_Msk /*!< Управление тактированием блока ECAP 2 */

#define IS_RCU_APB_CLK(VALUE) (((VALUE) == RCU_APBClk_TMR0) ||  \
                               ((VALUE) == RCU_APBClk_TMR1) ||  \
                               ((VALUE) == RCU_APBClk_TMR2) ||  \
                               ((VALUE) == RCU_APBClk_TMR3) ||  \
                               ((VALUE) == RCU_APBClk_PWM0) ||  \
                               ((VALUE) == RCU_APBClk_PWM1) ||  \
                               ((VALUE) == RCU_APBClk_PWM2) ||  \
                               ((VALUE) == RCU_APBClk_I2C) ||   \
                               ((VALUE) == RCU_APBClk_QEP) ||   \
                               ((VALUE) == RCU_APBClk_ECAP0) || \
                               ((VALUE) == RCU_APBClk_ECAP1) || \
                               ((VALUE) == RCU_APBClk_ECAP2))

/**
  * @}
  */

/** @defgroup RCU_AHBClk_Define Управление тактированием периферийных блоков AHB
  * @{
  */

#define RCU_AHBClk_GPIOA RCU_HCLKCFG_GPIOAEN_Msk /*!< Управление тактированием блока GPIOA */
#define RCU_AHBClk_GPIOB RCU_HCLKCFG_GPIOBEN_Msk /*!< Управление тактированием блока GPIOB */
#define RCU_AHBClk_CAN RCU_HCLKCFG_CANEN_Msk     /*!< Управление тактированием блока CAN */
#define IS_RCU_AHB_CLK(VALUE) (((VALUE) == RCU_AHBClk_GPIOA) || \
                               ((VALUE) == RCU_AHBClk_GPIOB) || \
                               ((VALUE) == RCU_AHBClk_CAN))

/**
  * @}
  */

/** @defgroup RCU_APBRst_Define Управление сбросом периферийных блоков APB
  * @{
  */

#define RCU_APBRst_TMR0 RCU_PRSTCFG_TMR0EN_Msk   /*!< Управление сбросом блока TMR 0 */
#define RCU_APBRst_TMR1 RCU_PRSTCFG_TMR1EN_Msk   /*!< Управление сбросом блока TMR 1 */
#define RCU_APBRst_TMR2 RCU_PRSTCFG_TMR2EN_Msk   /*!< Управление сбросом блока TMR 2 */
#define RCU_APBRst_TMR3 RCU_PRSTCFG_TMR3EN_Msk   /*!< Управление сбросом блока TMR 3 */
#define RCU_APBRst_PWM0 RCU_PRSTCFG_PWM0EN_Msk   /*!< Управление сбросом блока PWM 0 */
#define RCU_APBRst_PWM1 RCU_PRSTCFG_PWM1EN_Msk   /*!< Управление сбросом блока PWM 1 */
#define RCU_APBRst_PWM2 RCU_PRSTCFG_PWM2EN_Msk   /*!< Управление сбросом блока PWM 2 */
#define RCU_APBRst_I2C RCU_PRSTCFG_I2CEN_Msk     /*!< Управление сбросом блока I2C */
#define RCU_APBRst_QEP RCU_PRSTCFG_QEPEN_Msk     /*!< Управление сбросом блока QEP */
#define RCU_APBRst_ECAP0 RCU_PRSTCFG_ECAP0EN_Msk /*!< Управление сбросом блока ECAP 0 */
#define RCU_APBRst_ECAP1 RCU_PRSTCFG_ECAP1EN_Msk /*!< Управление сбросом блока ECAP 1 */
#define RCU_APBRst_ECAP2 RCU_PRSTCFG_ECAP2EN_Msk /*!< Управление сбросом блока ECAP 2 */

#define IS_RCU_APB_RST(VALUE) (((VALUE) == RCU_APBRst_TMR0) ||  \
                               ((VALUE) == RCU_APBRst_TMR1) ||  \
                               ((VALUE) == RCU_APBRst_TMR2) ||  \
                               ((VALUE) == RCU_APBRst_TMR3) ||  \
                               ((VALUE) == RCU_APBRst_PWM0) ||  \
                               ((VALUE) == RCU_APBRst_PWM1) ||  \
                               ((VALUE) == RCU_APBRst_PWM2) ||  \
                               ((VALUE) == RCU_APBRst_I2C) ||   \
                               ((VALUE) == RCU_APBRst_QEP) ||   \
                               ((VALUE) == RCU_APBRst_ECAP0) || \
                               ((VALUE) == RCU_APBRst_ECAP1) || \
                               ((VALUE) == RCU_APBRst_ECAP2))

/**
  * @}
  */

/** @defgroup RCU_AHBRst_Define Управление сбросом периферийных блоков AHB
  * @{
  */

#define RCU_AHBRst_GPIOA RCU_HRSTCFG_GPIOAEN_Msk /*!< Управление сбросом блока GPIOA */
#define RCU_AHBRst_GPIOB RCU_HRSTCFG_GPIOBEN_Msk /*!< Управление сбросом блока GPIOB */
#define RCU_AHBRst_CAN RCU_HRSTCFG_CANEN_Msk     /*!< Управление сбросом блока CAN */

#define IS_RCU_AHB_RST(VALUE) (((VALUE) == RCU_AHBRst_GPIOA) || \
                               ((VALUE) == RCU_AHBRst_GPIOB) || \
                               ((VALUE) == RCU_AHBRst_CAN))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCU_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор источника опорного сигнала PLL.
  */
typedef enum {
    RCU_PLL_Ref_OSEClk = RCU_PLLCFG_REFSRC_OSECLK, /*!< Сигнал внешнего осциллятора */
    RCU_PLL_Ref_OSIClk = RCU_PLLCFG_REFSRC_OSICLK  /*!< Сигнал внтуреннего осциллятора */
} RCU_PLL_Ref_TypeDef;
#define IS_RCU_PLL_REF(VALUE) (((VALUE) == RCU_PLL_Ref_OSEClk) || \
                               ((VALUE) == RCU_PLL_Ref_OSIClk))

/**
  * @brief  Выходной делитель OD
  */
typedef enum {
    RCU_PLL_OD_Disable = RCU_PLLCFG_OD_Disable, /*!< Делитель OD выключен */
    RCU_PLL_OD_Div2 = RCU_PLLCFG_OD_Div2,       /*!< Коэффициент деления OD равен 2 */
    RCU_PLL_OD_Div4 = RCU_PLLCFG_OD_Div4,       /*!< Коэффициент деления OD равен 4 */
    RCU_PLL_OD_Div8 = RCU_PLLCFG_OD_Div8        /*!< Коэффициент деления OD равен 8 */
} RCU_PLL_OD_TypeDef;
#define IS_RCU_PLL_OD(VALUE) (((VALUE) == RCU_PLL_OD_Disable) || \
                              ((VALUE) == RCU_PLL_OD_Div2) ||    \
                              ((VALUE) == RCU_PLL_OD_Div4) ||    \
                              ((VALUE) == RCU_PLL_OD_Div8))

/**
  * @brief  Выбор источника тактирования для периферийного блока c несколькими тактовыми доменами - ADC, UART, SPI
  */
typedef enum {
    RCU_PeriphClk_OSEClk = RCU_SPICFG_CLKSEL_OSECLK,       /*!< Сигнал внешнего осциллятора */
    RCU_PeriphClk_PLLClk = RCU_SPICFG_CLKSEL_PLLCLK,       /*!< Сигнал с PLL */
    RCU_PeriphClk_PLLDivClk = RCU_SPICFG_CLKSEL_PLLDIVCLK, /*!< Сигнал с деленного выхода PLL */
    RCU_PeriphClk_OSIClk = RCU_SPICFG_CLKSEL_OSICLK        /*!< Сигнал внтуреннего осциллятора */
} RCU_PeriphClk_TypeDef;
#define IS_RCU_PERIPH_CLK(VALUE) (((VALUE) == RCU_PeriphClk_OSEClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_PLLClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_PLLDivClk) || \
                                  ((VALUE) == RCU_PeriphClk_OSIClk))

/**
  * @brief  Выбор источника тактирования для CLKOUT, TRACE, WDT.
  */
typedef enum {
    RCU_SysPeriphClk_OSEClk = RCU_CLKOUTCFG_CLKSEL_OSECLK,       /*!< Сигнал внешнего осциллятора */
    RCU_SysPeriphClk_PLLClk = RCU_CLKOUTCFG_CLKSEL_PLLCLK,       /*!< Сигнал с PLL */
    RCU_SysPeriphClk_PLLDivClk = RCU_CLKOUTCFG_CLKSEL_PLLDIVCLK, /*!< Сигнал с деленного выхода PLL */
    RCU_SysPeriphClk_OSIClk = RCU_CLKOUTCFG_CLKSEL_OSICLK        /*!< Сигнал внтуреннего осциллятора */
} RCU_SysPeriphClk_TypeDef;
#define IS_RCU_SYS_PERIPH_CLK(VALUE) (((VALUE) == RCU_SysPeriphClk_OSEClk) ||    \
                                      ((VALUE) == RCU_SysPeriphClk_PLLClk) ||    \
                                      ((VALUE) == RCU_SysPeriphClk_PLLDivClk) || \
                                      ((VALUE) == RCU_SysPeriphClk_OSIClk))

/**
  * @brief  Выбор источника системной частоты.
  */
typedef enum {
    RCU_SysClk_OSIClk = RCU_SYSCLKCFG_SYSSEL_OSICLK,      /*!< Сигнал внтуреннего осциллятора */
    RCU_SysClk_OSEClk = RCU_SYSCLKCFG_SYSSEL_OSECLK,      /*!< Сигнал внешнего осциллятора */
    RCU_SysClk_PLLClk = RCU_SYSCLKCFG_SYSSEL_PLLCLK,      /*!< Сигнал с PLL */
    RCU_SysClk_PLLDivClk = RCU_SYSCLKCFG_SYSSEL_PLLDIVCLK /*!< Сигнал с деленного выхода PLL */
} RCU_SysClk_TypeDef;
#define IS_RCU_SYS_CLK(VALUE) (((VALUE) == RCU_SysClk_OSIClk) || \
                               ((VALUE) == RCU_SysClk_OSEClk) || \
                               ((VALUE) == RCU_SysClk_PLLClk) || \
                               ((VALUE) == RCU_SysClk_PLLDivClk))

/**
  * @brief  Структура инициализации PLL
  *
  */
typedef struct
{
    uint32_t DivVal;         /*!< Значение делителя сигнала на выходе блока PLL (итоговое значение 2*(Div+1)).
                                   Параметр может принимать любое значение из диапазона 0-63. */
    FunctionalState DivEn;   /*!< Активация делителя PLL*/
    RCU_PLL_Ref_TypeDef Ref; /*!< Источник опорного сигнала PLL */
    RCU_PLL_OD_TypeDef OD;   /*!< Выходной делитель OD */
    uint32_t M;              /*!< Множитель M.
                                   Параметр может принимать любое значение из диапазона 2-63. */
    uint32_t N;              /*!< Делитель N.
                                   Параметр может принимать любое значение из диапазона 1-63. */
} RCU_PLL_Init_TypeDef;
#define IS_RCU_PLL_DIV(VALUE) (((VALUE)&0xFFFFFFC0) == 0)
#define IS_RCU_PLL_M(VALUE) (((VALUE) <= 63) && ((VALUE) >= 2))
#define IS_RCU_PLL_N(VALUE) (((VALUE) <= 63) && ((VALUE) >= 1))
#define IS_RCU_PLL_REF_FREQ(VALUE) (((VALUE) <= 64000000) && ((VALUE) >= 4000000))
#define IS_RCU_PLL_CMP_FREQ(VALUE) (((VALUE) <= 20000000) && ((VALUE) >= 4000000))
#define IS_RCU_PLL_VCO_FREQ(VALUE) (((VALUE) <= 200000000) && ((VALUE) >= 120000000))

#define IS_RCU_SYSCLK_FREQ(VALUE) (((VALUE) <= 100000000) && ((VALUE) >= 1000000))
#define IS_RCU_SECPRD(VALUE) (((VALUE)&0xFFFFFF00) == 0)
#define IS_RCU_OSI_CALIB(VALUE) (((VALUE)&0xFFFFFC00) == 0)
#define IS_RCU_PERIPH_DIV(VALUE) (((VALUE)&0xFFFFFFC0) == 0)

/**
  * @}
  */

/** @defgroup RCU_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Включение тактирования выбранного APB блока периферии
  * @param   APBClk  Выбор периферии. Любая совокупность значений значений RCU_APBClk_x (@ref RCU_APBClk_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBClkCmd(uint32_t APBClk, FunctionalState State)
{
    assert_param(IS_RCU_APB_CLK(APBClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PCLKCFG, APBClk, State ? APBClk : 0);
}

/**
  * @brief   Включение тактирования выбранного AHB блока периферии
  * @param   AHBClk  Выбор периферии. Любая совокупность значений значений RCU_AHBClk_x (@ref RCU_AHBClk_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_AHBClkCmd(uint32_t AHBClk, FunctionalState State)
{
    assert_param(IS_RCU_AHB_CLK(AHBClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->HCLKCFG, AHBClk, State ? AHBClk : 0);
}

/**
  * @brief   Вывод из состояния сброса периферийных блоков APB
  * @param   APBRst  Выбор периферийного модуля. Любая совокупность значений значений RCU_APBRst_x (@ref RCU_APBRst_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBRstCmd(uint32_t APBRst, FunctionalState State)
{
    assert_param(IS_RCU_APB_RST(APBRst));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PRSTCFG, APBRst, State ? APBRst : 0);
}

/**
  * @brief   Вывод из состояния сброса периферийных блоков APB
  * @param   AHBRst  Выбор периферийного модуля. Любая совокупность значений значений RCU_AHBRst_x (@ref RCU_AHBRst_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_AHBRstCmd(uint32_t AHBRst, FunctionalState State)
{
    assert_param(IS_RCU_AHB_RST(AHBRst));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->HRSTCFG, AHBRst, State ? AHBRst : 0);
}

/**
  * @brief   Установка опорного тактового сигнала для системной частоты
  * @param   SysClk  Выбор тактового сигнала
  * @retval  void
  */
__STATIC_INLINE void RCU_SysClkConfig(RCU_SysClk_TypeDef SysClk)
{
    assert_param(IS_RCU_SYS_CLK(SysClk));

    WRITE_REG(RCU->SYSCLKCFG_bit.SYSSEL, SysClk);
}

/**
  * @brief   Получение текущего опорного тактового сигнала для системной частоты
  * @retval  Val  Выбранный сигнал
  */
__STATIC_INLINE RCU_SysClk_TypeDef RCU_SysClkStatus(void)
{
    return (RCU_SysClk_TypeDef)READ_REG(RCU->SYSCLKSTAT_bit.SYSSTAT);
}

/**
  * @brief   Получение статуса занятости менеджера тактовых сигналов
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus RCU_BusyStatus(void)
{
    return (FlagStatus)READ_BIT(RCU->SYSCLKSTAT, RCU_SYSCLKSTAT_BUSY_Msk);
}

/**
  * @brief   Получение статуса выбранного тактового сигнала
  * @param   ClkStatus  Выбор тактового сигнала. Любая совокупность значений значений RCU_ClkStatus_x (@ref RCU_ClkStatus_Define).
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus RCU_ClkStatus(uint32_t ClkStatus)
{
    return (FlagStatus)READ_BIT(RCU->SYSCLKSTAT, ClkStatus);
}

uint32_t RCU_GetOSIClkFreq();
uint32_t RCU_GetOSEClkFreq();
uint32_t RCU_GetPLLClkFreq();
uint32_t RCU_GetPLLDivClkFreq();
uint32_t RCU_GetSysClkFreq();

/**
  * @brief   Включение системы слежения за системным тактовым сигналом
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SecurityCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SYSCLKCFG_bit.SECEN, State);
}

/**
  * @brief   Настройка периода срабатывания системы слежения
  * @param   OSEPrd  Максимальное значение счетчика слежения за сигналом OSECLK
  * @param   PLLPrd  Максимальное значение счетчика слежения за сигналом PLLCLK
  * @param   PLLDivPrd  Максимальное значение счетчика слежения за сигналом PLLDIVCLK
  * @retval  void
  */
__STATIC_INLINE void RCU_SecurityConfig(uint32_t OSEPrd, uint32_t PLLPrd, uint32_t PLLDivPrd)
{
    assert_param(IS_RCU_SECPRD(OSEPrd));
    assert_param(IS_RCU_SECPRD(PLLPrd));
    assert_param(IS_RCU_SECPRD(PLLDivPrd));

    MODIFY_REG(RCU->SECPRD, (RCU_SECPRD_OSECLK_Msk | RCU_SECPRD_PLLCLK_Msk | RCU_SECPRD_PLLDIVCLK_Msk),
               ((OSEPrd << RCU_SECPRD_OSECLK_Pos) | (PLLPrd << RCU_SECPRD_PLLCLK_Pos) | (PLLDivPrd << RCU_SECPRD_PLLDIVCLK_Pos)));
}

/**
  * @brief   Получение статуса выбранного типа сброса
  * @param   RstStatus  Выбранный тип сброса. Любая совокупность значений значений RCU_RstStatus_x (@ref RCU_RstStatus_Define).
  * @retval  Status  Статус активности
  */
__STATIC_INLINE FlagStatus RCU_RstStatus(uint32_t RstStatus)
{
    return (FlagStatus)READ_BIT(RCU->SYSRSTSTAT, RstStatus);
}

/**
  * @brief   Очистка статуса выбранного типа сброса
  * @param   RstStatus  Выбранный тип сброса. Любая совокупность значений значений RCU_RstStatus_x (@ref RCU_RstStatus_Define).
  * @retval  void
  */
__STATIC_INLINE void RCU_RstStatusClear(uint32_t RstStatus)
{
    assert_param(IS_RCU_RST_STATUS(RstStatus));

    WRITE_REG(RCU->SYSRSTSTAT, RstStatus);
}

/**
  * @brief   Включение сброса ядра по переходу в состояние LockUp
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_LockUpRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SYSRSTCFG_bit.LOCKUPEN, State);
}

/**
  * @brief   Установка калибровочного значения для внутреннего осциллятора
  * @param   CalibVal  Значение калибровки
  * @retval  void
  */
__STATIC_INLINE void RCU_OSIConfig(uint32_t CalibVal)
{
    assert_param(IS_RCU_OSI_CALIB(CalibVal));

    WRITE_REG(RCU->OSICFG_bit.CAL, CalibVal);
}

/**
  * @brief   Разрешение работы внешнего осциллятора
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_OSECmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->OSECFG, (RCU_OSECFG_EN_Msk | RCU_OSECFG_XOEN_Msk),
               ((State << RCU_OSECFG_EN_Pos) | (State << RCU_OSECFG_XOEN_Pos)));
}

OperationStatus RCU_SysClkChangeCmd(RCU_SysClk_TypeDef SysClk);

/** @defgroup RCU_Init_Deinit Конфигурация PLL
  * @{
  */

OperationStatus RCU_PLL_AutoConfig(uint32_t SysClkFreq, RCU_PLL_Ref_TypeDef Ref);
OperationStatus RCU_PLL_Init(RCU_PLL_Init_TypeDef* InitStruct);
void RCU_PLL_DeInit(void);
void RCU_PLL_StructInit(RCU_PLL_Init_TypeDef* InitStruct);

/**
  * @brief   Разрешение работы выхода PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_OutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.OUTEN, State);
}

/**
  * @brief   Включение режима bypass PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_BypassCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.BYPASS, State);
}

/**
  * @brief   Настройка внешнего делителя PLL
  * @param   Val  Выбор значения делителя. Тактовый сигнал делится на Val+1.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_DivConfig(uint32_t Val, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));
    assert_param(IS_RCU_PLL_DIV(Val));

    MODIFY_REG(RCU->PLLDIV, RCU_PLLDIV_DIV_Msk | RCU_PLLDIV_DIVEN_Msk,
               (Val << RCU_PLLDIV_DIV_Pos |
                State << RCU_PLLDIV_DIVEN_Pos));
}

/**
  * @brief   Получение статуса захвата частоты PLL
  * @retval  Status  Статус захвата
  */
__STATIC_INLINE FlagStatus RCU_PLL_LockStatus(void)
{
    return (FlagStatus)READ_BIT(RCU->PLLCFG, RCU_PLLCFG_LOCK_Msk);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_Config_ClkOut Настройка выдачи тактового сигнала CLKOUT
  * @{
  */

uint32_t RCU_GetClkOutFreq(void);

/**
  * @brief   Настройка тактирования ClkOut
  * @param   ClkOut  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_ClkOutConfig(RCU_SysPeriphClk_TypeDef ClkOut, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_SYS_PERIPH_CLK(ClkOut));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->CLKOUTCFG, (RCU_CLKOUTCFG_CLKSEL_Msk | RCU_CLKOUTCFG_DIVN_Msk | RCU_CLKOUTCFG_DIVEN_Msk),
               ((ClkOut << RCU_CLKOUTCFG_CLKSEL_Pos) | (DivVal << RCU_CLKOUTCFG_DIVN_Pos) | (DivState << RCU_CLKOUTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования ClkOut
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ClkOutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->CLKOUTCFG_bit.CLKEN, State);
    WRITE_REG(SIU->CLKOUTCTL_bit.CLKOUTEN, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_Config_Trace Тактирование модуля трассировки
  * @{
  */

uint32_t RCU_GetTraceClkFreq(void);

/**
  * @brief   Настройка тактирования блока трассировки
  * @param   TraceClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_TraceClkConfig(RCU_SysPeriphClk_TypeDef TraceClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_SYS_PERIPH_CLK(TraceClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->TRACECFG, (RCU_TRACECFG_CLKSEL_Msk | RCU_TRACECFG_DIVN_Msk | RCU_TRACECFG_DIVEN_Msk),
               ((TraceClk << RCU_TRACECFG_CLKSEL_Pos) | (DivVal << RCU_TRACECFG_DIVN_Pos) | (DivState << RCU_TRACECFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования трассировки
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_TraceClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->TRACECFG_bit.CLKEN, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_UART Тактирование и сброс UART
  * @{
  */

uint32_t RCU_GetUARTClkFreq(UART_Num_TypeDef UARTx_Num);

/**
  * @brief   Настройка тактирования UART
  * @param   UARTx_Num  Порядковый номер блока UART
  * @param   UARTClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTClkConfig(UART_Num_TypeDef UARTx_Num, RCU_PeriphClk_TypeDef UARTClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(UARTClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->UARTCFG[UARTx_Num].UARTCFG, (RCU_UARTCFG_UARTCFG_CLKSEL_Msk | RCU_UARTCFG_UARTCFG_DIVN_Msk | RCU_UARTCFG_UARTCFG_DIVEN_Msk),
               ((UARTClk << RCU_UARTCFG_UARTCFG_CLKSEL_Pos) | (DivVal << RCU_UARTCFG_UARTCFG_DIVN_Pos) | (DivState << RCU_UARTCFG_UARTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования UART
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTClkCmd(UART_Num_TypeDef UARTx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса UART
  * @param   UARTx_Num  Порядковый номер блока UART
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTRstCmd(UART_Num_TypeDef UARTx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_SPI Тактирование и сброс SPI
  * @{
  */

uint32_t RCU_GetSPIClkFreq(void);

/**
  * @brief   Настройка тактирования SPI
  * @param   SPIClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkConfig(RCU_PeriphClk_TypeDef SPIClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(SPIClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->SPICFG, (RCU_SPICFG_CLKSEL_Msk | RCU_SPICFG_DIVN_Msk | RCU_SPICFG_DIVEN_Msk),
               ((SPIClk << RCU_SPICFG_CLKSEL_Pos) | (DivVal << RCU_SPICFG_DIVN_Pos) | (DivState << RCU_SPICFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_WDT Тактирование и сброс WDT
  * @{
  */

uint32_t RCU_GetWDTClkFreq(void);

/**
  * @brief   Настройка тактирования сторожевого таймера
  * @param   WDTClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTClkConfig(RCU_SysPeriphClk_TypeDef WDTClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_SYS_PERIPH_CLK(WDTClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->WDTCFG, (RCU_WDTCFG_CLKSEL_Msk | RCU_WDTCFG_DIVN_Msk | RCU_WDTCFG_DIVEN_Msk),
               ((WDTClk << RCU_WDTCFG_CLKSEL_Pos) | (DivVal << RCU_WDTCFG_DIVN_Pos) | (DivState << RCU_WDTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования сторожевого таймера
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->WDTCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса сторожевого таймера
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->WDTCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_ADC Тактирование и сброс ADC
  * @{
  */

uint32_t RCU_GetADCClkFreq(void);

/**
  * @brief   Настройка тактирования АЦП
  * @param   ADCClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCClkConfig(RCU_PeriphClk_TypeDef ADCClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(ADCClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->ADCCFG, (RCU_ADCCFG_CLKSEL_Msk | RCU_ADCCFG_DIVN_Msk | RCU_ADCCFG_DIVEN_Msk),
               ((ADCClk << RCU_ADCCFG_CLKSEL_Pos) | (DivVal << RCU_ADCCFG_DIVN_Pos) | (DivState << RCU_ADCCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования АЦП
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->ADCCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса АЦП
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->ADCCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_IT Прерывания
  * @{
  */

/**
  * @brief   Разрешение работы прерывания RCU
  * @param   ITSource  Выбор источника прерывания. Любая совокупность значений значений RCU_ITSource_x (@ref RCU_ITSource_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ITCmd(uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_RCU_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->INTEN, ITSource, State ? (uint32_t)ITSource : 0);
}

/**
  * @brief   Получение статуса выбранного флага прерывания
  * @param   ITStatus  Выбранный флаг. Любая совокупность значений значений RCU_ITStatus_x (@ref RCU_ITStatus_Define).
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus RCU_ITStatus(uint32_t ITStatus)
{
    assert_param(IS_RCU_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(RCU->INTSTAT, ITStatus);
}

/**
  * @brief   Сброс статуса выбранного флага прерывания
  * @param   ITStatus  Выбранный флаг. Любая совокупность значений значений RCU_ITStatus_x (@ref RCU_ITStatus_Define).
  * @retval  void
  */
__STATIC_INLINE void RCU_ITStatusClear(uint32_t ITStatus)
{
    assert_param(IS_RCU_IT_STATUS(ITStatus));

    WRITE_REG(RCU->INTSTAT, ITStatus);
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

#endif /* __PLIB035_RCU_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
