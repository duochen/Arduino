//***************************************************************************************************//
//****** This code is for using KY-038 Microphone Sensor to control 6 LEDs with beat of music *******//
//****** You need to connect the microphone sensor to the Arduino board, as well as connecting 6 LEDs ***//
//****** Refer to the slides for Lesson 07 of Arduino 1400 Advanced Sensors course ********************//
//***************************************************************************************************//

// global variables

// the pin connections for the 6 LEDs
int Led1 = 8;  // Led1 connects to digital pin #8
int Led2 = 9;  // Led2 connects to digital pin #9
int Led3 = 10;  // Led3 connects to digital pin #10
int Led4 = 11;  // Led4 connects to digital pin #11
int Led5 = 12;  // Led5 connects to digital pin #12
int Led6 = 13;  // Led6 connects to digital pin #13

int D0pin = 3;
int A0pin = A0;

int DigitalValue = 0; // variable for receiving digital signal from D0 of Metal touch sensor or Microphone sensor
int AnalogValue = 0; // variable for received analog signal from A0 of Metal touch sensor or Microphone sensor

//these are threshold values to control LEDs.
// You need to change the values to suit your music and the potentiometer.
// first, play the music, and watch the serial monitor. Notice the range of the Analog output numbers.
// then, back to the code below, input 6 numbers from largest to smallest. Make sure they cover the range of your music.
// after that, re-check and compile your code.

//****************  use the number range you see from serial monitor *********//
//****************  then put the 6 numbers in descending order (from largest to smallest)   *********//
int SoundLevel[] = {132, 131, 130, 129, 128, 127};


void setup()
{
  Serial.begin(9600);

  // LED pins are OUTPUT mode
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  
  pinMode(D0pin, INPUT); // the D0pin is for receiving (INPUT) signal from sensor
  pinMode(A0pin, INPUT); // the A0pin is for receiving (INPUT) signal from sensor

  // initialize LEDs to be turned off
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);

  delay(300);
}

void loop()
{
  // read digital value from sensor (either 0(LOW) or 1(HIGH))
  DigitalValue = digitalRead(D0pin); // DigitalValue receives value from D0 leg of sensor
  Serial.print("Read Digital value=");
  Serial.println(DigitalValue);      // print digital value (either 0 or 1) on serial monitor

  // read analog value from sensor (value could be within range 0~1023)
  AnalogValue = analogRead(A0pin); // AnalogValue receives value from A0 leg of sensor
  Serial.print("Read Analog value=");
  Serial.println(AnalogValue);       // print analog value on serial monitor

  // use the digital value to control ON or OFF of the LED light
  // if it's microphone sensor, LED turns on when sound level is high, turns off when it cannot detect sound
  if (AnalogValue < SoundLevel[0]) {
    digitalWrite(Led1, HIGH);
  } else {
    digitalWrite(Led1, LOW);
  }
  if (AnalogValue < SoundLevel[1]) {
    digitalWrite(Led2, HIGH);
  } else {
    digitalWrite(Led2, LOW);
  }
  if (AnalogValue < SoundLevel[2]) {
    digitalWrite(Led3, HIGH);
  } else {
    digitalWrite(Led3, LOW);
  }
  if (AnalogValue < SoundLevel[3]) {
    digitalWrite(Led4, HIGH);
  } else {
    digitalWrite(Led4, LOW);
  }
  if (AnalogValue < SoundLevel[4]) {
    digitalWrite(Led5, HIGH);
  } else {
    digitalWrite(Led5, LOW);
  }
  if (AnalogValue < SoundLevel[5]) {
    digitalWrite(Led6, HIGH);
  } else {
    digitalWrite(Led6, LOW);
  }

  delay(300);
}
