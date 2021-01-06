#define SP     11
#define DP     13
#define SL     10
#define DL     12

byte mas[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};  // штрих-код (первые цифрры координата в двоич сс, последние две цифрры координата в дес сс)
int i = 0;
int a = 0;
byte b = 2;  // куда виртуально повернут робот
byte x = 1;  // x вирт местоположение
byte y = 3;  // y вирт местоположение
byte pr[9][7] {               // "пробки" 
  // начало в 0;0 - y;x !!!
  {1, 15, 1, 1, 1, 1, 1},      // 1   - 0
  {1, 1, 30, 1, 1, 1, 1},      // 1^2 - 1
  {1, 31, 1, 1, 20, 1, 1},      // 2   - 2
  {1, 1, 17, 41, 1, 1, 1},      // 2^3 - 3
  {20, 1, 1, 31, 1, 31, 1},      // 3   - 4  -----
  {1, 1, 1, 1, 1, 1, 1},      // 3^4 - 5
  {1, 20, 1, 1, 23, 1, 1},      // 4   - 6
  {1, 1, 19, 1, 1, 1, 1},      // 4^5 - 7
  {2, 1, 18, 24, 1, 32, 1},      // 5   - 8
// |  |  |  |  |  |  |  
// 0  1  2  3  4  5  6
};
byte ms[50]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     
// "ключ" пути туда
byte ms_2[50] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     
// "ключ" пути обратно

// mas[7] = x
// mas[8] = y

void start()      {
  ZUM();
  delay (600);
  strich_cod();
  linia(); 
  // а3
  navigator();
  while (a == 0) {
    if (ms[i] == 0) { a = 1;   }
    if (ms[i] == 1) { linia(); }
    if (ms[i] == 2) { L();     }
    if (ms[i] == 3) { P();     }
    i++;
  }
  i = 0;
  a = 0;
  L();
  L();
  ZUM();
  delay(2000);
  ZUM();
  while (a == 0) {
    if (ms_2[i] == 0) { a = 1;   }
    if (ms_2[i] == 1) { linia(); }
    if (ms_2[i] == 2) { L();     }
    if (ms_2[i] == 3) { P();     }
    i++;
  }
  i = 0;
  a = 0;
  // а3
  linia();
  cod();
  ZUM();
}

void D_V()        {
  if (((pr[4][x - 1] > ( pr[3][x - 1] + pr[2][x] + pr[3][x + 1] ))) || ( pr[4][x - 1] > ( pr[5][x - 1] + pr[6][x] + pr[5][x + 1] ) ) ) {
    if ( ( pr[3][x - 1] + pr[2][x] + pr[3][x + 1] ) > ( pr[5][x - 1] + pr[6][x] + pr[5][x + 1] ) ) {
      ms[i] = 2; i++;
      ms[i] = 1; i++;
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 2; i++;
    }
    else {
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 2; i++;
      ms[i] = 1; i++;
      ms[i] = 2; i++;
      ms[i] = 1; i++;
      ms[i] = 3; i++;
    }
  }
  else {
    ms[i] = 1; i++;
  }
  x++;
}

void D_L_1()      {  
  if ((y == 3) && (mas[7] == x)) {
    if (pr[3][x-1] < (pr[2][x-1] + pr[3][x] + pr[4][x-1])) {
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        y--;
    }
    else {
      ms[i] = 1; i++;
      ms[i] = 2; i++;
      ms[i] = 1; i++;
      ms[i] = 2; i++;
      ms[i] = 1; i++;
      y--;
    }
  }
  else {
    if (y == 3) {
      if (pr[4][x - 1] < pr[3][x-1]) {
        ms[i] = 1; i++;
        x++;
      }
      else {
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        y--;
      }
    }
    else {
      //----------------------------------
      if (y == 2) {
        if ((pr[2][x - 1] < (pr[3][x - 1] + pr[4][x - 1] + pr[3][x])) && (pr[2][x - 1] < (pr[1][x - 1] + pr[0][x - 1] + pr[1][x]))) {
          ms[i] = 1; i++;
        }
        else {
          if ((pr[3][x - 1] + pr[4][x - 1] + pr[3][x]) < (pr[1][x - 1] + pr[0][x - 1] + pr[1][x])) {
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
          }
          else {
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
          }
        }
        x++;
      }
    }
  }
}

