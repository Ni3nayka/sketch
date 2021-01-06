#define ras 8 // n + 1 кол-во точек + 1

byte dor[ras][ras] { // матрица смежностей
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 9, 0, 9, 0, 0},
  {0, 0, 9, 0, 1, 0, 1, 0},
  {0, 0, 0, 1, 0, 0, 1, 0},
  {0, 1, 9, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 0, 2},
  {0, 0, 0, 0, 0, 1, 2, 0},
};

byte mas[ras] = {0}; // сколько добраться до кажной точки

byte move[ras];

int t_start = 5;
int t_finish = 4;

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
        if ((dor[perebor_1][perebor_2] > 0) && (mas[perebor_1] + dor[perebor_1][perebor_2] < mas[perebor_2])) {
          mas[perebor_2] = mas[perebor_1] + dor[perebor_1][perebor_2];
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
      if ((dor[t_nast][perebor] > 0) && (mas[t_nast] - dor[t_nast][perebor] == mas[perebor])) gg = 0;
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
  
}





















