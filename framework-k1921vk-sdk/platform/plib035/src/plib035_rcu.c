/**
  ******************************************************************************
  * @file    plib035_rcu.c
  *
  * @brief   Файл содержит реализацию функций для работы с RCU
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

/* Includes ------------------------------------------------------------------*/
#include "plib035_rcu.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup RCU
  * @{
  */

/** @defgroup RCU_Private Приватные данные
  * @{
  */

/** @defgroup RCU_Private_Defines Приватные константы
  * @{
  */

/** @defgroup RCU_TIMEOUT_DEFINE Значения для таймаутов
  * @{
  */

#define RCU_SYSCLK_CHANGE_TIMEOUT 10000 /*!< Время ожидания смены источника тактирования */
#define RCU_PLLCLK_LOCK_TIMEOUT 10000   /*!< Время ожидания стабилизации выходной частоты PLL */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCU_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getSysClkFreq(RCU_SysClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_SysClk_OSIClk:
        clk_freq = RCU_GetOSIClkFreq();
        break;
    case RCU_SysClk_OSEClk:
        clk_freq = RCU_GetOSEClkFreq();
        break;
    case RCU_SysClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_SysClk_PLLDivClk:
        clk_freq = RCU_GetPLLDivClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getPeriphClkFreq(RCU_PeriphClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_PeriphClk_OSEClk:
        clk_freq = RCU_GetOSEClkFreq();
        break;
    case RCU_PeriphClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_PeriphClk_PLLDivClk:
        clk_freq = RCU_GetPLLDivClkFreq();
        break;
    case RCU_PeriphClk_OSIClk:
        clk_freq = RCU_GetOSIClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getSysPeriphClkFreq(RCU_SysPeriphClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_SysPeriphClk_OSEClk:
        clk_freq = RCU_GetOSEClkFreq();
        break;
    case RCU_SysPeriphClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_SysPeriphClk_PLLDivClk:
        clk_freq = RCU_GetPLLDivClkFreq();
        break;
    case RCU_SysPeriphClk_OSIClk:
        clk_freq = RCU_GetOSIClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты тактового сигнала OSICLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetOSIClkFreq()
{
    return OSICLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала OSECLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetOSEClkFreq()
{
    return OSECLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала PLLCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLClkFreq()
{
    uint32_t pll_n, pll_m, pll_refclk;
    RCU_PLL_OD_TypeDef pll_od;

    pll_n = READ_REG(RCU->PLLCFG_bit.N);
    pll_m = READ_REG(RCU->PLLCFG_bit.M);
    pll_od = (RCU_PLL_OD_TypeDef)READ_REG(RCU->PLLCFG_bit.OD);
    if (READ_REG(RCU->PLLCFG_bit.REFSRC) == RCU_PLL_Ref_OSIClk)
        pll_refclk = OSICLK_VAL;
    else // RCU->PLLCFG_bit.REFSRC == RCU_PLLCFG_REFSRC_OSECLK
        pll_refclk = OSECLK_VAL;
    return (pll_refclk * pll_m) / (pll_n * (1 << (uint32_t)pll_od));
}

/**
  * @brief   Получение значения частоты тактового сигнала PLLDIVCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLDivClkFreq()
{
    uint32_t pll_div;

    pll_div = RCU->PLLDIV_bit.DIV + 1;

    return RCU_GetPLLClkFreq() / pll_div;
}

/**
  * @brief   Получение значения частоты SYSCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSysClkFreq()
{
    RCU_SysClk_TypeDef sys_clk;

    sys_clk = RCU_SysClkStatus();

    return getSysClkFreq(sys_clk);
}

/**
  * @brief   Получение значения частоты UARTCLK
  * @param   UARTx_Num  Порядковый номер блока UART
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetUARTClkFreq(UART_Num_TypeDef UARTx_Num)
{
    RCU_PeriphClk_TypeDef uart_clk;
    uint32_t div_val;

    uart_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.CLKSEL);
    if (READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(uart_clk) / div_val;
}

/**
  * @brief   Получение значения частоты SPICLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSPIClkFreq()
{
    RCU_PeriphClk_TypeDef spi_clk;
    uint32_t div_val;

    spi_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->SPICFG_bit.CLKSEL);
    if (READ_REG(RCU->SPICFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->SPICFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(spi_clk) / div_val;
}

/**
  * @brief   Получение значения частоты ADCCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetADCClkFreq()
{
    RCU_PeriphClk_TypeDef adc_clk;
    uint32_t div_val;

    adc_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->ADCCFG_bit.CLKSEL);
    if (READ_REG(RCU->ADCCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->ADCCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(adc_clk) / div_val;
}

/**
  * @brief   Получение значения частоты WDTCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetWDTClkFreq()
{
    RCU_SysPeriphClk_TypeDef wdt_clk;
    uint32_t div_val;

    wdt_clk = (RCU_SysPeriphClk_TypeDef)READ_REG(RCU->WDTCFG_bit.CLKSEL);
    if (READ_REG(RCU->WDTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->WDTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getSysPeriphClkFreq(wdt_clk) / div_val;
}

/**
  * @brief   Получение значения частоты TRACECLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetTraceClkFreq()
{
    RCU_SysPeriphClk_TypeDef trace_clk;
    uint32_t div_val;

    trace_clk = (RCU_SysPeriphClk_TypeDef)READ_REG(RCU->TRACECFG_bit.CLKSEL);
    if (READ_REG(RCU->TRACECFG_bit.DIVEN))
        div_val =  2 * (READ_REG(RCU->TRACECFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getSysPeriphClkFreq(trace_clk) / div_val;
}

/**
  * @brief   Получение значения частоты CLKOUT
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetClkOutFreq()
{
    RCU_SysPeriphClk_TypeDef clkout;
    uint32_t div_val;

    clkout = (RCU_SysPeriphClk_TypeDef)READ_REG(RCU->CLKOUTCFG_bit.CLKSEL);
    if (READ_REG(RCU->CLKOUTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->CLKOUTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getSysPeriphClkFreq(clkout) / div_val;
}

/**
  * @brief      Автоматическая конфигурация PLL для получения желаемой системной частоты
  * @attention  Если Freq < 30 МГц, то в качестве системной частоты может быть использован
  *             выход делителя PLLDIV
  * @param      Ref  Выбор источника опорного сигнала PLL.
  *                  Параметр принимает любое значение из @ref RCC_PLLRef_TypeDef.
  * @param      SysClkFreq  Желаемая системная частота в Гц
  *                         Параметр принимает любые значения из диапазона 1000000-100000000, кратные 1000000.
  *                         Некоторые значения частот получить невозможно.
  * @retval     Status
  */
OperationStatus RCU_PLL_AutoConfig(uint32_t SysClkFreq, RCU_PLL_Ref_TypeDef Ref)
{
    RCU_PLL_Init_TypeDef PLL_Init_Struct;
    uint32_t ref_freq;
    RCU_SysClk_TypeDef sysclk_sel;
    OperationStatus status = OK;

    RCU_PLL_StructInit(&PLL_Init_Struct);

    if (!IS_RCU_SYSCLK_FREQ(SysClkFreq))
        return ERROR;

    PLL_Init_Struct.Ref = Ref;
    if ((PLL_Init_Struct.Ref == RCU_PLL_Ref_OSEClk) &&
        IS_RCU_PLL_REF_FREQ(OSECLK_VAL))
        ref_freq = OSECLK_VAL;
    else if (PLL_Init_Struct.Ref == RCU_PLL_Ref_OSIClk)
        ref_freq = OSICLK_VAL;
    else
        return ERROR;

    if (SysClkFreq < 30000000) {
        PLL_Init_Struct.DivVal = 40000000 / SysClkFreq;
        PLL_Init_Struct.DivEn = ENABLE;
        SysClkFreq = SysClkFreq * (PLL_Init_Struct.DivVal + 1);
        sysclk_sel = RCU_SysClk_PLLDivClk;
    } else
        sysclk_sel = RCU_SysClk_PLLClk;

    if (SysClkFreq >= 60000000)
        PLL_Init_Struct.OD = RCU_PLL_OD_Div2;
    else if (SysClkFreq >= 30000000)
        PLL_Init_Struct.OD = RCU_PLL_OD_Div4;
    else
        return ERROR;

    uint32_t div_solved = 0;
    for (uint32_t i = 1; i < 64; i++) {
        uint32_t tmp_n = i;
        uint32_t tmp_m = (SysClkFreq * (1 << PLL_Init_Struct.OD)) / (ref_freq / i);
        if ((ref_freq % tmp_n == 0) &&
            IS_RCU_PLL_CMP_FREQ(ref_freq / tmp_n) &&
            ((SysClkFreq * (1 << PLL_Init_Struct.OD)) % (ref_freq / tmp_n) == 0) &&
            IS_RCU_PLL_M(tmp_m) &&
            IS_RCU_PLL_VCO_FREQ(ref_freq * tmp_m / tmp_n)) {
            div_solved = 1;
            PLL_Init_Struct.N = tmp_n;
            PLL_Init_Struct.M = tmp_m;
            break;
        }
    }

    if (!div_solved)
        status = ERROR;
    else
        status = RCU_PLL_Init(&PLL_Init_Struct);
    if (status != OK)
        return status;

    if (SysClkFreq >= 90000000)
        MFLASH_LatencyConfig(3);
    else if (SysClkFreq >= 60000000)
        MFLASH_LatencyConfig(2);
    else if (SysClkFreq >= 30000000)
        MFLASH_LatencyConfig(1);
    else
        MFLASH_LatencyConfig(0);

    status = RCU_SysClkChangeCmd(sysclk_sel);
    return status;
}

/**
  * @brief      Инициализирует PLL согласно параметрам структуры InitStruct.
  *             Значение выходной частоты PLL вычисляется по формуле:<br><br>
  *             <center>FOUT = (FIN × M) / (N × (2^OD)),</center>
  *             где FIN – входная частота PLL.<br>
  * @attention  При расчете коэффициентов деления PLL должны выполняться следующие условия:
  *             - 4 МГц <= FIN <= 64 МГц (REF),
  *             - 4 MГц <= FIN/N <= 20 МГц (CMP),
  *             - 120 МГц <= FIN*M/N <= 200 МГц (VCO),
  *             - 15 МГц <= FOUT <= 100 МГц;
  *
  * @param      InitStruct  Указатель на структуру типа @ref RCU_PLL_Init_TypeDef,
  *                         которая содержит конфигурационную информацию
  * @retval     Status
  */
OperationStatus RCU_PLL_Init(RCU_PLL_Init_TypeDef* InitStruct)
{
    uint32_t timeout = RCU_PLLCLK_LOCK_TIMEOUT;
    OperationStatus status = OK;

    assert_param(IS_FUNCTIONAL_STATE(InitStruct->DivEn));
    assert_param(IS_RCU_PLL_DIV(InitStruct->DivVal));
    assert_param(IS_RCU_PLL_M(InitStruct->M));
    assert_param(IS_RCU_PLL_N(InitStruct->N));
    assert_param(IS_RCU_PLL_OD(InitStruct->OD));
    assert_param(IS_RCU_PLL_REF(InitStruct->Ref));

    MODIFY_REG(RCU->PLLCFG, (RCU_PLLCFG_N_Msk | RCU_PLLCFG_M_Msk | RCU_PLLCFG_N_Msk | RCU_PLLCFG_OD_Msk | RCU_PLLCFG_REFSRC_Msk),
               (InitStruct->N << RCU_PLLCFG_N_Pos |
                InitStruct->M << RCU_PLLCFG_M_Pos |
                InitStruct->OD << RCU_PLLCFG_OD_Pos |
                InitStruct->Ref << RCU_PLLCFG_REFSRC_Pos));
    MODIFY_REG(RCU->PLLDIV, RCU_PLLDIV_DIV_Msk | RCU_PLLDIV_DIVEN_Msk,
               InitStruct->DivVal << RCU_PLLDIV_DIV_Pos |
                   InitStruct->DivEn << RCU_PLLDIV_DIVEN_Pos);
    RCU_PLL_OutCmd(ENABLE);
    while (timeout) {
        if (RCU_PLL_LockStatus()) {
            break;
        } else {
            timeout--;
        }
    }
    if (!timeout) {
        status = ERROR;
    }

    return status;
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref RCU_PLL_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void RCU_PLL_StructInit(RCU_PLL_Init_TypeDef* InitStruct)
{
    InitStruct->Ref = RCU_PLL_Ref_OSEClk;
    InitStruct->DivVal = 0;
    InitStruct->DivEn = DISABLE;
    InitStruct->M = 0;
    InitStruct->N = 0;
    InitStruct->OD = RCU_PLL_OD_Disable;
}

/**
  * @brief   Устанавливает все регистры PLL значениями по умолчанию
  * @retval  void
  */
void RCU_PLL_DeInit()
{
    RCU_PLL_OutCmd(DISABLE);
    CLEAR_REG(RCU->PLLCFG);
    CLEAR_REG(RCU->PLLDIV);
}

/**
  * @brief   Переключение источника для системного тактового сигнала
  * @param   SysClk  Выбор источника
  * @retval  void
  */
OperationStatus RCU_SysClkChangeCmd(RCU_SysClk_TypeDef SysClk)
{
    uint32_t timeout = RCU_SYSCLK_CHANGE_TIMEOUT;
    OperationStatus status = OK;

    assert_param(IS_RCU_SYS_CLK(SysClk));

    RCU_SysClkConfig(SysClk);

    while (timeout) {
        if (RCU_BusyStatus()) {
            timeout--;
        } else {
            break;
        }
    }

    if (!timeout || (RCU_SysClkStatus() != SysClk)) {
        status = ERROR;
    }

    return status;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE****/
