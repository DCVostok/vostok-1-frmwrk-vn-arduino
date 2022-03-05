/**
  ******************************************************************************
  * @file    plib035_pmu.h
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
  * <h2><center>&copy; 2018 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB035_PMU_H
#define __PLIB035_PMU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

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
    PMU_PeriphPD_OSE = PMU_PDEN_OSEPD_Msk        /*!< Управление режимом powerdown OSE */
} PMU_PeriphPD_TypeDef;
#define IS_PMU_PERIPH_PD(VALUE) (((VALUE) == PMU_PeriphPD_PLL) ||    \
                                 ((VALUE) == PMU_PeriphPD_MFLASH) || \
                                 ((VALUE) == PMU_PeriphPD_OSE))

/**
  * @brief  Управление разрешением получения событий RXEV от портов
  */
typedef enum {
    PMU_RXEV_GPIOA = PMU_RXEVEN_GPIOAEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOA */
    PMU_RXEV_GPIOB = PMU_RXEVEN_GPIOBEV_Msk, /*!< Управление разрешением получения событий RXEV от GPIOB */
} PMU_RXEV_TypeDef;
#define IS_PMU_RXEV(VALUE) (((VALUE) == PMU_RXEV_GPIOA) || \
                            ((VALUE) == PMU_RXEV_GPIOB))

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
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_PMU_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
