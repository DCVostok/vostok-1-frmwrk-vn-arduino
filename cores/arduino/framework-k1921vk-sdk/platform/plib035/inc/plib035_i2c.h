/**
  ******************************************************************************
  * @file    plib035_i2c.h
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
  * <h2><center>&copy; 2018 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB035_I2C_H
#define __PLIB035_I2C_H

#ifdef __cplusplus
//extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib035.h"

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

void I2C_FSFreqConfig(uint32_t FSFreq, uint32_t I2CFreq);
void I2C_HSFreqConfig(uint32_t HSFreq, uint32_t I2CFreq);

/**
  * @brief      Установка младшей части делителя частоты в режиме FS мастера.
  * @attention  Можно записать любое значение в диапазоне от 4 до 127. При попытке
  *             записи любого значения меньше 4, оно будет записано со смещением 4.
  *             Например, при записи числа 2, к нему будет аппаратно добавлено
  *             смещение 4 и, в итоге, в регистре окажется значение 6.
  * @param      DivVal  Значение (биты [6:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_FSDivLowConfig(uint32_t DivVal)
{
    assert_param(IS_I2C_FS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2C->CTL1_bit.SCLFRQ, DivVal);
}

/**
  * @brief   Установка старшей части делителя частоты в режиме FS мастера
  * @param   DivVal  Значение (биты [7:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_FSDivHighConfig(uint32_t DivVal)
{
    assert_param(IS_I2C_FS_DIV_HIGH_VAL(DivVal));

    WRITE_REG(I2C->CTL3_bit.SCLFRQ, DivVal);
}

/**
  * @brief      Установка младшей части делителя частоты в режиме HS мастера.
  * @attention  Можно записать любое значение в диапазоне от 2 до 15. При попытке
  *             записи любого значения меньше 2, оно будет записано со смещением 2.
  *             Например, при записи числа 1, к нему будет аппаратно добавлено
  *             смещение 2 и, в итоге, в регистре окажется значение 3.
  * @param      DivVal  Значение (биты [3:0])
  * @retval     void
  */
__STATIC_INLINE void I2C_HSDivLowConfig(uint32_t DivVal)
{
    assert_param(IS_I2C_HS_DIV_LOW_VAL(DivVal));

    WRITE_REG(I2C->CTL2_bit.HSDIV, DivVal);
}

/**
  * @brief   Установка старшей части делителя частоты в режиме HS мастера
  * @param   DivVal  Значение (биты [7:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_HSDivHighConfig(uint32_t DivVal)
{
    assert_param(IS_I2C_HS_DIV_HIGH_VAL(DivVal));

    WRITE_REG(I2C->CTL4_bit.HSDIV, DivVal);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_CtrlStatus Общее управление и статусная информация
  * @{
  */

/**
  * @brief   Включение модуля I2C
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->CTL1_bit.ENABLE, State);
}

/**
  * @brief   Получение состояния внутренней машины состояний I2C
  * @retval  Val  Значение
  */
__STATIC_INLINE I2C_State_TypeDef I2C_GetState(void)
{
    return (I2C_State_TypeDef)READ_REG(I2C->ST_bit.MODE);
}

/**
  * @brief   Установка байта данных I2C
  * @param   DataVal  Значение
  * @retval  void
  */
__STATIC_INLINE void I2C_SetData(uint32_t DataVal)
{
    assert_param(IS_I2C_DATA_VAL(DataVal));

    WRITE_REG(I2C->SDA, DataVal);
}

/**
  * @brief   Получение байта данных I2C
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t I2C_GetData(void)
{
    return READ_REG(I2C->SDA);
}

/**
  * @brief   Чтение статуса флага занятости шины
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_BusBusyStatus(void)
{
    return (FlagStatus)READ_BIT(I2C->CST, I2C_CST_BB_Msk);
}

/**
  * @brief   Чтение статуса флага ошибки сравнения контрольной суммы
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_PECFailStatus(void)
{
    return (FlagStatus)READ_BIT(I2C->CST, I2C_CST_PECFAULT_Msk);
}

/**
  * @brief   Чтение текущего состояния линии SDA
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_SDAStatus(void)
{
    return (FlagStatus)READ_BIT(I2C->CST, I2C_CST_TSDA_Msk);
}

/**
  * @brief   Включение режима распознавания адреса отклика на тревогу
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_AlertResponseMatchCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->CTL0_bit.SMBARE, State);
}

/**
  * @brief   Включение режима распознавания адреса общего вызова
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_GlobalCallMatchCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->CTL0_bit.GCMEN, State);
}

/**
  * @brief   Следующий переданный/принятый байт будет байтом контрольной суммы
  * @retval  void
  */
__STATIC_INLINE void I2C_PECCmd(void)
{
    WRITE_REG(I2C->CST_bit.PECNEXT, 1);
}

/**
  * @brief   Принудительное переключение сигнала SCL на один такт, когда на SDA низкий уровень
  * @retval  void
  */
