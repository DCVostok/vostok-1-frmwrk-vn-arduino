/**
  ******************************************************************************
  * @file    niietcm4_rcc.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с тактированием
  *          и сбросом периферийных блоков микроконтроллера.
  *
  * @author  НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  * @date    06.11.2015
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
  * <h2><center>&copy; 2015 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_rcc.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup RCC
  * @brief Драйвер для работы с тактированием и сбросом периферийных блоков.
  * @{
  */ 

/** @defgroup RCC_Private Приватные данные
  * @{
  */

/** @defgroup RCC_Private_Defines Приватные константы
  * @{
  */

/** @defgroup RCC_PLL_CONFIG_FREQ_DEFINE Значения различных частот, используемых при настройке PLL
  * @{
  */

#define RCC_PLL_REF_FREQ                ((uint32_t)1000000)     /*!< Частота F_REF, используемая при настройки PLL */
#define RCC_PLL_DIV_EN_FREQ             ((uint32_t)60000000)    /*!< Граничная желаемая системная частота - при значениях частоты меньше нее, настраивается и включается внешний делитель PLL */

/**
  * @}
  */

/** @defgroup RCC_regs_reset_define Начальные значения регистров
  * @{
  */

#define RCC_PLL_CTRL_Reset_Value        ((uint32_t)0x00000000)  /*!< Значение по сбросу регистра PLL_CTRL */
#define RCC_PLL_OD_Reset_Value          ((uint32_t)0x00000000)  /*!< Значение по сбросу регистра PLL_OD */
#define RCC_PLL_NR_Reset_Value          ((uint32_t)0x00000000)  /*!< Значение по сбросу регистра PLL_NR */
#define RCC_PLL_NF_Reset_Value          ((uint32_t)0x00000000)  /*!< Значение по сбросу регистра PLL_NF */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCC_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief  Процедура ожидания смены источника тактового сигнала
  *
  * @retval timeout Значение остатка времени после ожидания.
  */

static uint32_t RCC_WaitClkChange(RCC_SysClk_TypeDef RCC_SysClk)
{
    uint32_t timeout = RCC_CLK_CHANGE_TIMEOUT;

    while(timeout)
    {
        if ((RCC_SysClk_TypeDef)(NT_COMMON_REG->SYS_CLK_bit.CURR_SRC) == RCC_SysClk)
        {
            break;
        }
        else
        {
            timeout--;
        }
    }

    return timeout;
}

/**
  * @brief  Включение генерации тактового сигнала с частой равной половине системной
  *   на выводе H[0]. Функция использует драйвер GPIO для настройки выхода.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState:
  *     - ENABLE - переводит H[0] в выход  включенной альтернативной функцией 2.
  *     - DISABLE - переводит H[0] в состояние по умолчанию.
  * @retval Нет
  */

void RCC_SysClkDiv2Out(FunctionalState State)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(State));

    GPIO_Init_TypeDef GPIO_Init_Struct;

    GPIO_StructInit(&GPIO_Init_Struct);

    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_0;
    if (State == ENABLE)
    {
        GPIO_Init_Struct.GPIO_Dir = GPIO_Dir_Out;
        GPIO_Init_Struct.GPIO_AltFunc = GPIO_AltFunc_2;
        GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_AltFunc;
        GPIO_Init_Struct.GPIO_Out = GPIO_Out_En;
    }

    GPIO_Init(NT_GPIOH, &GPIO_Init_Struct);
}

/**
  * @brief  Автоматическая конфигурация PLL для получения желаемой системной частоты.
  *
  * С учетом данных об источнике частоты для PLL, а также о значении желаемой
  * частоты, вычисляются все необходимые коээффициенты.
  * @attention Если Freq < 60 МГц, то в качестве системной частоты будет использован
  *   выход делителя PLL DIV. В остальных случаях используется выход PLL напрямую.
  *
  * @param  RCC_PLLRef Выбор источника опорного сигнала PLL.
  *   Параметр принимает любое значение из @ref RCC_PLLRef_TypeDef.
  * @param  SysFreq Желаемая системная частота в Гц.
  *   Параметр принимает любые значения из диапазона 1000000-100000000, кратные 1000000.
  * @retval Нет
  */

