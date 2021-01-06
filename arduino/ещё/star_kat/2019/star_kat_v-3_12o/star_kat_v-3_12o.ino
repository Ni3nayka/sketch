#define SR     11
#define DR     13
#define SL     10
#define DL     12

int e1 = 0;
int e2 = 0;
int k  = 0;
int e  = 0;

byte mas[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 
int i = 0;
int a = 0;
int c = 0;
byte b = 0; 
byte x = 0; 
byte x1= 1;
byte y = 3; 
int ml = 0;
int mr = 0;
int mv = 0;
byte pr[9][7] {             
  {1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 1, 1, 1},    
  {1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 1, 1, 1},   
  {1, 1, 1, 1, 1, 1, 1},    
  {1, 1, 1, 1, 1, 1, 1},    
  {1, 1, 1, 1, 1, 1, 1},      
  {1, 1, 1, 1, 1, 1, 1},      
  {1, 1, 1, 1, 1, 1, 1},  
};
byte ms[50]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     
byte ms_2[50] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     

int i1 = 0;
int i2 = 0;

void setup()      {
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);  
  pinMode(4, OUTPUT);
  //------------------------------------------------------------------------------
  while ((digitalRead(2)) == 1) { delay(10); }
  ZUM();
  delay (600);
  start();
}

void loop()       {
  
}

void start()      {
  strich_cod();
  linia(); 
  navigator();
  a = 0;
  i = 0;
  while (a == 0) {
    if (ms_2[i] == 0) { a = 1;   }
    if (ms_2[i] == 1) { linia(); }
    if (ms_2[i] == 2) { L();     }
    if (ms_2[i] == 3) { R();     }
    i++;
  }
  i = 0;
  a = 0;
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
  linia();
  cod();
}

void navigator()  {
  x = mas[7] - 1;
  y = mas[8];
  while (i < 50) {
    if ((x == 0) && (y == 3)) {
      i = 55;  
    }
    else {  
      if (y == 3) { D_V();   } 
      if (y == 2) { D_R_1(); }  
      if (y == 1) { D_R_2(); } 
      if (y == 4) { D_L_1(); } 
      if (y == 5) { D_L_2(); }  
    }
  }
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
  RUN();
  i = 0;
  a = 0;
}

void RUN()        {
  x1 = mas[7];
  x = mas[7] - 1;
  y = mas[8];
  i = 0;
  if (x1 == 1) { mas[7] = 7; }
  if (x1 == 2) { mas[7] = 6; }
  if (x1 == 3) { mas[7] = 5; }
  if (x1 == 5) { mas[7] = 3; }
  if (x1 == 6) { mas[7] = 2; }
  if (x1 == 7) { mas[7] = 1; }
  mas[7] = mas[7] - 1;
  if (y == 1)  { mas[8] = 5; }
  if (y == 2)  { mas[8] = 4; }
  if (y == 4)  { mas[8] = 2; }
  if (y == 5)  { mas[8] = 1; }
  while (ms[i] > 0) {
    ms[i] = 0;
    i++;
  }
  i = 0;
  b = 0;
  if (x < mas[7]) {
    while (x < mas[7]) { naz(); }
    raz();
  }
  else {
    raz();
    while (x > mas[7]) { v(); }
  }
  if (y > mas[8]) {
    while (y > mas[8]) { r(); }
  }
  else {
    while (y < mas[8]) { l(); }
  }
  while (x > 0) { v(); }
  while (y > 3) { r(); }
  while (y < 3) { l(); }
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
  if ((!(b == 3)) && (!(((pr[2][x-1] == 1) && (pr[3][x-1] == 1) && (pr[4][x-3] == 1) && (x > 1)) || ((pr[2][x-1] == 1) && (pr[3][x-1] == 1) && (pr[5][x-1] == 1)))) && (((pr[3][x] == 1) && (x == 0)) || ((x > 0) && (pr[3][x] == 1) && ((pr[4][x-1] == 1) || (pr[4][x] == 1) || (pr[5][x] == 1))))) { l(); }
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
  if ((!(b == 2)) && (!(((pr[6][x-1] == 1) && (pr[5][x-1] == 1) && (pr[4][x-3] == 1) && (x > 1)) || ((pr[6][x-1] == 1) && (pr[5][x-1] == 1) && (pr[3][x-1] == 1)))) && (((pr[5][0] == 1) && (x == 0)) || ((x > 0) && (pr[5][x] == 1) && ((pr[4][x-1] == 1) || (pr[4][x] == 1) || (pr[3][x] == 1))))) { r(); }
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
  analogWrite(SL, 180);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 255);
  i = 10;
  a = 7;
  while (a > 0) {
    a--;
    if (mas[a] == 1) { a = 0; }
    else { i--; }
  }
  e = 0;
  a = 0;
  while (i*k >= e) {
    ekonder();
  }
  ZUM();
  delay(3200);
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