__STATIC_INLINE void I2C_ToggleSCL(void)
{
    WRITE_REG(I2C->CST_bit.TGSCL, 1);
}

/**
  * @brief   Формирование состояния СТАРТ
  * @retval  void
  */
__STATIC_INLINE void I2C_StartCmd(void)
{
    WRITE_REG(I2C->CTL0_bit.START, 1);
}

/**
  * @brief   Формирование состояния СТОП
  * @retval  void
  */
__STATIC_INLINE void I2C_StopCmd(void)
{
    WRITE_REG(I2C->CTL0_bit.STOP, 1);
}

/**
  * @brief   Передача значения NACK в ответе на запрос передатчика
  * @retval  void
  */
__STATIC_INLINE void I2C_NACKCmd(void)
{
    WRITE_REG(I2C->CTL0_bit.ACK, 1);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_SlaveMode Управление режимом ведомого
  * @{
  */

/**
  * @brief   Включение режима распознавания принятого адреса (режим ведомого)
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_SlaveCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->ADDR_bit.SAEN, State);
}

/**
  * @brief   Задание собственного адреса ведомого
  * @param   AddrVal  Значение адреса (биты [6:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_SetSlaveAddr(uint32_t AddrVal)
{
    assert_param(IS_I2C_SLAVE_ADDR_VAL(AddrVal));

    WRITE_REG(I2C->ADDR_bit.ADDR, AddrVal);
}

/**
  * @brief   Получение собственного адреса ведомого
  * @retval  Val  Значение адреса (биты [6:0])
  */
__STATIC_INLINE uint32_t I2C_GetSlaveAddr(void)
{
    return READ_REG(I2C->ADDR_bit.ADDR);
}

/**
  * @brief   Включение режима 10-битной адресации ведомого
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_Slave10AddrCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->CTL2_bit.S10EN, State);
}

/**
  * @brief   Задание старшей части 10-битного адреса ведомого.
  *          Два байта адреса формируются следующим образом:
  *          [11110b, S10ADDR[2:1]] и [S10ADDR[0], ADDR[6:0]].
  * @param   AddrVal  Значение адреса (биты [2:0])
  * @retval  void
  */
__STATIC_INLINE void I2C_SetSlave10Addr(uint32_t Addr10Val)
{
    assert_param(IS_I2C_SLAVE_10_ADDR_VAL(Addr10Val));

    WRITE_REG(I2C->CTL2_bit.S10ADR, Addr10Val);
}

/**
  * @brief   Получение старшей части 10-битного адреса ведомого
  * @retval  Val  Значение адреса (биты [2:0])
  */
__STATIC_INLINE uint32_t I2C_GetSlave10Addr(void)
{
    return READ_REG(I2C->CTL2_bit.S10ADR);
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
  * @param   TimeoutClkDiv  Выбор делителя
  * @retval  void
  */
__STATIC_INLINE void I2C_TimeoutClkDivConfig(I2C_TimeoutClkDiv_TypeDef TimeoutClkDiv)
{
    assert_param(IS_I2C_TIMEOUT_CLK_DIV(TimeoutClkDiv));

    WRITE_REG(I2C->CST_bit.TOCDIV, TimeoutClkDiv);
}

/**
  * @brief   Установка значения загрузки счетчика времени простоя
  * @param   LoadVal  Значение
  * @retval  void
  */
__STATIC_INLINE void I2C_SetTimeoutCounterLoad(uint32_t LoadVal)
{
    assert_param(IS_I2C_TIMEOUT_LOAD_VAL(LoadVal));

    WRITE_REG(I2C->TOPR, LoadVal);
}

/**
  * @brief   Получение значения загрузки счетчика времени простоя
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t I2C_GetTimeoutCounterLoad(void)
{
    return READ_REG(I2C->TOPR);
}

/**
  * @brief   Чтение статуса флага ошибки простоя I2C
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_TimeoutStatus(void)
{
    return (FlagStatus)READ_BIT(I2C->CST, I2C_CST_TOERR_Msk);
}

/**
  * @brief   Сброс флага ошибки простоя I2C
  * @retval  void
  */
__STATIC_INLINE void I2C_TimeoutStatusClear(void)
{
    WRITE_REG(I2C->CTL0_bit.CLRST, 1);
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_IT Прерывания
  * @{
  */

/**
  * @brief   Включение генерации прерывания I2C
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void I2C_ITCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(I2C->CTL0_bit.INTEN, State);
}

/**
  * @brief   Чтение статуса флага прерывания I2C
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus I2C_ITStatus(void)
{
    return (FlagStatus)READ_BIT(I2C->ST, I2C_ST_INT_Msk);
}

/**
  * @brief   Сброс флага прерывания I2C
  * @retval  void
  */
__STATIC_INLINE void I2C_ITStatusClear(void)
{
    WRITE_REG(I2C->CTL0_bit.CLRST, 1);
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

#endif /* __PLIB035_I2C_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
