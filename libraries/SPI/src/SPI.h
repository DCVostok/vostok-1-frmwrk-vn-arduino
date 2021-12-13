#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <Arduino.h>
#include "api/HardwareSPI.h"
#include <inttypes.h>



// SPI_HAS_NOTUSINGINTERRUPT means that SPI has notUsingInterrupt() method
#define SPI_HAS_NOTUSINGINTERRUPT 1

using arduino::SPISettings;
using arduino::SPIMode;
using arduino::DEFAULT_SPI_SETTINGS;
using arduino::SPI_MODE0;
using arduino::SPI_MODE1;
using arduino::SPI_MODE2;
using arduino::SPI_MODE3;


namespace arduino{
class SPIClassK1921VK: public HardwareSPI {
  public:
  SPIClassK1921VK(SPI_TypeDef *spi, pin_size_t pinMISO, pin_size_t pinSCK, pin_size_t pinMOSI);


  uint8_t transfer(uint8_t data);
  uint16_t transfer16(uint16_t data);
  void transfer(void *buf, size_t count);

  // Transaction Functions
  void usingInterrupt(int interruptNumber);
  void notUsingInterrupt(int interruptNumber);
  void beginTransaction(SPISettings settings);
  void endTransaction(void);

  // SPI Configuration methods
  void attachInterrupt();
  void detachInterrupt();

  void begin();
  void end();

  void setBitOrder(BitOrder order);
  void setDataMode(uint8_t uc_mode);
  void setClockDivider(uint8_t uc_div);

  private:
  void init();
  void config(SPISettings settings);
  void setClock(uint32_t clk);

  SPI_TypeDef *_spi;
  pin_size_t _pinMISO;
  pin_size_t _pinMOSI;
  pin_size_t _pinSCK;
  pin_size_t _pinSS;

  BitOrder _bitOrder;
  bool _initialized;
  typedef enum{
    SPI_IRQ_PROTECT_MODE_NONE,
    SPI_IRQ_PROTECT_MODE_GPIO,
    SPI_IRQ_PROTECT_MODE_GLOBAL
  }interruptMode_t;
  interruptMode_t _interruptMode;
  IRQn_Type _interruptPortNum;
};
}//namespace arduino

#if SPI_INTERFACES_COUNT > 0
  extern arduino::SPIClassK1921VK SPI;
#endif
#if SPI_INTERFACES_COUNT > 1
  extern arduino::SPIClassK1921VK SPI1;
#endif
#if SPI_INTERFACES_COUNT > 2
  extern arduino::SPIClassK1921VK SPI2;
#endif
#if SPI_INTERFACES_COUNT > 3
  extern arduino::SPIClassK1921VK SPI3;
#endif
#if SPI_INTERFACES_COUNT > 4
  extern arduino::SPIClassK1921VK SPI4;
#endif
#if SPI_INTERFACES_COUNT > 5
  extern arduino::SPIClassK1921VK SPI5;
#endif



#endif
