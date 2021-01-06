#define ras 33  // кол-во вершин + 1
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
int D = 0;   //для определения дугового движения
int a = 0;   // длинна дороги
int k = 0;   // длинна дороги прямого участка пути
int e = 0;   // ошибка для П регулятора
int min_2 = 600;
int min_3 = 500;
int max_2 = 900;
int max_3 = 900;
float A = 0; // какая локация
byte f, i, j, flag, u, ff;
int  x, y, x2, y2, xk, yk; 
byte left, right, up;
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
  //hello();
  //knopka_start();
  //auto_set();
  //scan();
  //vibros();
  //vozvrat();
  vivod_n();
}

void loop() {
  
}

void vivod_n() {
  navigator(2, 15);
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
  /*Serial.println("A");
  while (F != 'S') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
  napr = 0;
  while (napr == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '1') { napr = 1; }
      if (F == '2') { napr = 2; }
      if (F == '3') { napr = 3; }
      if (F == '4') { napr = 4; }
    }
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
      if (F == '1') { napr = 1; }
      if (F == '2') { napr = 2; }
      if (F == '3') { napr = 3; }
      if (F == '4') { napr = 4; }
    }
  }
  while (F != 'O') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }*/
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

void a_set() {
  napr = 1;
  if ((analogRead(A2) > 700) && (analogRead(A3) > 700)) {
    k = 0;
    digitalWrite(DL, 1);
    analogWrite (SL, M);
    digitalWrite(DR, 0);
    analogWrite (SR, M);
    while (analogRead(A0) <= 725) { k++; delay(1); }
    while (analogRead(A0) >= 725) { k++; delay(1); }
    k = k/900;    //  подогнать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    while (k > 0) {
      napr++;
      k--;
    }
    digitalWrite(DL, 1);
    analogWrite (SL, 0);
    digitalWrite(DR, 1);
    analogWrite (SR, 0);
    k = 0;
  }
  Serial.println(napr);
}

void scan() {
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
        if ((ver[i][3] == 0) && (ver[i][0] > 0) && (dor[myt][i] > 0) && (myt != i)) {
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
          if ((dor[i][i] < a) && (ver[i][3] == 0)) {
            a = dor[i][i];
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

/*void vivod3() {
  i = 1;
  Serial.println("------------");
  while ((i < 40) && (pyt[i] > 0)) { // путь по точкам
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
  Serial.println();
}

void vivod2() {
  Serial.println("---");
  Serial.print("myt:");
  Serial.print(myt);
  Serial.print(" u:");
  Serial.println(u);
          Serial.print(" x:");
          Serial.print(x);
          Serial.print(" y:");
          Serial.println(y);
  i = 1;
  while (pyt_auto[i] > 0) {
          Serial.print(pyt_auto[i]);
          Serial.println(" ");
          i++;
  }
  Serial.println("---");
}*/

void vivod() {
  Serial.println("---------------");
  
  //Serial.println(napr);
  //Serial.println("---");
  i = 1; u = 1;
  while (i < 33) {
    while (u < 33) {
      Serial.print(dor[i][u]);
      Serial.print(" ");
      u++;
    }
    u = 1;
    Serial.println();
    i++;
  }
  i = 1;
  while (ver[i][0] > 0) {
    Serial.print((int)ver[i][0]);
    Serial.print(" ");
    Serial.print((int)ver[i][1]);
    Serial.print(" ");
    Serial.print((int)ver[i][2]);
    Serial.print(" ");
    Serial.println((int)ver[i][3]);
    Serial.print(" ");
    i++;
    delay(100);
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

void linia() {
  if (ROOT == 1) {
    Serial.println("linia");
    while (F != 'S') {
      if (Serial.available() > 0)     { F = Serial.read(); }
    }
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
      if (D > 0) { A = 1; }
      else { A = 2; }
    }
    else {       // не дуга
      //process();
      if (analogRead(A1) < 700) { in1 = 1; } else { in1 = 0; }
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
      if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3; }
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

//--------------------------------------------------------------

void AV() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
        }
      }
      if (newt > 33) {
        ver[j][0] = j; 
        dor[myt][j] = 1;
        dor[j][myt] = 1;
        j++;
      }
      else {
        dor[myt][newt] = 1;
        dor[newt][myt] = 1;
      }
      newt = 1;
}

void AL() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
        }
      }
      if (newt > 33) {
        ver[j][0] = j; 
        dor[myt][j] = 1;
        dor[j][myt] = 1;
        j++;
      }
      else {
        dor[myt][newt] = 1;
        dor[newt][myt] = 1;
      }
      newt = 1;
}

void AR() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y + 1;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x - 1;
          ver[j][2] = y;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x;
          ver[j][2] = y - 1;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][1] = x + 1;
          ver[j][2] = y;
        }
      }
      if (newt > 33) {
        ver[j][0] = j; 
        dor[myt][j] = 1;
        dor[j][myt] = 1;
        j++;
      }
      else {
        dor[myt][newt] = 1;
        dor[newt][myt] = 1;
      }
      newt = 1;
}

//------------------------------- navigator 5.0 

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
  //while (gg > 0) {
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
  if (t_finish > 0) {
    t_nast = t_finish;
    ii = 1;
    pyt[1] = t_finish;
    iii = 2;
    while (t_nast != t_start) {
      while ((ii < ras*4) && (dor[ii][0] != t_nast)) { ii++; }
      if (ver[dor[ii][1]][4] + 1 == ver[t_nast][4]) {
        pyt[iii] = dor[ii][1];
        iii++;
        t_nast = dor[ii][1];
      }
      else {
        ii++;
      }
    }
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
    //------------------------------ mypyt(); 
    ii = 1;
    while (pyt_auto[ii] != 0) {
      pyt_auto[ii] = 0;
      ii++;
    }
    ii = 1; gg = 1; aa = 2;
    t_nast = t_start;
    Napr = napr;
    while (t_nast != t_finish) {
      //if (((napr == 1) && (ver[t_nast][1] + 1 == ver[t_finish][1]) && (ver[t_nast][2] == ver[t_finish][2])) || ((napr == 2) && (ver[t_nast][1] == ver[t_finish][1]) && (ver[t_nast][2] + 1 == ver[t_finish][2])) || ((napr == 3) && (ver[t_nast][1] - 1 == ver[t_finish][1]) && (ver[t_nast][2] == ver[t_finish][2])) || ((napr == 4) && (ver[t_nast][1] == ver[t_finish][1]) && (ver[t_nast][2] - 1 == ver[t_finish][2]))) { pyt_auto[ii] = 1; }                             
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
      //---------------------------------------------
      /*do {  // если есть прямые без перекрестков
        gg = 1;
        iii = 0;
        while (gg < ras) {
          if ((dor[t_nast][gg] > 0) && (gg != t_nast)) {
            if ((Napr == 1) || (Napr == 3)) {
              if (ver[t_nast][2] == ver[gg][2]) {
                iii = 3;
              }
              else {
                iii++;
              }
            }
            if ((Napr == 2) || (Napr == 4)) {
              if (ver[t_nast][1] == ver[gg][1]) {
                iii = 3;
              }
              else {
                iii++;
              }
            }
          } 
          gg++;
        } 
        t_nast = pyt[aa];
        aa++;
      } while (iii == 2); */
      t_nast = pyt[aa]; aa++;  // если нет прямых без перекрестков
    }
    //myt = t_finish;
    //napr = Napr;
  }
}
