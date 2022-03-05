/**
  ******************************************************************************
  * @file    niietcm4_pwm.h
  *
  * @brief   Файл содержит все прототипы функций для блоков ШИМ
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    23.08.2016
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
  * <h2><center>&copy; 2016 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_PWM_H
#define __NIIETCM4_PWM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup PWM
  * @{
  */

/** @defgroup PWM_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор режима остановки таймера при отладке.
  */

typedef enum
{
    PWM_CTR_Halt_StopOnTBCLK,   /*!< Остановка таймера при отладке со следующего такта TBCLK. */
    PWM_CTR_Halt_StopOnPeriod,  /*!< Остановка таймера при отладке в конце периода. */
}PWM_CTR_Halt_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_CTR_Halt_TypeDef.
  */

#define IS_PWM_CTR_HALT(CTR_HALT) (((CTR_HALT) == PWM_CTR_Halt_StopOnTBCLK) || \
                                   ((CTR_HALT) == PWM_CTR_Halt_StopOnPeriod))

/**
  * @brief Выбор схемы синхронизации модулей ШИМ.
  */

typedef enum
{
    PWM_Sync_Serial,    /*!< Последовательная синхронизация всех блоков: PWM0->PWM1->PWM2->...->PWM8 */
    PWM_Sync_Group1,    /*!< Разбиение на группы синхронизации: PWM0->PWM1->PWM2, PWM0->PWM3->PWM4->PWM5->PWM6->PWM7->PWM8 */
    PWM_Sync_Group2,    /*!< Разбиение на группы синхронизации: PWM0->PWM1->PWM2->PWM3->PWM4->PWM5, PWM0->PWM6->PWM7->PWM8 */
    PWM_Sync_Group3     /*!< Разбиение на группы синхронизации: PWM0->PWM1->PWM2, PWM0->PWM3->PWM4->PWM5, PWM0->PWM6->PWM7->PWM8 */
}PWM_Sync_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_Sync_TypeDef.
  */

#define IS_PWM_SYNC(SYNC)   (((SYNC) == PWM_Sync_Serial) || \
                             ((SYNC) == PWM_Sync_Group1) || \
                             ((SYNC) == PWM_Sync_Group2) || \
                             ((SYNC) == PWM_Sync_Group3))

/**
  * @brief Каналы ШИМ.
  */

typedef enum
{
    PWM_Channel_A,  /*!< Выбран канал A. */
    PWM_Channel_B,  /*!< Выбран канал B. */
    PWM_Channel_AB  /*!< Выбраны оба канала А и B. */
}PWM_Channel_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_Channel_TypeDef.
  */

#define IS_PWM_CHANNEL(CHANNEL)     (((CHANNEL) == PWM_Channel_A) || \
                                     ((CHANNEL) == PWM_Channel_B) || \
                                     ((CHANNEL) == PWM_Channel_AB))

/**
  * @brief  Коэффициент базового деления частоты.
  */

typedef enum
{
    PWM_ClkDiv_1   = ((uint32_t)0x0),    /*!< Без деления тактовой частоты. */
    PWM_ClkDiv_2   = ((uint32_t)0x1),    /*!< Деление тактовой частоты на 2. */
    PWM_ClkDiv_4   = ((uint32_t)0x2),    /*!< Деление тактовой частоты на 4. */
    PWM_ClkDiv_8   = ((uint32_t)0x3),    /*!< Деление тактовой частоты на 8. */
    PWM_ClkDiv_16  = ((uint32_t)0x4),    /*!< Деление тактовой частоты на 16. */
    PWM_ClkDiv_32  = ((uint32_t)0x5),    /*!< Деление тактовой частоты на 32. */
    PWM_ClkDiv_64  = ((uint32_t)0x6),    /*!< Деление тактовой частоты на 64. */
    PWM_ClkDiv_128 = ((uint32_t)0x7),    /*!< Деление тактовой частоты на 128. */
}PWM_ClkDiv_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_ClkDiv_TypeDef.
  */

#define IS_PWM_CLK_DIV(CLK_DIV)     (((CLK_DIV) == PWM_ClkDiv_1)  || \
                                     ((CLK_DIV) == PWM_ClkDiv_2)  || \
                                     ((CLK_DIV) == PWM_ClkDiv_4)  || \
                                     ((CLK_DIV) == PWM_ClkDiv_8)  || \
                                     ((CLK_DIV) == PWM_ClkDiv_16) || \
                                     ((CLK_DIV) == PWM_ClkDiv_32) || \
                                     ((CLK_DIV) == PWM_ClkDiv_64) || \
                                     ((CLK_DIV) == PWM_ClkDiv_128))

/**
  * @brief  Коэффициент дополнительного деления частоты.
  */

typedef enum
{
    PWM_ClkDivExtra_1   = ((uint32_t)0x0),    /*!< Без дополнительного деления тактовой частоты. */
    PWM_ClkDivExtra_2   = ((uint32_t)0x1),    /*!< Дополнительное деление тактовой частоты на 2. */
    PWM_ClkDivExtra_4   = ((uint32_t)0x2),    /*!< Дополнительное деление тактовой частоты на 4. */
    PWM_ClkDivExtra_6   = ((uint32_t)0x3),    /*!< Дополнительное деление тактовой частоты на 6. */
    PWM_ClkDivExtra_8   = ((uint32_t)0x4),    /*!< Дополнительное деление тактовой частоты на 8. */
    PWM_ClkDivExtra_10  = ((uint32_t)0x5),    /*!< Дополнительное деление тактовой частоты на 10. */
    PWM_ClkDivExtra_12  = ((uint32_t)0x6),    /*!< Дополнительное деление тактовой частоты на 12. */
    PWM_ClkDivExtra_14  = ((uint32_t)0x7),    /*!< Дополнительное деление тактовой частоты на 14. */
}PWM_ClkDivExtra_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_ClkDivExtra_TypeDef.
  */

#define IS_PWM_CLK_DIV_EXTRA(CLK_DIV_EXTRA)     (((CLK_DIV_EXTRA) == PWM_ClkDivExtra_1)  || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_2)  || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_4)  || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_6)  || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_8)  || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_10) || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_12) || \
                                                 ((CLK_DIV_EXTRA) == PWM_ClkDivExtra_14))

/**
  * @brief  Направление счета.
  */

typedef enum
{
    PWM_CTR_Dir_Down,      /*!< Счет вниз. */
    PWM_CTR_Dir_Up         /*!< Счет вверх. */
}PWM_CTR_Dir_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_CTR_Dir_TypeDef.
  */

#define IS_PWM_CTR_DIR(CTR_DIR)     (((CTR_DIR) == PWM_CTR_Dir_Down) || \
                                     ((CTR_DIR) == PWM_CTR_Dir_Up))