OperationStatus RCC_PLLAutoConfig(RCC_PLLRef_TypeDef RCC_PLLRef, uint32_t SysFreq)
{
    uint32_t f_in = 0;
    uint32_t nf, nr;
    RCC_PLLNO_TypeDef no;
    uint32_t pll_div = 0;
    OperationStatus status;
    RCC_PLLInit_TypeDef RCC_PLLInit_Struct;
    FunctionalState pll_div_cmd = DISABLE;
    volatile uint32_t pll_stable_wait = RCC_CLK_PLL_STABLE_TIMEOUT;

    /* Check the parameters */
    assert_param(IS_RCC_PLL_REF(RCC_PLLRef));
    assert_param(IS_RCC_SYS_FREQ(SysFreq));

    if (RCC_PLLRef == RCC_PLLRef_XI_OSC)
    {
        f_in = EXT_OSC_VALUE;
    }
    else if (RCC_PLLRef == RCC_PLLRef_USB_CLK)
    {
        if (NT_COMMON_REG->USB_CTRL_bit.FSEL)
        {
            f_in = (uint32_t)(24000000);
        }
        else
        {
            f_in = (uint32_t)(12000000);
        }
    }
    else if (RCC_PLLRef == RCC_PLLRef_USB_60MHz)
    {
        f_in = (uint32_t)(60000000);
    }
    else if (RCC_PLLRef == RCC_PLLRef_ETH_25MHz)
    {
        f_in = (uint32_t)(25000000);
    }

    no = RCC_PLLNO_Div4;
    if ((SysFreq < RCC_PLL_DIV_EN_FREQ))
    {
        pll_div = (RCC_PLL_DIV_EN_FREQ/SysFreq + 1)/2 - 1;
        pll_div_cmd = ENABLE;
    }

    nr = f_in/(2*RCC_PLL_REF_FREQ);
    if (pll_div_cmd == DISABLE)
    {
        nf = ((SysFreq/RCC_PLL_REF_FREQ) * ((uint32_t)no + 1) * nr )/(f_in/RCC_PLL_REF_FREQ);
    }
    else /* (pll_div_cmd == ENABLE) */
    {
        nf = ((SysFreq/RCC_PLL_REF_FREQ) * ((uint32_t)no + 1) * nr * 2*(pll_div+1) )/(f_in/RCC_PLL_REF_FREQ);
    }


    RCC_PLLInit_Struct.RCC_PLLRef = RCC_PLLRef;
    RCC_PLLInit_Struct.RCC_PLLDiv = pll_div;
    RCC_PLLInit_Struct.RCC_PLLNO = no;
    RCC_PLLInit_Struct.RCC_PLLNF = nf;
    RCC_PLLInit_Struct.RCC_PLLNR = nr;

    RCC_PLLInit(&RCC_PLLInit_Struct);

    while(pll_stable_wait)
    {
        pll_stable_wait--;
    }

    if (pll_div_cmd == DISABLE)
    {
        status = RCC_SysClkSel(RCC_SysClk_PLL);
    }
    else /* (pll_div_cmd == ENABLE) */
    {
        status = RCC_SysClkSel(RCC_SysClk_PLLDIV);
    }

    return status;
}

/**
  * @brief  Инициализирует PLL согласно параметрам структуры RCC_PLLInit_Struct.
  *
  * Значение выходной частоты PLL вычисляется с использованием значений
  * опорного NR и выходного NO делителей, а также делителя обратной связи NF
  * по формуле:<br><br>
  *
  * <center>FOUT = (FIN * NF) / (NO * NR),</center>
  *
  * где FIN – входная частота PLL.<br>
  * @attention
  *
  * При расчете коэффициентов деления PLL должны выполняться следующие условия:
  * - 3,2 МГц < FIN < 150 МГц,
  * - 800 КГц < FREF < 8МГц,
  * - 200 МГц < FVCO < 500МГц,
  *
  * где частота фазового детектора FREF вычисляется по формуле:<br><br>
  *
  * <center>FREF = FIN / (2 * NR),</center>
  *
  * а частота FVCO вычисляется по формуле:<br><br>
  *
  * <center>FVCO = FIN * (NF / NR)</center>
  * @param  RCC_PLLInit_Struct Указатель на структуру типа @ref RCC_PLLInit_TypeDef,
  *         которая содержит конфигурационную информацию.
  * @retval Нет
  */

