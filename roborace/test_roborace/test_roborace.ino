// https://robotraffik.ru/

#include <iarduino_I2C_Motor.h> 
iarduino_I2C_Motor mot_L(0x0A);
iarduino_I2C_Motor mot_R(0x0B);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C); 

#include <iarduino_Position_BMX055.h>
iarduino_Position_BMX055 sensor(BMX);

void setup() {
  delay(500);
  
  Serial.begin(9600);             //  Настраиваем COM-порт на работу со скоростью 9600 бит/сек
  Serial.println("Setup:");
  Serial.print("supply voltage: "); Serial.println(voltmetr());
  Serial.print("mot_L: "); serial_test(mot_L.begin());
  Serial.print("mot_R: "); serial_test(mot_R.begin());
  Serial.print("bumper: "); serial_test(bum.begin());
  sensor.begin();
  Serial.println("Setup - end");

  mot_L.setDirection(false);  //   Задаём направление вращения для левого  мотора: против часовой стрелки при положительных скоростях и по при отрицательных.                  
  mot_R.setDirection(true ); 
  
  /*mot_L.setSpeed( 50, MOT_PWM);
  mot_R.setSpeed( 50, MOT_PWM);
  delay(2000);
  mot_L.setStop();
  mot_R.setStop();  */

}
void loop() {
  //Serial.println(voltmetr()); //  Выводим в порт считанные с аналогового пина данные
  //Serial.println(bum.getLineAnalog(5));

  sensor.read();
  Serial.print("КУРС=");   Serial.print(sensor.axisZ); Serial.print(", ");
  Serial.print("ТАНГАЖ="); Serial.print(sensor.axisX); Serial.print(", ");
  Serial.print("КРЕН=");   Serial.print(sensor.axisY); Serial.print("\r\n");
}

void serial_test(bool test) {
  if (test) Serial.println("OK"); else Serial.println("ERROR");
}
float voltmetr() { return analogRead(A0)/64.4; }
