#define SR     11
#define DR     13
#define SL     10
#define DL     12

int e1 = 0;
int e2 = 0;
int e = 0;

void setup() 
{
  pinMode(DL, OUTPUT);
  pinMode(DR, OUTPUT);
  Serial.begin(112500);
  delay(10000);
} 

void loop() {
  digitalWrite(DL, 1);
  analogWrite(SL, 255);
  while (e < 1380) {
    ekonder();
  }
  digitalWrite(DL, 1);
  analogWrite(SL, 0);
  delay(500);
  e = 0;
}

void ekonder()    {
  if (((analogRead(A1)) > 1000) && (e1 == 0)) { e1++; e++; }
  if (((analogRead(A1)) < 1000) && (e1 == 1)) { e1--;      }
  if (((analogRead(A2)) > 1000) && (e2 == 0)) { e2++; e++; }
  if (((analogRead(A2)) < 1000) && (e2 == 1)) { e2--;      }
}

