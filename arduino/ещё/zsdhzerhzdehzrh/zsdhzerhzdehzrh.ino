#include <AFMotor.h>

AF_DCMotor M1(1, MOTOR12_64KHZ);
AF_DCMotor M2(2, MOTOR12_64KHZ);

void setup() {
  
}

void loop() {
  if (analogRead(A1) > 300){
    while (analogRead(A1) > 300) {
      M1.run(FORWARD);
      M1.setSpeed(255);
      M2.run(BACKWARD);
      M2.setSpeed(255);
    }
  }
  else {
    M1.run(FORWARD);
    M1.setSpeed(255);
  }

  if (analogRead(A2) > 300){
    while (analogRead(A2) > 300) {
      M1.run(BACKWARD);
      M1.setSpeed(255);
      M2.run(FORWARD);
      M2.setSpeed(255);
    }
  }
  else {
    M2.run(FORWARD);
    M2.setSpeed(255);
  }
  

}
