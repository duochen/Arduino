// Line Tracking
const int trackingPin=8; //the tracking module attach to pin 8
const int ledPin=13; // pin 13 is built-in LED
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trackingPin,INPUT); // set trackingPin as INPUT
  pinMode(ledPin,OUTPUT); // set ledPin as OUTPUT
}

void loop() 
{
  // put your main code here, to run repeatedly:
  boolean val=digitalRead(trackingPin); // read the value of the tracking module
  if(val==HIGH) // if it is HIGH
  {
    digitalWrite(ledPin,LOW); // turn off the LED
  }
  else {
    digitalWrite(ledPin,HIGH); // turn on the LED
  }
}
