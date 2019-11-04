//www.elegoo.com
//2016.12.9

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
int Led1 = 2; //pin# for 1st Led
int Led2 = 3; //pin# for 2nd Led
int Led3 = 4; //pin# for 3rd Led

int LedIsOn[] = {0, 0, 0, 0}; //status for Leds. LedIsOn[1] for 1st Led, [2] for 2nd Led, [3] for 3rd Led. [0] is set to always 0 (not used)

#define Code1 0xFFA25D
#define Code2 0xFF629D
#define Code3 0xFFE21D

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void controlLED()
{
  switch (results.value)
  {
    case Code1:    // if pushed "1" on remote control
      Serial.println("You pressed 1. First LED will turn on or off");
      if (LedIsOn[1] == 1)
      {
        digitalWrite(Led1, LOW);
        LedIsOn[1] = 0;
      }
      else
      {
        digitalWrite(Led1, HIGH);
        LedIsOn[1] = 1;
      }
      break;

    case Code2:    // if pushed "2" on remote control
      Serial.println("You pressed 2. Second LED will turn on or off");
      if (LedIsOn[2] == 1)
      {
        digitalWrite(Led2, LOW);
        LedIsOn[2] = 0;
      }
      else
      {
        digitalWrite(Led2, HIGH);
        LedIsOn[2] = 1;
      }
      break;

    case Code3:  // if pushed "3" on remote control
      Serial.println("You pressed 3. Third LED will turn on or off");
      if (LedIsOn[3] == 1)
      {
        digitalWrite(Led3, LOW);
        LedIsOn[3] = 0;
      }
      else
      {
        digitalWrite(Led3, HIGH);
        LedIsOn[3] = 1;
      }
      break;
    case 0xFF22DD: Serial.println("You pressed 4. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFF02FD: Serial.println("You pressed 5. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFFC23D: Serial.println("You pressed 6. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFFE01F: Serial.println("You pressed 7. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFFA857: Serial.println("You pressed 8. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFF906F: Serial.println("You pressed 9. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFF9867: Serial.println("You pressed 0. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFFB04F: Serial.println("You pressed #. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFF6897: Serial.println("You pressed *. Please press 1 or 2 or 3 to control LED");    break;
    case 0xFF18E7: Serial.println("You pressed UP. Please press 1 or 2 or 3 to control LED");   break;
    case 0xFF10EF: Serial.println("You pressed LEFT. Please press 1 or 2 or 3 to control LED"); break;
    case 0xFF38C7: Serial.println("You pressed OK. Please press 1 or 2 or 3 to control LED");   break;
    case 0xFF5AA5: Serial.println("You pressed RIGHT. Please press 1 or 2 or 3 to control LED"); break;
    case 0xFF4AB5: Serial.println("You pressed DOWN. Please press 1 or 2 or 3 to control LED"); break;
    default:
      Serial.println("Not recognized input. Please press 1 or 2 or 3 to control Leds");
      break;
  }
  delay(500); // do not get immediate repeat
}


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600); //initialize serial monitor

  // set LED's pin mode to OUTPUT
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);

  // initialize LEDs to be off at the begining
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);

  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    //translateIR();
    Serial.print("Received code:");
    Serial.println(results.value, HEX);
    controlLED();
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */
