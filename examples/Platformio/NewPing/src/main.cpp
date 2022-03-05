#include <Arduino.h>
#include <NewPing.h>

const uint8_t PIN_TRIG = 4;
const uint8_t PIN_ECHO = 5;
NewPing sonar(PIN_TRIG, PIN_ECHO, 500);

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
  pinMode(PIN_TRIG,OUTPUT);
}
int ditance_cm = 0;
void loop() {
  ditance_cm = sonar.ping_cm();
  Serial.println(ditance_cm);
  delay(50);
}
