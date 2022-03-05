/**
  ******************************************************************************
  * @file    plib028_pmu.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          PMU, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_PMU_H
#define __PLIB028_PMU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup PMU
  * @brief Драйвер для работы с PMU
  * @{
  */

/** @defgroup PMU_Exported_Defines Константы
  * @{
  */

/** @defgroup PMU_ADCLDO_Define Управление LDO внутри АЦП
  * @{
  */

#define PMU_ADCLDO_0 PMU_ADCPC_LDOEN0_Msk /*!< Управление LDO АЦП0 */
#define PMU_ADCLDO_1 PMU_ADCPC_LDOEN1_Msk /*!< Управление LDO АЦП1 */
#define PMU_ADCLDO_2 PMU_ADCPC_LDOEN2_Msk /*!< Управление LDO АЦП2 */
#define PMU_ADCLDO_3 PMU_ADCPC_LDOEN3_Msk /*!< Управление LDO АЦП3 */
#define PMU_ADCLDO_All (PMU_ADCLDO_0 | \
                        PMU_ADCLDO_1 | \
                        PMU_ADCLDO_2 | \
                        PMU_ADCLDO_3) /*!< Управление LDO всех АЦП */

#define IS_PMU_ADC_LDO(VALUE) (((VALUE) & ~PMU_ADCLDO_All) == 0)

/**
  * @}
  */

/** @defgroup PMU_ADCLDOStatus_Define Статус LDO внутри АЦП
  * @{
  */

#define PMU_ADCLDOStatus_Ready0 PMU_ADCPC_LDORDY0_Msk /*!< Статус готовности LDO АЦП0 */
#define PMU_ADCLDOStatus_Ready1 PMU_ADCPC_LDORDY1_Msk /*!< Статус готовности LDO АЦП1 */
#define PMU_ADCLDOStatus_Ready2 PMU_ADCPC_LDORDY2_Msk /*!< Статус готовности LDO АЦП2 */
#define PMU_ADCLDOStatus_Ready3 PMU_ADCPC_LDORDY3_Msk /*!< Статус готовности LDO АЦП3 */
#define PMU_ADCLDOStatus_ReadyAll (PMU_ADCLDOStatus_Ready0 | \
                                   PMU_ADCLDOStatus_Ready1 | \
                                   PMU_ADCLDOStatus_Ready2 | \
                                   PMU_ADCLDOStatus_Ready3) /*!< Статусы LDO всех АЦП */

#define IS_PMU_ADC_LDO_STATUS(VALUE) (((VALUE) & ~PMU_ADCLDOStatus_ReadyAll) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup PMU_Exported_Types Типы
  * @{
  */

/**
  * @brief  Управление режимом powerdown выбранного блока периферии
  */
typedef enum {
    PMU_PeriphPD_PLL = PMU_PDEN_PLLPD_Msk,       /*!< Управление режимом powerdown PLL */
    PMU_PeriphPD_MFLASH = PMU_PDEN_MFLASHPD_Msk, /*!< Управление режимом powerdown MFLASH */
    PMU_PeriphPD_BFLASH = PMU_PDEN_BFLASHPD_Msk, /*!< Управление режимом powerdown BFLASH */
    PMU_PeriphPD_OSE = PMU_PDEN_OSEPD_Msk        /*!< Управление режимом powerdown OSE */
} PMU_PeriphPD_TypeDef;
#define IS_PMU_PERIPH_PD(VALUE) (((VALUE) == PMU_PeriphPD_PLL) ||    \
                                 ((VALUE) == PMU_PeriphPD_MFLASH) || \
                                 ((VALUE) == PMU_PeriphPD_BFLASH) || \
                                 ((VALUE) == PMU_PeriphPD_OSE))

/**
  * @brief  Управление разрешением получения событий RXEV от портов
  */