void RCC_PLLInit(RCC_PLLInit_TypeDef* RCC_PLLInit_Struct)
{
    assert_param(IS_RCC_PLLDIV(RCC_PLLInit_Struct->RCC_PLLDiv));
    assert_param(IS_RCC_PLL_NF(RCC_PLLInit_Struct->RCC_PLLNF));
    assert_param(IS_RCC_PLL_NO(RCC_PLLInit_Struct->RCC_PLLNO));
    assert_param(IS_RCC_PLL_NR(RCC_PLLInit_Struct->RCC_PLLNR));
    assert_param(IS_RCC_PLL_REF(RCC_PLLInit_Struct->RCC_PLLRef));

    NT_COMMON_REG->PLL_CTRL_bit.REFSEL = ((uint32_t)(RCC_PLLInit_Struct->RCC_PLLRef));
    NT_COMMON_REG->PLL_CTRL_bit.PLL_DIV = RCC_PLLInit_Struct->RCC_PLLDiv;
    NT_COMMON_REG->PLL_OD = ((uint32_t)(RCC_PLLInit_Struct->RCC_PLLNO));
    NT_COMMON_REG->PLL_NF = RCC_PLLInit_Struct->RCC_PLLNF - 2;
    NT_COMMON_REG->PLL_NR = RCC_PLLInit_Struct->RCC_PLLNR - 2;
}

/**
  * @brief  Заполнение каждого члена структуры RCC_PLLInit_Struct значениями по умолчанию.
  * @param  RCC_PLLInit_Struct Указатель на структуру типа @ref RCC_PLLInit_TypeDef,
  *         которую необходимо проинициализировать.
  * @retval Нет
  */

void RCC_PLLStructInit(RCC_PLLInit_TypeDef* RCC_PLLInit_Struct)
{
    RCC_PLLInit_Struct->RCC_PLLRef = RCC_PLLRef_XI_OSC;
    RCC_PLLInit_Struct->RCC_PLLDiv = 0;
    RCC_PLLInit_Struct->RCC_PLLNO = RCC_PLLNO_Disable;
    RCC_PLLInit_Struct->RCC_PLLNF = 2;
    RCC_PLLInit_Struct->RCC_PLLNR = 2;
}

/**
  * @brief  Устанавливает все регистры PLL значениями по умолчанию.
  * @retval Нет
  */

void RCC_PLLDeInit()
{
    NT_COMMON_REG->PLL_CTRL = RCC_PLL_CTRL_Reset_Value;
    NT_COMMON_REG->PLL_OD = RCC_PLL_OD_Reset_Value;
    NT_COMMON_REG->PLL_NF = RCC_PLL_NF_Reset_Value;
    NT_COMMON_REG->PLL_NR = RCC_PLL_NR_Reset_Value;
}

