#define ras 33  // кол-во вершин + 1
/*byte dor[ras*4][2] {
  {0, 0},
  {1, 2 },
  {2, 1 },
  {3, 2 },
  {2, 3 },
  {4, 2 },
  {2, 4 },
  {5, 3 },
  {3, 5 },
  {6, 5 },
  {5, 6 },
  {7, 6 },
  {6, 7 },
  {8, 6 },
  {6, 8 },
  {9, 7 },
  {7, 9 },
  {1, 7 },
  {7, 1 },
  {10, 7 },
  {7, 10 },
  {11, 9 },
  {9, 11 },
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
  {1, 0, 0, 0, 0},
  {2, 1, 0, 1, 0},
  {3, 2, 0, 1, 0},
  {4, 1, 1, 0, 0},
  {5, 2, -1, 1, 0},
  {6, 1, -1, 1, 0},
  {7, 0, -1, 1, 0},
  {8, 1, -2, 0, 0},
  {9, -1, -1, 1, 0},
  {10, 0, -2, 0, 0},
  {11, -1, -2, 1, 0},
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
};*/
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
#define ROOT 1
// if (ROOT == 1) { virtual; }
// if (ROOT == 2) { real;    }
#define SR     11
#define DR     13
#define SL     10
#define DL     12
#define M      125
int in0, in1, in2, in3, in4;
#define LIN    1100 // время для одной клетки (lin)
int D = 0;   //для определения дугового движения
int a = 0;   // длинна дороги
int k = 0;   // длинна дороги прямого участка пути
int e = 0;   // ошибка для П регулятора
int min_2 = 600;
int min_3 = 500;
int max_2 = 900;
int max_3 = 900;
float A = 0; // какая локация
byte f, i, j, flag, u, ff, uu;
int  x, y, x2, y2, xk, yk, p, w; 
byte left, right, up, down;
byte myt  = 0;
byte newt = 0;
char F = 0;  // для обмена данными между ардуинами/ПК

//int x1 = 2;
//int y1 = 2;

/* arxiv:
 *  Y - да, все ОК
 *  E - ошибка
 *  S - старт
 *  K - нажали на кнопку
 *  O - конец, задание выполнено
 *  вывод в linia (SoftSerial): A a
 */

/*
byte dor[ras*4][2] {  // TEST MAP
  {0, 0},
  {1, 5},
  {5, 1},
  {5, 6},
  {5, 9},
  {2, 6},
  {3, 7},
  {3, 4},
  {4, 3},
  {6, 2},
  {6, 7},
  {6, 5},
  {7, 3},
  {7, 8},
  {8, 7},
  {8, 12},
  {9, 5},
  {9, 13},
  {10, 11},
  {10, 14},
  {11, 10},
  {11, 12},
  {12, 11},
  {12, 8},
  {13, 9},
  {13, 14},
  {14, 13},
  {14, 10},
  {14, 15},
  {15, 14},
  {15, 16},
  {16, 15},
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
  {2, 1, 0, 0, 0}, // обозначили вторую (переднюю локацию)
  {3, 2, 0, 0, 0},
  {4, 3, 0, 0, 0},
  {5, 0, 1, 0, 0},
  {6, 1, 1, 0, 0},
  {7, 2, 1, 0, 0},
  {8, 3, 1, 0, 0},
  {9, 0, 2, 0, 0},
  {10, 1, 2, 0, 0},
  {11, 2, 2, 0, 0},
  {12, 3, 2, 0, 0},
  {13, 0, 3, 0, 0},
  {14, 1, 3, 0, 0},
  {15, 2, 3, 0, 0},
  {16, 3, 3, 0, 0},
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
*/

void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  while ((digitalRead(2) == 1) && (ROOT == 2)) { delay(1); }
  //hello();
  //knopka_start();
  auto_set();
  scan();
  /*navigator(11, 0);
  vivod2();
  vivod();
  navigator(11, 1);
  vivod2();
  vivod();*/
  //vibros();
  //vozvrat();
  //vivod_n();
}

void loop() {
  
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
  dvigenie();
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
  
  //-------------------------
  navigator(myt, 0);
  i = 1; a = 99; u = 0;
  while (i < 33) {
    if ((dor[i][i] < a) && (ver[i][3] == 0)) {
      a = dor[i][i];
      u = i;
    }
    i++;
  }
  
}

