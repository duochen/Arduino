#define ctsPin 2 // Pin for capacitive touch sensor

int ledPin = 13; // pin for the LED

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ctsPin, INPUT);
}

void loop() {
  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("not touched");
  }
  delay(500);
}
