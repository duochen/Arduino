#define PT 0    // pin A0
int PTvalue;
float PTvoltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  PTvalue = analogRead(PT);  // Read value 0 - 1023
  PTvoltage = PTvalue * 5.0 / 1024;
  Serial.println(PTvoltage);
  delay(1000);
}
