/**
  ******************************************************************************
  * @file    plib028_qep.h
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
  * <h2><center>&copy; 2019 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB028_QEP_H
#define __PLIB028_QEP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

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
  * @brief  Выбор режима работы дополнительного входного фильтра
  */
typedef enum {
    QEP_QualMode_3Sample, /*!< Используется 3 отсчета для фильтрации */
    QEP_QualMode_6Sample  /*!< Используется 6 отсчетов для фильтрации */
} QEP_QualMode_TypeDef;
#define IS_QEP_QUAL_MODE(VALUE) (((VALUE) == QEP_QualMode_3Sample) || \
                                 ((VALUE) == QEP_QualMode_6Sample))

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

#define IS_QEP_QUAL_PERIOD(VALUE) (((VALUE)&0xFFFF0000) == 0)

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

void QEP_DeInit(QEP_TypeDef* QEPx);

/**
  * @brief   Настройка режима дополнительного входного фильтра QEP
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_QualModeConfig(QEP_TypeDef* QEPx, QEP_QualMode_TypeDef Mode)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_QUAL_MODE(Mode));

    if (QEPx == QEP0) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPMODE0_Msk, Mode << SIU_QCQUALCTL_QEPMODE0_Pos);
    } else if (QEPx == QEP1) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPMODE1_Msk, Mode << SIU_QCQUALCTL_QEPMODE1_Pos);
    } else if (QEPx == QEP2) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPMODE2_Msk, Mode << SIU_QCQUALCTL_QEPMODE2_Pos);
    } else /*if (QEPx == QEP3)*/ {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPMODE3_Msk, Mode << SIU_QCQUALCTL_QEPMODE3_Pos);
    }
}

/**
  * @brief   Настройка времени сэмплирования дополнительного входного фильтра
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   SamplePerod  Количество тактов системной частоты между отсчетами фильтра
  * @retval  void
  */
__STATIC_INLINE void QEP_QualSampleConfig(QEP_TypeDef* QEPx, uint32_t SamplePerod)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_QUAL_PERIOD(SamplePerod));

    WRITE_REG(SIU->QCQUALSAMPLE_bit.QEPVAL, SamplePerod);
}

/**
  * @brief   Включение дополнительного входного фильтра QEP
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_QualCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (QEPx == QEP0) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPEN0_Msk, (uint32_t)State << SIU_QCQUALCTL_QEPEN0_Pos);
    } else if (QEPx == QEP1) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPEN1_Msk, (uint32_t)State << SIU_QCQUALCTL_QEPEN1_Pos);
    } else if (QEPx == QEP2) {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPEN2_Msk, (uint32_t)State << SIU_QCQUALCTL_QEPEN2_Pos);
    } else /*if (QEPx == QEP3)*/ {
        MODIFY_REG(SIU->QCQUALCTL, SIU_QCQUALCTL_QEPEN3_Msk, (uint32_t)State << SIU_QCQUALCTL_QEPEN3_Pos);
    }
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений QEP_Flag_x из @ref QEP_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_FlagStatus(QEP_TypeDef* QEPx, uint32_t Flag)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_FLAG(Flag));

    return (FlagStatus)READ_BIT(QEPx->QEPSTS, Flag);
}

/**
  * @brief   Сброс флагов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Status  Выбор флагов.
  *                  Параметр принимает любою совокупность значений из @ref QEP_Flag_Define.
  * @retval  void
  */
__STATIC_INLINE void QEP_FlagStatusClear(QEP_TypeDef* QEPx, uint32_t Flag)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_FLAG(Flag));

    WRITE_REG(QEPx->QEPSTS, Flag);
}

/**
  * @brief   Настройка режима остановки всех счетчиков таймеров QEP
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Halt  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_HaltConfig(QEP_TypeDef* QEPx, QEP_Halt_TypeDef Halt)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_HALT(Halt));

    WRITE_REG(QEPx->QEPCTL_bit.FREESOFT, Halt);
}

/** @defgroup QEP_Exported_Functions_IO Управление входами
  * @{
  */

/**
  * @brief   Включение обмена входов A и B местами
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_SwapABCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.SWAP, State);
}

/**
  * @brief   Включение стробирования сигнала индекса
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_GateICmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.IGATE, State);
}

/**
  * @brief   Включение инверсии входа A
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvACmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.QAP, State);
}

/**
  * @brief   Включение инверсии входа B
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvBCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.QBP, State);
}

/**
  * @brief   Включение инверсии входа I (индекса)
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvICmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.QIP, State);
}

/**
  * @brief   Включение инверсии входа S (строба)
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_IO_InvSCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.QSP, State);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_PositionCounter Счётчик позиции
  * @{
  */

