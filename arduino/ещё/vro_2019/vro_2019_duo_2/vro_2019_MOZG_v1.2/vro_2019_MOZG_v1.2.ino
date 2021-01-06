#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(5, 6); // RX, TX
#include "navigator_v2.2.h"
//byte dor[1][1];
float A = 0; // какая локация
byte a, f, i, j, flag, u;
int  x, y; 
byte left, right, up;
byte myt  = 0;
byte newt = 0;
byte napr = 1;
char F = 0;  // для обмена данными между ардуинами/ПК
char ver[33][4] { // №, x, y, посещена ли
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

/* arxiv:
 *  Y - да, все ОК
 *  E - ошибка
 *  S - старт
 *  K - нажали на кнопку
 *  O - конец, задание выполнено
 *  вывод в linia (SoftSerial): A a
 */

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  pinMode (13, OUTPUT);
  //hello();
  //knopka_start();
}

void loop() {
  
}

void test_n() {
  t_finish = 11;
  t_start = 3;
  navigator();
  i = 1;
  while ((i < 40) && (mas[i] < 200)) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(mas[i]);
    i++;
  }
  i = 1;
  Serial.println("------------");
  while ((i < 40) && (pyt[i] > 0)) {
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
}

void dvigenie_scan() {
  t_start = myt;
  i = 1;
  while (ver[i][3] == 1) { i++; }
  t_finish = i;
  navigator();
  i = 1;
  while (pyt[i] > 0) {
    if (napr == 1) {
      
    }
    //--------------
    myt = pyt[i];
    i++;
  }
}

void scan() {
  j = 3;  // общий счетчик точек
  x = 0; y = 0; // наст. коорд.
  napr = 1;
  u = 1;
  newt = 1;
  while (f == 0) {//---------------------------------------------
    linia();      // проехал до локации
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
        
        if ((napr == 1) && (ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { up++;    }
        if ((napr == 2) && (ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) { up++;    }
        if ((napr == 3) && (ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { up++;    }
        if ((napr == 4) && (ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) { up++;    }
        
        if ((napr == 1) && (ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) { left++;  }
        if ((napr == 2) && (ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { left++;  }
        if ((napr == 3) && (ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) { left++;  }
        if ((napr == 4) && (ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { left++;  }
        
        if ((napr == 1) && (ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) { right++; }
        if ((napr == 2) && (ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { right++; }
        if ((napr == 3) && (ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) { right++; }
        if ((napr == 4) && (ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) { right++; }
        
        i++;
      }
      i = 1;
      if ((up > 0) || (left > 0) || (right > 0)) {  // есть рядом неразведанные
        if (up > 0) { V(); }
        else if (left > 0) { L(); }
        else { R(); }
      }
      else { // нет рядом неразведанных (они далеко)
        //--------------------------------------------------  дописать
        dvigenie_scan();
      }
      up = 0;
      left = 0;
      right = 0;
      f = 0;
    }
  }
  Serial.println(napr);
  Serial.println("---");
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
void linia() {
  Serial.println("l");
  while (F != 'S') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
  A = 0;
  a = 10;
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
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
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
    if (SoftSerial.available() > 0) {
      F = SoftSerial.read();
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
  while (F != 'O') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
}

void hello() {
  delay(1000);
  Serial.println("H");
  SoftSerial.println("H");
  while (F != 'Y') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
  Serial.println("Z");
  SoftSerial.println("Z");
}

void knopka_start() {
  while (F != 'K') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
  Serial.println("Z");
  SoftSerial.println("Z");
  delay(600);
}

void otklik() {
  while (F != 'S') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
  while (F != 'O') {
    if (Serial.available() > 0)     { F = Serial.read();     }
    if (SoftSerial.available() > 0) { F = SoftSerial.read(); }
  }
}

void V() {
  Serial.println("V");
  SoftSerial.println("V");
  otklik();
}

void N() {
  Serial.println("N");
  SoftSerial.println("N");
  otklik();
}

void L() {
  if (napr == 1) { napr = 4; }
  else { napr--; }
  Serial.println("L");
  SoftSerial.println("L");
  otklik();
}

void R() {
  if (napr == 4) { napr = 1; }
  else { napr++; }
  Serial.println("R");
  SoftSerial.println("R");
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
  SoftSerial.println("Z");
  otklik();
}

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

