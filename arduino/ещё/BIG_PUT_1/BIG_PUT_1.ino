#include <Wire.h>
#include <HMC5883L.h>
#include <Servo.h>

//компас

// моторы
#define SP     11
#define MP     13
#define SL     10
#define ML     12

//серво
Servo S;

// рабочие переменные
int Y = 0;
int A = 0;
int L = 0;

void setup() {
  Serial.begin(9600);

  //компас

  // серво
  S.attach(9);
  S.write(60);

  // моторы
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 

  //
  /*while ((digitalRead(2)) == 1) {
    delay(10);
  }*/
  //P1 ();
  //P2 ();
  //P3 ();
  //P4 ();
}

//датчик ИК:
//белый  >400 
//черный <400

//Serial.println(analogRead(A0));

//COLOR();

//S.write(0);
//взять     110
//отпустить 60

// моторы
//analogWrite(SL, 255);
//digitalWrite(ML, HIGH);
//analogWrite(SP, 255);
//digitalWrite(MP, HIGH);


void loop() {
  Serial.println (analogRead(A0));
  delay(100);
  //S.write(110);
}

void V() {
  while (Y < 100) {
    ++Y;  
    S.write(Y);
    delay(10);
  }
  A = 1;
}

void O() {
  while (Y > 60) {
    --Y;  
    S.write(Y);
    delay(10);
  }
  A = 0;
}


void LINIA() {
  while (((analogRead(A1)) > 400) || ((analogRead(A3)) > 400)) { 
    if  (((analogRead(A1)) > 400) && ((analogRead(A3)) > 400)) {
      analogWrite(SL, 70);
      digitalWrite(ML, HIGH);
      analogWrite(SP, 70);
      digitalWrite(MP, HIGH);
    }
    if  (((analogRead(A1)) > 400) && ((analogRead(A3)) < 400)) {
      analogWrite(SL, 200);
      digitalWrite(ML, HIGH);
      analogWrite(SP, 255);
      digitalWrite(MP, LOW);
    }
    if  (((analogRead(A1)) < 400) && ((analogRead(A3)) > 400)) {
      analogWrite(SL, 255);
      digitalWrite(ML, LOW);
      analogWrite(SP, 200);
      digitalWrite(MP, HIGH);
    }
  }
  delay (100);
  analogWrite(SL, 0);
  digitalWrite(ML, HIGH);
  analogWrite(SP, 0);
  digitalWrite(MP, HIGH);
  }

  void LINIA2() {
  while (((analogRead(A1)) < 400) || ((analogRead(A3)) < 400)) {  
    if  (((analogRead(A1)) < 400) && ((analogRead(A3)) < 400)) {
      analogWrite(SL, 70);
      digitalWrite(ML, HIGH);
      analogWrite(SP, 70);
      digitalWrite(MP, HIGH);
    }
    if  (((analogRead(A1)) < 400) && ((analogRead(A3)) > 400)) {
      analogWrite(SL, 200);
      digitalWrite(ML, HIGH);
      analogWrite(SP, 255);
      digitalWrite(MP, LOW);
    }
    if  (((analogRead(A1)) > 400) && ((analogRead(A3)) < 400)) {
      analogWrite(SL, 255);
      digitalWrite(ML, LOW);
      analogWrite(SP, 200);
      digitalWrite(MP, HIGH);
    }
  }
  delay (100);
  analogWrite(SL, 0);
  digitalWrite(ML, HIGH);
  analogWrite(SP, 0);
  digitalWrite(MP, HIGH);
  }

 void P1() {
  
 }

 void P2() {
  while (((analogRead(A1)) > 400) || ((analogRead(A3)) > 400)) {
     
  }
  while (((analogRead(A1)) < 400) && ((analogRead(A3)) < 400)) {
     analogWrite(SL, 70);
     digitalWrite(ML, HIGH);
     analogWrite(SP, 70);
     digitalWrite(MP, HIGH);
  }
 }
 
 void P3() {
  while (L < 8) {
    LINIA ();
    LINIA2 ();
    L=L+1;
  }
 }

 void P4() {
  
 }

