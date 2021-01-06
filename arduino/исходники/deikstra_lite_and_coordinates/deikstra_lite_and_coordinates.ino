#define ras 10 // n + 1 кол-во точек + 1

byte dor[ras*4][3] { // (point_1, point_2, dor between) матрица смежностей => dis 
  {0, 0, 0}, // no
  {1, 2, 1},
  {2, 3, 1},
  {2, 1, 1},
  {3, 2, 1},
  {1, 4, 1},
  {4, 1, 1},
  {2, 5, 9},
  {5, 2, 9},
  {3, 6, 1},
  {6, 3, 1},
  {4, 5, 1},
  {5, 4, 1},
  {5, 8, 1},
  {8, 5, 1},
  {6, 9, 1},
  {9, 6, 1},
  {7, 8, 1},
  {8, 7, 1},
  {8, 9, 1},
  {9, 8, 1},
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
  {0, 0},
  {1, 0},
  {2, 0},
  {0, 1},
  {1, 1},
  {2, 1},
  {0, 2},
  {1, 2},
  {2, 2},
};

byte mas[ras] = {0}; // сколько добраться до кажной точки

byte move[ras];

byte way[ras*3]; // путь: 1 - forward, 2 - left, 3 - right

int t_start = 5;
int t_finish = 1;

byte NAPR = 3; // 1 - left, 2 - up, 3 - right, 4 - down

void setup() {
  Serial.begin(9600);
  deikstra();
}

void loop() {
  
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
    perebor_1 = 1;
    for (;perebor_1 < ras; perebor_1++) {
      perebor_2 = 1;
      for (;perebor_2 < ras; perebor_2++) {
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
  int i = 0;
  while ((dor[i][0] != point_1) || (dor[i][1] != point_2)) i++;
  return dor[i][2];
}
