
#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration[] = {1000,500,1000,500,1000,500,1000,500};
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {  
  for (int thisNote = 7; thisNote >=0; thisNote--) {
    Serial.print("index = ");
    Serial.println(thisNote);
    Serial.print("The value of the Note: ");
    Serial.println(melody[thisNote]);
    
    // pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration[thisNote]);
     
    // Output the voice after several minutes
    delay(1000);
  }
   
  // restart after two seconds 
  delay(2000);
}
