/**
  ******************************************************************************
  * @file    plib028_rcu.h
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
  * <h2><center>&copy; 2019 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB028_RCU_H
#define __PLIB028_RCU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

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

#define RCU_ClkStatus_SysClkFail RCU_SYSCLKSTAT_SYSFAIL_Msk         /*!< Ошибка текущей системной частоты */
#define RCU_ClkStatus_SRCClkFail RCU_SYSCLKSTAT_SRCCLKERR_Msk       /*!< Ошибка сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkFail RCU_SYSCLKSTAT_PLLCLKERR_Msk       /*!< Ошибка сигнала с PLL */
#define RCU_ClkStatus_PLLDivClkFail RCU_SYSCLKSTAT_PLLDIVCLKERR_Msk /*!< Ошибка сигнала с деленного выхода PLL */
#define RCU_ClkStatus_SRCClkGood RCU_SYSCLKSTAT_SRCCLKOK_Msk        /*!< Нормальная работа сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkGood RCU_SYSCLKSTAT_PLLCLKOK_Msk        /*!< Нормальная работа сигнала с PLL */
#define RCU_ClkStatus_PLLDivClkGood RCU_SYSCLKSTAT_PLLDIVCLKOK_Msk  /*!< Нормальная работа сигнала с деленного выхода PLL */

#define IS_RCU_CLK_STATUS(VALUE) (((VALUE) == RCU_ClkStatus_SysClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_SRCClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLDivClkFail) || \
                                  ((VALUE) == RCU_ClkStatus_SRCClkGood) ||    \
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

#define RCU_ITSource_SRCClkFail RCU_INTEN_SRCCLKERR_Msk       /*!< Произошла ошибка сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkFail RCU_INTEN_PLLCLKERR_Msk       /*!< Произошла ошибка сигнала с PLL */
#define RCU_ITSource_PLLDivClkFail RCU_INTEN_PLLDIVCLKERR_Msk /*!< Произошла ошибка сигнала с деленного выхода PLL */
#define RCU_ITSource_SRCClkGood RCU_INTEN_SRCCLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkGood RCU_INTEN_PLLCLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала с PLL */
#define RCU_ITSource_PLLDivClkGood RCU_INTEN_PLLDIVCLKOK_Msk  /*!< Произошел переход к нормальной работе сигнала с деленного выхода PLL */
#define RCU_ITSource_PLLLock RCU_INTEN_PLLLOCK_Msk            /*!< Произошел захват частоты PLL */

#define IS_RCU_IT_SOURCE(VALUE) (((VALUE) == RCU_ITSource_SRCClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkFail) || \
                                 ((VALUE) == RCU_ITSource_SRCClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkGood) || \
                                 ((VALUE) == RCU_ITSource_PLLLock))

/**
  * @}
  */

/** @defgroup RCU_ITStatus_Define Статусы прерываний
  * @{
  */

#define RCU_ITStatus_SRCClkFail RCU_INTSTAT_SRCCLKERR_Msk       /*!< Флаг ошибки сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkFail RCU_INTSTAT_PLLCLKERR_Msk       /*!< Флаг ошибки сигнала с PLL */
#define RCU_ITStatus_PLLDivClkFail RCU_INTSTAT_PLLDIVCLKERR_Msk /*!< Флаг ошибки сигнала с деленного выхода PLL */
#define RCU_ITStatus_SRCClkGood RCU_INTSTAT_SRCCLKOK_Msk        /*!< Флаг перехода к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkGood RCU_INTSTAT_PLLCLKOK_Msk        /*!< Флаг перехода к нормальной работе сигнала с PLL */
#define RCU_ITStatus_PLLDivClkGood RCU_INTSTAT_PLLDIVCLKOK_Msk  /*!< Флаг перехода к нормальной работе сигнала с деленного выхода PLL */
#define RCU_ITStatus_PLLLock RCU_INTSTAT_PLLLOCK_Msk            /*!< Флаг захвата частоты PLL */
#define RCU_ITStatus_SysFail RCU_INTSTAT_SYSFAIL_Msk            /*!< Флаг сбоя системной частоты */

#define IS_RCU_IT_STATUS(VALUE) (((VALUE) == RCU_ITStatus_SRCClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLDivClkFail) || \
                                 ((VALUE) == RCU_ITStatus_SRCClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLDivClkGood) || \
                                 ((VALUE) == RCU_ITStatus_PLLLock) ||       \
                                 ((VALUE) == RCU_ITStatus_SysFail))

/**
  * @}
  */

/** @defgroup RCU_APBClk0_Define Управление тактированием периферийных блоков APB группа 0
  * @{
  */

#define RCU_APBClk0_TUART0 RCU_PCLKCFG0_TUART0EN_Msk /*!< Управление тактированием блока TUART 0 */
#define RCU_APBClk0_TUART1 RCU_PCLKCFG0_TUART1EN_Msk /*!< Управление тактированием блока TUART 1 */
#define RCU_APBClk0_I2C0 RCU_PCLKCFG0_I2C0EN_Msk     /*!< Управление тактированием блока I2C 0 */
#define RCU_APBClk0_I2C1 RCU_PCLKCFG0_I2C1EN_Msk     /*!< Управление тактированием блока I2C 1 */
#define RCU_APBClk0_TMR0 RCU_PCLKCFG0_TMR0EN_Msk     /*!< Управление тактированием блока TMR 0 */
#define RCU_APBClk0_TMR1 RCU_PCLKCFG0_TMR1EN_Msk     /*!< Управление тактированием блока TMR 1 */
#define RCU_APBClk0_TMR2 RCU_PCLKCFG0_TMR2EN_Msk     /*!< Управление тактированием блока TMR 2 */
#define RCU_APBClk0_TMR3 RCU_PCLKCFG0_TMR3EN_Msk     /*!< Управление тактированием блока TMR 3 */
#define RCU_APBClk0_ETMR0 RCU_PCLKCFG0_ETMR0EN_Msk   /*!< Управление тактированием блока ETMR 0 */
#define RCU_APBClk0_ETMR1 RCU_PCLKCFG0_ETMR1EN_Msk   /*!< Управление тактированием блока ETMR 1 */
#define RCU_APBClk0_ETMR2 RCU_PCLKCFG0_ETMR2EN_Msk   /*!< Управление тактированием блока ETMR 2 */
#define RCU_APBClk0_ETMR3 RCU_PCLKCFG0_ETMR3EN_Msk   /*!< Управление тактированием блока ETMR 3 */
#define RCU_APBClk0_RTC RCU_PCLKCFG0_RTCEN_Msk       /*!< Управление тактированием блока RTC */
#define RCU_APBClk0_ECAP0 RCU_PCLKCFG0_ECAP0EN_Msk   /*!< Управление тактированием блока ECAP 0 */
#define RCU_APBClk0_ECAP1 RCU_PCLKCFG0_ECAP1EN_Msk   /*!< Управление тактированием блока ECAP 1 */
#define RCU_APBClk0_ECAP2 RCU_PCLKCFG0_ECAP2EN_Msk   /*!< Управление тактированием блока ECAP 2 */
#define RCU_APBClk0_ECAP3 RCU_PCLKCFG0_ECAP3EN_Msk   /*!< Управление тактированием блока ECAP 3 */
#define RCU_APBClk0_ECAP4 RCU_PCLKCFG0_ECAP4EN_Msk   /*!< Управление тактированием блока ECAP 4 */
#define RCU_APBClk0_ECAP5 RCU_PCLKCFG0_ECAP5EN_Msk   /*!< Управление тактированием блока ECAP 5 */

#define IS_RCU_APB_CLK_0(VALUE) (((VALUE) == RCU_APBClk0_TUART0) || \
                                 ((VALUE) == RCU_APBClk0_TUART1) || \
                                 ((VALUE) == RCU_APBClk0_I2C0) ||   \
                                 ((VALUE) == RCU_APBClk0_I2C1) ||   \
                                 ((VALUE) == RCU_APBClk0_TMR0) ||   \
                                 ((VALUE) == RCU_APBClk0_TMR1) ||   \
                                 ((VALUE) == RCU_APBClk0_TMR2) ||   \
                                 ((VALUE) == RCU_APBClk0_TMR3) ||   \
                                 ((VALUE) == RCU_APBClk0_ETMR0) ||  \
                                 ((VALUE) == RCU_APBClk0_ETMR1) ||  \
                                 ((VALUE) == RCU_APBClk0_ETMR2) ||  \
                                 ((VALUE) == RCU_APBClk0_ETMR3) ||  \
                                 ((VALUE) == RCU_APBClk0_RTC) ||    \
                                 ((VALUE) == RCU_APBClk0_ECAP0) ||  \
                                 ((VALUE) == RCU_APBClk0_ECAP1) ||  \
                                 ((VALUE) == RCU_APBClk0_ECAP2) ||  \
                                 ((VALUE) == RCU_APBClk0_ECAP3) ||  \
                                 ((VALUE) == RCU_APBClk0_ECAP4) ||  \
                                 ((VALUE) == RCU_APBClk0_ECAP5))

/**
  * @}
  */

/** @defgroup RCU_APBClk1_Define Управление тактированием периферийных блоков APB группа 1
  * @{
  */

#define RCU_APBClk1_PWM0 RCU_PCLKCFG1_PWM0EN_Msk /*!< Управление тактированием блока PWM 0 */
#define RCU_APBClk1_PWM1 RCU_PCLKCFG1_PWM1EN_Msk /*!< Управление тактированием блока PWM 1 */
#define RCU_APBClk1_PWM2 RCU_PCLKCFG1_PWM2EN_Msk /*!< Управление тактированием блока PWM 2 */
#define RCU_APBClk1_PWM3 RCU_PCLKCFG1_PWM3EN_Msk /*!< Управление тактированием блока PWM 3 */
#define RCU_APBClk1_PWM4 RCU_PCLKCFG1_PWM4EN_Msk /*!< Управление тактированием блока PWM 4 */
#define RCU_APBClk1_PWM5 RCU_PCLKCFG1_PWM5EN_Msk /*!< Управление тактированием блока PWM 5 */
#define RCU_APBClk1_PWM6 RCU_PCLKCFG1_PWM6EN_Msk /*!< Управление тактированием блока PWM 6 */
#define RCU_APBClk1_PWM7 RCU_PCLKCFG1_PWM7EN_Msk /*!< Управление тактированием блока PWM 7 */
#define RCU_APBClk1_PWM8 RCU_PCLKCFG1_PWM8EN_Msk /*!< Управление тактированием блока PWM 8 */
#define RCU_APBClk1_PWM9 RCU_PCLKCFG1_PWM9EN_Msk /*!< Управление тактированием блока PWM 9 */
#define RCU_APBClk1_QEP0 RCU_PCLKCFG1_QEP0EN_Msk /*!< Управление тактированием блока QEP 0 */
#define RCU_APBClk1_QEP1 RCU_PCLKCFG1_QEP1EN_Msk /*!< Управление тактированием блока QEP 1 */
#define RCU_APBClk1_QEP2 RCU_PCLKCFG1_QEP2EN_Msk /*!< Управление тактированием блока QEP 2 */
#define RCU_APBClk1_QEP3 RCU_PCLKCFG1_QEP3EN_Msk /*!< Управление тактированием блока QEP 3 */
#define RCU_APBClk1_LAU RCU_PCLKCFG1_LAUEN_Msk   /*!< Управление тактированием блока LAU */
#define RCU_APBClk1_OWI0 RCU_PCLKCFG1_OWI0EN_Msk /*!< Управление тактированием блока OWI 0 */
#define RCU_APBClk1_OWI1 RCU_PCLKCFG1_OWI1EN_Msk /*!< Управление тактированием блока OWI 1 */

