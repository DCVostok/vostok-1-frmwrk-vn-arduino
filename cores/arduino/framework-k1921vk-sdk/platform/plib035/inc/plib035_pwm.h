/**
  ******************************************************************************
  * @file    plib035_pwm.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          PWM, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_PWM_H
#define __PLIB035_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup PWM
  * @brief Драйвер для работы с PWM
  * @{
  */

/** @defgroup PWM_Exported_Defines Константы
  * @{
  */

/** @defgroup PWM_TB_Status_Define Статусы счетчика
  * @{
  */

#define PWM_TB_Status_CountDir PWM_TBSTS_CTRDIR_Msk /*!< Направление счета */
#define PWM_TB_Status_SyncIn PWM_TBSTS_SYNCI_Msk    /*!< Произошло событие синхронизации */
#define PWM_TB_Status_CountMax PWM_TBSTS_CTRMAX_Msk /*!< Таймер достиг максимального значения 0xFFFF */
#define PWM_TB_Status_All (PWM_TB_Status_CountDir | \
                           PWM_TB_Status_SyncIn |   \
                           PWM_TB_Status_CountMax) /*!< Все статусы выбраны */

#define IS_PWM_TB_STATUS(VALUE) (((VALUE) & ~PWM_TB_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_CMP_Status_Define Статусы компаратора
  * @{
  */

#define PWM_CMP_Status_ShadowLoadedA PWM_CMPCTL_SHDWAFULL_Msk /*!< Произошла теневая загрузка в CMPA */
#define PWM_CMP_Status_ShadowLoadedB PWM_CMPCTL_SHDWBFULL_Msk /*!< Произошла теневая загрузка в CMPB */
#define PWM_CMP_Status_All (PWM_CMP_Status_ShadowLoadedA | \
                            PWM_CMP_Status_ShadowLoadedB) /*!< Все статусы выбраны */

#define IS_PWM_CMP_STATUS(VALUE) (((VALUE) & ~PWM_CMP_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_Presc_Define Управление предделителями таймеров блоков ШИМ
  * @{
  */

#define PWM_TB_Presc_0 (0x1UL << SIU_PWMSYNC_PRESCRST_Pos) /*!< Предделитель блока ШИМ0 */
#define PWM_TB_Presc_1 (0x2UL << SIU_PWMSYNC_PRESCRST_Pos) /*!< Предделитель блока ШИМ1 */
#define PWM_TB_Presc_2 (0x4UL << SIU_PWMSYNC_PRESCRST_Pos) /*!< Предделитель блока ШИМ2 */
#define PWM_TB_Presc_All (PWM_TB_Presc_0 | \
                          PWM_TB_Presc_1 | \
                          PWM_TB_Presc_2) /*!< Все блоки выбраны */

#define IS_PWM_TB_PRESC(VALUE) (((VALUE) & ~PWM_TB_Presc_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_TZ_ITSource_Define Источники прерываний блока сигналов аварий ШИМ
  * @{
  */

#define PWM_TZ_ITSource_Cycle PWM_TZEINT_CBC_Msk   /*!< Циклический обработчик сигнала аварии */
#define PWM_TZ_ITSource_OneShot PWM_TZEINT_OST_Msk /*!< Однократный обработчик сигнала аварии */
#define PWM_TZ_ITSource_All (PWM_TZ_ITSource_Cycle | \
                             PWM_TZ_ITSource_OneShot) /*!< Все источники выбраны */

#define IS_PWM_TZ_IT_SOURCE(IT_SOURCE) (((IT_SOURCE) & ~PWM_TZ_ITSource_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_TZ_ITStatus_Define Флаги прерываний блока сигналов аварий ШИМ
  * @{
  */

#define PWM_TZ_ITStatus_Int PWM_TZFLG_INT_Msk     /*!< Флаг прерывания NVIC */
#define PWM_TZ_ITStatus_Cycle PWM_TZFLG_CBC_Msk   /*!< Циклический обработчик сигнала аварии */
#define PWM_TZ_ITStatus_OneShot PWM_TZFLG_OST_Msk /*!< Однократный обработчик сигнала аварии */
#define PWM_TZ_ITStatus_All (PWM_TZ_ITStatus_Int |   \
                             PWM_TZ_ITStatus_Cycle | \
                             PWM_TZ_ITStatus_OneShot) /*!< Все флаги выбраны */

#define IS_PWM_TZ_IT_STATUS(VALUE) (((VALUE) & ~PWM_TZ_ITStatus_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_ET_Status_Define Флаги генерации событий запуска АЦП и DMA обработчиком событий
  * @{
  */

#define PWM_ET_Status_SOCA PWM_ETFLG_SOCA_Msk /*!< Флаг генерации запуска АЦП от канала А */
#define PWM_ET_Status_SOCB PWM_ETFLG_SOCB_Msk /*!< Флаг генерации запуска АЦП от канала B */
#define PWM_ET_Status_DRQA PWM_ETFLG_DRQA_Msk /*!< Флаг генерации запроса DMA от канала А */
#define PWM_ET_Status_DRQB PWM_ETFLG_DRQB_Msk /*!< Флаг генерации запроса DMA от канала B */
#define PWM_ET_Status_All (PWM_ET_Status_SOCA | \
                           PWM_ET_Status_SOCB | \
                           PWM_ET_Status_DRQA | \
                           PWM_ET_Status_DRQB) /*!< Все флаги выбраны */

#define IS_PWM_ET_STATUS(VALUE) (((VALUE) & ~PWM_ET_Status_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_HD_Source_Define Выбор источника события удержания
  * @{
  */

#define PWM_HD_Source_ADCDC0 PWM_HDSEL_ADCDC0_Msk /*!< Сигнал от цифрового компаратора 0 АЦП */
#define PWM_HD_Source_ADCDC1 PWM_HDSEL_ADCDC1_Msk /*!< Сигнал от цифрового компаратора 1 АЦП */
#define PWM_HD_Source_ADCDC2 PWM_HDSEL_ADCDC2_Msk /*!< Сигнал от цифрового компаратора 2 АЦП */
#define PWM_HD_Source_ADCDC3 PWM_HDSEL_ADCDC3_Msk /*!< Сигнал от цифрового компаратора 3 АЦП */
#define PWM_HD_Source_All (PWM_HD_Source_ADCDC0 | \
                           PWM_HD_Source_ADCDC1 | \
                           PWM_HD_Source_ADCDC2 | \
                           PWM_HD_Source_ADCDC3) /*!< Все источники выбраны */

#define IS_PWM_HD_SOURCE(VALUE) (((VALUE) & ~PWM_HD_Source_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_HD_ITSource_Define Источники прерываний блока cобытий удержания
  * @{
  */

#define PWM_HD_ITSource_Cycle PWM_HDEINT_CBC_Msk   /*!< Циклический обработчик cобытия удержания */
#define PWM_HD_ITSource_OneShot PWM_HDEINT_OST_Msk /*!< Однократный обработчик cобытия удержания */
#define PWM_HD_ITSource_All (PWM_HD_ITSource_Cycle | \
                             PWM_HD_ITSource_OneShot) /*!< Все источники выбраны */

#define IS_PWM_HD_IT_SOURCE(VALUE) (((VALUE) & ~PWM_HD_ITSource_All) == 0)

/**
  * @}
  */

/** @defgroup PWM_HD_ITStatus_Define Флаги прерываний блока cобытий удержания
  * @{
  */

#define PWM_HD_ITStatus_Int PWM_HDFLG_INT_Msk     /*!< Флаг прерывания NVIC */
#define PWM_HD_ITStatus_Cycle PWM_HDFLG_CBC_Msk   /*!< Циклический обработчик cобытия удержания */
#define PWM_HD_ITStatus_OneShot PWM_HDFLG_OST_Msk /*!< Однократный обработчик cобытия удержания */
#define PWM_HD_ITStatus_All (PWM_HD_ITStatus_Int |   \
                             PWM_HD_ITStatus_Cycle | \
                             PWM_HD_ITStatus_OneShot) /*!< Все флаги выбраны */

#define IS_PWM_HD_IT_STATUS(VALUE) (((VALUE) & ~PWM_HD_ITStatus_All) == 0)

/**
  * @}
  */

#define IS_PWM_IT_PERIOD(VALUE) ((VALUE) < 0x4)
#define IS_PWM_FILTER(VALUE) ((VALUE) < 0x100)
#define IS_PWM_PC_DUTY(VALUE) ((VALUE) < 0x7)
#define IS_PWM_PC_FREQ_DIV(VALUE) ((VALUE) < 0x8)
#define IS_PWM_PC_FIRST_WIDTH(VALUE) ((VALUE) < 0x10)

