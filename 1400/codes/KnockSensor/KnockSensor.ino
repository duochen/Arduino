int knockPin=10; //use Pin 10 as out Input
int knockVal=HIGH; //This is where we record our shock measurement

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(knockPin,INPUT); // input from the KY-031
}

void loop() {
  // put your main code here, to run repeatedly:
  knockVal=digitalRead(knockPin); // read KY-031 Value
  if(knockVal==LOW) // If we see a knock
  {
    Serial.println("KNOCK, KNOCK"); // print "KNOCK, KNOCK" on serial monitor
    delay(100); // wait for 100 miliseconds
  }
}
