#ifndef TwoWire_h
#define TwoWire_h
#include "Arduino.h"
#include "api/HardwareI2C.h"

#include "api/RingBuffer.h"
#include "wiring_private.h"

#define TWO_WIRE_TIME_OUT (100) // ms

namespace arduino {
class TwoWire : public HardwareI2C {
public:
  TwoWire(I2C_TypeDef *i2c, pin_size_t pinSDA, pin_size_t pinSCL);
  void begin();
  void begin(uint8_t address);
  void end();
  void setClock(uint32_t);

  void beginTransmission(uint8_t);
  uint8_t endTransmission(bool stopBit);
  uint8_t endTransmission(void);

  size_t requestFrom(uint8_t address, size_t quantity, bool stopBit);
  size_t requestFrom(uint8_t address, size_t quantity);

  size_t write(uint8_t data);
  size_t write(const uint8_t *data, size_t quantity);

  virtual int available(void);
  virtual int read(void);
  virtual int peek(void);
  virtual void flush(void);
  void onReceive(void (*)(int));
  void onRequest(void (*)(void));

  inline size_t write(unsigned long n) { return write((uint8_t)n); }
  inline size_t write(long n) { return write((uint8_t)n); }
  inline size_t write(unsigned int n) { return write((uint8_t)n); }
  inline size_t write(int n) { return write((uint8_t)n); }
  using Print::write;

  void onService(void);

private:
  void wait_stop();
  void init_periph();
  typedef enum { MASTER, SLAVE, OFF } eWire_mode_t;

  typedef enum {
    I2C_STATUS_RUN,
    I2C_STATUS_DONE,
    I2C_STATUS_ADDR_NACK,
    I2C_STATUS_DATA_NACK,
    I2C_STATUS_ERROR
  } eI2c_periph_status_t;

  eWire_mode_t _mode;
  I2C_TypeDef *_i2c;
  pin_size_t _uc_pinSDA;
  pin_size_t _uc_pinSCL;

  bool _transmissionBegun;
  volatile eI2c_periph_status_t _i2c_periph_status;
  size_t _request_quantity;
  // RX Buffer
  RingBufferN<256> _rxBuffer;

  // TX buffer
  RingBufferN<256> _txBuffer;
  uint8_t _txAddress;
  uint8_t _i2cAddress;

  static const uint8_t WIRE_WRITE_FLAG = 0;
  static const uint8_t WIRE_READ_FLAG = 1;
  // Callback user functions
  void (*_onRequestCallback)(void);
  void (*_onReceiveCallback)(int);
};
} // namespace arduino
#if WIRE_INTERFACES_COUNT > 0
extern arduino::TwoWire Wire;
#endif
#if WIRE_INTERFACES_COUNT > 1
extern arduino::TwoWire Wire1;
#endif
#if WIRE_INTERFACES_COUNT > 2
extern arduino::TwoWire Wire2;
#endif
#if WIRE_INTERFACES_COUNT > 3
extern arduino::TwoWire Wire3;
#endif
#if WIRE_INTERFACES_COUNT > 4
extern arduino::TwoWire Wire4;
#endif
#if WIRE_INTERFACES_COUNT > 5
extern arduino::TwoWire Wire5;
#endif
#endif