/**
  * @}
  */

/** @defgroup PWM_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор режима остановки таймера при отладке
  */
typedef enum {
    PWM_TB_Halt_StopOnTBCLK = PWM_TBCTL_FREESOFT_StopAtTBCLK,   /*!< Остановка таймера при отладке со следующего такта TBCLK */
    PWM_TB_Halt_StopOnPeriod = PWM_TBCTL_FREESOFT_StopAtPeriod, /*!< Остановка таймера при отладке в конце периода */
    PWM_TB_Halt_Free = PWM_TBCTL_FREESOFT_FreeRun               /*!< Без остановки */
} PWM_TB_Halt_TypeDef;
#define IS_PWM_TB_HALT(VALUE) (((VALUE) == PWM_TB_Halt_StopOnTBCLK) || \
                               ((VALUE) == PWM_TB_Halt_StopOnPeriod))

/**
  * @brief  Коэффициент базового деления частоты
  */
typedef enum {
    PWM_TB_ClkDiv_1 = PWM_TBCTL_CLKDIV_Div1,    /*!< Без деления тактовой частоты */
    PWM_TB_ClkDiv_2 = PWM_TBCTL_CLKDIV_Div2,    /*!< Деление тактовой частоты на 2 */
    PWM_TB_ClkDiv_4 = PWM_TBCTL_CLKDIV_Div4,    /*!< Деление тактовой частоты на 4 */
    PWM_TB_ClkDiv_8 = PWM_TBCTL_CLKDIV_Div8,    /*!< Деление тактовой частоты на 8 */
    PWM_TB_ClkDiv_16 = PWM_TBCTL_CLKDIV_Div16,  /*!< Деление тактовой частоты на 16 */
    PWM_TB_ClkDiv_32 = PWM_TBCTL_CLKDIV_Div32,  /*!< Деление тактовой частоты на 32 */
    PWM_TB_ClkDiv_64 = PWM_TBCTL_CLKDIV_Div64,  /*!< Деление тактовой частоты на 64 */
    PWM_TB_ClkDiv_128 = PWM_TBCTL_CLKDIV_Div128 /*!< Деление тактовой частоты на 128 */
} PWM_TB_ClkDiv_TypeDef;
#define IS_PWM_TB_CLK_DIV(VALUE) (((VALUE) == PWM_TB_ClkDiv_1) ||  \
                                  ((VALUE) == PWM_TB_ClkDiv_2) ||  \
                                  ((VALUE) == PWM_TB_ClkDiv_4) ||  \
                                  ((VALUE) == PWM_TB_ClkDiv_8) ||  \
                                  ((VALUE) == PWM_TB_ClkDiv_16) || \
                                  ((VALUE) == PWM_TB_ClkDiv_32) || \
                                  ((VALUE) == PWM_TB_ClkDiv_64) || \
                                  ((VALUE) == PWM_TB_ClkDiv_128))

/**
  * @brief  Коэффициент дополнительного деления частоты
  */
typedef enum {
    PWM_TB_ClkDivExtra_1 = PWM_TBCTL_HSPCLKDIV_Div1,   /*!< Без дополнительного деления тактовой частоты */
    PWM_TB_ClkDivExtra_2 = PWM_TBCTL_HSPCLKDIV_Div2,   /*!< Дополнительное деление тактовой частоты на 2 */
    PWM_TB_ClkDivExtra_4 = PWM_TBCTL_HSPCLKDIV_Div4,   /*!< Дополнительное деление тактовой частоты на 4 */
    PWM_TB_ClkDivExtra_6 = PWM_TBCTL_HSPCLKDIV_Div6,   /*!< Дополнительное деление тактовой частоты на 6 */
    PWM_TB_ClkDivExtra_8 = PWM_TBCTL_HSPCLKDIV_Div8,   /*!< Дополнительное деление тактовой частоты на 8 */
    PWM_TB_ClkDivExtra_10 = PWM_TBCTL_HSPCLKDIV_Div10, /*!< Дополнительное деление тактовой частоты на 10 */
    PWM_TB_ClkDivExtra_12 = PWM_TBCTL_HSPCLKDIV_Div12, /*!< Дополнительное деление тактовой частоты на 12 */
    PWM_TB_ClkDivExtra_14 = PWM_TBCTL_HSPCLKDIV_Div14, /*!< Дополнительное деление тактовой частоты на 14 */
} PWM_TB_ClkDivExtra_TypeDef;
#define IS_PWM_TB_CLK_DIV_EXTRA(VALUE) (((VALUE) == PWM_TB_ClkDivExtra_1) ||  \
                                        ((VALUE) == PWM_TB_ClkDivExtra_2) ||  \
                                        ((VALUE) == PWM_TB_ClkDivExtra_4) ||  \
                                        ((VALUE) == PWM_TB_ClkDivExtra_6) ||  \
                                        ((VALUE) == PWM_TB_ClkDivExtra_8) ||  \
                                        ((VALUE) == PWM_TB_ClkDivExtra_10) || \
                                        ((VALUE) == PWM_TB_ClkDivExtra_12) || \
                                        ((VALUE) == PWM_TB_ClkDivExtra_14))

/**
  * @brief  Направление счета
  */
typedef enum {
    PWM_TB_Dir_Down, /*!< Счет вниз */
    PWM_TB_Dir_Up    /*!< Счет вверх */
} PWM_TB_Dir_TypeDef;
#define IS_PWM_TB_DIR(VALUE) (((VALUE) == PWM_TB_Dir_Down) || \
                              ((VALUE) == PWM_TB_Dir_Up))

/**
  * @brief  Источник для выходного сигнала синхронизации SYNCO
  */
typedef enum {
    PWM_TB_SyncOut_SyncIn = PWM_TBCTL_SYNCOSEL_SYNCI,        /*!< Входной сигнал SYNCI */
    PWM_TB_SyncOut_CTREqZero = PWM_TBCTL_SYNCOSEL_CTREqZero, /*!< Значение таймера равно нулю */
    PWM_TB_SyncOut_CTREqCMPB = PWM_TBCTL_SYNCOSEL_CTREqCMPB, /*!< Значение таймера равно регистру CMPB */
    PWM_TB_SyncOut_Disable = PWM_TBCTL_SYNCOSEL_Disable      /*!< Выдача синхроимпульса запрещена */
} PWM_TB_SyncOut_TypeDef;
#define IS_PWM_TB_SYNC_OUT(VALUE) (((VALUE) == PWM_TB_SyncOut_SyncIn) ||    \
                                   ((VALUE) == PWM_TB_SyncOut_CTREqZero) || \
                                   ((VALUE) == PWM_TB_SyncOut_CTREqCMPB) || \
                                   ((VALUE) == PWM_TB_SyncOut_Disable))

/**
  * @brief Направление счета
  */
typedef enum {
    PWM_TB_Mode_Up = PWM_TBCTL_CTRMODE_Up,         /*!< Счет вверх */
    PWM_TB_Mode_Down = PWM_TBCTL_CTRMODE_Down,     /*!< Счет вниз */
    PWM_TB_Mode_UpDown = PWM_TBCTL_CTRMODE_UpDown, /*!< Счет вверх-вниз */
    PWM_TB_Mode_Disable = PWM_TBCTL_CTRMODE_Stop   /*!< Счетчик остановлен */
} PWM_TB_Mode_TypeDef;
#define IS_PWM_TB_MODE(VALUE) (((VALUE) == PWM_TB_Mode_Up) ||     \
                               ((VALUE) == PWM_TB_Mode_Down) ||   \
                               ((VALUE) == PWM_TB_Mode_UpDown) || \
                               ((VALUE) == PWM_TB_Mode_Disable))

/**
  * @brief  Событие для загрузки значения сравнения в теневом режиме
  */
typedef enum {
    PWM_CMP_LoadEvent_CTREqZero = PWM_CMPCTL_LOADAMODE_CTREqZero,            /*!< Загрузка отложенного значения при условии, что значение таймера равно нулю */
    PWM_CMP_LoadEvent_CTREqPeriod = PWM_CMPCTL_LOADAMODE_CTREqPRD,           /*!< Загрузка отложенного значения при условии, что значение таймера равно периоду */
    PWM_CMP_LoadEvent_CTREqZeroOrPeriod = PWM_CMPCTL_LOADAMODE_CTREqZeroPRD, /*!< Загрузка отложенного значения при условии, что значение таймера равно нулю или периоду */
    PWM_CMP_LoadEvent_Disable = PWM_CMPCTL_LOADAMODE_Disable                 /*!< Загрузка отложенного значения запрещена */
} PWM_CMP_LoadEvent_TypeDef;
#define IS_PWM_CMP_LOAD_EVENT(VALUE) (((VALUE) == PWM_CMP_LoadEvent_CTREqZero) ||         \
                                      ((VALUE) == PWM_CMP_LoadEvent_CTREqPeriod) ||       \
                                      ((VALUE) == PWM_CMP_LoadEvent_CTREqZeroOrPeriod) || \
                                      ((VALUE) == PWM_CMP_LoadEvent_Disable))

