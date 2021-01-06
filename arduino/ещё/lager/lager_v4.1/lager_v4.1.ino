#define SR     11
#define DR     13
#define SL     10
#define DL     12

byte dor[209][2] { // из, в
  {0,0},
  {1,2},
  {2,1},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
};

int  ver[33][4] { // №, x, y, посещена ли
  {0, 0, 0, 0},
  {1, 0, 0, 0}, // обозначили стартовую локацию №1
  {2, 1, 0, 0}, // обозначили вторую (переднюю локацию)
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
};

float M = 50;
float p = 0;
float A = 0; // какая локация
int   a, b, c, d, e, f, g, h, i, j, x, y, z, in0, in1, in2, in3, in4; 
int n = 1;   // направление
long int k = 0;

void setup() {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (4 , OUTPUT);
  pinMode (DR, OUTPUT);
  pinMode (DL, OUTPUT);
  i = 0;
  //digitalWrite(4, 1); delay(10); digitalWrite(4, 0);
  //zum();
  while (digitalRead(2) == 1) { delay(10); }
  //zum();
  delay(500);
  start();
  //linia();
  //linia(); V(); linia(); R(); linia(); R(); linia(); 
  //linia(); R();
  //L(); linia(); L(); linia(); R(); linia(); L(); linia(); R();
}

void start() {
  int napr = 1;
  j        = 3;  // общий счетчик точек
  c        = 3;  // счетчик для dor[][]
  int a2   = 0;
  int myt  = 0;
  int newt = 0;
  x = 0; y = 0;
  while (f == 0) {//---------------------------------------------
    linia();      // проехал до локации
    a2 = a;
    /*if (a > 0) {  //учитываем прямые участки пути
      while (a > 0) {
        i = 0;  
        if (napr == 1) {
          x++;
          ver[j-1][0] = j;
        }
        if (napr == 2) { y++; }
        if (napr == 3) { x--; }
        if (napr == 4) { y--; }
        a--;
      }
    }*/
    if (napr == 1) { x++; }  // определяем координату
    if (napr == 2) { y++; }
    if (napr == 3) { x--; }
    if (napr == 4) { y--; }
    i = 1;
    myt = 1;
    while (!((ver[myt][1] == x) && (ver[myt][2] == y))) { myt++; } // ищем точку с такой-же координатой
    ver[myt][3] = 1;   // отмечаем, что были в ней
    // определил соседние локации
    Serial.println(A);
    //myt = 1; while ((!((ver[myt][1] == x) && (ver[myt][2] == y))) && (myt < 35)) { myt++; } // определить настоящую координату (myt)
    if (A == 3.1) {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y - 1;
          dor[c][0] = myt;
          dor[c][1] = j;
          c++;
          dor[c][0] = j;
          dor[c][1] = myt;
          c++;
          j++;
        }
        else {         // была такая точка раньше
          dor[c][0] = myt;
          dor[c][1] = newt;
          c++;
          dor[c][0] = newt;
          dor[c][1] = myt;
          c++;
        }
      }
      if (napr == 2) {
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x + 1;
          ver[j][2] = y;
          dor[c][0] = myt;
          dor[c][1] = j;
          c++;
          dor[c][0] = j;
          dor[c][1] = myt;
          c++;
          j++;
        }
        else {         // была такая точка раньше
          dor[c][0] = myt;
          dor[c][1] = newt;
          c++;
          dor[c][0] = newt;
          dor[c][1] = myt;
          c++;
        }
      }
      if (napr == 3) {
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y + 1;
          dor[c][0] = myt;
          dor[c][1] = j;
          c++;
          dor[c][0] = j;
          dor[c][1] = myt;
          c++;
          j++;
        }
        else {         // была такая точка раньше
          dor[c][0] = myt;
          dor[c][1] = newt;
          c++;
          dor[c][0] = newt;
          dor[c][1] = myt;
          c++;
        }
      }
      if (napr == 4) {
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x - 1;
          ver[j][2] = y;
          dor[c][0] = myt;
          dor[c][1] = j;
          c++;
          dor[c][0] = j;
          dor[c][1] = myt;
          c++;
          j++;
        }
        else {         // была такая точка раньше
          dor[c][0] = myt;
          dor[c][1] = newt;
          c++;
          dor[c][0] = newt;
          dor[c][1] = myt;
          c++;
        }
      }
    }
    // проверить на "все ли обследованны"
    // определить, куда ехать дальше если !(f == 0) и при надобности повернуть
    f++; 
  }
  i = 1;
  while (ver[i][0] > 0) {
    Serial.print(ver[i][0]);
    Serial.print(" ");
    Serial.print(ver[i][1]);
    Serial.print(" ");
    Serial.print(ver[i][2]);
    Serial.print(" ");
    Serial.println(ver[i][3]);
    Serial.print(" ");
    i++;
    delay(100);
  }
  Serial.println("---------------");
  i = 1;
  while (dor[i][0] > 0) {
    Serial.print(dor[i][0]);
    Serial.print(" ");
    Serial.println(dor[i][1]);
    i++;
    delay(100);
  }
}

void loop() {
  //process(); test_d2();
  //test_d();
  //test_e();
  //linia();
}

void linia() {
  a = 0;
  while ((((analogRead(A1) > 350) && (analogRead(A4) > 350))) && (((analogRead(A2) < 850) || (analogRead(A3) < 850))) && (analogRead(A0) < 800)) {
    e = (map((analogRead(A3)), 729, 985, 0, M) - map((analogRead(A2)), 650, 972, 0, M));
    digitalWrite(DL, 1);
    analogWrite (SL, M - e);
    digitalWrite(DR, 1);
    analogWrite (SR, M + e);
    k++;
    delay(1);
  }
  digitalWrite(DL, 0);
  analogWrite (SL, 50);
  digitalWrite(DR, 0);
  analogWrite (SR, 50);
  delay(10);
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
  a = (k + 400)/1000 - 1;
  if (a < 0) { a = 0; }
  //Serial.println("-----------");
  //Serial.println(a);
  k = 0;
  //-------------------------------------------------- проехали по линии до какого-то элемента
  process();
  //test_d2();
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
  if ((in1 == 0) && (in4 == 0) && (in0 == 0))                             { A = 4;   }
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 3.2; }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3.1; }
  //if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 1;   }
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

void V() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  while ((analogRead(A1) < 570) || (analogRead(A3) < 825)) {} 
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void L() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  delay(650);
  digitalWrite(DL, 0);
  analogWrite (SL, 60);
  digitalWrite(DR, 1);
  analogWrite (SR, 60);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void R() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  delay(650);
  digitalWrite(DL, 1);
  analogWrite (SL, 60);
  digitalWrite(DR, 0);
  analogWrite (SR, 60);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
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
  e = (map((analogRead(A3)), 729, 985, 0, 50) - map((analogRead(A2)), 650, 972, 0, 50));
  Serial.println(e);
  delay(100);
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


