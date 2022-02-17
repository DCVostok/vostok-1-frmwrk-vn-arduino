#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "api/ArduinoAPI.h"

#define interrupts()    __enable_irq()
#define noInterrupts()  __disable_irq()
#define digitalPinToInterrupt(P)   ( P ) 

#include "api/itoa.h"

#include "pins_arduino.h"

#include "wiring_analog.h"
#include "wiring_private.h"
#include "api/deprecated-avr-comp/avr/dtostrf.h"
#ifdef __cplusplus
using namespace arduino;
#endif

#endif//ARDUINO_H