/**
  * @brief Выбор действия на выводе ШИМ
  */
typedef enum {
    PWM_AQ_Action_None = PWM_AQCTLA_ZRO_NoAction, /*!< Нет реакции */
    PWM_AQ_Action_ToZero = PWM_AQCTLA_PRD_Clear,  /*!< Переключение в ноль */
    PWM_AQ_Action_ToOne = PWM_AQCTLA_CAU_Set,     /*!< Переключение в единицу */
    PWM_AQ_Action_Inv = PWM_AQCTLA_CAD_Toggle     /*!< Инверсия текущего состояния */
} PWM_AQ_Action_TypeDef;
#define IS_PWM_AQ_ACTION(VALUE) (((VALUE) == PWM_AQ_Action_None) ||   \
                                 ((VALUE) == PWM_AQ_Action_ToZero) || \
                                 ((VALUE) == PWM_AQ_Action_ToOne) ||  \
                                 ((VALUE) == PWM_AQ_Action_Inv))

/**
  * @brief  Возможные события для генерации внешних сигналов/запросов
  */
typedef enum {
    PWM_AQ_Event_CTREqZero = PWM_AQCTLA_ZRO_Pos,     /*!< Значение таймера равно нулю */
    PWM_AQ_Event_CTREqPeriod = PWM_AQCTLA_PRD_Pos,   /*!< Значение таймера равно периоду */
    PWM_AQ_Event_CTREqCMPAUp = PWM_AQCTLA_CAU_Pos,   /*!< Значение таймера равно регистру CMPA при счете вверх */
    PWM_AQ_Event_CTREqCMPADown = PWM_AQCTLA_CAD_Pos, /*!< Значение таймера равно регистру CMPA при счете вниз */
    PWM_AQ_Event_CTREqCMPBUp = PWM_AQCTLA_CBU_Pos,   /*!< Значение таймера равно регистру CMPB при счете вверх */
    PWM_AQ_Event_CTREqCMPBDown = PWM_AQCTLA_CBD_Pos  /*!< Значение таймера равно регистру CMPB при счете вниз */
} PWM_AQ_Event_TypeDef;
#define IS_PWM_AQ_EVENT(VALUE) (((VALUE) == PWM_AQ_Event_CTREqZero) ||     \
                                ((VALUE) == PWM_AQ_Event_CTREqPeriod) ||   \
                                ((VALUE) == PWM_AQ_Event_CTREqCMPAUp) ||   \
                                ((VALUE) == PWM_AQ_Event_CTREqCMPADown) || \
                                ((VALUE) == PWM_AQ_Event_CTREqCMPBUp) ||   \
                                ((VALUE) == PWM_AQ_Event_CTREqCMPBDown))

/**
  * @brief  Cобытия для применения настроек однократного или цилического программного воздействия на вывода
  */
typedef enum {
    PWM_AQ_ForceShadowEvent_CTREqZero = PWM_AQSFRC_RLDCSF_CTREqZero,          /*!< Значение таймера равно нулю */
    PWM_AQ_ForceShadowEvent_CTREqPeriod = PWM_AQSFRC_RLDCSF_CTREqPRD,         /*!< Значение таймера равно периоду */
    PWM_AQ_ForceShadowEvent_CTREqPeriodZero = PWM_AQSFRC_RLDCSF_CTREqZeroPRD, /*!< Значение таймера равно периоду или нулю */
    PWM_AQ_ForceShadowEvent_None = PWM_AQSFRC_RLDCSF_NoShadow,                /*!< Прямая запись */
} PWM_AQ_ForceShadowEvent_TypeDef;
#define IS_PWM_AQ_FORCE_SHADOW_EVENT(VALUE) (((VALUE) == PWM_AQ_ForceShadowEvent_CTREqZero) ||       \
                                             ((VALUE) == PWM_AQ_ForceShadowEvent_CTREqPeriod) ||     \
                                             ((VALUE) == PWM_AQ_ForceShadowEvent_CTREqPeriodZero) || \
                                             ((VALUE) == PWM_AQ_ForceShadowEvent_None))

/**
  * @brief Выбор источников для формирования задержки
  */
typedef enum {
    PWM_DB_In_A = PWM_DBCTL_INMODE_APosNeg,            /*!< Входной сигнал А задержан по обоим фронтам */
    PWM_DB_In_AFallBRise = PWM_DBCTL_INMODE_ANeg_BPos, /*!< Входной сигнал A задержан заднему фронту, B - по переднему  */
    PWM_DB_In_ARiseBFall = PWM_DBCTL_INMODE_APos_BNeg, /*!< Входной сигнал A задержан переднему фронту, B - по заднему  */
    PWM_DB_In_B = PWM_DBCTL_INMODE_BPosNeg             /*!< Входной сигнал B задержан по обоим фронтам */
} PWM_DB_In_TypeDef;
#define IS_PWM_DB_IN(VALUE) (((VALUE) == PWM_DB_In_A) ||          \
                             ((VALUE) == PWM_DB_In_ARiseBFall) || \
                             ((VALUE) == PWM_DB_In_AFallBRise) || \
                             ((VALUE) == PWM_DB_In_B))

/**
  * @brief Выбор полярности задержанных сигналов
  */
typedef enum {
    PWM_DB_Polarity_ActiveHigh = PWM_DBCTL_POLSEL_InvDisable, /*!< Нет инверсии */
    PWM_DB_Polarity_ActiveLowCompl = PWM_DBCTL_POLSEL_InvA,   /*!< Инвертируется сигнал, задержанный по переднему фронту  */
    PWM_DB_Polarity_ActiveHighCompl = PWM_DBCTL_POLSEL_InvB,  /*!< Инвертируется сигнал, задержанный по заднему фронту  */
    PWM_DB_Polarity_ActiveLow = PWM_DBCTL_POLSEL_InvAB        /*!< Инвертируются оба сигнала */
} PWM_DB_Polarity_TypeDef;
#define IS_PWM_DB_POLARITY(VALUE) (((VALUE) == PWM_DB_Polarity_ActiveHigh) ||      \
                                   ((VALUE) == PWM_DB_Polarity_ActiveLowCompl) ||  \
                                   ((VALUE) == PWM_DB_Polarity_ActiveHighCompl) || \
                                   ((VALUE) == PWM_DB_Polarity_ActiveLow))

/**
  * @brief Выбор выходных сигналов блока задержки
  */
typedef enum {
    PWM_DB_Out_BypassAB = PWM_DBCTL_OUTMODE_NoSpec,  /*!< Нет задержки. Входные сигналы A и B подключены напрямую к выходу модуля задержки. */
    PWM_DB_Out_BypassA = PWM_DBCTL_OUTMODE_BNeg,     /*!< Входной сигнал A подключен напрямую к выходу A модуля задержки. Задержанный по заднему фронту сигнал подключен к выходу B.  */
    PWM_DB_Out_BypassB = PWM_DBCTL_OUTMODE_APos,     /*!< Входной сигнал B подключен напрямую к выходу B модуля задержки. Задержанный по переднему фронту сигнал подключен к выходу A.  */
    PWM_DB_Out_DelayAB = PWM_DBCTL_OUTMODE_Apos_BNeg /*!< Задержанный по переднему фронту сигнал подключен к выходу A, по заднему - к выходу B. */
} PWM_DB_Out_TypeDef;
#define IS_PWM_DB_OUT(VALUE) (((VALUE) == PWM_DB_Out_BypassAB) || \
                              ((VALUE) == PWM_DB_Out_BypassA) ||  \
                              ((VALUE) == PWM_DB_Out_BypassB) ||  \
                              ((VALUE) == PWM_DB_Out_DelayAB))

/**
  * @brief  Возможные события для генерации внешних сигналов/запросов
  */
