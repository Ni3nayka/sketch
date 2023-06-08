#include <AFMotor.h>
AF_DCMotor motor_rulilo(1);
#define KP_RUL 2
#define MAX_ANGLE 50
int save_angle = 0;
//void motor_rul(int angle=save_angle);

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(A4, A5); // RX, TX
#define TEST bluetooth
int M = 100;

#define PWM_FORWARD 10
#define PWM_BACKWARD 9
#define MAX_SPEED 100

void motor_rul(int angle=save_angle) {
  int real_angle = map(analogRead(A0),420,670,-MAX_ANGLE,MAX_ANGLE);
  angle = constrain(angle,-MAX_ANGLE,MAX_ANGLE);
  save_angle = angle;
  int delta = angle-real_angle;
  motor_rulilo.run(delta==0?RELEASE:(delta>0?FORWARD:BACKWARD));
  motor_rulilo.setSpeed(constrain(abs(delta)*KP_RUL,0,250));
}

void setup() {      
  delay(500); 
  Serial.begin(9600);
  bluetooth.begin(9600);
  motor_rulilo.run(RELEASE);
  pinMode(PWM_FORWARD,OUTPUT);
  pinMode(PWM_BACKWARD,OUTPUT);
}

// 670 - 420

void loop() {
  //motor_rul(0);
  bluetooth_main();
  motor_rul();
}

void bluetooth_main() {
  if (TEST.available()) {
    char t = TEST.read();
    if      (t=='F') motor(M,0);
    else if (t=='S') motor(0,0);
    else if (t=='B') motor(-M,0);
    else if (t=='L') motor(0,1);
    else if (t=='R') motor(0,-1);
    else if (t=='G') motor(M,1);
    else if (t=='I') motor(M,-1);
    else if (t=='H') motor(-M,1);
    else if (t=='J') motor(-M,-1);
    else if (t=='0') M = 0;
    else if (t=='1') M = 10;
    else if (t=='2') M = 20;
    else if (t=='3') M = 30;
    else if (t=='4') M = 40;
    else if (t=='5') M = 50;
    else if (t=='6') M = 60;
    else if (t=='7') M = 70;
    else if (t=='8') M = 80;
    else if (t=='9') M = 90;
    else if (t=='q') M = 100;
  }
}

void motor(int speed, int angle) {
  motor_rul(angle*(-35));
  speed = map(constrain(speed,-100,100),-100,100,-MAX_SPEED,MAX_SPEED);
  analogWrite(PWM_FORWARD,speed>0?speed:0);
  analogWrite(PWM_BACKWARD,speed<0?-speed:0);
}
