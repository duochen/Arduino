int sensorValue=0;
int touchpin=A0; // sets the KY-036 metal touch sensor pin A0
int ledpin=7;
int value;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(touchpin);
  Serial.println(sensorValue,DEC); //DEC is ASCII-encoded decimal, same as without the DEC argument
  if(sensorValue>265) // the sensorValue may seem RANDOM, may need to adjust the analog value to turn on or off the LED
  {
    digitalWrite(ledpin,HIGH);
  }
  else
  {
    digitalWrite(ledpin,LOW);
  }
  delay(1000);
}
