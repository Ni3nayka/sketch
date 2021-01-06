#include <AFMotor.h> // добавляем библиотеку

AF_DCMotor M1(1);  // подключаем моторы
AF_DCMotor M2(2); 


void setup() 
{ 

M1.setSpeed(255); // устанавливаем максимальную скорость вращения 200/255 
M2.setSpeed(255); 

Serial.begin(9600);  // настраиваем вывод
} 

void loop() 
{ 

if (((analogRead(A1)) > 300) && ((analogRead(A2)) < 300) && ((analogRead(A3)) > 300)) 
{ 
M1.run(FORWARD);  // вперед
M1.setSpeed(255);
M2.run(FORWARD);
M2.setSpeed(255);
} 

if ((analogRead(A1)) < 300) { 
while((analogRead(A2)) > 300){
M1.run(BACKWARD);  // вправо
M1.setSpeed(50);
M2.run(FORWARD);
M2.setSpeed(255);
} 
} 
if ((analogRead(A3)) < 300) { 
while((analogRead(A2)) > 300){ 
M1.run(FORWARD);  // влево
M1.setSpeed(255);
M2.run(BACKWARD);
M2.setSpeed(50); 
} 
} 

}
