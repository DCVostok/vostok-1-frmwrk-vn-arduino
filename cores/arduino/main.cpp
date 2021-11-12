#define ARDUINO_MAIN
#include "Arduino.h"
#include "system_init.h"

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