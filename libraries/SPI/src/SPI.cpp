#include "SPI.h"
#include "wiring_private.h"

#ifdef MCU_K1921VK035
#define SPI_Cmd(spi, cmd) SPI_Cmd(cmd)
#define SPI_Init(spi, init_struct) SPI_Init(init_struct)
#define SPI_SCKDivConfig(spi, SCKDiv, SCKDivExtra)                             \
  SPI_SCKDivConfig(SCKDiv, SCKDivExtra)
#define SPI_SCKConfig(spi, SPI_SCKPhase, SPI_SCKPolarity)                      \
  SPI_SCKConfig(SPI_SCKPhase, SPI_SCKPolarity)
#define SPI_SendData(spi, data) SPI_SendData(data)
#define SPI_FlagStatus(spi, flag) SPI_FlagStatus(flag)
#define SPI_RecieveData(spi) SPI_RecieveData()
#endif
namespace arduino {
SPIClassK1921VK::SPIClassK1921VK(SPI_TypeDef *spi, pin_size_t pinMISO,
                                 pin_size_t pinSCK, pin_size_t pinMOSI) {
  _initialized = false;
  _interruptMode = SPI_IRQ_PROTECT_MODE_NONE;
  _interruptPortNum = (IRQn_Type)0;
  _spi = spi;
  // pins
  _pinMISO = pinMISO;
  _pinSCK = pinSCK;
  _pinMOSI = pinMOSI;
}

void SPIClassK1921VK::begin() {
  init();
  config(DEFAULT_SPI_SETTINGS);
}

void SPIClassK1921VK::init() {
  if (_initialized)
    return;
  const PinDescription *pin_description_SCK = PIN_GET_DESCRIPTION(_pinSCK);
  const PinDescription *pin_description_MOSI = PIN_GET_DESCRIPTION(_pinMOSI);
  const PinDescription *pin_description_MISO = PIN_GET_DESCRIPTION(_pinMISO);
  digital_pin_use_hook(_pinSCK);
  digital_pin_use_hook(_pinMOSI);
  digital_pin_use_hook(_pinMISO);

  GPIO_Init_TypeDef GPIO_InitStruct;
#ifdef MCU_K1921VK035
  RCU_SPIClkConfig(RCU_PeriphClk_PLLClk, 0, DISABLE);
  RCU_SPIRstCmd(ENABLE);
  RCU_SPIClkCmd(ENABLE);
  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.Pin = pin_description_SCK->pin_msk;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_InitStruct.Out = ENABLE;
  GPIO_InitStruct.OutMode = GPIO_OutMode_PP;
  GPIO_Init(pin_description_SCK->port, &GPIO_InitStruct);

  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.Pin = pin_description_MOSI->pin_msk;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_InitStruct.Out = ENABLE;
  GPIO_InitStruct.OutMode = GPIO_OutMode_PP;
  GPIO_Init(pin_description_MOSI->port, &GPIO_InitStruct);

  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.Pin = pin_description_MISO->pin_msk;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_InitStruct.Out = DISABLE;
  GPIO_Init(pin_description_MISO->port, &GPIO_InitStruct);
#elif MCU_K1921VK01T
  if (_spi == NT_SPI0) {
    // sclk A6, C9
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_SCK->port == NT_GPIOA ? GPIO_AltFunc_1 : GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_SCK->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_SCK->port, &GPIO_InitStruct);
    // mosi A1,C11
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MOSI->port == NT_GPIOA
                                       ? GPIO_AltFunc_1
                                       : GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MOSI->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_MOSI->port, &GPIO_InitStruct);
    // miso A7,C10
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MISO->port == NT_GPIOA
                                       ? GPIO_AltFunc_1
                                       : GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MISO->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_Dis;
    GPIO_Init(pin_description_MISO->port, &GPIO_InitStruct);
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI1, ENABLE);
  }
  if (_spi == NT_SPI1) {
    // sclk B1,E9
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_SCK->port == NT_GPIOB ? GPIO_AltFunc_2 : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_SCK->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_SCK->port, &GPIO_InitStruct);
    // mosi A2,F0
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MOSI->port == NT_GPIOA
                                       ? GPIO_AltFunc_2
                                       : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MOSI->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_MOSI->port, &GPIO_InitStruct);
    // miso B2,G2
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MISO->port == NT_GPIOB
                                       ? GPIO_AltFunc_2
                                       : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MISO->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_Dis;
    GPIO_Init(pin_description_MISO->port, &GPIO_InitStruct);
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI1, ENABLE);
  }
  if (_spi == NT_SPI2) {
    // sclk G5,B14
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc =
        pin_description_SCK->port == NT_GPIOG ? GPIO_AltFunc_2 : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_SCK->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_SCK->port, &GPIO_InitStruct);
    // mosi G6,C6
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MOSI->port == NT_GPIOG
                                       ? GPIO_AltFunc_2
                                       : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MOSI->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(pin_description_MOSI->port, &GPIO_InitStruct);
    // miso F3,B15
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = pin_description_MISO->port == NT_GPIOF
                                       ? GPIO_AltFunc_2
                                       : GPIO_AltFunc_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = pin_description_MISO->pin_msk;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_Dis;
    GPIO_Init(pin_description_MISO->port, &GPIO_InitStruct);
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI2, ENABLE);
  }
  if (_spi == NT_SPI3) {
    // F2 SPI_CLK3 Alt2 sclk
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(NT_GPIOF, &GPIO_InitStruct);
    // F4 SPI_TXD3 Alt2 mosi
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_Out;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
    GPIO_Init(NT_GPIOF, &GPIO_InitStruct);
    // G4 SPI_RXD3 Alt2 miso
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_AltFunc = GPIO_AltFunc_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
    GPIO_InitStruct.GPIO_Out = GPIO_Out_Dis;
    GPIO_Init(NT_GPIOG, &GPIO_InitStruct);

    RCC_PeriphRstCmd(RCC_PeriphRst_SPI3, ENABLE);
  }
  RCC_SPIClkCmd(_spi, ENABLE);
