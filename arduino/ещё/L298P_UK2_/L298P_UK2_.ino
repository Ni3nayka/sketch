#include <IRremote.h>

#define SP    10 
#define DP    12
#define SL    11
#define DL    13

int i = 0;

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
    case 0xFF9867:
        i = 0;
        break;
    case 0xFFA25D:
        i = 1;
        break;
    case 0xFF629D:
        i = 2;
        break;
    case 0xFFE21D:
        i = 3;
        break;
    }
    
         
    irrecv.resume(); // принимаем следующую команду 
 }

//-------------------------------------------------------------------------------
if (i == 1) {
  while (i == 1) {
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
    case 0xFF9867:
        i = 0;
        break;
    }
    
         
    irrecv.resume(); // принимаем следующую команду 
 }
}
}

if (i == 2) {
  while (i == 2) {
    if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
    case 0xFF9867:
        i = 0;
        break;
    }
    irrecv.resume(); // принимаем следующую команду
  }
if (analogRead(A1) < 300){
        digitalWrite(DL, HIGH );
        analogWrite(SL, 200);
        digitalWrite(DP, HIGH );
        analogWrite(SP, 200);
}
else {
        digitalWrite(DL, LOW );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 255);
        delay (350);
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 255);
        delay (150);
}

}
}
  

if (i == 3) {
  while (i == 3) {
    if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
    case 0xFF9867:
        i = 0;
        break;
    }
    irrecv.resume(); // принимаем следующую команду
  }
if (analogRead(A1) > 300){
    while (analogRead(A1) > 300) {
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 50);
    }
  }
  else {
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
  }

  if (analogRead(A2) > 300){
    while (analogRead(A2) > 300) {
        digitalWrite(DL, LOW );
        analogWrite(SL, 50);
        digitalWrite(DP, HIGH );
        analogWrite(SP, 255);
    }
  }
  else {
        digitalWrite(DP, HIGH );
        analogWrite(SP, 255);
  }
}
}

        digitalWrite(DL, LOW );
        analogWrite(SL, 0);
        digitalWrite(DP, LOW );
        analogWrite(SP, 0);

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