void QEP_PC_Init(QEP_TypeDef* QEPx, QEP_PC_Init_TypeDef* InitStruct);
void QEP_PC_StructInit(QEP_PC_Init_TypeDef* InitStruct);

/**
  * @brief   Включение счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_Cmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QEPCTL_bit.QPEN, State);
}

/**
  * @brief   Настройка режима счета
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_ModeConfig(QEP_TypeDef* QEPx, QEP_PC_Mode_TypeDef Mode)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_MODE(Mode));

    WRITE_REG(QEPx->QDECCTL_bit.QSRC, Mode);
}

/**
  * @brief   Настройка скорости счета для режимов счета вверх или вниз
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   CountRate  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_CountRateConfig(QEP_TypeDef* QEPx, QEP_PC_CountRate_TypeDef CountRate)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_COUNT_RATE(CountRate));

    WRITE_REG(QEPx->QDECCTL_bit.XCR, CountRate);
}

/**
  * @brief   Настройка события для сброса счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ResetEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_ResetEventConfig(QEP_TypeDef* QEPx, QEP_PC_ResetEvent_TypeDef ResetEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_RESET_EVENT(ResetEvent));

    WRITE_REG(QEPx->QEPCTL_bit.PCRM, ResetEvent);
}

/**
  * @brief   Настройка события стробирования для инициализации счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_InitEventSConfig(QEP_TypeDef* QEPx, QEP_PC_InitEventS_TypeDef InitEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_INIT_EVENT_S(InitEvent));

    WRITE_REG(QEPx->QEPCTL_bit.SEI, InitEvent);
}

/**
  * @brief   Настройка события индексации для инициализации счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_InitEventIConfig(QEP_TypeDef* QEPx, QEP_PC_InitEventI_TypeDef InitEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_INIT_EVENT_I(InitEvent));

    WRITE_REG(QEPx->QEPCTL_bit.IEI, InitEvent);
}

/**
  * @brief   Выполнение программной инициализации счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SwInitCmd(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QEPCTL_bit.SWI, 1);
}

/**
  * @brief   Настройка события стробирования для сохранения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_LatchEventSConfig(QEP_TypeDef* QEPx, QEP_PC_LatchEventS_TypeDef LatchEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_LATCH_EVENT_S(LatchEvent));

    WRITE_REG(QEPx->QEPCTL_bit.SEL, LatchEvent);
}

/**
  * @brief   Настройка события индексации для сохранения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   InitEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_LatchEventIConfig(QEP_TypeDef* QEPx, QEP_PC_LatchEventI_TypeDef LatchEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_PC_LATCH_EVENT_I(LatchEvent));

    WRITE_REG(QEPx->QEPCTL_bit.IEL, LatchEvent);
}

/**
  * @brief   Установка значения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCount(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QPOSCNT, Val);
}

/**
  * @brief   Получение текущего значения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCount(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSCNT);
}

/**
  * @brief   Установка значения инициализации счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCountInit(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QPOSINIT, Val);
}

/**
  * @brief   Получение текущего значения инициализации счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountInit(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSINIT);
}

/**
  * @brief   Установка максимального значения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_PC_SetCountMax(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QPOSMAX, Val);
}

/**
  * @brief   Получение текущего максимального значения счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountMax(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSMAX);
}

/**
  * @brief   Получение сохраненного значения счетчика позиции по стробу
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatchS(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSSLAT);
}

/**
  * @brief   Получение сохраненного значения счетчика позиции по индексу
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatchI(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSILAT);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_PositionCompare Компаратор
  * @{
  */

void QEP_CMP_Init(QEP_TypeDef* QEPx, QEP_CMP_Init_TypeDef* InitStruct);
void QEP_CMP_StructInit(QEP_CMP_Init_TypeDef* InitStruct);

