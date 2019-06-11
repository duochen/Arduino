int vibr_pin = 3;
int LED_Pin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(vibr_pin, INPUT);
  pinMode(LED_Pin, OUTPUT);
}

void loop() {
  int val;
  val = digitalRead(vibr_pin);
  if (val == 1) {
    Serial.print("Val: ");
    Serial.println(val);
    digitalWrite(LED_Pin, HIGH);
    delay(1000);
    digitalWrite(LED_Pin, LOW);
    delay(1000);
  }
  else
    digitalWrite(LED_Pin, LOW);
}
