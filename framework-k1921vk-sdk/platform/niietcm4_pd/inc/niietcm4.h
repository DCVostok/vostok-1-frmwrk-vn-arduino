/**
  ******************************************************************************
  * @file    niietcm4.h
  *
  * @brief   Это главный заголовочный файл драйвера, обычно включаемый в main.c.
  *
  *          Этот файл содержит:
  *           - Главный заголовочный файл целевого устройства, с описанием всех регистров его периферии
  *           - Область настройки драйвера, которая позволяет сконфигурировать:
  *              - Модель целевого устройства
  *              - Используемые тактовые частоты
  *           - Макросы для доступа к регистрам периферии
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

/** @addtogroup NIIETCM4_PeriphDriver Драйвер периферии
  * @{
  */

#ifndef __NIIETCM4_H
#define __NIIETCM4_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup Driver_configuration_section Настройка драйвера
  * @{
  */

#if defined (K1921VK01T)
    #include  "K1921VK01T.h"
/*  Совет: Чтобы избежать необходимости каждый раз изменять этот файл,
 *         можно передать определение устройства компилятору через ключ.
 *         Например, для GCC ARM это выглядит так:
 *         -DK1921VK01T
 */

#else
    #error "Не указано целевое устройство (файл niietcm4.h)"
#endif

/**
 * @brief Определение частоты используемого внешнего тактового генератора.
 *
 * Совет: Чтобы избежать необходимости каждый раз изменять этот файл,
 *        можно передать определение устройства компилятору через ключ.
 *        <br>Например, для GCC ARM это выглядит так:
 *        <br>-DEXT_OSC_VALUE=16000000<br><br>
 */

#if !defined  EXT_OSC_VALUE
    #define EXT_OSC_VALUE    ((uint32_t)12000000) /*!< Частота внешнего тактового генератора [Гц]. */
#endif /* EXT_OSC_VALUE */

/**
 * @brief Определение частоты частоты внутреннего тактового генератора.
 *
 * Кофигурируется автоматически в зависимости от выбранного целевого устройства.
 */

#if defined (K1921VK01T)
    #if !defined  INT_OSC_VALUE
        #define INT_OSC_VALUE    ((uint32_t)5000000) /*!< Частота внутреннего тактового генератора [Гц]. */
    #endif
#else
    #if !defined  INT_OSC_VALUE
        #define INT_OSC_VALUE    ((uint32_t)8000000) /*!< Частота внутреннего тактового генератора [Гц]. */
    #endif /* INT_OSC_VALUE */
#endif

/**
  * @}
  */



/** @addtogroup Exported_macro Макросы
  * @{
  */

#if defined (__ICCARM__)
    #define __RAMFUNC   __ramfunc
#elif defined (__CMCARM__)
    #define __RAMFUNC   __ramfunc
#elif defined (__CC_ARM)
    #define __RAMFUNC
#elif defined (__GNUC__)
    #define __RAMFUNC   __attribute__((long_call, section(".ramfunc")))
#elif defined (__CMCPPARM__)
    #define __RAMFUNC   /*Not support only #pragma ramfunc*/
#else
    #error "Нет реализации под данный компилятор"
#endif

/**
 * @brief Установить бит в регистре.
 */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

/**
  * @brief Сбросить бит в регистре.
  */

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

/**
  * @brief Прочитать бит из регистра.
  */

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

/**
  * @brief Обнулить значение регистра.
  */

#define CLEAR_REG(REG)        ((REG) = (0x0))

/**
  * @brief Записать значение в регистр.
  */

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

/**
  * @brief Прочитать значение из регистра.
  */

#define READ_REG(REG)         ((REG))

/**
  * @brief Изменить значение регистра по маске.
  */

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

/** @addtogroup Exported_Types Типы
  * @{
  */

/**
  * @brief Описывает логическое состояние периферии.
  * Используется для операций включения/выключения периферийных блоков.
  */

typedef enum
{
    DISABLE = 0,
    ENABLE = 1
}FunctionalState;

/**
   * @brief Макрос проверки аргументов типа @ref FunctionalState.
   */

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

/**
  * @brief Описывает коды возврата для функций при выполнении какой-либо операции.
  */

typedef enum
{
    OK = 0,
    ERROR = 1
}OperationStatus;

/**
  * @brief Описывает возможные состояния флага при запросе его статуса.
  */

typedef enum
{
    Flag_CLEAR = 0,
    Flag_SET = 1
}FlagStatus;

/**
  * @brief Макрос проверки аргументов типа @ref NT_TIMER_TypeDef.
  */

#define IS_TIMER_ALL_PERIPH(PERIPH) (((PERIPH) == NT_TIMER0) || \
                                     ((PERIPH) == NT_TIMER1) || \
                                     ((PERIPH) == NT_TIMER2))

