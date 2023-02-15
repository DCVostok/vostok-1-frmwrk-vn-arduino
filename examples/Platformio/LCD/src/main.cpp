#include <Arduino.h>
#include "Wire.h"
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules is 0x27, PCF8574A has default address 0x3F 
void setup() {
  Serial.begin(115200);
  Wire.begin();
  lcd.begin();
  lcd.backlight();
}

void loop() {
  Serial.print("Vostok uno-vn035 LCD ");
  Serial.print("millis: ");
  Serial.println(millis());

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vostok uno-vn035 LCD");
  lcd.setCursor(0, 1);
  lcd.print("millis: ");
  lcd.print(millis());
  delay(200);
}
