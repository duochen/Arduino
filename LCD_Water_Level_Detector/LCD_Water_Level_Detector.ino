#include <Wire.h>
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
const int waterSensor = 0;
int waterValue = 0;

void setup() {
  lcd.init();       //initialize the lcd
  lcd.backlight(); //open the backlight
  lcd.setCursor(0, 0);
  lcd.print(" Water Sensor ");
}

void loop() {
  int waterValue = analogRead(waterSensor); // get water sensor value
  lcd.setCursor(6, 1);    //place cursor at 6 column,2 row
  lcd.print(waterValue);  //value displayed on lcd
  delay(200);             //delay 200ms
  lcd.setCursor(0, 1);    //place cursor at 1 column,2 row
  lcd.print(" ");         //Add 16 spaces to make sure the remaining characters
}
