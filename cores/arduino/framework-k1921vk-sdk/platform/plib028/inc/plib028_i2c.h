/**
  ******************************************************************************
  * @file    plib028_i2c.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          I2C, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB028_I2C_H
#define __PLIB028_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib028.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup I2C
  * @brief Драйвер для работы с I2C
  * @{
  */

/** @defgroup I2C_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Exported_Types Типы
  * @{
  */

/**
  * @brief  Коды состояния I2C
  */
typedef enum {
    I2C_State_IDLE = I2C_ST_MODE_IDLE,       /*!< Общий - Idle, нет доступной статусной информации */
    I2C_State_STDONE = I2C_ST_MODE_STDONE,   /*!< FS мастер - Сформировано состояние СТАРТа */
    I2C_State_RSDONE = I2C_ST_MODE_RSDONE,   /*!< FS мастер - Сформировано состояние повторного СТАРТа */
    I2C_State_IDLARL = I2C_ST_MODE_IDLARL,   /*!< FS мастер - Потеря арбитража, переход в режим безадресного ведомого */
    I2C_State_MTADPA = I2C_ST_MODE_MTADPA,   /*!< FS мастер передача - Отправлен адрес ведомого, ACK */
    I2C_State_MTADNA = I2C_ST_MODE_MTADNA,   /*!< FS мастер передача - Отправлен адрес ведомого, NACK */
    I2C_State_MTDAPA = I2C_ST_MODE_MTDAPA,   /*!< FS мастер передача - Отправлен байт данных, ACK */
    I2C_State_MTDANA = I2C_ST_MODE_MTDANA,   /*!< FS мастер передача - Отправлен байт данных, NACK */
    I2C_State_MRADPA = I2C_ST_MODE_MRADPA,   /*!< FS мастер приём - Отправлен адрес ведомого, ACK */
    I2C_State_MRADNA = I2C_ST_MODE_MRADNA,   /*!< FS мастер приём - Отправлен адрес ведомого, NACK */
    I2C_State_MRDAPA = I2C_ST_MODE_MRDAPA,   /*!< FS мастер приём - Принят байт данных, ACK */
    I2C_State_MRDANA = I2C_ST_MODE_MRDANA,   /*!< FS мастер приём - Принят байт данных, NACK */
    I2C_State_MTMCER = I2C_ST_MODE_MTMCER,   /*!< FS мастер - Отправлен код мастера, обнаружена ошибка, ACK */
    I2C_State_SRADPA = I2C_ST_MODE_SRADPA,   /*!< FS ведомый приём - Принят адрес ведомого, ACK */
    I2C_State_SRAAPA = I2C_ST_MODE_SRAAPA,   /*!< FS ведомый приём - Принят адрес ведомого после потери арбитража, ACK */
    I2C_State_SRDAPA = I2C_ST_MODE_SRDAPA,   /*!< FS ведомый приём - Принят байт данных, ACK */
    I2C_State_SRDANA = I2C_ST_MODE_SRDANA,   /*!< FS ведомый приём - Принят байт данных, NACK */
    I2C_State_STADPA = I2C_ST_MODE_STADPA,   /*!< FS ведомый передача - Принят адрес ведомого, ACK */
    I2C_State_STAAPA = I2C_ST_MODE_STAAPA,   /*!< FS ведомый передача - Принят адрес ведомого, NACK */
    I2C_State_STDAPA = I2C_ST_MODE_STDAPA,   /*!< FS ведомый передача - Отправлен байт данных, ACK */
    I2C_State_STDANA = I2C_ST_MODE_STDANA,   /*!< FS ведомый передача - Отправлен байт данных, NACK */
    I2C_State_SATADP = I2C_ST_MODE_SATADP,   /*!< FS ведомый передача отклика на тревогу - Принят адрес отклика на тревогу, ACK */
    I2C_State_SATAAP = I2C_ST_MODE_SATAAP,   /*!< FS ведомый передача отклика на тревогу - Принят адрес отклика на тревогу после потери арбитража, ACK */
    I2C_State_SATDAP = I2C_ST_MODE_SATDAP,   /*!< FS ведомый передача отклика на тревогу - Отправлен байт данных отклика на тревогу, ACK */
    I2C_State_SATDAN = I2C_ST_MODE_SATDAN,   /*!< FS ведомый передача отклика на тревогу - Отправлен байт данных отклика на тревогу, NACK */
    I2C_State_SSTOP = I2C_ST_MODE_SSTOP,     /*!< FS ведомый - Обнаружено состояние СТОП ведомого */
    I2C_State_SGADPA = I2C_ST_MODE_SGADPA,   /*!< FS ведомый - Принят адрес общего вызова, ACK */
    I2C_State_SDAAPA = I2C_ST_MODE_SDAAPA,   /*!< FS ведомый - Принят адрес общего вызова после потери арбитража, ACK */
    I2C_State_BERROR = I2C_ST_MODE_BERROR,   /*!< Общий - Обнаружена ошибка шины (некорректный СТАРТ или СТОП) */
    I2C_State_HMTMCOK = I2C_ST_MODE_HMTMCOK, /*!< HS мастер - Код мастера передан успешно - переход в режим HS */
    I2C_State_HRSDONE = I2C_ST_MODE_HRSDONE, /*!< HS мастер - Сформировано состояние повторного СТАРТа */
    I2C_State_HIDLARL = I2C_ST_MODE_HIDLARL, /*!< HS мастер - Потеря арбитража, переход в режим HS безадресного ведомого  */
    I2C_State_HMTADPA = I2C_ST_MODE_HMTADPA, /*!< HS мастер передача - Отправлен адрес ведомого, ACK */
    I2C_State_HMTADNA = I2C_ST_MODE_HMTADNA, /*!< HS мастер передача - Отправлен адрес ведомого, NACK */
    I2C_State_HMTDAPA = I2C_ST_MODE_HMTDAPA, /*!< HS мастер передача - Отправлен байт данных, ACK */
    I2C_State_HMTDANA = I2C_ST_MODE_HMTDANA, /*!< HS мастер передача - Отправлен байт данных, NACK */
    I2C_State_HMRADPA = I2C_ST_MODE_HMRADPA, /*!< HS мастер приём - Отправлен адрес ведомого, ACK */
    I2C_State_HMRADNA = I2C_ST_MODE_HMRADNA, /*!< HS мастер приём - Отправлен адрес ведомого, NACK */
    I2C_State_HMRDAPA = I2C_ST_MODE_HMRDAPA, /*!< HS мастер приём - Принят байт данных, ACK */
    I2C_State_HMRDANA = I2C_ST_MODE_HMRDANA, /*!< HS мастер приём - Принят байт данных, NACK */
    I2C_State_HSRADPA = I2C_ST_MODE_HSRADPA, /*!< HS ведомый приём - Принят адрес ведомого, ACK */
    I2C_State_HSRDAPA = I2C_ST_MODE_HSRDAPA, /*!< HS ведомый приём - Принят байт данных, ACK */
    I2C_State_HSRDANA = I2C_ST_MODE_HSRDANA, /*!< HS ведомый приём - Принят байт данных, NACK */
    I2C_State_HSTADPA = I2C_ST_MODE_HSTADPA, /*!< HS ведомый передача - Принят адрес ведомого, ACK */
    I2C_State_HSTDAPA = I2C_ST_MODE_HSTDAPA, /*!< HS ведомый передача - Отправлен байт данных, ACK */
    I2C_State_HSTDANA = I2C_ST_MODE_HSTDANA, /*!< HS ведомый передача - Отправлен байт данных, NACK */
} I2C_State_TypeDef;

