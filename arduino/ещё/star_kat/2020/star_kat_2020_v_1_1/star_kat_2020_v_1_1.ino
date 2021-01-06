//#include "const.h"
#define SR     11
#define DR     13
#define SL     10
#define DL     12

#define M  150

#define min_1 330
#define max_1 980
#define min_2 360
#define max_2 980

int in1, in2;

bool enkoder_2, enkoder_3, enkoder_4, enkoder_5;
long int E1 = 0;
long int E2 = 0;

unsigned long int time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(4, OUTPUT);
  //while (digitalRead(2));
  //linia();
  //motor(1, 255);
  //motor(2, 255);
}

void loop() {
  if (!digitalRead(2)) {
    stich_cod();
    //linia();
    //L();
    //linia();
    //R();
    //linia();
  }
  //test();
  /*enkoder();
  if (millis() > time + 1000) {
    Serial.println(E1);
    time = millis();
  }*/
}

void test() {
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
}

void dat() {
  in1 = map(analogRead(A0), min_1, max_1, 0, M);
  in2 = map(analogRead(A1), min_2, max_2, 0, M);
}

void stich_cod() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  time = millis();
  motor(1, M);
  motor(2, M*1.1);
  while (in1 <= M/2) dat();
  while (in1 >= M/2) dat();
  unsigned int polosa = (millis() - time)/2; // *1.1
  delay(polosa/2);
  for(int i = 0; i < 8; i++) {
    Serial.println(analogRead(A0));
    delay(polosa);
  }
  //Serial.println(polosa);
  motor(1, 0);
  motor(2, 0);
}

void linia() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  time = millis();
  while (millis() < time + 1200) pid(); 
  motor(1, 0);
  motor(2, 0);
}

void L() {
  motor(1, -M);
  motor(2, M);
  dat();
  while(in1 <= M/2) dat();
  while(in1 >= M/2) dat();
  while(in1 <= M/2) dat();
  motor(1, 0);
  motor(2, 0);
}

void R() {
  motor(1, M);
  motor(2, -M);
  dat();
  while(in2 <= M/2) dat();
  while(in2 >= M/2) dat();
  while(in2 <= M/2) dat();
  motor(1, 0);
  motor(2, 0);
}

void pid() {
  dat();
  int e = in1 - in2;
  motor(1, M + e);
  motor(2, M - e);
}

void enkoder() {
  //enkoder_2, enkoder_3, enkoder_4, enkoder_5;
  /*Serial.print(analogRead(A2)); Serial.print(" ");
  Serial.print(analogRead(A3)); Serial.print(" ");
  Serial.print(analogRead(A4)); Serial.print(" ");
  Serial.print(analogRead(A5)); Serial.print(" ");
  Serial.println();*/
  bool a2 = 0, a3 = 0, a4 = 0, a5 = 0;
  if (analogRead(A2) > 1000) a2 = 1;
  if (analogRead(A3) > 1000) a3 = 1;
  if (analogRead(A4) > 1000) a4 = 1;
  if (analogRead(A5) > 1000) a5 = 1;
  
  if ((enkoder_2 == 1) && (a2 == 0) && (a3 == 1)) E1++; //  && (enkoder_3 == 1)
  //if ((enkoder_2 == 0) && (a2 == 0) && (enkoder_3 == 1) && (a3 == 0)) E1++;
  //if ((enkoder_2 == 0) && (a2 == 1) && (enkoder_3 == 0) && (a3 == 0)) E1++;
  //if ((enkoder_2 == 1) && (a2 == 1) && (enkoder_3 == 0) && (a3 == 1)) E1++; 

  enkoder_2 = a2;
  enkoder_3 = a3;
  enkoder_4 = a4; 
  enkoder_5 = a5;
  
  //delay(1);
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
  
  if      (number == 1) analogWrite(SL, speed);
  else if (number == 2) analogWrite(SR, speed);
}
