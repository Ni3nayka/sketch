#define ras 36 // n + 1 кол-во точек + 1

byte dor[ras*4][3] { // (point_1, point_2, dor between) матрица смежностей => dis 
  {0, 0, 0}, // no
  {1, 2, 16},
  {2, 1, 16},
  {2, 3, 28},
  {3, 2, 28},
  {3, 4, 27},
  {4, 3, 27},
  {4, 5, 3},
  {5, 4, 3},
  {5, 6, 8},
  {6, 5, 8},
  {6, 7, 8},
  {7, 6, 8},
  {8, 9, 4},
  {9, 8, 4},
  {9, 10, 22},
  {10, 9, 22},
  {10, 11, 22},
  {11, 10, 22},
  {11, 12, 3},
  {12, 11, 3},
  {12, 13, 19},
  {13, 12, 19},
  {13, 14, 2},
  {14, 13, 2},
  {15, 16, 22},
  {16, 15, 22},
  {16, 17, 7},
  {17, 16, 7},
  {17, 18, 10},
  {18, 17, 10},
  {18, 19, 16},
  {19, 18, 16},
  {19, 20, 22},
  {20, 19, 22},
  {20, 21, 13},
  {21, 20, 13},
  {22, 23, 20},
  {23, 22, 20},
  {23, 24, 7},
  {24, 23, 7},
  {25, 24, 30},
  {24, 25, 30},
  {26, 25, 5},
  {25, 26, 5},
  {26, 27, 8},
  {27, 26, 8},
  {27, 28, 17},
  {28, 27, 17},
  {29, 30, 27},
  {30, 29, 27},
  {30, 31, 27},
  {31, 30, 27},
  {31, 32, 22},
  {32, 31, 22},
  {32, 33, 10},
  {33, 32, 10},
  {33, 34, 12},
  {33, 34, 12},
  {34, 35, 18},
  {35, 34, 18}, // ================================
  {1, 8, 3},
  {8, 1, 3},
  {2, 9, 16},
  {9, 2, 16},
  {3, 10, 15},
  {10, 3, 15},
  {4, 11, 2},
  {11, 4, 2},
  {5, 12, 23},
  {12, 5, 23},
  {6, 13, 18},
  {13, 6, 18},
  {7, 14, 9},
  {14, 7, 9},
  {8, 15, 21},
  {15, 8, 21},
  {9, 16, 20},
  {16, 9, 20},
  {10, 17, 1},
  {17, 10, 1},
  {11, 18, 30},
  {18, 11, 30},
  {12, 19, 25},
  {19, 12, 25},
  {13, 20, 18},
  {20, 13, 18},
  {14, 21, 10},
  {21, 14, 10},
  {15, 22, 23},
  {22, 15, 23},
  {16, 23, 27},
  {23, 16, 27},
  {17, 24, 16},
  {24, 17, 16},
  {18, 25, 14},
  {25, 18, 14},
  {19, 26, 1},
  {26, 19, 1},
  {20, 27, 11},
  {27, 20, 11},
  {21, 28, 19},
  {28, 21, 19},
  {22, 29, 21},
  {29, 22, 21},
  {23, 30, 17},
  {30, 23, 17},
  {24, 31, 10},
  {31, 24, 10},
  {25, 32, 26},
  {32, 25, 26},
  {26, 33, 5},
  {33, 26, 5},
  {27, 34, 1},
  {34, 27, 1},
  {28, 35, 3},
  {35, 28, 3},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
};

byte ver[ras][2] { // x, y
  {0, 0}, // no
  {1, 1},
  {2, 1},
  {3, 1},
  {4, 1},
  {5, 1},
  {6, 1},
  {7, 1},
  {1, 2},
  {2, 2},
  {3, 2},
  {4, 2},
  {5, 2},
  {6, 2},
  {7, 2},
  {1, 3},
  {2, 3},
  {3, 3},
  {4, 3},
  {5, 3},
  {6, 3},
  {7, 3},
  {1, 4},
  {2, 4},
  {3, 4},
  {4, 4},
  {5, 4},
  {6, 4},
  {7, 4},
  {1, 5},
  {2, 5},
  {3, 5},
  {4, 5},
  {5, 5},
  {6, 5},
  {7, 5},
};

