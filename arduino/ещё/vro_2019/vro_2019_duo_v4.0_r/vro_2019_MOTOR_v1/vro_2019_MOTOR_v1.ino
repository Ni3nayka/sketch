#include <Servo.h>
Servo S;
byte napr = 1;
#define PWMA 3
#define AIN1 2
#define AIN2 4
#define PWMB 6
#define BIN1 5
#define BIN2 7
#define M      255    //125
int in0, in1, in2, in3, in4;
#define LIN    620 // время для одной клетки (lin)
#define POV    420  // время для поворота на 90 градусов
int D = 0;   //для определения дугового движения
int a = 0;   // длинна дороги
int k = 0;   // длинна дороги прямого участка пути
int e = 0;   // ошибка для П регулятора
int min_2 = 600;
int min_3 = 500;
int max_2 = 900;
int max_3 = 900;
float A = 0; // какая локация
byte f, i, j, flag, ff, Ai;
char F = 0;  // для обмена данными между ардуинами/ПК
byte kkk = 0;

void setup() {
  Serial.begin(9600);
  S.attach(9);
  S.write(25); // 100
  pinMode (8, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  zum();
  //while ((digitalRead(10) == 1) && (ROOT == 2)) { delay(1); } delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    F = Serial.read();
    flag = 0;
    if (F == 'l') {
      linia();
      //flag = 1;
    }
    if (F == 'v') {
      lin();
      //flag = 1;
    }
    if (F == 'A') {
      auto_set();
    }
    if (F == 'V') {
      V();
      flag = 1;
    }
    if (F == 'L') {
      L();
      flag = 1;
    }
    if (F == 'R') {
      R();
      flag = 1;
    }
    if (F == 'Z') {
      zum();
      flag = 1;
    }
    if (F == 'P') {
      povorot();
      flag = 1;
    }
    if (F == 'o') {
      out();
      flag = 1;
    }
    if (flag == 1) {
      Serial.println("O");
    }
  }
}

void zapros() {
  F = 0;
  while (F == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '0') { F = 0; }
      if (F == '1') { F = 1; }
      if (F == '2') { F = 2; }
      if (F == '3') { F = 3; }
      if (F == '4') { F = 4; }
      if (F == '5') { F = 5; }
      if (F == '6') { F = 6; }
      if (F == '7') { F = 7; }
      if (F == '8') { F = 8; }
      if (F == '9') { F = 9; }
    }
  }
}

void povorot() {
  zapros();
  analogWrite(PWMA, M);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  analogWrite(PWMB, M);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
  while (F > 0) {
    delay(POV);  
    F--;
  }
  analogWrite(PWMA, 0);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  analogWrite(PWMB, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
}

void bluetooth() {
  if (Serial.available() > 0) {
    F = Serial.read();
    if (F == 'l') {
      linia();
      flag = 0;
    }
    if (F == 'L') {
      L();
      flag = 0;
    }
    if (F == 'R') {
      R();
      flag = 0;
    }
    if (F == 'V') {
      lin();
      flag = 0;
    }
    if (F == '2') {
      flag = 2;
    }
    if (F == '1') {
      flag = 1;
    }
  }
  if (flag == 1) {
    test_d();
  }
  if (flag == 2) {
    test_d3();
  }
}

void auto_set() {
    napr = 1;
    if (analogRead(A0) >= 725) {
      k = 0;
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 0);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 0);
      digitalWrite(BIN2, 1);
      while (analogRead(A0) <= 725) { k++; delay(1); }
      while (analogRead(A0) >= 725) { k++; delay(1); }
      k = k/(POV - 120); 
      while (k > 0) {
        //r();
        if (napr == 4) { napr = 1; }
        else { napr++; }
        k--;
      }
      analogWrite(PWMA, 0);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, 0);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 1);
      k = 0;
    }
    Serial.println(napr);
}

//-----------------------------------------

