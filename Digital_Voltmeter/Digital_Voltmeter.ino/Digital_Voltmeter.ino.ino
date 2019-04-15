#include "LiquidCrystal.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float input_voltage = 0.0;
float temp = 0.0;
float r1 = 90900.0;
float r2 = 10000.0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("DIGITAL VOLTMETER");
}

void loop() {
  int analog_value = analogRead(A0);
  temp = (analog_value * 5.0) / 1024.0;
  input_voltage = temp / (r2 / (r1 + r2));
  
  if (input_voltage < 0.1) {
    input_voltage = 0.0;
  }
  
  Serial.print("v= ");
  Serial.println(input_voltage);
  lcd.setCursor(0, 1);
  lcd.print("Voltage= ");
  lcd.print(input_voltage);
  delay(300);
}