/**
  * @brief   Включение компаратора счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_Cmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QPOSCTL_bit.PCE, State);
}

/**
  * @brief   Включение отложенной загрузки компаратора счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_ShadowLoadCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QPOSCTL_bit.PCSHDW, State);
}

/**
  * @brief   Настройка события для отложенной загрузки компаратора счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   LoadEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_LoadEventConfig(QEP_TypeDef* QEPx, QEP_CMP_LoadEvent_TypeDef LoadEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CMP_LOAD_EVENT(LoadEvent));

    WRITE_REG(QEPx->QPOSCTL_bit.PCLOAD, LoadEvent);
}

/**
  * @brief   Настройка вывода для выдачи выходного сигнала компаратора счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Out  Выбор вывода
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutConfig(QEP_TypeDef* QEPx, QEP_CMP_Out_TypeDef Out)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CMP_OUT(Out));

    WRITE_REG(QEPx->QDECCTL_bit.SPSEL, Out);
}

/**
  * @brief   Разрешение выходного сигнала компаратора счётчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QDECCTL_bit.SOEN, State);
}

/**
  * @brief   Настройка полярности выходного сигнала компаратора счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   OutPolarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_OutPolarityConfig(QEP_TypeDef* QEPx, QEP_CMP_OutPolarity_TypeDef OutPolarity)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CMP_OUT_POLARITY(OutPolarity));

    WRITE_REG(QEPx->QPOSCTL_bit.PCPOL, OutPolarity);
}

/**
  * @brief   Настройка ширигы импульса выходного сигнала компаратора счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   OutPolarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_SetOutWidth(QEP_TypeDef* QEPx, uint32_t OutWidth)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CMP_OUT_WIDTH_VAL(OutWidth));

    WRITE_REG(QEPx->QPOSCTL_bit.PCSPW, OutWidth);
}

/**
  * @brief   Установка значения компаратора счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CMP_SetComp(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QPOSCMP, Val);
}

/**
  * @brief   Получение текущего значения компаратора счетчика позиции
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CMP_GetComp(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QPOSCMP);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_CaptureTime Модуль захвата времени
  * @{
  */

void QEP_CAP_Init(QEP_TypeDef* QEPx, QEP_CAP_Init_TypeDef* InitStruct);
void QEP_CAP_StructInit(QEP_CAP_Init_TypeDef* InitStruct);

/**
  * @brief   Включение модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_Cmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QCAPCTL_bit.CEN, State);
}

/**
  * @brief   Включение теневой загрузки делителей модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DivShadowLoadCmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QCAPCTL_bit.EPSLD, State);
}

/**
  * @brief   Настройка события сброса счетчика модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ResetEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_ResetEventConfig(QEP_TypeDef* QEPx, QEP_CAP_ResetEvent_TypeDef ResetEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CAP_RESET_EVENT(ResetEvent));

    WRITE_REG(QEPx->QCAPCTL_bit.SELEVENT, ResetEvent);
}

/**
  * @brief   Настройка делителей для модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   PCLKDiv  Выбор делителя PCLK
  * @param   QCLKDiv  Выбор делителя QCLK
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DivConfig(QEP_TypeDef* QEPx, QEP_CAP_PCLKDiv_TypeDef PCLKDiv, QEP_CAP_QCLKDiv_TypeDef QCLKDiv)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CAP_PCLK_DIV(PCLKDiv));
    assert_param(IS_QEP_CAP_QCLK_DIV(QCLKDiv));

    MODIFY_REG(QEPx->QCAPCTL, QEP_QCAPCTL_CCPS_Msk | QEP_QCAPCTL_UPPS_Msk,
               ((PCLKDiv << QEP_QCAPCTL_CCPS_Pos) | (QCLKDiv << QEP_QCAPCTL_UPPS_Pos)));
}

/**
  * @brief   Настройка делителя PCLK для модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   PCLKDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_PCLKDivConfig(QEP_TypeDef* QEPx, QEP_CAP_PCLKDiv_TypeDef PCLKDiv)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CAP_PCLK_DIV(PCLKDiv));

    WRITE_REG(QEPx->QCAPCTL_bit.CCPS, PCLKDiv);
}

/**
  * @brief   Настройка делителя QCLK для модуля захвата времени
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   QCLKDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_QCLKDivConfig(QEP_TypeDef* QEPx, QEP_CAP_QCLKDiv_TypeDef QCLKDiv)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CAP_QCLK_DIV(QCLKDiv));

    WRITE_REG(QEPx->QCAPCTL_bit.UPPS, QCLKDiv);
}

/**
  * @brief   Настройка события сохранения значения регистров модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   LatchEvent  Выбор события
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_LatchEventConfig(QEP_TypeDef* QEPx, QEP_CAP_LatchEvent_TypeDef LatchEvent)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_CAP_LATCH_EVENT(LatchEvent));

    WRITE_REG(QEPx->QEPCTL_bit.QCLM, LatchEvent);
}

/**
  * @brief   Установка значения счетчика модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_SetCount(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QCTMR, Val);
}

/**
  * @brief   Получение текущего значения счетчика модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CAP_GetCount(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QCTMR);
}

/**
  * @brief   Установка значения периода модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_SetPeriod(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QCPRD, Val);
}

/**
  * @brief   Получение текущего значения периода модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_CAP_GetPeriod(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QCPRD);
}

/**
  * @brief   Получение сохраненного значения счетчика модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetCountLatch(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QCTMRLAT);
}

/**
  * @brief   Получение сохраненного значения периода модуля захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_PC_GetPeriodLatch(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QCPRDLAT);
}

/**
  * @brief   Включение генерации запроса DMA событию захвата
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_CAP_DMACmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->DMAREQ_bit.DMAEN, State);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_UnitTimer Таймер временных отсчетов
  * @{
  */