/**
  * @brief Макрос проверки аргументов типа @ref NT_GPIO_TypeDef.
  */

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == NT_GPIOA) || \
                                    ((PERIPH) == NT_GPIOB) || \
                                    ((PERIPH) == NT_GPIOC) || \
                                    ((PERIPH) == NT_GPIOD) || \
                                    ((PERIPH) == NT_GPIOE) || \
                                    ((PERIPH) == NT_GPIOF) || \
                                    ((PERIPH) == NT_GPIOG) || \
                                    ((PERIPH) == NT_GPIOH))

/**
  * @brief Макрос проверки аргументов типа @ref NT_UART_TypeDef.
  */

#define IS_UART_ALL_PERIPH(PERIPH) (((PERIPH) == NT_UART0) || \
                                    ((PERIPH) == NT_UART1) || \
                                    ((PERIPH) == NT_UART2) || \
                                    ((PERIPH) == NT_UART3))

/**
  * @brief Макрос проверки аргументов типа @ref NT_SPI_TypeDef.
  */

#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == NT_SPI0) || \
                                   ((PERIPH) == NT_SPI1) || \
                                   ((PERIPH) == NT_SPI2) || \
                                   ((PERIPH) == NT_SPI3))

/**
  * @brief Макрос проверки аргументов типа @ref NT_CAP_TypeDef.
  */

#define IS_CAP_ALL_PERIPH(PERIPH) (((PERIPH) == NT_CAP0) || \
                                   ((PERIPH) == NT_CAP1) || \
                                   ((PERIPH) == NT_CAP2) || \
                                   ((PERIPH) == NT_CAP3) || \
                                   ((PERIPH) == NT_CAP4) || \
                                   ((PERIPH) == NT_CAP5))

/**
  * @brief Макрос проверки аргументов типа @ref NT_PWM_TypeDef.
  */

#define IS_PWM_ALL_PERIPH(PERIPH) (((PERIPH) == NT_PWM0) || \
                                   ((PERIPH) == NT_PWM1) || \
                                   ((PERIPH) == NT_PWM2) || \
                                   ((PERIPH) == NT_PWM3) || \
                                   ((PERIPH) == NT_PWM4) || \
                                   ((PERIPH) == NT_PWM5) || \
                                   ((PERIPH) == NT_PWM6) || \
                                   ((PERIPH) == NT_PWM7) || \
                                   ((PERIPH) == NT_PWM8))

 /**
   * @brief Макрос проверки аргументов типа @ref NT_PWM_TypeDef, в которых доустпен режим высокого разрешения.
   */

 #define IS_PWM_HR_ALL_PERIPH(PERIPH) (((PERIPH) == NT_PWM0) || \
                                       ((PERIPH) == NT_PWM1) || \
                                       ((PERIPH) == NT_PWM2) || \
                                       ((PERIPH) == NT_PWM3) || \
                                       ((PERIPH) == NT_PWM4) || \
                                       ((PERIPH) == NT_PWM5))

/**
  * @}
  */

/** @addtogroup Peripheral Периферия
  * @{
  */

#include "niietcm4_conf.h"

/**
  * @}
  */

/** @defgroup Misc Дополнительные модули
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
