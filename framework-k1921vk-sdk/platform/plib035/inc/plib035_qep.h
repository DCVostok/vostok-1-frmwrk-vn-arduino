/**
  ******************************************************************************
  * @file    plib035_qep.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          QEP, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB035_QEP_H
#define __PLIB035_QEP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup QEP
  * @brief Драйвер для работы с QEP
  * @{
  */

/** @defgroup QEP_Exported_Defines Константы
  * @{
  */

/** @defgroup QEP_Flag_Define Флаги работы QEP
  * @{
  */

#define QEP_Flag_PCError QEP_QEPSTS_PCEF_Msk             /*!< Флаг ошибки счетчика позиции. Обновляется  по каждому сигналу индексации. */
#define QEP_Flag_FirstIndex QEP_QEPSTS_FIMF_Msk          /*!< Флаг приема первого импульса сигнала индексации */
#define QEP_Flag_CAPDirectionError QEP_QEPSTS_CDEF_Msk   /*!< Флаг ошибки изменения направления вращения вала ротора между двумя событиями захвата */
#define QEP_Flag_CAPCountOverflow QEP_QEPSTS_COEF_Msk    /*!< Флаг переполнения счетчика модуля захвата */
#define QEP_Flag_QuadDirectionI QEP_QEPSTS_QDLF_Msk      /*!< Флаг направления вращения. Обновляется по каждому сигналу индексации. */
#define QEP_Flag_QuadDirection QEP_QEPSTS_QDF_Msk        /*!< Флаг направления вращения. Обновляется по каждому событию на входах квадратур. */
#define QEP_Flag_FirstIndexDirection QEP_QEPSTS_FIDF_Msk /*!< Индикатор направления вращения по событию первого импульса индексации. */
#define QEP_Flag_CAPEvent QEP_QEPSTS_UPEVNT_Msk          /*!< Флаг события захвата */
#define QEP_Flag_DirectionChange QEP_QEPSTS_DCF_Msk      /*!< Флаг изменения направления вращения вала ротора */
#define QEP_Flag_All (QEP_Flag_PCError |             \
                      QEP_Flag_FirstIndex |          \
                      QEP_Flag_CAPDirectionError |   \
                      QEP_Flag_CAPCountOverflow |    \
                      QEP_Flag_QuadDirectionI |      \
                      QEP_Flag_QuadDirection |       \
                      QEP_Flag_FirstIndexDirection | \
                      QEP_Flag_CAPEvent |            \
                      QEP_Flag_DirectionChange) /*!< Все флаги выбраны */

#define IS_QEP_FLAG(VALUE) (((VALUE) & ~QEP_Flag_All) == 0)

/**
  * @}
  */

/** @defgroup QEP_ITStatus_Define Флаги прерываний
  * @{
  */

#define QEP_ITStatus_GeneralInt QEP_QFLG_INT_Msk      /*!< Флаг общего сигнала прерывания */
#define QEP_ITStatus_PCError QEP_QFLG_PCE_Msk         /*!< Флаг прерывания по ошибке счетчика позиции */
#define QEP_ITStatus_QuadPhaseError QEP_QFLG_QPE_Msk  /*!< Флаг прерывания по ошибке фазы на квадратурном входе */
#define QEP_ITStatus_DirectionChange QEP_QFLG_QDC_Msk /*!< Флаг прерывания по смене направления вращения */
#define QEP_ITStatus_Watchdog QEP_QFLG_WTO_Msk        /*!< Флаг прерывания по срабатыванию сторожевого таймера */
#define QEP_ITStatus_PCOverflow QEP_QFLG_PCO_Msk      /*!< Флаг прерывания по переполнению счетчика позиции (переход через максимальное значение) */
#define QEP_ITStatus_PCUnderflow QEP_QFLG_PCU_Msk     /*!< Флаг прерывания по недозаполнению счетчика позиции (переход через минимальное значение) */
#define QEP_ITStatus_CMPShadowReady QEP_QFLG_PCR_Msk  /*!< Флаг прерывания по готовности компаратора к загрузке значения сравнения из отложенного регистра */
#define QEP_ITStatus_CMP QEP_QFLG_PCM_Msk             /*!< Флаг прерывания по срабатыванию компаратора */
#define QEP_ITStatus_Strobe QEP_QFLG_SEL_Msk          /*!< Флаг прерывания по событию стробирования */
#define QEP_ITStatus_Index QEP_QFLG_IEL_Msk           /*!< Флаг прерывания по событию индексации */
#define QEP_ITStatus_TMR QEP_QFLG_UTO_Msk             /*!< Флаг прерывания по таймера временных отсчетов */
#define QEP_ITStatus_All (QEP_ITStatus_GeneralInt |      \
                          QEP_ITStatus_PCError |         \
                          QEP_ITStatus_QuadPhaseError |  \
                          QEP_ITStatus_DirectionChange | \
                          QEP_ITStatus_Watchdog |        \
                          QEP_ITStatus_PCOverflow |      \
                          QEP_ITStatus_PCUnderflow |     \
                          QEP_ITStatus_CMPShadowReady |  \
                          QEP_ITStatus_CMP |             \
                          QEP_ITStatus_Strobe |          \
                          QEP_ITStatus_Index |           \
                          QEP_ITStatus_TMR) /*!< Все флаги выбраны */

