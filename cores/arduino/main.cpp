#define ARDUINO_MAIN
#include "Arduino.h"

/*
 * \brief Main entry point of Arduino application
 */
int main( void )
{
  init();
  
  initVariant();

  setup();

  for (;;)
  {
    loop();
    //if (serialEventRun) serialEventRun();
  }

  return 0;
}