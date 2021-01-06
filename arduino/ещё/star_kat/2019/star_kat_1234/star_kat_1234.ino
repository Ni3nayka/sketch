#define SL     11
#define DL     13
#define SP     10
#define DP     12
//#define ZM      4

byte mas[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//byte mas[] = {0, 1, 0, 0, 0, 1, 1, 0, 0};
byte x = 0;
byte y = 0;
/*
void setup() {
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);  
  pinMode(ZUM, OUTPUT);
  Serial.begin (9600);
  //----------------------------------
  while ((digitalRead(9)) == 1) { delay(10); }
  ZUM();
  delay (600);
  linia();
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
  ZUM();
  delay (2000);
  ZUM();
  x = mas[7] - 1;
  y = mas[8] - 1;
  l();
  l();
  while (y > 0) {
    linia();
    y--;
  }
  y = mas[8] - 1;
  if (y > 3) {
    p();
  }
  if (y < 3) {
    l();
  }
  while (x > 0) {
    linia();
    x--;
  }
  // на а3
  linia();
  delay (1100);   // время на преодаление штрих-кода
  linia();
  linia();
  digitalWrite(DL, LOW );
  analogWrite(SL, 100);
  digitalWrite(DP, LOW );
  analogWrite(SP, 100);
  delay (200)    //  время чтобы точно встать в квадрат от его задней стенки
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}
*/

void setup() {
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin (9600);
  while ((digitalRead(9)) == 1) { delay(10); }
  //ZUM();
  delay (600);
  linia();
  strich_cod();
  /*digitalWrite(DL, HIGH );
  analogWrite(SL, 65);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 65);*/
  Serial.println (mas[0]);
  Serial.println (mas[1]);
  Serial.println (mas[2]);
  Serial.println (mas[3]);
  Serial.println (mas[4]);
  Serial.println (mas[5]);
  Serial.println (mas[6]);
  Serial.println ("---");
  Serial.println (mas[7]);
  Serial.println (mas[8]);
}

void loop() {
  //Serial.println (digitalRead(9));
  //delay(100);
}

void l() {
  digitalWrite(DL, LOW );
  analogWrite(SL, 100);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 100);
  while ((analogRead(A1)) < 600) { }
  while ((analogRead(A1)) > 600) { }
  while ((analogRead(A1)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void P() {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DP, LOW );
  analogWrite(SP, 100);
  while ((analogRead(A2)) < 600) { }
  while ((analogRead(A2)) > 600) { }
  while ((analogRead(A2)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void ZUM() {
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
}

void strich_cod() {
  digitalWrite(DL, HIGH );
  analogWrite(SL, 50);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 50);
  while (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) { }
  delay (150);
  while (x < 7) {
    if ((analogRead(A1)) < 600) {
      mas[x] = 1;
    }
    delay (200);
    x++;
  }
  x = 0;
  delay (100);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
  // черная линия, а потом 7-бит
  // проехать вперед и считать код, записать в массив mas[]
  y = (mas[0]*64)+(mas[1]*32)+(mas[2]*16)+(mas[3]*8)+(mas[4]*4)+(mas[5]*2)+(mas[6]*1);
  while (y >= 10) {
    y = y - 10;
    x = x + 1;
  }
  mas[7] = x;
  mas[8] = y;
  x = x - 1;
  y = y - 1;
}

void linia() {
  while (((analogRead(A1)) > 600) || ((analogRead(A2)) > 600)) {
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 100);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 100);
    }
    if (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
      digitalWrite(DL, LOW );
      analogWrite(SL, 100);
      digitalWrite(DP, HIGH );
      analogWrite(SP, 100);
    }
    if (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
      digitalWrite(DL, HIGH );
      analogWrite(SL, 100);
      digitalWrite(DP, LOW );
      analogWrite(SP, 100);
    }
  }
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 100);
    digitalWrite(DP, HIGH );
    analogWrite(SP, 100);    
  }
  delay(50);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