byte mas[ras] = {0}; // сколько добраться до кажной точки

byte move[ras];

byte way[ras*3]; // путь: 1 - forward, 2 - left, 3 - right

int t_start = 15;
int t_finish = 1;

byte NAPR = 3; // 1 - left, 2 - up, 3 - right, 4 - down

#define SR     11
#define DR     13
#define SL     10
#define DL     12

#define M  250

#define min_1 390
#define max_1 980
#define min_2 330
#define max_2 980

int in1, in2;

int coo = 0; // записываем координату, считанную со штрих-кода

bool encoder_2 = 0, encoder_3 = 0, encoder_4 = 0, encoder_5 = 0;
long int E1 = 0;
long int E2 = 0;
bool a2 = 0, a3 = 0;

unsigned long int time = 0;


void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, INPUT);
  //encoder
  a2 = digitalRead(2);
  a3 = digitalRead(3);
  attachInterrupt(0, gerkon_1, CHANGE);
  attachInterrupt(1, gerkon_2, CHANGE);
  //pinMode(3, INPUT);
  //pinMode(5, INPUT);
  //pinMode(6, INPUT);
  //pinMode(7, INPUT);
  //coo = 34;
  //Serial.println(COO(coo));
}

void loop() {
  if (millis()%1000 == 0) {
    //Serial.print(E1); Serial.print(" "); Serial.println(E2);
    //Serial.println(E1);
    
  }
  Serial.println(E1);
  //test();
  //encoder();
  int EE = E1;
  if (abs(EE) > 100) EE = (EE/abs(EE))*100;
  //motor(2, -EE);
  if (!digitalRead(9)) {
    //algoritm();
    //linia();
     delay(1000); motor(1, 255); motor(2, 255); delay(3000); motor(1, 0); motor(2, 0);
  }
}

void algoritm() {
  zum();
  delay(500);
  stich_cod();
  coo = COO(coo);
  Serial.println(coo);
  t_finish = coo;
  //t_finish = 23;
  deikstra();
  linia();
  int i;
  while (way[i] > 0) {
    if (way[i] == 1) linia();
    if (way[i] == 2) L();
    if (way[i] == 3) R();
    i++;
  }
  L(); L(); zum(); delay(1000);
  while (i >= 0) {
    if (way[i] == 1) linia();
    if (way[i] == 3) L();
    if (way[i] == 2) R();
    i--;
  }
  //zum();
  linia();
  motor(1, M);
  motor(2, M*1.3);
  delay(7000);
  motor(1, 0);
  motor(2, 0);
  zum();
}

int COO(int abc) {
  int i = 1;
  int x = coo/10;
  int y = coo%10; 
  while ((i < ras) && ((ver[i][0] != x) || (ver[i][1] != y))) i++;
  Serial.println(x);
  Serial.println(y);
  return i;
}

void test() {
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
}

void dat() {
  in1 = map(analogRead(A0), min_1, max_1, 0, M);
  in2 = map(analogRead(A1), min_2, max_2, 0, M);
}

void stich_cod() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  time = millis();
  motor(1, M);
  motor(2, M*1.2);
  while (in1 <= M/2) dat();
  while (in1 >= M/2) dat();
  bool masv[7] = {0};
  unsigned int polosa = (millis() - time)/2; // *1.1
  delay(polosa*3/2);
  for(int i = 0; i < 7; i++) {
    Serial.println(analogRead(A0));
    if (analogRead(A0) < 700) masv[i] = 1; 
    delay(polosa);
  }
  //Serial.println(polosa);
  motor(1, 0);
  motor(2, 0);
  coo = (masv[6]*64)+(masv[5]*32)+(masv[4]*16)+(masv[3]*8)+(masv[2]*4)+(masv[1]*2)+masv[0];
  Serial.println(coo);
}