#define IS_RCU_APB_CLK_1(VALUE) (((VALUE) == RCU_APBClk1_PWM0) || \
                                 ((VALUE) == RCU_APBClk1_PWM1) || \
                                 ((VALUE) == RCU_APBClk1_PWM2) || \
                                 ((VALUE) == RCU_APBClk1_PWM3) || \
                                 ((VALUE) == RCU_APBClk1_PWM4) || \
                                 ((VALUE) == RCU_APBClk1_PWM5) || \
                                 ((VALUE) == RCU_APBClk1_PWM6) || \
                                 ((VALUE) == RCU_APBClk1_PWM7) || \
                                 ((VALUE) == RCU_APBClk1_PWM8) || \
                                 ((VALUE) == RCU_APBClk1_PWM9) || \
                                 ((VALUE) == RCU_APBClk1_QEP0) || \
                                 ((VALUE) == RCU_APBClk1_QEP1) || \
                                 ((VALUE) == RCU_APBClk1_QEP2) || \
                                 ((VALUE) == RCU_APBClk1_QEP3) || \
                                 ((VALUE) == RCU_APBClk1_LAU) ||  \
                                 ((VALUE) == RCU_APBClk1_OWI0) || \
                                 ((VALUE) == RCU_APBClk1_OWI1))

/**
  * @}
  */

/** @defgroup RCU_AHBClk_Define Управление тактированием периферийных блоков AHB
  * @{
  */

#define RCU_AHBClk_GPIOA RCU_HCLKCFG_GPIOAEN_Msk     /*!< Управление тактированием блока GPIOA */
#define RCU_AHBClk_GPIOB RCU_HCLKCFG_GPIOBEN_Msk     /*!< Управление тактированием блока GPIOB */
#define RCU_AHBClk_GPIOC RCU_HCLKCFG_GPIOCEN_Msk     /*!< Управление тактированием блока GPIOC */
#define RCU_AHBClk_GPIOD RCU_HCLKCFG_GPIODEN_Msk     /*!< Управление тактированием блока GPIOD */
#define RCU_AHBClk_GPIOE RCU_HCLKCFG_GPIOEEN_Msk     /*!< Управление тактированием блока GPIOE */
#define RCU_AHBClk_GPIOF RCU_HCLKCFG_GPIOFEN_Msk     /*!< Управление тактированием блока GPIOF */
#define RCU_AHBClk_GPIOG RCU_HCLKCFG_GPIOGEN_Msk     /*!< Управление тактированием блока GPIOG */
#define RCU_AHBClk_GPIOH RCU_HCLKCFG_GPIOHEN_Msk     /*!< Управление тактированием блока GPIOH */
#define RCU_AHBClk_GPIOJ RCU_HCLKCFG_GPIOJEN_Msk     /*!< Управление тактированием блока GPIOJ */
#define RCU_AHBClk_GPIOK RCU_HCLKCFG_GPIOKEN_Msk     /*!< Управление тактированием блока GPIOK */
#define RCU_AHBClk_GPIOL RCU_HCLKCFG_GPIOLEN_Msk     /*!< Управление тактированием блока GPIOL */
#define RCU_AHBClk_GPIOM RCU_HCLKCFG_GPIOMEN_Msk     /*!< Управление тактированием блока GPIOM */
#define RCU_AHBClk_CAN RCU_HCLKCFG_CANEN_Msk         /*!< Управление тактированием блока CAN */
#define RCU_AHBClk_MILSTD0 RCU_HCLKCFG_MILSTD0EN_Msk /*!< Управление тактированием блока MILSTD 0 */
#define RCU_AHBClk_MILSTD1 RCU_HCLKCFG_MILSTD1EN_Msk /*!< Управление тактированием блока MILSTD 1 */
#define RCU_AHBClk_SPWR0 RCU_HCLKCFG_SPWR0EN_Msk     /*!< Управление тактированием блока SPWR 0 */
#define RCU_AHBClk_SPWR1 RCU_HCLKCFG_SPWR1EN_Msk     /*!< Управление тактированием блока SPWR 1 */
#define RCU_AHBClk_EXTMEM RCU_HCLKCFG_EXTMEMEN_Msk   /*!< Управление тактированием блока EXTMEM */
#define RCU_AHBClk_SDFM RCU_HCLKCFG_SDFMEN_Msk       /*!< Управление тактированием блока SDFM */

#define IS_RCU_AHB_CLK(VALUE) (((VALUE) == RCU_AHBClk_GPIOA) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOB) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOC) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOD) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOE) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOF) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOG) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOH) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOJ) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOK) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOL) ||   \
                               ((VALUE) == RCU_AHBClk_GPIOM) ||   \
                               ((VALUE) == RCU_AHBClk_CAN) ||     \
                               ((VALUE) == RCU_AHBClk_MILSTD0) || \
                               ((VALUE) == RCU_AHBClk_MILSTD1) || \
                               ((VALUE) == RCU_AHBClk_SPWR0) ||   \
                               ((VALUE) == RCU_AHBClk_SPWR1) ||   \
                               ((VALUE) == RCU_AHBClk_EXTMEM) ||  \
                               ((VALUE) == RCU_AHBClk_GPIOM) ||   \
                               ((VALUE) == RCU_AHBClk_SDFM))

/**
  * @}
  */

/** @defgroup RCU_APBRst0_Define Управление сбросом периферийных блоков APB группа 0
  * @{
  */

