#include <AFMotor.h>
#include <Servo.h>

// моторы
AF_DCMotor M1(1); 
AF_DCMotor M2(2);

//серво
Servo S;

// ЦВЕТ
#define s2  A5
#define s3  A3
#define out A4
byte red = 0;  // освобождаем память для переменных
byte green = 0;
byte blue = 0;

// рабочие переменные
int G = 1    // номер груза
int Y = 70;  // серво
int A = 0;   // наличие груза 0-нет  1-есть
int C = 0;   // цвет определяемый
//int C1 = 0;  // бывший цвет
             //   1-белый   2-красный

void setup() // процедура setup
{
  Serial.begin(9600);
  
 //ЦВЕТ
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 
 // серво
 S.attach(9);
 S.write(70);

 delay (1000);  // задержка, чтобы не сразу машинка стартовала
} 

//датчик ИК:
//белый  >600 
//черный <600

//Serial.println(analogRead(A0));

//COLOR();

//S.write(0);
//взять     110
//отпустить 70

// моторы
// FORWARD   впреред
// BACKWARD  назад
// RELEASE   стоп
// M1.run(RELASE);
// M1.setSpeed(255);

void loop() {

  
 // LINIA();
  LINIA();
  
  //V();
  //LINIA();
  L();
  LINIA();
  O();
}

void MODUL() {   // модуль отвоза и возврата груза (*6 полное прохождение трассы)
  if (G == 1) {
    LINIA();
    LINIA();
    L();
  }
  LINIA();
  V();
  L();
  LINIA();
  if ((G == 1) || (G == 2) || (G == 3)) {
    L();
  }
  else {
    P();
  }
  if ((G == 1) || (G == 4)) {
    LINIA();
    LINIA();
    LINIA();
  }
  if ((G == 2) || (G == 5)) {
    LINIA();
    LINIA();
  }
  if ((G == 3) || (G == 6)) {
    LINIA();
  }
  if (C == 1) {
    P();
  }
  else {
    L();
  }
  LINIA();
  O();
  M1.run(BACKWARD);   //отьехать назад
  M1.setSpeed(70);
  M2.run(BACKWARD);
  M2.setSpeed(70);
  delay (200);
  L();
  LINIA();
  if ((G == 1) || (G == 4)) {
    L();
    LINIA();
    LINIA();
  }
  if ((G == 2) || (G == 5)) {
    L();
    LINIA();
  }
  if (G == 3) {
    L();
    LINIA();
    LINIA();
    LINIA();
  }
  if (G == 6) {
    P();
    LINIA();
    M1.run(FORWARD);
    M1.setSpeed(70);
    M2.run(FORWARD);
    M2.setSpeed(70);
    delay (200);
  }
  if ((G == 1) || (G == 2) || (G == 3) || (G == 4) || (G == 5)) {
    if ((G == 1) || (G == 2) || (G == 3)) {
      P();
    }
    else {
      L();
    }
  }
  ++G;
}

void V() {   // взять
  while (Y < 110) {
    ++Y;  
    S.write(Y);
    delay(10);
  }
  A = 1;
}

void O() {   // отпустить
  while (Y > 70) {
    --Y;  
    S.write(Y);
    delay(10);
  }
  A = 0;
}

void L() {   // поворот влево
  M1.run(BACKWARD);
  M1.setSpeed(100);
  M2.run(FORWARD);
  M2.setSpeed(100);
  while ((analogRead(A1)) < 600){}
  while ((analogRead(A1)) > 600){}
  while ((analogRead(A1)) < 600){}
  M1.run(RELEASE);
  M2.run(RELEASE);
}

void P() {{   // поворот вправо
  M1.run(FORWARD);
  M1.setSpeed(100);
  M2.run(BACKWARD);
  M2.setSpeed(100);
  while ((analogRead(A2)) < 600){}
  while ((analogRead(A2)) > 600){}
  while ((analogRead(A2)) < 600){}
  M1.run(RELEASE);
  M2.run(RELEASE);
}

void LINIA() {{   // движение по линии до перекрестка ? и детали ?
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600) || ( ((analogRead(A0)) > 250) && (A = 0))) {  // значение A0 надо корректировать
    if  (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      M1.run(FORWARD);
      M1.setSpeed(70);
      M2.run(FORWARD);
      M2.setSpeed(70);
    }
    if  (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      M1.run(FORWARD);
      M1.setSpeed(200);
      M2.run(BACKWARD);
      M2.setSpeed(255);
    }
    if  (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      M1.run(BACKWARD);
      M1.setSpeed(255);
      M2.run(FORWARD);
      M2.setSpeed(200);
    }
  }
      while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) {
      M1.run(FORWARD);
      M1.setSpeed(70);
      M2.run(FORWARD);
      M2.setSpeed(70);
  }
  delay (100);
  M1.run(RELEASE);
  M2.run(RELEASE);
  }

void COLOR() // процедура определения цвета
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
