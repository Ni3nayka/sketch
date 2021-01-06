#include <AFMotor.h>

AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

int a  = 0;
int b  = 0;
int c  = 0;
int d  = 0;
int i  = 0;
int i1 = 0;
int k1 = 0;
int k2 = 0; 
int k3 = 0; 
int x9 = 1;
int y9 = 1;

int x1 = 0;
int y1 = 0;
int f1 = 0;
int y2 = 0;
int f2 = 0;
int f3 = 0;

int x = 0;
int y = 0;

void setup() {
  Serial.begin(115200);
  M1.setSpeed(200);
  M2.setSpeed(200);
  M3.setSpeed(255);
  M4.setSpeed(255);
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
  Serial.println("robot complete!");
  //dvigenie(); 
}

  // RELEASE
  // FORWARD
  // BACKWARD

void loop() {
  //Serial.println(analogRead(A0));
  PK();
}

void PK() {
  if (Serial.available() > 0) {
    i = Serial.read();
    if ((i == 'h') || (i == 'H')) {
      Serial.println("---");
      Serial.print("X = ");
      Serial.println(x);
      Serial.print("Y = ");
      Serial.println(y);
      Serial.println("---");
      Serial.println("3");
      delay(500);
      Serial.println("2");
      delay(500);
      Serial.println("1");
      delay(500);
      Serial.println("START");
      Serial.println("---");
      dvigenie();
      x9 = 1;
      y9 = 1;
      x = 0;
      y = 0;
      i1 = 0;
      Serial.println("FINISH");
      Serial.println("---");
    }
    if ((i == 'y') || (i == 'Y')) {
      i1 = 1;
      //Serial.print("Y:");
    }
    if ((i == 'x') || (i == 'X')) {
      i1 = 2;
      //Serial.print("X:");
    }
    if (i1 == 2) {
      if (i == '-') { x9 = -1; }
      if (i == '1') { x = 1*x9; }
      if (i == '2') { x = 2*x9; }
      if (i == '3') { x = 3*x9; }
      if (i == '4') { x = 4*x9; }
      if (i == '5') { x = 5*x9; }
      if (i == '6') { x = 6*x9; }
      if (i == '7') { x = 7*x9; }
      if (i == '8') { x = 8*x9; }
      if (i == '9') { x = 9*x9; }
      if (i == '0') { x = 0; }
      //Serial.println(x);
    }
    if (i1 == 1) {
      if (i == '-') { y9 = -1; }
      if (i == '1') { y = 1*y9; }
      if (i == '2') { y = 2*y9; }
      if (i == '3') { y = 3*y9; }
      if (i == '4') { y = 4*y9; }
      if (i == '5') { y = 5*y9; }
      if (i == '6') { y = 6*y9; }
      if (i == '7') { y = 7*y9; }
      if (i == '8') { y = 8*y9; }
      if (i == '9') { y = 9*y9; }
      if (i == '0') { y = 0; }
      //Serial.println(y);
    }
    //Serial.println("---");
    i = 0;
  }
}

void dvigenie() {
  if (x > 0) { x1 = x; } else { x1 = x*(-1); }
  if (y > 0) { y1 = y; } else { y1 = y*(-1); }
  y2 = y1;
  f1 = 1;
  f2 = 1;
  f3 = 1;
  k1 = 0;
  k2 = 0;
  k3 = 0;
  if (y == 0) {} else {
    if (y > 0) {
      M1.run(FORWARD);
      M2.run(FORWARD);
    }
    else {
      M1.run(BACKWARD);
      M2.run(BACKWARD);
    }
    // 1 черная
    // 0 белая
    while ((y1 > -80) || (y2 > -80)) {
      if (((analogRead(A1)) > 600) && (f1 == 1) && (y1 > 0)) { f1 = 0;       }
      if (((analogRead(A1)) < 600) && (f1 == 0) && (y1 > 0)) { f1 = 1; y1--; }
      if (y1 == 0) {
        if (y > 0) { M1.run(BACKWARD); }
        else { M1.run(FORWARD); }
        y1--;  
      }
      if ((y1 < 0) && (y1 > -30)) { delay(1); y1--; }
      if (y1 == -30) { M1.run(RELEASE); y1 = -100; }
      //if ((y1 < 0) && ((analogRead(A1)) < 350)) { M1.run(RELEASE); y1 = -100; }
      
      if (((analogRead(A2)) > 600) && (f2 == 1) && (y2 > 0)) { f2 = 0;       }
      if (((analogRead(A2)) < 600) && (f2 == 0) && (y2 > 0)) { f2 = 1; y2--; }
      if (y2 == 0) {
        if (y > 0) { M2.run(BACKWARD); }
        else { M2.run(FORWARD); }
        y2--;  
      }
      if ((y2 < 0) && (y2 > -55)) { delay(1); y2--; }
      if (y2 == -55) { M2.run(RELEASE); y2 = -100; }
      //if ((y2 < 0) && ((analogRead(A2)) < 350)) { M2.run(RELEASE); y2 = -100; }
    }
    //Serial.println("---");
    M1.run(RELEASE);
    M2.run(RELEASE);
    delay(500);
  }
  //------------------------------------------------------
  if (x == 0) {} else {
    if (x > 0) {
      M3.run(FORWARD);
    }
    else {
      M3.run(BACKWARD);
    }
    // 1 черная
    // 0 белая
    while (x1 > -50) {
      if (((analogRead(A0)) > 600) && (f3 == 1) && (x1 > 0)) { f3 = 0;       }
      if (((analogRead(A0)) < 600) && (f3 == 0) && (x1 > 0)) { f3 = 1; x1--; }
      if (x1 == 0) {
        if (x > 0) { M3.run(BACKWARD); }
        else { M3.run(FORWARD); }
        x1--;  
      }
      if ((x1 < 0) && (x1 > -3)) { delay(1); x1--; }
      if (x1 == -3) { M3.run(RELEASE); x1 = -100; }
    }
    //Serial.println("---");
    M3.run(RELEASE);
  }
}