/**
  * @brief  Выбор предделителя тактовой частоты для счетчика простоя линии SCL
  */
typedef enum {
    I2C_TimeoutClkDiv_Disable = I2C_CST_TOCDIV_Disable, /*!< Выключен, не тактируется */
    I2C_TimeoutClkDiv_Div4 = I2C_CST_TOCDIV_Div4,       /*!< Деление на 4 */
    I2C_TimeoutClkDiv_Div8 = I2C_CST_TOCDIV_Div8,       /*!< Деление на 8 */
    I2C_TimeoutClkDiv_Div16 = I2C_CST_TOCDIV_Div16      /*!< Деление на 16 */
} I2C_TimeoutClkDiv_TypeDef;
#define IS_I2C_TIMEOUT_CLK_DIV(VALUE) (((VALUE) == I2C_TimeoutClkDiv_Disable) || \
                                       ((VALUE) == I2C_TimeoutClkDiv_Div4) ||    \
                                       ((VALUE) == I2C_TimeoutClkDiv_Div8) ||    \
                                       ((VALUE) == I2C_TimeoutClkDiv_Div16))

#define IS_I2C_TIMEOUT_LOAD_VAL(VALUE) ((VALUE) < 0x100)
#define IS_I2C_DATA_VAL(VALUE) ((VALUE) < 0x100)
#define IS_I2C_FS_DIV_LOW_VAL(VALUE) (((VALUE) < 0x80) && ((VALUE) > 0x3))
#define IS_I2C_FS_DIV_HIGH_VAL(VALUE) ((VALUE) < 0x100)
#define IS_I2C_HS_DIV_LOW_VAL(VALUE) (((VALUE) < 0x10) && ((VALUE) > 0x1))
#define IS_I2C_HS_DIV_HIGH_VAL(VALUE) ((VALUE) < 0x100)
#define IS_I2C_SLAVE_ADDR_VAL(VALUE) ((VALUE) < 0x80)
#define IS_I2C_SLAVE_10_ADDR_VAL(VALUE) ((VALUE) < 0x8)

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions Функции
  * @{
  */

/** @defgroup I2C_Exported_Functions_Clk Настройка тактирования
  * @{
  */

void I2C_FSFreqConfig(I2C_TypeDef* I2Cx, uint32_t FSFreq, uint32_t I2CFreq);
void I2C_HSFreqConfig(I2C_TypeDef* I2Cx, uint32_t HSFreq, uint32_t I2CFreq);

/**
  * @brief      Установка младшей части делителя частоты в режиме FS мастера.
  * @attention  Можно записать любое значение в диапазоне от 4 до 127. При попытке
  *             записи любого значения меньше 4, оно будет записано со смещением 4.
  *             Например, при записи числа 2, к нему будет аппаратно добавлено
  *             смещение 4 и, в итоге, в регистре окажется значение 6.
  * @param      I2Cx  Выбор модуля I2C, где x=0|1
  * @param      DivVal  Значение (биты [6:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_FSDivLowConfig(I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_FS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2Cx->CTL1_bit.SCLFRQ, DivVal);
}

/**
  * @brief   Установка старшей части делителя частоты в режиме FS мастера
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   DivVal  Значение (биты [7:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_FSDivHighConfig(I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_FS_DIV_HIGH_VAL(DivVal));

    WRITE_REG(I2Cx->CTL3_bit.SCLFRQ, DivVal);
}

/**
  * @brief      Установка младшей части делителя частоты в режиме HS мастера.
  * @attention  Можно записать любое значение в диапазоне от 2 до 15. При попытке
  *             записи любого значения меньше 2, оно будет записано со смещением 2.
  *             Например, при записи числа 1, к нему будет аппаратно добавлено
  *             смещение 2 и, в итоге, в регистре окажется значение 3.
  * @param      I2Cx  Выбор модуля I2C, где x=0|1
  * @param      DivVal  Значение (биты [3:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_HSDivLowConfig(I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_HS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2Cx->CTL2_bit.HSDIV, DivVal);
}

/**
  * @brief   Установка старшей части делителя частоты в режиме HS мастера
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   DivVal  Значение (биты [7:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_HSDivHighConfig(I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_HS_DIV_HIGH_VAL(DivVal));

    WRITE_REG(I2Cx->CTL4_bit.HSDIV, DivVal);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_CtrlStatus Общее управление и статусная информация
  * @{
  */

/**
  * @brief   Включение модуля I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->CTL1_bit.ENABLE, State);
}

/**
  * @brief   Получение состояния внутренней машины состояний I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Val  Значение
  */
__STATIC_INLINE I2C_State_TypeDef I2C_GetState(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (I2C_State_TypeDef)READ_REG(I2Cx->ST_bit.MODE);
}

/**
  * @brief   Установка байта данных I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   DataVal  Значение
  * @retval  void
  */
__STATIC_INLINE void I2C_SetData(I2C_TypeDef* I2Cx, uint32_t DataVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_DATA_VAL(DataVal));

    WRITE_REG(I2Cx->SDA, DataVal);
}

