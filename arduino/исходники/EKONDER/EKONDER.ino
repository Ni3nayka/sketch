#define SR     11
#define DR     13
#define SL     10
#define DL     12

int f   = 0;
int fl  = 0;
int in1 = 0;
int in2 = 0;
int e   = 0;

void setup() {
  Serial.begin(112500);
  pinMode(DR, OUTPUT);
  pinMode(DL, OUTPUT);
  pinMode(4,  OUTPUT);
}

/*
  digitalWrite(DL, HIGH );
  analogWrite(SL, 180);
  digitalWrite(DR, HIGH );
  analogWrite(SR, 255);
  */

void loop() {
  ekonder();
  Serial.println(e);
}

void ekonder() {
  if ((analogRead(A1)) > 700) { in1 = 1; } else { in1 = 0; }
  if ((analogRead(A2)) > 700) { in2 = 1; } else { in2 = 0; }
  if ((f == 0) && (fl == 0))    { fl++;  }
  if ((f == 3) && (fl >  0))    { fl= 0; }
  if ((in1 == 0) && (in2 == 0)) { f = 0; }
  if ((in1 == 1) && (in2 == 0)) { f = 1; }
  if ((in1 == 0) && (in2 == 1)) { f = 2; }
  if ((in1 == 1) && (in2 == 1)) { f = 3; }
  if ((fl == 1) && ((f == 1) || (f == 2))) {
    fl++;
    if (f == 1) { e++; }
    if (f == 2) { e--; }
  }
}

void test() {
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.println(analogRead(A2));
  delay(100);
}