typedef enum {
    PWM_ET_Event_CTREqZero = PWM_ETSEL_SOCASEL_CTREqZero,             /*!< Значение таймера равно нулю */
    PWM_ET_Event_CTREqPeriod = PWM_ETSEL_SOCASEL_CTREqPRD,            /*!< Значение таймера равно периоду */
    PWM_ET_Event_CTREqCMPA_Up = PWM_ETSEL_SOCASEL_CTREqCMPA_OnUp,     /*!< Значение таймера равно регистру CMPA при счете вверх */
    PWM_ET_Event_CTREqCMPA_Down = PWM_ETSEL_SOCASEL_CTREqCMPA_OnDown, /*!< Значение таймера равно регистру CMPA при счете вниз */
    PWM_ET_Event_CTREqCMPB_Up = PWM_ETSEL_SOCASEL_CTREqCMPB_OnUp,     /*!< Значение таймера равно регистру CMPB при счете вверх */
    PWM_ET_Event_CTREqCMPB_Down = PWM_ETSEL_SOCASEL_CTREqCMPB_OnDown  /*!< Значение таймера равно регистру CMPB при счете вниз */
} PWM_ET_Event_TypeDef;
#define IS_PWM_ET_EVENT(VALUE) (((VALUE) == PWM_ET_Event_CTREqZero) ||      \
                                ((VALUE) == PWM_ET_Event_CTREqPeriod) ||    \
                                ((VALUE) == PWM_ET_Event_CTREqCMPA_Up) ||   \
                                ((VALUE) == PWM_ET_Event_CTREqCMPA_Down) || \
                                ((VALUE) == PWM_ET_Event_CTREqCMPB_Up) ||   \
                                ((VALUE) == PWM_ET_Event_CTREqCMPB_Down))

/**
  * @brief Выбор поведения вывода в случае наступления сигнала аварии
  */
typedef enum {
    PWM_TZ_Action_ToZ = PWM_TZCTL_TZA_Z,        /*!< Переключение вывода в третье состояние */
    PWM_TZ_Action_ToOne = PWM_TZCTL_TZA_Set,    /*!< Переключение в единицу */
    PWM_TZ_Action_ToZero = PWM_TZCTL_TZA_Clear, /*!< Переключение в ноль  */
    PWM_TZ_Action_None = PWM_TZCTL_TZA_NoAction /*!< Нет действий */
} PWM_TZ_Action_TypeDef;
#define IS_PWM_TZ_ACTION(VALUE) (((VALUE) == PWM_TZ_Action_ToZ) ||    \
                                 ((VALUE) == PWM_TZ_Action_ToOne) ||  \
                                 ((VALUE) == PWM_TZ_Action_ToZero) || \
                                 ((VALUE) == PWM_TZ_Action_None))

/**
  * @brief Выбор поведения вывода в случае наступления события удержания.
  */

typedef enum {
    PWM_HD_Action_ToOne = PWM_HDCTL_HDA_Set,    /*!< Переключение в единицу*/
    PWM_HD_Action_ToZero = PWM_HDCTL_HDA_Clear, /*!< Переключение в ноль  */
    PWM_HD_Action_None = PWM_HDCTL_HDA_NoAction /*!< Нет действий */
} PWM_HD_Action_TypeDef;
#define IS_PWM_HD_ACTION(VALUE) (((VALUE) == PWM_HD_Action_ToOne) ||  \
                                 ((VALUE) == PWM_HD_Action_ToZero) || \
                                 ((VALUE) == PWM_HD_Action_None))

/**
  * @brief  Структура инициализации таймера-счетчика блока ШИМ
  */
typedef struct
{
    PWM_TB_Halt_TypeDef Halt;               /*!< Выбор режима остановки таймера при отладке */
    PWM_TB_ClkDiv_TypeDef ClkDiv;           /*!< Коэффициент базового деления частоты */
    PWM_TB_ClkDivExtra_TypeDef ClkDivExtra; /*!< Коэффициент дополнительного деления частоты.
                                                 Результирующий коэффциент = ClkDiv * ClkDivExtra */
    PWM_TB_SyncOut_TypeDef SyncOut;         /*!< Источник для выходного сигнала синхронизации SYNCO */
    FunctionalState PhaseSync;              /*!< Разрешает загрузку счетчика значением регистра фазы при получении события синхронизации */
    PWM_TB_Dir_TypeDef PhaseSyncDir;        /*!< Задание направления счета после синхронизации фазы */
    uint32_t Phase;                         /*!< Значение фазы ШИМ при получении события синхронизации.
                                                 Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    PWM_TB_Mode_TypeDef Mode;               /*!< Задание направления счета */
    FunctionalState PeriodDirectLoad;       /*!< Разрешает только прямую загрузку в регистр периода (теневая отключена) */
    uint32_t Period;                        /*!< Значение периода таймера ШИМ.
                                                 Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
} PWM_TB_Init_TypeDef;
#define IS_PWM_TB_PHASE_VAL(VALUE) ((VALUE) < 0x10000)
#define IS_PWM_TB_PERIOD_VAL(VALUE) ((VALUE) < 0x10000)
#define IS_PWM_TB_COUNTER_VAL(VALUE) ((VALUE) < 0x10000)

typedef struct
{
    PWM_AQ_Action_TypeDef ActionA_CTREqZero;     /*!< Действие в канале А, при наступлении события равенства счетчика таймера нулю */
    PWM_AQ_Action_TypeDef ActionA_CTREqPeriod;   /*!< Действие в канале А, при наступлении события равенства счетчика значению периода */
    PWM_AQ_Action_TypeDef ActionA_CTREqCMPAUp;   /*!< Действие в канале А, при наступлении события равенства счетчика таймера значению сравнения A при счете вверх */
    PWM_AQ_Action_TypeDef ActionA_CTREqCMPADown; /*!< Действие в канале A, при наступлении события равенства счетчика таймера значению сравнения A при счете вниз */
    PWM_AQ_Action_TypeDef ActionA_CTREqCMPBUp;   /*!< Действие в канале А, при наступлении события равенства счетчика таймера значению сравнения B при счете вверх */
    PWM_AQ_Action_TypeDef ActionA_CTREqCMPBDown; /*!< Действие в канале A, при наступлении события равенства счетчика таймера значению сравнения B при счете вниз */
    PWM_AQ_Action_TypeDef ActionB_CTREqZero;     /*!< Действие в канале B, при наступлении события равенства счетчика таймера нулю */
    PWM_AQ_Action_TypeDef ActionB_CTREqPeriod;   /*!< Действие в канале B, при наступлении события равенства счетчика значению периода */
    PWM_AQ_Action_TypeDef ActionB_CTREqCMPAUp;   /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения A при счете вверх */
    PWM_AQ_Action_TypeDef ActionB_CTREqCMPADown; /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения A при счете вниз */
    PWM_AQ_Action_TypeDef ActionB_CTREqCMPBUp;   /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения B при счете вверх */
    PWM_AQ_Action_TypeDef ActionB_CTREqCMPBDown; /*!< Действие в канале B, при наступлении события равенства счетчика таймера значению сравнения B при счете вниз */
} PWM_AQ_Init_TypeDef;

/**
   * @brief  Структура инициализации компараторов блока ШИМ
   */
typedef struct
{
    FunctionalState CmpADirectLoad;          /*!< Разрешает только прямую загрузку в регистр CMPA (теневая отключена) */
    PWM_CMP_LoadEvent_TypeDef LoadEventCmpA; /*!< Событие для теневой загрузки в регистр сравнения CMPA */
    uint32_t CmpA;                           /*!< Значение порога срабатывания канала А, которое сравнивается со значением счетчика таймера.
                                                  Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
    FunctionalState CmpBDirectLoad;          /*!< Разрешает только прямую загрузку в регистр CMPB (теневая отключена) */
    PWM_CMP_LoadEvent_TypeDef LoadEventCmpB; /*!< Событие для теневой загрузки в регистр сравнения CMPB */
    uint32_t CmpB;                           /*!< Значение порога срабатывания канала B, которое сравнивается со значением счетчика таймера.
                                                  Параметр может принимать любое значение из диапазона: 0x0000-0xFFFF. */
} PWM_CMP_Init_TypeDef;
#define IS_PWM_CMP_VAL(VALUE) ((VALUE) < 0x10000)

/**
   * @brief  Структура инициализации порогового выключателя блока ШИМ
   */
typedef struct
{
    PWM_HD_Action_TypeDef ActionA; /*!< Настройка поведения канала A при поступлении события удержания */
    PWM_HD_Action_TypeDef ActionB; /*!< Настройка поведения канала B при поступлении события удержания */
    uint32_t Source;               /*!< Выбор источников для генерации события удержания.
                                        Параметр принимает любую совокупность значений из @ref PWM_HD_Source_Define */
    FunctionalState Cycle;         /*!< Включение циклической обработки сигнала удержания */
    FunctionalState OneShot;       /*!< Включение однократной обработки сигнала удержания */
} PWM_HD_Init_TypeDef;

