#define SR     11
#define DR     13
#define SL     10
#define DL     12

byte dor[208][2];  // из, в
byte ver[32][4];   // №, x, y, посещена ли

float M = 50;
float p = 0;
float A = 0; // какая локация
int   a, b, c, d, e, f, g, h, i, j, x, y, z, in0, in1, in2, in3, in4; 
int n = 1;   // направление
long int k = 0;

void setup() {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (4 , OUTPUT);
  pinMode (DR, OUTPUT);
  pinMode (DL, OUTPUT);
  //zum();
  while (digitalRead(2) == 1) { delay(10); }
  //zum();
  delay(500);
  //linia();
  linia(); V(); linia(); R(); linia(); R(); linia(); 
  //linia(); R();
  //L(); linia(); L(); linia(); R(); linia(); L(); linia(); R();
}

/*void start() {
  x = 0; y = 0; b = 1;
  i = 1; j = 2; g = 0;
  V[0][0] = i;
  while (f == 0) {
    f = 0;
    linia();
    if (b == 1) { x++; }
    if (b == 2) { y++; }
    if (b == 3) { x--; }
    if (b == 4) { y--; }
    while (!((V[g][1] == x) && (v[g][2] == y))) { g++; } V[g][2] = 1; // отметили, что были в точке x;y
    //------------------------- отмечаем новые возможные координаты
    if (A = 3.1) { // слева что то есть
      if (b == 1) { 
        i++;
        V[i][0] = x;
        V[i][1] = y + 1;
        E[i][0] = g;
        E[i][1] = j; j++;
      }
      
    }
    
    //-----------------------
    //i++;
    // повека на наличие неразведанных клеток
    //if (V[0][3] == 0) { f++; }
    while (V[g][0] > 0) {
      if (V[g][3] == 0) { f++; }
      g++;
    }
    g = 0;
    if (f == 0) { f++; }
    else { f = 0; }
  }
}*/

void start() {
  int napr = 1;
  int nov = 2;
  ver[0][0] = 1; // обозначили стартовую локацию №1
  ver[1][0] = 2; ver[1][1] = 1; ver[1][2] = 0; // обозначили вторую(переднюю локацию) 
  while (f == 0) {
    linia();      // проехал до локации
    a = A;
    while (a >= 0) {  //учитываем прямые участки пути
      if (napr == 1) { x++; }  // определил координату
      if (napr == 2) { y++; }
      if (napr == 3) { x--; }
      if (napr == 4) { y--; }
      a--;
    }
    while ((ver[i][1] == x) && (ver[i][2])) { i++; } // ищем точку с такой-же координатой
    ver[i][3] = 1;   // отмечаем, что были в ней
    // определил соседние локации
    if (napr == 1) {
       
    }
    
    // проверить на "все ли обследованны"
    // определить, куда ехать дальше если !(f == 0) и при надобности повернуть 
  }
}

void loop() {
  //process(); test_d2();
  //test_d();
  //test_e();
  //linia();
}

void linia() {
  a = 0;
  while ((((analogRead(A1) > 350) && (analogRead(A4) > 350))) && (((analogRead(A2) < 850) || (analogRead(A3) < 850))) && (analogRead(A0) < 800)) {
    e = (map((analogRead(A3)), 729, 985, 0, M) - map((analogRead(A2)), 650, 972, 0, M));
    digitalWrite(DL, 1);
    analogWrite (SL, M - e);
    digitalWrite(DR, 1);
    analogWrite (SR, M + e);
    k++;
    delay(1);
  }
  digitalWrite(DL, 0);
  analogWrite (SL, 50);
  digitalWrite(DR, 0);
  analogWrite (SR, 50);
  delay(10);
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
  a = (k + 400)/1000 - 1;
  if (a < 0) { a = 0; }
  Serial.println("-----------");
  Serial.println(a);
  k = 0;
  //-------------------------------------------------- проехали по линии до какого-то элемента
  process();
  test_d2();
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
  if ((in1 == 0) && (in4 == 0) && (in0 == 0))                             { A = 4;   }
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 1) && (in0 == 0)) { A = 3.2; }
  if ((in1 == 1) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 0)) { A = 3.1; }
  if ((in1 == 0) && (in2 == 1) && (in3 == 1) && (in4 == 0) && (in0 == 1)) { A = 1;   }
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

void V() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  while ((analogRead(A1) < 570) || (analogRead(A3) < 825)) {} 
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void L() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  delay(650);
  digitalWrite(DL, 0);
  analogWrite (SL, 60);
  digitalWrite(DR, 1);
  analogWrite (SR, 60);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
}

void R() {
  digitalWrite(DL, 1);
  analogWrite (SL, 50);
  digitalWrite(DR, 1);
  analogWrite (SR, 50);
  delay(650);
  digitalWrite(DL, 1);
  analogWrite (SL, 60);
  digitalWrite(DR, 0);
  analogWrite (SR, 60);
  while (analogRead(A0) <= 725) {}
  while (analogRead(A0) >= 725) {}
  digitalWrite(DL, 1);
  analogWrite (SL, 0);
  digitalWrite(DR, 1);
  analogWrite (SR, 0);
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
  e = (map((analogRead(A3)), 729, 985, 0, 50) - map((analogRead(A2)), 650, 972, 0, 50));
  Serial.println(e);
  delay(100);
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


