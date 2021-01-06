#include <Servo.h>
#include <AFMotor.h>

Servo S;

AF_DCMotor M1(1);
AF_DCMotor M2(2);

float k = 0.75;

int trigPin1 = A3; // L
int echoPin1 = A2;
int trigPin2 = A1; // R
int echoPin2 = A0; 
int ras1 = 0;
int ras2 = 0;
int duration = 0;

void setup() {
  S.attach(9);
  Serial.begin(115200);
  M1.setSpeed(150);
  M2.setSpeed(150);
  M1.run(RELEASE);
  M2.run(RELEASE);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  S.write(123);
  while ((digitalRead(10)) == 1) { delay(10); }
  //M1.run(FORWARD);
  //M2.run(FORWARD);
}

  // RELEASE
  // FORWARD
  // BACKWARD
  
void loop() {
  //Serial.println(analogRead(A4));
  dv();
}

void dv() {
  if ((analogRead(A4)) > 200) {
    M1.run(FORWARD);
    M2.run(FORWARD);
    rast();
    if (ras1 > 80) { ras1 = 80; }
    if (ras2 > 80) { ras2 = 80; }
    S.write(123 - (ras1 - ras2)*k ); 
  }
  else {
    M1.run(BACKWARD);
    M2.run(BACKWARD);
    delay(800);
  }
}

void rast(){
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW); 
  duration = pulseIn(echoPin1, HIGH); 
  ras1 = duration / 58;
  //------------------------------------------
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW); 
  duration = pulseIn(echoPin2, HIGH); 
  ras2 = duration / 58;
} 
