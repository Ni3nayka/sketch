#define SR     11
#define DR     13
#define SL     10
#define DL     12

byte mas[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};  // штрих-код (первые цифрры координата в двоич сс, последние две цифрры координата в дес сс)
int i = 0;
int a = 0;
byte b = 0;  // откуда виртуально приехал робот
byte x = 1;  // x вирт местоположение
byte y = 3;  // y вирт местоположение
byte pr[9][7] {               // "пробки" 
  // начало в 0;0 - y;x !!!
  {1, 1, 1, 1, 1, 1, 1},      // 1   - 0
  {1, 1, 1, 1, 1, 1, 1},      // 1^2 - 1
  {1, 1, 1, 1, 1, 1, 1},      // 2   - 2
  {1, 1, 1, 1, 1, 1, 1},      // 2^3 - 3
  {1, 1, 1, 1, 1, 1, 1},      // 3   - 4  -----
  {1, 1, 1, 1, 1, 1, 1},      // 3^4 - 5
  {1, 1, 1, 1, 1, 1, 1},      // 4   - 6
  {1, 1, 1, 1, 1, 1, 1},      // 4^5 - 7
  {1, 1, 1, 1, 1, 1, 1},      // 5   - 8
// |  |  |  |  |  |  |  
// 0  1  2  3  4  5  6
};
byte ms[50]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     
// "ключ" пути обратно
byte ms_2[50] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     
// "ключ" пути туда

int i1 = 0;
int i2 = 0;

// mas[7] = x
// mas[8] = y

void setup()      {
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);  
  pinMode(4, OUTPUT);
  Serial.begin (112500);
  //test2();
  //------------------------------------------------------------------------------
  while ((digitalRead(2)) == 1) { delay(10); }
  ZUM();
  //test();
  delay (600);
  linia();
  linia();
  linia();
  L();
  linia();
  linia();
  R();
  R();
  linia();
  linia();
  R();
  linia();
  //linia();
  //test2();
  //start();
  ZUM();
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
  digitalWrite(DR, HIGH );
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
  if ((mas[7]==6) && (mas[8]==1)) {
    ZUM();
  }
}

void test2()      {
  Serial.println("TEST:");
  mas[7] = 3;  // x
  mas[8] = 4;  // y
  navigator();
  Serial.println("NAVIGATOR_COMPLETE");
  Serial.println("ms:");
  while ((i < 50) && (ms[i] > 0)) {
    Serial.print(ms[i]);
    i++;
  }
  i = 0;
  Serial.println("");
  Serial.println("ms2:");
  while ((i < 50) && (ms_2[i] > 0)) {
    Serial.print(ms_2[i]);
    i++;
  }
  Serial.println("");
  Serial.println("TEST_COMPLETE");
}

void start()      {
  strich_cod();
  /*mas[0] = 0;
  mas[1] = 1;
  mas[2] = 0;
  mas[3] = 0;
  mas[4] = 0;
  mas[5] = 1;
  mas[6] = 0;
  mas[7] = 5;  // 3
  mas[8] = 2;  // 4*/
  linia(); 
  // а3
  navigator();
  while (a == 0) {
    if (ms_2[i] == 0) { a = 1;   }
    if (ms_2[i] == 1) { linia(); }
    if (ms_2[i] == 2) { L();     }
    if (ms_2[i] == 3) { R();     }
    i++;
  }
  i = 0;
  a = 0;
  L();
  L();
  ZUM();
  delay(1500);
  ZUM();
  while (a == 0) {
    if (ms[i] == 0) { a = 1;   }
    if (ms[i] == 1) { linia(); }
    if (ms[i] == 2) { L();     }
    if (ms[i] == 3) { R();     }
    i++;
  }
  i = 0;
  a = 0;
  // а3
  linia();
  cod();
}