/**
  * @brief  Режим загрузки.
  */

typedef enum
{
    PWM_LoadMode_Shadow,    /*!< Режим отложенной загрузки разрешен. */
    PWM_LoadMode_Direct     /*!< Прямая запись в регистр. */
}PWM_LoadMode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_LoadMode_TypeDef.
  */

#define IS_PWM_LOAD_MODE(LOAD_MODE)     (((LOAD_MODE) == PWM_LoadMode_Shadow) || \
                                         ((LOAD_MODE) == PWM_LoadMode_Direct))

/**
  * @brief  Событие для загрузки в теневом режиме.
  */

typedef enum
{
    PWM_LoadEvent_CTREqZero,            /*!< Загрузка отложенного значения при условии, что значение таймера равно нулю. */
    PWM_LoadEvent_CTREqPeriod,          /*!< Загрузка отложенного значения при условии, что значение таймера равно периоду. */
    PWM_LoadEvent_CTREqZeroOrPeriod,    /*!< Загрузка отложенного значения при условии, что значение таймера равно нулю или периоду. */
    PWM_LoadEvent_Disable               /*!< Загрузка отложенного значения запрещена. */
}PWM_LoadEvent_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_LoadEvent_TypeDef.
  */

#define IS_PWM_LOAD_EVENT(LOAD_EVENT)   (((LOAD_EVENT) == PWM_LoadEvent_CTREqZero)         || \
                                         ((LOAD_EVENT) == PWM_LoadEvent_CTREqPeriod)       || \
                                         ((LOAD_EVENT) == PWM_LoadEvent_CTREqZeroOrPeriod) || \
                                         ((LOAD_EVENT) == PWM_LoadEvent_Disable))

/**
  * @brief  Источник для выходного сигнала синхронизации SYNCO.
  */

typedef enum
{
    PWM_CTR_SyncOut_SyncIn,         /*!< Входной сигнал SYNCI. */
    PWM_CTR_SyncOut_CTREqZero,      /*!< Значение таймера равно нулю. */
    PWM_CTR_SyncOut_CTREqCMPB,      /*!< Значение таймера равно регистру CMPB. */
    PWM_CTR_SyncOut_Disable         /*!< Выдача синхроимпульса запрещена. */
}PWM_CTR_SyncOut_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_CTR_SyncOut_TypeDef.
  */

#define IS_PWM_CTR_SYNC_OUT(CTR_SYNC_OUT)   (((CTR_SYNC_OUT) == PWM_CTR_SyncOut_SyncIn)      || \
                                             ((CTR_SYNC_OUT) == PWM_CTR_SyncOut_CTREqZero) || \
                                             ((CTR_SYNC_OUT) == PWM_CTR_SyncOut_CTREqCMPB) || \
                                             ((CTR_SYNC_OUT) == PWM_CTR_SyncOut_Disable))

/**
  * @brief Направление счета.
  */

typedef enum
{
    PWM_CTR_Mode_Up,        /*!< Счет вверх. */
    PWM_CTR_Mode_Down,      /*!< Счет вниз. */
    PWM_CTR_Mode_UpDown,    /*!< Счет вверх-вниз. */
    PWM_CTR_Mode_Disable    /*!< Счетчик остановлен. */
}PWM_CTR_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_CTR_Mode_TypeDef.
  */

#define IS_PWM_CTR_MODE(CTR_MODE)   (((CTR_MODE) == PWM_CTR_Mode_Up)     || \
                                     ((CTR_MODE) == PWM_CTR_Mode_Down)   || \
                                     ((CTR_MODE) == PWM_CTR_Mode_UpDown) || \
                                     ((CTR_MODE) == PWM_CTR_Mode_Disable))

/**
  * @brief Действие на выводе ШИМ.
  */

typedef enum
{
    PWM_ChAction_None,       /*!< Нет реакции. */
    PWM_ChAction_ToZero,     /*!< Переключение в ноль. */
    PWM_ChAction_ToOne,      /*!< Переключение в единицу. */
    PWM_ChAction_Inv         /*!< Инверсия текущего состояния. */
}PWM_ChAction_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_ChAction_TypeDef.
  */

#define IS_PWM_CH_ACTION(CH_ACTION)   (((CH_ACTION) == PWM_ChAction_None)   || \
                                       ((CH_ACTION) == PWM_ChAction_ToZero) || \
                                       ((CH_ACTION) == PWM_ChAction_ToOne)  || \
                                       ((CH_ACTION) == PWM_ChAction_Inv))

/**
  * @brief Выбор источников для формирования задержки.
  */

typedef enum
{
    PWM_DB_In_A,               /*!< Входной сигнал А задержан по обоим фронтам. */
    PWM_DB_In_AFallBRise,      /*!< Входной сигнал A задержан заднему фронту, B - по переднему.  */
    PWM_DB_In_ARiseBFall,      /*!< Входной сигнал A задержан переднему фронту, B - по заднему.  */
    PWM_DB_In_B                /*!< Входной сигнал B задержан по обоим фронтам. */
}PWM_DB_In_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_DB_In_TypeDef.
  */

#define IS_PWM_DB_IN(DB_IN)   (((DB_IN) == PWM_DB_In_A)          || \
                               ((DB_IN) == PWM_DB_In_ARiseBFall) || \
                               ((DB_IN) == PWM_DB_In_AFallBRise) || \
                               ((DB_IN) == PWM_DB_In_B))

/**
  * @brief Выбор полярности задержанных сигналов.
  */

typedef enum
{
    PWM_DB_Pol_ActHigh,        /*!< Нет инверсии. */
    PWM_DB_Pol_ActLowCompl,    /*!< Инвертируется сигнал, задержанный по переднему фронту.  */
    PWM_DB_Pol_ActHighCompl,   /*!< Инвертируется сигнал, задержанный по заднему фронту.  */
    PWM_DB_Pol_ActLow          /*!< Инвертируются оба сигнала. */
}PWM_DB_Pol_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_DB_Pol_TypeDef.
  */

#define IS_PWM_DB_POL(DB_POL)   (((DB_POL) == PWM_DB_Pol_ActHigh)      || \
                                 ((DB_POL) == PWM_DB_Pol_ActLowCompl)  || \
                                 ((DB_POL) == PWM_DB_Pol_ActHighCompl) || \
                                 ((DB_POL) == PWM_DB_Pol_ActLow))

/**
  * @brief Выбор выходных сигналов блока задержки.
  */