/**
  * @brief   Получение байта данных I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t I2C_GetData(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->SDA);
}

/**
  * @brief   Чтение статуса флага занятости шины
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_BusBusyStatus(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_BB_Msk);
}

/**
  * @brief   Чтение статуса флага ошибки сравнения контрольной суммы
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_PECFailStatus(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_PECFAULT_Msk);
}

/**
  * @brief   Чтение текущего состояния линии SDA
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_SDAStatus(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_TSDA_Msk);
}

/**
  * @brief   Включение режима распознавания адреса отклика на тревогу
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_AlertResponseMatchCmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->CTL0_bit.SMBARE, State);
}

/**
  * @brief   Включение режима распознавания адреса общего вызова
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_GlobalCallMatchCmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->CTL0_bit.GCMEN, State);
}

/**
  * @brief   Следующий переданный/принятый байт будет байтом контрольной суммы
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_PECCmd(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CST_bit.PECNEXT, 1);
}

/**
  * @brief   Принудительное переключение сигнала SCL на один такт, когда на SDA низкий уровень
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_ToggleSCL(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CST_bit.TGSCL, 1);
}

/**
  * @brief   Формирование состояния СТАРТ
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_StartCmd(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.START, 1);
}

/**
  * @brief   Формирование состояния СТОП
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_StopCmd(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.STOP, 1);
}

/**
  * @brief   Передача значения NACK в ответе на запрос передатчика
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_NACKCmd(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.ACK, 1);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_SlaveMode Управление режимом ведомого
  * @{
  */

