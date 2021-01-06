/*#include <NewPing.h>

#define TRIGGER_PIN  29  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     28  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.*/

#include <Servo.h>

Servo S1;
Servo S2;

#define SR     11
#define DR     13
#define SL     10
#define DL     12

#define M  250

#define min_1 360
#define max_1 980
#define min_2 360
#define max_2 980

int in1, in2;
bool in3, in4;

bool encoder_2 = 0, encoder_3 = 0, encoder_4 = 0, encoder_5 = 0;
long int E1 = 0;
long int E2 = 0;
bool a2 = 0, a3 = 0, a4 = 0, a5 = 0;

unsigned long int time = 0;

int mas[4] = {-1,-1,-1,-1};

void setup() {
  delay(500);
  S1.attach(52);
  S2.attach(53);
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, INPUT);
  //encoder
  a2 = digitalRead(20);
  a3 = digitalRead(21);
  a4 = digitalRead(18);
  a5 = digitalRead(19);
  attachInterrupt(3, gerkon_1, CHANGE);
  attachInterrupt(2, gerkon_2, CHANGE);
  attachInterrupt(4, gerkon_3, CHANGE);
  attachInterrupt(5, gerkon_4, CHANGE);
  //while (digitalRead(2));
  //S1.write(10); S2.write(180); // взять
  S1.write(160); S2.write(20); // отпустить
  
}

void loop() {
  //S1.write(10); S2.write(180); // взять
  //S1.write(160); S2.write(20); // отпустить
  //S1.write(40); S2.write(140);
  //Serial.print(E1); Serial.print(" "); Serial.println(E2);
  //motor_encoder_test();
  //test();
  Serial.println(analogRead(A3));
  if (!digitalRead(2)) {
    algoritm3();
    //forward_encoder_cm(23);
  }
}

void algoritm2() {
  linia_old();
  linia_old();
  linia_old();
  linia_old();
  linia_old();
  linia_old();
  linia_old();
  forward_encoder_cm(45);
  L_G(90);
  forward_encoder_cm(36);
}

void algoritm() {
  //S1.write(10); S2.write(180); // взять
  S1.write(160); S2.write(20); // отпустить
  //S1.write(80); S2.write(100);
  E1 = 0; 
  E2 = 0;
  int i;
  int u = 4;
  long int D;
  for(i = 1; i <= 7; i++) {
    linia_old();
    L_G(90);
    S1.write(80); S2.write(100); delay(1000);
    forward_encoder_cm(30);
    if (in4) {
      S1.write(10); S2.write(180); delay(1000);// взять
      backward_encoder_cm(32);
      L_G(90);
      for(int r = 1; r < i; r++) linia_old();
      linia9();
      for(int uu = 1; uu < u; uu++) {
        linia10();
      }
      S1.write(160); S2.write(20); delay(1000);
      L_G(180);
      for(int uu = 1; uu < u; uu++) {
        linia10();
      }
      u--;
      linia_old();
      for(int r = 1; r < i; r++) linia_old();
    }
    else {
      S1.write(160); S2.write(20); delay(1000);
      //L_G(180);
      backward_encoder_cm(32);
      R_G(90);
    }
    
    //R_G(360);
    
  }
  
  //linia_old();
  //S1.write(160); S2.write(20);
  forward_encoder_cm(45);
  L_G(90);
  forward_encoder_cm(40);
}

void algoritm3() {
  //S1.write(10); S2.write(180); // взять
  S1.write(160); S2.write(20); // отпустить
  //S1.write(80); S2.write(100);
  E1 = 0; 
  E2 = 0;
  int i;
  int u = 4;
  long int D;
  for(i = 1; i <= 7; i++) {
    linia_old();
    L_G(90);
    S1.write(80); S2.write(100); delay(1000);
    forward_encoder_cm(50);
    S1.write(160); S2.write(20); delay(1000);
    //L_G(180);
    backward_encoder_cm(52);
    R_G(90);
  }
  //linia_old();
  //S1.write(160); S2.write(20);
  forward_encoder_cm(45);
  L_G(90);
  forward_encoder_cm(40);
}

int dist() {
  //return sonar.ping_cm();
}

void motor_encoder_test() {
  long int EE1 = E1*2;
  long int EE2 = E2*2;
  if (abs(EE1) > 100) EE1 = (EE1/abs(EE1))*100;
  if (abs(EE2) > 100) EE2 = (EE2/abs(EE2))*100;
  motor(1, -EE1);
  motor(2, -EE2);
}

void test() {
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.println(analogRead(A3));
}

void dat() {
  in1 = map(analogRead(A1), min_1, max_1, 0, M);
  in2 = map(analogRead(A2), min_2, max_2, 0, M);
  if (analogRead(A0) > 600) in3 = 1;
  else in3 = 0;
  if (analogRead(A3) > 550) in4 = 1;
  else in4 = 0;
}