#define RCU_APBRst0_TUART0 RCU_PRSTCFG0_TUART0EN_Msk /*!< Управление сбросом блока TUART 0 */
#define RCU_APBRst0_TUART1 RCU_PRSTCFG0_TUART1EN_Msk /*!< Управление сбросом блока TUART 1 */
#define RCU_APBRst0_I2C0 RCU_PRSTCFG0_I2C0EN_Msk     /*!< Управление сбросом блока I2C 0 */
#define RCU_APBRst0_I2C1 RCU_PRSTCFG0_I2C1EN_Msk     /*!< Управление сбросом блока I2C 1 */
#define RCU_APBRst0_TMR0 RCU_PRSTCFG0_TMR0EN_Msk     /*!< Управление сбросом блока TMR 0 */
#define RCU_APBRst0_TMR1 RCU_PRSTCFG0_TMR1EN_Msk     /*!< Управление сбросом блока TMR 1 */
#define RCU_APBRst0_TMR2 RCU_PRSTCFG0_TMR2EN_Msk     /*!< Управление сбросом блока TMR 2 */
#define RCU_APBRst0_TMR3 RCU_PRSTCFG0_TMR3EN_Msk     /*!< Управление сбросом блока TMR 3 */
#define RCU_APBRst0_ETMR0 RCU_PRSTCFG0_ETMR0EN_Msk   /*!< Управление сбросом блока ETMR 0 */
#define RCU_APBRst0_ETMR1 RCU_PRSTCFG0_ETMR1EN_Msk   /*!< Управление сбросом блока ETMR 1 */
#define RCU_APBRst0_ETMR2 RCU_PRSTCFG0_ETMR2EN_Msk   /*!< Управление сбросом блока ETMR 2 */
#define RCU_APBRst0_ETMR3 RCU_PRSTCFG0_ETMR3EN_Msk   /*!< Управление сбросом блока ETMR 3 */
#define RCU_APBRst0_RTC RCU_PRSTCFG0_RTCEN_Msk       /*!< Управление сбросом блока RTC */
#define RCU_APBRst0_ECAP0 RCU_PRSTCFG0_ECAP0EN_Msk   /*!< Управление сбросом блока ECAP 0 */
#define RCU_APBRst0_ECAP1 RCU_PRSTCFG0_ECAP1EN_Msk   /*!< Управление сбросом блока ECAP 1 */
#define RCU_APBRst0_ECAP2 RCU_PRSTCFG0_ECAP2EN_Msk   /*!< Управление сбросом блока ECAP 2 */
#define RCU_APBRst0_ECAP3 RCU_PRSTCFG0_ECAP3EN_Msk   /*!< Управление сбросом блока ECAP 3 */
#define RCU_APBRst0_ECAP4 RCU_PRSTCFG0_ECAP4EN_Msk   /*!< Управление сбросом блока ECAP 4 */
#define RCU_APBRst0_ECAP5 RCU_PRSTCFG0_ECAP5EN_Msk   /*!< Управление сбросом блока ECAP 5 */

#define IS_RCU_APB_RST_0(VALUE) (((VALUE) == RCU_APBRst0_TUART0) || \
                                 ((VALUE) == RCU_APBRst0_TUART1) || \
                                 ((VALUE) == RCU_APBRst0_I2C0) ||   \
                                 ((VALUE) == RCU_APBRst0_I2C1) ||   \
                                 ((VALUE) == RCU_APBRst0_TMR0) ||   \
                                 ((VALUE) == RCU_APBRst0_TMR1) ||   \
                                 ((VALUE) == RCU_APBRst0_TMR2) ||   \
                                 ((VALUE) == RCU_APBRst0_TMR3) ||   \
                                 ((VALUE) == RCU_APBRst0_ETMR0) ||  \
                                 ((VALUE) == RCU_APBRst0_ETMR1) ||  \
                                 ((VALUE) == RCU_APBRst0_ETMR2) ||  \
                                 ((VALUE) == RCU_APBRst0_ETMR3) ||  \
                                 ((VALUE) == RCU_APBRst0_RTC) ||    \
                                 ((VALUE) == RCU_APBRst0_ECAP0) ||  \
                                 ((VALUE) == RCU_APBRst0_ECAP1) ||  \
                                 ((VALUE) == RCU_APBRst0_ECAP2) ||  \
                                 ((VALUE) == RCU_APBRst0_ECAP3) ||  \
                                 ((VALUE) == RCU_APBRst0_ECAP4) ||  \
                                 ((VALUE) == RCU_APBRst0_ECAP5))

/**
  * @}
  */

/** @defgroup RCU_APBRst1_Define Управление сбросом периферийных блоков APB группа 1
  * @{
  */

