#include <AFMotor.h>

AF_DCMotor motor_L(1);
AF_DCMotor motor_R(2);

#define DAT_L A1
#define DAT_R A2

#define basic_speed 60
#define turn_speed 70
#define Ke 0.4

unsigned long int time = 0;

void setup() { 
  Serial.begin(9600);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}
void loop () { 
  int e = analogRead(DAT_L) - analogRead(DAT_R);
  e *= Ke;
  motor_L.setSpeed(constrain(basic_speed + e,0,255));
  motor_R.setSpeed(constrain(basic_speed - e,0,255));
  Serial.println(analogRead(DAT_L));

  if (time+3000<millis()) {
    motor_L.run(BACKWARD);
    motor_L.setSpeed(turn_speed);
    motor_R.setSpeed(turn_speed);
    while (analogRead(DAT_L)<850); delay(50);
    while (analogRead(DAT_L)>850); delay(50);
    while (analogRead(DAT_L)<850); delay(50);
    time = millis();
    motor_L.run(FORWARD);
  }
}
