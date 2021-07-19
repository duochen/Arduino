//www.elegoo.com
//2016.12.9

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes
{
  // we print the received code in three formats
  Serial.println("Received signal. Code is in Decimal, Binary, and Hexadecimal:");
  Serial.print(results.value, DEC); // in decimal format
  Serial.print(", ");
  Serial.print(results.value, BIN); // in binary format 
  Serial.print(", ");
  Serial.print(results.value, HEX); // in hexadecimal format

  switch (results.value) // use switch-case structure to interpret the received code for each button pressed
  {
    case 0xFFA25D: Serial.println("==>You pushed Button 1");    break;
    case 0xFFE21D: Serial.println("==>You pushed Button 3");    break;
    case 0xFF629D: Serial.println("==>You pushed Button 2");    break;
    case 0xFF22DD: Serial.println("==>You pushed Button 4");    break;
    case 0xFF02FD: Serial.println("==>You pushed Button 5");    break;
    case 0xFFC23D: Serial.println("==>You pushed Button 6");    break;
    case 0xFFE01F: Serial.println("==>You pushed Button 7");    break;
    case 0xFFA857: Serial.println("==>You pushed Button 8");    break;
    case 0xFF906F: Serial.println("==>You pushed Button 9");    break;
    case 0xFF9867: Serial.println("==>You pushed Button 0");    break;
    case 0xFFB04F: Serial.println("==>You pushed Button #");    break;
    case 0xFF6897: Serial.println("==>You pushed Button *");    break;
    case 0xFF18E7: Serial.println("==>You pushed Button UP");   break;
    case 0xFF10EF: Serial.println("==>You pushed Button LEFT"); break;
    case 0xFF38C7: Serial.println("==>You pushed Button OK");   break;
    case 0xFF5AA5: Serial.println("==>You pushed Button RIGHT");   break;
    case 0xFF4AB5: Serial.println("==>You pushed Button DOWN");    break;
    case 0xFFFFFFFF: Serial.println("==>You pushed Button too fast!"); break;

    default:
      Serial.println("==>You pushed some Oher Buttons!");

  }// End Case

  delay(500); // Do not get immediate repeat

} //END translateIR


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR();
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */
