int mas[] = {0, 0, 0, 0, 0, 0, 0};
int x = 0;
int y = 0;

void setup() {
  // кнопка
  linia();
  strich_cod();
  linia(); // если потребуется доехать до а3
  while (x > 0) {
    linia();
    x--;
  }
  if (y > 3) {
    p();
  }
  if (y < 3) {
    l();
  }
  while (y > 0) {
    linia();
    y--;
  }
  ostanovka();
  x = mas[0] - 1;
  y = mas[1] - 1;
  rasvorot();
  while (y > 0) {
    linia();
    y--;
  }
  if (y > 3) {
    p();
  }
  y = mas[1] - 1;
  if (y < 3) {
    l();
  }
  while (x > 0) {
    linia();
    x--;
  }
  // доехали до а3 
  // доехать до финиша (через щтрих-код)
}

void loop() {
  
}

void strich_cod() {
  // черная линия, а потом 7-бит
  // проехать вперед и считать код, записать в массив mas[]
  y = (mas[6]*64)+(mas[5]*32)+(mas[4]*16)+(mas[3]*8)+(mas[2]*4)+(mas[1]*2)+(mas[0]*1);
  while (y >= 10) {
    y = y - 10;
    x = x + 1;
  }
  int mas[] = {0, 0, 0, 0, 0, 0, 0};
  mas[0] = x;
  mas[1] = y;
  x = x - 1;
  y = y - 1;
}

