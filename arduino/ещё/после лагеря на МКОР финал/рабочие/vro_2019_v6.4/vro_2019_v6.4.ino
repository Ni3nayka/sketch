#define ras 33  // кол-во вершин + 1
#include <Servo.h>
Servo S;
byte dor[ras*4][2] {
  {0, 0},
  {1, 2},
  {2, 1},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
};
char ver[ras][5] { // №, x, y, посещена ли, сколько доехать до неё (mas)
  {0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}, // обозначили стартовую локацию №1
  {2, 0, 0, 0, 0}, // обозначили вторую (переднюю локацию)
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
};
byte pyt[ras];
byte pyt_auto[ras*2];
byte napr = 1;
byte Napr = 1;
#define root 1  // 0  // Serial_vivod
#define ROOT 1
// if (ROOT == 1) { virtual; }
// if (ROOT == 2) { real;    }
#define PWMA 3
#define AIN1 2
#define AIN2 4
#define PWMB 6
#define BIN1 5
#define BIN2 7
#define M      255
int in0, in1, in2, in3, in4;
#define LIN    420 // 620 // время для одной клетки (lin)
#define POV    420 // 500  // время для поворота на 90 градусов
int D = 0;   //для определения дугового движения
int a = 0;   // длинна дороги
int k = 0;   // длинна дороги прямого участка пути
int e = 0;   // ошибка для П регулятора
int min_2 = 600;
int min_3 = 500;
int max_2 = 900;
int max_3 = 900;
int pr1 = 700;
int pr2 = 900;
int pr3 = 900;
int pr4 = 700;
int pr0 = 800;
float A = 0; // какая локация
byte f, i, j, flag, u, ff, uu;
int  x, y, x2, y2, xk, yk, p, w, AA; 
byte left, right, up, down, POVOROT;
byte myt  = 0;
byte newt = 0;
char F = 0;  // для обмена данными между ардуинами/ПК
int x1 = 1;
int y1 = 0;

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
    //while ((digitalRead(10) == 1)) { delay(1); }
    zum();
  while ((digitalRead(10) == 1) && (ROOT == 2)) { delay(1); } delay (500);
  start();
  //navigator(11, 0);
  //kalibrovka(); zum();
  //test_vibros();
}

void loop() {
  bluetooth();
  //process();
  //test_d3();
  //test_d();
}

void test_vibros() {
  lin();
  POVOROT = 1;
  povorot();
  out();
  L();
  lin();
  N();
  linia();
}

void start() {
  zum();
  auto_set();
  scan();
  vibros();
  zum();
}

void kalibrovka() {
  int ppp = 500;
  analogWrite(PWMA, M);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  analogWrite(PWMB, M);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
  delay(ppp*4);
  analogWrite(PWMA, 0);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  analogWrite(PWMB, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
  zum();
  delay(500);
  analogWrite(PWMA, M);
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  analogWrite(PWMB, M);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
  delay(ppp*4);
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
    flag = 0;
    if (F == 'l') {
      linia();
      flag = 2;
    }
    if (F == 'v') {
      lin();
      flag = 2;
    }
    if (F == 'A') {
      auto_set();
      flag = 2;
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
    if (F == 'N') {
      N();
      flag = 1;
    }
    if (F == 'Z') {
      zum();
      flag = 1;
    }
    if (F == 'P') {
      zapros_povorot();
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
    Serial.println();
    /*if (flag == 0) {
      Serial.println("ERROR_COMMAND");
    }*/
  }
}

void zapros_povorot() {
  POVOROT = 0;
  while (POVOROT == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '0') { POVOROT = 0; }
      if (F == '1') { POVOROT = 1; }
      if (F == '2') { POVOROT = 2; }
      if (F == '3') { POVOROT = 3; }
      if (F == '4') { POVOROT = 4; }
      if (F == '5') { POVOROT = 5; }
      if (F == '6') { POVOROT = 6; }
      if (F == '7') { POVOROT = 7; }
      if (F == '8') { POVOROT = 8; }
      if (F == '9') { POVOROT = 9; }
    }
  }
}

void povorot() {
  //zapros();
  if (ROOT == 2) {
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
  }
  while (POVOROT > 0) {
    if (ROOT == 2) { delay(POV); }  
    else { Serial.print("P"); }
    r();
    POVOROT--;
  }
  Serial.println();
  if (ROOT == 2) {
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  }
}