void D_L_2()      {
  if ((y == 3) && (mas[7] == x)) {
    a = pr[1][x-1] + pr[3][x-1];
    if ((a > (pr[4][x-1] + pr[3][x] + pr[2][x-1] + pr[1][x-1])) || (a > (pr[2][x-1] + pr[1][x] + pr[0][x-1] + pr[3][x-1])) || (a > (pr[4][x-1] + pr[3][x] + pr[1][x] + pr[0][x-1]))) {
      if (a > (pr[4][x-1] + pr[3][x] + pr[2][x-1] + pr[1][x-1])) { 
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
      }
      else {
      if (a > (pr[2][x-1] + pr[1][x] + pr[0][x-1] + pr[3][x-1])) {
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
      }
      else {
      if (a > (pr[4][x-1] + pr[3][x] + pr[1][x] + pr[0][x-1])) {
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
      }
      }
      }
    }
    else {
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 1; i++;
    }
    y--;
    y--;
  }
  else {
    if ((y == 2) && (mas[7] == x)) {
      if (pr[1][x-1] < (pr[2][x-1] + pr[1][x] + pr[0][x-1])) {
        ms[i] = 2; i++;
        ms[i] = 1; i++;
      }
      else {
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
      }
      y--;
    }
    else {
    if (y == 3) {
      if (pr[4][x - 1] < pr[3][x-1]) {
        ms[i] = 1; i++;
        x++;
      }
      else {
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        y--;
      }
    }
    else {
      if (y == 2) {
        if (pr[2][x - 1] < pr[1][x-1]) {
          ms[i] = 1; i++;
          x++;
        }
        else {
          ms[i] = 2; i++;
          ms[i] = 1; i++;
          ms[i] = 3; i++;
          y--;
        }
      }
      else {
        if (y == 1) {
          if (pr[0][x-1] < (pr[1][x-1] + pr[2][x-1] + pr[1][x])) {
            ms[i] = 1; i++;
          }
          else {
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
          }
          x++;
        }
      }
    }
  }
  }  
}

void D_P_1()      {
  if ((y == 3) && (mas[7] == x)) {
    if (pr[5][x-1] < (pr[4][x-1] + pr[5][x] + pr[6][x-1])) {
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        y++;
    }
    else {
      ms[i] = 1; i++;
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      y++;
    }
  }
  else {
    if (y == 3) {
      if (pr[4][x - 1] < pr[5][x-1]) {
        ms[i] = 1; i++;
        x++;
      }
      else {
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        y++;
      }
    }
    else {
      if (y == 4) {
        if ((pr[6][x - 1] < (pr[5][x - 1] + pr[4][x - 1] + pr[5][x])) && (pr[6][x - 1] < (pr[7][x - 1] + pr[8][x - 1] + pr[7][x]))) {
          ms[i] = 1; i++;
        }
        else {
          if ((pr[5][x - 1] + pr[4][x - 1] + pr[5][x]) < (pr[7][x - 1] + pr[8][x - 1] + pr[7][x])) {
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
          }
          else {
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
          }
        }
        x++;
      }
    }
  }
}