void dvigenie() {
  navigator(myt, u);
  myt = u;
  i = 1;
  while (pyt_auto[i] > 0) {
    if (!(((pyt_auto[i] == 2) && (A == 2.1)) || ((pyt_auto[i] == 3) && (A == 2.2)))) {
      if (pyt_auto[i] == 1) { V(); linia(); }
      if (pyt_auto[i] == 2) { L();          }
      if (pyt_auto[i] == 3) { R();          }
      if (pyt_auto[i] == 4) { N();          }
    }
    i++;
  }
  x = ver[myt][1];
  y = ver[myt][2];
  napr = Napr;    
}

void auto_set() {
  if (ROOT == 1) {
    napr = 0;
    Serial.println("napr (auto_set)");
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
    napr = 1;
    if ((analogRead(A2) > 700) && (analogRead(A3) > 700)) {
      k = 0;
      digitalWrite(DL, 0);
      analogWrite (SL, M);
      digitalWrite(DR, 1);
      analogWrite (SR, M);
      while (analogRead(A0) <= 725) { k++; delay(1); }
      while (analogRead(A0) >= 725) { k++; delay(1); }
      k = k/900;    //  подогнать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      while (k > 0) {
        r();
        k--;
      }
      digitalWrite(DL, 1);
      analogWrite (SL, 0);
      digitalWrite(DR, 1);
      analogWrite (SR, 0);
      k = 0;
    }
  }
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
      linia();
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
    if ((A == 5.1) || (A == 5.2) || (A == 6)) { AV(); } 
    if ((A == 2.1) || (A == 3.1) || (A == 5) || (A == 5.1) || (A == 6)) { AL(); }
    if ((A == 2.2) || (A == 3.2) || (A == 5) || (A == 5.2) || (A == 6)) { AR(); }
    if (A == 2.1) { l(); }
    if (A == 2.2) { r(); }
    /*Serial.println(myt);
    Serial.println(napr);
    Serial.println(x);
    Serial.println(y);
    vivod();*/
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
        //Serial.print("deikstra:"); Serial.println(myt);
        navigator(myt, 0); //navigator(myt, 0);
        //vivod();
        //vivod2();
        i = 1; u = 101; w = 0;
        while ((i < ras)) {  // находим ближайшую неразведанную точку // 
          while ((ver[i][4] == 0) && (i < ras)) { i++; }
          if ((ver[i][3] == 0) && (ver[i][4] < u) && (i < ras)) {
            w = i;
            u = ver[i][4];
          }
          i++;
        }
        navigator(myt, w);
        //vivod2();
        i = 1;
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
        y = ver[myt][2];
      }
      //vivod3();
    }
  }
  Serial.println("FINISH");
  vivod();
}

