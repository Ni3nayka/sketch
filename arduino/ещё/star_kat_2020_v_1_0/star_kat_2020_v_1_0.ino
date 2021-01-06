//#include "const.h"
#define SR     11
#define DR     13
#define SL     10
#define DL     12

#define M  150

#define min_1 123
#define max_1 987
#define min_2 123
#define max_2 987

int in1, in2;

void setup() {
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(4, OUTPUT);
  //while (digitalRead(2));
}

void loop() {
  
}

void dat() {
  in1 = map(analogRead(A0), min_1, max_1, 0, M);
  in2 = map(analogRead(A1), min_2, max_2, 0, M);
}

void zum() {
  digitalWrite(4, 1);
  delay(100);
  digitalWrite(4, 0);
  delay(100);
  digitalWrite(4, 1);
  delay(100);
  digitalWrite(4, 0);
  delay(100);
}

void motor(byte number, int speed) { 
  if      ((number == 1) && (speed > 0)) digitalWrite(DL, 1);
  else if ((number == 1) && (speed < 0)) digitalWrite(DL, 0);
  else if ((number == 2) && (speed > 0)) digitalWrite(DR, 1);
  else if ((number == 2) && (speed < 0)) digitalWrite(DR, 0);

  if (abs(speed) > 255) speed = (speed/abs(speed))*255;
  
  if      (number == 1) digitalWrite(DL, speed);
  else if (number == 2) digitalWrite(DR, speed);
}
