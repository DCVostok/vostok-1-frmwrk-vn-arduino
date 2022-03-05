/**
  ******************************************************************************
  * @file    plib028_rcu.c
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
  * <h2><center>&copy; 2019 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "plib028_rcu.h"

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

#define RCU_PLLCFG_RST_VAL 0x34111101 /*!< Значение по сбросу регистра PLLCFG */

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
    case RCU_SysClk_RefClk:
        clk_freq = RCU_GetRefClkFreq();
        break;
    case RCU_SysClk_SrcClk:
        clk_freq = RCU_GetSrcClkFreq();
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
    case RCU_PeriphClk_PLLExtClk:
        clk_freq = RCU_GetPLLExtClkFreq();
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
    case RCU_SysPeriphClk_RefClk:
        clk_freq = RCU_GetRefClkFreq();
        break;
    case RCU_SysPeriphClk_SrcClk:
        clk_freq = RCU_GetSrcClkFreq();
        break;
    case RCU_SysPeriphClk_SysClk:
        clk_freq = RCU_GetSysClkFreq();
        break;
    case RCU_SysPeriphClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getTraceClkFreq(RCU_TraceClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_TraceClk_RefClk:
        clk_freq = RCU_GetRefClkFreq();
        break;
    case RCU_TraceClk_SrcClk:
        clk_freq = RCU_GetSrcClkFreq();
        break;
    case RCU_TraceClk_SysClk:
        clk_freq = RCU_GetSysClkFreq();
        break;
    case RCU_TraceClk_TRACEExtClk:
        clk_freq = RCU_GetPLLClkFreq();
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
  * @brief   Получение значения частоты тактового сигнала REFCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetRefClkFreq()
{
    return REFCLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала SRCCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSrcClkFreq()
{
    return SRCCLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала PLLCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLClkFreq()
{
    uint32_t pll_div1, pll_div2, pll_fbdiv, pll_refdiv, pll_refclk;

    pll_div1 = READ_REG(RCU->PLLCFG_bit.DIV1);
    pll_div2 = READ_REG(RCU->PLLCFG_bit.DIV2);
    pll_fbdiv = READ_REG(RCU->PLLCFG_bit.FBDIV);
    pll_refdiv = READ_REG(RCU->PLLCFG_bit.REFDIV);
    if (READ_REG(RCU->PLLCFG_bit.REFSRC) == RCU_PLLCFG_REFSRC_OSICLK)
        pll_refclk = OSICLK_VAL;
    else if (READ_REG(RCU->PLLCFG_bit.REFSRC) == RCU_PLLCFG_REFSRC_OSECLK)
        pll_refclk = OSECLK_VAL;
    else // (READ_REG(RCU->PLLCFG_bit.REFSRC) == RCU_PLLCFG_REFSRC_PLLEXTCLK)
        pll_refclk = PLLEXTCLK_VAL;

    return (pll_refclk * pll_fbdiv) / (pll_refdiv * pll_div1 * pll_div2);
}

/**
  * @brief   Получение значения частоты тактового сигнала PLLDIVCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLDivClkFreq()
{
    uint32_t pll_div;

    pll_div = READ_REG(RCU->PLLDIV_bit.DIV) + 1;

    return RCU_GetPLLClkFreq() / pll_div;
}

/**
  * @brief   Получение значения частоты тактового сигнала PLLEXTCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLExtClkFreq()
{
    return PLLEXTCLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала TRACEEXTCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetTraceExtClkFreq()
{
    return TRACEEXTCLK_VAL;
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
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSPIClkFreq(SPI_Num_TypeDef SPIx_Num)
{
    RCU_PeriphClk_TypeDef spi_clk;
    uint32_t div_val;

    spi_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.CLKSEL);
    if (READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(spi_clk) / div_val;
}

/**
  * @brief   Получение значения частоты MILSTDCLK
  * @param   MILSTDx_Num  Порядковый номер блока MILSTD
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetMILSTDClkFreq(MILSTD_Num_TypeDef MILSTDx_Num)
{
    RCU_PeriphClk_TypeDef milstd_clk;
    uint32_t div_val;

    milstd_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG_bit.CLKSEL);
    if (READ_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->MILSTDCFG[MILSTDx_Num].MILSTDCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(milstd_clk) / div_val;
}

/**
  * @brief   Получение значения частоты SPWRCLK
  * @param   SPWRx_Num  Порядковый номер блока SPWR
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSPWRClkFreq(SPWR_Num_TypeDef SPWRx_Num)
{
    uint32_t div_val;

    if (READ_REG(RCU->SPWRCFG[SPWRx_Num].SPWRCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->SPWRCFG[SPWRx_Num].SPWRCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return RCU_GetPLLClkFreq() / div_val;
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
    RCU_TraceClk_TypeDef trace_clk;
    uint32_t div_val;

    trace_clk = (RCU_TraceClk_TypeDef)READ_REG(RCU->TRACECFG_bit.CLKSEL);
    if (READ_REG(RCU->TRACECFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->TRACECFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getTraceClkFreq(trace_clk) / div_val;
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
  * @attention  Если Freq < 10 МГц, то в качестве системной будет использован
  *             выход делителя PLLDIV
  * @param      Ref  Выбор источника опорного сигнала PLL.
  *                  Параметр принимает любое значение из @ref RCC_PLLRef_TypeDef.
  * @param      SysClkFreq  Желаемая системная частота в Гц
  *                         Параметр принимает любые значения из диапазона 1000000-200000000, кратные 1000000.
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

    if (SysClkFreq < 20000000) {
        PLL_Init_Struct.DivVal = 9; //div10
        PLL_Init_Struct.DivEn = ENABLE;
        SysClkFreq = SysClkFreq * (PLL_Init_Struct.DivVal + 1);
        sysclk_sel = RCU_SysClk_PLLDivClk;
    } else
        sysclk_sel = RCU_SysClk_PLLClk;

    uint32_t div_solved = 0;
    for (uint32_t div1 = 1; div1 < 8; div1++) {
        for (uint32_t div2 = 1; div2 < 8; div2++) {
            for (uint32_t refdiv = 1; refdiv < 64; refdiv++) {
                uint32_t tmp_fbdiv = (SysClkFreq * refdiv * div1 * div2) / (ref_freq);
                uint32_t tmp_fvco = (ref_freq * tmp_fbdiv) / (refdiv);
                if ((ref_freq % refdiv == 0) &&
                    ((tmp_fvco % (div1 * div2)) == 0) &&
                    ((tmp_fvco / (div1 * div2)) == SysClkFreq) &&
                    IS_RCU_PLL_VCO_FREQ(tmp_fvco) &&
                    IS_RCU_PLL_FB_DIV(tmp_fbdiv)) {
                    div_solved = 1;
                    PLL_Init_Struct.FbDiv = tmp_fbdiv;
                    PLL_Init_Struct.RefDiv = refdiv;
                    PLL_Init_Struct.Div1 = div1;
                    PLL_Init_Struct.Div2 = div2;
                    break;
                }
            }
            if (div_solved)
                break;
        }
        if (div_solved)
            break;
    }

    if (!div_solved)
        status = ERROR;
    else
        status = RCU_PLL_Init(&PLL_Init_Struct);
    if (status != OK)
        return status;

    if (SysClkFreq >= 180000000) {
        MFLASH_LatencyConfig(6);
        BFLASH_LatencyConfig(6);
    } else if (SysClkFreq >= 150000000) {
        MFLASH_LatencyConfig(5);
        BFLASH_LatencyConfig(5);
    } else if (SysClkFreq >= 120000000) {
        MFLASH_LatencyConfig(4);
        BFLASH_LatencyConfig(4);
    } else if (SysClkFreq >= 90000000) {
        MFLASH_LatencyConfig(3);
        BFLASH_LatencyConfig(3);
    } else if (SysClkFreq >= 60000000) {
        MFLASH_LatencyConfig(2);
        BFLASH_LatencyConfig(2);
    } else if (SysClkFreq >= 30000000) {
        MFLASH_LatencyConfig(1);
        BFLASH_LatencyConfig(1);
    } else {
        MFLASH_LatencyConfig(0);
        BFLASH_LatencyConfig(0);
    }

    status = RCU_SysClkChangeCmd(sysclk_sel);
    return status;
}

/**
  * @brief      Инициализирует PLL согласно параметрам структуры InitStruct.
  *             Значение выходной частоты PLL вычисляется по формуле:<br><br>
  *             <center>FOUT = (FREF x FBDIV) / (REFDIV x DIV1 x DIV2),</center>
  *             где FREF – опорная частота PLL.<br>
  * @attention  При расчете коэффициентов деления PLL должны выполняться следующие условия:
  *             - 8 МГц <= FREF <= 800 МГц (REF),
  *             - 400 МГц <= FIN*FBDIV/REFDIV <= 16000 МГц (VCO),
  *             - 8 МГц <= FOUT <= 1600 МГц;
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
    assert_param(IS_RCU_PLL_FB_DIV(InitStruct->FbDiv));
    assert_param(IS_RCU_PLL_REF_DIV(InitStruct->RefDiv));
    assert_param(IS_RCU_PLL_REF(InitStruct->Ref));
    assert_param(IS_RCU_PLL_DIV1(InitStruct->Div1));
    assert_param(IS_RCU_PLL_DIV2(InitStruct->Div2));

    CLEAR_BIT(RCU->PLLCFG, RCU_PLLCFG_BP_Msk | RCU_PLLCFG_PD_Msk);
    MODIFY_REG(RCU->PLLCFG, (RCU_PLLCFG_FBDIV_Msk | RCU_PLLCFG_REFDIV_Msk | RCU_PLLCFG_DIV1_Msk | RCU_PLLCFG_DIV2_Msk | RCU_PLLCFG_REFSRC_Msk),
               (InitStruct->FbDiv << RCU_PLLCFG_FBDIV_Pos |
                InitStruct->RefDiv << RCU_PLLCFG_REFDIV_Pos |
                InitStruct->Div1 << RCU_PLLCFG_DIV1_Pos |
                InitStruct->Div2 << RCU_PLLCFG_DIV2_Pos |
                InitStruct->Ref << RCU_PLLCFG_REFSRC_Pos));
    MODIFY_REG(RCU->PLLDIV, RCU_PLLDIV_DIV_Msk | RCU_PLLDIV_DIVEN_Msk,
               (InitStruct->DivVal << RCU_PLLDIV_DIV_Pos |
                InitStruct->DivEn << RCU_PLLDIV_DIVEN_Pos));
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
    InitStruct->FbDiv = 16;
    InitStruct->RefDiv = 1;
    InitStruct->Div1 = 1;
    InitStruct->Div2 = 1;
}

/**
  * @brief   Устанавливает все регистры PLL значениями по умолчанию
  * @retval  void
  */
void RCU_PLL_DeInit()
{
    RCU_PLL_OutCmd(DISABLE);
    WRITE_REG(RCU->PLLCFG, RCU_PLLCFG_RST_VAL);
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
        if ((RCU_SysClkStatus() != SysClk)) {
            timeout--;
        } else {
            break;
        }
    }

    if (!timeout) {
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

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