void scan1() {
  j = 3;  // общий счетчик точек
  x = 0; y = 0; // наст. коорд.
  //napr = 1;
  u = 1;
  newt = 1;
  ff = 0;
  while (f == 0) {//---------------------------------------------
    if (ff == 0) { 
    linia();       // проехал до локации
    //ff = 0;
    //a2 = a;
    while (a > 0) {  //учитываем прямые участки пути
      if (napr == 1) { x++; }  // определяем координату
      if (napr == 2) { y++; }
      if (napr == 3) { x--; }
      if (napr == 4) { y--; }
      myt = 1;
      while (!((ver[myt][1] == x) && (ver[myt][2] == y))) { myt++; } // ищем точку с такой-же координатой
      ver[myt][3] = 1;   // отмечаем, что были в ней
      AV();
      a--;
    }
    if (napr == 1) { x++; }  // определяем координату
    if (napr == 2) { y++; }
    if (napr == 3) { x--; }
    if (napr == 4) { y--; }
    if (A == 2.1) { l(); }
    if (A == 2.2) { r(); }
    myt = 1;
    while (!((ver[myt][1] == x) && (ver[myt][2] == y))) { myt++; } // ищем точку с такой-же координатой
    } 
    ff = 0;
    //--------------------------------------------
    ver[myt][3] = 1;   // отмечаем, что были в ней
    // определил соседние локации
    //Serial.println(A);
    if (A == 2.1) { AV();             }
    if (A == 2.2) { AV();             }
    if (A == 3.1) { AL();             }
    if (A == 3.2) { AR();             }
    if (A == 5  ) { AR(); AL();       }
    if (A == 5.1) { AL(); AV();       }
    if (A == 5.2) { AR(); AV();       }
    if (A == 6  ) { AL(); AR(); AV(); }
    // проверить на "все ли обследованны"
    i = 1;
    while (ver[i][0] > 0) {
      if (ver[i][3] == 0) { f++; }
      i++;
    }
    if (f > 0) { f = 0; }
    else       { f = 1; } 
    i = 1;
    
    // определить, куда ехать дальше если !(f == 0) и при надобности повернуть
    //f++;
    if (f == 0) {
      // проверка: есть ли рядом неразведанные
      flag = 0;
      i = 1;
      while ((i < 34) && (ver[i][0] > 0)) {
        p = 1;
        while ((dor[0][p] != myt) && (dor[1][p] != i) && (p < ras*4) && (dor[0][p] != 0)) { p++; }
        if ((ver[i][3] == 0) && (ver[i][0] > 0) && (p < ras*4) && (myt != i)) {
          if      (((napr == 1) && (ver[i][1] == x + 1) && (ver[i][2] == y)) || ((napr == 2) && (ver[i][1] == x) && (ver[i][2] == y + 1)) || ((napr == 3) && (ver[i][1] == x - 1) && (ver[i][2] == y)) || ((napr == 4) && (ver[i][1] == x) && (ver[i][2] == y - 1))) { up++;    }      
          else if (((napr == 1) && (ver[i][1] == x) && (ver[i][2] == y - 1)) || ((napr == 2) && (ver[i][1] == x + 1) && (ver[i][2] == y)) || ((napr == 3) && (ver[i][1] == x) && (ver[i][2] == y + 1)) || ((napr == 4) && (ver[i][1] == x - 1) && (ver[i][2] == y))) { left++;  }
          else if (((napr == 1) && (ver[i][1] == x) && (ver[i][2] == y + 1)) || ((napr == 2) && (ver[i][1] == x - 1) && (ver[i][2] == y)) || ((napr == 3) && (ver[i][1] == x) && (ver[i][2] == y - 1)) || ((napr == 4) && (ver[i][1] == x + 1) && (ver[i][2] == y))) { right++; }
        }
        i++;
      }
      i = 1;
      if ((up > 0) || (left > 0) || (right > 0)) {  // есть рядом неразведанные
        /*Serial.print("mozg: x:");
        Serial.print(x);
        Serial.print(" y:");
        Serial.print(y);
        Serial.print(" napr:");
        Serial.println(napr);*/
        if (up > 0) { V(); }
        else if (left > 0) { L(); }
        else { R(); }
      }
      else { // нет рядом неразведанных (они далеко)
        //--------------------------------------------------  дописать
        navigator(myt, 0);
        i = 1; a = 99; u = 0;
        while (i < 33) {
          if ((ver[i][4] < a) && (ver[i][3] == 0)) {
            a = ver[i][4];
            u = i;
          }
          i++;
        }
        navigator(myt, u);
        //vivod2();
        myt = u;
        //vivod();
        //vivod3();
        i = 1;
        left = 0;
        right = 0;
        /*Serial.print("navigator: x:");
        Serial.print(x);
        Serial.print(" y:");
        Serial.print(y);
        Serial.print(" napr:");
        Serial.println(napr);*/
        while (pyt_auto[i] > 0) {
          if (!(((pyt_auto[i] == 2) && (A == 2.1)) || ((pyt_auto[i] == 3) && (A == 2.2)))) {
            if (pyt_auto[i] == 1) { V(); linia(); }
            if (pyt_auto[i] == 2) { L();          }
            if (pyt_auto[i] == 3) { R();          }
            if (pyt_auto[i] == 4) { N();          }
          }
          /*else {
            if ((pyt_auto[i] == 2) && (A == 2.1)) { left++; }
            else { right++; }
          }*/
          i++;
        }
        x = ver[myt][1];
        y = ver[myt][2];
        napr = Napr;
        //u = 1;
        ff++;
      }
      up = 0;
      left = 0;
      right = 0;
      //f = 0;
    }
    //vivod();
  }
  vivod();
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

void V() {
  if (ROOT == 1) {
    Serial.println("V");
  }
  else {
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
}

void N() {
  if (ROOT == 1) {
    if ((A == 5) || (A == 6)) {
      Serial.println("N(N)"); 
    }
    else if ((A == 2.2) || (A == 3.2) || (A == 5.2) || (A == 4)) {
      Serial.println("N(L)");
    }
    else if ((A == 2.1) || (A == 3.1) || (A == 5.1)) {
      Serial.println("N(R)");
    }
  }
  else {
    if ((A == 5) || (A == 6)) {  // N
      L(); L(); 
    }
    else if ((A == 2.2) || (A == 3.2) || (A == 5.2) || (A == 4)) {  // L
      L();
    }
    else if ((A == 2.1) || (A == 3.1) || (A == 5.1)) {  // R
      R();
    }
  }
  n();
}

void L() {
  if (ROOT == 1) {
    Serial.println("L");
  }
  else {
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
  l();
}

void R() {
  if (ROOT == 1) {
    Serial.println("R");
  }
  else {
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
  r();
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

void zum() {
  if (ROOT == 1) {
    Serial.println("Z");
  }
  else {
    digitalWrite(4, 1);
    delay(100);
    digitalWrite(4, 0);
    delay(100);
    digitalWrite(4, 1);
    delay(100);
    digitalWrite(4, 0);
    delay(100);
  }
}

//-----------------------------------------

void lin() { // линия до центра клетки
  if (ROOT == 1) {
    Serial.println("lin");
    A = 0;
    while (A == 0) {
      if (Serial.available() > 0) {
        F = Serial.read();
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
    while ((abs(D) < 4500) && (analogRead(A1) > 350) && (analogRead(A4) > 350) && ((analogRead(A2) < 850) || (analogRead(A3) < 850)) && (k < LIN))  {
      linia_d();
      if (abs(e) >= M*0.9) { D = D + e; }
      if (abs(e) < 5) { D = 0; }
      k++;
      delay(1);
    }
    if ((D < 4500) && (k < LIN)) {
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
    //a = (k + 400)/1000 - 1;
    a = 0;
    //if (a < 0) { a = 0; }
    //-------------------------------------------------- проехали по линии до какого-то элемента
    if (abs(D) > 100) {  // дуга
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else {       // не дуга
      process();
      /*if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
      if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
      if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
      if (analogRead(A4) < 700) { in4 = 1; } else { in4 = 0; }
      if (analogRead(A0) < 800) { in0 = 1; } else { in0 = 0; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 8; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 5; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 6; }
      if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 7; }
      if ((in1 == 0) && (in2 == 0) && (in3 == 0) && (in4 == 0) && (in0 == 0)) { A = 9; }
      if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 4; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3; }*/
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
    Serial.print("(A:");
    Serial.print(A); 
    Serial.print(" a:");
    Serial.print(a); 
    Serial.print(" k:");
    Serial.print(k);
    Serial.println(")");
    /*Serial.print("(");
    Serial.print(A+" ");
    Serial.print(a+" ");
    //Serial.print(" ");
    Serial.print(k);
    Serial.println(")");*/
    k = 0;
  }
}

void linia() {
  if (ROOT == 1) {
    Serial.println("linia");
    A = 0;
    while (A == 0) {
      if (Serial.available() > 0) {
        F = Serial.read();
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
      if (D > 0) { A = 2.1; }
      else { A = 2.2; }
    }
    else {       // не дуга
      process();
      /*if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
      if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
      if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
      if (analogRead(A4) < 700) { in4 = 1; } else { in4 = 0; }
      if (analogRead(A0) < 800) { in0 = 1; } else { in0 = 0; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 8; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 5; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 6; }
      if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 1)) { A = 7; }
      if ((in1 == 0) && (in2 == 0) && (in3 == 0) && (in4 == 0) && (in0 == 0)) { A = 9; }
      if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 4; }
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3; }*/
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
    Serial.print("(A:");
    Serial.print(A); 
    Serial.print(" a:");
    Serial.print(a); 
    Serial.print(" k:");
    Serial.print(k);
    Serial.println(")");
    /*Serial.print("(");
    Serial.print(A+" ");
    Serial.print(a+" ");
    //Serial.print(" ");
    Serial.print(k);
    Serial.println(")");*/
    k = 0;
  }
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
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 1;   }
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

//--------------------------------------------------------------

/*void AV() {
      i = 1;
      if (napr == 1) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
          newt = j;
          j++;
        }
      }
      if (ver[newt][3] == 0) {
        while (dor[i][0] != 0) { i++; }
        dor[i][0] = newt;
        dor[i][1] = myt;
        i++;
        dor[i][0] = myt;
        dor[i][1] = newt;
      }
      newt = 1;
}*/

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
