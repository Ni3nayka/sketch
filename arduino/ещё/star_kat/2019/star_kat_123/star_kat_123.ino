#define SP     11
#define DP     13
#define SL     10
#define DL     12
#define ZUM     4

byte mas[] = {0, 0, 0, 0, 0, 0, 0};
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
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  //---------------
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
  //------------------
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  delay (2000);
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  //------------------
  x = mas[0] - 1;
  y = mas[1] - 1;
  l();
  l();
  while (y > 0) {
    linia();
    y--;
  }
  y = mas[1] - 1;
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
  pinMode(ZUM, OUTPUT);
  Serial.begin (9600);
  //----------------------------------
  while ((digitalRead(9)) == 1) { delay(10); }
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  digitalWrite (ZUM, HIGH);
  delay (250);
  digitalWrite (ZUM, LOW);
  delay (250);
  //----------------------------------
  linia();
  strich_cod();
}

void loop() {
  //Serial.println (digitalRead(9));
  //delay(100);
}

void l() {
  while ((analogRead(A1)) < 600) {
    digitalWrite(DL, LOW );
    analogWrite(SL, 100);
    digitalWrite(DP, HIGH );
    analogWrite(SP, 100);  
  }
  while ((analogRead(A1)) > 600) { }
  while ((analogRead(A1)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void P() {
  while ((analogRead(A2)) < 600) {
    digitalWrite(DL, HIGH );
    analogWrite(SL, 100);
    digitalWrite(DP, LOW );
    analogWrite(SP, 100);  
  }
  while ((analogRead(A2)) > 600) { }
  while ((analogRead(A2)) < 600) { }
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void strich_cod() {
  // черная линия, а потом 7-бит
  // проехать вперед и считать код, записать в массив mas[]
  y = (mas[6]*64)+(mas[5]*32)+(mas[4]*16)+(mas[3]*8)+(mas[2]*4)+(mas[1]*2)+(mas[0]*1);
  while (y >= 10) {
    y = y - 10;
    x = x + 1;
  }
  byte mas[] = {0, 0, 0, 0, 0, 0, 0};
  mas[0] = x;
  mas[1] = y;
  x = x - 1;
  y = y - 1;
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

void linia() {
  while (((analogRead(A1)) < 600) && ((analogRead(A2)) < 600)) {
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
  delay(200);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 0);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 0);
}

