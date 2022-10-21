#ifndef VARIANT_H
#define VARIANT_H

#include <WVariant.h>

#ifdef __cplusplus
  #include "Uart.h"
extern "C"{
#endif

#define PINS_COUNT           (27u)
#define NUM_DIGITAL_PINS     (24u)
#define NUM_ANALOG_INPUTS    (4u)



// LEDs
// ----
#define PIN_LED_13  (13u)
#define PIN_LED     PIN_LED_13
#define LED_BUILTIN PIN_LED


/*
 * Analog pins
 */
#define PIN_A0               (14ul)
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
#define PIN_LS_0    (21ul)
#define PIN_LS_1    (PIN_LS_0+1)
#define PIN_LS_2    (PIN_LS_0+2)
#define PIN_LS_3    (PIN_LS_0+3)

/*
 * SPI Interfaces
 */
#define PIN_USER_BTN (20ul)

static const uint8_t USER_BTN  = PIN_USER_BTN;

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1


#define PERIPH_SPI SPI0
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
#define WIRE_INTERFACES_COUNT 1

  // "external" public i2c interface
#define PIN_WIRE_SDA         (PIN_A4)
#define PIN_WIRE_SCL         (PIN_A5)
#define PERIPH_WIRE I2C
#define WIRE_IT_HANDLER I2C_IRQHandler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// I2S Interfaces
// --------------
#define I2S_INTERFACES_COUNT 0

// Serial ports
// ------------
#define PIN_UART_TX0 0
#define PIN_UART_RX0 1
#define PIN_UART_TX1 7
#define PIN_UART_RX1 2

#ifdef __cplusplus
  extern arduino::UartSerial Serial;
  extern arduino::UartSerial Serial1;
#endif

#define PIN_MUX_NO 0xfe
#define PIN_MUX_WITH(pinNum) (pinNum)


extern const pin_size_t pins_mux_map[];// key - arduino pin num

pin_size_t pin_get_description_with_pwm(pin_size_t pin_num);
#undef PIN_GET_DESCRIPTION_WITH_PWM
#define PIN_GET_DESCRIPTION_WITH_PWM(pinNum) PIN_GET_DESCRIPTION(pin_get_description_with_pwm(pinNum))


#ifdef __cplusplus
}
#endif
#endif//VARIANT_H