void raz()        {
  ms[i] = 2; i++;
  ms[i] = 2; i++;
  b = 1;
}

void naz()        {
  ms[i] = 1; i++;
  x++;
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
  delay(200);
  while ((analogRead(A1)) < 900) { }
  while ((analogRead(A1)) > 900) { }
  while ((analogRead(A1)) < 900) { }
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
  delay(200);
  while ((analogRead(A2)) < 900) { }
  while ((analogRead(A2)) > 900) { }
  while ((analogRead(A2)) < 900) { }
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
  linia2();
  while ((i1 > 900) || (i2 > 900)) {
    linia2();
  }
  while (c < 900) {
    linia2();
    c++;
    delay(1);
  }
  c = 0;
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
  i1 = 0;
  i2 = 0;
}

void linia2()     {
  i1 = analogRead(A1);
  i2 = analogRead(A2);
  if ((i1 < 900) && (i2 < 900)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 200);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 > 900) && (i2 > 900)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 200);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 < 900) && (i2 > 900)) {
    digitalWrite(DL, LOW );
    analogWrite(SL, 255);
    digitalWrite(DR, HIGH );
    analogWrite(SR, 255);
  }
  if ((i1 > 900) && (i2 < 900)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 255);
    digitalWrite(DR, LOW );
    analogWrite(SR, 255);
  }
}

void strich_cod() {
  linia2();
  while ((i1 > 800) || (i2 > 800)) {
    linia2();
  }
  i1 = 0;
  i2 = 0;
  k = 16;
  digitalWrite(DL, HIGH );
  analogWrite(SL, 150);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 255);
  e = 0;
  while ((analogRead(A1)) < 800) {
    ekonder();
  }
  k = e;
  e = 0;
  while (e <= k/2) { ekonder(); }
  e = 0;
  //i = 0;
  while (i <= 8) {
    ekonder();
    if (e >= k) { i++; e = 0; i1 = analogRead(A1); i2 = 1; }
    if ((i >= 2) && (i1 < 500) && (i2 == 1)) { mas[i-2] = 1; i2 = 0; }
  }
  i1 = 0;
  i2 = 0;
  i = 0;
  delay(500);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 0);
  i = (mas[6]*64)+(mas[5]*32)+(mas[4]*16)+(mas[3]*8)+(mas[2]*4)+(mas[1]*2)+mas[0];
  while (i >= 10) {
    i = i - 10;
    mas[7]++;
  }
  mas[8] = i;
  i = 0;
  if ((mas[7]==6) && (mas[8]==4)) { ZUM(); }
}

void ekonder()    {
  if (((analogRead(A5)) > 1000) && (e1 == 0)) {
    e++;
    e1++;
  }
  if (((analogRead(A5)) < 1000) && (e1 == 1)) {
    e1--;
  }
  if (((analogRead(A4)) > 1000) && (e2 == 0)) {
    e++;
    e2++;
  }
  if (((analogRead(A4)) < 1000) && (e2 == 1)) {
    e2--;
  }
}
