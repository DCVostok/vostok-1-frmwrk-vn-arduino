#ifndef VARIANT_H
#define VARIANT_H

#include <WVariant.h>

#ifdef __cplusplus
  #include "Uart.h"
#endif

#define PINS_COUNT           (27u)
#define NUM_DIGITAL_PINS     (27u)
#define NUM_ANALOG_INPUTS    (6u)



// LEDs
// ----
#define PIN_LED_13  (13u)
#define PIN_LED     PIN_LED_13
#define LED_BUILTIN PIN_LED


/*
 * Analog pins
 */
#define PIN_A0               (22ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A4               (PIN_A0 + 4)
#define PIN_A5               (PIN_A0 + 5)


static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;

#define MAX_ADC_RESOLUTION   12

/* 
 * Level shifter control pins 
 */ 
#define PIN_LS_0    (29ul)
#define PIN_LS_1    (PIN_LS_0+1)
#define PIN_LS_2    (PIN_LS_0+2)
#define PIN_LS_3    (PIN_LS_0+3)
#define PIN_LS_4    (PIN_LS_0+4)
#define PIN_LS_5    (PIN_LS_0+5)

/*
 * SPI Interfaces
 */
#define PIN_USER_BTN (28ul)

static const uint8_t USER_BTN  = PIN_USER_BTN;

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PERIPH_SPI NT_SPI0

#define PIN_SPI_MISO         (12)
#define PIN_SPI_SCK          (13)
#define PIN_SPI_MOSI         (11)
#define PIN_SPI_SS           (10)
static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;


/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

  // "external" public i2c interface
#define PIN_WIRE_SDA         (PIN_A5)
#define PIN_WIRE_SCL         (PIN_A4)
#define PERIPH_WIRE NT_I2C0
#define WIRE_IT_HANDLER I2C0_IRQHandler

#define PIN_WIRE1_SDA         (20u)
#define PIN_WIRE1_SCL         (21u)
#define PERIPH_WIRE1 NT_I2C1
#define WIRE1_IT_HANDLER I2C1_IRQHandler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// I2S Interfaces
// --------------
#define I2S_INTERFACES_COUNT 0

// Serial ports
// ------------
#define PIN_UART_TX0 (0u)
#define PIN_UART_RX0 (1u)
#define PIN_UART_TX1 (18u)
#define PIN_UART_RX1 (19u)
#define PIN_UART_TX2 (16u)
#define PIN_UART_RX2 (17u)
#define PIN_UART_TX3 (14u)
#define PIN_UART_RX3 (15u)

#ifdef __cplusplus
  extern arduino::UartSerial Serial;
  extern arduino::UartSerial Serial1;
  extern arduino::UartSerial Serial2;
  extern arduino::UartSerial Serial3;
#endif

#endif//VARIANT_H