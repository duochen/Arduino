// Line Tracking Sensor TCRT5000
const int trackingPin = 8; //the tracking module attach to pin 8
const int ledPin = 13; // pin 13 is built-in LED
const int AOpin = A0; // AO pin of TCRT5000 sensor is connected to pin A0 on Arduino
const int buzzerpin = 2; // active buzzer pin

int AnalogValue;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trackingPin, INPUT); // set trackingPin as INPUT (read digital signal from sensor)
  pinMode(AOpin, INPUT); // set analog output pin as INPUT (read analog signal from sensor)
  pinMode(ledPin, OUTPUT); // set ledPin as OUTPUT
  pinMode(buzzerpin, OUTPUT); // set buzzerpin as OUTPUT
}

void loop()
{
  // put your main code here, to run repeatedly:
  boolean val = digitalRead(trackingPin); // read the value of the tracking module
  AnalogValue = analogRead(AOpin);
  Serial.print("Read analog value=");
  Serial.print(AnalogValue);
  Serial.print("\t Digital value=");
  Serial.println(val);

  if (val == HIGH) // if it is HIGH (Object is NOT detected)
  {
    digitalWrite(ledPin, LOW); // turn off the LED
    digitalWrite(LED_BUILTIN, LOW); // turn off the built-in LED on Arduino board
    digitalWrite(buzzerpin, LOW); // buzzer is muted
  }

  // when digital output DO is LOW, it means detected
  else {
    digitalWrite(ledPin, HIGH); // turn on the LED
    digitalWrite(LED_BUILTIN, HIGH); // turn on built-in LED on Arduino board
    digitalWrite(buzzerpin, HIGH); // buzzer turns on
  }

  delay(500);
}
