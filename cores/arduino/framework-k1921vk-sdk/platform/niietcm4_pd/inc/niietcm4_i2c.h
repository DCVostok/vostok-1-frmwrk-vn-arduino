#ifndef __NIIETCM4_I2C_H
#define __NIIETCM4_I2C_H



#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"


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
    I2C_State_IDLE = 0x0UL,       /*!< Общий - Idle, нет доступной статусной информации */
    I2C_State_STDONE = 0x1UL,   /*!< FS мастер - Сформировано состояние СТАРТа */
    I2C_State_RSDONE = 0x2UL,   /*!< FS мастер - Сформировано состояние повторного СТАРТа */
    I2C_State_IDLARL = 0x3UL,   /*!< FS мастер - Потеря арбитража, переход в режим безадресного ведомого */
    I2C_State_MTADPA = 0x4UL,   /*!< FS мастер передача - Отправлен адрес ведомого, ACK */
    I2C_State_MTADNA = 0x5UL,   /*!< FS мастер передача - Отправлен адрес ведомого, NACK */
    I2C_State_MTDAPA = 0x6UL,   /*!< FS мастер передача - Отправлен байт данных, ACK */
    I2C_State_MTDANA = 0x7UL,   /*!< FS мастер передача - Отправлен байт данных, NACK */
    I2C_State_MRADPA = 0x8UL,   /*!< FS мастер приём - Отправлен адрес ведомого, ACK */
    I2C_State_MRADNA = 0x9UL,   /*!< FS мастер приём - Отправлен адрес ведомого, NACK */
    I2C_State_MRDAPA = 0xAUL,   /*!< FS мастер приём - Принят байт данных, ACK */
    I2C_State_MRDANA = 0xBUL,   /*!< FS мастер приём - Принят байт данных, NACK */
    I2C_State_MTMCER = 0xCUL,   /*!< FS мастер - Отправлен код мастера, обнаружена ошибка, ACK */
    I2C_State_SRADPA = 0x10UL,   /*!< FS ведомый приём - Принят адрес ведомого, ACK */
    I2C_State_SRAAPA = 0x11UL,   /*!< FS ведомый приём - Принят адрес ведомого после потери арбитража, ACK */
    I2C_State_SRDAPA = 0x12UL,   /*!< FS ведомый приём - Принят байт данных, ACK */
    I2C_State_SRDANA = 0x13UL,   /*!< FS ведомый приём - Принят байт данных, NACK */
    I2C_State_STADPA = 0x14UL,   /*!< FS ведомый передача - Принят адрес ведомого, ACK */
    I2C_State_STAAPA = 0x15UL,   /*!< FS ведомый передача - Принят адрес ведомого, NACK */
    I2C_State_STDAPA = 0x16UL,   /*!< FS ведомый передача - Отправлен байт данных, ACK */
    I2C_State_STDANA = 0x17UL,   /*!< FS ведомый передача - Отправлен байт данных, NACK */
    I2C_State_SATADP = 0x18UL,   /*!< FS ведомый передача отклика на тревогу - Принят адрес отклика на тревогу, ACK */
    I2C_State_SATAAP = 0x19UL,   /*!< FS ведомый передача отклика на тревогу - Принят адрес отклика на тревогу после потери арбитража, ACK */
    I2C_State_SATDAP = 0x1AUL,   /*!< FS ведомый передача отклика на тревогу - Отправлен байт данных отклика на тревогу, ACK */
    I2C_State_SATDAN = 0x1BUL,   /*!< FS ведомый передача отклика на тревогу - Отправлен байт данных отклика на тревогу, NACK */
    I2C_State_SSTOP = 0x1CUL,     /*!< FS ведомый - Обнаружено состояние СТОП ведомого */
    I2C_State_SGADPA = 0x1DUL,   /*!< FS ведомый - Принят адрес общего вызова, ACK */
    I2C_State_SDAAPA = 0x1EUL,   /*!< FS ведомый - Принят адрес общего вызова после потери арбитража, ACK */
    I2C_State_BERROR = 0x1FUL,   /*!< Общий - Обнаружена ошибка шины (некорректный СТАРТ или СТОП) */
    I2C_State_HMTMCOK = 0x21UL, /*!< HS мастер - Код мастера передан успешно - переход в режим HS */
    I2C_State_HRSDONE = 0x22UL, /*!< HS мастер - Сформировано состояние повторного СТАРТа */
    I2C_State_HIDLARL = 0x23UL, /*!< HS мастер - Потеря арбитража, переход в режим HS безадресного ведомого  */
    I2C_State_HMTADPA = 0x24UL, /*!< HS мастер передача - Отправлен адрес ведомого, ACK */
    I2C_State_HMTADNA = 0x25UL, /*!< HS мастер передача - Отправлен адрес ведомого, NACK */
    I2C_State_HMTDAPA = 0x26UL, /*!< HS мастер передача - Отправлен байт данных, ACK */
    I2C_State_HMTDANA = 0x27UL, /*!< HS мастер передача - Отправлен байт данных, NACK */
    I2C_State_HMRADPA = 0x28UL, /*!< HS мастер приём - Отправлен адрес ведомого, ACK */
    I2C_State_HMRADNA = 0x29UL, /*!< HS мастер приём - Отправлен адрес ведомого, NACK */
    I2C_State_HMRDAPA = 0x2AUL, /*!< HS мастер приём - Принят байт данных, ACK */
    I2C_State_HMRDANA = 0x2BUL, /*!< HS мастер приём - Принят байт данных, NACK */
    I2C_State_HSRADPA = 0x30UL, /*!< HS ведомый приём - Принят адрес ведомого, ACK */
    I2C_State_HSRDAPA = 0x32UL, /*!< HS ведомый приём - Принят байт данных, ACK */
    I2C_State_HSRDANA = 0x33UL, /*!< HS ведомый приём - Принят байт данных, NACK */
    I2C_State_HSTADPA = 0x34UL, /*!< HS ведомый передача - Принят адрес ведомого, ACK */
    I2C_State_HSTDAPA = 0x36UL, /*!< HS ведомый передача - Отправлен байт данных, ACK */
    I2C_State_HSTDANA = 0x37UL, /*!< HS ведомый передача - Отправлен байт данных, NACK */
} I2C_State_TypeDef;