void linia10() {
  dat();
  while ((in1 >= M/2) && (in2 >= M/2) && in3) pid(); 
  while (((in1 >= M/2) || (in2 >= M/2)) && !in3) pid();
  long int e1 = E1;
  long int e2 = E2;
  while ((E1 - e1 < 300) && (E2 - e2 < 300)) {
    pid();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
  }
  encoder_stabilitation();
}

void linia9() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  long int e1 = E1;
  long int e2 = E2;
  while ((E1 - e1 < 300) && (E2 - e2 < 300)) {
    pid();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
  }
  encoder_stabilitation();
}

void linia_old() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  long int e1 = E1;
  long int e2 = E2;
  while ((E1 - e1 < 800) && (E2 - e2 < 800)) {
    pid();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
  }
  encoder_stabilitation();
}

void linia() {
  dat();
  while (((in1 >= M/2) || (in2 >= M/2)) && ((!in3) || (in1 <= M/2) || (in2 <= M/2)) && (!in4)) pid();
  if (!in4 && !in3) {
    long int e1 = E1;
    long int e2 = E2;
    while ((E1 - e1 < 800) && (E2 - e2 < 800)) {
      pid();
      Serial.print(E1); Serial.print(" "); Serial.println(E2);
    }
  }
  encoder_stabilitation();
}

void big_linia() {
  dat();
  while (((in1 >= M/2) || (in2 >= M/2)) && (!in3) && (!in4)) pid();
  if (!in4 && !in3) {
    long int e1 = E1;
    long int e2 = E2;
    while ((E1 - e1 < 800) && (E2 - e2 < 800)) {
      pid();
      Serial.print(E1); Serial.print(" "); Serial.println(E2);
    }
  }
  encoder_stabilitation();
}

