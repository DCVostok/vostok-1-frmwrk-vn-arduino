extern "C" {
#include <string.h>
}

#include <Arduino.h>
#include <wiring_private.h>

#include "Wire.h"
#ifdef MCU_K1921VK035
#define I2C_Cmd(_i2c, cmd) I2C_Cmd(cmd)
#define I2C_ITCmd(_i2c, cmd) I2C_ITCmd(cmd)
#define I2C_StartCmd(_i2c) I2C_StartCmd()
#define I2C_StopCmd(_i2c) I2C_StopCmd()
#define I2C_SetSlaveAddr(_i2c, addr) I2C_SetSlaveAddr(addr)
#define I2C_SlaveCmd(_i2c, cmd) I2C_SlaveCmd(cmd)
#define I2C_GetState(_i2c) I2C_GetState()
#define I2C_SetData(_i2c, data) I2C_SetData(data)
#define I2C_ITStatusClear(_i2c) I2C_ITStatusClear()
#define I2C_GetData(_i2c) I2C_GetData()
#define I2C_NACKCmd(_i2c) I2C_NACKCmd()

#endif
namespace arduino {
TwoWire::TwoWire(I2C_TypeDef *i2c, uint8_t pinSDA, uint8_t pinSCL) {
  this->_i2c = i2c;
  this->_uc_pinSDA = pinSDA;
  this->_uc_pinSCL = pinSCL;
  _transmissionBegun = false;
  _i2c_periph_status = I2C_STATUS_DONE;
  _mode = OFF;
}

void TwoWire::init_periph(void) {
  GPIO_Init_TypeDef GPIO_InitStruct;

  const PinDescription *pin_description_sda = PIN_GET_DESCRIPTION(_uc_pinSDA);
  if (pin_description_sda == NULL) {
    return;
  }
  const PinDescription *pin_description_scl = PIN_GET_DESCRIPTION(_uc_pinSCL);
  if (pin_description_scl == NULL) {
    return;
  }
  digital_pin_use_hook(_uc_pinSDA);
  digital_pin_use_hook(_uc_pinSCL);

#ifdef MCU_K1921VK035
  NVIC_EnableIRQ(I2C_IRQn);
  NVIC_SetPriority(I2C_IRQn, 0);
  RCU_APBClkCmd(RCU_APBClk_I2C, ENABLE);
  RCU_APBRstCmd(RCU_APBRst_I2C, ENABLE);
  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.AltFunc = ENABLE;
  GPIO_InitStruct.Pin = pin_description_sda->pin_msk;
  GPIO_InitStruct.Digital = ENABLE;
  GPIO_InitStruct.Out = ENABLE;
  GPIO_InitStruct.OutMode = GPIO_OutMode_OD;
  GPIO_InitStruct.PullMode = GPIO_PullMode_PU;
  GPIO_InitStruct.InMode = GPIO_InMode_Schmitt;
  GPIO_Init(pin_description_sda->port, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = pin_description_scl->pin_msk;
  GPIO_Init(pin_description_scl->port, &GPIO_InitStruct);
#elif MCU_K1921VK01T
  NVIC_EnableIRQ(_i2c == NT_I2C0 ? I2C0_IRQn : I2C1_IRQn);
  RCC_PeriphClkCmd(_i2c == NT_I2C0 ? RCC_PeriphClk_I2C0 : RCC_PeriphClk_I2C1,
                   ENABLE);
  RCC_PeriphRstCmd(_i2c == NT_I2C0 ? RCC_PeriphRst_I2C0 : RCC_PeriphRst_I2C1,
                   ENABLE);

  GPIO_InitStruct.GPIO_AltFunc =
      pin_description_sda->port == NT_GPIOG
          ? GPIO_AltFunc_1
          : GPIO_AltFunc_2; // SDA0 on pin G0 use Alt1
  GPIO_InitStruct.GPIO_Dir = GPIO_Dir_In;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AltFunc;
  GPIO_InitStruct.GPIO_Out = GPIO_Out_En;
  GPIO_InitStruct.GPIO_OutMode = GPIO_OutMode_OD;
  GPIO_InitStruct.GPIO_PullUp = GPIO_PullUp_En;
  GPIO_InitStruct.GPIO_Pin = pin_description_sda->pin_msk;
  GPIO_Init(pin_description_sda->port, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_AltFunc =
      pin_description_scl->port == NT_GPIOF ? GPIO_AltFunc_1 : GPIO_AltFunc_2;
  ; // SCL0 on pin F5 use Alt1
  GPIO_InitStruct.GPIO_Pin = pin_description_scl->pin_msk;
  GPIO_Init(pin_description_scl->port, &GPIO_InitStruct);
#endif
  setClock(100000);
  I2C_Cmd(_i2c, ENABLE);
  I2C_ITCmd(_i2c, ENABLE);
}
void TwoWire::begin(void) { // master mode
  if (_mode != OFF) {
    return;
  }
  _mode = MASTER;
  init_periph();
  I2C_SlaveCmd(_i2c, DISABLE);
}

void TwoWire::begin(uint8_t address) { // slave mode
  if (_mode != OFF) {
    return;
  }
  _mode = SLAVE;
  init_periph();
  I2C_SetSlaveAddr(_i2c, address);
  I2C_SlaveCmd(_i2c, ENABLE);
}

void TwoWire::setClock(uint32_t baudrate) {
  uint32_t freq_calc;
  freq_calc = SystemCoreClock / (4 * baudrate);
#ifdef MCU_K1921VK035
  I2C_FSDivHighConfig(freq_calc >> 7);
  I2C_FSDivLowConfig(freq_calc & 0x7F);
#elif MCU_K1921VK01T
  I2C_FSDivConfig(_i2c, freq_calc & 0x7F);
#endif
}

void TwoWire::end() {
  I2C_Cmd(_i2c, DISABLE);
#ifdef MCU_K1921VK035
  NVIC_DisableIRQ(I2C_IRQn);
  RCU_APBRstCmd(RCU_APBRst_I2C, DISABLE);
  RCU_APBClkCmd(RCU_APBClk_I2C, DISABLE);
#elif MCU_K1921VK01T
  NVIC_DisableIRQ(_i2c == NT_I2C0 ? I2C0_IRQn : I2C1_IRQn);
  RCC_PeriphClkCmd(_i2c == NT_I2C0 ? RCC_PeriphClk_I2C0 : RCC_PeriphClk_I2C1,
                   DISABLE);
  RCC_PeriphRstCmd(_i2c == NT_I2C0 ? RCC_PeriphRst_I2C0 : RCC_PeriphRst_I2C1,
                   DISABLE);
#endif
  _mode = OFF;
  pinMode(_uc_pinSDA, INPUT);
  pinMode(_uc_pinSCL, INPUT);
}

size_t TwoWire::requestFrom(uint8_t address, size_t quantity, bool stopBit) {
  uint32_t start_time;
  if (quantity == 0) {
    return 0;
  }

  _rxBuffer.clear();

  _i2cAddress = (address << 1) | WIRE_READ_FLAG;
  _i2c_periph_status = I2C_STATUS_RUN;
  _request_quantity = quantity;
  I2C_StartCmd(_i2c);
  start_time = millis();
  while (_i2c_periph_status == I2C_STATUS_RUN) { // wait
    if (millis() - start_time > TWO_WIRE_TIME_OUT) {
      I2C_StopCmd(_i2c);
      wait_stop();
      ;
      return 0;
    }
  }

  if (_i2c_periph_status != I2C_STATUS_DONE) {
    _rxBuffer.clear();
    I2C_StopCmd(_i2c);
    wait_stop();
    return 0;
  }
  if (stopBit) {
    I2C_StopCmd(_i2c);
    wait_stop();
  }

  return quantity;
}

size_t TwoWire::requestFrom(uint8_t address, size_t quantity) {
  return requestFrom(address, quantity, true);
}

void TwoWire::beginTransmission(uint8_t address) {
  // save address of target and clear buffer
  _txAddress = address;
  _txBuffer.clear();
  _transmissionBegun = true;
}

// Errors:
//  0 : Success
//  1 : Data too long
//  2 : NACK on transmit of address
//  3 : NACK on transmit of data
//  4 : Other error
uint8_t TwoWire::endTransmission(bool stopBit) {
  uint32_t start_time;
  if (!_transmissionBegun) {
    _txBuffer.clear();
    return 4;
  }
  _transmissionBegun = false;
  _i2cAddress = (_txAddress << 1) | WIRE_WRITE_FLAG;
  _i2c_periph_status = I2C_STATUS_RUN;
  I2C_StartCmd(_i2c);
  start_time = millis();
  while (_i2c_periph_status == I2C_STATUS_RUN) { // wait
    if (millis() - start_time > TWO_WIRE_TIME_OUT) {
      I2C_StopCmd(_i2c);
      wait_stop();
      ;
      return 4;
    }
  }

  if (_i2c_periph_status == I2C_STATUS_ADDR_NACK) {
    _txBuffer.clear();
    wait_stop();
    ;
    return 2;
  }
  if (_i2c_periph_status == I2C_STATUS_DATA_NACK) {
    _txBuffer.clear();
    wait_stop();
    ;
    return 3;
  }
  if (_i2c_periph_status == I2C_STATUS_ERROR) {
    _txBuffer.clear();
    wait_stop();
    ;
    return 4;
  }

  if (stopBit) {
    I2C_StopCmd(_i2c);
    wait_stop();
    ;
  }
  return 0;
}

uint8_t TwoWire::endTransmission() { return endTransmission(true); }

size_t TwoWire::write(uint8_t ucData) {
  // No writing, without begun transmission or a full buffer
  if ((!_transmissionBegun && _mode == MASTER) || _txBuffer.isFull() ||
      _mode == OFF) {
    return 0;
  }

  _txBuffer.store_char(ucData);

  return 1;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity) {
  // Try to store all data
  for (size_t i = 0; i < quantity; ++i) {
    // Return the number of data stored, when the buffer is full (if write
    // return 0)
    if (!write(data[i]))
      return i;
  }

  // All data stored
  return quantity;
}

int TwoWire::available(void) { return _rxBuffer.available(); }

int TwoWire::read(void) { return _rxBuffer.read_char(); }

int TwoWire::peek(void) { return _rxBuffer.peek(); }

void TwoWire::flush(void) {
  // Do nothing, use endTransmission(..) to force
  // data transfer.
}

void TwoWire::onReceive(void (*function)(int)) {
  _onReceiveCallback = function;
}

void TwoWire::onRequest(void (*function)(void)) {
  _onRequestCallback = function;
}

void TwoWire::wait_stop() {
  while (_i2c->CTL0_bit.STOP) {
    // while (_i2c->CST_bit.BB) {
    //   /* code */
    // }
    if (_i2c->ST_bit.MODE == 0) {
      _i2c->CTL0_bit.STOP = 0;
      break;
    }
  }
}

void TwoWire::onService(void) {
  switch (I2C_GetState(_i2c)) {
  case I2C_State_STDONE:
    I2C_SetData(_i2c, _i2cAddress);
    break;
  case I2C_State_RSDONE:
    I2C_SetData(_i2c, _i2cAddress);
    break;

  case I2C_State_MTADPA: // master sent write_ADDR and receive ACK
    if (_txBuffer.available()) {
      I2C_SetData(_i2c, _txBuffer.read_char());
    } else {
      I2C_StopCmd(_i2c);
      _i2c_periph_status = I2C_STATUS_DONE;
    }
    break;

  case I2C_State_MTADNA: // master sent write_ADDR and receive NACK
    I2C_StopCmd(_i2c);
    _i2c_periph_status = I2C_STATUS_ADDR_NACK;
    break;

  case I2C_State_MTDAPA: // master sent byte
    if (_txBuffer.available()) {
      I2C_SetData(_i2c, _txBuffer.read_char());
    } else {
      I2C_StopCmd(_i2c);
      _i2c_periph_status = I2C_STATUS_DONE;
    }
    break;

  case I2C_State_MTDANA: // master sent byte NACK
    I2C_StopCmd(_i2c);
    _i2c_periph_status = I2C_STATUS_DATA_NACK;
    break;

  case I2C_State_MRADPA: // master sent read_ADDR and receive ACK
    if (_request_quantity <= 1) {
      I2C_NACKCmd(_i2c);
    }
    break;

  case I2C_State_MRADNA: // master sent read_ADDR and receive NACK
    I2C_StopCmd(_i2c);
    _i2c_periph_status = I2C_STATUS_ADDR_NACK;
    break;

  case I2C_State_MRDAPA: // master read byte
    _rxBuffer.store_char(I2C_GetData(_i2c));
    _request_quantity--;
    if (_request_quantity == 1) {
      I2C_NACKCmd(_i2c);
    }
    break;

  case I2C_State_MRDANA: // master read last byte after NACK
    _rxBuffer.store_char(I2C_GetData(_i2c));
    _request_quantity = 0;
    _i2c_periph_status = I2C_STATUS_DONE;
    break;

  case I2C_State_MTMCER:

    break;

  case I2C_State_SRADPA: // slave adrr match
    // if(_onReceiveCallback != NULL && _rxBuffer.available()){
    //   _onReceiveCallback(_rxBuffer.available());
    // }
    _rxBuffer.clear();
    break;

  case I2C_State_SRDAPA: // slave read byte
    if (_rxBuffer.isFull()) {
      I2C_NACKCmd(_i2c);
    } else {
      _rxBuffer.store_char(I2C_GetData(_i2c));
    }
    break;

  case I2C_State_STADPA: // master request data
    if (_onRequestCallback != NULL) {
      _txBuffer.clear();
      _onRequestCallback();
    }
    if (_txBuffer.available()) {
      I2C_SetData(_i2c, _txBuffer.read_char());
    } else {
      I2C_SetData(_i2c, 0x0);
    }
    break;

  case I2C_State_STDAPA:
    if (_txBuffer.available()) {
      I2C_SetData(_i2c, _txBuffer.read_char());
    } else {
      I2C_SetData(_i2c, 0);
    }
    break;

  case I2C_State_STDANA:
    if (_txBuffer.available()) {
      I2C_SetData(_i2c, _txBuffer.read_char());
    } else {
      I2C_SetData(_i2c, 0);
    }
    break;

  case I2C_State_SSTOP:
    if (_onReceiveCallback != NULL) {
      _onReceiveCallback(_rxBuffer.available());
    }
    _rxBuffer.clear();

    break;

  case I2C_State_BERROR:
    _i2c_periph_status = I2C_STATUS_ERROR;
    break;

  default:
    break;
  }
  I2C_ITStatusClear(_i2c);
}
} // namespace arduino

#if WIRE_INTERFACES_COUNT > 0
arduino::TwoWire Wire(PERIPH_WIRE, PIN_WIRE_SDA, PIN_WIRE_SCL);

extern "C" {
void WIRE_IT_HANDLER(void) { Wire.onService(); }
}
#endif

#if WIRE_INTERFACES_COUNT > 1
arduino::TwoWire Wire1(PERIPH_WIRE1, PIN_WIRE1_SDA, PIN_WIRE1_SCL);
extern "C" {
void WIRE1_IT_HANDLER(void) { Wire1.onService(); }
}
#endif

#if WIRE_INTERFACES_COUNT > 2
arduino::TwoWire Wire2(&PERIPH_WIRE2, PIN_WIRE2_SDA, PIN_WIRE2_SCL);
extern "C" {
void WIRE2_IT_HANDLER(void) { Wire2.onService(); }
}
#endif

#if WIRE_INTERFACES_COUNT > 3
arduino::TwoWire Wire3(&PERIPH_WIRE3, PIN_WIRE3_SDA, PIN_WIRE3_SCL);
extern "C" {
void WIRE3_IT_HANDLER(void) { Wire3.onService(); }
}
#endif

#if WIRE_INTERFACES_COUNT > 4
arduino::TwoWire Wire4(&PERIPH_WIRE4, PIN_WIRE4_SDA, PIN_WIRE4_SCL);
extern "C" {
void WIRE4_IT_HANDLER(void) { Wire4.onService(); }
}
#endif

#if WIRE_INTERFACES_COUNT > 5
arduino::TwoWire Wire5(&PERIPH_WIRE5, PIN_WIRE5_SDA, PIN_WIRE5_SCL);
extern "C" {
void WIRE5_IT_HANDLER(void) { Wire5.onService(); }
}
#endif