#define RCU_APBRst1_PWM0 RCU_PRSTCFG1_PWM0EN_Msk /*!< Управление сбросом блока PWM 0 */
#define RCU_APBRst1_PWM1 RCU_PRSTCFG1_PWM1EN_Msk /*!< Управление сбросом блока PWM 1 */
#define RCU_APBRst1_PWM2 RCU_PRSTCFG1_PWM2EN_Msk /*!< Управление сбросом блока PWM 2 */
#define RCU_APBRst1_PWM3 RCU_PRSTCFG1_PWM3EN_Msk /*!< Управление сбросом блока PWM 3 */
#define RCU_APBRst1_PWM4 RCU_PRSTCFG1_PWM4EN_Msk /*!< Управление сбросом блока PWM 4 */
#define RCU_APBRst1_PWM5 RCU_PRSTCFG1_PWM5EN_Msk /*!< Управление сбросом блока PWM 5 */
#define RCU_APBRst1_PWM6 RCU_PRSTCFG1_PWM6EN_Msk /*!< Управление сбросом блока PWM 6 */
#define RCU_APBRst1_PWM7 RCU_PRSTCFG1_PWM7EN_Msk /*!< Управление сбросом блока PWM 7 */
#define RCU_APBRst1_PWM8 RCU_PRSTCFG1_PWM8EN_Msk /*!< Управление сбросом блока PWM 8 */
#define RCU_APBRst1_PWM9 RCU_PRSTCFG1_PWM9EN_Msk /*!< Управление сбросом блока PWM 9 */
#define RCU_APBRst1_QEP0 RCU_PRSTCFG1_QEP0EN_Msk /*!< Управление сбросом блока QEP 0 */
#define RCU_APBRst1_QEP1 RCU_PRSTCFG1_QEP1EN_Msk /*!< Управление сбросом блока QEP 1 */
#define RCU_APBRst1_QEP2 RCU_PRSTCFG1_QEP2EN_Msk /*!< Управление сбросом блока QEP 2 */
#define RCU_APBRst1_QEP3 RCU_PRSTCFG1_QEP3EN_Msk /*!< Управление сбросом блока QEP 3 */
#define RCU_APBRst1_LAU RCU_PRSTCFG1_LAUEN_Msk   /*!< Управление сбросом блока LAU */
#define RCU_APBRst1_OWI0 RCU_PRSTCFG1_OWI0EN_Msk /*!< Управление сбросом блока OWI 0 */
#define RCU_APBRst1_OWI1 RCU_PRSTCFG1_OWI1EN_Msk /*!< Управление сбросом блока OWI 1 */

#define IS_RCU_APB_RST_1(VALUE) (((VALUE) == RCU_APBRst1_PWM0) || \
                                 ((VALUE) == RCU_APBRst1_PWM1) || \
                                 ((VALUE) == RCU_APBRst1_PWM2) || \
                                 ((VALUE) == RCU_APBRst1_PWM3) || \
                                 ((VALUE) == RCU_APBRst1_PWM4) || \
                                 ((VALUE) == RCU_APBRst1_PWM5) || \
                                 ((VALUE) == RCU_APBRst1_PWM6) || \
                                 ((VALUE) == RCU_APBRst1_PWM7) || \
                                 ((VALUE) == RCU_APBRst1_PWM8) || \
                                 ((VALUE) == RCU_APBRst1_PWM9) || \
                                 ((VALUE) == RCU_APBRst1_QEP0) || \
                                 ((VALUE) == RCU_APBRst1_QEP1) || \
                                 ((VALUE) == RCU_APBRst1_QEP2) || \
                                 ((VALUE) == RCU_APBRst1_QEP3) || \
                                 ((VALUE) == RCU_APBRst1_LAU) ||  \
                                 ((VALUE) == RCU_APBRst1_OWI0) || \
                                 ((VALUE) == RCU_APBRst1_OWI1))

/**
  * @}
  */

/** @defgroup RCU_AHBRst_Define Управление сбросом периферийных блоков AHB
  * @{
  */

#define RCU_AHBRst_GPIOA RCU_HRSTCFG_GPIOAEN_Msk     /*!< Управление сбросом блока GPIOA */
#define RCU_AHBRst_GPIOB RCU_HRSTCFG_GPIOBEN_Msk     /*!< Управление сбросом блока GPIOB */
#define RCU_AHBRst_GPIOC RCU_HRSTCFG_GPIOCEN_Msk     /*!< Управление сбросом блока GPIOC */
#define RCU_AHBRst_GPIOD RCU_HRSTCFG_GPIODEN_Msk     /*!< Управление сбросом блока GPIOD */
#define RCU_AHBRst_GPIOE RCU_HRSTCFG_GPIOEEN_Msk     /*!< Управление сбросом блока GPIOE */
#define RCU_AHBRst_GPIOF RCU_HRSTCFG_GPIOFEN_Msk     /*!< Управление сбросом блока GPIOF */
#define RCU_AHBRst_GPIOG RCU_HRSTCFG_GPIOGEN_Msk     /*!< Управление сбросом блока GPIOG */
#define RCU_AHBRst_GPIOH RCU_HRSTCFG_GPIOHEN_Msk     /*!< Управление сбросом блока GPIOH */
#define RCU_AHBRst_GPIOJ RCU_HRSTCFG_GPIOJEN_Msk     /*!< Управление сбросом блока GPIOJ */
#define RCU_AHBRst_GPIOK RCU_HRSTCFG_GPIOKEN_Msk     /*!< Управление сбросом блока GPIOK */
#define RCU_AHBRst_GPIOL RCU_HRSTCFG_GPIOLEN_Msk     /*!< Управление сбросом блока GPIOL */
#define RCU_AHBRst_GPIOM RCU_HRSTCFG_GPIOMEN_Msk     /*!< Управление сбросом блока GPIOM */
#define RCU_AHBRst_CAN RCU_HRSTCFG_CANEN_Msk         /*!< Управление сбросом блока CAN */
#define RCU_AHBRst_MILSTD0 RCU_HRSTCFG_MILSTD0EN_Msk /*!< Управление сбросом блока MILSTD 0 */
#define RCU_AHBRst_MILSTD1 RCU_HRSTCFG_MILSTD1EN_Msk /*!< Управление сбросом блока MILSTD 1 */
#define RCU_AHBRst_SPWR0 RCU_HRSTCFG_SPWR0EN_Msk     /*!< Управление сбросом блока SPWR 0 */
#define RCU_AHBRst_SPWR1 RCU_HRSTCFG_SPWR1EN_Msk     /*!< Управление сбросом блока SPWR 1 */
#define RCU_AHBRst_EXTMEM RCU_HRSTCFG_EXTMEMEN_Msk   /*!< Управление сбросом блока EXTMEM */
#define RCU_AHBRst_SDFM RCU_HRSTCFG_SDFMEN_Msk       /*!< Управление сбросом блока SDFM */