#define IS_QEP_IT_STATUS(VALUE) (((VALUE) & ~QEP_ITStatus_All) == 0)

/**
  * @}
  */

/** @defgroup QEP_ITSource_Define Источники прерываний
  * @{
  */

#define QEP_ITSource_PCError QEP_QEINT_PCE_Msk         /*!< Прерывание по ошибке счетчика позиции */
#define QEP_ITSource_QuadPhaseError QEP_QEINT_QPE_Msk  /*!< Прерывание по ошибке фазы на квадратурном входе */
#define QEP_ITSource_DirectionChange QEP_QEINT_QDC_Msk /*!< Прерывание по смене направления вращения */
#define QEP_ITSource_Watchdog QEP_QEINT_WTO_Msk        /*!< Прерывание по срабатыванию сторожевого таймера */
#define QEP_ITSource_PCOverflow QEP_QEINT_PCO_Msk      /*!< Прерывание по переполнению счетчика позиции (переход через максимальное значение) */
#define QEP_ITSource_PCUnderflow QEP_QEINT_PCU_Msk     /*!< Прерывание по недозаполнению счетчика позиции (переход через минимальное значение) */
#define QEP_ITSource_CMPShadowReady QEP_QEINT_PCR_Msk  /*!< Прерывание по готовности компаратора к загрузке значения сравнения из отложенного регистра */
#define QEP_ITSource_CMP QEP_QEINT_PCM_Msk             /*!< Прерывание по срабатыванию компаратора */
#define QEP_ITSource_Strobe QEP_QEINT_SEL_Msk          /*!< Прерывание по событию стробирования */
#define QEP_ITSource_Index QEP_QEINT_IEL_Msk           /*!< Прерывание по событию индексации */
#define QEP_ITSource_TMR QEP_QEINT_UTO_Msk             /*!< Прерывание по таймера временных отсчетов */
#define QEP_ITSource_All (QEP_ITSource_PCError |         \
                          QEP_ITSource_QuadPhaseError |  \
                          QEP_ITSource_DirectionChange | \
                          QEP_ITSource_Watchdog |        \
                          QEP_ITSource_PCOverflow |      \
                          QEP_ITSource_PCUnderflow |     \
                          QEP_ITSource_CMPShadowReady |  \
                          QEP_ITSource_CMP |             \
                          QEP_ITSource_Strobe |          \
                          QEP_ITSource_Index |           \
                          QEP_ITSource_TMR) /*!< Все источники выбраны */

#define IS_QEP_IT_SOURCE(VALUE) (((VALUE) & ~QEP_ITSource_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup QEP_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор режима остановки таймеров QEP при отладке
  */
typedef enum {
    QEP_Halt_Stop = QEP_QEPCTL_FREESOFT_Stop,                /*!< Принудительная остановка */
    QEP_Halt_StopOnOverflow = QEP_QEPCTL_FREESOFT_StopAtOvf, /*!< Остановка после переполнения */
    QEP_Halt_Free = QEP_QEPCTL_FREESOFT_Free                 /*!< Без остановки */
} QEP_Halt_TypeDef;
#define IS_QEP_HALT(VALUE) (((VALUE) == QEP_Halt_Stop) ||           \
                            ((VALUE) == QEP_Halt_StopOnOverflow) || \
                            ((VALUE) == QEP_Halt_Free))

/**
  * @brief  Режим счёта
  */
typedef enum {
    QEP_PC_Mode_Quad = QEP_QDECCTL_QSRC_Quad,         /*!< Квадратурный режим счета */
    QEP_PC_Mode_CountDir = QEP_QDECCTL_QSRC_CountDir, /*!< Режим счета-направления */
    QEP_PC_Mode_CountUp = QEP_QDECCTL_QSRC_Up,        /*!< Счет вверх */
    QEP_PC_Mode_CountDown = QEP_QDECCTL_QSRC_Down     /*!< Счет вниз */
} QEP_PC_Mode_TypeDef;
#define IS_QEP_PC_MODE(VALUE) (((VALUE) == QEP_PC_Mode_Quad) ||     \
                               ((VALUE) == QEP_PC_Mode_CountDir) || \
                               ((VALUE) == QEP_PC_Mode_CountUp) ||  \
                               ((VALUE) == QEP_PC_Mode_CountDown))

/**
  * @brief  Выбор скорости счета для режимов счета вверх или вниз
  */
typedef enum {
    QEP_PC_CountRate_Single, /*!< Счет по переднему фронту */
    QEP_PC_CountRate_Double  /*!< Счет по обоим перепадам */
} QEP_PC_CountRate_TypeDef;
#define IS_QEP_PC_COUNT_RATE(VALUE) (((VALUE) == QEP_PC_CountRate_Single) || \
                                     ((VALUE) == QEP_PC_CountRate_Double))

/**
  * @brief  Выбор события для сброса счетчика позиции
  */
