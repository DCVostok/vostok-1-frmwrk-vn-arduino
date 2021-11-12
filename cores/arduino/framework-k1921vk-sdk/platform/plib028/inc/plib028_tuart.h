/**
  ******************************************************************************
  * @file    plib028_tuart.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          TUART, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_TUART_H
#define __PLIB028_TUART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup TUART
  * @brief Драйвер для работы с TUART
  * @{
  */

/** @defgroup TUART_Exported_Defines Константы
  * @{
  */

/** @defgroup TUART_ITSource_Define Источники прерываний TUART
  * @{
  */

#define TUART_ITSource_RxBuffOverflow TUART_CTRL_ROIEN_Msk /*!< Переполнение буффера приемника */
#define TUART_ITSource_TxBuffOverflow TUART_CTRL_TOIEN_Msk /*!< Переполнение буффера передатчика */
#define TUART_ITSource_Transmit TUART_CTRL_TXIEN_Msk   /*!< Готов к передаче */
#define TUART_ITSource_Receive TUART_CTRL_RXIEN_Msk    /*!< Произошёл приём */
#define TUART_ITSource_All (TUART_CTRL_ROIEN_Msk | \
                            TUART_CTRL_TOIEN_Msk | \
                            TUART_CTRL_TXIEN_Msk | \
                            TUART_CTRL_RXIEN_Msk) /*!< Все источники выбраны */

#define IS_TUART_IT_SOURCE(VALUE) (((VALUE) & ~TUART_ITSource_All) == 0)

/**
   * @}
   */

/** @defgroup TUART_Flag_Define Флаги работы TUART
  * @{
  */
#define TUART_Flag_TxBuffFull TUART_STATE_TXF_Msk    /*!< Флаг заполнения буффера передатчика */
#define TUART_Flag_RxBuffFull TUART_STATE_RXF_Msk    /*!< Флаг заполнения буффера приемника */
#define TUART_Flag_RxBuffOverflow TUART_STATE_RO_Msk /*!< Флаг переполнения буффера приемника */
#define TUART_Flag_TxBuffOverflow TUART_STATE_TO_Msk /*!< Флаг переполнения буффера передатчика */
#define TUART_Flag_All (TUART_STATE_TXF_Msk | \
                        TUART_STATE_RXF_Msk | \
                        TUART_STATE_RO_Msk |  \
                        TUART_STATE_TO_Msk) /*!< Все флаги выбраны */

#define IS_TUART_FLAG(VALUE) (((VALUE) & ~TUART_Flag_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup TUART_Exported_Types Типы
  * @{
  */

#define IS_TUART_BAUD_DIV(VALUE) (((VALUE) > 15) && ((VALUE) < 0x100000))
#define IS_TUART_DATA(VALUE) ((VALUE) < 0x100)

/**
  * @}
  */

/** @defgroup TUART_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Настройка делителя для реализации необходимой скорости передачи
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   BaudDiv  Значение делителя.
  *                   Параметр принимает любое значение из диапазона 0x10-0xFFFFF.
  * @retval  void
  */
__STATIC_INLINE void TUART_BaudDivConfig(TUART_TypeDef* TUARTx, uint32_t BaudDiv)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_BAUD_DIV(BaudDiv));

    WRITE_REG(TUARTx->BAUDDIV, BaudDiv);
}

/**
  * @brief   Разрешение приема
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TUART_RxCmd(TUART_TypeDef* TUARTx, FunctionalState State)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TUARTx->CTRL_bit.RXEN, State);
}

/**
  * @brief   Разрешение передачи
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TUART_TxCmd(TUART_TypeDef* TUARTx, FunctionalState State)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(TUARTx->CTRL_bit.TXEN, State);
}

/**
  * @brief   Передача слова данных
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   Data   Слово данных (биты 7-0)
  * @retval  void
  */
__STATIC_INLINE void TUART_SendData(TUART_TypeDef* TUARTx, uint32_t Data)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_DATA(Data));

    WRITE_REG(TUARTx->DATA, Data);
}

/**
  * @brief   Прием слова данных
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @retval  Val  Слово данных
  */
__STATIC_INLINE uint32_t TUART_RecieveData(TUART_TypeDef* TUARTx)
{
    assert_param(IS_TUART_PERIPH(TUARTx));

    return READ_REG(TUARTx->DATA);
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений TUART_Flag_x из @ref TUART_Flag_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus TUART_FlagStatus(TUART_TypeDef* TUARTx, uint32_t Flag)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_FLAG(Flag));

    return (FlagStatus)READ_BIT(TUARTx->STATE, Flag);
}

/**
  * @brief   Очистка выбранных флагов
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений TUART_Flag_x из @ref TUART_Flag_Define.
  * @retval  void
  */
__STATIC_INLINE void TUART_FlagStatusClear(TUART_TypeDef* TUARTx, uint32_t Flag)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_FLAG(Flag));

    WRITE_REG(TUARTx->STATE, Flag);
}

/**
  * @brief   Маскирование выбранных прерываний
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений TUART_ITSource_x из @ref TUART_ITSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void TUART_ITCmd(TUART_TypeDef* TUARTx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_IT_SOURCE(ITSource));

    MODIFY_REG(TUARTx->CTRL, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Запрос состояния прерывания
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений TUART_ITSource_x из @ref TUART_ITSource_Define.
  * @retval  Status  Состояние флага. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus TUART_ITStatus(TUART_TypeDef* TUARTx, uint32_t ITSource)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_IT_SOURCE(ITSource));

    return (FlagStatus)READ_BIT(TUARTx->INTSTATUS, ITSource >> TUART_CTRL_TXIEN_Pos);
}

/**
  * @brief   Сброс флагов состояния выбранных прерываний
  * @param   TUARTx  Выбор модуля TUART, где x=0|1
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений TUART_ITSource_x из @ref TUART_ITSource_Define.
  * @retval  void
  */
__STATIC_INLINE void TUART_ITStatusClear(TUART_TypeDef* TUARTx, uint32_t ITSource)
{
    assert_param(IS_TUART_PERIPH(TUARTx));
    assert_param(IS_TUART_IT_SOURCE(ITSource));

    WRITE_REG(TUARTx->INTSTATUS, ITSource >> TUART_CTRL_TXIEN_Pos);
}

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB028_TUART_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
