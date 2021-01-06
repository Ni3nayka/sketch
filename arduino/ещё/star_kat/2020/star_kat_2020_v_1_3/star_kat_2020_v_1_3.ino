#define ras 36 // n + 1 кол-во точек + 1

byte dor[ras*4][3] { // (point_1, point_2, dor between) матрица смежностей => dis 
  {0, 0, 0}, // no
  {1, 2, 1},
  {2, 1, 1},
  {2, 3, 1},
  {3, 2, 1},
  {3, 4, 1},
  {4, 3, 1},
  {4, 5, 1},
  {5, 4, 1},
  {5, 6, 1},
  {6, 5, 1},
  {6, 7, 1},
  {7, 6, 1},
  {8, 9, 1},
  {9, 8, 1},
  {9, 10, 1},
  {10, 9, 1},
  {10, 11, 1},
  {11, 10, 1},
  {11, 12, 1},
  {12, 11, 1},
  {12, 13, 1},
  {13, 12, 1},
  {13, 14, 1},
  {14, 13, 1},
  {15, 16, 1},
  {16, 15, 1},
  {16, 17, 1},
  {17, 16, 1},
  {17, 18, 1},
  {18, 17, 1},
  {18, 19, 1},
  {19, 18, 1},
  {19, 20, 1},
  {20, 19, 1},
  {20, 21, 1},
  {21, 20, 1},
  {22, 23, 1},
  {23, 22, 1},
  {23, 24, 1},
  {24, 23, 1},
  {25, 24, 1},
  {24, 25, 1},
  {26, 25, 1},
  {25, 26, 1},
  {26, 27, 1},
  {27, 26, 1},
  {27, 28, 1},
  {28, 27, 1},
  {29, 30, 1},
  {30, 29, 1},
  {30, 31, 1},
  {31, 30, 1},
  {31, 32, 1},
  {32, 31, 1},
  {32, 33, 1},
  {33, 32, 1},
  {33, 34, 1},
  {33, 34, 1},
  {34, 35, 1},
  {35, 34, 1}, // ================================
  {1, 8, 1},
  {8, 1, 1},
  {2, 9, 1},
  {9, 2, 1},
  {3, 10, 1},
  {10, 3, 1},
  {4, 11, 1},
  {11, 4, 1},
  {5, 12, 1},
  {12, 5, 1},
  {6, 13, 1},
  {13, 6, 1},
  {7, 14, 1},
  {14, 7, 1},
  {8, 15, 1},
  {15, 8, 1},
  {9, 16, 1},
  {16, 9, 1},
  {10, 17, 1},
  {17, 10, 1},
  {11, 18, 1},
  {18, 11, 1},
  {12, 19, 1},
  {19, 12, 1},
  {13, 20, 1},
  {20, 13, 1},
  {14, 21, 1},
  {21, 14, 1},
  {15, 22, 1},
  {22, 15, 1},
  {16, 23, 1},
  {23, 16, 1},
  {17, 24, 1},
  {24, 17, 1},
  {18, 25, 1},
  {25, 18, 1},
  {19, 26, 1},
  {26, 19, 1},
  {20, 27, 1},
  {27, 20, 1},
  {21, 28, 1},
  {28, 21, 1},
  {22, 29, 1},
  {29, 22, 1},
  {23, 30, 1},
  {30, 23, 1},
  {24, 31, 1},
  {31, 24, 1},
  {25, 32, 1},
  {32, 25, 1},
  {26, 33, 1},
  {33, 26, 1},
  {27, 34, 1},
  {34, 27, 1},
  {28, 35, 1},
  {35, 28, 1},
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

int t_start = 3;
int t_finish = 1;

byte NAPR = 3; // 1 - left, 2 - up, 3 - right, 4 - down

#define SR     11
#define DR     13
#define SL     10
#define DL     12

#define M  150

#define min_1 330
#define max_1 980
#define min_2 360
#define max_2 980

int in1, in2;

int coo = 0; // записываем координату, считанную со штрих-кода

bool enkoder_2, enkoder_3, enkoder_4, enkoder_5;
long int E1 = 0;
long int E2 = 0;

unsigned long int time = 0;


void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(4, OUTPUT);
  //deikstra();
  //while (digitalRead(2));
  //linia();
  //motor(1, 255);
  //motor(2, 255);
}

void loop() {
  if (!digitalRead(2)) {
    stich_cod();
    //linia();
    //L();
    //linia();
    //R();
    //linia();
  }
  //test();
  /*enkoder();
  if (millis() > time + 1000) {
    Serial.println(E1);
    time = millis();
  }*/
}

void algoritm() {
  zum();
  delay(500);
  stich_cod();
  t_finish = coo;
  deikstra();
  int i;
  while (way[i] > 0) {
    if (way[i] == 1) linia();
    if (way[i] == 2) L();
    if (way[i] == 3) R();
    i++;
  }
  L(); L(); zum(); delay(1000);
  while (i > 0) {
    if (way[i] == 1) linia();
    if (way[i] == 3) L();
    if (way[i] == 2) R();
    i--;
  }
  linia();
  motor(1, M);
  motor(2, M*1.1);
  delay(4000);
  motor(1, 0);
  motor(2, 0);
  zum();
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
  motor(2, M*1.1);
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
  while (millis() < time + 1200) pid(); 
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

void enkoder() {
  //enkoder_2, enkoder_3, enkoder_4, enkoder_5;
  /*Serial.print(analogRead(A2)); Serial.print(" ");
  Serial.print(analogRead(A3)); Serial.print(" ");
  Serial.print(analogRead(A4)); Serial.print(" ");
  Serial.print(analogRead(A5)); Serial.print(" ");
  Serial.println();*/
  bool a2 = 0, a3 = 0, a4 = 0, a5 = 0;
  if (analogRead(A2) > 1000) a2 = 1;
  if (analogRead(A3) > 1000) a3 = 1;
  if (analogRead(A4) > 1000) a4 = 1;
  if (analogRead(A5) > 1000) a5 = 1;
  
  if ((enkoder_2 == 1) && (a2 == 0) && (a3 == 1)) E1++; //  && (enkoder_3 == 1)
  //if ((enkoder_2 == 0) && (a2 == 0) && (enkoder_3 == 1) && (a3 == 0)) E1++;
  //if ((enkoder_2 == 0) && (a2 == 1) && (enkoder_3 == 0) && (a3 == 0)) E1++;
  //if ((enkoder_2 == 1) && (a2 == 1) && (enkoder_3 == 0) && (a3 == 1)) E1++; 

  enkoder_2 = a2;
  enkoder_3 = a3;
  enkoder_4 = a4; 
  enkoder_5 = a5;
  
  //delay(1);
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
