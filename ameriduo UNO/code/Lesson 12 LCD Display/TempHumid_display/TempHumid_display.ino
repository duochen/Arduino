#include <LiquidCrystal.h>
#include <SimpleDHT.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    return;
  }

  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");

  // set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print((int)temperature);  
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print((int)humidity);  
}
