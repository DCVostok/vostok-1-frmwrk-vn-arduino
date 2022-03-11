# TimerOne library
    Allows use Timer0 and Timer1 on Vostok boards (Vostok uno-vn35 etc.). 
## void initialize(long microseconds=1000000);
    Init timer and start with period *microseconds*.  
    Default period 1 second.
## void start();
    Start timer from begin of current period.
## void stop();
    Stop timer.
## void restart();
    Start timer from begin of current period.
## void resume();
    Start timer without change of current counter value.
## unsigned long read();
    Read current counter value.
## void attachInterrupt(void (*irq)(), long microseconds=-1);
    Attach interrupt to callback.
## void detachInterrupt();
    Disable interrupt
## void setPeriod(long microseconds);
    Set new timer period and restart timer from begin of period.

## Example 

```
#include <Arduino.h>
#include <TimerOne.h>

PinStatus led_state = HIGH;
void timer_blink(){
  if(led_state == HIGH){
    digitalWrite(13,LOW);
    led_state = LOW;
  }
  else{
    digitalWrite(13,HIGH);
    led_state = HIGH;
  }
  Serial.println("timer_blink");
}

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Timer0.initialize(100000);
  Timer0.attachInterrupt(timer_blink);
  delay(10000);
  Timer0.setPeriod(500000);
}

void loop() {
  
}
```