/**
   * @brief  Структура инициализации задержки сигналов ШИМ ("мертвое время").
   */
typedef struct
{
    PWM_DB_In_TypeDef In;             /*!< Выбор источников для формирования задержки */
    PWM_DB_Polarity_TypeDef Polarity; /*!< Выбор полярности задержанных сигналов */
    PWM_DB_Out_TypeDef Out;           /*!< Выбор выходных сигналов блока задержки */
    uint32_t RiseDelay;               /*!< Величина задержки переднего фронта.
                                           Параметр может принимать любое значение из диапазона: 0x000-0x3FF. */
    uint32_t FallDelay;               /*!< Величина задержки заднего фронта.
                                           Параметр может принимать любое значение из диапазона: 0x000-0x3FF. */
} PWM_DB_Init_TypeDef;
#define IS_PWM_DB_DELAY_VAL(VALUE) ((VALUE) < 0x400)

/**
   * @brief  Структура инициализации обработчика сигнала аварии блока ШИМ
   */
typedef struct
{
    PWM_TZ_Action_TypeDef ActionA; /*!< Настройка поведения канала A при поступлении сигнала аварии */
    PWM_TZ_Action_TypeDef ActionB; /*!< Настройка поведения канала B при поступлении сигнала аварии */
    FunctionalState Cycle;         /*!< Включение циклической обработки сигнала аварии */
    FunctionalState OneShot;       /*!< Включение однократной обработки сигнала аварии */
} PWM_TZ_Init_TypeDef;

/**
  * @brief  Структура инициализации блока "триггера событий" для генерации внешних сигналов/запросов
  */
typedef struct
{
    FunctionalState SOCA;           /*!< Канал А: разрешает формирование строба запуска АЦП */
    PWM_ET_Event_TypeDef EventSOCA; /*!< Канал А: выбор события для формирования строба запуска АЦП */
    uint32_t PeriodSOCA;            /*!< Канал А: выбор количества событий для возникновения строба АЦП.
                                         Параметр принимает любое значение из диапазона 0-3,
                                         где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
    FunctionalState SOCB;           /*!< Канал B: разрешает формирование строба запуска АЦП */
    PWM_ET_Event_TypeDef EventSOCB; /*!< Канал B: выбор события для формирования строба запуска АЦП */
    uint32_t PeriodSOCB;            /*!< Канал B: выбор количества событий для возникновения строба запуска АЦП.
                                         Параметр принимает любое значение из диапазона 0-3,
                                         где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
    FunctionalState DRQA;           /*!< Канал А: разрешает формирование запроса DMA */
    PWM_ET_Event_TypeDef EventDRQA; /*!< Канал А: выбор события для формирования запроса DMA */
    uint32_t PeriodDRQA;            /*!< Канал А: выбор количества событий для возникновения запроса DMA.
                                         Параметр принимает любое значение из диапазона 0-3,
                                         где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
    FunctionalState DRQB;           /*!< Канал B: разрешает формирование запроса DMA */
    PWM_ET_Event_TypeDef EventDRQB; /*!< Канал B: выбор события для формирования запроса DMA */
    uint32_t PeriodDRQB;            /*!< Канал B: выбор количества событий для возникновения запроса DMA.
                                         Параметр принимает любое значение из диапазона 0-3,
                                         где 0 - соответсвует каждому событию, 1 - каждому второму и т.д. */
} PWM_ET_Init_TypeDef;
#define IS_PWM_ET_PERIOD(VALUE) ((VALUE) < 0x4)

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions Функции
  * @{
  */

void PWM_DeInit(PWM_TypeDef* PWMx);

/**
  * @brief   Установка ширины фильтрации коротких импульсов
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   FilterVal  Значение.
  *                     Параметр принимает любое значение из диапазона 0x00-0xFF,
  *                     где 0 - фильтр выключен, а 0xFF - 25.6 мкс (шаг установки 0.1 мкс).
  * @retval  void
  */
__STATIC_INLINE void PWM_FilterConfig(PWM_TypeDef* PWMx, uint32_t FilterVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_FILTER(FilterVal));

    WRITE_REG(PWMx->FWDTH, FilterVal);
}

/**
  * @brief   Разрешение всех теневых загрузок регистров PWM
  * @param   PWMx  Выбор блока PWM, где x лежит в диапазоне 0-2.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_GlobalShadowLoadCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->TBCTL_bit.SHDWGLOB, State);
}

/** @defgroup PWM_Exported_Functions_TimeBase Счетчик
  * @{
  */

void PWM_TB_Init(PWM_TypeDef* PWMx, PWM_TB_Init_TypeDef* InitStruct);
void PWM_TB_StructInit(PWM_TB_Init_TypeDef* InitStruct);

/**
  * @brief   Управление предделителями тактирования таймеров блоков PWM
  * @param   Presc  Выбор предделителей блоков.
  *                 Параметр принимает любою совокупность значений из @ref PWM_Presc_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_PrescCmd(uint32_t Presc, FunctionalState State)
{
    assert_param(IS_PWM_TB_PRESC(Presc));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(SIU->PWMSYNC, Presc, State ? Presc : 0);
}

/**
  * @brief   Настройка коэффициента деления частоты для получения счетного тактового сигнала TBCLK.
  *          Результирующий коэффциент = ClkDiv * ClkDivExtra
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ClkDiv  Выбор делителя
  * @param   ClkDivExtra  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_ClkDivConfig(PWM_TypeDef* PWMx, PWM_TB_ClkDiv_TypeDef ClkDiv, PWM_TB_ClkDivExtra_TypeDef ClkDivExtra)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_CLK_DIV(ClkDiv));
    assert_param(IS_PWM_TB_CLK_DIV_EXTRA(ClkDivExtra));

    MODIFY_REG(PWMx->TBCTL, PWM_TBCTL_CLKDIV_Msk | PWM_TBCTL_HSPCLKDIV_Msk,
               ((ClkDiv << PWM_TBCTL_CLKDIV_Pos) |
                (ClkDivExtra << PWM_TBCTL_HSPCLKDIV_Pos)));
}

/**
  * @brief   Чтение статуса флага состояния таймера PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любою совокупность значений из @ref PWM_TB_Status_Define.
  * @retval  Status  Статус прерывания. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus PWM_TB_Status(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_STATUS(Status));

    return (FlagStatus)READ_BIT(PWMx->TBSTS, Status);
}

/**
  * @brief   Сброс флагов статусов таймера PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любою совокупность значений из @ref PWM_TB_Status_Define.
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_StatusClear(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_STATUS(Status));

    WRITE_REG(PWMx->TBSTS, Status);
}

/**
  * @brief   Установка значения счетчика PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   CounterVal  Значение счетчика
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_SetCounter(PWM_TypeDef* PWMx, uint32_t CounterVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_COUNTER_VAL(CounterVal));

    WRITE_REG(PWMx->TBCTR, CounterVal);
}

/**
  * @brief   Установка значения периода PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Значение периода
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_SetPeriod(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_PERIOD_VAL(PeriodVal));

    WRITE_REG(PWMx->TBPRD, PeriodVal);
}

/**
  * @brief   Установка значения фазы PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PhaseVal  Значение фазы
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_SetPhase(PWM_TypeDef* PWMx, uint32_t PhaseVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_PHASE_VAL(PhaseVal));

    WRITE_REG(PWMx->TBPHS, PhaseVal);
}

/**
  * @brief   Получение текущего значения счетчика PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение счетчика
  */
__STATIC_INLINE uint32_t PWM_TB_GetCounter(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->TBCTR);
}

/**
  * @brief   Получение текущего значения периода PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение периода
  */
__STATIC_INLINE uint32_t PWM_TB_GetPeriod(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->TBPRD);
}

/**
  * @brief   Получение текущего значения фазы PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение фазы
  */
__STATIC_INLINE uint32_t PWM_TB_GetPhase(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->TBPHS);
}

