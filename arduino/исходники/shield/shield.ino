#define PWMA 3
#define AIN1 2
#define AIN2 4
#define PWMB 6
#define BIN1 5
#define BIN2 7

void setup() {
  pinMode (PWMA, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
  analogWrite(PWMA, 255);
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  analogWrite(PWMB, 255);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
  delay(1000);
  analogWrite(PWMA, 255);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  analogWrite(PWMB, 255);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
  delay(1000);
  analogWrite(PWMA, 0);
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  analogWrite(PWMB, 0);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
}

void loop() {
  
}