typedef enum {
    QEP_PC_ResetEvent_Index = QEP_QEPCTL_PCRM_Ind,           /*!< Событие индексации */
    QEP_PC_ResetEvent_CountMax = QEP_QEPCTL_PCRM_PosMax,     /*!< Достижение счетчиком максимального значения */
    QEP_PC_ResetEvent_FirstIndex = QEP_QEPCTL_PCRM_FirstInd, /*!< Первое событие индексации */
    QEP_PC_ResetEvent_TMR = QEP_QEPCTL_PCRM_Time             /*!< Окончание временного отсчета */
} QEP_PC_ResetEvent_TypeDef;
#define IS_QEP_PC_RESET_EVENT(VALUE) (((VALUE) == QEP_PC_ResetEvent_Index) ||      \
                                      ((VALUE) == QEP_PC_ResetEvent_CountMax) ||   \
                                      ((VALUE) == QEP_PC_ResetEvent_FirstIndex) || \
                                      ((VALUE) == QEP_PC_ResetEvent_TMR))

/**
  * @brief  Выбор события стробирования для инициализации счетчика позиции
  */
typedef enum {
    QEP_PC_InitEventS_None = QEP_QEPCTL_SEI_NoInit,            /*!< Без инициализации */
    QEP_PC_InitEventS_Rise = QEP_QEPCTL_SEI_QEPSPos,           /*!< По переднему фронту S */
    QEP_PC_InitEventS_UpRiseDownFall = QEP_QEPCTL_SEI_QEPSDir, /*!< По переднему фронту S при счете вверх (вращение по часовой, вперед)
                                                                    и по заднему фронту S при счете вниз (вращение против часовой, назад) */
} QEP_PC_InitEventS_TypeDef;
#define IS_QEP_PC_INIT_EVENT_S(VALUE) (((VALUE) == QEP_PC_InitEventS_None) || \
                                       ((VALUE) == QEP_PC_InitEventS_Rise) || \
                                       ((VALUE) == QEP_PC_InitEventS_UpRiseDownFall))

/**
  * @brief  Выбор события индексации для инициализации счетчика позиции
  */
typedef enum {
    QEP_PC_InitEventI_None = QEP_QEPCTL_IEI_NoInit,  /*!< Без инициализации */
    QEP_PC_InitEventI_Rise = QEP_QEPCTL_IEI_QEPIPos, /*!< По переднему фронту I */
    QEP_PC_InitEventI_Fall = QEP_QEPCTL_IEI_QEPINeg, /*!< По заднему фронту I */
} QEP_PC_InitEventI_TypeDef;
#define IS_QEP_PC_INIT_EVENT_I(VALUE) (((VALUE) == QEP_PC_InitEventI_None) || \
                                       ((VALUE) == QEP_PC_InitEventI_Rise) || \
                                       ((VALUE) == QEP_PC_InitEventI_Fall))

/**
  * @brief  Выбор события стробирования для сохранения значения счетчика позиции
  */
typedef enum {
    QEP_PC_LatchEventS_Rise,           /*!< По переднему фронту S */
    QEP_PC_LatchEventS_UpRiseDownFall, /*!< По переднему фронту S при счете вверх (вращение по часовой, вперед)
                                           и по заднему фронту S при счете вниз (вращение против часовой, назад) */
} QEP_PC_LatchEventS_TypeDef;
#define IS_QEP_PC_LATCH_EVENT_S(VALUE) (((VALUE) == QEP_PC_LatchEventS_Rise) || \
                                        ((VALUE) == QEP_PC_LatchEventS_UpRiseDownFall))

/**
  * @brief  Выбор события индексации для сохранения значения счетчика позиции
  */
typedef enum {
    QEP_PC_LatchEventI_None = QEP_QEPCTL_IEL_NoLatch,  /*!< Без сохранения */
    QEP_PC_LatchEventI_Rise = QEP_QEPCTL_IEL_IndPos,   /*!< По переднему фронту I */
    QEP_PC_LatchEventI_Fall = QEP_QEPCTL_IEL_IndNeg,   /*!< По заднему фронту I */
    QEP_PC_LatchEventI_Marker = QEP_QEPCTL_IEL_IndMark /*!< По маркеру индексации */
} QEP_PC_LatchEventI_TypeDef;
#define IS_QEP_PC_LATCH_EVENT_I(VALUE) (((VALUE) == QEP_PC_LatchEventI_None) || \
                                        ((VALUE) == QEP_PC_LatchEventI_Rise) || \
                                        ((VALUE) == QEP_PC_LatchEventI_Fall) || \
                                        ((VALUE) == QEP_PC_LatchEventI_Marker))

/**
  * @brief  Выбор события загрузки для отложенной записи значения сравнения счетчика позиции
  */
typedef enum {
    QEP_CMP_LoadEvent_PCCountEqZero, /*!< Загрузка по равенству счетчика позиции нулю */
    QEP_CMP_LoadEvent_PCCountEqComp  /*!< Загрузка по равенству счетчика позиции значению сравнения */
} QEP_CMP_LoadEvent_TypeDef;
#define IS_QEP_CMP_LOAD_EVENT(VALUE) (((VALUE) == QEP_CMP_LoadEvent_PCCountEqZero) || \
                                      ((VALUE) == QEP_CMP_LoadEvent_PCCountEqComp))