/**
  * @brief   Программный запуск входного синхроимпульса SYNCI
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_SwSyncInCmd(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->TBCTL_bit.SWFSYNC, 1);
}

/**
  * @brief   Настройка режима остановки таймера PWM при отладке
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Halt  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_HaltConfig(PWM_TypeDef* PWMx, PWM_TB_Halt_TypeDef Halt)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_HALT(Halt));

    WRITE_REG(PWMx->TBCTL_bit.FREESOFT, Halt);
}

/**
  * @brief   Настройка источника выходного сигнала синхронизации SYNCO
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   SyncOut  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_SyncOutConfig(PWM_TypeDef* PWMx, PWM_TB_SyncOut_TypeDef SyncOut)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_SYNC_OUT(SyncOut));

    WRITE_REG(PWMx->TBCTL_bit.SYNCOSEL, SyncOut);
}

/**
  * @brief   Разрешает загрузку счетчика значением регистра фазы при получении события синхронизации
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_PhaseSyncCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->TBCTL_bit.PHSEN, State);
}

/**
  * @brief   Задание направления счета после синхронизации фазы
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PhaseSyncDir  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_PhaseSyncDirConfig(PWM_TypeDef* PWMx, PWM_TB_Dir_TypeDef PhaseSyncDir)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_DIR(PhaseSyncDir));

    WRITE_REG(PWMx->TBCTL_bit.PHSDIR, PhaseSyncDir);
}

/**
  * @brief   Задание направления счета PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_ModeConfig(PWM_TypeDef* PWMx, PWM_TB_Mode_TypeDef Mode)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TB_MODE(Mode));

    WRITE_REG(PWMx->TBCTL_bit.CTRMODE, Mode);
}

/**
  * @brief   Разрешает прямую загрузку в регистр периода (теневая отключена)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TB_PeriodDirectLoadCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->TBCTL_bit.PRDLD, State);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_ActionQualifier Управление поведением выводов
  * @{
  */

void PWM_AQ_Init(PWM_TypeDef* PWMx, PWM_AQ_Init_TypeDef* InitStruct);
void PWM_AQ_StructInit(PWM_AQ_Init_TypeDef* InitStruct);

/**
  * @brief   Задание действия на выходе PWM A по выбранному событию
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ActionAConfig(PWM_TypeDef* PWMx, PWM_AQ_Event_TypeDef Event, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_EVENT(Event));
    assert_param(IS_PWM_AQ_ACTION(Action));

    MODIFY_REG(PWMx->AQCTLA, 3 << (uint32_t)Event, Action << (uint32_t)Event);
}

/**
  * @brief   Программное задание продолжительного воздействия на канал PWM A
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceContACmd(PWM_TypeDef* PWMx, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_ACTION(Action));

    WRITE_REG(PWMx->AQCSFRC_bit.CSFA, Action);
}

/**
  * @brief   Настройка типа однократного программного воздействия на канал PWM A
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceAConfig(PWM_TypeDef* PWMx, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_ACTION(Action));

    WRITE_REG(PWMx->AQSFRC_bit.ACTSFA, Action);
}

/**
  * @brief   Применение выбранного однократного программного воздействия на канал PWM A
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceACmd(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->AQSFRC_bit.OTSFA, 1);
}

/**
  * @brief   Задание действия на выходе PWM B по выбранному событию
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ActionBConfig(PWM_TypeDef* PWMx, PWM_AQ_Event_TypeDef Event, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_EVENT(Event));
    assert_param(IS_PWM_AQ_ACTION(Action));

    MODIFY_REG(PWMx->AQCTLB, 3 << (uint32_t)Event, Action << (uint32_t)Event);
}

/**
  * @brief   Программное задание продолжительного воздействия на канал PWM B
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceContBCmd(PWM_TypeDef* PWMx, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_ACTION(Action));

    WRITE_REG(PWMx->AQCSFRC_bit.CSFB, Action);
}

/**
  * @brief   Настройка типа однократного программного воздействия на канал PWM B
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceBConfig(PWM_TypeDef* PWMx, PWM_AQ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_ACTION(Action));

    WRITE_REG(PWMx->AQSFRC_bit.ACTSFB, Action);
}

/**
  * @brief   Применение выбранного однократного программного воздействия на канал PWM B
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceBCmd(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->AQSFRC_bit.OTSFB, 1);
}

/**
  * @brief   Задание события для применения настроек однократного или цилического программного воздействия на вывода
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_AQ_ForceShadowConfig(PWM_TypeDef* PWMx, PWM_AQ_ForceShadowEvent_TypeDef ForceShadowEvent)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_AQ_FORCE_SHADOW_EVENT(ForceShadowEvent));

    WRITE_REG(PWMx->AQSFRC_bit.RLDCSF, (uint32_t)ForceShadowEvent);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_Compare Компараторы
  * @{
  */

void PWM_CMP_Init(PWM_TypeDef* PWMx, PWM_CMP_Init_TypeDef* InitStruct);
void PWM_CMP_StructInit(PWM_CMP_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка cобытия для теневой загрузки в регистр сравнения CMPA
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   LoadEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_CmpALoadEventConfig(PWM_TypeDef* PWMx, PWM_CMP_LoadEvent_TypeDef LoadEvent)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_LOAD_EVENT(LoadEvent));

    WRITE_REG(PWMx->CMPCTL_bit.LOADAMODE, LoadEvent);
}

/**
  * @brief   Разрешает прямую загрузку в регистр CMPA (теневая отключена)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_CmpADirectLoadCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->CMPCTL_bit.SHDWAMODE, State);
}

/**
  * @brief   Установка значения сравнения A PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   CMPAVal  Значение сравнения
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_SetCmpA(PWM_TypeDef* PWMx, uint32_t CMPAVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_VAL(CMPAVal));

    WRITE_REG(PWMx->CMPA_bit.CMPA, CMPAVal);
}

/**
  * @brief   Получение текущего значения сравнения A PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t PWM_CMP_GetCmpA(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->CMPA_bit.CMPA);
}

/**
  * @brief   Настройка cобытия для теневой загрузки в регистр сравнения CMPB
  * @param   PWMx  Выбор ШИМ, где x лежит в диапазоне 0-2
  * @param   LoadEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_CmpBLoadEventConfig(PWM_TypeDef* PWMx, PWM_CMP_LoadEvent_TypeDef LoadEvent)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_LOAD_EVENT(LoadEvent));

    WRITE_REG(PWMx->CMPCTL_bit.LOADBMODE, LoadEvent);
}

/**
  * @brief   Разрешает прямую загрузку в регистр CMPB (теневая отключена)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_CmpBDirectLoadCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->CMPCTL_bit.SHDWBMODE, State);
}

/**
  * @brief   Установка значения сравнения B PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   CMPBVal  Значение сравнения
  * @retval  void
  */
__STATIC_INLINE void PWM_CMP_SetCmpB(PWM_TypeDef* PWMx, uint32_t CMPBVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_VAL(CMPBVal));

    WRITE_REG(PWMx->CMPB_bit.CMPB, CMPBVal);
}

/**
  * @brief   Получение текущего значения сравнения B PWM
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t PWM_CMP_GetCmpB(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->CMPB_bit.CMPB);
}

/**
  * @brief   Чтение статуса флага состояния компараторов PWM.
  *          Флаги установлены, если произошла запись в активный регистр значения сравнения из теневого.
  *          Сбрасываются флаги автоматически при каждой записи в теневой регистр.
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любою совокупность значений из @ref PWM_CMP_Status_Define.
  * @retval  Status  Статус флагов. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus PWM_CMP_Status(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_CMP_STATUS(Status));

    return (FlagStatus)READ_BIT(PWMx->CMPCTL, Status);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_HoldDetector Блок порогового выключателя
  * @{
  */

void PWM_HD_Init(PWM_TypeDef* PWMx, PWM_HD_Init_TypeDef* InitStruct);
void PWM_HD_StructInit(PWM_HD_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка поведения канала A при поступлении события удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_ActionAConfig(PWM_TypeDef* PWMx, PWM_HD_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_ACTION(Action));

    WRITE_REG(PWMx->HDCTL_bit.HDA, Action);
}

