#include "Uart.h"
#include "Arduino.h"

namespace arduino {

void UartSerial::init_gpio_nvic_rcc() {
  const PinDescription *pin_description_tx = &(pins_description_map[_pin_tx]);
  const PinDescription *pin_description_rx = &(pins_description_map[_pin_rx]);
  GPIO_Init_TypeDef GPIO_InitStruct;
  GPIO_StructInit(&GPIO_InitStruct);

#ifdef MCU_K1921VK035

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = pin_description_rx->pin_msk;
  GPIO_InitStruct.Out = DISABLE;
  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.InMode = GPIO_InMode_Schmitt;
  GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
  GPIO_InitStruct.DriveMode = GPIO_DriveMode_HighFast;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_Init(pin_description_rx->port, &GPIO_InitStruct);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = pin_description_tx->pin_msk;
  GPIO_InitStruct.Out = ENABLE;
  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.InMode = GPIO_InMode_Schmitt;
  GPIO_InitStruct.OutMode = GPIO_OutMode_PP;
  GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
  GPIO_InitStruct.DriveMode = GPIO_DriveMode_HighFast;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_Init(pin_description_tx->port, &GPIO_InitStruct);

  UART_Num_TypeDef uart_num = _nt_uart == UART0 ? UART0_Num : UART1_Num;
  RCU_PeriphClk_TypeDef Rcu_uart_clk_sel = RCU_PeriphClk_PLLClk;
  if (RCU->SYSCLKCFG_bit.SYSSEL == RCU_SYSCLKCFG_SYSSEL_OSICLK) {
    Rcu_uart_clk_sel = RCU_PeriphClk_OSIClk;
  }
  if (RCU->SYSCLKCFG_bit.SYSSEL == RCU_SYSCLKCFG_SYSSEL_OSECLK) {
    Rcu_uart_clk_sel = RCU_PeriphClk_OSEClk;
  }
  RCU_UARTClkConfig(uart_num, Rcu_uart_clk_sel, 0, DISABLE);
  RCU_UARTClkCmd(uart_num, ENABLE);
  RCU_UARTRstCmd(uart_num, ENABLE);
  if (_nt_uart == UART0) {
    NVIC_SetPriority(UART0_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART0_RX_IRQn);
    NVIC_SetPriority(UART0_E_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART0_E_RT_IRQn);
    // NVIC_SetPriority(UART0_TX_IRQn,_c_irq_priority);
    // NVIC_EnableIRQ(UART0_TX_IRQn);
  } else {
    NVIC_SetPriority(UART1_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART1_RX_IRQn);
    NVIC_SetPriority(UART1_E_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART1_E_RT_IRQn);
    // NVIC_SetPriority(UART1_TX_IRQn,_c_irq_priority);
    // NVIC_EnableIRQ(UART1_TX_IRQn);
  }

#elif MCU_K1921VK01T
  if (_nt_uart == NT_UART0) {
    if (pin_description_rx->port == NT_GPIOC) {
      NT_COMMON_REG->GPIOPCTLE_bit.PIN0 = GPIO_AltFunc_3; // turn off rx from E0
    }

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_rx->port == NT_GPIOC ? GPIO_AltFunc_2 : GPIO_AltFunc_1;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_PullUp = GPIO_PullUp_En;
    GPIO_Init(pin_description_rx->port, &GPIO_InitStruct);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_tx->port == NT_GPIOC ? GPIO_AltFunc_2 : GPIO_AltFunc_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_Init(pin_description_tx->port, &GPIO_InitStruct);

    NVIC_SetPriority(UART0_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART0_RT_IRQn);
    NVIC_SetPriority(UART0_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART0_RX_IRQn);
    NVIC_SetPriority(UART0_TX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART0_TX_IRQn);
    RCC_UARTClkCmd(NT_UART0, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_UART0, ENABLE);
  }
  if (_nt_uart == NT_UART1) {
    if (pin_description_rx->port == NT_GPIOC) {
      NT_COMMON_REG->GPIOPCTLA_bit.PIN4 = GPIO_AltFunc_3; // turn off rx from A4
    }

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_rx->port == NT_GPIOC ? GPIO_AltFunc_2 : GPIO_AltFunc_1;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_PullUp = GPIO_PullUp_En;
    GPIO_Init(pin_description_rx->port, &GPIO_InitStruct);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_tx->port == NT_GPIOC ? GPIO_AltFunc_2 : GPIO_AltFunc_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_Init(pin_description_tx->port, &GPIO_InitStruct);

    NVIC_SetPriority(UART1_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART1_RT_IRQn);
    NVIC_SetPriority(UART1_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART1_RX_IRQn);
    NVIC_SetPriority(UART1_TX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART1_TX_IRQn);
    RCC_UARTClkCmd(NT_UART1, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_UART1, ENABLE);
  }
  if (_nt_uart == NT_UART2) {
    if (pin_description_rx->port == NT_GPIOF &&
        pin_description_rx->pin_msk == GPIO_Pin_4) {
      NT_COMMON_REG->GPIOPCTLF_bit.PIN11 =
          GPIO_AltFunc_3; // turn off rx from F11
      NT_COMMON_REG->GPIOPCTLD_bit.PIN0 = GPIO_AltFunc_3; // turn off rx from D0
    }
    if (pin_description_rx->port == NT_GPIOD &&
        pin_description_rx->pin_msk == GPIO_Pin_0) {
      NT_COMMON_REG->GPIOPCTLF_bit.PIN11 =
          GPIO_AltFunc_3; // turn off rx from F11
    }

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_rx->port == NT_GPIOD ? GPIO_AltFunc_2
        : pin_description_rx->port == NT_GPIOF &&
                pin_description_rx->pin_msk == GPIO_Pin_4
            ? GPIO_AltFunc_3
            : GPIO_AltFunc_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_PullUp = GPIO_PullUp_En;
    GPIO_Init(pin_description_rx->port, &GPIO_InitStruct);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_tx->port == NT_GPIOD   ? GPIO_AltFunc_2
        : pin_description_tx->port == NT_GPIOC ? GPIO_AltFunc_2
        : pin_description_tx->port == NT_GPIOF ? GPIO_AltFunc_1
                                               : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_Init(pin_description_tx->port, &GPIO_InitStruct);

    NVIC_SetPriority(UART2_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART2_RT_IRQn);
    NVIC_SetPriority(UART2_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART2_RX_IRQn);
    NVIC_SetPriority(UART2_TX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART2_TX_IRQn);
    RCC_UARTClkCmd(NT_UART2, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_UART2, ENABLE);
  }
  if (_nt_uart == NT_UART3) {
    if (pin_description_rx->port == NT_GPIOD) {
      NT_COMMON_REG->GPIOPCTLF_bit.PIN12 =
          GPIO_AltFunc_3; // turn off tx from F12
      NT_COMMON_REG->GPIOPCTLF_bit.PIN13 =
          GPIO_AltFunc_3; // turn off rx from F13
    }

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_rx->port == NT_GPIOD ? GPIO_AltFunc_2 : GPIO_AltFunc_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_rx->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_PullUp = GPIO_PullUp_En;
    GPIO_Init(pin_description_rx->port, &GPIO_InitStruct);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_tx->port == NT_GPIOD ? GPIO_AltFunc_2 : GPIO_AltFunc_1;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_InitStruct.GPIO_Pin = pin_description_tx->pin_msk;
    GPIO_Init(pin_description_tx->port, &GPIO_InitStruct);

    NVIC_SetPriority(UART3_RT_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART3_RT_IRQn);
    NVIC_SetPriority(UART3_RX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART3_RX_IRQn);
    NVIC_SetPriority(UART3_TX_IRQn, _c_irq_priority);
    NVIC_EnableIRQ(UART3_TX_IRQn);
    RCC_UARTClkCmd(NT_UART3, ENABLE);
    RCC_PeriphRstCmd(RCC_PeriphRst_UART3, ENABLE);
  }
#endif
}

UartSerial::UartSerial(UART_TypeDef *nt_uart, int pin_tx, int pin_rx) {
  _nt_uart = nt_uart;
  _pin_tx = pin_tx;
  _pin_rx = pin_rx;
}
void UartSerial::begin(unsigned long baudRate) { begin(baudRate, SERIAL_8N1); }

void UartSerial::begin(unsigned long baudRate, uint16_t config) {

  // tx_in_progress = false;
  init_gpio_nvic_rcc();
  UART_Init_TypeDef UART_InitStruct;
  UART_StructInit(&UART_InitStruct);
  UART_DataWidth_TypeDef DataWidth =
      (config & SERIAL_DATA_MASK) == SERIAL_DATA_5   ? UART_DataWidth_5
      : (config & SERIAL_DATA_MASK) == SERIAL_DATA_6 ? UART_DataWidth_6
      : (config & SERIAL_DATA_MASK) == SERIAL_DATA_7 ? UART_DataWidth_7
      : (config & SERIAL_DATA_MASK) == SERIAL_DATA_8 ? UART_DataWidth_8
                                                     : UART_DataWidth_8;

  UART_StopBit_TypeDef StopBit =
      (config & SERIAL_STOP_BIT_MASK) == SERIAL_STOP_BIT_1   ? UART_StopBit_1
      : (config & SERIAL_STOP_BIT_MASK) == SERIAL_STOP_BIT_2 ? UART_StopBit_2
                                                             : UART_StopBit_1;

  UART_ParityBit_TypeDef ParityBit =
      (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_EVEN  ? UART_ParityBit_Even
      : (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_ODD ? UART_ParityBit_Odd
      : (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_MARK
          ? UART_ParityBit_High
      : (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_NONE
          ? UART_ParityBit_Disable
      : (config & SERIAL_PARITY_MASK) == SERIAL_PARITY_SPACE
          ? UART_ParityBit_Low
          : UART_ParityBit_Disable;
#ifdef MCU_K1921VK035
  UART_InitStruct.Rx = ENABLE;
  UART_InitStruct.Tx = ENABLE;
  UART_InitStruct.FIFO = DISABLE;
  UART_InitStruct.BaudRate = baudRate;
  UART_InitStruct.DataWidth = DataWidth;
  UART_InitStruct.StopBit = StopBit;
  UART_InitStruct.ParityBit = ParityBit;

#elif MCU_K1921VK01T
  UART_InitStruct.UART_ClkFreq = SystemCoreClock;
  UART_InitStruct.UART_FIFOEn = DISABLE;
  UART_InitStruct.UART_BaudRate = baudRate;
  UART_InitStruct.UART_DataWidth = DataWidth;
  UART_InitStruct.UART_StopBit = StopBit;
  UART_InitStruct.UART_ParityBit = ParityBit;
#endif
  // UART_ITCmd (_nt_uart,UART_ITSource_TxFIFOLevel, ENABLE);
  UART_ITCmd(_nt_uart, UART_ITSource_RxFIFOLevel, ENABLE);

  UART_Init(_nt_uart, &UART_InitStruct);
  UART_Cmd(_nt_uart, ENABLE);
}

void UartSerial::end() {
  UART_Cmd(_nt_uart, DISABLE);
  while (_nt_uart->FR_bit.BUSY) {
  };

#ifdef MCU_K1921VK035
  UART_Num_TypeDef uart_num = _nt_uart == UART0 ? UART0_Num : UART1_Num;
  RCU_UARTRstCmd(uart_num, DISABLE);
  RCU_UARTClkCmd(uart_num, DISABLE);

#elif MCU_K1921VK01T
  RCC_UARTClkCmd(_nt_uart, DISABLE);
#endif
  _rxBuffer.clear();
  pinMode(_pin_tx, INPUT);
  pinMode(_pin_rx, INPUT);
  //_txBuffer.clear();
}
int UartSerial::available() { return _rxBuffer.available(); }
int UartSerial::availableForWrite() {
  return 1;
  // return _txBuffer.availableForStore();
}
int UartSerial::peek() { return _rxBuffer.peek(); }
void UartSerial::flush() {
  // while(_txBuffer.available());
}
int UartSerial::read() { return _rxBuffer.read_char(); }

size_t UartSerial::write(const uint8_t data) {
  while (_nt_uart->FR_bit.BUSY) {
  };
  UART_SendData(_nt_uart, data);
  return 1;
}

void UartSerial::IrqHandlerRx() {
  while (!UART_FlagStatus(_nt_uart, UART_Flag_RxFIFOEmpty)) {
    int c = UART_RecieveData(_nt_uart);
    _rxBuffer.store_char(c);
  }
  UART_ITStatusClear(_nt_uart, UART_ITSource_RxFIFOLevel);
}
void UartSerial::IrqHandlerRxTimeout() {
  while (!UART_FlagStatus(_nt_uart, UART_Flag_RxFIFOEmpty)) {
    int c = UART_RecieveData(_nt_uart);
    _rxBuffer.store_char(c);
  }
  UART_ITStatusClear(_nt_uart, UART_ITSource_RecieveTimeout);
}
void UartSerial::IrqHandlerTx() {
  // if(_txBuffer.available()){
  // 	UART_SendData(_nt_uart,_txBuffer.read_char());
  // }
  // else{
  // 	tx_in_progress = false;
  // }
  // UART_ITStatusClear(_nt_uart,UART_ITSource_TxFIFOLevel);
}
} // namespace arduino