/**
  * @brief  Выбор вывода для выдачи выходного сигнала компаратора
  */
typedef enum {
    QEP_CMP_Out_S, /*!< Вывод сигнала строба */
    QEP_CMP_Out_I  /*!< Вывод сигнала индекса */
} QEP_CMP_Out_TypeDef;
#define IS_QEP_CMP_OUT(VALUE) (((VALUE) == QEP_CMP_Out_S) || \
                               ((VALUE) == QEP_CMP_Out_I))

/**
  * @brief  Выбор полярности выходного сигнала компаратора счетчика позиции
  */
typedef enum {
    QEP_CMP_OutPolarity_ActiveHigh, /*!< Активная единица */
    QEP_CMP_OutPolarity_ActiveLow,  /*!< Активный ноль */
} QEP_CMP_OutPolarity_TypeDef;
#define IS_QEP_CMP_OUT_POLARITY(VALUE) (((VALUE) == QEP_CMP_OutPolarity_ActiveHigh) || \
                                        ((VALUE) == QEP_CMP_OutPolarity_ActiveLow))

/**
  * @brief  Выбор события для сброса таймера захвата
  */
typedef enum {
    QEP_CAP_ResetEvent_QCLKDiv, /*!< Деленное квадратурное событие */
    QEP_CAP_ResetEvent_CMPOut   /*!< Выходной сигнал компаратора счетчика позиции */
} QEP_CAP_ResetEvent_TypeDef;
#define IS_QEP_CAP_RESET_EVENT(VALUE) (((VALUE) == QEP_CAP_ResetEvent_QCLKDiv) || \
                                       ((VALUE) == QEP_CAP_ResetEvent_CMPOut))

/**
  * @brief  Коэффициент деления тактового сигнала PCLK для таймера захвата
  */
typedef enum {
    QEP_CAP_PCLKDiv_1 = QEP_QCAPCTL_CCPS_Disable, /*!< Без деления тактовой частоты */
    QEP_CAP_PCLKDiv_2 = QEP_QCAPCTL_CCPS_Div2,    /*!< Деление тактовой частоты на 2 */
    QEP_CAP_PCLKDiv_4 = QEP_QCAPCTL_CCPS_Div4,    /*!< Деление тактовой частоты на 4 */
    QEP_CAP_PCLKDiv_8 = QEP_QCAPCTL_CCPS_Div8,    /*!< Деление тактовой частоты на 8 */
    QEP_CAP_PCLKDiv_16 = QEP_QCAPCTL_CCPS_Div16,  /*!< Деление тактовой частоты на 16 */
    QEP_CAP_PCLKDiv_32 = QEP_QCAPCTL_CCPS_Div32,  /*!< Деление тактовой частоты на 32 */
    QEP_CAP_PCLKDiv_64 = QEP_QCAPCTL_CCPS_Div64,  /*!< Деление тактовой частоты на 64 */
    QEP_CAP_PCLKDiv_128 = QEP_QCAPCTL_CCPS_Div128 /*!< Деление тактовой частоты на 128 */
} QEP_CAP_PCLKDiv_TypeDef;
#define IS_QEP_CAP_PCLK_DIV(VALUE) (((VALUE) == QEP_CAP_PCLKDiv_1) ||  \
                                    ((VALUE) == QEP_CAP_PCLKDiv_2) ||  \
                                    ((VALUE) == QEP_CAP_PCLKDiv_4) ||  \
                                    ((VALUE) == QEP_CAP_PCLKDiv_8) ||  \
                                    ((VALUE) == QEP_CAP_PCLKDiv_16) || \
                                    ((VALUE) == QEP_CAP_PCLKDiv_32) || \
                                    ((VALUE) == QEP_CAP_PCLKDiv_64) || \
                                    ((VALUE) == QEP_CAP_PCLKDiv_128))

/**
  * @brief  Коэффициент деления квадратурных событий
  */
