#define ras 33  // кол-во вершин + 1
#define ROOT  2
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
int a = 0;   // длинна дороги
float A = 0; // какая локация
byte f, i, j, flag, u, ff, uu;
int  x, y, x2, y2, xk, yk, p, w; 
byte left, right, up, down;
byte myt  = 0;
byte newt = 0;
char F = 0;  // для обмена данными между ардуинами/ПК
int x1 = 2;
int y1 = 2;
byte kkk = 0;
void setup() {
  Serial.begin(9600);
  while ((digitalRead(10) == 1) && (ROOT == 2)) { delay(1); } delay(500);
  start();
}

void loop() {
  
}

void start() {
  zum();
  delay(500);
  auto_set();
  scan();
  vibros();
  //vozvrat();
  delay(100);
  zum();
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

void dvigenie() {
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
  myt = newt;
  x = ver[myt][1];
  y = ver[myt][2];
  napr = Napr;  
}

void vozvrat() {
  newt = 1;
  navigator(myt, newt);
  i = 1;
  dvigenie();
  if (napr != 1) {
    ff = 0;
    while(napr > 1) {
      ff++;
      r(); 
    }
    Serial.println("P");
    Serial.println(ff);
    otklik();
  }
}

void vibros() {
  i = 1; xk = 0; yk = 0; kkk = 1;
  while (ver[i][0] != 0) {
    if ((ver[i][1] <= ver[kkk][1]) && (ver[i][2] <= ver[kkk][2])) { kkk = i; }
    i++;
  }
  //-------------------------
  x1 = xk; //x1 = xk + x1;
  y1 = yk; //y1 = yk + y1;
  i = 1;
  while ((ver[i][1] != x1) || (ver[i][2] != y1)) { i++; }
  //newt = ver[i][0];
  newt = kkk;
  navigator(myt, newt);
  //i = 1; a = 101; u = 0;
  dvigenie();
  //Serial.println("O");
  //delay(1000);
}

void auto_set() {
  napr = 0;
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
    if ((A == 5.1) || (A == 5.2) || (A == 6) || (A == 1 ))              { AV(); } 
    if ((A == 2.1) || (A == 3.1) || (A == 5) || (A == 5.1) || (A == 6)) { AL(); }
    if ((A == 2.2) || (A == 3.2) || (A == 5) || (A == 5.2) || (A == 6)) { AR(); }
    if (A == 2.1) { l(); }
    if (A == 2.2) { r(); }
    if (ROOT == 1) {
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
        if (ROOT == 1) { Serial.print("deikstra(otkuda): "); Serial.print(myt); Serial.println(" ");  }
        navigator(myt, 0); //navigator(myt, 0);
        if (ROOT == 1) {
          vivod();
          vivod2();
        }
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
        if (ROOT == 1) { Serial.print("deikstra(kuda): "); Serial.println(w);  vivod2(); }
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
      if (ROOT == 1) { vivod3(); }
    }
  }
  if (ROOT == 1) { Serial.println("FINISH"); }
  if (ROOT == 1) { vivod(); }
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

void otklik() {
  F = 0;
  while (F == 0) {
    if(Serial.available() > 0) {
      F = Serial.read();
      if (F != 'O') { F = 0; }
    }
  }
}
  
void V() {
  Serial.println("V");
  otklik();
}

void N() {
  if (ROOT == 1) { Serial.print("N:"); }
  if ((A == 5) || (A == 6)) {  // N
    L(); L(); 
  }
  else if ((A == 2.2) || (A == 3.2) || (A == 5.2) || (A == 4)) {  // L
    L();
  }
  else if ((A == 2.1) || (A == 3.1) || (A == 5.1)) {  // R
    R();
  }
  n();
  otklik();
}

void L() {
  Serial.println("L");
  l();
  otklik();
}

void R() {
  Serial.println("R");
  r();
  otklik();
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
  Serial.println("Z");
  otklik();
}

void out() {
  Serial.println("o");
  otklik();
}

//-----------------------------------------

void lin() { // линия до центра клетки
  Serial.println("v");
    A = 10;
    while (A == 10) {
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
}

void linia() { // линия, пока идет прямая
  Serial.println("l");
    A = 10;
    while (A == 10) {
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


