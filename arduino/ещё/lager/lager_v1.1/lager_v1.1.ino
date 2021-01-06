#define SR     11
#define DR     13
#define SL     10
#define DL     12

float M = 50;
float e = 0;
long int p = 0;

void setup() {
  Serial.begin(115200);
  pinMode (13, OUTPUT);
  pinMode (4 , OUTPUT);
  pinMode (DR, OUTPUT);
  pinMode (DL, OUTPUT);
  //zum();
  while (digitalRead(2) == 1) { delay(10); }
  //zum();
  linia();
}

void loop() {
  //test_d();
  //test_e();
  //linia();
}

void linia() {
  while ((((analogRead(A1) > 600) || (analogRead(A3) > 600))) && ((analogRead(A2)) < 900)) {
    e = ((analogRead(A1)) - (analogRead(A3)) + 70)*(M/500);
    digitalWrite(DL, 1);
    analogWrite (SL, M + e);
    digitalWrite(DR, 1);
    analogWrite (SR, M - e);
    /*if ((analogRead(A2)) > 950) {
      //digitalWrite(4, 1);
      if (e < 0) {
        while ((analogRead(A2)) > 950) {
          digitalWrite(DL, 0);
          analogWrite (SL, 50);
          digitalWrite(DR, 1);
          analogWrite (SR, 50);
        }
      }
      else {
        while ((analogRead(A2)) > 950) {
          digitalWrite(DL, 1);
          analogWrite (SL, 50);
          digitalWrite(DR, 0);
          analogWrite (SR, 50);
        }
      }
      delay(100);
    }*/ 
  }
  analogWrite (SL, 0);
  analogWrite (SR, 0);
}

void test_d() {
  Serial.print(analogRead(A1));
  Serial.print("   ");
  Serial.print(analogRead(A2));
  Serial.print("   ");
  Serial.println(analogRead(A3));
  delay(100);
}

void test_e() {
  e = ((analogRead(A1)) - (analogRead(A3)) + 70);
  Serial.print(e);
  Serial.print("   ");
  e = e*(M/500);
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

