int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;

void setup() 
{
  Serial.begin(9000);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}

void loop() 
{
  int aRead = digitalRead(buttonApin);
  Serial.print("ButtonA ");
  Serial.println(aRead);
  if (aRead == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  int bRead = digitalRead(buttonBpin);
  Serial.print("ButtonB ");
  Serial.println(bRead);
  
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
