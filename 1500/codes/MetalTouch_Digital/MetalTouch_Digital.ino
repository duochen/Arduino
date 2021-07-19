int ledpin = 7; //set the LED @pin 7
int touchpin = 9; // sets the KY-036 metal touch sensor @pin 9
int value=0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(touchpin, INPUT); //set the metal touch sensor as INPUT
  pinMode(ledpin, OUTPUT); //
  digitalWrite(ledpin, HIGH);
  delay(1000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  value=digitalRead(touchpin); //reads the value of the touchpin
  Serial.println("Touched?");
  Serial.println(value);
  if(value==HIGH) // If the value is HIGH
  {
    digitalWrite(ledpin,HIGH); // it will turn the LED ON, indicating tha the sensor has been triggered
  }
  else
  {
    digitalWrite(ledpin,LOW); // LED is turned off if sensor is not triggered
   }
   delay(500);
}