#define IS_RCU_AHB_RST(VALUE) (((VALUE) == RCU_AHBRst_GPIOA) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOB) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOC) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOD) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOE) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOF) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOG) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOH) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOJ) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOK) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOL) ||   \
                               ((VALUE) == RCU_AHBRst_GPIOM) ||   \
                               ((VALUE) == RCU_AHBRst_CAN) ||     \
                               ((VALUE) == RCU_AHBRst_MILSTD0) || \
                               ((VALUE) == RCU_AHBRst_MILSTD1) || \
                               ((VALUE) == RCU_AHBRst_SPWR0) ||   \
                               ((VALUE) == RCU_AHBRst_SPWR1) ||   \
                               ((VALUE) == RCU_AHBRst_EXTMEM) ||  \
                               ((VALUE) == RCU_AHBRst_GPIOM) ||   \
                               ((VALUE) == RCU_AHBRst_SDFM))

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
  * @brief  Выбор источника опорного сигнала PLL
  */
typedef enum {
    RCU_PLL_Ref_OSEClk = RCU_PLLCFG_REFSRC_OSECLK,      /*!< Сигнал внешнего осциллятора */
    RCU_PLL_Ref_OSIClk = RCU_PLLCFG_REFSRC_OSICLK,      /*!< Сигнал внтуреннего осциллятора */
    RCU_PLL_Ref_PLLExtClk = RCU_PLLCFG_REFSRC_PLLEXTCLK /*!< Внешний тактовый сигнал PLLEXTCLK */
} RCU_PLL_Ref_TypeDef;
#define IS_RCU_PLL_REF(VALUE) (((VALUE) == RCU_PLL_Ref_OSEClk) || \
                               ((VALUE) == RCU_PLL_Ref_OSIClk) || \
                               ((VALUE) == RCU_PLL_Ref_PLLExtClk))

/**
  * @brief  Выбор источника тактирования для периферийного блока
  *         c несколькими тактовыми доменами - ADC, UART, SPI, MILSTD
  */
typedef enum {
    RCU_PeriphClk_OSEClk = RCU_SPICFG_SPICFG_CLKSEL_OSECLK,       /*!< Сигнал внешнего осциллятора */
    RCU_PeriphClk_PLLClk = RCU_SPICFG_SPICFG_CLKSEL_PLLCLK,       /*!< Сигнал с PLL */
    RCU_PeriphClk_PLLDivClk = RCU_SPICFG_SPICFG_CLKSEL_PLLDIVCLK, /*!< Сигнал с деленного выхода PLL */
    RCU_PeriphClk_PLLExtClk = RCU_SPICFG_SPICFG_CLKSEL_PLLEXTCLK  /*!< Сигнал с внешнего входа PLLEXTCLK */
} RCU_PeriphClk_TypeDef;
#define IS_RCU_PERIPH_CLK(VALUE) (((VALUE) == RCU_PeriphClk_OSEClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_PLLClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_PLLDivClk) || \
                                  ((VALUE) == RCU_PeriphClk_PLLExtClk))

/**
  * @brief  Выбор источника тактирования для CLKOUT, WDT
  */
typedef enum {
    RCU_SysPeriphClk_RefClk = RCU_CLKOUTCFG_CLKSEL_REFCLK, /*!< Сигнал REFCLK */
    RCU_SysPeriphClk_SrcClk = RCU_CLKOUTCFG_CLKSEL_SRCCLK, /*!< Сигнал SRCLK */
    RCU_SysPeriphClk_SysClk = RCU_CLKOUTCFG_CLKSEL_SYSCLK, /*!< Сигнал SYSCLK */
    RCU_SysPeriphClk_PLLClk = RCU_CLKOUTCFG_CLKSEL_PLLCLK  /*!< Сигнал PLLCLK */
} RCU_SysPeriphClk_TypeDef;
#define IS_RCU_SYS_PERIPH_CLK(VALUE) (((VALUE) == RCU_SysPeriphClk_RefClk) || \
                                      ((VALUE) == RCU_SysPeriphClk_SrcClk) || \
                                      ((VALUE) == RCU_SysPeriphClk_SysClk) || \
                                      ((VALUE) == RCU_SysPeriphClk_PLLClk))

/**
  * @brief  Выбор источника тактирования для TRACE
  */
typedef enum {
    RCU_TraceClk_RefClk = RCU_TRACECFG_CLKSEL_REFCLK,          /*!< Сигнал REFCLK */
    RCU_TraceClk_SrcClk = RCU_TRACECFG_CLKSEL_SRCCLK,          /*!< Сигнал SRCLK */
    RCU_TraceClk_SysClk = RCU_TRACECFG_CLKSEL_SYSCLK,          /*!< Сигнал SYSCLK */
    RCU_TraceClk_TRACEExtClk = RCU_TRACECFG_CLKSEL_TRACEEXTCLK /*!< Сигнал TRACEEXTCLK */
} RCU_TraceClk_TypeDef;
#define IS_RCU_TRACE_CLK(VALUE) (((VALUE) == RCU_TraceClk_RefClk) || \
                                 ((VALUE) == RCU_TraceClk_SrcClk) || \
                                 ((VALUE) == RCU_TraceClk_SysClk) || \
                                 ((VALUE) == RCU_TraceClk_TRACEExtClk))

/**
  * @brief  Выбор источника системной частоты
  */