void dvigenie_2() {
  if (x > 0) { x1 = x; } else { x1 = x*(-1); }
  if (y > 0) { y1 = y; } else { y1 = y*(-1); }
  y2 = y1;
  f1 = 1;
  f2 = 1;
  f3 = 1;
  k1 = 0;
  k2 = 0;
  k3 = 0;
  
  if (y == 0) {} else {  // ось Y
    if (y > 0) {
      M1.run(FORWARD);
      M2.run(FORWARD);
    }
    else {
      M1.run(BACKWARD);
      M2.run(BACKWARD);
    }
    // флаги:
    // 0 - белое
    // 1 - черное
    while ((k1 < 100) || (k2 < 100)) {
      if (k1 == 0) {
        if ((analogRead(A1))  > 400) { f1 = 0; }
        if (((analogRead(A1)) < 400) && (f1 == 0)) { f1 = 1; y1--; }
        if (y1 == 0) { k1 = 1; }  
      }
      else { 
        if ((k1 == 1) && ((analogRead(A1)) > 400)) { k1 = 2; }
        if (k1 == 2) {
          if (y > 0) { M1.run(BACKWARD); } else { M1.run(FORWARD); }
          k1 = 3;
        }
        if ((k1 == 3) && ((analogRead(A1)) < 400)) { k1 = 4; }
        if ((k1 > 3) && (k1 < 10)) { k1++; }
        if (k1 == 10) {  M1.run(RELEASE); k1 = 200; }
      }
      
      if (k2 == 0) {
        if ((analogRead(A2))  > 400) { f2 = 0; }
        if (((analogRead(A2)) < 400) && (f2 == 0)) { f2 = 1; y2--; }
        if (y2 == 0) { k2 = 1; }  
      }
      else { 
        if ((k2 == 1) && ((analogRead(A2)) > 400)) { k2 = 2; }
        if (k2 == 2) {
          if (y > 0) { M2.run(BACKWARD); } else { M2.run(FORWARD); }
          k2 = 3;
        }
        if ((k2 == 3) && ((analogRead(A2)) < 500)) { k2 = 4; }
        if ((k2 > 3) && (k2 < 5)) { k2++; }
        if (k2 == 5) {  M2.run(RELEASE); k2 = 200; }
      }
    }
  }  
  M1.run(RELEASE);
  M2.run(RELEASE);
  
  if (x == 0) {} else {  // ось X
    if (x > 0) {
      M3.run(FORWARD);  
    }
    else {
      M3.run(BACKWARD); 
    }
    // флаги:
    // 0 - белое
    // 1 - черное
    while (k3 < 100) {
      if (k3 == 0) {
        if ((analogRead(A0))  > 450) { f3 = 0; }
        if (((analogRead(A0)) < 450) && (f3 == 0)) { f3 = 1; x1--; }
        if (x1 == 0) { 
          k3 = 1;
          if (x > 0) { M3.run(BACKWARD); }
          else { M3.run(FORWARD); } 
        }  
      }
      else {
        if (k3 < 20) { k3++; delay(1); }
        if ((k3 == 20) && ((analogRead(A0)) < 450)) {
          M3.run(RELEASE); k3 = 200;    
        }
      }
    }
  }
  M3.run(RELEASE);
}