typedef enum
{
    PWM_DB_Out_BypassAB,   /*!< Нет задержки. Входные сигналы A и B подключены напрямую к выходу модуля задержки. */
    PWM_DB_Out_BypassA,    /*!< Входной сигнал A подключен напрямую к выходу A модуля задержки. Задержанный по заднему фронту сигнал подключен к выходу B.  */
    PWM_DB_Out_BypassB,    /*!< Входной сигнал B подключен напрямую к выходу B модуля задержки. Задержанный по переднему фронту сигнал подключен к выходу A.  */
    PWM_DB_Out_DelayAB     /*!< Задержанный по переднему фронту сигнал подключен к выходу A, по заднему - к выходу B. */
}PWM_DB_Out_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_DB_Out_TypeDef.
  */

#define IS_PWM_DB_OUT(DB_OUT)   (((DB_OUT) == PWM_DB_Out_BypassAB) || \
                                 ((DB_OUT) == PWM_DB_Out_BypassA)  || \
                                 ((DB_OUT) == PWM_DB_Out_BypassB)  || \
                                 ((DB_OUT) == PWM_DB_Out_DelayAB))

/**
  * @brief  Возможные события для генерации внешних сигналов.
  */

typedef enum
{
    PWM_Event_None           = ((uint32_t)0x0),   /*!< Событие не выбрано. */
    PWM_Event_CTREqZero      = ((uint32_t)0x1),   /*!< Значение таймера равно нулю. */
    PWM_Event_CTREqPeriod    = ((uint32_t)0x2),   /*!< Значение таймера равно периоду. */
    PWM_Event_CTREqCMPA_Up   = ((uint32_t)0x4),   /*!< Значение таймера равно регистру CMPA при счете вверх. */
    PWM_Event_CTREqCMPA_Down = ((uint32_t)0x5),   /*!< Значение таймера равно регистру CMPA при счете вниз. */
    PWM_Event_CTREqCMPB_Up   = ((uint32_t)0x6),   /*!< Значение таймера равно регистру CMPB при счете вверх. */
    PWM_Event_CTREqCMPB_Down = ((uint32_t)0x7)    /*!< Значение таймера равно регистру CMPB при счете вниз. */
}PWM_Event_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_Event_TypeDef.
  */

#define IS_PWM_EVENT(EVENT)     (((EVENT) == PWM_Event_None)           || \
                                 ((EVENT) == PWM_Event_CTREqZero)      || \
                                 ((EVENT) == PWM_Event_CTREqPeriod)    || \
                                 ((EVENT) == PWM_Event_CTREqCMPA_Up)   || \
                                 ((EVENT) == PWM_Event_CTREqCMPA_Down) || \
                                 ((EVENT) == PWM_Event_CTREqCMPB_Up)   || \
                                 ((EVENT) == PWM_Event_CTREqCMPB_Down))

/**
  * @brief Выбор поведения вывода в случае наступления сигнала аварии.
  */

typedef enum
{
    PWM_TZ_Action_ToThird,  /*!< Переключение вывода в третье состояние. */
    PWM_TZ_Action_ToOne,    /*!< Переключение в единицу.*/
    PWM_TZ_Action_ToZero,   /*!< Переключение в ноль.  */
    PWM_TZ_Action_None      /*!< Нет действий. */
}PWM_TZ_Action_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_TZ_Action_TypeDef.
  */

#define IS_PWM_TZ_ACTION(TZ_ACTION)     (((TZ_ACTION) == PWM_TZ_Action_ToThird) || \
                                         ((TZ_ACTION) == PWM_TZ_Action_ToOne)   || \
                                         ((TZ_ACTION) == PWM_TZ_Action_ToZero)  || \
                                         ((TZ_ACTION) == PWM_TZ_Action_None))

/**
  * @brief  Выбор канала для генерации события запуска.
  */

typedef enum
{
    PWM_ET_Channel_A,    /*!< Канал A. */
    PWM_ET_Channel_B     /*!< Канал B. */
}PWM_ET_Channel_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_ET_Channel_TypeDef.
  */

#define IS_PWM_ET_CHANNEL(ET_CHANNEL)   (((ET_CHANNEL) == PWM_ET_Channel_A) || \
                                         ((ET_CHANNEL) == PWM_ET_Channel_B))

/**
  * @brief  Выбор события для отложенной загрузки значения сравнения CMP в режиме высокого разрешения.
  */

typedef enum
{
    PWM_HR_CMPLoad_CTREqZero,     /*!< Загрузка отложенного значения при условии, что значение таймера равно нулю. */
    PWM_HR_CMPLoad_CTREqPeriod    /*!< Загрузка отложенного значения при условии, что значение таймера равно периоду. */
}PWM_HR_CMPLoad_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_HR_CMPLoad_TypeDef.
  */

#define IS_PWM_HR_CMP_LOAD(HR_CMP_LOAD)     (((HR_CMP_LOAD) == PWM_HR_CMPLoad_CTREqZero) || \
                                             ((HR_CMP_LOAD) == PWM_HR_CMPLoad_CTREqPeriod))

/**
  * @brief  Выбор режима для задания задержки высокого разрешения.
  */

typedef enum
{
    PWM_HR_Mode_CMP,     /*!< Задержка высокого разрешения задается через регистр сравнения. */
    PWM_HR_Mode_Phase    /*!< Задержка высокого разрешения задается через регистр фазы. */
}PWM_HR_Mode_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_HR_Mode_TypeDef.
  */

#define IS_PWM_HR_MODE(HR_MODE)     (((HR_MODE) == PWM_HR_Mode_CMP) || \
                                     ((HR_MODE) == PWM_HR_Mode_Phase))

/**
  * @brief Выбор фронта ШИМ, который сдвигается линией задержки.
  */

typedef enum
{
    PWM_HR_Edge_None,       /*!< Ни один из фронтов не задерживается. */
    PWM_HR_Edge_Rise,       /*!< Задержка переднего фронта.*/
    PWM_HR_Edge_Fall,       /*!< Задержка заднего фронта.  */
    PWM_HR_Edge_RiseFall    /*!< Оба фронта будут задержаны. */
}PWM_HR_Edge_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_HR_Edge_TypeDef.
  */

#define IS_PWM_HR_EDGE(HR_EDGE)     (((HR_EDGE) == PWM_HR_Edge_None) || \
                                     ((HR_EDGE) == PWM_HR_Edge_Rise) || \
                                     ((HR_EDGE) == PWM_HR_Edge_Fall) || \
                                     ((HR_EDGE) == PWM_HR_Edge_RiseFall))

/**
  * @brief Выбор поведения вывода в случае наступления события удержания.
  */

typedef enum
{
    PWM_HD_Action_ToOne  = ((uint32_t)0x1),   /*!< Переключение в единицу.*/
    PWM_HD_Action_ToZero = ((uint32_t)0x2),   /*!< Переключение в ноль.  */
    PWM_HD_Action_None   = ((uint32_t)0x3)    /*!< Нет действий. */
}PWM_HD_Action_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref PWM_HD_Action_TypeDef.
  */

