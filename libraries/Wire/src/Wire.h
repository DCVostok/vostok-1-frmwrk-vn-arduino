#ifndef TwoWire_h
#define TwoWire_h

#include "api/HardwareI2C.h"

#include "wiring_private.h"
#include "api/RingBuffer.h"

namespace arduino {
class TwoWire : public HardwareI2C
{
  public:
    TwoWire(I2C_TypeDef *i2c, uint8_t pinSDA, uint8_t pinSCL);
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
    size_t write(const uint8_t * data, size_t quantity);

    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive(void(*)(int));
    void onRequest(void(*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

    void onService(void);

  private:
    void init_periph();
    typedef enum {
      MASTER,
      SLAVE
    }eWire_mode_t;
    
    eWire_mode_t _mode;
    I2C_TypeDef* _i2c;
    uint8_t _uc_pinSDA;
    uint8_t _uc_pinSCL;

    bool _transmissionBegun;
    bool _send_txBufferDone;
    size_t _request_quantity;
    // RX Buffer
    RingBufferN<256> _rxBuffer;

    //TX buffer
    RingBufferN<256> _txBuffer;
    uint8_t _txAddress;
    static const uint8_t WIRE_WRITE_FLAG = 1;
    static const uint8_t WIRE_READ_FLAG = 0;
    // Callback user functions
    void (*_onRequestCallback)(void);
    void (*_onReceiveCallback)(int);
};
}
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