void navigator()  {
  //ZUM();
  //delay (500);
  //mas[7] = x;
  //mas[8] = y;
  x = mas[7] - 1;
  y = mas[8];
  while (i < 50) {
    if ((x == 0) && (y == 3)) {
      i = 55;  //  добрался
    }
    else {  
      if (y == 3) { D_V();   }  // вперед
      if (y == 2) { D_R_1(); }  // вправо 1
      if (y == 1) { D_R_2(); }  // вправо 2
      if (y == 4) { D_L_1(); }  // влево 1
      if (y == 5) { D_L_2(); }  // влево 2
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
  /*
  i = 0;
  a = 0;
  while (ms_2[i] > 0) { i++; }
  ms_2[i] = 2; i++;
  ms_2[i] = 2;
  */
  i = 0;
  a = 0;
  //delay (500);
  //ZUM();
  Serial.println("ms2_COMPLETE");
  Serial.println("navigator_COMPLETE");
}

void D_V()        {
  if ((!(b == 4)) && (((x == 1) && (pr[4][0] == 1)) || ((x > 1) && (pr[4][x-1] == 1) && ((pr[4][x-2] == 1) || (pr[3][x-1]) || (pr[5][x-1]))))) { v(); }
  else {
    if ((!(b == 3)) && ((pr[5][x] == 1) && ((pr[6][x-1] == 1) || (pr[6][x] == 1) || (pr[7][x])))) { l(); }
    else {
      if ((!(b == 2)) && (((pr[3][x] == 1) && ((pr[2][x-1] == 1) || (pr[2][x] == 1) || (pr[1][x]))))) { r(); }
      else { n(); }
    }
  }
}

void D_R_1()      {  
  if ((!(b == 3)) && (((pr[3][x] == 1) && (x == 0)) || ((x > 0) && (pr[3][x] == 1) && ((pr[4][x-1] == 1) || (pr[4][x] == 1) || (pr[5][x] == 1))))) { l(); }
  else {
    if ((!(b == 4)) && ((x > 0) && (pr[2][x-1] == 1) && (((x > 1) && ((pr[3][x-1] == 1) || (pr[1][x-1] == 1) || (pr[2][x-2] == 1))) || ((x == 1) && ((pr[3][0] == 1) || (pr[1][0] == 1)))))) { v(); }
    else {
      if ((!(b == 2)) && ((pr[1][x] == 1) && (((x > 0) && (pr[0][x-1] == 1)) || (pr[0][x] == 1)))) { r(); }
      else { n(); }
    }
  }
}

void D_R_2()      {  
  if ((!(b == 3)) && (((pr[1][0] == 1) && (x == 0) && ((pr[3][0] == 1) || (pr[2][0] == 1))) || ((x > 0) && (pr[1][x] == 1) && ((pr[2][x-1] == 1) || (pr[2][x] == 1) || (pr[3][x] == 1)))))  { l(); }
  else {
    if ((!(b == 4)) && ((x > 0) && (pr[0][x-1] == 1) && ((pr[1][x-1] == 1) || ((pr[0][x-2] == 1) && (x > 1))))) { v(); }
    else {
      n();
    }
  }
}

void D_L_1()      {
  if ((!(b == 2)) && (((pr[5][0] == 1) && (x == 0)) || ((x > 0) && (pr[5][x] == 1) && ((pr[4][x-1] == 1) || (pr[4][x] == 1) || (pr[3][x] == 1))))) { r(); }
  else {
    if ((!(b == 4)) && ((x > 0) && (pr[6][x-1] == 1) && (((x > 1) && ((pr[5][x-1] == 1) || (pr[7][x-1] == 1) || (pr[6][x-2] == 1))) || ((x == 1) && ((pr[5][0] == 1) || (pr[7][0] == 1)))))) { v(); }
    else {
      if ((!(b == 3)) && ((pr[7][x] == 1) && (((x > 0) && (pr[8][x-1] == 1)) || (pr[8][x] == 1)))) { l(); }
      else { n(); }
    }
  }
}

void D_L_2()      {
  if ((!(b == 2)) && (((pr[7][0] == 1) && (x == 0) && ((pr[5][0] == 1) || (pr[6][0] == 1))) || ((x > 0) && (pr[7][x] == 1) && ((pr[6][x-1] == 1) || (pr[6][x] == 1) || (pr[5][x] == 1)))))  { r(); }
  else {
    if ((!(b == 4)) && ((x > 0) && (pr[8][x-1] == 1) && ((pr[7][x-1] == 1) || ((pr[8][x-2] == 1) && (x > 1))))) { v(); }
    else {
      n();
    }
  }
}

void cod()        {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 100);
  i = 10;
  a = 7;
  while (a > 0) {
    a--;
    if (mas[a] == 1) { a = 0; }
    else { i--; }
  }
  delay (i*100);
  delay (700);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
}

void v()          {
  ms[i] = 1; i++;
  b = 1;
  x--;
}

void l()          {
  ms[i] = 2; i++;
  ms[i] = 1; i++;
  ms[i] = 3; i++;
  b = 2;
  y++;
}

void r()          {
  ms[i] = 3; i++;
  ms[i] = 1; i++;
  ms[i] = 2; i++;
  b = 3;
  y--;
}

void n()          {
  ms[i] = 2; i++;
  ms[i] = 2; i++;
  ms[i] = 1; i++;
  ms[i] = 2; i++;
  ms[i] = 2; i++;
  b = 4;
  x++;
}

void L()          {
  digitalWrite(DL, LOW );
  analogWrite(SL, 255);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 255);
  while ((analogRead(A1)) < 800) { }
  while ((analogRead(A1)) > 800) { }
  while ((analogRead(A1)) < 800) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
}

void R()          {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 255);
  digitalWrite(DR, LOW );
  analogWrite(SR, 255);
  while ((analogRead(A2)) < 800) { }
  while ((analogRead(A2)) > 800) { }
  while ((analogRead(A2)) < 800) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
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

void linia()      {
  while ((i1 > 800) || (i2 > 800)) {
    linia2();
  }
  while (i < 800) {
    linia2();
    i++;
    delay(1);
  }
  i = 0;
  delay(50);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
}

void linia2()     {
  i1 = analogRead(A1);
  i2 = analogRead(A2);
  if ((i1 < 800) && (i2 < 800)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 255);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 > 800) && (i2 > 800)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 255);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 < 800) && (i2 > 800)) {
    digitalWrite(DL, LOW );
    analogWrite(SL, 255);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 > 800) && (i2 < 800)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 255);
    digitalWrite(DR, LOW );
    analogWrite(SR, 255);
  }
}

void strich_cod() {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 40);
      digitalWrite(DR, HIGH );
      analogWrite(SR, 40);
    }
    if (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, LOW );
      analogWrite(SL, 50);
      digitalWrite(DR, HIGH );
      analogWrite(SR, 50);
    }
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 50);
      digitalWrite(DR, LOW );
      analogWrite(SR, 50);
    }
  }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 40);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 40);
  while ((analogRead(A1)) < 600) { }
  while ((analogRead(A1)) > 600) { }
  i = -1;
  while (i < 7) {
    while ((analogRead(A0)) > 400) { }
    if (((analogRead(A1)) < 600) && (i > -1)) { mas[i] = 1; }
    while ((analogRead(A0)) < 600) { }
    i++;
  }
  i = 0;
  delay (100);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
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
}

