#include <IRremote.h>
#define irPin 7
 
IRrecv irrecv(irPin);
decode_results results;
 
void setup() {
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn();
}
 
void loop() {
  
   if (irrecv.decode(&results)) {
      Serial.println(results.value);
      
      switch (results.value) {
        
         case 0xFF18E7:            // FORDWARD
            forward();
            break;
 
         case 0xFF10EF:            // LEFT
            left();
            break;
               
         case 0xFF38C7:            // STOP
            Stop();
            break;
 
         case 0xFF5AA5:            // RIGHT
            right();
            break;
 
         case 0xFF4AB5:            // BACK
            back();
            break;
 
         
         }      
   irrecv.resume();
   }
}
 
void forward()
{
            digitalWrite(5, 0);
            digitalWrite(9, 127);
            digitalWrite(10, 0);
            digitalWrite(11, 128);
}
 
void back()
{
            digitalWrite(5, 127);
            digitalWrite(9, 0);
            digitalWrite(10, 127);
            digitalWrite(11, 0);
}
 
void left()
{
            digitalWrite(5, 0);
            digitalWrite(9, 127);
            digitalWrite(10, 127);
            digitalWrite(11, 0);
}
 
void right()
{
              digitalWrite(5, 127);
              digitalWrite(9, 0);
              digitalWrite(10, 0);
              digitalWrite(11, 127);
} 
 
void Stop()
{
            digitalWrite(5, 0);
            digitalWrite(9, 0);
            digitalWrite(10, 0);
            digitalWrite(11, 0);
}