#define SP     11
#define DP     13
#define SL     10
#define DL     12

float P   = 0;
float I   = 0;
float D   = 0;
float pid = 0;

int i = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;

int  e1 = 0;
int  e2 = 0;
//byte o [25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//--------------------------------------------------------------------
float M  =  255;   // средняя скорость мотора
float kp =  0.36; //0.12   // пропорциональный коэффицент
float kd =  1;    // диферинциальный коэффицент
float ki =  0.5;   // интегральный коэффицент
float ki2 =  2;     // интегральный коэффицент 2
//--------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);  
  pinMode(4, OUTPUT);
  digitalWrite(DL, HIGH );
  digitalWrite(DP, HIGH );
  while ((digitalRead(9)) == 1) { delay(10); }
  delay(1000);
}

void PID() {
  e1 = analogRead(A2) - analogRead(A1);
  P = kp*e1;
  I = I + ki*e1;
  D = D + kp*(e1 - e2); e2 = e1;
  //if (((e1 + 50) < e2) || ((e1 - 50) > e2)) { D = kd*(e1 - e2); e2 = e1; }    
  pid = P ;
}

void loop() {
  PID();
  if (pid > 0) {
    analogWrite(SL, (M - pid));
    analogWrite(SP, M);
  }
  else {
    analogWrite(SL,  M);
    analogWrite(SP, (M + pid));
  }
  
  //analogWrite(SL, (M - pid));
  //analogWrite(SP, (M + pid));
}

void ZUM()        {
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
}