void linia() {
  dat();
  while ((in1 >= M/2) || (in2 >= M/2)) pid();
  time = millis();
  motor(1, -M);
  motor(2, -M);
  delay(60);
  //while (millis() < time + 1200) pid(); 
  motor(1, 0);
  motor(2, 0);
}

void L() {
  motor(1, -M);
  motor(2, M);
  dat();
  while(in1 <= M/2) dat();
  while(in1 >= M/2) dat();
  while(in1 <= M/2) dat();
  motor(1, 0);
  motor(2, 0);
}

void R() {
  motor(1, M);
  motor(2, -M);
  dat();
  while(in2 <= M/2) dat();
  while(in2 >= M/2) dat();
  while(in2 <= M/2) dat();
  motor(1, 0);
  motor(2, 0);
}

void pid() {
  dat();
  int e = in1 - in2;
  motor(1, M + e);
  motor(2, M - e);
}

void encoder2() {
  //enkoder_2, enkoder_3, enkoder_4, enkoder_5;
  //bool a2 = 0, a3 = 0, a4 = 0, a5 = 0;
  if (digitalRead(6)) a2 = 1;
  if (digitalRead(7)) a3 = 1;
  //if (digitalRead(3)) a4 = 1;
  //if (digitalRead(5)) a5 = 1;

  /*Serial.print(a2); Serial.print(" ");
  Serial.print(a3); Serial.print(" ");
  Serial.print(a4); Serial.print(" ");
  Serial.print(a5); Serial.print(" ");
  Serial.println();*/
  
  /*if (!encoder_3 &&  a3 && !encoder_2 && !a2) E1++;
  if ( encoder_3 &&  a3 && !encoder_2 &&  a2) E1++;
  if ( encoder_3 && !a3 &&  encoder_2 &&  a2) E1++;
  if (!encoder_3 && !a3 &&  encoder_2 && !a2) E1++;

  if (!encoder_2 &&  a2 && !encoder_3 && !a3) E1--;
  if ( encoder_2 &&  a2 && !encoder_3 &&  a3) E1--;
  if ( encoder_2 && !a2 &&  encoder_3 &&  a3) E1--;
  if (!encoder_2 && !a2 &&  encoder_3 && !a3) E1--;

  if (!encoder_5 &&  a5 && !encoder_4 && !a4) E2++;
  if ( encoder_5 &&  a5 && !encoder_4 &&  a4) E2++;
  if ( encoder_5 && !a5 &&  encoder_4 &&  a4) E2++;
  if (!encoder_5 && !a5 &&  encoder_4 && !a4) E2++;

  if (!encoder_4 &&  a4 && !encoder_5 && !a5) E2--;
  if ( encoder_4 &&  a4 && !encoder_5 &&  a5) E2--;
  if ( encoder_4 && !a4 &&  encoder_5 &&  a5) E2--;
  if (!encoder_4 && !a4 &&  encoder_5 && !a5) E2--;*/

  /*if ((!encoder_3 &&  a3 && !encoder_2 && !a2) || ( encoder_3 &&  a3 && !encoder_2 &&  a2) || ( encoder_3 && !a3 &&  encoder_2 &&  a2) || (!encoder_3 && !a3 &&  encoder_2 && !a2)) E1++;
  if ((!encoder_2 &&  a2 && !encoder_3 && !a3) || ( encoder_2 &&  a2 && !encoder_3 &&  a3) || ( encoder_2 && !a2 &&  encoder_3 &&  a3) || (!encoder_2 && !a2 &&  encoder_3 && !a3)) E1--;
  if ((!encoder_5 &&  a5 && !encoder_4 && !a4) || ( encoder_5 &&  a5 && !encoder_4 &&  a4) || ( encoder_5 && !a5 &&  encoder_4 &&  a4) || (!encoder_5 && !a5 &&  encoder_4 && !a4)) E2++;
  if ((!encoder_4 &&  a4 && !encoder_5 && !a5) || ( encoder_4 &&  a4 && !encoder_5 &&  a5) || ( encoder_4 && !a4 &&  encoder_5 &&  a5) || (!encoder_4 && !a4 &&  encoder_5 && !a5)) E2--;*/

  
  
  encoder_2 = a2;
  encoder_3 = a3;
  //encoder_4 = a4; 
  //encoder_5 = a5;

  Serial.println(E1);
  //delay(1);
}