void D_P_2()      {
  if ((y == 3) && (mas[7] == x)) {
    a = pr[5][x-1] + pr[7][x-1];
    if ((a > (pr[4][x-1] + pr[5][x] + pr[6][x-1] + pr[7][x-1])) || (a > (pr[6][x-1] + pr[7][x] + pr[8][x-1] + pr[5][x-1])) || (a > (pr[4][x-1] + pr[5][x] + pr[7][x] + pr[8][x-1]))) {
      if (a > (pr[4][x-1] + pr[5][x] + pr[6][x-1] + pr[7][x-1])) { 
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
      }
      else {
      if (a > (pr[6][x-1] + pr[7][x] + pr[8][x-1] + pr[5][x-1])) {
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
      }
      else {
      if (a > (pr[4][x-1] + pr[5][x] + pr[7][x] + pr[8][x-1])  ) {
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
      }
      }
      }
    }
    else {
      ms[i] = 3; i++;
      ms[i] = 1; i++;
      ms[i] = 1; i++;
    }
    y++;
    y++;
  }
  else {
    if ((y == 4) && (mas[7] == x)) {
      if (pr[7][x-1] < (pr[6][x-1] + pr[7][x] + pr[8][x-1])) {
        ms[i] = 3; i++;
        ms[i] = 1; i++;
      }
      else {
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 3; i++;
        ms[i] = 1; i++;
      }
      y++;
    }
    else {
    if (y == 3) {
      if (pr[4][x - 1] < pr[5][x-1]) {
        ms[i] = 1; i++;
        x++;
      }
      else {
        ms[i] = 3; i++;
        ms[i] = 1; i++;
        ms[i] = 2; i++;
        y++;
      }
    }
    else {
      if (y == 4) {
        if (pr[6][x - 1] < pr[7][x-1]) {
          ms[i] = 1; i++;
          x++;
        }
        else {
          ms[i] = 3; i++;
          ms[i] = 1; i++;
          ms[i] = 2; i++;
          y++;
        }
      }
      else {
        if (y == 5) {
          if (pr[8][x-1] < (pr[7][x-1] + pr[6][x-1] + pr[7][x])) {
            ms[i] = 1; i++;
          }
          else {
            ms[i] = 2; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 3; i++;
            ms[i] = 1; i++;
            ms[i] = 2; i++;
          }
          x++;
        }
      }
    }
  }
  }  
}

void navigator()  {
  //ZUM();
  //delay (500);
  //mas[7] = x;
  //mas[8] = y;
  while (i < 50) {
    if ((x == mas[7]) && (y == mas[8])) {
      i = 55;  //  добрался
    }
    else {  
      if (((mas[8] == 1) && (mas[7] == 6)) || ((mas[8] == 4) && (mas[7] == 3)))   {
        ms[0] = 2;
        ms[1] = 1;
        ms[2] = 3;
        ms[3] = 1;
        ms[4] = 3;
        ms[5] = 1;
        ms[6] = 2;
        ms[7] = 1;
        ms[8] = 3;
        ms[9] = 1;
        if ((mas[8] == 1) && (mas[7] == 6)) {
          ms[10] = 2;
          ms[11] = 1;
          ms[12] = 1;
          ms[13] = 2;
          ms[14] = 1;
          ms[15] = 3;
          ms[16] = 1;
          ms[17] = 2;
          ms[18] = 1;
          ms[19] = 1;
        }
        i = 55;
      }
      else {
        if (mas[8] == 3) { D_V();   }  // вперед
        if (mas[8] == 4) { D_P_1(); }  // вправо 1
        if (mas[8] == 5) { D_P_2(); }  // вправо 2
        if (mas[8] == 2) { D_L_1(); }  // влево 1
        if (mas[8] == 1) { D_L_2(); }  // влево 2
      }
    }
    Serial.print("processed...");
    Serial.println(i);
    //i++;
  }
  Serial.println("ms_COMPLETE");
  Serial.println("ms2_OPERATING");
  //-----------------------------------------
  i = 49;
  a = 0;
  while (i  >=   0) {  
    if (ms[i] == 1) { ms_2[a] = 1;  } 
    if (ms[i] == 2) { ms_2[a] = 3;  }  
    if (ms[i] == 3) { ms_2[a] = 2;  }
    if (ms[i] == 0) { } else { a++; } 
    i--;
  }
  i = 0;
  a = 0;
  //delay (500);
  //ZUM();
  Serial.println("ms2_COMPLETE");
  Serial.println("navigator_COMPLETE");
}

void cod()        {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 100);
  i = 10;
  a = 7;
  while (a > 0) {
    a--;
    if (mas[a] == 1) { a = 0; }
    else { i--; }
  }
  //delay (i*100);
  //delay (600);
  delay (1200);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void setup()      {
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);  
  pinMode(4, OUTPUT);
  Serial.begin (9600);
  //test();
  //------------------------------------------------------------------------------
  while ((digitalRead(9)) == 1) { delay(10); }
  //test();
  start();
  /*digitalWrite(DL, HIGH );
  analogWrite(SL, 50);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 50);*/
  
}