void vivod_n() {
  navigator(2, 16);
  i = 1;
  while ((i < ras) && (ver[i][4] < 101)) {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(int(ver[i][4]));
    i++;
  }
  i = 1;
  Serial.println("-----------------");
  while ((i < ras) && (pyt[i] != 0)) {
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
  i = 1;
  Serial.println();
  Serial.println("-----------------");
  while ((i < ras) && (pyt_auto[i] != 0)) {
    Serial.print(pyt_auto[i]);
    Serial.print(" ");
    i++;
  }
}

void vozvrat() {
  navigator(myt, 1);
  //dvigenie();
  if (napr != 1) {
    
  }
}

void vibros() {
  i = 1; xk = 99;
  while (ver[i][0] != 0) {
    if (ver[i][1] < xk) { xk = ver[i][1]; }
    i++;
  }
  i = 1; yk = 99;
  while (ver[i][0] != 0) {
    if (ver[i][2] < yk) { yk = ver[i][2]; }
    i++;
  }  
  x1 = x1 + xk;
  y1 = y1 + yk;
  //-------------------------
  dvigenie(x1, y1);
  out();
}

void dvigenie(byte nachalo, byte konec) {
  myt = nachalo;
  u = konec;
  navigator(myt, u);
  i = 1;
  while (pyt_auto[i] > 0) {
    //if (!(((pyt_auto[i] == 2) && (A == 2.1)) || ((pyt_auto[i] == 3) && (A == 2.2)))) {
    if (pyt_auto[i] == 1)                 { lin(); }
    if ((pyt_auto[i] == 2) && (A != 2.1)) { L();   }
    if ((pyt_auto[i] == 3) && (A != 2.2)) { R();   }
    if (pyt_auto[i] == 4)                 { N();   }
    i++;
  }
  myt = u;
  x = ver[myt][1];
  y = ver[myt][2];
  napr = Napr;    
  /*i = 1;
        while (pyt_auto[i] != 0) {
          if (pyt_auto[i] == 1) {
            V(); 
            lin(); 
          }
          if ((pyt_auto[i] == 2) && (A != 2.1)) { L(); }
          if ((pyt_auto[i] == 3) && (A != 2.2)) { R(); }
          if (pyt_auto[i] == 4) { N(); }
          i++;
        }
        myt = w;
        napr = Napr;
        ff = 1;
        x = ver[myt][1];
        y = ver[myt][2];*/
}

void auto_set() {
  if (ROOT == 1) {
    napr = 0;
    //Serial.println("napr (auto_set)");
    Serial.println("A");
    while (napr == 0) {
      if (Serial.available() > 0) {
        F = Serial.read();
        if (F == '1') { napr = 1; }  
        if (F == '2') { napr = 2; }
        if (F == '3') { napr = 3; }
        if (F == '4') { napr = 4; }
      }
    }
  }
  else {
    //Serial.print("A: ");
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
        r();
        //if (napr == 4) { napr = 1; }
        //else { napr++; }
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
  }
  Serial.println(napr);
  if (napr == 1) {
    ver[2][1] = 1;
    ver[2][2] = 0;
  }
  if (napr == 2) {
    ver[2][1] = 0;
    ver[2][2] = 1;
  }
  if (napr == 3) {
    ver[2][1] = -1;
    ver[2][2] = 0;
  }
  if (napr == 4) {
    ver[2][1] = 0;
    ver[2][2] = -1;
  }
}

void scan() {
  j = 3; // общий счетчик точек
  i = 1; u = 1; ff = 0;
  x = 0; y = 0; myt = 1;
  while (flag == 0) {
    if (ff == 0) { // не использовалась деикстра
      lin(); // linia();
      while (a > 0) {
        if (napr == 1) { x++; }
        if (napr == 2) { y++; }
        if (napr == 3) { x--; }
        if (napr == 4) { y--; }
        i = 1;
        while ((ver[i][1] != x) || (ver[i][2] != y)) { i++; }
        myt = ver[i][0];
        ver[myt][3] = 1;
        AV();
        a--;
      }
      if (napr == 1) { x++; }
      if (napr == 2) { y++; }
      if (napr == 3) { x--; }
      if (napr == 4) { y--; }
    }
    else {
      ff = 0;
    }
    //---------------------------- обрабатываем ту, до которой доехали
    i = 1;
    while ((ver[i][1] != x) || (ver[i][2] != y)) { i++; }
    myt = ver[i][0];
    ver[myt][3] = 1;
    //newt = 1;
    if ((A == 5.1) || (A == 5.2) || (A == 6) || (A == 1  )            ) { AV(); } 
    if ((A == 2.1) || (A == 3.1) || (A == 5) || (A == 5.1) || (A == 6)) { AL(); }
    if ((A == 2.2) || (A == 3.2) || (A == 5) || (A == 5.2) || (A == 6)) { AR(); }
    if (A == 2.1) { l(); }
    if (A == 2.2) { r(); }
    if (root == 1) { 
      Serial.println(myt);
      Serial.println(napr);
      Serial.println(x);
      Serial.println(y);
      vivod();
    }
    //-------------------------проверка на наличие неразведанных клеток
    flag = 0;
    i = 1; w = 0;
    while ((ver[i][0] != 0) && (i < ras)) {
      if (ver[i][3] == 0) { w++; }
      i++;
    }
    if (w == 0) {
      flag++;
    }
    if (flag == 0) {  // решаем, куда ехать дальше (если есть неразведанные)
      i = 1; u = 0; w = 1;
      while ((i < ras*4) && (dor[i][0] != 0)) {
        if ((dor[i][0] == myt) && (ver[dor[i][1]][1] == x + 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { u++; }
        if ((dor[i][0] == myt) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y + 1) && (ver[dor[i][1]][3] == 0)) { u++; }
        if ((dor[i][0] == myt) && (ver[dor[i][1]][1] == x - 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { u++; }
        if ((dor[i][0] == myt) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y - 1) && (ver[dor[i][1]][3] == 0)) { u++; }
        i++;
      }
      if (u > 0) { // есть неразведанные рядом
        i = 1; u = 1; w = 1; left = 0; right = 0; up = 0; down = 0;
        while ((i < ras*4) && (dor[i][0] != 0)) {
          if ((dor[i][0] == myt) && (napr == 1) && (ver[dor[i][1]][1] == x + 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { up++; }
          if ((dor[i][0] == myt) && (napr == 2) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y + 1) && (ver[dor[i][1]][3] == 0)) { up++; }
          if ((dor[i][0] == myt) && (napr == 3) && (ver[dor[i][1]][1] == x - 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { up++; }
          if ((dor[i][0] == myt) && (napr == 4) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y - 1) && (ver[dor[i][1]][3] == 0)) { up++; }
          //-------
          if ((dor[i][0] == myt) && (napr == 2) && (ver[dor[i][1]][1] == x + 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { left++; }
          if ((dor[i][0] == myt) && (napr == 3) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y + 1) && (ver[dor[i][1]][3] == 0)) { left++; }
          if ((dor[i][0] == myt) && (napr == 4) && (ver[dor[i][1]][1] == x - 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { left++; }
          if ((dor[i][0] == myt) && (napr == 1) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y - 1) && (ver[dor[i][1]][3] == 0)) { left++; }
          //-------
          if ((dor[i][0] == myt) && (napr == 4) && (ver[dor[i][1]][1] == x + 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { right++; }
          if ((dor[i][0] == myt) && (napr == 1) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y + 1) && (ver[dor[i][1]][3] == 0)) { right++; }
          if ((dor[i][0] == myt) && (napr == 2) && (ver[dor[i][1]][1] == x - 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { right++; }
          if ((dor[i][0] == myt) && (napr == 3) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y - 1) && (ver[dor[i][1]][3] == 0)) { right++; }
          //-------
          if ((dor[i][0] == myt) && (napr == 3) && (ver[dor[i][1]][1] == x + 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { down++; }
          if ((dor[i][0] == myt) && (napr == 4) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y + 1) && (ver[dor[i][1]][3] == 0)) { down++; }
          if ((dor[i][0] == myt) && (napr == 1) && (ver[dor[i][1]][1] == x - 1) && (ver[dor[i][1]][2] == y) && (ver[dor[i][1]][3] == 0)) { down++; }
          if ((dor[i][0] == myt) && (napr == 2) && (ver[dor[i][1]][1] == x) && (ver[dor[i][1]][2] == y - 1) && (ver[dor[i][1]][3] == 0)) { down++; }
          i++;
        }
        if (up > 0) { V(); }
        else if (left  > 0) { L(); }
        else if (right > 0) { R(); }
        else { N(); }
      }
      else {  // нет неразведанных рядом
        if (root == 1) { Serial.print("deikstra:"); Serial.println(myt); }
        navigator(myt, 0); //navigator(myt, 0);
        if (root == 1) { 
          vivod();
          vivod2();
        }
        i = 1; u = 101; w = 0;
        while ((i < ras)) {  // находим ближайшую неразведанную точку // 
          while ((ver[i][4] == 0) && (i < ras)) { i++; }
          if ((ver[i][3] == 0) && (ver[i][4] <= u) && (i < ras)) {
            w = i;
            u = ver[i][4];
          }
          i++;
        }
        if (root == 1) { navigator(myt, w); vivod2(); }
        dvigenie(myt, w);
        /*i = 1;
        while (pyt_auto[i] != 0) {
          if (pyt_auto[i] == 1) {
            V(); 
            lin(); 
          }
          if ((pyt_auto[i] == 2) && (A != 2.1)) { L(); }
          if ((pyt_auto[i] == 3) && (A != 2.2)) { R(); }
          if (pyt_auto[i] == 4) { N(); }
          i++;
        }
        myt = w;
        napr = Napr;
        ff = 1;
        x = ver[myt][1];
        y = ver[myt][2];*/
        ff = 1;    // флаг для линии (для последующих циклов)
      }
      if (root == 1) { vivod3(); }
    }
  }
  if (root == 1) { Serial.println("FINISH"); }
  if (root == 1) { vivod(); }
}

void vivod3() {
  Serial.println("******");
  Serial.println(myt);
  Serial.println(napr);
  Serial.println(x);
  Serial.println(y);
  Serial.println("******");
}

void vivod2() {
  Serial.println("------------");
  i = 1;
  while ((i < ras) && (ver[i][0] > 0)) { // путь по точкам
    Serial.println(int(ver[i][4]));
    i++;
  }
  Serial.println("------------");
  i = 1;
  while ((i < ras) && (pyt[i] > 0)) { // путь по точкам
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
  Serial.println("------------");
  i = 1;
  while ((i < ras) && (pyt_auto[i] > 0)) { // путь по точкам
    Serial.print(pyt_auto[i]);
    Serial.print(" ");
    i++;
  }
  Serial.println("------------");
}

void vivod() {
  Serial.println("---------------");
  
  //Serial.println(napr);
  //Serial.println("---");
  i = 1; u = 0;
  while ((i < ras*4) && (dor[i][u] != 0)) {
    while (u < 2) {
      Serial.print(dor[i][u]);
      Serial.print(" ");
      u++;
    }
    u = 0;
    Serial.println();
    i++;
  }
  i = 1;
  Serial.println("---------------");
  while ((ver[i][0] > 0) && (i < ras)) { // 
    Serial.print((int)ver[i][0]);
    Serial.print(" ");
    Serial.print((int)ver[i][1]);
    Serial.print(" ");
    Serial.print((int)ver[i][2]);
    Serial.print(" ");
    Serial.println((int)ver[i][3]);
    Serial.print(" ");
    i++;
  }
  Serial.println("---------------");
}

//-----------------------------------------

void otklick() {
  F = 0;
  while (F == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F != 'O') { F = 0; }
    }
  }
}

void N() {
  //i = napr;
  if ((A == 5) || (A == 6)) {  // N
    if (root == 1) { Serial.println("N(N)"); }
    L(); L(); 
  }
  else if ((A == 2.2) || (A == 3.2) || (A == 5.2) || (A == 4) || (A == 1)) {  // L
    if (root == 1) { Serial.println("N(L)"); }
    L(); l();
  }
  else if ((A == 2.1) || (A == 3.1) || (A == 5.1)) {  // R
    if (root == 1) { Serial.println("N(R)"); }
    R(); r();
  }
  //Serial.println();
  //napr = i;
  //n();
}

void V() {
  //Serial.println("V");
}

void L() {
  l();
  if (root == 1) { Serial.println("L"); }
  if (ROOT == 2) {
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
}

void R() {
  r();
  if (root == 1) { Serial.println("R"); }
  if (ROOT == 2) {
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
}

void zum() {
  if (root == 1) { Serial.println("zum"); }
  if (ROOT == 2) {
    digitalWrite(8, 1);
    delay(100);
    digitalWrite(8, 0);
    delay(100);
    digitalWrite(8, 1);
    delay(100);
    digitalWrite(8, 0);
    delay(100);
  }
}

void out() {
  if (root == 1) { Serial.println("Servo_out"); }
  if (ROOT == 2) {
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 0);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
    delay(POV/4);
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
    delay(100);
    S.write(100);
    delay(500);
    S.write(25);
    delay(500);
    analogWrite(PWMA, M);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    analogWrite(PWMB, M);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);
    delay(POV/4);
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
    delay(100);
  }
}

void n() {
  l();
  l();
}

void l() {
  if (napr == 1) { napr = 4; }
  else { napr--; }
}

void r() {
  if (napr == 4) { napr = 1; }
  else { napr++; }
}

//-----------------------------------------

void lin() { // линия до центра клетки
  if (ROOT == 1) {
    Serial.println("lin");
    A = 0;
    while (A == 0) {
      if (Serial.available() > 0) {
        F = Serial.read();
        if (F == '0') { A = 1  ; }
        if (F == '1') { A = 2.1; }
        if (F == '2') { A = 2.2; }
        if (F == '3') { A = 3.1; }
        if (F == '4') { A = 3.2; }
        if (F == '5') { A = 5;   }
        if (F == '6') { A = 5.1; }
        if (F == '7') { A = 5.2; }
        if (F == '8') { A = 6;   }
        if (F == '9') { A = 4;   }
      }
    }
    if (root == 1) { Serial.println(A); }
    a = 0;
    /*a = 10;
    while (a == 10) {
      if (Serial.available() > 0) {
        F = Serial.read();
        if (F == '0') { a = 0; }
        if (F == '1') { a = 1; }
        if (F == '2') { a = 2; }
        if (F == '3') { a = 3; }
        if (F == '4') { a = 4; }
        if (F == '5') { a = 5; }
        if (F == '6') { a = 6; }
        if (F == '7') { a = 7; }
        if (F == '8') { a = 8; }
        if (F == '9') { a = 9; }
      }
    }*/
  }
  else {
    a = 0;
    D = 0;
    dat();
    while ((in1 > pr1) && (in4 > pr4) && ((in2 < pr2) || (in3 < pr3)) && (k < LIN))  { // (abs(D) < 4500) && 
      linia_d();
      //if (abs(e) >= M*0.9) { D = D + e; }
      if (abs(e) < 5) { D = 0; }
      k++;
      //delay(1);
    }
    if (abs(D) > 4500) {  // дуга
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else {
      process();
    }
    a = 0;
    //-------------------------------------------------- проехали по линии до какого-то элемента
    if ((D < 4500) && (k < LIN) && (A != 4)) {
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 0);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 0);
      //delay(250);  // 250
      delay(LIN*0.4);
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
    /*convecter();
    Serial.println(AA);*/
    Serial.print("(A:");
    Serial.print(A);
    Serial.print(" a:");
    Serial.print(a); 
    Serial.print(" k:");
    Serial.print(k);
    Serial.println(")");
    D = 0;
    k = 0;
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  }
}

void linia() {
  if (ROOT == 1) {
    Serial.println("linia");
    A = 0;
    while (A == 0) {
      if (Serial.available() > 0) {
        F = Serial.read();
        if (F == '0') { A = 1;   }
        if (F == '1') { A = 2.1; }
        if (F == '2') { A = 2.2; }
        if (F == '3') { A = 3.1; }
        if (F == '4') { A = 3.2; }
        if (F == '5') { A = 5;   }
        if (F == '6') { A = 5.1; }
        if (F == '7') { A = 5.2; }
        if (F == '8') { A = 6;   }
        if (F == '9') { A = 4;   }
      }
    }
    //a = 0;
    a = 10;
    while (a == 10) {
      if (Serial.available() > 0) {
        F = Serial.read();
        if (F == '0') { a = 0; }
        if (F == '1') { a = 1; }
        if (F == '2') { a = 2; }
        if (F == '3') { a = 3; }
        if (F == '4') { a = 4; }
        if (F == '5') { a = 5; }
        if (F == '6') { a = 6; }
        if (F == '7') { a = 7; }
        if (F == '8') { a = 8; }
        if (F == '9') { a = 9; }
      }
    }
  }
  else {
    a = 0;
    D = 0;
    dat();
    while ((in1 > pr1) && (in4 > pr4) && ((in2 < pr2) || (in3 < pr3)))  {  // (abs(D) < 4500) && 
      linia_d();
      //if (abs(e) >= M*0.9) { D = D + e; }
      if (abs(e) < 5) { D = 0; }
      k++;
      //delay(1);
    }
    if (abs(D) > 4500) {  // дуга
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else { 
      process();
    }
    //a = k/(LIN - 200) - 1;
    a = k/(LIN*4/5) - 1;
    if (a < 0) { a = 0; }
    //-------------------------------------------------- проехали по линии до какого-то элемента
    //Serial.println(k);
    if ((D < 4500) && (A != 4)) {
      analogWrite(PWMA, M);
      digitalWrite(AIN1, 1);
      digitalWrite(AIN2, 0);
      analogWrite(PWMB, M);
      digitalWrite(BIN1, 1);
      digitalWrite(BIN2, 0);
      //delay(250);  // 250
      delay(LIN*0.4);
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
    /*convecter();
    Serial.println(AA);
    Serial.println(a);*/
    Serial.print("(A:");
    Serial.print(A);
    Serial.print(" a:");
    Serial.print(a); 
    Serial.print(" k:");
    Serial.print(k);
    Serial.println(")");
    k = 0;
    analogWrite(PWMA, 0);
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
    analogWrite(PWMB, 0);
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  }
}

void convecter() {
  if (A == 1  ) { AA = 0; }
  if (A == 2.1) { AA = 1; }
  if (A == 2.2) { AA = 2; }
  if (A == 3.1) { AA = 3; }
  if (A == 3.2) { AA = 4; }
  if (A == 5  ) { AA = 5; }
  if (A == 5.1) { AA = 6; }
  if (A == 5.2) { AA = 7; }
  if (A == 6  ) { AA = 8; }
  if (A == 4  ) { AA = 9; }
}

void linia_d() {
  dat();
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
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
}

void dat() {
  in1 = 0;
  in2 = 0;
  in3 = 0;
  in4 = 0;
  in0 = 0;
  i = 1;
  while (i <= 3) {
    in1 = analogRead(A1) + in1;
    in2 = analogRead(A2) + in2;
    in3 = analogRead(A3) + in3;
    in4 = analogRead(A4) + in4;
    in0 = analogRead(A0) + in0;
    i++;
  }
  in1 = in1/3;
  in2 = in2/3;
  in3 = in3/3;
  in4 = in4/3;
  in0 = in0/3;
}

void process() {
  A = 0;
  delay(50);
  /*if (analogRead(A1) < 800) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < 800) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < 700) { in0 = 1; } else { in0 = 0; }*/
  if (analogRead(A1) < pr1) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < pr2) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < pr3) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < pr4) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < pr0) { in0 = 1; } else { in0 = 0; }
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
  if (analogRead(A1) < pr1) { in1 = 1; } else { in1 = 0; }
  if (analogRead(A2) < pr2) { in2 = 1; } else { in2 = 0; }
  if (analogRead(A3) < pr3) { in3 = 1; } else { in3 = 0; }
  if (analogRead(A4) < pr4) { in4 = 1; } else { in4 = 0; }
  if (analogRead(A0) < pr0) { in0 = 1; } else { in0 = 0; }
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

//--------------------------------------------------------------

void AV() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (ver[newt][3] == 0) {
        i = 1;
        while (dor[i][0] != 0) { i++; }
        dor[i][0] = newt;
        dor[i][1] = myt;
        i++;
        dor[i][0] = myt;
        dor[i][1] = newt;
      }
      newt = 1;
}

void AL() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (ver[newt][3] == 0) {
        i = 1;
        while (dor[i][0] != 0) { i++; }
        dor[i][0] = newt;
        dor[i][1] = myt;
        i++;
        dor[i][0] = myt;
        dor[i][1] = newt;
      }
      newt = 1;
}

void AR() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
          newt = j;
          ver[j][0] = j;
          j++;
        }
      }
      if (ver[newt][3] == 0) {
        i = 1;
        while (dor[i][0] != 0) { i++; }
        dor[i][0] = newt;
        dor[i][1] = myt;
        i++;
        dor[i][0] = myt;
        dor[i][1] = newt;
      }
      newt = 1;
}

//------------------------------- navigator 5.1 

void navigator(byte t_start, byte t_finish) {
  byte t_nast = 1;
  byte ii = 1;
  byte iii = 1;
  byte gg = 1;
  byte aa = 1;
  byte t1 = 1;
  byte t2 = 1; 
  while (ii < ras) {
    ver[ii][4] = 101;
    ii++;
  }
  ii = 1;
  ver[t_start][4] = 0;
  gg = 1;
  while (gg > 0) {
    t_nast = 1;
    ii = 1;
    gg = 0;
    while (t_nast < ras) {
      while ((ii < ras*4) && (dor[ii][0] != t_nast)) { ii++; }
      if (ii < ras*4) {
        if (ver[t_nast][4] + 1 < ver[dor[ii][1]][4]) {
          ver[dor[ii][1]][4] = ver[t_nast][4] + 1;
          gg++;
        }
        ii++;
      }
      else {
        ii = 1;
        t_nast++;
      }
    }
  }
  //-------------------------------------------
  if ((t_finish > 0) && (ver[t_finish][4] < 101)) {
    //Serial.println("iiiiiiiiiiiiii");
    ii = 1;
    while (pyt[ii] != 0) {
      pyt[ii] = 0;
      ii++;
    }
    t_nast = t_finish;
    ii = 1;
    pyt[1] = t_finish;
    iii = 2;
    //Serial.println("iiiiiiiiiiiiii");
    /*Serial.println(t_nast);
    Serial.println(t_start);
    Serial.println(t_finish);*/
    while (t_nast != t_start) {
      while ((ii < ras*4) && (dor[ii][0] != t_nast) && (dor[ii][0] != 0)) { ii++; }
      if ((ver[dor[ii][1]][4] + 1 == ver[t_nast][4]) && (dor[ii][0] != 0)) {
        pyt[iii] = dor[ii][1];
        iii++;
        t_nast = dor[ii][1];
        //ii++;
      }
      //else {
        ii++;
      //}
      if (dor[ii][0] == 0) {
        ii = 1;
      }
    }
    //Serial.println("iiiiiiiiiiiiii_1");
    //------------------------------------------
    //gg = iii - 1;
    //ii = 1;
    ii = 1; gg = 1;
    while (pyt[gg] != 0) {
      gg++;
    }
    gg--;
    if (gg % 2 == 0) {
      while ((gg - ii) >= 1) {
        t_nast = pyt[ii];
        pyt[ii] = pyt[gg];
        pyt[gg] = t_nast;
        ii++;
        gg--;
      }
    }
    else {
      while ((gg - ii) >= 2) {
        t_nast = pyt[ii];
        pyt[ii] = pyt[gg];
        pyt[gg] = t_nast;
        ii++;
        gg--;
      }
    }
    //Serial.println("iiiiiiiiiiiiii_2");
    //------------------------------ mypyt(); 
    ii = 1;
    while (pyt_auto[ii] != 0) {
      pyt_auto[ii] = 0;
      ii++;
    }
    ii = 1; gg = 1; aa = 2;
    t_nast = t_start;
    Napr = napr;
    //Serial.println("iiiiiiiiiiiiii_3");
    while (t_nast != t_finish) {                           
      if (((Napr == 1) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 2; 
        ii++; 
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
      }
      if (((Napr == 1) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 3; 
        ii++; 
        if (Napr == 4) { Napr = 1; }
        else { Napr++; }
      }
      if (((Napr == 1) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 4; 
        ii++; 
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
      }                             
      pyt_auto[ii] = 1; ii++;
      t_nast = pyt[aa]; aa++;  // если нет прямых без перекрестков
    }
  }
}



