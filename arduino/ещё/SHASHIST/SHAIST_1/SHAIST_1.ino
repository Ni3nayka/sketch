#include <AFMotor.h>
int i = 2;
AF_DCMotor m1(1);
AF_DCMotor m2(2);
void setup() {
  m1.setSpeed(255);
  m2.setSpeed(255);
  m1.run(RELEASE);
  m2.run(RELEASE);
  D();
}

//m1.run(RELEASE);
//m1.run(FORWARD);
//m1.run(BACKWARD);

void loop() {
  
}

void D () {
  if (i > 0) {
    m1.run(FORWARD);
    m2.run(FORWARD);
  }
  else {
    m1.run(BACKWARD);
    m2.run(BACKWARD);
    i = (i*(-1));
  }
  while (i > 0) {
    while ((analogRead(A3)) < 500) {}
    while ((analogRead(A3)) > 500) {}
    i--;  
  }
  m1.run(RELEASE);
  m2.run(RELEASE);

}