/**
  * @brief   Включение таймера временных отсчетов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_Cmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QEPCTL_bit.UTE, State);
}

/**
  * @brief   Установка значения счетчика таймера временных отсчетов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_SetCount(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QUTMR, Val);
}

/**
  * @brief   Получение значения счетчика таймера временных отсчетов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_TMR_GetCount(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QUTMR);
}

/**
  * @brief   Установка значения периода таймера временных отсчетов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_TMR_SetPeriod(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QUPRD, Val);
}

/**
  * @brief   Получение значения периода таймера временных отсчетов
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_TMR_GetPeriod(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QUPRD);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_Watchdog Сторожевой таймер
  * @{
  */

/**
  * @brief   Включение сторожевого таймера
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_Cmd(QEP_TypeDef* QEPx, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(QEPx->QEPCTL_bit.WDE, State);
}

/**
  * @brief   Установка значения счетчика сторожевого таймера
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_SetCount(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QWDTMR, Val);
}

/**
  * @brief   Получение значения счетчика сторожевого таймера
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_WDT_GetCount(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QWDTMR);
}

/**
  * @brief   Установка значения периода сторожевого таймера
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void QEP_WDT_SetPeriod(QEP_TypeDef* QEPx, uint32_t Val)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->QWDPRD, Val);
}

/**
  * @brief   Получение значения периода сторожевого таймера
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t QEP_WDT_GetPeriod(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return READ_REG(QEPx->QWDPRD);
}

/**
  * @}
  */

/** @defgroup QEP_Exported_Functions_IT Прерывания
  * @{
  */

/**
  * @brief   Разрешение генерации прерываний
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений QEP_ITSource_x из @ref QEP_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void QEP_ITCmd(QEP_TypeDef* QEPx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(QEPx->QEINT, ITSource, State ? (uint32_t)ITSource : 0);
}

/**
  * @brief   Принудительный вызов прерывания
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений QEP_ITSource_x из @ref QEP_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void QEP_ITForceCmd(QEP_TypeDef* QEPx, uint32_t ITSource)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_IT_SOURCE(ITSource));

    WRITE_REG(QEPx->QFRC, ITSource);
}

/**
  * @brief   Чтение статуса прерывания
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_Define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_ITStatus(QEP_TypeDef* QEPx, uint32_t ITStatus)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(QEPx->QFLG, ITStatus);
}

/**
  * @brief   Чтение сохраненного статуса прерывания (сохранение каждый раз при чтении счетчика позиции)
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_Define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus QEP_ITStatusLatch(QEP_TypeDef* QEPx, uint32_t ITStatus)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(QEPx->QFLG, ITStatus << QEP_QFLG_QFLGLAT_Pos);
}

/**
  * @brief   Сброс статуса прерывания
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений QEP_ITStatus_x из @ref QEP_ITStatus_Define.
  * @retval  void
  */
__STATIC_INLINE void QEP_ITStatusClear(QEP_TypeDef* QEPx, uint32_t ITStatus)
{
    assert_param(IS_QEP_PERIPH(QEPx));
    assert_param(IS_QEP_IT_STATUS(ITStatus));

    WRITE_REG(QEPx->QCLR, ITStatus);
}

/**
  * @brief   Чтение активного статуса прерывания
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus QEP_ITPendStatus(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    return (FlagStatus)READ_BIT(QEPx->INTCLR, QEP_INTCLR_INT_Msk);
}

/**
  * @brief   Сброс активности прерывания
  * @param   QEPx  Выбор модуля QEP, где x=0|1|2|3
  * @retval  void
  */
__STATIC_INLINE void QEP_ITPendStatusClear(QEP_TypeDef* QEPx)
{
    assert_param(IS_QEP_PERIPH(QEPx));

    WRITE_REG(QEPx->INTCLR, QEP_INTCLR_INT_Msk);
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

#endif /* __PLIB028_QEP_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