void V() {
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);
    while ((analogRead(A1) < 600) || (analogRead(A4) < 600)) {} 
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  
}

void L() {
    //Serial.println("L");
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 0);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);
    delay(300);
    while (analogRead(A0) <= 725) {}
    while (analogRead(A0) >= 725) {}
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
}

void R() {
    //Serial.println("R");
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
    delay(300);
    while (analogRead(A0) <= 725) {}
    while (analogRead(A0) >= 725) {}
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
}

void zum() {
    digitalWrite(8, 1);
    delay(100);
    digitalWrite(8, 0);
    delay(100);
    digitalWrite(8, 1);
    delay(100);
    digitalWrite(8, 0);
    delay(100);
}

void out() {
  S.write(100);
  delay(500);
  S.write(25);
  delay(500);
}

//-----------------------------------------

void convecter() {
  if (A == 2.1) { Ai = 1; } 
  if (A == 2.2) { Ai = 2; }
  if (A == 3.1) { Ai = 3; }
  if (A == 3.2) { Ai = 4; }
  if (A == 5)   { Ai = 5; }
  if (A == 5.1) { Ai = 6; }
  if (A == 5.2) { Ai = 7; }
  if (A == 6)   { Ai = 8; }
  if (A == 4)   { Ai = 9; }
  if (A == 1)   { Ai = 0; }
}

void lin() { // линия до центра клетки
    a = 0;
    D = 0;
    while ((analogRead(A1) > 500) && (analogRead(A4) > 500) && ((analogRead(A2) < 900) || (analogRead(A3) < 900)) && (k < LIN))  { // (abs(D) < 4500) && 
      linia_d();
      //if (abs(e) >= M*0.9) { D = D + e; }
      if (abs(e) < 5) { D = 0; }
      k++;
      delay(1);
    }
    if (abs(D) > 4500) {  // дуга
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else {
    /*if (k < LIN + 200) {       // не дуга
      /*digitalWrite(AIN1, 0);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 0);
      digitalWrite(BIN2, 1);
      delay(50);
      analogWrite(PWMA, 0);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, 0);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 1);
      delay(200);
    }*/
    process();
    }
    //a = k/LIN - 1;
    //if (a < 0) { a = 0; }
    a = 0;
    //-------------------------------------------------- проехали по линии до какого-то элемента
    if ((D < 4500) && (k < LIN) && (A != 4)) {
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 0);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 0);
      delay(250);
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 0);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 0);
      digitalWrite(BIN2, 1);
      delay(20);
      analogWrite(PWMA, 0);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, 0);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 1);
    }
    convecter();
    //Serial.print("(A:");
    Serial.println(Ai); 
    //Serial.print(" a:");
    //Serial.println(a); 
    //Serial.print(" k:");
    //Serial.print(k);
    //Serial.println(")");
    D = 0;
    k = 0;
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  
}

void linia() {
    a = 0;
    D = 0;
    while ((analogRead(A1) > 500) && (analogRead(A4) > 500) && ((analogRead(A2) < 900) || (analogRead(A3) < 900)))  {  // (abs(D) < 4500) && 
      linia_d();
      //if (abs(e) >= M*0.9) { D = D + e; }
      if (abs(e) < 5) { D = 0; }
      k++;
      delay(1);
    }
    if (abs(D) > 4500) {  // дуга
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else {       // не дуга
      /*analogWrite(PWMA, M);
      digitalWrite(AIN1, 0);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 0);
      digitalWrite(BIN2, 1);
      delay(50);
      analogWrite(PWMA, 0);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, 0);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 1);
      delay(200);*/
      process();
    }
    a = k/(LIN - 200) - 1;
    if (a < 0) { a = 0; }
    //-------------------------------------------------- проехали по линии до какого-то элемента
    Serial.println(k);
    if ((D < 4500) && (A != 4)) {
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 0);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 0);
      delay(250);  // 250
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 0);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 0);
      digitalWrite(BIN2, 1);
      delay(20);
      analogWrite(PWMA, 0);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 1);
      analogWrite(PWMB, 0);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 1);
    }
    D = 0;
    //test_d2();
    convecter();
    //Serial.print("(A:");
    Serial.println(Ai); 
    //Serial.print(" a:");
    Serial.println(a); 
    //Serial.print(" k:");
    //Serial.print(k);
    //Serial.println(")");
    k = 0;
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
}