/**
  * @brief   Включение режима распознавания принятого адреса (режим ведомого)
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_SlaveCmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->ADDR_bit.SAEN, State);
}

/**
  * @brief   Задание собственного адреса ведомого
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   AddrVal  Значение адреса (биты [6:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_SetSlaveAddr(I2C_TypeDef* I2Cx, uint32_t AddrVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_SLAVE_ADDR_VAL(AddrVal));

    WRITE_REG(I2Cx->ADDR_bit.ADDR, AddrVal);
}

/**
  * @brief   Получение собственного адреса ведомого
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Val  Значение адреса (биты [6:0])
  */
__STATIC_INLINE uint32_t I2C_GetSlaveAddr(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->ADDR_bit.ADDR);
}

/**
  * @brief   Включение режима 10-битной адресации ведомого
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_Slave10AddrCmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->CTL2_bit.S10EN, State);
}

/**
  * @brief   Задание старшей части 10-битного адреса ведомого.
  *          Два байта адреса формируются следующим образом:
  *          [11110b, S10ADDR[2:1]] и [S10ADDR[0], ADDR[6:0]].
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   AddrVal  Значение адреса (биты [2:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_SetSlave10Addr(I2C_TypeDef* I2Cx, uint32_t Addr10Val)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_SLAVE_10_ADDR_VAL(Addr10Val));

    WRITE_REG(I2Cx->CTL2_bit.S10ADR, Addr10Val);
}

/**
  * @brief   Получение старшей части 10-битного адреса ведомого
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Val  Значение адреса (биты [2:0])
  */
__STATIC_INLINE uint32_t I2C_GetSlave10Addr(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->CTL2_bit.S10ADR);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Timeout Контроль простоя шины
  * @{
  */

/**
  * @brief   Устанавливает коэффициент деления тактового сигнала,
  *          подаваемого на предделитель времени простоя линии SCL
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   TimeoutClkDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void I2C_TimeoutClkDivConfig(I2C_TypeDef* I2Cx, I2C_TimeoutClkDiv_TypeDef TimeoutClkDiv)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_TIMEOUT_CLK_DIV(TimeoutClkDiv));

    WRITE_REG(I2Cx->CST_bit.TOCDIV, TimeoutClkDiv);
}

/**
  * @brief   Установка значения загрузки счетчика времени простоя
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   LoadVal  Значение
  * @retval  void
  */
__STATIC_INLINE void I2C_SetTimeoutCounterLoad(I2C_TypeDef* I2Cx, uint32_t LoadVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_TIMEOUT_LOAD_VAL(LoadVal));

    WRITE_REG(I2Cx->TOPR, LoadVal);
}

/**
  * @brief   Получение значения загрузки счетчика времени простоя
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t I2C_GetTimeoutCounterLoad(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->TOPR);
}

/**
  * @brief   Чтение статуса флага ошибки простоя I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_TimeoutStatus(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_TOERR_Msk);
}

/**
  * @brief   Сброс флага ошибки простоя I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_TimeoutStatusClear(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.CLRST, 1);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_IT Прерывания
  * @{
  */

/**
  * @brief   Включение генерации прерывания I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_ITCmd(I2C_TypeDef* I2Cx, FunctionalState State)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2Cx->CTL0_bit.INTEN, State);
}

/**
  * @brief   Чтение статуса флага прерывания I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_ITStatus(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->ST, I2C_ST_INT_Msk);
}

/**
  * @brief   Сброс флага прерывания I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_ITStatusClear(I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.CLRST, 1);
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

#endif /* __PLIB028_I2C_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