typedef enum {
    RCU_SysClk_RefClk = RCU_SYSCLKCFG_SYSSEL_REFCLK,      /*!< Сигнал REFCLK */
    RCU_SysClk_SrcClk = RCU_SYSCLKCFG_SYSSEL_SRCCLK,      /*!< Сигнал SRCCLK */
    RCU_SysClk_PLLClk = RCU_SYSCLKCFG_SYSSEL_PLLCLK,      /*!< Сигнал с PLL */
    RCU_SysClk_PLLDivClk = RCU_SYSCLKCFG_SYSSEL_PLLDIVCLK /*!< Сигнал с деленного выхода PLL */
} RCU_SysClk_TypeDef;
#define IS_RCU_SYS_CLK(VALUE) (((VALUE) == RCU_SysClk_RefClk) || \
                               ((VALUE) == RCU_SysClk_SrcClk) || \
                               ((VALUE) == RCU_SysClk_PLLClk) || \
                               ((VALUE) == RCU_SysClk_PLLDivClk))

/**
  * @brief  Структура инициализации PLL
  *
  */
typedef struct
{
    uint32_t DivVal;         /*!< Значение внешнего делителя сигнала на выходе блока PLL (итоговое значение 2*(Div+1)).
                                   Параметр может принимать любое значение из диапазона 0-63. */
    FunctionalState DivEn;   /*!< Активация внешнего делителя PLL*/
    RCU_PLL_Ref_TypeDef Ref; /*!< Источник опорного сигнала PLL */
    uint32_t RefDiv;         /*!< Делитель опорного сигнала PLL.
                                   Параметр может принимать любое значение из диапазона 1-63. */
    uint32_t FbDiv;          /*!< Делитель обратной связи.
                                   Параметр может принимать любое значение из диапазона 16-200. */
    uint32_t Div1;           /*!< Внутренний делитель PLL 1.
                                   Параметр может принимать любое значение из диапазона 1-7. */
    uint32_t Div2;           /*!< Внутренний делитель PLL 2.
                                   Параметр может принимать любое значение из диапазона 1-7. */
} RCU_PLL_Init_TypeDef;

#define IS_RCU_PLL_DIV(VALUE) (((VALUE)&0xFFFFFFC0) == 0)
#define IS_RCU_PLL_REF_DIV(VALUE) (((VALUE) <= 63) && ((VALUE) >= 1))
#define IS_RCU_PLL_FB_DIV(VALUE) (((VALUE) <= 200) && ((VALUE) >= 16))
#define IS_RCU_PLL_DIV1(VALUE) (((VALUE) <= 7) && ((VALUE) >= 1))
#define IS_RCU_PLL_DIV2(VALUE) (((VALUE) <= 7) && ((VALUE) >= 1))
#define IS_RCU_PLL_REF_FREQ(VALUE) (((VALUE) <= 800000000) && ((VALUE) >= 8000000))
#define IS_RCU_PLL_OUT_FREQ(VALUE) (((VALUE) <= 1600000000) && ((VALUE) >= 8000000))
#define IS_RCU_PLL_VCO_FREQ(VALUE) (((VALUE) <= 1600000000) && ((VALUE) >= 400000000))
#define IS_RCU_SYSCLK_FREQ(VALUE) (((VALUE) <= 200000000) && ((VALUE) >= 1000000))
#define IS_RCU_SECPRD(VALUE) (((VALUE)&0xFFFFFF00) == 0)
#define IS_RCU_PERIPH_DIV(VALUE) (((VALUE)&0xFFFFFFC0) == 0)
#define IS_RCU_CLKOUT_DIV(VALUE) (((VALUE)&0xFFFFFFF8) == 0)

/**
  * @}
  */

/** @defgroup RCU_Exported_Functions Функции
  * @{
  */

uint32_t RCU_GetOSIClkFreq(void);
uint32_t RCU_GetOSEClkFreq(void);
uint32_t RCU_GetRefClkFreq(void);
uint32_t RCU_GetSrcClkFreq(void);
uint32_t RCU_GetPLLClkFreq(void);
uint32_t RCU_GetPLLDivClkFreq(void);
uint32_t RCU_GetPLLExtClkFreq(void);
uint32_t RCU_GetTraceExtClkFreq(void);

/**
  * @brief   Включение тактирования выбранного APB блока периферии.
  *          Группа 0: TUART, I2C, TMR, ETMR, RTC, ECAP.
  * @param   APBClk0  Выбор периферии. Любая совокупность значений значений RCU_APBClk0_x (@ref RCU_APBClk0_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBClk0Cmd(uint32_t APBClk0, FunctionalState State)
{
    assert_param(IS_RCU_APB_CLK_0(APBClk0));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PCLKCFG0, APBClk0, State ? APBClk0 : 0);
}

/**
  * @brief   Включение тактирования выбранного APB блока периферии.
  *          Группа 1: PWM, QEP, LAU, OWI.
  * @param   APBClk1  Выбор периферии. Любая совокупность значений значений RCU_APBClk1_x (@ref RCU_APBClk1_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBClk1Cmd(uint32_t APBClk1, FunctionalState State)
{
    assert_param(IS_RCU_APB_CLK_1(APBClk1));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PCLKCFG1, APBClk1, State ? APBClk1 : 0);
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
  *          Группа 0: TUART, I2C, TMR, ETMR, RTC, ECAP.
  * @param   APBRst0  Выбор периферийного модуля. Любая совокупность значений значений RCU_APBRst0_x (@ref RCU_APBRst0_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBRst0Cmd(uint32_t APBRst0, FunctionalState State)
{
    assert_param(IS_RCU_APB_RST_0(APBRst0));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PRSTCFG0, APBRst0, State ? APBRst0 : 0);
}

/**
  * @brief   Вывод из состояния сброса периферийных блоков APB
  *          Группа 1: PWM, QEP, LAU, OWI.
  * @param   APBRst1  Выбор периферийного модуля. Любая совокупность значений значений RCU_APBRst1_x (@ref RCU_APBRst1_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBRst1Cmd(uint32_t APBRst1, FunctionalState State)
{
    assert_param(IS_RCU_APB_RST_1(APBRst1));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->PRSTCFG1, APBRst1, State ? APBRst1 : 0);
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

uint32_t RCU_GetSysClkFreq(void);

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
  * @param   SrcPrd  Максимальное значение счетчика слежения за сигналом SRCCLK
  * @param   PLLPrd  Максимальное значение счетчика слежения за сигналом PLLCLK
  * @param   PLLDivPrd  Максимальное значение счетчика слежения за сигналом PLLDIVCLK
  * @retval  void
  */