void linia_d() {
  in2 = analogRead(A2);
  in3 = analogRead(A3);
  if (in2 > max_2) { max_2 = in2; }
  if (in2 < min_2) { min_2 = in2; }
  if (in3 > max_3) { max_3 = in3; }
  if (in3 < min_3) { min_3 = in3; }
  e = (map(in3, min_3, max_3, 0, M) - map(in2, min_2, max_2, 0, M))*1.5;
  if (e > M)      { e = M; }
  if (e < M*(-1)) { e = M*(-1); }
  if (e > 0) {
    analogWrite(PWMA, M - e);
    analogWrite(PWMB, M);
  }
  else {
    analogWrite(PWMA, M);
    analogWrite(PWMB, M + e);
  }
  //analogWrite(PWMA, M - e);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  //analogWrite(PWMB, M + e);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
  /*digitalWrite(DL, 1);
  analogWrite (SL, M - e);
  digitalWrite(DR, 1); 
  analogWrite (SR, M + e);*/
}

void process() {
  A = 0;
  /*if (analogRead(A1) < 570) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 750) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 825) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 600) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 725) { in0 = 1; } else { in0 = 0; }*/
  if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 600) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 700) { in0 = 1; } else { in0 = 0; }
  if ((in2 == 1) || (in3 == 1)) {
    if ((in1 == 1) && (in4 == 1) && (in0 == 1)) { A = 6;   }
    if ((in1 == 1) && (in4 == 1) && (in0 == 0)) { A = 5;   }
    if ((in1 == 1) && (in4 == 0) && (in0 == 1)) { A = 5.1; }
    if ((in1 == 0) && (in4 == 1) && (in0 == 1)) { A = 5.2; }
    if ((in1 == 0) && (in4 == 1) && (in0 == 0)) { A = 3.2; }
    if ((in1 == 1) && (in4 == 0) && (in0 == 0)) { A = 3.1; }
    if ((in1 == 0) && (in4 == 0) && (in0 == 1)) { A = 1;   }
  }
  else {
    A = 4;
  }
}

void test_d3() {
  if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 700) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 800) { in0 = 1; } else { in0 = 0; }
  Serial.print(in1);
  Serial.print(" ");
  Serial.print(in2);
  Serial.print(" ");
  Serial.print(in3);
  Serial.print(" ");
  Serial.print(in4);
  Serial.print(" ");
  Serial.println(in0);
  delay(100);
}

void test_d2() {
  Serial.println(A);
  Serial.print(in1);
  Serial.print(" ");
  Serial.print(in2);
  Serial.print(" ");
  Serial.print(in3);
  Serial.print(" ");
  Serial.print(in4);
  Serial.print(" ");
  Serial.println(in0);
  delay(100);
}

void test_d() {
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.println(analogRead(A0));
  delay(100);
}

void test_e() {
  in2 = analogRead(A2);
  in3 = analogRead(A3);
  if (in2 > max_2) { max_2 = in2; }
  if (in2 < min_2) { min_2 = in2; }
  if (in3 > max_3) { max_3 = in3; }
  if (in3 < min_3) { min_3 = in3; }
  e = (map(in3, min_3, max_3, 0, 50) - map(in2, min_2, max_2, 0, 50));
  //e = (map((analogRead(A3)), 729, 985, 0, 50) - map((analogRead(A2)), 650, 972, 0, 50));
  Serial.println(e);
  delay(100);
}


