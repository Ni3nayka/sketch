#define SR     11
#define DR     13
#define SL     10
#define DL     12
#define M      125
#include <Servo.h>
Servo S;
//float p = 0;
float A = 0; // какая локация
int  a, b, c, d, e, f, g, h, i, j, x, y, z; 
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

void vibros() {
  S.write(70);
  delay(500);
  S.write(17);
  delay(1000);
}

void V() {
  digitalWrite(DL, 1);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  while ((analogRead(A1) < 570) || (analogRead(A3) < 825)) {} 
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void L() {
  digitalWrite(DL, 1);
  analogWrite (SL, M);
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  delay(650);
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
  digitalWrite(DR, 1);
  analogWrite (SR, M);
  delay(650);
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
          ver[j][0] = j; 
          ver[j][1] = x + 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y + 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x - 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y - 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      newt = 0;
}

void AL() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y - 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x + 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y + 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x - 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      newt = 0;
}

void AR() {
      if (napr == 1) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y + 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y + 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 2) {  
        while ((!((ver[newt][1] == x - 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x - 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 3) {  
        while ((!((ver[newt][1] == x) && (ver[newt][2] == y - 1))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x;
          ver[j][2] = y - 1;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      if (napr == 4) {  
        while ((!((ver[newt][1] == x + 1) && (ver[newt][2] == y))) && (newt < 35)) { newt++; } // ищем точку с нужной координатой
        if (newt > 33) { // небыло такой точки раньше
          ver[j][0] = j; 
          ver[j][1] = x + 1;
          ver[j][2] = y;
          dor[myt][j] = 1;
          dor[j][myt] = 1;
          j++;
        }
        else {         // была такая точка раньше
          dor[myt][newt] = 1;
          dor[newt][myt] = 1;
        }
      }
      newt = 0;
}

