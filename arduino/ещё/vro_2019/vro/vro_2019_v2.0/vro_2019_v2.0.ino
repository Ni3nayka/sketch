#include "navigator_v2.2.h"
#include "library.h"
//int i = 1;

void setup() {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (4 , OUTPUT);
  pinMode (DR, OUTPUT);
  pinMode (DL, OUTPUT);
  scan();
  while (digitalRead(2) == 1) { delay(10); } zum(); delay(500); 
  //linia();
  //L(); linia(); R(); linia(); 
  //Serial.print("O"); delay(3000); Serial.print("O");
  //test_n();
}

void loop() {
  //test_d();
}

void serial_v() {
  if (u == 6) { f++; }
}

void linia_v() {
  if (u == 1) { A = 6; a = 0; }
  if (u == 2) { A = 6; a = 0; }
  if (u == 3) { A = 3.1; a = 1; }
  if (u == 4) { A = 2.1; a = 0; }
  if (u == 5) { A = 3.1; a = 1; }
  //if (u == 5) { A = 2.2; a = 0; }
  //if (u == 2) { f++; }
  a++;
  u++;
  
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

void arxiv() {
  //test_e();
  //test_d3();
  //test_d();
  linia_d();
  if (abs(e) >= M*0.9) { D = D + e; }
  if (abs(e) < 5) { D = 0; }
  Serial.print(e);
  Serial.print(" ");
  Serial.println(D);
  delay(1);
  if (abs(D) > 4500) {
    analogWrite (SL, 0); 
    analogWrite (SR, 0);
    while (b < 1000) {}
  }
  /*in0 = analogRead(A0);
  if (in0 > max_0) { max_0 = in0; }
  if (in0 < min_0) { min_0 = in0; }
  Serial.print(min_0);
  Serial.print(" ");
  Serial.println(max_0);*/
}

void scan() {
  j = 3;  // общий счетчик точек
  x = 0; y = 0; // наст. коорд.
  napr = 1;
  u = 1;
  newt = 1;
  while (f == 0) {//---------------------------------------------
    //linia();      // проехал до локации
    linia_v();// if (A > 0) {
    //a2 = a;
    /*while (a > 0) {  //учитываем прямые участки пути
      if (napr == 1) { x++; }  // определяем координату
      if (napr == 2) { y++; }
      if (napr == 3) { x--; }
      if (napr == 4) { y--; }
      myt = 1;
      while (!((ver[myt][1] == x) && (ver[myt][2] == y))) { myt++; } // ищем точку с такой-же координатой
      ver[myt][3] = 1;   // отмечаем, что были в ней
      AV();
      a--;
    }*/
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
      while ((i < 34) && (flag == 0)) {
        if (((dor[myt][i] > 0) && (ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) || ((dor[myt][i] > 0) && (ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) || ((dor[myt][i] > 0) && (ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) || ((dor[myt][i] > 0) && (ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0))) {
          flag = 1;
        }
        i++;
      }
      i = 1;
      if (flag == 1) {  // есть рядом неразведанные
        flag = 0;  // поиск, куда можно поехать
        // вперед 
        while (!((ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 1) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 1)) { flag = 1; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 2) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 2)) { flag = 1; }; i = 1;
        while (!((ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 3) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 3)) { flag = 1; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 4) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 4)) { flag = 1; }; i = 1;
        // влево
        while (!((ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 2) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 2)) { flag = 2; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 3) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 3)) { flag = 2; }; i = 1;
        while (!((ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 4) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 4)) { flag = 2; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 1) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 1)) { flag = 2; }; i = 1;
        // вправо
        while (!((ver[i][1] == x + 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 4) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 4)) { flag = 3; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y + 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 1) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 1)) { flag = 3; }; i = 1;
        while (!((ver[i][1] == x - 1) && (ver[i][2] == y) && (ver[i][3] == 0)) && (flag == 0) && (napr == 2) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 2)) { flag = 3; }; i = 1;
        while (!((ver[i][1] == x) && (ver[i][2] == y - 1) && (ver[i][3] == 0)) && (flag == 0) && (napr == 3) && (i < 34)) { i++; } if ((dor[myt][i] > 0) && (i < 34) && (flag == 0) && (napr == 3)) { flag = 3; }; i = 1;
        Serial.println(flag);
        /*if (flag == 1) { V(); }
        if (flag == 2) { L(); }
        if (flag == 3) { R(); }*/
        //Serial.println(flag);
        if (flag == 2) { l(); }
        if (flag == 3) { r(); }
      }
      else { // нет рядом неразведанных (они далеко)
        //--------------------------------------------------  дописать
        Serial.println("11111111");
      }
    }
    //} 
    serial_v(); // искуственная проверка 
  }
  Serial.println("---");
  Serial.println(napr);
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

void linia() {
  a = 0;
  //while ((((analogRead(A1) > 350) && (analogRead(A4) > 350))) && (((analogRead(A2) < 850) || (analogRead(A3) < 850)))) {
  while ((abs(D) < 4500) && (analogRead(A1) > 600) && (analogRead(A4) > 600) && ((analogRead(A2) < 850) || (analogRead(A3) < 850)))  {
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
    delay(100);
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
  a++;
  delay(100);
  //-------------------------------------------------- проехали по линии до какого-то элемента
  if (abs(D) > 100) {  // дуга
    if (D > 0) { A = 2.1;}
    else { A = 2.2; }
  }
  else {       // не дуга
    //process();
    if (analogRead(A1) < 600) { in1 = 1; } else { in1 = 0; }
    if (analogRead(A2) < 800) { in2 = 1; } else { in2 = 0; }
    if (analogRead(A3) < 800) { in3 = 1; } else { in3 = 0; }
    if (analogRead(A4) < 600) { in4 = 1; } else { in4 = 0; }
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
    delay(500);
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

void dvigenie() {
  t_start = myt;
  i = 1;
  while (ver[i][3] == 1) { i++; }
  t_finish = i;
  navigator();
  i = 1; u = 2;
  while (pyt[u] > 1) {
    if (napr == 1) {
      if      ((ver[myt][1] + 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { V(); }
      else if ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] - 1 == ver[pyt[u]][2])) { L(); }
      else if ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] + 1 == ver[pyt[u]][2])) { R(); }
      else { N(); }
    }
    if (napr == 2) {
      if      ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] + 1 == ver[pyt[u]][2])) { V(); }
      else if ((ver[myt][1] + 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { L(); }
      else if ((ver[myt][1] - 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { R(); }
      else { N(); }
    }
    if (napr == 3) {
      if      ((ver[myt][1] - 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { V(); }
      else if ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] + 1 == ver[pyt[u]][2])) { L(); }
      else if ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] - 1 == ver[pyt[u]][2])) { R(); }
      else { N(); }
    }
    if (napr == 4) {
      if      ((ver[myt][1] == ver[pyt[u]][1]) && (ver[myt][2] - 1 == ver[pyt[u]][2])) { V(); }
      else if ((ver[myt][1] - 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { L(); }
      else if ((ver[myt][1] + 1 == ver[pyt[u]][1]) && (ver[myt][2] == ver[pyt[u]][2])) { R(); }
      else { N(); }
    }
    myt = pyt[u];
    linia();
    u++;
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


