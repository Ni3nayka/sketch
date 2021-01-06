#define ras 10

int mas[ras];

int i = 0;
int u = 0;
int b = 0;

void setup() {
  Serial.begin(9600);
  while (i < ras) {
    mas[i] = rand();
    i++;
  }
}

void loop() {
  i = 0; while (i < ras) { Serial.print(mas[i]); Serial.print(" "); i++; } Serial.println();
  i = ras-1;
  while (i > 0) {
    mas[i] = mas[i-1];
    i--;
  }
  i = 0; while (i < ras) { Serial.print(mas[i]); Serial.print(" "); i++; } Serial.println();
  mas[0] = rand();
  i = 0; while (i < ras) { Serial.print(mas[i]); Serial.print(" "); i++; } Serial.println();
  i = 0; u = 0;
  while (i < ras) {
    while (u < ras-1) {
      if (mas[u] > mas[u+1]) { b = mas[u]; mas[u] = mas[u+1]; mas[u+1] = b; }
      u++;
    }
    u = 0; i++;
  }
  i = 0; while (i < ras) { Serial.print(mas[i]); Serial.print(" "); i++; } Serial.println();
  Serial.println("========================================");
}
