#include <Servo.h>

//серво
Servo S;

// ЦВЕТ
#define s2  A5
#define s3  A3
#define out A4
byte red = 0;  // освобождаем память для переменных
byte green = 0;
byte blue = 0;

// МОТОРЫ
int E1 = 10;   // скорость вращения
int M1 = 12;   // направление вращения
int E2 =11;    // скорость вращения
int M2 = 13;   // направление вращения

// рабочие переменные
int Y = 70;  // серво
int A = 0;
int C = 0;   // цвет определяемый
int C1 = 0;  // бывший цвет
             //   1-белый   2-красный

void setup() // процедура setup
{
  Serial.begin(9600);
  
 //ЦВЕТ
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 
 //МОТОРЫ
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);

 // серво
 S.attach(9);
 S.write(70);
} 

//датчик ИК:
//белый  >600 
//черный <600

// digitalWrite(M1,HIGH);
// digitalWrite(M2, HIGH);
// analogWrite(E1, 255);
// analogWrite(E2, 255);

//Serial.println(analogRead(A0));

//COLOR();

//S.write(0);
//взять     110
//отпустить 70

void loop() {
  
}

void V() {
  while (Y < 110) {
    ++Y;  
    S.write(Y);
    delay(10);
  }
}

void O() {
  while (Y > 70) {
    --Y;  
    S.write(Y);
    delay(10);
  }
}

void L() {
  digitalWrite(M1,LOW);
  analogWrite(E2, 100);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 100);
  while ((analogRead(A1)) < 600){}
  while ((analogRead(A1)) < 600){}
  while ((analogRead(A1)) < 600){}
  digitalWrite(M1,HIGH);
  analogWrite(E2, 0);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
}

void P() {
  digitalWrite(M1,HIGH);
  analogWrite(E2, 100);
  digitalWrite(M2, LOW);
  analogWrite(E1, 100);
  while ((analogRead(A2)) < 600){}
  while ((analogRead(A2)) < 600){}
  while ((analogRead(A2)) < 600){}
  digitalWrite(M1,HIGH);
  analogWrite(E2, 0);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
}

void LINIA() {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if  (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(M1,HIGH);
      analogWrite(E2, 70);
      digitalWrite(M2, HIGH);
      analogWrite(E1, 70);
    }
    if  (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(M1,HIGH);
      analogWrite(E2, 255);
      digitalWrite(M2, LOW);
      analogWrite(E1, 200);
    }
    if  (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(M1,LOW);
      analogWrite(E2, 200);
      digitalWrite(M2, HIGH);
      analogWrite(E1, 255);
    }
  }
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) {
    digitalWrite(M1,HIGH);
    analogWrite(E2, 255);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 255);
  }
  digitalWrite(M1,HIGH);
  analogWrite(E2, 0);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
}

void COLOR() // процедура color
{
 // если 2 и 3 порты отключить, то получим значение красного цвета
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // если 3 порт включить, а 2 отключить, то получим синий цвет
 digitalWrite(s3, HIGH);
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // если 2 включить, а 3 отключить, то получим зеленый цвет
 digitalWrite(s2, HIGH);
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 // назначаем номер цвету---------------------------
 if (blue < 8) {
    C = 1;
  }
  else {
    C = 2;
  } 
  delay (1000);
}