/**
  * @brief  Управление режимом PowerDown PLL.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_PLLPowerDownCmd(FunctionalState State)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == DISABLE)
    {
        NT_COMMON_REG->PLL_CTRL_bit.PD = 0;
    }
    else if (State == ENABLE)
    {
        NT_COMMON_REG->PLL_CTRL_bit.PD = 1;
    }
}

/**
  * @brief  Включение тактирования выбранного блока периферии.
  * @attention Блоки UART , SPI, ADC, USB управляются отдельно.
  *   - @ref RCC_CLK_Config_UART
  *   - @ref RCC_CLK_Config_SPI
  *   - @ref RCC_CLK_Config_ADC
  *   - @ref RCC_CLK_Config_USB
  * @param  RCC_PeriphClk  Выбор периферии.
  *   Параметр принимает любое значение из @ref RCC_PeriphClk_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_PeriphClkCmd(RCC_PeriphClk_TypeDef RCC_PeriphClk, FunctionalState State)
{
    /* Check the parameters */
    assert_param(IS_RCC_PERIPH_CLK(RCC_PeriphClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    {
        NT_COMMON_REG->APB_CLK |= RCC_PeriphClk;
    }
    else if (State == DISABLE)
    {
        NT_COMMON_REG->APB_CLK &= ~RCC_PeriphClk;
    }
}

/**
  * @brief  Выбор источника для системного тактового сигнала.
  * @param  RCC_SysClk  Выбор источника.
  *   Параметр принимает любое значение из @ref RCC_SysClk_TypeDef.
  * @retval Нет
  */

OperationStatus RCC_SysClkSel(RCC_SysClk_TypeDef RCC_SysClk)
{
    uint32_t timeout;
    OperationStatus status;

    /* Check the parameters */
    assert_param(IS_RCC_SYS_CLK(RCC_SysClk));

    NT_COMMON_REG->SYS_CLK = ((uint32_t)RCC_SysClk);

   timeout = RCC_WaitClkChange(RCC_SysClk);

    if (timeout)
    {
        status = OK;
    }
    else
    {
        status = ERROR;
    }

    return status;
}

/**
  * @brief  Текущий источник системного тактового сигнала.
  * @retval Значение из @ref RCC_SysClk_TypeDef
  */

RCC_SysClk_TypeDef RCC_SysClkStatus()
{
    return((RCC_SysClk_TypeDef)((NT_COMMON_REG->SYS_CLK)>>COMMON_REG_SYS_CLK_CURR_SRC_Pos));
}

/**
  * @brief  Настройка источника и включение тактового сигнала для USB.
  * @param  RCC_USBClk  Выбор источника тактирования.
  *   Параметр принимает любое значение из @ref RCC_USBClk_TypeDef.
  * @param  RCC_USBFreq  Выбор фиксированной частоты на входе CLK_USB.
  *   Параметр принимает любое значение из @ref RCC_USBFreq_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_USBClkConfig(RCC_USBClk_TypeDef RCC_USBClk, RCC_USBFreq_TypeDef RCC_USBFreq, FunctionalState State)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(State));
    assert_param(IS_RCC_USB_CLK(RCC_USBClk));
    assert_param(IS_RCC_USB_FREQ(RCC_USBFreq));

    static union
    {
      __IO uint32_t Value;
      __IO _COMMON_REG_USB_CTRL_bits Bits;
    } USB_CTRL_Shadow;

    USB_CTRL_Shadow.Bits.FSEL = (uint32_t)RCC_USBFreq;
    USB_CTRL_Shadow.Bits.CLKSEL = (uint32_t)RCC_USBClk;
    if (State == ENABLE)
    {
        USB_CTRL_Shadow.Bits.CLKEN = 1;
    }
    else if (State == DISABLE)
    {
        USB_CTRL_Shadow.Bits.CLKEN = 0;
    }

    NT_COMMON_REG->USB_CTRL = USB_CTRL_Shadow.Value;
}

/**
  * @brief  Настройка источника тактового сигнала для выбранного UART.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  RCC_UARTClk  Выбор источника тактирования для UART.
  *   Параметр принимает любое значение из @ref RCC_UARTClk_TypeDef.
  * @retval Нет
  */

void RCC_UARTClkSel(NT_UART_TypeDef* UARTx, RCC_UARTClk_TypeDef RCC_UARTClk)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_RCC_UART_CLK(RCC_UARTClk));

    if (UARTx == NT_UART0)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_UART0_Pos;
    }
    else if (UARTx == NT_UART1)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_UART1_Pos;
    }
    else if (UARTx == NT_UART2)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_UART2_Pos;
    }
    else /* (UARTx == NT_UART3) */
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_UART3_Pos;
    }

    NT_COMMON_REG->UART_SPI_CLK_SEL &= ~(3<<offset);
    NT_COMMON_REG->UART_SPI_CLK_SEL |= (RCC_UARTClk<<offset);
}

