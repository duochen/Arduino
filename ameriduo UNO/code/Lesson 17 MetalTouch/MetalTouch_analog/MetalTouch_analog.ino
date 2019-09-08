int sensorValue = 0;
int touchpin = A0; // sets the KY-036 metal touch sensor pin A0
int value ;         // defines the numeric variables as value
void setup ()
{
  Serial.begin(9600);
}
void loop ()
{
  sensorValue = analogRead(touchpin);
  Serial.println(sensorValue, DEC);
  delay(1000);
}
