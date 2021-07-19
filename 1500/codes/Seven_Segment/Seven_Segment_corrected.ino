//www.elegoo.com
//2016.12.12

// define the LED digit patterns, from 0 - 9
// 1 = LED on, 0 = LED off, in this order:
//                74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7
//                Mapping to      a,b,c,d,e,f,g of Seven-Segment LED
// this is for the common anode type 7-segment display (the common pins are for Vcc's, common-anode 7-segment display)
byte seven_seg_digits[10] = { B00000011,  // = 0
                              B10011111,  // = 1
                              B00100101,  // = 2
                              B00001101,  // = 3
                              B10011001,  // = 4
                              B01001001,  // = 5
                              B01000001,  // = 6
                              B00011111,  // = 7
                              B00000001,  // = 8
                              B00011001   // = 9
                            };

// connect to the ST_CP of 74HC595 (pin 3,latch pin)
int latchPin = 3;
// connect to the SH_CP of 74HC595 (pin 4, clock pin)
int clockPin = 4;
// connect to the DS of 74HC595 (pin 2)
int dataPin = 2;

int buzzerpin = 7;

void setup() {
  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
}

// display a number on the digital segment display
void sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);

  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);

  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // count from 9 to 0
  for (byte digit = 10; digit > 0; --digit) {
    delay(500);
    sevenSegWrite(digit - 1);
    // if there is buzzle, let it go on
    digitalWrite(buzzerpin, HIGH);
    delay(100);
    digitalWrite(buzzerpin, LOW);
  }

  // suspend 1 second
  delay(1000);
}
