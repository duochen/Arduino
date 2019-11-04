int knockPin = 10; // Use Pin 10 as our Input
int knockVal = HIGH; // This is where we record our shock measurement

void setup ()
{
  Serial.begin(9600);  
  pinMode (knockPin, INPUT) ; // input from the KY-031
}
void loop ()
{
  knockVal = digitalRead (knockPin) ; // read KY-031 Value
  
  if (knockVal == LOW) // If we see a knock
  {
      Serial.println("KNOCK, KNOCK");
        delay(100);
  }

}
