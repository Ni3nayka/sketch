#include <AFMotor.h>

AF_DCMotor M1(1, MOTOR12_64KHZ); 
AF_DCMotor M2(2, MOTOR12_64KHZ); // создаем объект motor №2, ШИМ 64 кГц 


void setup() 
{ 

M1.setSpeed(200); 
M2.setSpeed(200); // устанавливаем скорость вращения 200/255 

Serial.begin(9600); 
} 

void loop() 
{ 

if (((analogRead(A1)) < 300) && ((analogRead(A2)) < 300)) 
{ 
M1.run(FORWARD); 
M2.run(FORWARD); 
} 

if ((analogRead(A1)) > 300) { 
while((analogRead(A1)) > 300){ 
M1.run(FORWARD); 
M2.run(RELEASE); 
} 
} 
if ((analogRead(A2)) > 300) 
{ 
while((analogRead(A2)) > 300){ 
M1.run(RELEASE); 
M2.run(FORWARD); 
} 
} 

Serial.println(analogRead(A2)); 
Serial.println(analogRead(A2)); 
Serial.print ("\n"); 

}
