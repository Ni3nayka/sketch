#define SR     11
#define DR     13
#define SL     10
#define DL     12
#define M      80
//float p = 0;
float A = 0; // какая локация
int  a, b, c, d, e, f, g, h, i, j, x, y, z, flag, u, ff, uu, k1, k2; 
int   in0, in1, in2, in3, in4, D; 
int n = 1;   // направление
int k = 0;   // длинна дороги прямого участка пути
/*int min_2 = 670;
int min_3 = 750;
int max_2 = 950;
int max_3 = 950;*/
//int min_0 = 400;
int min_2 = 600;
int min_3 = 500;
//int max_0 = 700;
int max_2 = 900;
int max_3 = 900;
int a2   = 0;
int myt  = 0;
int newt = 0;
int napr = 1;
char rrr;


char ver[33][4] { // №, x, y, посещена ли
  {0, 0, 0, 0},
  {1, 0, 0, 0}, // обозначили стартовую локацию №1
  {2, 1, 0, 0}, // обозначили вторую (переднюю локацию)
  {3, 2, 0, 0},
  {4, 3, 0, 0},
  {5, 4, 0, 0},
  {6, 5, 0, 0},
  {7, 6, 0, 0},
  {8, 7, 0, 0},
  {9, 0, 0, 0},
  {10, 1, 1, 0},
  {11, 2, 1, 0},
  {12, 3, 1, 0},
  {13, 4, 1, 0},
  {14, 5, 1, 0},
  {15, 6, 1, 0},
  {16, 7, 1, 0},
  {17, 0, 2, 0},
  {18, 1, 2, 0},
  {19, 2, 2, 0},
  {20, 3, 2, 0},
  {21, 4, 2, 0},
  {22, 5, 2, 0},
  {23, 6, 2, 0},
  {24, 7, 2, 0},
  {25, 0, 3, 0},
  {26, 1, 3, 0},
  {27, 2, 3, 0},
  {28, 3, 3, 0},
  {29, 4, 3, 0},
  {30, 5, 3, 0},
  {31, 6, 3, 0},
  {32, 7, 3, 0},
};

void N() {
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
  if (napr == 1) { napr = 4; }
  else { napr--; }
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
  if (napr == 1) { napr = 4; }
  else { napr--; }
}

void V() {
  /*digitalWrite(DL, 1);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  while ((analogRead(A1) < 600) || (analogRead(A4) < 600)) {} 
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);*/
}

void L() {
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
  if (napr == 1) { napr = 4; }
  else { napr--; }
}

void R() {
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
  if (napr == 4) { napr = 1; }
  else { napr++; }
}

void v() {
  
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
  digitalWrite(4, 1);
  delay(100);
  digitalWrite(4, 0);
  delay(100);
  digitalWrite(4, 1);
  delay(100);
  digitalWrite(4, 0);
  delay(100);
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
