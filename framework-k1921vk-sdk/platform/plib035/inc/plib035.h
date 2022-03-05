/**
  ******************************************************************************
  * @file    plib035.h
  *
  * @brief   Низкоуровневая библиотека периферии для микроконтроллера НИИЭТ К1921ВК035
  *          Этот файл содержит:
  *           - Главный заголовочный файл целевого устройства, с описанием всех регистров его периферии
  *           - Область настройки драйвера
  *           - Макросы для доступа к регистрам периферии
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

/** @addtogroup PLib035 Библиотека периферии
  * @{
  */

#ifndef __PLIB035_H
#define __PLIB035_H

#ifdef __cplusplus
extern "C" {
#endif

#include "K1921VK035.h"

/** @addtogroup Exported_macro Макросы
  * @{
  */

#if defined(__ICCARM__)
#define __RAMFUNC __ramfunc
#elif defined(__CMCARM__)
#define __RAMFUNC __ramfunc
#elif defined(__CC_ARM)
#define __RAMFUNC
#elif defined(__GNUC__)
#define __RAMFUNC __attribute__((long_call, section(".ramfunc")))
#else
#error "plib035.h: RAMFUNC - нет реализации под данный компилятор!"
#endif

#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT) (((REG) & (BIT)) ? (0x1) : (0x0))

#define CLEAR_REG(REG) ((REG) = (0x0))

#define WRITE_REG(REG, VAL) ((REG) = (VAL))

#define READ_REG(REG) ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

/** @addtogroup Exported_Types Типы
  * @{
  */

/**
  * @brief Описывает логическое состояние периферии.
  * Используется для операций включения/выключения периферийных блоков или их функций.
  */
typedef enum {
    DISABLE = 0UL,
    ENABLE = 1UL
} FunctionalState;
#define IS_FUNCTIONAL_STATE(VALUE) (((VALUE) == DISABLE) || ((VALUE) == ENABLE))

/**
  * @brief Описывает коды возврата при выполнении какой-либо операции
  */
typedef enum {
    OK = 0UL,
    ERROR = 1UL
} OperationStatus;

/**
  * @brief Описывает возможные состояния флага или бита
  */
typedef enum {
    CLEAR = 0UL,
    SET = 1UL
} FlagStatus,
    BitState;
#define IS_BIT_STATE(VALUE) (((VALUE) == CLEAR) || ((VALUE) == SET))

/**
  * @}
  */

/** @defgroup Misc Дополнительные модули
  * @{
  */

#include "plib035_assert.h"
#include "plib035_version.h"

/**
  * @}
  */

/** @addtogroup Peripheral Периферия
  * @{
  */

#include "plib035_conf.h"

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB035_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