/**
  * @brief  Настройка делителя тактового сигнала для выбранного UART.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  DivVal  Значение делителя. Результирующий коэффициент деления вычисляется
  *   по формуле (2*(DivVal+1)).
  *   Параметр принимает любое значение из диапазона 0-63.
  * @param  DivState  Выбор состояния делителя.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_UARTClkDivConfig(NT_UART_TypeDef* UARTx, uint32_t DivVal, FunctionalState DivState)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_RCC_CLK_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    if (UARTx == NT_UART0)
    {
        offset = COMMON_REG_UART_CLK_DIVEN_UART0_Pos;
    }
    else if (UARTx == NT_UART1)
    {
        offset = COMMON_REG_UART_CLK_DIVEN_UART1_Pos;
    }
    else if (UARTx == NT_UART2)
    {
        offset = COMMON_REG_UART_CLK_DIVEN_UART2_Pos;
    }
    else /* (UARTx == NT_UART3) */
    {
        offset = COMMON_REG_UART_CLK_DIVEN_UART3_Pos;
    }

    NT_COMMON_REG->UART_CLK &= ~(0x7F << offset);
    NT_COMMON_REG->UART_CLK |=  (DivVal << (offset+1)) | (DivState << offset);
}

/**
  * @brief  Включение тактирования UART.
  * @param  UARTx  Выбор модуля UART, где x лежит в диапазоне 0-3.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_UARTClkCmd(NT_UART_TypeDef* UARTx, FunctionalState State)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (UARTx == NT_UART0)
    {
        offset = COMMON_REG_UART_CLK_CLKEN_UART0_Pos;
    }
    else if (UARTx == NT_UART1)
    {
        offset = COMMON_REG_UART_CLK_CLKEN_UART1_Pos;
    }
    else if (UARTx == NT_UART2)
    {
        offset = COMMON_REG_UART_CLK_CLKEN_UART2_Pos;
    }
    else /* (UARTx == NT_UART3) */
    {
        offset = COMMON_REG_UART_CLK_CLKEN_UART3_Pos;
    }

    if (State == ENABLE)
    {
        NT_COMMON_REG->UART_CLK |=  (1 << offset);
    }
    else if (State == DISABLE)
    {
        NT_COMMON_REG->UART_CLK &= ~(1 << offset);
    }
}

/**
  * @brief  Настройка источника тактового сигнала для выбранного SPI.
  * @param  SPIx  Выбор модуля SPI, где x лежит в диапазоне 0-3.
  * @param  RCC_SPIClk  Выбор источника тактирования для SPI.
  *   Параметр принимает любое значение из @ref RCC_SPIClk_TypeDef.
  * @retval Нет
  */

void RCC_SPIClkSel(NT_SPI_TypeDef* SPIx, RCC_SPIClk_TypeDef RCC_SPIClk)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_RCC_SPI_CLK(RCC_SPIClk));

    if (SPIx == NT_SPI0)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI0_Pos;
    }
    else if (SPIx == NT_SPI1)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI1_Pos;
    }
    else if (SPIx == NT_SPI2)
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI2_Pos;
    }
    else /* (SPIx == NT_SPI3) */
    {
        offset = COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI3_Pos;
    }

    NT_COMMON_REG->UART_SPI_CLK_SEL &= ~(3<<offset);
    NT_COMMON_REG->UART_SPI_CLK_SEL |= (RCC_SPIClk<<offset);
}