__STATIC_INLINE void RCU_SecurityConfig(uint32_t SrcPrd, uint32_t PLLPrd, uint32_t PLLDivPrd)
{
    assert_param(IS_RCU_SECPRD(SrcPrd));
    assert_param(IS_RCU_SECPRD(PLLPrd));
    assert_param(IS_RCU_SECPRD(PLLDivPrd));

    MODIFY_REG(RCU->SECPRD, (RCU_SECPRD_SRCCLK_Msk | RCU_SECPRD_PLLCLK_Msk | RCU_SECPRD_PLLDIVCLK_Msk),
               ((SrcPrd << RCU_SECPRD_SRCCLK_Pos) | (PLLPrd << RCU_SECPRD_PLLCLK_Pos) | (PLLDivPrd << RCU_SECPRD_PLLDIVCLK_Pos)));
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

OperationStatus RCU_SysClkChangeCmd(RCU_SysClk_TypeDef SysClk);

/** @defgroup RCU_Init_Deinit Конфигурация PLL
  * @{
  */

OperationStatus RCU_PLL_AutoConfig(uint32_t SysClkFreq, RCU_PLL_Ref_TypeDef Ref);
OperationStatus RCU_PLL_Init(RCU_PLL_Init_TypeDef* InitStruct);
void RCU_PLL_DeInit(void);
void RCU_PLL_StructInit(RCU_PLL_Init_TypeDef* InitStruct);

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
  * @brief   Разрешение работы выхода PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_OutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.OUTDIS, !State);
}

/**
  * @brief   Разрешение работы PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.PD, !State);
}

/**
  * @brief   Включение режима bypass PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_BypassCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.BP, State);
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
__STATIC_INLINE void RCU_TraceClkConfig(RCU_TraceClk_TypeDef TraceClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_TRACE_CLK(TraceClk));
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

uint32_t RCU_GetSPIClkFreq(SPI_Num_TypeDef SPIx_Num);

/**
  * @brief   Настройка тактирования SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   SPIClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkConfig(SPI_Num_TypeDef SPIx_Num, RCU_PeriphClk_TypeDef SPIClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(SPIClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->SPICFG[SPIx_Num].SPICFG, (RCU_SPICFG_SPICFG_CLKSEL_Msk | RCU_SPICFG_SPICFG_DIVN_Msk | RCU_SPICFG_SPICFG_DIVEN_Msk),
               ((SPIClk << RCU_SPICFG_SPICFG_CLKSEL_Pos) | (DivVal << RCU_SPICFG_SPICFG_DIVN_Pos) | (DivState << RCU_SPICFG_SPICFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkCmd(SPI_Num_TypeDef SPIx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIRstCmd(SPI_Num_TypeDef SPIx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_MILSTD Тактирование и сброс MILSTD
  * @{
  */

uint32_t RCU_GetMILSTDClkFreq(MILSTD_Num_TypeDef MILSTDx_Num);

/**
  * @brief   Настройка тактирования MILSTD
  * @param   MILSTDx_Num  Порядковый номер блока MILSTD
  * @param   MILSTDClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_MILSTDClkConfig(MILSTD_Num_TypeDef MILSTDx_Num, RCU_PeriphClk_TypeDef MILSTDClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(MILSTDClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG, (RCU_MILSTDCFG_MILSTDCFG_CLKSEL_Msk | RCU_MILSTDCFG_MILSTDCFG_DIVN_Msk | RCU_MILSTDCFG_MILSTDCFG_DIVEN_Msk),
               ((MILSTDClk << RCU_MILSTDCFG_MILSTDCFG_CLKSEL_Pos) | (DivVal << RCU_MILSTDCFG_MILSTDCFG_DIVN_Pos) | (DivState << RCU_MILSTDCFG_MILSTDCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования MILSTD
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_MILSTDClkCmd(MILSTD_Num_TypeDef MILSTDx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса MILSTD
  * @param   MILSTDx_Num  Порядковый номер блока MILSTD
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_MILSTDRstCmd(MILSTD_Num_TypeDef MILSTDx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_SPWR Тактирование и сброс SPWR
  * @{
  */

uint32_t RCU_GetSPWRClkFreq(SPWR_Num_TypeDef SPWRx_Num);

/**
  * @brief   Настройка тактирования SPWR
  * @param   SPWRx_Num  Порядковый номер блока SPWR
  * @param   SPWRClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_SPWRClkConfig(SPWR_Num_TypeDef SPWRx_Num, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->SPWRCFG[SPWRx_Num].SPWRCFG, (RCU_SPWRCFG_SPWRCFG_DIVN_Msk | RCU_SPWRCFG_SPWRCFG_DIVEN_Msk),
               ((DivVal << RCU_SPWRCFG_SPWRCFG_DIVN_Pos) | (DivState << RCU_SPWRCFG_SPWRCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования SPWR
  * @param   SPWRx_Num  Порядковый номер блока SPWR
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPWRClkCmd(SPWR_Num_TypeDef SPWRx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPWRCFG[SPWRx_Num].SPWRCFG_bit.CLKEN, State);
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

#endif /* __PLIB028_RCU_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