typedef enum {
    QEP_CAP_QCLKDiv_1 = QEP_QCAPCTL_UPPS_Disable,    /*!< Без деления квадратурных событий */
    QEP_CAP_QCLKDiv_2 = QEP_QCAPCTL_UPPS_Div2,       /*!< Деление квадратурных событий на 2 */
    QEP_CAP_QCLKDiv_4 = QEP_QCAPCTL_UPPS_Div4,       /*!< Деление квадратурных событий на 4 */
    QEP_CAP_QCLKDiv_8 = QEP_QCAPCTL_UPPS_Div8,       /*!< Деление квадратурных событий на 8 */
    QEP_CAP_QCLKDiv_16 = QEP_QCAPCTL_UPPS_Div16,     /*!< Деление квадратурных событий на 16 */
    QEP_CAP_QCLKDiv_32 = QEP_QCAPCTL_UPPS_Div32,     /*!< Деление квадратурных событий на 32 */
    QEP_CAP_QCLKDiv_64 = QEP_QCAPCTL_UPPS_Div64,     /*!< Деление квадратурных событий на 64 */
    QEP_CAP_QCLKDiv_128 = QEP_QCAPCTL_UPPS_Div128,   /*!< Деление квадратурных событий на 128 */
    QEP_CAP_QCLKDiv_256 = QEP_QCAPCTL_UPPS_Div256,   /*!< Деление квадратурных событий на 64 */
    QEP_CAP_QCLKDiv_512 = QEP_QCAPCTL_UPPS_Div512,   /*!< Деление квадратурных событий на 128 */
    QEP_CAP_QCLKDiv_1024 = QEP_QCAPCTL_UPPS_Div1024, /*!< Деление квадратурных событий на 64 */
    QEP_CAP_QCLKDiv_2048 = QEP_QCAPCTL_UPPS_Div2048, /*!< Деление квадратурных событий на 128 */
} QEP_CAP_QCLKDiv_TypeDef;
#define IS_QEP_CAP_QCLK_DIV(VALUE) (((VALUE) == QEP_CAP_QCLKDiv_1) ||    \
                                    ((VALUE) == QEP_CAP_QCLKDiv_2) ||    \
                                    ((VALUE) == QEP_CAP_QCLKDiv_4) ||    \
                                    ((VALUE) == QEP_CAP_QCLKDiv_8) ||    \
                                    ((VALUE) == QEP_CAP_QCLKDiv_16) ||   \
                                    ((VALUE) == QEP_CAP_QCLKDiv_32) ||   \
                                    ((VALUE) == QEP_CAP_QCLKDiv_64) ||   \
                                    ((VALUE) == QEP_CAP_QCLKDiv_128) ||  \
                                    ((VALUE) == QEP_CAP_QCLKDiv_256) ||  \
                                    ((VALUE) == QEP_CAP_QCLKDiv_512) ||  \
                                    ((VALUE) == QEP_CAP_QCLKDiv_1024) || \
                                    ((VALUE) == QEP_CAP_QCLKDiv_2048))

/**
  * @brief  Выбор события для сохранения значения регистров модуля захвата
  */
typedef enum {
    QEP_CAP_LatchEvent_ReadPCCount,     /*!< Чтение счетного регистра счетчика позиции */
    QEP_CAP_LatchEvent_TMRCountEqPeriod /*!< Равенство счетного регистра таймера периоду */
} QEP_CAP_LatchEvent_TypeDef;
#define IS_QEP_CAP_LATCH_EVENT(VALUE) (((VALUE) == QEP_CAP_LatchEvent_ReadPCCount) || \
                                       ((VALUE) == QEP_CAP_LatchEvent_TMRCountEqPeriod))

/**
  * @brief  Структура инициализации счётчика позиции
  */
typedef struct
{
    QEP_PC_Mode_TypeDef Mode;
    QEP_PC_CountRate_TypeDef CountRate;
    QEP_PC_ResetEvent_TypeDef ResetEvent;
    QEP_PC_InitEventS_TypeDef InitEventS;
    QEP_PC_InitEventI_TypeDef InitEventI;
    QEP_PC_LatchEventS_TypeDef LatchEventS;
    QEP_PC_LatchEventI_TypeDef LatchEventI;
    uint32_t Count;
    uint32_t CountInit;
    uint32_t CountMax;
} QEP_PC_Init_TypeDef;

/**
  * @brief  Структура инициализации компаратора счётчика позиции
  */
typedef struct
{
    FunctionalState ShadowLoad;
    QEP_CMP_LoadEvent_TypeDef LoadEvent;
    QEP_CMP_Out_TypeDef Out;
    FunctionalState OutEn;
    QEP_CMP_OutPolarity_TypeDef OutPolarity;
    uint32_t OutWidth;
    uint32_t Comp;
} QEP_CMP_Init_TypeDef;
#define IS_QEP_CMP_OUT_WIDTH_VAL(VALUE) ((VALUE) < 0x1000)

/**
  * @brief  Структура инициализации модуля захвата времени
  */