#endif
  _initialized = true;
}
void SPIClassK1921VK::setClock(uint32_t clk) {
  volatile uint32_t SCKDiv;
  uint32_t SCKDivExtra = 1;
  do {
    SCKDivExtra++;
    SCKDiv = (SystemCoreClock / clk / SCKDivExtra) - 1;
  } while (SCKDiv > 0xff);

  SPI_SCKDivConfig(_spi, SCKDiv, SCKDivExtra);
}

void SPIClassK1921VK::config(SPISettings settings) {
  SPI_Cmd(_spi, DISABLE);

  SPI_Init_TypeDef spi_init_struct;
  SPI_StructInit(&spi_init_struct);
  spi_init_struct.DataWidth = SPI_DataWidth_8;
  spi_init_struct.FrameFormat = SPI_FrameFormat_SPI;
  spi_init_struct.Mode = SPI_Mode_Master;
  spi_init_struct.SCKDiv = 1;
  spi_init_struct.SCKDivExtra = 2;
  SPI_Init(_spi, &spi_init_struct);

  setClock(settings.getClockFreq());
  setDataMode(settings.getDataMode());
  _bitOrder = settings.getBitOrder();

  SPI_Cmd(_spi, ENABLE);
}

void SPIClassK1921VK::end() {
  SPI_Cmd(_spi, DISABLE);
#ifdef MCU_K1921VK035
  RCU_SPIRstCmd(DISABLE);
  RCU_SPIClkCmd(DISABLE);

#elif MCU_K1921VK01T
  if (_spi == NT_SPI0) {
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI0, DISABLE);
  }
  if (_spi == NT_SPI1) {
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI1, DISABLE);
  }
  if (_spi == NT_SPI2) {
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI2, DISABLE);
  }
  if (_spi == NT_SPI3) {
    RCC_PeriphRstCmd(RCC_PeriphRst_SPI3, DISABLE);
  }
  RCC_SPIClkCmd(_spi, DISABLE);
#endif
  pinMode(_pinSCK, INPUT);
  pinMode(_pinMOSI, INPUT);
  pinMode(_pinMISO, INPUT);
}

void SPIClassK1921VK::usingInterrupt(int interruptNumber) {
  const PinDescription *pin_description =
      PIN_GET_DESCRIPTION((pin_size_t)interruptNumber);
  noInterrupts();
  if (pin_description == NULL || _interruptMode == SPI_IRQ_PROTECT_MODE_GPIO) {
    _interruptMode = SPI_IRQ_PROTECT_MODE_GLOBAL;
  } else {
    _interruptMode = SPI_IRQ_PROTECT_MODE_GPIO;
    _interruptPortNum = GPIO_PORT_TO_IRQ(pin_description->port);
  }
  interrupts();
}

void SPIClassK1921VK::notUsingInterrupt(int interruptNumber) {
  const PinDescription *pin_description =
      PIN_GET_DESCRIPTION((pin_size_t)interruptNumber);
  if (pin_description == NULL) {
  }
  noInterrupts();
  _interruptMode = SPI_IRQ_PROTECT_MODE_NONE;

  interrupts();
}

