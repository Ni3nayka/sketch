#define SR     11
#define DR     13
#define SL     10
#define DL     12
#define M      125
//float p = 0;
float A = 0; // какая локация
int   in0, in1, in2, in3, in4;
int D = 0;   //для определения дугового движения
int a = 0;   // длинна дороги
int k = 0;   // длинна дороги прямого участка пути
int e = 0;   // ошибка для П регулятора
int min_2 = 600;
int min_3 = 500;
int max_2 = 900;
int max_3 = 900;
char F = 0;  // для ввода/вывода информации

/* arxiv:
 *  Y - да, все ОК
 *  E - ошибка
 *  S - старт
 *  ; - завершение подпрограммы bluetooth
 *  / - переход на новую строку (bluetooth)
 */

void setup() {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (4 , OUTPUT);
  pinMode (DR, OUTPUT);
  pinMode (DL, OUTPUT);
  hello();
}

void loop() {
  while (Serial.available() == 0) { }
  F = Serial.read();
  //Serial.println(F);
  if ((F == 'Z') || (F == 'V') || (F == 'L') || (F == 'R') || (F == 'N') || (F == 'l') || (F == 'B')) {
    Serial.println("S");
    if (F == 'Z') { zum();   }
    if (F == 'V') { V();     }
    if (F == 'L') { L();     }
    if (F == 'R') { R();     }
    if (F == 'N') { N();     }
    if (F == 'l') { linia(); }
    if (F == 'B') { BT();    }
    Serial.println("Y");
  }
  else {
    Serial.print("E");
  }
}

void BT() {
  while (F != ';') {
    while (Serial.available() == 0) { }
    F = Serial.read();
    //if (F == '/') { softSerial.println(); } else { softSerial.print(F); }
  }
}

void hello() {
  while (F == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == 'H') { Serial.println("Y"); }
      else { F = 0; }
    }
  }
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

void V() {
  digitalWrite(DL, 1);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  while ((analogRead(A1) < 600) || (analogRead(A4) < 600)) {} 
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void L() {
  digitalWrite(DL, 0);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void R() {
  digitalWrite(DL, 1);
  analogWrite (SL, M);
  digitalWrite(DR, 0);
  analogWrite (SR, M);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void N() {
  digitalWrite(DL, 0);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void linia() {
  a = 0;
  D = 0;
  while ((abs(D) < 4500) && (analogRead(A1) > 350) && (analogRead(A4) > 350) && ((analogRead(A2) < 850) || (analogRead(A3) < 850)))  {
    linia_d();
    if (abs(e) >= M*0.9) { D = D + e; }
    if (abs(e) < 5) { D = 0; }
    k++;
    delay(1);
  }
  if (D < 4500) {
    digitalWrite(DL, 1);
    analogWrite (SL, M);
    digitalWrite(DR, 1);
    analogWrite (SR, M);
    delay(100);
    digitalWrite(DL, 0);
    analogWrite (SL, M);
    digitalWrite(DR, 0);
    analogWrite (SR, M);
    delay(20);
    digitalWrite(DL, 0);
    analogWrite (SL, 0);
    digitalWrite(DR, 0);
    analogWrite (SR, 0);
  }
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
  a = (k + 400)/1000 - 1;
  if (a < 0) { a = 0; }
  //-------------------------------------------------- проехали по линии до какого-то элемента
  if (abs(D) > 100) {  // дуга
    if (D > 0) { A = 2.1;}
    else { A = 2.2; }
  }
  else {       // не дуга
    //process();
    if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
    if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
    if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
    if (analogRead(A4) < 700) { in4 = 1; } else { in4 = 0; }
    if (analogRead(A0) < 800) { in0 = 1; } else { in0 = 0; }
    if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 6;   }
    if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 5;   }
    if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 5.1; }
    if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 5.2; }
    if ((in1 == 0) && (in2 == 0) && (in3 == 0) && (in4 == 0) && (in0 == 0)) { A = 4;   }
    if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 3.2; }
    if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3.1; }
  }
  if (D < 4500) {
    digitalWrite(DL, 1);
    analogWrite (SL, M);
    digitalWrite(DR, 1);
    analogWrite (SR, M);
    delay(400);
    digitalWrite(DL, 0);
    analogWrite (SL, M);
    digitalWrite(DR, 0);
    analogWrite (SR, M);
    delay(20);
    digitalWrite(DL, 0);
    analogWrite (SL, 0);
    digitalWrite(DR, 0);
    analogWrite (SR, 0);
  }
  D = 0;
  //test_d2();
  Serial.println("-----------");
  Serial.println(A);
  Serial.print(a);
  Serial.print(" ");
  Serial.println(k);
  k = 0;
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
  digitalWrite(DL, 1);
  analogWrite (SL, M - e);
  digitalWrite(DR, 1); 
  analogWrite (SR, M + e);
}

void process() {
  /*if (analogRead(A1) < 570) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 750) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 825) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 600) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 725) { in0 = 1; } else { in0 = 0; }*/
  if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 700) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 800) { in0 = 1; } else { in0 = 0; }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 6;   }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 5;   }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 5.1; }
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 5.2; }
  if ((in1 == 0) && (in2 == 0) && (in3 == 0) && (in4 == 0) && (in0 == 0)) { A = 4;   }
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 3.2; }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3.1; }
  //if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 1;   }
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