/**
  * @brief  Выбор предделителя тактовой частоты для счетчика простоя линии SCL
  */
typedef enum {
    I2C_TimeoutClkDiv_Disable = 0x0UL, /*!< Выключен, не тактируется */
    I2C_TimeoutClkDiv_Div4 = 0x1UL,       /*!< Деление на 4 */
    I2C_TimeoutClkDiv_Div8 = 0x2UL,       /*!< Деление на 8 */
    I2C_TimeoutClkDiv_Div16 = 0x3UL      /*!< Деление на 16 */
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
#define IS_I2C_PERIPH(PERIPH) (((PERIPH) == NT_I2C0) || \
                                ((PERIPH) == NT_I2C1))
 
/**
  * @brief      Установка делителя частоты в режиме FS мастера.
  * @attention  Можно записать любое значение в диапазоне от 4 до 127. При попытке
  *             записи любого значения меньше 4, оно будет записано со смещением 4.
  *             Например, при записи числа 2, к нему будет аппаратно добавлено
  *             смещение 4 и, в итоге, в регистре окажется значение 6.
  * @param      I2Cx  Выбор модуля I2C, где x=0|1
  * @param      DivVal  Значение (биты [6:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_FSDivConfig(NT_I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_FS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2Cx->CTL1_bit.SCLFRQ, DivVal);
}

/**
  * @brief      Установка делителя частоты в режиме HS мастера.
  * @attention  Можно записать любое значение в диапазоне от 2 до 15. При попытке
  *             записи любого значения меньше 2, оно будет записано со смещением 2.
  *             Например, при записи числа 1, к нему будет аппаратно добавлено
  *             смещение 2 и, в итоге, в регистре окажется значение 3.
  * @param      I2Cx  Выбор модуля I2C, где x=0|1
  * @param      DivVal  Значение (биты [3:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_HSDivConfig(NT_I2C_TypeDef* I2Cx, uint32_t DivVal)
{
    assert_param(IS_I2C_PERIPH(I2Cx));
    assert_param(IS_I2C_HS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2Cx->CTL2_bit.HSDIV, DivVal);
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
__STATIC_INLINE void I2C_Cmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE I2C_State_TypeDef I2C_GetState(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_SetData(NT_I2C_TypeDef* I2Cx, uint32_t DataVal)
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
__STATIC_INLINE uint32_t I2C_GetData(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->SDA);
}

/**
  * @brief   Чтение статуса флага занятости шины
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_BusBusyStatus(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_BB_Msk);
}

/**
  * @brief   Чтение статуса флага ошибки сравнения контрольной суммы
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_PECFailStatus(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_PECFAULT_Msk);
}

/**
  * @brief   Чтение текущего состояния линии SDA
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_SDAStatus(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_AlertResponseMatchCmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE void I2C_GlobalCallMatchCmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE void I2C_PECCmd(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CST_bit.PECNEXT, 1);
}

/**
  * @brief   Принудительное переключение сигнала SCL на один такт, когда на SDA низкий уровень
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_ToggleSCL(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CST_bit.TGSCL, 1);
}

/**
  * @brief   Формирование состояния СТАРТ
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_StartCmd(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.START, 1);
}

/**
  * @brief   Формирование состояния СТОП
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_StopCmd(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    WRITE_REG(I2Cx->CTL0_bit.STOP, 1);
}

/**
  * @brief   Передача значения NACK в ответе на запрос передатчика
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_NACKCmd(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_SlaveCmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE void I2C_SetSlaveAddr(NT_I2C_TypeDef* I2Cx, uint32_t AddrVal)
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
__STATIC_INLINE uint32_t I2C_GetSlaveAddr(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_Slave10AddrCmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE void I2C_SetSlave10Addr(NT_I2C_TypeDef* I2Cx, uint32_t Addr10Val)
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
__STATIC_INLINE uint32_t I2C_GetSlave10Addr(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_TimeoutClkDivConfig(NT_I2C_TypeDef* I2Cx, I2C_TimeoutClkDiv_TypeDef TimeoutClkDiv)
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
__STATIC_INLINE void I2C_SetTimeoutCounterLoad(NT_I2C_TypeDef* I2Cx, uint32_t LoadVal)
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
__STATIC_INLINE uint32_t I2C_GetTimeoutCounterLoad(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return READ_REG(I2Cx->TOPR);
}

/**
  * @brief   Чтение статуса флага ошибки простоя I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_TimeoutStatus(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->CST, I2C_CST_TOERR_Msk);
}

/**
  * @brief   Сброс флага ошибки простоя I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_TimeoutStatusClear(NT_I2C_TypeDef* I2Cx)
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
__STATIC_INLINE void I2C_ITCmd(NT_I2C_TypeDef* I2Cx, FunctionalState State)
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
__STATIC_INLINE FlagStatus I2C_ITStatus(NT_I2C_TypeDef* I2Cx)
{
    assert_param(IS_I2C_PERIPH(I2Cx));

    return (FlagStatus)READ_BIT(I2Cx->ST, I2C_ST_INT_Msk);
}

/**
  * @brief   Сброс флага прерывания I2C
  * @param   I2Cx  Выбор модуля I2C, где x=0|1
  * @retval  void
  */
__STATIC_INLINE void I2C_ITStatusClear(NT_I2C_TypeDef* I2Cx)
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


#endif //__NIIETCM4_I2C_H