void SPIClassK1921VK::beginTransaction(SPISettings settings) {
  if (_interruptMode != SPI_IRQ_PROTECT_MODE_NONE) {
    if (_interruptMode == SPI_IRQ_PROTECT_MODE_GLOBAL) {
      noInterrupts();
    }
    if (_interruptMode == SPI_IRQ_PROTECT_MODE_GPIO) {
      NVIC_DisableIRQ(_interruptPortNum);
    }
  }

  config(settings);
}

void SPIClassK1921VK::endTransaction(void) {
  if (_interruptMode != SPI_IRQ_PROTECT_MODE_NONE) {
    if (_interruptMode == SPI_IRQ_PROTECT_MODE_GLOBAL) {
      interrupts();
    }
    if (_interruptMode == SPI_IRQ_PROTECT_MODE_GPIO) {
      NVIC_EnableIRQ(_interruptPortNum);
    }
  }
}

void SPIClassK1921VK::setBitOrder(BitOrder order) { _bitOrder = order; }

void SPIClassK1921VK::setDataMode(uint8_t mode) {
  SPI_SCKPhase_TypeDef SPI_SCKPhase = mode == SPI_MODE0 || mode == SPI_MODE2
                                          ? SPI_SCKPhase_CaptureRise
                                          : SPI_SCKPhase_CaptureFall;
  SPI_SCKPolarity_TypeDef SPI_SCKPolarity =
      mode == SPI_MODE0 || mode == SPI_MODE1 ? SPI_SCKPolarity_SteadyLow
                                             : SPI_SCKPolarity_SteadyHigh;
  SPI_SCKConfig(_spi, SPI_SCKPhase, SPI_SCKPolarity);
}

void SPIClassK1921VK::setClockDivider(uint8_t div) {
  setClock(SystemCoreClock / div);
}

uint8_t SPIClassK1921VK::transfer(uint8_t data) {
  if (_bitOrder == LSBFIRST) {
    data = bitFlip(data);
  }
  SPI_SendData(_spi, data);
  while (SPI_FlagStatus(_spi, SPI_Flag_Busy))
    ;
  data = SPI_RecieveData(_spi);
  if (_bitOrder == LSBFIRST) {
    data = bitFlip(data);
  }
  return data;
}

uint16_t SPIClassK1921VK::transfer16(uint16_t data) {
  union {
    uint16_t val;
    struct {
      uint8_t lsb;
      uint8_t msb;
    };
  } t;

  t.val = data;

  if (_bitOrder == LSBFIRST) {
    t.lsb = transfer(t.lsb);
    t.msb = transfer(t.msb);
  } else {
    t.msb = transfer(t.msb);
    t.lsb = transfer(t.lsb);
  }

  return t.val;
}

void SPIClassK1921VK::transfer(void *buf, size_t count) {
  uint8_t *buffer = reinterpret_cast<uint8_t *>(buf);
  for (size_t i = 0; i < count; i++) {
    *buffer = transfer(*buffer);
    buffer++;
  }
}

void SPIClassK1921VK::attachInterrupt() {
  // Should be enableInterrupt()
}

void SPIClassK1921VK::detachInterrupt() {
  // Should be disableInterrupt()
}
} // namespace arduino

#if SPI_INTERFACES_COUNT > 0

arduino::SPIClassK1921VK SPI(PERIPH_SPI, PIN_SPI_MISO, PIN_SPI_SCK,
                             PIN_SPI_MOSI);
#endif
#if SPI_INTERFACES_COUNT > 1
arduino::SPIClassK1921VK SPI1(PERIPH_SPI1, PIN_SPI1_MISO, PIN_SPI1_SCK,
                              PIN_SPI1_MOSI);
#endif
#if SPI_INTERFACES_COUNT > 2
arduino::SPIClassK1921VK SPI2(PERIPH_SPI2, PIN_SPI2_MISO, PIN_SPI2_SCK,
                              PIN_SPI2_MOSI);
#endif
#if SPI_INTERFACES_COUNT > 3
arduino::SPIClassK1921VK SPI3(PERIPH_SPI3, PIN_SPI3_MISO, PIN_SPI3_SCK,
                              PIN_SPI3_MOSI);
#endif
#if SPI_INTERFACES_COUNT > 4
arduino::SPIClassK1921VK SPI4(PERIPH_SPI4, PIN_SPI4_MISO, PIN_SPI4_SCK,
                              PIN_SPI4_MOSI);
#endif
#if SPI_INTERFACES_COUNT > 5
arduino::SPIClassK1921VK SPI5(PERIPH_SPI5, PIN_SPI5_MISO, PIN_SPI5_SCK,
                              PIN_SPI5_MOSI);
#endif