/**
  * @brief   Настройка поведения канала B при поступлении события удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_ActionBConfig(PWM_TypeDef* PWMx, PWM_HD_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_ACTION(Action));

    WRITE_REG(PWMx->HDCTL_bit.HDB, Action);
}

/**
  * @brief   Выбор источников для генерации события удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Source  Выбор источника
  *                  Параметр принимает любую совокупность значений из @ref PWM_HD_Source_Define
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_SourceCmd(PWM_TypeDef* PWMx, uint32_t Source, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_SOURCE(Source));

    MODIFY_REG(PWMx->HDSEL, Source, State ? Source : 0);
}

/**
  * @brief   Включение циклической обработки сигнала удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_CycleCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->HDSEL_bit.CBC, State);
}

/**
  * @brief   Включение однократной обработки сигнала удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_OneShotCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->HDSEL_bit.OST, State);
}

/**
  * @brief   Включение прерывания по событию удержания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источника прерывания
  *                    Параметр принимает любую совокупность значений из @ref PWM_HD_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_ITCmd(PWM_TypeDef* PWMx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_SOURCE(ITSource));

    MODIFY_REG(PWMx->HDEINT, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Программный вызов прерывания от обработчика событий удержания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источника прерывания
  *                    Параметр принимает любую совокупность значений из @ref PWM_HD_ITSource_Define
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_ITForceCmd(PWM_TypeDef* PWMx, uint32_t ITSource)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_SOURCE(ITSource));

    WRITE_REG(PWMx->HDFRC, ITSource);
}

/**
  * @brief   Чтение статуса флага прерывания от обработчика событий удержания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref PWM_HD_ITSource_Define.
  * @retval  Status  Статус прерывания. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus PWM_HD_ITStatus(PWM_TypeDef* PWMx, uint32_t ITStatus)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(PWMx->HDFLG, ITStatus);
}

/**
  * @brief   Сброс флага прерывания от обработчика событий удержания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref PWM_HD_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void PWM_HD_ITStatusClear(PWM_TypeDef* PWMx, uint32_t ITStatus)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_HD_IT_STATUS(ITStatus));

    WRITE_REG(PWMx->HDCLR, ITStatus);
}

/**
  * @brief   Чтение статуса активного запроса прерывания от обработчика событий удержания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Status  Статус запроса прерывания
  */
__STATIC_INLINE FlagStatus PWM_HD_ITPendStatus(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return (FlagStatus)READ_BIT(PWMx->HDINTCLR, PWM_HDINTCLR_INT_Msk);
}

/**
  * @brief  Сброс активного запроса прерывания от обработчика событий удержания выбранного блока ШИМ
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval Нет
  */
__STATIC_INLINE void PWM_HD_ITPendStatusClear(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->HDINTCLR_bit.INT, 1);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_DeadBand Блок "мертвого времени"
  * @{
  */

void PWM_DB_Init(PWM_TypeDef* PWMx, PWM_DB_Init_TypeDef* InitStruct);
void PWM_DB_StructInit(PWM_DB_Init_TypeDef* InitStruct);

/**
  * @brief   Выбор источников для формирования задержки
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   In  Выбор источника
  * @retval  void
  */
__STATIC_INLINE void PWM_DB_InConfig(PWM_TypeDef* PWMx, PWM_DB_In_TypeDef In)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_DB_IN(In));

    WRITE_REG(PWMx->DBCTL_bit.INMODE, In);
}

/**
  * @brief   Выбор выходных сигналов блока задержки
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Out  Выбор сигнала
  * @retval  void
  */
__STATIC_INLINE void PWM_DB_OutConfig(PWM_TypeDef* PWMx, PWM_DB_Out_TypeDef Out)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_DB_OUT(Out));

    WRITE_REG(PWMx->DBCTL_bit.OUTMODE, Out);
}

/**
  * @brief   Выбор полярности задержанных сигналов
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Polarity  Выбор полярности
  * @retval  void
  */
__STATIC_INLINE void PWM_DB_PolarityConfig(PWM_TypeDef* PWMx, PWM_DB_Polarity_TypeDef Polarity)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_DB_POLARITY(Polarity));

    WRITE_REG(PWMx->DBCTL_bit.POLSEL, Polarity);
}

/**
  * @brief   Установка значения величины задержки по переднему фронту
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   RiseDelayVal  Значение
  * @retval  void
  */
__STATIC_INLINE void PWM_DB_SetRiseDelay(PWM_TypeDef* PWMx, uint32_t RiseDelayVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_DB_DELAY_VAL(RiseDelayVal));

    WRITE_REG(PWMx->DBRED, RiseDelayVal);
}

/**
  * @brief   Установка значения величины задержки по заднему фронту
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   FallDelayVal  Значение
  * @retval  void
  */
__STATIC_INLINE void PWM_DB_SetFallDelay(PWM_TypeDef* PWMx, uint32_t FallDelayVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_DB_DELAY_VAL(FallDelayVal));

    WRITE_REG(PWMx->DBFED, FallDelayVal);
}

/**
  * @brief   Получение текущего значения величины задержки по переднему фронту
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_DB_GetRiseDelay(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->DBRED);
}

/**
  * @brief   Получение текущего значения величины задержки по заднему фронту
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_DB_GetFallDelay(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->DBFED);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_PWM_Chopper Блок модуляции
  * @{
  */

/**
  * @brief   Настройка модулятора сигналов ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   DutyVal  Значение скважности второго и последующего импульсов.
  *                   Параметр принимает любое значение из диапазона 0x0-0x6,
  *                   где 0x0 - скважность 1/8, а 0x6 - 7/8.
  * @param   FreqDivVal  Значение делителя частоты второго и последующего импульсов.
  *                      Параметр принимает любое значение из диапазона 0x0-0x7,
  *                      где 0x0 - без деления, 0x1 - с коэф. 1/2, а 0x7 - 1/8.
  * @param   FirstWidthVal  Значение ширины первого импульса в тактах SysClk/8.
  *                         Параметр принимает любое значение из диапазона 0x0-0xF,
  *                         где 0x0 - 1 такт, а 0xF - 16 тактов.
  * @retval  void
  */
__STATIC_INLINE void PWM_PC_Config(PWM_TypeDef* PWMx, uint32_t DutyVal, uint32_t FreqDivVal, uint32_t FirstWidthVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_PC_DUTY(DutyVal));
    assert_param(IS_PWM_PC_FREQ_DIV(FreqDivVal));
    assert_param(IS_PWM_PC_FIRST_WIDTH(FirstWidthVal));

    MODIFY_REG(PWMx->PCCTL, PWM_PCCTL_CHPDUTY_Msk | PWM_PCCTL_CHPFREQ_Msk | PWM_PCCTL_OSTWTH_Msk,
               ((DutyVal << PWM_PCCTL_CHPDUTY_Pos) |
                (FreqDivVal << PWM_PCCTL_CHPFREQ_Pos) |
                (FirstWidthVal << PWM_PCCTL_OSTWTH_Pos)));
}

/**
  * @brief   Включение модулятора блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_PC_Cmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->PCCTL_bit.CHPEN, State);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_TripZone Блок обработки сигналов аварии
  * @{
  */

void PWM_TZ_Init(PWM_TypeDef* PWMx, PWM_TZ_Init_TypeDef* InitStruct);
void PWM_TZ_StructInit(PWM_TZ_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка поведения канала A при поступлении сигнала аварии
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_ActionAConfig(PWM_TypeDef* PWMx, PWM_TZ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_ACTION(Action));

    WRITE_REG(PWMx->TZCTL_bit.TZA, Action);
}

/**
  * @brief   Настройка поведения канала B при поступлении сигнала аварии
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Action  Выбор действия
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_ActionBConfig(PWM_TypeDef* PWMx, PWM_TZ_Action_TypeDef Action)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_ACTION(Action));

    WRITE_REG(PWMx->TZCTL_bit.TZB, Action);
}

/**
  * @brief   Включение циклической обработки сигнала аварии
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_CycleCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->TZSEL_bit.CBC, State);
}

/**
  * @brief   Включение однократной обработки сигнала аварии
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_OneShotCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->TZSEL_bit.OST, State);
}

/**
  * @brief   Включение прерывания по сигналу аварии
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источника прерывания
  *                    Параметр принимает любую совокупность значений из @ref PWM_TZ_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_ITCmd(PWM_TypeDef* PWMx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(PWMx->TZEINT, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Чтение статуса флага прерывания от обработчика сигналов аварии выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref PWM_TZ_ITSource_Define.
  * @retval  Status  Статус прерывания. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus PWM_TZ_ITStatus(PWM_TypeDef* PWMx, uint32_t ITStatus)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(PWMx->TZFLG, ITStatus);
}

/**
  * @brief   Сброс флага прерывания от обработчика сигналов аварии выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флагов.
  *                    Параметр принимает любую совокупность значений из @ref PWM_TZ_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_ITStatusClear(PWM_TypeDef* PWMx, uint32_t ITStatus)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_STATUS(ITStatus));

    WRITE_REG(PWMx->TZCLR, ITStatus);
}

/**
  * @brief   Чтение статуса активного запроса прерывания от обработчика сигналов аварии выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Status  Статус запроса прерывания
  */
__STATIC_INLINE FlagStatus PWM_TZ_ITPendStatus(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return (FlagStatus)READ_BIT(PWMx->TZINTCLR, PWM_TZINTCLR_INT_Msk);
}

/**
  * @brief  Сброс активного запроса прерывания от обработчика сигналов аварии выбранного блока ШИМ
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval Нет
  */
