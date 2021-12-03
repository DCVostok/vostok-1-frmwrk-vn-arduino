#include "Arduino.h"
#include "wiring_private.h"

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse.
 *
 * ATTENTION:
 * This function relies on micros() so cannot be used in noInterrupt() context
 */
uint32_t pulseIn(uint32_t pin, uint32_t state, uint32_t timeout)
{
  // Cache the port and bit of the pin in order to speed up the
  // pulse width measuring loop and achieve finer resolution.
  // Calling digitalRead() instead yields much coarser resolution.
  const PinDescription *pin_description = PIN_GET_DESCRIPTION(pin);
  if(pin_description == NULL){
    return 0;
  }
  if((pin_description->pin_attribute & PIN_ATTR_NEED_LS_CTRL) == PIN_ATTR_NEED_LS_CTRL){
    pinMode(adc_ls_ctrl_map[pin_description->adc_ch], OUTPUT);
    digitalWrite(adc_ls_ctrl_map[pin_description->adc_ch],HIGH);
  }

  uint32_t bit = pin_description->pin_msk;
  __IO uint32_t *portIn = &(pin_description->port->DATA);
  uint32_t stateMask = (state ? bit : 0);
  uint32_t startMicros = micros();

  // wait for any previous pulse to end
  while ((*portIn & bit) == stateMask) {
    if (micros() - startMicros > timeout) {
      return 0;
    }
  }

  // wait for the pulse to start
  while ((*portIn & bit) != stateMask) {
    if (micros() - startMicros > timeout) {
      return 0;
    }
  }

  uint32_t start = micros();
  // wait for the pulse to stop
  while ((*portIn & bit) == stateMask) {
    if (micros() - startMicros > timeout) {
      return 0;
    }
  }
  return (micros() - start);
}

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse.
 *
 * ATTENTION:
 * This function relies on micros() so cannot be used in noInterrupt() context
 */
uint32_t pulseInLong(uint32_t pin, uint32_t state, uint32_t timeout)
{
  return pulseIn(pin, state, timeout);
}