/**
  * @brief  Настройка делителя тактового сигнала для выбранного SPI.
  * @param  SPIx  Выбор модуля SPI, где x лежит в диапазоне 0-3.
  * @param  DivVal  Значение делителя.  Результирующий коэффициент деления вычисляется
  *   по формуле (2*(DivVal+1)).
  *   Параметр принимает любое значение из диапазона 0-63.
  * @param  DivState  Выбор состояния делителя.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_SPIClkDivConfig(NT_SPI_TypeDef* SPIx, uint32_t DivVal, FunctionalState DivState)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_RCC_CLK_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    if (SPIx == NT_SPI0)
    {
        offset = COMMON_REG_SPI_CLK_DIVEN_SPI0_Pos;
    }
    else if (SPIx == NT_SPI1)
    {
        offset = COMMON_REG_SPI_CLK_DIVEN_SPI1_Pos;
    }
    else if (SPIx == NT_SPI2)
    {
        offset = COMMON_REG_SPI_CLK_DIVEN_SPI2_Pos;
    }
    else /* (SPIx == NT_SPI3) */
    {
        offset = COMMON_REG_SPI_CLK_DIVEN_SPI3_Pos;
    }

    NT_COMMON_REG->SPI_CLK &= ~(0x7F << offset);
    NT_COMMON_REG->SPI_CLK |=  (DivVal << (offset+1)) | (DivState << offset);
}

/**
  * @brief  Включение тактирования SPI.
  * @param  SPIx  Выбор модуля SPI, где x лежит в диапазоне 0-3.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_SPIClkCmd(NT_SPI_TypeDef* SPIx, FunctionalState State)
{
    uint32_t offset;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (SPIx == NT_SPI0)
    {
        offset = COMMON_REG_SPI_CLK_CLKEN_SPI0_Pos;
    }
    else if (SPIx == NT_SPI1)
    {
        offset = COMMON_REG_SPI_CLK_CLKEN_SPI1_Pos;
    }
    else if (SPIx == NT_SPI2)
    {
        offset = COMMON_REG_SPI_CLK_CLKEN_SPI2_Pos;
    }
    else /* (SPIx == NT_SPI3) */
    {
        offset = COMMON_REG_SPI_CLK_CLKEN_SPI3_Pos;
    }

    if (State == ENABLE)
    {
        NT_COMMON_REG->SPI_CLK |=  (1 << offset);
    }
    else if (State == DISABLE)
    {
        NT_COMMON_REG->SPI_CLK &= ~(1 << offset);
    }
}