void test2()      {
  Serial.println("TEST:");
  mas[7] = 1;  // x
  mas[8] = 1;  // y
  navigator();
  Serial.println("NAVIGATOR_COMPLETE");
  while (i < 50) {
    Serial.println(ms[i]);
    i++;
  }
  Serial.println("TEST_COMPLETE");
}

void loop()       {
  /*Serial.print (analogRead(A1));
  Serial.print ("---");
  Serial.println (analogRead(A2));
  delay(100);*/
}

void test()       {
  //linia();
  strich_cod();
  /*digitalWrite(DL, HIGH );
  analogWrite(SL, 65);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 65);*/
  Serial.println (mas[0]);
  Serial.println (mas[1]);
  Serial.println (mas[2]);
  Serial.println (mas[3]);
  Serial.println (mas[4]);
  Serial.println (mas[5]);
  Serial.println (mas[6]);
  Serial.println ("---");
  Serial.println (mas[7]);
  Serial.println (mas[8]);
  Serial.println ("---");
  if ((mas[7]==3) && (mas[8]==4)) {
    ZUM();
  }
}

void L()          {
  digitalWrite(DL, LOW );
  analogWrite(SL, 100);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 100);
  while ((analogRead(A1)) < 600) { }
  while ((analogRead(A1)) > 600) { }
  while ((analogRead(A1)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void P()          {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DP, LOW );
  analogWrite(SP, 100);
  while ((analogRead(A2)) < 600) { }
  while ((analogRead(A2)) > 600) { }
  while ((analogRead(A2)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}
 
void ZUM()        {
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
}

/*void strich_cod() {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 50);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 50);
    }
    if (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, LOW );
      analogWrite(SL, 50);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 50);
    }
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 50);
      digitalWrite(DP, LOW );
      analogWrite(SP, 50);
    }
  }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 50);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 50);
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) { }
  while (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) { }
  delay (400);
  while (i < 7) {
    if ((analogRead(A2)) < 600) {
      mas[i] = 1;
    }
    delay (180);  //23 мм (200 мсек - 30 мм)
    i++;
  }
  i = 0;
  delay (100);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
  // черная линия, а потом 7-бит
  // проехать вперед и считать код, записать в массив mas[]
  i = (mas[6]*64)+(mas[5]*32)+(mas[4]*16)+(mas[3]*8)+(mas[2]*4)+(mas[1]*2)+mas[0];
  while (i >= 10) {
    i = i - 10;
    mas[7]++;
  }
  mas[8] = i;
  i = 0;
  //mas[7] = x;
  //mas[8] = y;
}*/

void strich_cod() {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 70);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 70);
    }
    if (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, LOW );
      analogWrite(SL, 70);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 70);
    }
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 70);
      digitalWrite(DP, LOW );
      analogWrite(SP, 70);
    }
  }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 70);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 70);
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) { }
  while (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) { }
  delay (300);
  while (i < 7) {
    if ((analogRead(A2)) < 600) {
      mas[i] = 1;
    }
    delay (100);  //23 мм (200 мсек - 30 мм)
    i++;
  }
  i = 0;
  delay (100);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
  // черная линия, а потом 7-бит
  // проехать вперед и считать код, записать в массив mas[]
  i = (mas[6]*64)+(mas[5]*32)+(mas[4]*16)+(mas[3]*8)+(mas[2]*4)+(mas[1]*2)+mas[0];
  while (i >= 10) {
    i = i - 10;
    mas[7]++;
  }
  mas[8] = i;
  i = 0;
  if (mas[3] == 1) {
    mas[7] = 6;
    mas[8] = 1;
  }
  if (mas[3] == 0) {
    mas[7] = 3;
    mas[8] = 4;
  }
  
  //mas[7] = x;
  //mas[8] = y;
} 

void linia()      {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 100);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 100);
    }
    if (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, LOW );
      analogWrite(SL, 100);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 100);
    }
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 100);
      digitalWrite(DP, LOW );
      analogWrite(SP, 100);
    }
  }
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 100);
    digitalWrite(DP, HIGH );
    analogWrite(SP, 100);    
  }
  delay(100);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

