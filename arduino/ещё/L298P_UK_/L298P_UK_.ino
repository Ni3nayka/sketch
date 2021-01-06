#include <IRremote.h>

#define SP    10 
#define DP    12
#define SL    11
#define DL    13

IRrecv irrecv(A0); // указываем вывод, к которому подключен приемник
decode_results results;

void setup() 
{
  irrecv.enableIRIn(); // запускаем прием
} 
 
void loop() 
{ 

if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
    case 0xFF18E7:
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
        digitalWrite(DP, HIGH );
        analogWrite(SP, 255);
        break;
    case 0xFF4AB5:
        digitalWrite(DL, LOW );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 255);
        break;
    case 0xFF10EF:
        digitalWrite(DL, LOW );
        analogWrite(SL, 255);
        digitalWrite(DP, HIGH );
        analogWrite(SP, 255);
        delay (150);
        digitalWrite(DL, LOW );
        analogWrite(SL, 0);
        digitalWrite(DP, LOW );
        analogWrite(SP, 0);
        break;
    case 0xFF5AA5:
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 255);
        delay (150);
        digitalWrite(DL, LOW );
        analogWrite(SL, 0);
        digitalWrite(DP, LOW );
        analogWrite(SP, 0);
        break;
    case 0xFF38C7:
        digitalWrite(DL, LOW );
        analogWrite(SL, 0);
        digitalWrite(DP, LOW );
        analogWrite(SP, 0);
        break;
    }
    
         
    irrecv.resume(); // принимаем следующую команду 
 }

/* else {
   if ( irrecv.decode( &results )) { // если данные пришли
     return 19; 
   }
   else {
     if ( irrecv.decode( &results )) { // если данные пришли
     return 19; 
   }
   else {
    if ( irrecv.decode( &results )) { // если данные пришли
     return 19; 
   }
   else {
        digitalWrite(DL, HIGH );
        analogWrite(SL, 0);
        digitalWrite(DP, LOW );
        analogWrite(SP, 0);
   } 
   }
   }
 }*/
}
