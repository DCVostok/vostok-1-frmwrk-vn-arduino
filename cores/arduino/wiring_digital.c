#include "Arduino.h"
#include "k1921vk_sdk.h"

#ifdef __cplusplus
extern "C" {
#endif

void pinMode( pin_size_t ulPin, PinMode ulMode ){
  if(ulPin >= PINS_COUNT){
    return;
  }
  PinDescription * pin_description = pins_description_map[ulPin];

  // Set pin mode according to chapter '22.6.3 I/O Pin Configuration'
  switch ( ulMode )
  {
    case INPUT:
      // Set pin to input mode

    break ;

    case INPUT_PULLUP:

    break ;

    case INPUT_PULLDOWN:

    break ;

    case OUTPUT:

    break ;

    default:
      // do nothing
    break ;
  }
}

void digitalWrite( pin_size_t ulPin, PinStatus ulVal )
{
    return;
}

PinStatus digitalRead( pin_size_t ulPin )
{

  return;
}

#ifdef __cplusplus
}
#endif