void encoder() {
  if ((digitalRead(6))) a2 = 1; else a2 = 0; //  && (digitalRead(7))
  if ((digitalRead(3))) a3 = 1; else a3 = 0; //  && (digitalRead(5))

  if (!encoder_2 && a2) E1++;
  if (!encoder_3 && a3) E2++;
  
  encoder_2 = a2;
  encoder_3 = a3;

  //Serial.println(E1);
  //delay(1);
}

void gerkon_1() {
  if (a2) a2 = 0;
  else a2 = 1;
  
  if (!encoder_3 &&  a3 && !encoder_2 && !a2) E1++;
  if ( encoder_3 &&  a3 && !encoder_2 &&  a2) E1++;
  if ( encoder_3 && !a3 &&  encoder_2 &&  a2) E1++;
  if (!encoder_3 && !a3 &&  encoder_2 && !a2) E1++;

  if (!encoder_2 &&  a2 && !encoder_3 && !a3) E1--;
  if ( encoder_2 &&  a2 && !encoder_3 &&  a3) E1--;
  if ( encoder_2 && !a2 &&  encoder_3 &&  a3) E1--;
  if (!encoder_2 && !a2 &&  encoder_3 && !a3) E1--;

  encoder_2 = a2;
}

void gerkon_2() {
  if (a3) a3 = 0;
  else a3 = 1;
  
  if (!encoder_3 &&  a3 && !encoder_2 && !a2) E1++;
  if ( encoder_3 &&  a3 && !encoder_2 &&  a2) E1++;
  if ( encoder_3 && !a3 &&  encoder_2 &&  a2) E1++;
  if (!encoder_3 && !a3 &&  encoder_2 && !a2) E1++;

  if (!encoder_2 &&  a2 && !encoder_3 && !a3) E1--;
  if ( encoder_2 &&  a2 && !encoder_3 &&  a3) E1--;
  if ( encoder_2 && !a2 &&  encoder_3 &&  a3) E1--;
  if (!encoder_2 && !a2 &&  encoder_3 && !a3) E1--;

  encoder_3 = a3;
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

void motor(byte number, int speed) { 
  if      ((number == 1) && (speed > 0)) digitalWrite(DL, 1);
  else if ((number == 1) && (speed < 0)) digitalWrite(DL, 0);
  else if ((number == 2) && (speed > 0)) digitalWrite(DR, 1);
  else if ((number == 2) && (speed < 0)) digitalWrite(DR, 0);

  if (abs(speed) > 255) speed = (speed/abs(speed))*255;
  
  if      (number == 1) analogWrite(SL, abs(speed));
  else if (number == 2) analogWrite(SR, abs(speed));
}

void deikstra() {
  int i = 0;
  for(; i < ras; i++) mas[i] = 99;
  mas[t_start] = 0;
  bool gg;
  int perebor_1 = 1;
  int perebor_2 = 1;
  do {
    gg = 0;
    //============================
    //perebor_1 = 1;
    for (perebor_1 = 1; perebor_1 < ras; perebor_1++) {
      //perebor_2 = 1;
      for (perebor_2 = 1; perebor_2 < ras; perebor_2++) {
        if ((dis(perebor_1, perebor_2) > 0) && (mas[perebor_1] + dis(perebor_1, perebor_2) < mas[perebor_2])) {
          mas[perebor_2] = mas[perebor_1] + dis(perebor_1, perebor_2);
          gg = 1;
        }
      }
    }
    //============================
  } while (gg == 1);
  for(i = 1; i < ras; i++) { Serial.print(mas[i]); Serial.print(" "); } Serial.println();
  //gg = 1; // пока gg == 1 мы не на финише
  int t_nast = t_finish;
  int perebor = 1;
  move[1] = t_finish;
  for(i = 2; i < ras; i++) move[i] = 0;
  i = 2;
  while (t_nast != t_start) {
    perebor = 1;
    gg = 1;
    while (gg) {
      if ((dis(t_nast, perebor) > 0) && (mas[t_nast] - dis(t_nast, perebor) == mas[perebor])) gg = 0;
      else perebor++; 
    }
    move[i] = perebor;
    t_nast = perebor;
    i++;
  }
  for(i = 1; i < ras; i++) { Serial.print(move[i]); Serial.print(" "); } Serial.println();
  for(i = 1; move[i] > 0; i++); // считаем кол-во точек, в которых записан наш маршрут
  i--;
  //Serial.println(i);
  int a, i0 = 1; // i0 - счетчик сначала, i счетчик с конца
  if (i%2 == 0) {
    while (i - i0 >= 1) {
      a = move[i0];
      move[i0] = move[i];
      move[i] = a;
      i--;
      i0++;
    }
  }
  else {
    while (i - i0 >= 2) {
      a = move[i0];
      move[i0] = move[i];
      move[i] = a;
      i--;
      i0++;
    }
  }
  for(i = 1; i < ras; i++) { Serial.print(move[i]); Serial.print(" "); } Serial.println();
  Serial.println("==============");
  //============================================= my pyt
  byte napr = NAPR;
  //t_nast = t_start;
  for(i = 0; i < ras*3; i++) way[i] = 0;
  i = 1; // for move
  int ii = 0; // for way
  while (move[i] != t_finish) { 
    if      (((ver[move[i]][0] - 1 == ver[move[i+1]][0]) && (napr == 1)) || ((ver[move[i]][1] - 1 == ver[move[i+1]][1]) && (napr == 2)) || ((ver[move[i]][0] + 1 == ver[move[i+1]][0]) && (napr == 3)) || ((ver[move[i]][1] + 1 == ver[move[i+1]][1]) && (napr == 4))) {
      way[ii] = 1; 
      i++;
    }                                                    
    else if (((ver[move[i]][1] + 1 == ver[move[i+1]][1]) && (napr == 1)) || ((ver[move[i]][0] - 1 == ver[move[i+1]][0]) && (napr == 2)) || ((ver[move[i]][1] - 1 == ver[move[i+1]][1]) && (napr == 3)) || ((ver[move[i]][0] + 1 == ver[move[i+1]][0]) && (napr == 4))) {
      way[ii] = 2; 
      l(napr); 
    }                                                    
    else if (((ver[move[i]][1] - 1 == ver[move[i+1]][1]) && (napr == 1)) || ((ver[move[i]][0] + 1 == ver[move[i+1]][0]) && (napr == 2)) || ((ver[move[i]][1] + 1 == ver[move[i+1]][1]) && (napr == 3)) || ((ver[move[i]][0] - 1 == ver[move[i+1]][0]) && (napr == 4))) {
      way[ii] = 3; 
      r(napr); 
    }                                                     
    else { 
      way[ii] = 2;
      ii++;       
      way[ii] = 2;   
      l(napr);
      l(napr);                                          
    }
    ii++;
  }
  napr = NAPR;
  for(i = 0; i < ras*3; i++) { Serial.print(way[i]); Serial.print(" "); } Serial.println();
}

void l(byte& napr) {
  if (napr == 1) napr = 4;
  else napr--;
}

void r(byte& napr) {
  if (napr == 4) napr = 1;
  else napr++;
}

int dis(byte point_1, byte point_2) {
  int i = 1;
  while ((i < ras*4) && ((dor[i][0] != point_1) || (dor[i][1] != point_2))) i++;
  if (i == ras*4) return 99; 
  else return dor[i][2];
}