/**
  * @brief  Настройка делителя тактового сигнала для выбранного ADC.
  * @param  RCC_ADCClk  Выбор модуля ADC.
  *   Параметр принимает любое значение из @ref RCC_ADCClk_TypeDef.
  * @param  DivVal  Значение делителя. Результирующий коэффициент деления вычисляется
  *   по формуле (2*(DivVal+1)).
  *   Параметр принимает любое значение из диапазона 0-63.
  * @param  DivState  Выбор состояния делителя.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_ADCClkDivConfig(RCC_ADCClk_TypeDef RCC_ADCClk, uint32_t DivVal, FunctionalState DivState)
{
    uint32_t offset;
    volatile uint32_t* ctrl_reg;

    /* Check the parameters */
    assert_param(IS_RCC_ADC_CLK(RCC_ADCClk));
    assert_param(IS_RCC_CLK_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    if (RCC_ADCClk == RCC_ADCClk_0)
    {
        offset = COMMON_REG_ADC_CTRL0_DIVEN_ADC0_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_1)
    {
        offset = COMMON_REG_ADC_CTRL0_DIVEN_ADC1_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_2)
    {
        offset = COMMON_REG_ADC_CTRL0_DIVEN_ADC2_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_3)
    {
        offset = COMMON_REG_ADC_CTRL0_DIVEN_ADC3_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_4)
    {
        offset = COMMON_REG_ADC_CTRL1_DIVEN_ADC4_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_5)
    {
        offset = COMMON_REG_ADC_CTRL1_DIVEN_ADC5_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_6)
    {
        offset = COMMON_REG_ADC_CTRL1_DIVEN_ADC6_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_7)
    {
        offset = COMMON_REG_ADC_CTRL1_DIVEN_ADC7_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_8)
    {
        offset = COMMON_REG_ADC_CTRL2_DIVEN_ADC8_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else if (RCC_ADCClk == RCC_ADCClk_9)
    {
        offset = COMMON_REG_ADC_CTRL2_DIVEN_ADC9_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else if (RCC_ADCClk == RCC_ADCClk_10)
    {
        offset = COMMON_REG_ADC_CTRL2_DIVEN_ADC10_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else /* (RCC_ADCClk == RCC_ADCClk_11) */
    {
        offset = COMMON_REG_ADC_CTRL2_DIVEN_ADC11_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }

    *ctrl_reg &= ~(0x7F << offset);
    *ctrl_reg |=  (DivVal << (offset+1)) | (DivState << offset);
}

/**
  * @brief  Включение тактирования ADC.
  * @param  RCC_ADCClk  Выбор модуля ADC.
  *   Параметр принимает любое значение из @ref RCC_ADCClk_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_ADCClkCmd(RCC_ADCClk_TypeDef RCC_ADCClk, FunctionalState State)
{
    uint32_t offset;
    volatile uint32_t* ctrl_reg;

    /* Check the parameters */
    assert_param(IS_RCC_ADC_CLK(RCC_ADCClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (RCC_ADCClk == RCC_ADCClk_0)
    {
        offset = COMMON_REG_ADC_CTRL0_CLKEN_ADC0_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_1)
    {
        offset = COMMON_REG_ADC_CTRL0_CLKEN_ADC1_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_2)
    {
        offset = COMMON_REG_ADC_CTRL0_CLKEN_ADC2_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_3)
    {
        offset = COMMON_REG_ADC_CTRL0_CLKEN_ADC3_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL0);
    }
    else if (RCC_ADCClk == RCC_ADCClk_4)
    {
        offset = COMMON_REG_ADC_CTRL1_CLKEN_ADC4_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_5)
    {
        offset = COMMON_REG_ADC_CTRL1_CLKEN_ADC5_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_6)
    {
        offset = COMMON_REG_ADC_CTRL1_CLKEN_ADC6_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_7)
    {
        offset = COMMON_REG_ADC_CTRL1_CLKEN_ADC7_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL1);
    }
    else if (RCC_ADCClk == RCC_ADCClk_8)
    {
        offset = COMMON_REG_ADC_CTRL2_CLKEN_ADC8_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else if (RCC_ADCClk == RCC_ADCClk_9)
    {
        offset = COMMON_REG_ADC_CTRL2_CLKEN_ADC9_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else if (RCC_ADCClk == RCC_ADCClk_10)
    {
        offset = COMMON_REG_ADC_CTRL2_CLKEN_ADC10_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }
    else /* (RCC_ADCClk == RCC_ADCClk_11) */
    {
        offset = COMMON_REG_ADC_CTRL2_CLKEN_ADC11_Pos;
        ctrl_reg = &(NT_COMMON_REG->ADC_CTRL2);
    }

    if (State == ENABLE)
    {
        *ctrl_reg |=  (1 << offset);
    }
    else if (State == DISABLE)
    {
        *ctrl_reg &= ~(1 << offset);
    }

}

/**
  * @brief  Вывод из состояния сброса периферийных блоков.
  * @param  RCC_PeriphRst  Выбор периферийного модуля.
  *   Параметр принимает любое значение из @ref RCC_PeriphRst_TypeDef.
  * @param  State  Выбор состояния.
  *   Параметр принимает любое значение из @ref FunctionalState.
  * @retval Нет
  */

void RCC_PeriphRstCmd(RCC_PeriphRst_TypeDef RCC_PeriphRst, FunctionalState State)
{
    volatile uint32_t* ctrl_reg;
    uint32_t offset = 0;

    /* Check the parameters */
    assert_param(IS_RCC_PERIPH_RST(RCC_PeriphRst));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (RCC_PeriphRst <= RCC_PeriphRst_ETH)
    {
        ctrl_reg = &(NT_COMMON_REG->PER_RST0);
    }
    else
    {
        ctrl_reg = &(NT_COMMON_REG->PER_RST1);
        offset = (uint32_t)RCC_PeriphRst_ETH + 1; //последняя периферия в rst1
    }

    if (State == ENABLE)
    {
        *ctrl_reg |= (1<<(RCC_PeriphRst-offset));
    }
    else if (State == DISABLE)
    {
        *ctrl_reg &= ~(1<<(RCC_PeriphRst-offset));
    }
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

/******************* (C) COPYRIGHT 2015 NIIET *****END OF FILE****/