void forward_encoder_cm(int g) {
  //int o = 1000;
  int cm = 59;
  int o = cm*g;
  long int e1 = E1;
  long int e2 = E2;
  long int EE1, EE2;
    dat();
  while((abs(E1 - e1 - o) > 20) && (abs(E2 - e2 - o) > 20)) { // && !in4
    dat();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 - o)*5;
    EE2 = (E2 - e2 - o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  //Serial.println("A");
  //motor(1, 0);
  //motor(2, 0);
  encoder_stabilitation();
}

void backward_encoder_cm(int g) {
  //int o = 1000;
  int cm = 59;
  int o = cm*g;
  long int e1 = E1;
  long int e2 = E2;
  long int EE1, EE2;
    dat();
  while((abs(E1 - e1 + o) > 20) && (abs(E2 - e2 + o) > 20)) { // && !in4
    dat();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 + o)*5;
    EE2 = (E2 - e2 + o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  //Serial.println("A");
  //motor(1, 0);
  //motor(2, 0);
  encoder_stabilitation();
}

void backward_encoder(int g) {
  //int o = 1000;
  int cm = 59;
  int o = g;
  long int e1 = E1;
  long int e2 = E2;
  long int EE1, EE2;
    dat();
  while((abs(E1 - e1 + o) > 20) && (abs(E2 - e2 + o) > 20) && !in4) {
    dat();
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 + o)*5;
    EE2 = (E2 - e2 + o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  //Serial.println("A");
  //motor(1, 0);
  //motor(2, 0);
  encoder_stabilitation();
}

int forward_encoder() {
  //int o = 1000;
  int cm = 58;
  //int o = cm*g;
  long int e1 = E1;
  long int e2 = E2;
  /*long int EE1, EE2;
  while((abs(E1 - e1 - o) > 10) && (abs(E2 - e2 - o) > 10)) {
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 - o)*5;
    EE2 = (E2 - e2 - o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }*/
  while (!in4 && ((in1 >= M/2) || (in2 >= M/2)) && !in3) {
    pid_encoder();
  }
  encoder_stabilitation();
}

void encoder_stabilitation() {
  time = millis();
  long int e1 = E1;
  long int e2 = E2;
  int EE1, EE2;
  while(time + 500 > millis()) {
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1)*5;
    EE2 = (E2 - e2)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  motor(1, 0);
  motor(2, 0);
}

void R_G(int g) {
  int o = 4200;
  o = o/360*g;
  long int e1 = E1;
  long int e2 = E2;
  long int EE1, EE2;
  while((abs(E1 - e1 - o) > 10) && (abs(E2 - e2 + o) > 10)) {
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 - o)*5;
    EE2 = (E2 - e2 + o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  encoder_stabilitation();
}

void L_G(int g) {
  int o = 4200;
  o = o/360*g;
  long int e1 = E1;
  long int e2 = E2;
  long int EE1, EE2;
  while((abs(E1 - e1 + o) > 10) && (abs(E2 - e2 - o) > 10)) {
    Serial.print(E1); Serial.print(" "); Serial.println(E2);
    EE1 = (E1 - e1 + o)*5;
    EE2 = (E2 - e2 - o)*5;
    if (abs(EE1) > 200) EE1 = (EE1/abs(EE1))*200;
    if (abs(EE2) > 200) EE2 = (EE2/abs(EE2))*200;
    motor(1, -EE1);
    motor(2, -EE2);
  }
  encoder_stabilitation();
}

void L() {
  motor(1, -M);
  motor(2, M);
  dat();
  while(in1 <= M/2) dat();
  while(in1 >= M/2) dat();
  while(in1 <= M/2) dat();
  encoder_stabilitation();
}

void R() {
  motor(1, M);
  motor(2, -M);
  dat();
  while(in2 <= M/2) dat();
  while(in2 >= M/2) dat();
  while(in2 <= M/2) dat();
  encoder_stabilitation();
}

void pid() {
  dat();
  int e = in1 - in2;
  motor(1, M + e);
  motor(2, M - e);
}

void pid_encoder() {
  //dat(); // for stich_cod()
  long int e = (E1 - E2)*2;
  if (abs(e) > M) e = (e/abs(e))*M;
  Serial.print(E1); Serial.print(" "); Serial.print(E2); Serial.print(" "); Serial.println(e);
  if (abs(e) > M) e = (e/abs(e))*M;
  motor(1, M - e);
  motor(2, M + e);
}

void gerkon_1() {
  if (a2) a2 = 0;
  else a2 = 1;
  
  if (!encoder_3 &&  a3 && !encoder_2 && !a2) E1++;
  if ( encoder_3 &&  a3 && !encoder_2 &&  a2) E1++;
  if ( encoder_3 && !a3 &&  encoder_2 &&  a2) E1++;
  if (!encoder_3 && !a3 &&  encoder_2 && !a2) E1++;

  if (!encoder_2 &&  a2 && !encoder_3 && !a3) E1--;
  if ( encoder_2 &&  a2 && !encoder_3 &&  a3) E1--;
  if ( encoder_2 && !a2 &&  encoder_3 &&  a3) E1--;
  if (!encoder_2 && !a2 &&  encoder_3 && !a3) E1--;

  encoder_2 = a2;
}

void gerkon_2() {
  if (a3) a3 = 0;
  else a3 = 1;
  
  if (!encoder_3 &&  a3 && !encoder_2 && !a2) E1++;
  if ( encoder_3 &&  a3 && !encoder_2 &&  a2) E1++;
  if ( encoder_3 && !a3 &&  encoder_2 &&  a2) E1++;
  if (!encoder_3 && !a3 &&  encoder_2 && !a2) E1++;

  if (!encoder_2 &&  a2 && !encoder_3 && !a3) E1--;
  if ( encoder_2 &&  a2 && !encoder_3 &&  a3) E1--;
  if ( encoder_2 && !a2 &&  encoder_3 &&  a3) E1--;
  if (!encoder_2 && !a2 &&  encoder_3 && !a3) E1--;

  encoder_3 = a3;
}

void gerkon_3() {
  if (a4) a4 = 0;
  else a4 = 1;
  
  if (!encoder_5 &&  a5 && !encoder_4 && !a4) E2++;
  if ( encoder_5 &&  a5 && !encoder_4 &&  a4) E2++;
  if ( encoder_5 && !a5 &&  encoder_4 &&  a4) E2++;
  if (!encoder_5 && !a5 &&  encoder_4 && !a4) E2++;

  if (!encoder_4 &&  a4 && !encoder_5 && !a5) E2--;
  if ( encoder_4 &&  a4 && !encoder_5 &&  a5) E2--;
  if ( encoder_4 && !a4 &&  encoder_5 &&  a5) E2--;
  if (!encoder_4 && !a4 &&  encoder_5 && !a5) E2--;

  encoder_4 = a4;
}

void gerkon_4() {
  if (a5) a5 = 0;
  else a5 = 1;
  
  if (!encoder_5 &&  a5 && !encoder_4 && !a4) E2++;
  if ( encoder_5 &&  a5 && !encoder_4 &&  a4) E2++;
  if ( encoder_5 && !a5 &&  encoder_4 &&  a4) E2++;
  if (!encoder_5 && !a5 &&  encoder_4 && !a4) E2++;

  if (!encoder_4 &&  a4 && !encoder_5 && !a5) E2--;
  if ( encoder_4 &&  a4 && !encoder_5 &&  a5) E2--;
  if ( encoder_4 && !a4 &&  encoder_5 &&  a5) E2--;
  if (!encoder_4 && !a4 &&  encoder_5 && !a5) E2--;

  encoder_5 = a5;
}

void zum() {
  int t = 3000;
  //digitalWrite(4, 1);
  tone(4, t);
  delay(100);
  noTone(4);
  delay(100);
  tone(4, t);
  delay(100);
  noTone(4);
  delay(100);
}

void motor(byte number, int speed) { 
  if      ((number == 1) && (speed > 0)) digitalWrite(DL, 1);
  else if ((number == 1) && (speed < 0)) digitalWrite(DL, 0);
  else if ((number == 2) && (speed > 0)) digitalWrite(DR, 1);
  else if ((number == 2) && (speed < 0)) digitalWrite(DR, 0);

  if (abs(speed) > 255) speed = (speed/abs(speed))*255;
  
  if      (number == 1) analogWrite(SL, abs(speed));
  else if (number == 2) analogWrite(SR, abs(speed));
}
