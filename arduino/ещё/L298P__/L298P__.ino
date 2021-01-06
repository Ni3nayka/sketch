#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define SP      10 
#define DP      12
#define SL      11
#define DL      13
 
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
    case 0xFF5AA5:
        digitalWrite(DL, HIGH );
        analogWrite(SL, 255);
        digitalWrite(DP, LOW );
        analogWrite(SP, 255);
    } 
    irrecv.resume(); // принимаем следующую команду 
}
  //irrecv.resume(); // принимаем следующую команду
  
}