__STATIC_INLINE void PWM_TZ_ITPendStatusClear(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->TZINTCLR_bit.INT, 1);
}

/**
  * @brief   Программный вызов прерывания от обработчика сигналов аварии выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источника прерывания
  *                    Параметр принимает любую совокупность значений из @ref PWM_TZ_ITSource_Define
  * @retval  void
  */
__STATIC_INLINE void PWM_TZ_ITForceCmd(PWM_TypeDef* PWMx, uint32_t ITSource)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_TZ_IT_SOURCE(ITSource));

    WRITE_REG(PWMx->TZFRC, ITSource);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_EventTrigger Генерация внешних сигналов
  * @{
  */

void PWM_ET_Init(PWM_TypeDef* PWMx, PWM_ET_Init_TypeDef* InitStruct);
void PWM_ET_StructInit(PWM_ET_Init_TypeDef* InitStruct);

/**
  * @brief   Включение генерации строба запуска АЦП по событию канала A
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCACmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->ETSEL_bit.SOCAEN, State);
}

/**
  * @brief   Настройка события канала A для генерации строба запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCAEventConfig(PWM_TypeDef* PWMx, PWM_ET_Event_TypeDef Event)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_EVENT(Event));

    WRITE_REG(PWMx->ETSEL_bit.SOCASEL, Event);
}

/**
  * @brief   Настройка количества событий канала A для генерации строба запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Выбор количества событий для возникновения строба АЦП.
                        Параметр принимает любое значение из диапазона 0-3,
                        где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCAPeriodConfig(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_PERIOD(PeriodVal));

    WRITE_REG(PWMx->ETPS_bit.SOCAPRD, PeriodVal);
}

/**
  * @brief   Получение текущего значения счетчика событий, приводящих к генерации события запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_ET_GetEventCountSOCA(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->ETPS_bit.SOCACNT);
}

/**
  * @brief   Включение генерации строба запуска АЦП по событию канала B
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCBCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->ETSEL_bit.SOCBEN, State);
}

/**
  * @brief   Настройка события канала B для генерации строба запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCBEventConfig(PWM_TypeDef* PWMx, PWM_ET_Event_TypeDef Event)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_EVENT(Event));

    WRITE_REG(PWMx->ETSEL_bit.SOCBSEL, Event);
}

/**
  * @brief   Настройка количества событий канала B для генерации строба запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Выбор количества событий для возникновения строба АЦП.
                        Параметр принимает любое значение из диапазона 0-3,
                        где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_SOCBPeriodConfig(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_PERIOD(PeriodVal));

    WRITE_REG(PWMx->ETPS_bit.SOCBPRD, PeriodVal);
}

/**
  * @brief   Получение текущего значения счетчика событий, приводящих к генерации события запуска АЦП
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_ET_GetEventCountSOCB(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->ETPS_bit.SOCBCNT);
}

/**
  * @brief   Включение генерации запроса DMA по событию канала A
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQACmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->ETSEL_bit.DRQAEN, State);
}

/**
  * @brief   Настройка события канала A для генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQAEventConfig(PWM_TypeDef* PWMx, PWM_ET_Event_TypeDef Event)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_EVENT(Event));

    WRITE_REG(PWMx->ETSEL_bit.DRQASEL, Event);
}

/**
  * @brief   Настройка количества событий канала A для генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Выбор количества событий для возникновения запроса DMA.
                        Параметр принимает любое значение из диапазона 0-3,
                        где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQAPeriodConfig(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_PERIOD(PeriodVal));

    WRITE_REG(PWMx->ETPS_bit.DRQAPRD, PeriodVal);
}

/**
  * @brief   Получение текущего значения счетчика событий, приводящих к генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_ET_GetEventCountDRQA(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->ETPS_bit.DRQACNT);
}

/**
  * @brief   Включение генерации запроса DMA по событию канала B
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQBCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->ETSEL_bit.DRQBEN, State);
}

/**
  * @brief   Настройка события канала B для генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQBEventConfig(PWM_TypeDef* PWMx, PWM_ET_Event_TypeDef Event)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_EVENT(Event));

    WRITE_REG(PWMx->ETSEL_bit.DRQBSEL, Event);
}

/**
  * @brief   Настройка количества событий канала B для генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Выбор количества событий для возникновения запроса DMA.
                        Параметр принимает любое значение из диапазона 0-3,
                        где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_DRQBPeriodConfig(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_PERIOD(PeriodVal));

    WRITE_REG(PWMx->ETPS_bit.DRQBPRD, PeriodVal);
}

/**
  * @brief   Получение текущего значения счетчика событий, приводящих к генерации запроса DMA
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_ET_GetEventCountDRQB(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->ETPS_bit.DRQBCNT);
}

/**
  * @brief   Чтение статусов флагов генерации внешних сигналов/запросов выбранным блоком ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любую совокупность значений из @ref PWM_ET_Status_Define.
  * @retval  Status  Статус. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus PWM_ET_Status(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(Status));

    return (FlagStatus)READ_BIT(PWMx->ETFLG, Status);
}

/**
  * @brief   Сброс флагов генерации внешних сигналов/запросов выбранным блоком ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любую совокупность значений из @ref PWM_ET_Status_Define.
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_StatusClear(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(Status));

    WRITE_REG(PWMx->ETCLR, Status);
}

/**
  * @brief   Программный вызов генерации внешних сигналов/запросов выбранным блоком ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Status  Выбор источника.
  *                  Параметр принимает любую совокупность значений из @ref PWM_ET_Status_Define
  * @retval  void
  */
__STATIC_INLINE void PWM_ET_ForceCmd(PWM_TypeDef* PWMx, uint32_t Status)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_STATUS(Status));

    WRITE_REG(PWMx->ETFRC, Status);
}

/**
  * @}
  */

/** @defgroup PWM_Exported_Functions_IT Прерывание счетчика ШИМ
  * @{
  */

/**
  * @brief   Настройка события канала для генерации прерывания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   Event  Выбор события
  * @retval  void
  */
__STATIC_INLINE void PWM_ITEventConfig(PWM_TypeDef* PWMx, PWM_ET_Event_TypeDef Event)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_EVENT(Event));

    WRITE_REG(PWMx->ETSEL_bit.INTSEL, Event);
}

/**
  * @brief   Настройка количества событий для генерации прерывания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Выбор количества событий для возникновения прерывания
                        Параметр принимает любое значение из диапазона 0-3,
                        где 0 - соответсвует каждому событию, 1 - каждому второму и т.д.
  * @retval  void
  */
__STATIC_INLINE void PWM_ITPeriodConfig(PWM_TypeDef* PWMx, uint32_t PeriodVal)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_PWM_ET_PERIOD(PeriodVal));

    WRITE_REG(PWMx->ETPS_bit.INTPRD, PeriodVal);
}

/**
  * @brief   Включение генерации прерывания ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void PWM_ITCmd(PWM_TypeDef* PWMx, FunctionalState State)
{
    assert_param(IS_PWM_PERIPH(PWMx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(PWMx->ETSEL_bit.INTEN, State);
}

/**
  * @brief   Получение текущего значения счетчика событий, приводящих к генерации прерывания
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t PWM_GetITEventCount(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return READ_REG(PWMx->ETPS_bit.INTCNT);
}

/**
  * @brief   Чтение статуса флага прерывания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus PWM_ITStatus(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return (FlagStatus)READ_BIT(PWMx->ETFLG, PWM_ETFRC_INT_Msk);
}

/**
  * @brief   Сброс флагов прерывания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void PWM_ITStatusClear(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->ETCLR, PWM_ETCLR_INT_Msk);
}

/**
  * @brief   Чтение статуса флага активного прерывания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus PWM_ITPendStatus(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    return (FlagStatus)READ_BIT(PWMx->INTCLR, PWM_INTCLR_INT_Msk);
}

/**
  * @brief   Сброс флагов активного прерывания выбранного блока ШИМ
  * @param   PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void PWM_ITPendStatusClear(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->INTCLR, PWM_INTCLR_INT_Msk);
}

/**
  * @brief  Программный вызов прерывания выбранного блока ШИМ
  * @param  PWMx  Выбор PWM, где x лежит в диапазоне 0-2
  * @retval Нет
  */
__STATIC_INLINE void PWM_ITForceCmd(PWM_TypeDef* PWMx)
{
    assert_param(IS_PWM_PERIPH(PWMx));

    WRITE_REG(PWMx->ETFRC, PWM_ETFRC_INT_Msk);
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

#endif /* __PLIB035_PWM_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