#define IS_PWM_HD_ACTION(HD_ACTION)     (((HD_ACTION) == PWM_HD_Action_ToOne)   || \
                                         ((HD_ACTION) == PWM_HD_Action_ToZero)  || \
                                         ((HD_ACTION) == PWM_HD_Action_None))

/**
  * @brief  Структура инициализации таймера блока ШИМ.
  */

typedef struct
{
    PWM_CTR_Halt_TypeDef PWM_CTR_Halt;                  /*!< Выбор режима остановки таймера при отладке.
                                                            Параметр может принимать любое значение из @ref PWM_CTR_Halt_TypeDef. */
    PWM_ClkDiv_TypeDef PWM_ClkDiv;                      /*!< Коэффициент базового деления частоты.
                                                            Параметр может принимать любое значение из @ref PWM_ClkDiv_TypeDef. */
    PWM_ClkDivExtra_TypeDef PWM_ClkDivExtra;            /*!< Коэффициент дополнительного деления частоты.
                                                            Результирующий коэффциент = PWM_ClkDiv * PWM_ClkDivExtra
                                                            Параметр может принимать любое значение из @ref PWM_ClkDivExtra_TypeDef. */
    PWM_CTR_SyncOut_TypeDef PWM_CTR_SyncOut;            /*!< Источник для выходного сигнала синхронизации SYNCO.
                                                            Параметр может принимать любое значение из @ref PWM_CTR_SyncOut_TypeDef. */
    FunctionalState PWM_PhaseEn;                        /*!< Разрешает загрузку счетчика значением регистра фазы при получении события синхронизации.
                                                            Параметр может принимать любое значение из @ref FunctionalState. */
    PWM_CTR_Dir_TypeDef PWM_CTR_Dir_Phase;              /*!< Задание направления счета после синхронизации фазы.
                                                            Параметр может принимать любое значение из @ref PWM_CTR_Dir_TypeDef. */
    uint32_t PWM_Phase;                                 /*!< Значение фазы ШИМ при получении события синхронизации.
                                                            Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    PWM_CTR_Mode_TypeDef PWM_CTR_Mode;                  /*!< Задание направления счета.
                                                            Параметр может принимать любое значение из @ref PWM_CountMode_TypeDef. */
    PWM_LoadMode_TypeDef PWM_LoadMode_Period;           /*!< Режим загрузки в регистр периода.
                                                            Параметр может принимать любое значение из @ref PWM_LoadMode_TypeDef. */
    uint32_t PWM_Period;                                /*!< Значение периода таймера ШИМ.
                                                            Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqZero_A;      /*!< Действие в канале А, при наступлении события равенства счетчика таймера нулю.
                                                            Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqZero_B;      /*!< Действие в канале B, при наступлении события равенства счетчика таймера нулю.
                                                            Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqPeriod_A;    /*!< Действие в канале А, при наступлении события равенства счетчика значению периода.
                                                            Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqPeriod_B;    /*!< Действие в канале B, при наступлении события равенства счетчика значению периода.
                                                            Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
}PWM_CTR_Init_TypeDef;

/**
  * @brief Проверка значения фазы на попадание в допустимый диапазон.
  */

#define IS_PWM_PHASE_VAL(PHASE_VAL) ((PHASE_VAL) < ((uint32_t)0x10000))

/**
  * @brief Проверка значения периода на попадание в допустимый диапазон.
  */

#define IS_PWM_PERIOD_VAL(PERIOD_VAL) ((PERIOD_VAL) < ((uint32_t)0x10000))

/**
  * @brief Проверка значения таймера на попадание в допустимый диапазон.
  */

#define IS_PWM_COUNTER_VAL(COUNTER_VAL) ((COUNTER_VAL) < ((uint32_t)0x10000))

 /**
   * @brief  Структура инициализации компараторов блока ШИМ.
   */

 typedef struct
 {
    PWM_LoadMode_TypeDef PWM_LoadMode_CMPA;                 /*!< Режим загрузки в регистр сравнения CMPA.
                                                                Параметр может принимать любое значение из @ref PWM_LoadMode_TypeDef. */
    PWM_LoadEvent_TypeDef PWM_LoadEvent_CMPA;               /*!< Событие для теневой загрузки в регистр сравнения CMPA.
                                                                Параметр может принимать любое значение из @ref PWM_LoadEvent_TypeDef. */
    uint32_t PWM_CMPA;                                      /*!< Значение порога срабатывания канала А, которое сравнивается со значением счетчика таймера.
                                                                Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    PWM_LoadMode_TypeDef PWM_LoadMode_CMPB;                 /*!< Режим загрузки в регистр сравнения CMPB.
                                                                Параметр может принимать любое значение из @ref PWM_LoadMode_TypeDef. */
    PWM_LoadEvent_TypeDef PWM_LoadEvent_CMPB;               /*!< Событие для теневой загрузки в регистр сравнения CMPB.
                                                                Параметр может принимать любое значение из @ref PWM_LoadEvent_TypeDef. */
    uint32_t PWM_CMPB;                                      /*!< Значение порога срабатывания канала B, которое сравнивается со значением счетчика таймера.
                                                                Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPA_Up_A;       /*!< Действие в канале А, при наступлении события равенства счетчика таймера значению сравнения A при счете вверх.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPA_Down_A;     /*!< Действие в канале A, при наступлении события равенства счетчика таймера значению сравнения A при счете вниз.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPB_Up_A;       /*!< Действие в канале А, при наступлении события равенства счетчика таймера значению сравнения B при счете вверх.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPB_Down_A;     /*!< Действие в канале A, при наступлении события равенства счетчика таймера значению сравнения B при счете вниз.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPA_Up_B;       /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения A при счете вверх.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPA_Down_B;     /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения A при счете вниз.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPB_Up_B;       /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения B при счете вверх.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
    PWM_ChAction_TypeDef PWM_ChAction_CTREqCMPB_Down_B;     /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения B при счете вниз.
                                                                Параметр может принимать любое значение из @ref PWM_ChAction_TypeDef. */
 }PWM_CMP_Init_TypeDef;

/**
  * @brief Проверка значения сравнения на попадание в допустимый диапазон.
  */

#define IS_PWM_CMP_VAL(CMP_VAL) ((CMP_VAL) < ((uint32_t)0x10000))

/**
  * @brief  Структура инициализации режима высокого разрешения блока ШИМ.
  */

typedef struct
{
    PWM_HR_CMPLoad_TypeDef PWM_HR_CMPLoad;  /*!< Режим отложенной загрузки в регистр сравнения CMPA.
                                                Параметр может принимать любое значение из @ref PWM_HR_CMPLoad_TypeDef. */
    PWM_HR_Mode_TypeDef PWM_HR_Mode;        /*!< Выбор режима для задания задержки высокого разрешения.
                                                Параметр может принимать любое значение из @ref PWM_HR_Mode_TypeDef. */
    PWM_HR_Edge_TypeDef PWM_HR_Edge;        /*!< Выбор фронта ШИМ, который сдвигается линией задержки.
                                                Параметр может принимать любое значение из @ref PWM_HR_Edge_TypeDef. */
    uint32_t PWM_HR_CMP;                    /*!< Значение расширения регистра сравнения канала А в режиме высокого разрешения.
                                                Параметр может принимать любое значение из диапазона: 0x00-0xFF. */
    uint32_t PWM_HR_Phase;                  /*!< Значение расширения регистра фазы в режиме высокого разрешения.
                                                Параметр может принимать любое значение из диапазона: 0x00-0xFF. */
}PWM_HR_Init_TypeDef;

/**
  * @brief Проверка значения сравнения на попадание в допустимый диапазон для ШИМ высокого разрешения.
  */

#define IS_PWM_HR_CMP_VAL(CMP_VAL) ((CMP_VAL) < ((uint32_t)0x100))

/**
  * @brief Проверка значения сравнения на попадание в допустимый диапазон для ШИМ высокого разрешения.
  */

#define IS_PWM_HR_CMP_VAL(CMP_VAL) ((CMP_VAL) < ((uint32_t)0x100))

/**
  * @brief Проверка значения фазы на попадание в допустимый диапазон для ШИМ высокого разрешения.
  */

#define IS_PWM_HR_PHASE_VAL(PHASE_VAL) ((PHASE_VAL) < ((uint32_t)0x100))

 /**
   * @brief  Структура инициализации задержки сигналов ШИМ ("мертвое время").
   */

 typedef struct
 {
    PWM_DB_In_TypeDef PWM_DB_In;       /*!< Выбор источников для формирования задержки.
                                            Параметр может принимать любое значение из @ref PWM_DB_In_TypeDef. */
    PWM_DB_Pol_TypeDef PWM_DB_Pol;     /*!< Выбор полярности задержанных сигналов.
                                            Параметр может принимать любое значение из @ref PWM_DB_Pol_TypeDef. */
    PWM_DB_Out_TypeDef PWM_DB_Out;     /*!< Выбор выходных сигналов блока задержки.
                                            Параметр может принимать любое значение из @ref PWM_DB_Out_TypeDef. */
    uint32_t PWM_DB_RiseDelay;         /*!< Величина задержки переднего фронта.
                                            Параметр может принимать любое значение из диапазона: 0x000-0x3FF. */
    uint32_t PWM_DB_FallDelay;         /*!< Величина задержки заднего фронта.
                                            Параметр может принимать любое значение из диапазона: 0x000-0x3FF. */
 }PWM_DB_Init_TypeDef;

/**
  * @brief Проверка значения величины задержки фронта в блоке "мертвого времени".
  */

#define IS_PWM_DB_DELAY_VAL(DB_DELAY_VAL) ((DB_DELAY_VAL) < ((uint32_t)0x400))

/**
  * @brief  Структура инициализации блока "триггера событий" для запуска измерений АЦП.
  */

typedef struct
{
    PWM_Event_TypeDef PWM_ET_Event_A;   /*!< Канал А: выбор события для формирования строба запуска.
                                            Параметр может принимать любое значение из @ref PWM_Event_TypeDef. */
    uint32_t PWM_ET_Period_A;           /*!< Канал А: выбор количества событий для возникновения строба.
                                            Параметр принимает любое значение из диапазона 0-3,
                                            где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
    PWM_Event_TypeDef PWM_ET_Event_B;   /*!< Канал B: выбор события для формирования строба запуска.
                                            Параметр может принимать любое значение из @ref PWM_Event_TypeDef. */
    uint32_t PWM_ET_Period_B;           /*!< Канал B: выбор количества событий для возникновения строба.
                                            Параметр принимает любое значение из диапазона 0-3,
                                            где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
}PWM_ET_Init_TypeDef;

/**
  * @brief Проверка значения количества событий для генерации строба запуска обработчиком событий.
  */

#define IS_PWM_ET_PERIOD(ET_PERIOD) ((ET_PERIOD) < ((uint32_t)0x4))

/**
 * @}
 */

/** @defgroup PWM_Exported_Constants Константы
  * @{
  */

/** @defgroup PWM_Exported_Constants_CTR_Status Статусы счетчика
  * @{
  */

#define PWM_CTR_Status_CountDir       ((uint32_t)0x1)    /*!< Направление счета. Этот флаг может быть приведен к типу @ref PWM_CountDir_TypeDef */
#define PWM_CTR_Status_SyncIn         ((uint32_t)0x2)    /*!< Произошло событие синхронизации. */
#define PWM_CTR_Status_CountMax       ((uint32_t)0x4)    /*!< Таймер достиг максимального значения 0xFFFF. */
#define PWM_CTR_Status_All            ((uint32_t)0x7)    /*!< Все статусы выбраны. */

/**
  * @brief Макрос проверки статусов таймера на попадание в допустимый диапазон.
  */

#define IS_PWM_CTR_STATUS(CTR_STATUS) (((CTR_STATUS) & ~PWM_CTR_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_CMP_Status Статусы компаратора
  * @{
  */

#define PWM_CMP_Status_ShadowLoadedA     ((uint32_t)0x100)    /*!< Произошла теневая загрузка в CMPA. */
#define PWM_CMP_Status_ShadowLoadedB     ((uint32_t)0x200)    /*!< Произошла теневая загрузка в CMPB. */
#define PWM_CMP_Status_All               ((uint32_t)0x300)    /*!< Все статусы выбраны. */

/**
  * @brief Макрос проверки статусов компаратора на попадание в допустимый диапазон.
  */

#define IS_PWM_CMP_STATUS(CMP_STATUS) (((CMP_STATUS) & ~PWM_CMP_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_Presc Управление предделителями таймеров блоков ШИМ
  * @{
  */

#define PWM_Presc_0     ((uint32_t)0x1)    /*!< Предделитель блока ШИМ0. */
#define PWM_Presc_1     ((uint32_t)0x2)    /*!< Предделитель блока ШИМ1. */
#define PWM_Presc_2     ((uint32_t)0x4)    /*!< Предделитель блока ШИМ2. */
#define PWM_Presc_3     ((uint32_t)0x8)    /*!< Предделитель блока ШИМ3. */
#define PWM_Presc_4     ((uint32_t)0x10)   /*!< Предделитель блока ШИМ4. */
#define PWM_Presc_5     ((uint32_t)0x20)   /*!< Предделитель блока ШИМ5. */
#define PWM_Presc_6     ((uint32_t)0x40)   /*!< Предделитель блока ШИМ6. */
#define PWM_Presc_7     ((uint32_t)0x80)   /*!< Предделитель блока ШИМ7. */
#define PWM_Presc_8     ((uint32_t)0x100)  /*!< Предделитель блока ШИМ8. */
#define PWM_Presc_All   ((uint32_t)0x1FF)  /*!< Все блоки выбраны. */

/**
  * @brief Макрос проверки выбора предделителей блоков ШИМ на попадание в допустимый диапазон.
  */

#define IS_PWM_PRESC(PRESC) (((PRESC) & ~PWM_Presc_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_TZ_ITSource Источники прерываний блока сигналов аварий ШИМ
  * @{
  */

#define PWM_TZ_ITSource_Cycle   ((uint32_t)0x00000002)      /*!< Циклический обработчик сигнала аварии */
#define PWM_TZ_ITSource_OneShot ((uint32_t)0x00000004)      /*!< Однократный обработчик сигнала аварии */
#define PWM_TZ_ITSource_All     ((uint32_t)0x00000006)      /*!< Все источники выбраны. */

/**
  * @brief Макрос проверки прерываний блока сигналов аварий ШИМ на попадание в допустимый диапазон.
  */

#define IS_PWM_TZ_IT_SOURCE(IT_SOURCE)  (((IT_SOURCE) & ~PWM_TZ_ITSource_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_TZ_ITStatus Флаги прерываний блока сигналов аварий ШИМ
  * @{
  */

#define PWM_TZ_ITStatus_Int     ((uint32_t)0x00000001)      /*!< Флаг прерывания NVIC */
#define PWM_TZ_ITStatus_Cycle   ((uint32_t)0x00000002)      /*!< Циклический обработчик сигнала аварии */
#define PWM_TZ_ITStatus_OneShot ((uint32_t)0x00000004)      /*!< Однократный обработчик сигнала аварии */
#define PWM_TZ_ITStatus_All     ((uint32_t)0x00000007)      /*!< Все флаги выбраны. */

/**
  * @brief Макрос проверки прерываний блока сигналов аварий ШИМ на попадание в допустимый диапазон.
  */

#define IS_PWM_TZ_IT_STATUS(IT_STATUS)  (((IT_STATUS) & ~PWM_TZ_ITStatus_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_TZ_Channel Выбор номера сигнала аварии
  * @{
  */

#define PWM_TZ_Channel_0    ((uint32_t)0x00000001)      /*!< Сигнал аварии 0 */
#define PWM_TZ_Channel_1    ((uint32_t)0x00000002)      /*!< Сигнал аварии 1 */
#define PWM_TZ_Channel_2    ((uint32_t)0x00000004)      /*!< Сигнал аварии 2 */
#define PWM_TZ_Channel_3    ((uint32_t)0x00000008)      /*!< Сигнал аварии 3 */
#define PWM_TZ_Channel_4    ((uint32_t)0x00000010)      /*!< Сигнал аварии 4 */
#define PWM_TZ_Channel_5    ((uint32_t)0x00000020)      /*!< Сигнал аварии 5 */
#define PWM_TZ_Channel_All  ((uint32_t)0x0000003F)      /*!< Все сигналы выбраны. */

/**
  * @brief Макрос проверки номера сигнала аварии на попадание в допустимый диапазон.
  */

#define IS_PWM_TZ_CHANNEL(TZ_CHANNEL)  (((TZ_CHANNEL) & ~PWM_TZ_Channel_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_ET_Status Флаги генерации событий запуска АЦП обработчиком событий
  * @{
  */

#define PWM_ET_Status_A     ((uint32_t)0x00000004)      /*!< Флаг генерации события от канала А */
#define PWM_ET_Status_B     ((uint32_t)0x00000008)      /*!< Флаг генерации события от канала B */
#define PWM_ET_Status_All   ((uint32_t)0x0000000C)      /*!< Все флаги выбраны. */

/**
  * @brief Макрос проверки событий запуска АЦП обработчиком событий на попадание в допустимый диапазон.
  */

#define IS_PWM_ET_STATUS(ET_STATUS)  (((ET_STATUS) & ~PWM_ET_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_HD_Channel Выбор источника события удержания
  * @{
  */

#define PWM_HD_Channel_DC0   ((uint32_t)0x00000001)      /*!< Сигнал от цифрового компаратора 0 */
#define PWM_HD_Channel_DC1   ((uint32_t)0x00000002)      /*!< Сигнал от цифрового компаратора 1 */
#define PWM_HD_Channel_DC2   ((uint32_t)0x00000004)      /*!< Сигнал от цифрового компаратора 2 */
#define PWM_HD_Channel_DC3   ((uint32_t)0x00000008)      /*!< Сигнал от цифрового компаратора 3 */
#define PWM_HD_Channel_DC4   ((uint32_t)0x00000010)      /*!< Сигнал от цифрового компаратора 4 */
#define PWM_HD_Channel_DC5   ((uint32_t)0x00000020)      /*!< Сигнал от цифрового компаратора 5 */
#define PWM_HD_Channel_DC6   ((uint32_t)0x00000040)      /*!< Сигнал от цифрового компаратора 6 */
#define PWM_HD_Channel_DC7   ((uint32_t)0x00000080)      /*!< Сигнал от цифрового компаратора 7 */
#define PWM_HD_Channel_DC8   ((uint32_t)0x00000100)      /*!< Сигнал от цифрового компаратора 8 */
#define PWM_HD_Channel_DC9   ((uint32_t)0x00000200)      /*!< Сигнал от цифрового компаратора 9 */
#define PWM_HD_Channel_DC10  ((uint32_t)0x00000400)      /*!< Сигнал от цифрового компаратора 10 */
#define PWM_HD_Channel_DC11  ((uint32_t)0x00000800)      /*!< Сигнал от цифрового компаратора 11 */
#define PWM_HD_Channel_DC12  ((uint32_t)0x00001000)      /*!< Сигнал от цифрового компаратора 12 */
#define PWM_HD_Channel_DC13  ((uint32_t)0x00002000)      /*!< Сигнал от цифрового компаратора 13 */
#define PWM_HD_Channel_DC14  ((uint32_t)0x00004000)      /*!< Сигнал от цифрового компаратора 14 */
#define PWM_HD_Channel_DC15  ((uint32_t)0x00008000)      /*!< Сигнал от цифрового компаратора 15 */
#define PWM_HD_Channel_DC16  ((uint32_t)0x00010000)      /*!< Сигнал от цифрового компаратора 16 */
#define PWM_HD_Channel_DC17  ((uint32_t)0x00020000)      /*!< Сигнал от цифрового компаратора 17 */
#define PWM_HD_Channel_DC18  ((uint32_t)0x00040000)      /*!< Сигнал от цифрового компаратора 18 */
#define PWM_HD_Channel_DC19  ((uint32_t)0x00080000)      /*!< Сигнал от цифрового компаратора 19 */
#define PWM_HD_Channel_DC20  ((uint32_t)0x00100000)      /*!< Сигнал от цифрового компаратора 20 */
#define PWM_HD_Channel_DC21  ((uint32_t)0x00200000)      /*!< Сигнал от цифрового компаратора 21 */
#define PWM_HD_Channel_DC22  ((uint32_t)0x00400000)      /*!< Сигнал от цифрового компаратора 22 */
#define PWM_HD_Channel_DC23  ((uint32_t)0x00800000)      /*!< Сигнал от цифрового компаратора 23 */
#define PWM_HD_Channel_AC0   ((uint32_t)0x01000000)      /*!< Сигнал от аналогового компаратора 0 */
#define PWM_HD_Channel_AC1   ((uint32_t)0x02000000)      /*!< Сигнал от аналогового компаратора 1 */
#define PWM_HD_Channel_AC2   ((uint32_t)0x04000000)      /*!< Сигнал от аналогового компаратора 2 */
#define PWM_HD_Channel_All   ((uint32_t)0x07FFFFFF)      /*!< Все источники выбраны. */

/**
  * @brief Макрос проверки источника события удержания на попадание в допустимый диапазон.
  */

#define IS_PWM_HD_CHANNEL(HD_CHANNEL)  (((HD_CHANNEL) & ~PWM_HD_Channel_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_HD_ITSource Источники прерываний блока cобытий удержания
  * @{
  */

#define PWM_HD_ITSource_Cycle   ((uint32_t)0x00000002)      /*!< Циклический обработчик cобытия удержания */
#define PWM_HD_ITSource_OneShot ((uint32_t)0x00000004)      /*!< Однократный обработчик cобытия удержания */
#define PWM_HD_ITSource_All     ((uint32_t)0x00000006)      /*!< Все источники выбраны. */

/**
  * @brief Макрос проверки источников прерываний блока cобытий удержания на попадание в допустимый диапазон.
  */

#define IS_PWM_HD_IT_SOURCE(IT_SOURCE)  (((IT_SOURCE) & ~PWM_HD_ITSource_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Exported_Constants_HD_ITStatus Флаги прерываний блока cобытий удержания
  * @{
  */

#define PWM_HD_ITStatus_Int     ((uint32_t)0x00000001)      /*!< Флаг прерывания NVIC */
#define PWM_HD_ITStatus_Cycle   ((uint32_t)0x00000002)      /*!< Циклический обработчик cобытия удержания */
#define PWM_HD_ITStatus_OneShot ((uint32_t)0x00000004)      /*!< Однократный обработчик cобытия удержания */
#define PWM_HD_ITStatus_All     ((uint32_t)0x00000007)      /*!< Все флаги выбраны. */

/**
  * @brief Макрос проверки статусов прерываний блока cобытий удержания на попадание в допустимый диапазон.
  */

#define IS_PWM_HD_IT_STATUS(IT_STATUS)  (((IT_STATUS) & ~PWM_HD_ITStatus_All) == 0)

/**
  * @}
  */

/**
  * @brief Макрос проверки количества событий для возникновения прерывания на попадание в допустимый диапазон.
  */

#define IS_PWM_IT_PERIOD(IT_PERIOD)     ((IT_PERIOD) < ((uint32_t)0x4))

/**
  * @brief Макрос проверки ширины фильтрации коротких импульсов на попадание в допустимый диапазон.
  */

#define IS_PWM_FILTER(FILTER)     ((FILTER) < ((uint32_t)0x100))

/**
  * @brief Макрос проверки значения скважности второго и последующего импульсов в модуляторе на попадание в допустимый диапазон.
  */

#define IS_PWM_PC_DUTY(PC_DUTY)   ((PC_DUTY) < ((uint32_t)0x7))

/**
  * @brief Макрос проверки значения делителя частоты второго и последующего импульсов в модуляторе на попадание в допустимый диапазон.
  */

#define IS_PWM_PC_FREQ_DIV(PC_FREQ_DIV)   ((PC_FREQ_DIV) < ((uint32_t)0x8))

/**
  * @brief Макрос проверки значения ширины первого импульса в модуляторе на попадание в допустимый диапазон.
  */

#define IS_PWM_PC_FIRST_WIDTH(PC_FIRST_WIDTH)   ((PC_FIRST_WIDTH) < ((uint32_t)0x10))

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions Функции
  * @{
  */

void PWM_DeInit(NT_PWM_TypeDef* PWMx);
void PWM_PrescCmd(uint32_t Presc, FunctionalState State);
void PWM_SyncConfig(PWM_Sync_TypeDef SyncSelect);
void PWM_ChForceContCmd(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel, PWM_ChAction_TypeDef ChActionA, PWM_ChAction_TypeDef ChActionB);
void PWM_ChForceConfig(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel, PWM_ChAction_TypeDef ChActionA, PWM_ChAction_TypeDef ChActionB);
void PWM_ChForceCmd(NT_PWM_TypeDef* PWMx, PWM_Channel_TypeDef Channel);
void PWM_FilterConfig(NT_PWM_TypeDef* PWMx, uint32_t FilterVal);

/** @defgroup PWM_Exported_Functions_CTR Счетчик
  * @{
  */

void PWM_CTR_Init(NT_PWM_TypeDef* PWMx, PWM_CTR_Init_TypeDef* PWM_CTR_InitStruct);
void PWM_CTR_StructInit(PWM_CTR_Init_TypeDef* PWM_CTR_InitStruct);
FlagStatus PWM_CTR_Status(NT_PWM_TypeDef* PWMx, uint32_t CTR_Status);
void PWM_CTR_StatusClear(NT_PWM_TypeDef* PWMx, uint32_t CTR_Status);
void PWM_CTR_SetValue(NT_PWM_TypeDef* PWMx, uint32_t CTR_Val);
void PWM_CTR_SetPeriod(NT_PWM_TypeDef* PWMx, uint32_t CTR_PeriodVal);
void PWM_CTR_SetPhase(NT_PWM_TypeDef* PWMx, uint32_t CTR_PhaseVal);
uint32_t PWM_CTR_GetValue(NT_PWM_TypeDef* PWMx);
uint32_t PWM_CTR_GetPeriod(NT_PWM_TypeDef* PWMx);
uint32_t PWM_CTR_GetPhase(NT_PWM_TypeDef* PWMx);
void PWM_CTR_SWSyncInCmd(NT_PWM_TypeDef* PWMx);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_CMP Компараторы
  * @{
  */

void PWM_CMP_Init(NT_PWM_TypeDef* PWMx, PWM_CMP_Init_TypeDef* PWM_CMP_InitStruct);
void PWM_CMP_StructInit(PWM_CMP_Init_TypeDef* PWM_CMP_InitStruct);
void PWM_CMP_SetA(NT_PWM_TypeDef* PWMx, uint32_t CMPAVal);
void PWM_CMP_SetB(NT_PWM_TypeDef* PWMx, uint32_t CMPBVal);
uint32_t PWM_CMP_GetA(NT_PWM_TypeDef* PWMx);
uint32_t PWM_CMP_GetB(NT_PWM_TypeDef* PWMx);
FlagStatus PWM_CMP_Status(NT_PWM_TypeDef* PWMx, uint32_t CMP_Status);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_HighResolution Режим высокого разрешения
  * @{
  */

void PWM_HR_Init(NT_PWM_TypeDef* PWMx, PWM_HR_Init_TypeDef* PWM_HR_InitStruct);
void PWM_HR_StructInit(PWM_HR_Init_TypeDef* PWM_HR_InitStruct);
void PWM_HR_SetCMP(NT_PWM_TypeDef* PWMx, uint32_t HR_CMPVal);
void PWM_HR_SetPhase(NT_PWM_TypeDef* PWMx, uint32_t HR_PhaseVal);
uint32_t PWM_HR_GetCMP(NT_PWM_TypeDef* PWMx);
uint32_t PWM_HR_GetPhase(NT_PWM_TypeDef* PWMx);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_HoldDetector Блок порогового выключателя
  * @{
  */

void PWM_HD_ActionConfig(NT_PWM_TypeDef* PWMx, PWM_HD_Action_TypeDef HD_ActionA, PWM_HD_Action_TypeDef HD_ActionB);
void PWM_HD_ChannelCmd(NT_PWM_TypeDef* PWMx, uint32_t HD_Channel, FunctionalState State);
void PWM_HD_CycleCmd(NT_PWM_TypeDef* PWMx, FunctionalState State);
void PWM_HD_OneShotCmd(NT_PWM_TypeDef* PWMx, FunctionalState State);
void PWM_HD_ITCmd(NT_PWM_TypeDef* PWMx, uint32_t HD_ITSource, FunctionalState State);
FlagStatus PWM_HD_ITStatus(NT_PWM_TypeDef* PWMx, uint32_t HD_ITStatus);
void PWM_HD_ITStatusClear(NT_PWM_TypeDef* PWMx, uint32_t HD_ITStatus);
FlagStatus PWM_HD_ITPendStatus(NT_PWM_TypeDef* PWMx);
void PWM_HD_ITPendClear(NT_PWM_TypeDef* PWMx);
void PWM_HD_ITForce(NT_PWM_TypeDef* PWMx, uint32_t HD_ITSource);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_DeadBand Блок "мертвого времени"
  * @{
  */

void PWM_DB_Init(NT_PWM_TypeDef* PWMx, PWM_DB_Init_TypeDef* PWM_DB_InitStruct);
void PWM_DB_StructInit(PWM_DB_Init_TypeDef* PWM_DB_InitStruct);
void PWM_DB_SetRiseDelay(NT_PWM_TypeDef* PWMx, uint32_t RiseDelayVal);
void PWM_DB_SetFallDelay(NT_PWM_TypeDef* PWMx, uint32_t FallDelayVal);
uint32_t PWM_DB_GetRiseDelay(NT_PWM_TypeDef* PWMx);
uint32_t PWM_DB_GetFallDelay(NT_PWM_TypeDef* PWMx);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_PWM_Chopper Блок модуляции
  * @{
  */

void PWM_PC_Config(NT_PWM_TypeDef* PWMx, uint32_t DutyVal, uint32_t FreqDivVal, uint32_t FirstWidthVal);
void PWM_PC_Cmd(NT_PWM_TypeDef* PWMx, FunctionalState State);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_TripZone Блок обработки сигналов аварии
  * @{
  */

void PWM_TZ_ActionConfig(NT_PWM_TypeDef* PWMx, PWM_TZ_Action_TypeDef TZ_ActionA, PWM_TZ_Action_TypeDef TZ_ActionB);
void PWM_TZ_CycleCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_Channel, FunctionalState State);
void PWM_TZ_OneShotCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_Channel, FunctionalState State);
void PWM_TZ_ITCmd(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITSource, FunctionalState State);
FlagStatus PWM_TZ_ITStatus(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITStatus);
void PWM_TZ_ITStatusClear(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITStatus);
FlagStatus PWM_TZ_ITPendStatus(NT_PWM_TypeDef* PWMx);
void PWM_TZ_ITPendClear(NT_PWM_TypeDef* PWMx);
void PWM_TZ_ITForce(NT_PWM_TypeDef* PWMx, uint32_t TZ_ITSource);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_EventTrigger Генерация сигналов запуска АЦП
  * @{
  */

void PWM_ET_Init(NT_PWM_TypeDef* PWMx, PWM_ET_Init_TypeDef* PWM_ET_InitStruct);
void PWM_ET_StructInit(PWM_ET_Init_TypeDef* PWM_ET_InitStruct);
void PWM_ET_Cmd(NT_PWM_TypeDef* PWMx, PWM_ET_Channel_TypeDef ET_Channel, FunctionalState State);
uint32_t PWM_ET_GetEventCount(NT_PWM_TypeDef* PWMx, PWM_ET_Channel_TypeDef ET_Channel);
FlagStatus PWM_ET_Status(NT_PWM_TypeDef* PWMx, uint32_t ET_Status);
void PWM_ET_StatusClear(NT_PWM_TypeDef* PWMx, uint32_t ET_Status);
void PWM_ET_Force(NT_PWM_TypeDef* PWMx, uint32_t ET_Status);

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_IT Прерывание ШИМ
  * @{
  */

void PWM_ITConfig(NT_PWM_TypeDef* PWMx, PWM_Event_TypeDef Event, uint32_t ITPeriod);
void PWM_ITCmd(NT_PWM_TypeDef* PWMx, FunctionalState State);
uint32_t PWM_GetITEventCount(NT_PWM_TypeDef* PWMx);
FlagStatus PWM_ITStatus(NT_PWM_TypeDef* PWMx);
void PWM_ITStatusClear(NT_PWM_TypeDef* PWMx);
FlagStatus PWM_ITPendStatus(NT_PWM_TypeDef* PWMx);
void PWM_ITPendClear(NT_PWM_TypeDef* PWMx);
void PWM_ITForce(NT_PWM_TypeDef* PWMx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_PWM_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