typedef enum {
    PMU_RXEV_GPIOA = PMU_RXEVEN_GPIOAEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOA */
    PMU_RXEV_GPIOB = PMU_RXEVEN_GPIOBEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOB */
    PMU_RXEV_GPIOC = PMU_RXEVEN_GPIOCEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOC */
    PMU_RXEV_GPIOD = PMU_RXEVEN_GPIODEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOD */
    PMU_RXEV_GPIOE = PMU_RXEVEN_GPIOEEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOE */
    PMU_RXEV_GPIOF = PMU_RXEVEN_GPIOFEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOF */
    PMU_RXEV_GPIOG = PMU_RXEVEN_GPIOGEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOG */
    PMU_RXEV_GPIOH = PMU_RXEVEN_GPIOHEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOH */
    PMU_RXEV_GPIOJ = PMU_RXEVEN_GPIOJEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOJ */
    PMU_RXEV_GPIOK = PMU_RXEVEN_GPIOKEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOK */
    PMU_RXEV_GPIOL = PMU_RXEVEN_GPIOLEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOL */
    PMU_RXEV_GPIOM = PMU_RXEVEN_GPIOMEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOM */
} PMU_RXEV_TypeDef;
#define IS_PMU_RXEV(VALUE) (((VALUE) == PMU_RXEV_GPIOA) || \
                            ((VALUE) == PMU_RXEV_GPIOB) || \
                            ((VALUE) == PMU_RXEV_GPIOC) || \
                            ((VALUE) == PMU_RXEV_GPIOD) || \
                            ((VALUE) == PMU_RXEV_GPIOE) || \
                            ((VALUE) == PMU_RXEV_GPIOF) || \
                            ((VALUE) == PMU_RXEV_GPIOG) || \
                            ((VALUE) == PMU_RXEV_GPIOH) || \
                            ((VALUE) == PMU_RXEV_GPIOJ) || \
                            ((VALUE) == PMU_RXEV_GPIOK) || \
                            ((VALUE) == PMU_RXEV_GPIOL) || \
                            ((VALUE) == PMU_RXEV_GPIOM))

#define IS_PMU_POWERUP_DELAY(VALUE) (((VALUE)&0xFFFF0000) == 0)

/**
  * @}
  */

/** @defgroup PMU_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы PMU - необходимо для перехода в режим Deepsleep
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PMU_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PMU->CFG_bit.EN, State);
}

/**
  * @brief   Настройка задержки выхода из сна в тактах OSI
  * @param   DelayVal  Величина хадержки
  * @retval  void
  */
__STATIC_INLINE void PMU_PowerUpDelayConfig(uint32_t DelayVal)
{
    assert_param(IS_PMU_POWERUP_DELAY(DelayVal));

    WRITE_REG(PMU->PUDEL, DelayVal);
}

/**
  * @brief   Управление режимом powerdown выбранного блока периферии
  * @param   PeriphPD  Выбор периферии
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PMU_PeriphPDCmd(PMU_PeriphPD_TypeDef PeriphPD, FunctionalState State)
{
    assert_param(IS_PMU_PERIPH_PD(PeriphPD));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(PMU->PDEN, PeriphPD, State ? (uint32_t)PeriphPD : 0);
}

/**
  * @brief   Управление разрешением получения событий RXEV от портов
  * @param   RXEV  Выбор порта
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PMU_RXEVCmd(PMU_RXEV_TypeDef RXEV, FunctionalState State)
{
    assert_param(IS_PMU_RXEV(RXEV));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(PMU->RXEVEN, RXEV, State ? (uint32_t)RXEV : 0);
}

/**
  * @brief   Управление LDO внутри АЦП
  * @param   ADCLDO  Выбор LDO АЦП. Любая совокупность значений PMU_ADCLDO_x (@ref PMU_ADCLDO_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PMU_ADCLDOCmd(uint32_t ADCLDO, FunctionalState State)
{
    assert_param(IS_PMU_ADC_LDO(ADCLDO));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(PMU->ADCPC, ADCLDO, State ? (uint32_t)ADCLDO : 0);
}

/**
  * @brief   Получение статуса выбранного LDO АЦП
  * @param   ADCLDOStatus  Выбор статуса LDO АЦП. Любая совокупность значений PMU_ADCLDOStatus_x (@ref PMU_ADCLDOStatus_Define).
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus PMU_ADCLDOStatus(uint32_t ADCLDOStatus)
{
    return (FlagStatus)READ_BIT(PMU->ADCPC, ADCLDOStatus);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_PMU_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
