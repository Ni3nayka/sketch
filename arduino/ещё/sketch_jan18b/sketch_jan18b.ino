#include <AFMotor.h> 

#include <iarduino_HC_SR04.h> // подключаем библиотеку для работы с датчиком 

iarduino_HC_SR04 hcsr(A2,A3); // объявляем переменную для работы с датчиком, указывая номера arduino подключенные к выводам TRIG и ECHO датчика 

AF_DCMotor Left(1, MOTOR12_64KHZ); 
AF_DCMotor Right(2, MOTOR12_64KHZ); 

#define led_1 9 //левый датчик 
#define led_2 10 //правый датчик 

#define sped0 200 
#define sped1 150 
#define sped2 100 
#define sped3 50 
#define sped4 30 
#define sped5 10 

#define pausa 5 
#define stop_pausa 1000 

boolean sens_L = 0; 
boolean sens_R = 0; 

boolean flag_L = 0; 
boolean flag_R = 0; 

const uint8_t valDistance = 10; 


void setup(){ 

Left.run(RELEASE); 
Right.run(RELEASE); 
pinMode(led_1, INPUT); 
pinMode(led_2, INPUT); 
Right.run(FORWARD); 
Left.run(FORWARD); 
Left.setSpeed(255); 
Right.setSpeed(255); 
Serial.begin(9600); // инициализация передачи данных по COM-порту 
} 
void loop(){ 
sens_L = digitalRead(led_1); 
sens_R = digitalRead(led_2); 

Serial.println(hcsr.distance()); // вывод расстояния 
if(hcsr.distance()<10) 
{ 
Left.run(RELEASE); 
Right.run(RELEASE); 
Left.setSpeed(0); 
Right.setSpeed(0); 
//delay(pausa); 
} 


if(sens_L==0 & sens_R==0){ //если все норм едем вдоль линии 
Left.setSpeed(sped0); 
Right.setSpeed(sped0); 
Left.run(FORWARD); 
Right.run(FORWARD); 

} 
if(sens_L==0 & sens_R==1){ //справа наехали на линию 
Left.setSpeed(sped0); 
Right.setSpeed(sped5); 
Left.run(FORWARD); 
Right.run(BACKWARD); 

flag_L = 1; 
flag_R = 0; 

} 
if(sens_L==1 & sens_R==0){ //слева наехали на линию 
Left.setSpeed(sped5); 
Right.setSpeed(sped0); 
Left.run(BACKWARD); 
Right.run(FORWARD); 

flag_L = 0; 
flag_R = 1; 
} 
if(sens_L==1 & sens_R==1){ //мы на чем то но не на белой бумаге. встаем 
//Left.setSpeed(0); 
//Right.setSpeed(0); 
//delay(pausa); 

if(flag_L == 0 & flag_R == 1){ //выруливаем слева 
Left.setSpeed(sped3); 
Right.setSpeed(sped0); 
Left.run(BACKWARD); 
Right.run(FORWARD); 

//delay(pausa); 
} 
if(flag_L == 1 & flag_R == 0){ //выруливаем справа 
Left.setSpeed(sped0); 
Right.setSpeed(sped3); 
Left.run(FORWARD); 
Right.run(BACKWARD); 
} 
} 
}
