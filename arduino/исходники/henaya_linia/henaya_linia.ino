#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


IRrecv irrecv(A0); // указываем пин, к которому подключен IR приемник 

decode_results results; 

void setup() // процедура setup 
{ 

irrecv.enableIRIn(); // запускаем прием инфракрасного сигнала 

pinMode(13, OUTPUT); // пин 13 будет выходом (англ. «output») 
pinMode(12, OUTPUT); // пин 13 будет выходом (англ. «output») 
pinMode(A0, INPUT); // пин A0 будет входом (англ. «intput») 

Serial.begin(9600); // подключаем монитор порта 
} 

void loop() // процедура loop 
{ 
if (irrecv.decode(&results)) // если данные пришли выполняем команды 
{ 

Serial.println(results.value); // отправляем полученные данные на порт 

// включаем и выключаем светодиоды, в зависимости от полученного сигнала 

if (results.value == 16754775) { 
digitalWrite(13, HIGH); 
} 
if (results.value == 16769055) { 
digitalWrite(13, LOW); 
} 
if (results.value == 16718055) { 
digitalWrite(12, HIGH); 
} 
if (results.value == 16724175) { 
digitalWrite(12, LOW); 
} 
irrecv.resume(); // принимаем следующий сигнал на ИК приемнике 
} 
}