typedef struct
{
    FunctionalState DivShadowLoad;
    QEP_CAP_ResetEvent_TypeDef ResetEvent;
    QEP_CAP_PCLKDiv_TypeDef PCLKDiv;
    QEP_CAP_QCLKDiv_TypeDef QCLKDiv;
    QEP_CAP_LatchEvent_TypeDef LatchEvent;
    uint32_t Count;
    uint32_t Period;
} QEP_CAP_Init_TypeDef;

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions Функции
  * @{
  */

void QEP_DeInit(void);

/**
  * @brief   Разрешение работы выводов QEP
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_RemapCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(SIU->REMAPAF_bit.QEPEN, State);
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений QEP_Flag_x из @ref QEP_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_FlagStatus(uint32_t Flag)
{
    assert_param(IS_QEP_FLAG(Flag));

    return (FlagStatus)READ_BIT(QEP->QEPSTS, Flag);
}

/**
  * @brief   Сброс флагов
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любою совокупность значений из @ref QEP_Flag_Define.
  * @retval  void
  */
__STATIC_INLINE void QEP_FlagStatusClear(uint32_t Flag)
{
    assert_param(IS_QEP_FLAG(Flag));

    WRITE_REG(QEP->QEPSTS, Flag);
}

/**
  * @brief   Настройка режима остановки всех счетчиков таймеров QEP
  * @param   Halt  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_HaltConfig(QEP_Halt_TypeDef Halt)
{
    assert_param(IS_QEP_HALT(Halt));

    WRITE_REG(QEP->QEPCTL_bit.FREESOFT, Halt);
}

/** @defgroup QEP_Exported_Functions_IO Управление входами
  * @{
  */

/**
  * @brief   Включение обмена входов A и B местами
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_SwapABCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.SWAP, State);
}

/**
  * @brief   Включение стробирования сигнала индекса
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_GateICmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.IGATE, State);
}

/**
  * @brief   Включение инверсии входа A
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvACmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.QAP, State);
}

/**
  * @brief   Включение инверсии входа B
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvBCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.QBP, State);
}

/**
  * @brief   Включение инверсии входа I (индекса)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvICmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.QIP, State);
}

/**
  * @brief   Включение инверсии входа S (строба)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvSCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.QSP, State);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_PositionCounter Счётчик позиции
  * @{
  */

void QEP_PC_Init(QEP_PC_Init_TypeDef* InitStruct);
void QEP_PC_StructInit(QEP_PC_Init_TypeDef* InitStruct);

/**
  * @brief   Включение счётчика позиции
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QEPCTL_bit.QPEN, State);
}

/**
  * @brief   Настройка режима счета
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_ModeConfig(QEP_PC_Mode_TypeDef Mode)
{
    assert_param(IS_QEP_PC_MODE(Mode));

    WRITE_REG(QEP->QDECCTL_bit.QSRC, Mode);
}

/**
  * @brief   Настройка скорости счета для режимов счета вверх или вниз
  * @param   CountRate  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_CountRateConfig(QEP_PC_CountRate_TypeDef CountRate)
{
    assert_param(IS_QEP_PC_COUNT_RATE(CountRate));

    WRITE_REG(QEP->QDECCTL_bit.XCR, CountRate);
}

/**
  * @brief   Настройка события для сброса счетчика позиции
  * @param   ResetEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_ResetEventConfig(QEP_PC_ResetEvent_TypeDef ResetEvent)
{
    assert_param(IS_QEP_PC_RESET_EVENT(ResetEvent));

    WRITE_REG(QEP->QEPCTL_bit.PCRM, ResetEvent);
}

/**
  * @brief   Настройка события стробирования для инициализации счетчика позиции
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_InitEventSConfig(QEP_PC_InitEventS_TypeDef InitEvent)
{
    assert_param(IS_QEP_PC_INIT_EVENT_S(InitEvent));

    WRITE_REG(QEP->QEPCTL_bit.SEI, InitEvent);
}

/**
  * @brief   Настройка события индексации для инициализации счетчика позиции
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_InitEventIConfig(QEP_PC_InitEventI_TypeDef InitEvent)
{
    assert_param(IS_QEP_PC_INIT_EVENT_I(InitEvent));

    WRITE_REG(QEP->QEPCTL_bit.IEI, InitEvent);
}

/**
  * @brief   Выполнение программной инициализации счетчика позиции
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SwInitCmd(void)
{
    WRITE_REG(QEP->QEPCTL_bit.SWI, 1);
}

/**
  * @brief   Настройка события стробирования для сохранения счетчика позиции
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_LatchEventSConfig(QEP_PC_LatchEventS_TypeDef LatchEvent)
{
    assert_param(IS_QEP_PC_LATCH_EVENT_S(LatchEvent));

    WRITE_REG(QEP->QEPCTL_bit.SEL, LatchEvent);
}

/**
  * @brief   Настройка события индексации для сохранения счетчика позиции
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_LatchEventIConfig(QEP_PC_LatchEventI_TypeDef LatchEvent)
{
    assert_param(IS_QEP_PC_LATCH_EVENT_I(LatchEvent));

    WRITE_REG(QEP->QEPCTL_bit.IEL, LatchEvent);
}

/**
  * @brief   Установка значения счетчика позиции
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCount(uint32_t Val)
{
    WRITE_REG(QEP->QPOSCNT, Val);
}

/**
  * @brief   Получение текущего значения счетчика позиции
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCount(void)
{
    return READ_REG(QEP->QPOSCNT);
}

/**
  * @brief   Установка значения инициализации счетчика позиции
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCountInit(uint32_t Val)
{
    WRITE_REG(QEP->QPOSINIT, Val);
}

/**
  * @brief   Получение текущего значения инициализации счетчика позиции
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountInit(void)
{
    return READ_REG(QEP->QPOSINIT);
}

/**
  * @brief   Установка максимального значения счетчика позиции
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCountMax(uint32_t Val)
{
    WRITE_REG(QEP->QPOSMAX, Val);
}

/**
  * @brief   Получение текущего максимального значения счетчика позиции
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountMax(void)
{
    return READ_REG(QEP->QPOSMAX);
}

/**
  * @brief   Получение сохраненного значения счетчика позиции по стробу
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatchS(void)
{
    return READ_REG(QEP->QPOSSLAT);
}

/**
  * @brief   Получение сохраненного значения счетчика позиции по индексу
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatchI(void)
{
    return READ_REG(QEP->QPOSILAT);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_PositionCompare Компаратор
  * @{
  */

void QEP_CMP_Init(QEP_CMP_Init_TypeDef* InitStruct);
void QEP_CMP_StructInit(QEP_CMP_Init_TypeDef* InitStruct);

/**
  * @brief   Включение компаратора счётчика позиции
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QPOSCTL_bit.PCE, State);
}

/**
  * @brief   Включение отложенной загрузки компаратора счётчика позиции
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_ShadowLoadCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QPOSCTL_bit.PCSHDW, State);
}

/**
  * @brief   Настройка события для отложенной загрузки компаратора счётчика позиции
  * @param   LoadEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_LoadEventConfig(QEP_CMP_LoadEvent_TypeDef LoadEvent)
{
    assert_param(IS_QEP_CMP_LOAD_EVENT(LoadEvent));

    WRITE_REG(QEP->QPOSCTL_bit.PCLOAD, LoadEvent);
}

/**
  * @brief   Настройка вывода для выдачи выходного сигнала компаратора счётчика позиции
  * @param   Out  Выбор вывода
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutConfig(QEP_CMP_Out_TypeDef Out)
{
    assert_param(IS_QEP_CMP_OUT(Out));

    WRITE_REG(QEP->QDECCTL_bit.SPSEL, Out);
}

/**
  * @brief   Разрешение выходного сигнала компаратора счётчика позиции
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QDECCTL_bit.SOEN, State);
}

/**
  * @brief   Настройка полярности выходного сигнала компаратора счетчика позиции
  * @param   OutPolarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutPolarityConfig(QEP_CMP_OutPolarity_TypeDef OutPolarity)
{
    assert_param(IS_QEP_CMP_OUT_POLARITY(OutPolarity));

    WRITE_REG(QEP->QPOSCTL_bit.PCPOL, OutPolarity);
}

/**
  * @brief   Настройка ширигы импульса выходного сигнала компаратора счетчика позиции
  * @param   OutPolarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_SetOutWidth(uint32_t OutWidth)
{
    assert_param(IS_QEP_CMP_OUT_WIDTH_VAL(OutWidth));

    WRITE_REG(QEP->QPOSCTL_bit.PCSPW, OutWidth);
}

/**
  * @brief   Установка значения компаратора счетчика позиции
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_SetComp(uint32_t Val)
{
    WRITE_REG(QEP->QPOSCMP, Val);
}

/**
  * @brief   Получение текущего значения компаратора счетчика позиции
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CMP_GetComp(void)
{
    return READ_REG(QEP->QPOSCMP);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_CaptureTime Модуль захвата времени
  * @{
  */

void QEP_CAP_Init(QEP_CAP_Init_TypeDef* InitStruct);
void QEP_CAP_StructInit(QEP_CAP_Init_TypeDef* InitStruct);

/**
  * @brief   Включение модуля захвата времени
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QCAPCTL_bit.CEN, State);
}

/**
  * @brief   Включение теневой загрузки делителей модуля захвата времени
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DivShadowLoadCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QCAPCTL_bit.EPSLD, State);
}

/**
  * @brief   Настройка события сброса счетчика модуля захвата времени
  * @param   ResetEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_ResetEventConfig(QEP_CAP_ResetEvent_TypeDef ResetEvent)
{
    assert_param(IS_QEP_CAP_RESET_EVENT(ResetEvent));

    WRITE_REG(QEP->QCAPCTL_bit.SELEVENT, ResetEvent);
}

/**
  * @brief   Настройка делителей для модуля захвата времени
  * @param   PCLKDiv  Выбор делителя PCLK
  * @param   QCLKDiv  Выбор делителя QCLK
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DivConfig(QEP_CAP_PCLKDiv_TypeDef PCLKDiv, QEP_CAP_QCLKDiv_TypeDef QCLKDiv)
{
    assert_param(IS_QEP_CAP_PCLK_DIV(PCLKDiv));
    assert_param(IS_QEP_CAP_QCLK_DIV(QCLKDiv));

    MODIFY_REG(QEP->QCAPCTL, QEP_QCAPCTL_CCPS_Msk | QEP_QCAPCTL_UPPS_Msk,
               ((PCLKDiv << QEP_QCAPCTL_CCPS_Pos) | (QCLKDiv << QEP_QCAPCTL_UPPS_Pos)));
}

/**
  * @brief   Настройка делителя PCLK для модуля захвата времени
  * @param   PCLKDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_PCLKDivConfig(QEP_CAP_PCLKDiv_TypeDef PCLKDiv)
{
    assert_param(IS_QEP_CAP_PCLK_DIV(PCLKDiv));

    WRITE_REG(QEP->QCAPCTL_bit.CCPS, PCLKDiv);
}

/**
  * @brief   Настройка делителя QCLK для модуля захвата времени
  * @param   QCLKDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_QCLKDivConfig(QEP_CAP_QCLKDiv_TypeDef QCLKDiv)
{
    assert_param(IS_QEP_CAP_QCLK_DIV(QCLKDiv));

    WRITE_REG(QEP->QCAPCTL_bit.UPPS, QCLKDiv);
}

/**
  * @brief   Настройка события сохранения значения регистров модуля захвата
  * @param   LatchEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_LatchEventConfig(QEP_CAP_LatchEvent_TypeDef LatchEvent)
{
    assert_param(IS_QEP_CAP_LATCH_EVENT(LatchEvent));

    WRITE_REG(QEP->QEPCTL_bit.QCLM, LatchEvent);
}

/**
  * @brief   Установка значения счетчика модуля захвата
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_SetCount(uint32_t Val)
{
    WRITE_REG(QEP->QCTMR, Val);
}

/**
  * @brief   Получение текущего значения счетчика модуля захвата
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CAP_GetCount(void)
{
    return READ_REG(QEP->QCTMR);
}

/**
  * @brief   Установка значения периода модуля захвата
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_SetPeriod(uint32_t Val)
{
    WRITE_REG(QEP->QCPRD, Val);
}

/**
  * @brief   Получение текущего значения периода модуля захвата
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CAP_GetPeriod(void)
{
    return READ_REG(QEP->QCPRD);
}

/**
  * @brief   Получение сохраненного значения счетчика модуля захвата
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatch(void)
{
    return READ_REG(QEP->QCTMRLAT);
}

/**
  * @brief   Получение сохраненного значения периода модуля захвата
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetPeriodLatch(void)
{
    return READ_REG(QEP->QCPRDLAT);
}

/**
  * @brief   Включение генерации запроса DMA событию захвата
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DMACmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->DMAREQ_bit.DMAEN, State);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_UnitTimer Таймер временных отсчетов
  * @{
  */

/**
  * @brief   Включение таймера временных отсчетов
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QEPCTL_bit.UTE, State);
}

/**
  * @brief   Установка значения счетчика таймера временных отсчетов
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_SetCount(uint32_t Val)
{
    WRITE_REG(QEP->QUTMR, Val);
}

/**
  * @brief   Получение значения счетчика таймера временных отсчетов
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_TMR_GetCount(void)
{
    return READ_REG(QEP->QUTMR);
}

/**
  * @brief   Установка значения периода таймера временных отсчетов
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_SetPeriod(uint32_t Val)
{
    WRITE_REG(QEP->QUPRD, Val);
}

/**
  * @brief   Получение значения периода таймера временных отсчетов
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_TMR_GetPeriod(void)
{
    return READ_REG(QEP->QUPRD);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_Watchdog Сторожевой таймер
  * @{
  */

/**
  * @brief   Включение сторожевого таймера
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEP->QEPCTL_bit.WDE, State);
}

/**
  * @brief   Установка значения счетчика сторожевого таймера
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_SetCount(uint32_t Val)
{
    WRITE_REG(QEP->QWDTMR, Val);
}

/**
  * @brief   Получение значения счетчика сторожевого таймера
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_WDT_GetCount(void)
{
    return READ_REG(QEP->QWDTMR);
}

/**
  * @brief   Установка значения периода сторожевого таймера
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_SetPeriod(uint32_t Val)
{
    WRITE_REG(QEP->QWDPRD, Val);
}

/**
  * @brief   Получение значения периода сторожевого таймера
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_WDT_GetPeriod(void)
{
    return READ_REG(QEP->QWDPRD);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_IT Прерывания
  * @{
  */

/**
  * @brief   Разрешение генерации прерываний
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений QEP_ITSource_x из @ref QEP_ITSource_define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_ITCmd(uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_QEP_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(QEP->QEINT, ITSource, State ? (uint32_t)ITSource : 0);
}

/**
  * @brief   Принудительный вызов прерывания
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений QEP_ITSource_x из @ref QEP_ITSource_define.
  * @retval  void
  */
__STATIC_INLINE void QEP_ITForceCmd(uint32_t ITSource)
{
    assert_param(IS_QEP_IT_SOURCE(ITSource));

    WRITE_REG(QEP->QFRC, ITSource);
}

/**
  * @brief   Чтение статуса прерывания
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_ITStatus(uint32_t ITStatus)
{
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(QEP->QFLG, ITStatus);
}

/**
  * @brief   Чтение сохраненного статуса прерывания (сохранение каждый раз при чтении счетчика позиции)
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_ITStatusLatch(uint32_t ITStatus)
{
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(QEP->QFLG, ITStatus << QEP_QFLG_QFLGLAT_Pos);
}

/**
  * @brief   Сброс статуса прерывания
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_define.
  * @retval  void
  */
__STATIC_INLINE void QEP_ITStatusClear(uint32_t ITStatus)
{
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    WRITE_REG(QEP->QCLR, ITStatus);
}

/**
  * @brief   Чтение активного статуса прерывания
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus QEP_ITPendStatus(void)
{
    return (FlagStatus)READ_BIT(QEP->INTCLR, QEP_INTCLR_INT_Msk);
}

/**
  * @brief   Сброс активности прерывания
  * @retval  void
  */
__STATIC_INLINE void QEP_ITPendStatusClear(void)
{
    WRITE_REG(QEP->INTCLR, QEP_INTCLR_INT_Msk);
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

#endif /* __PLIB035_QEP_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
