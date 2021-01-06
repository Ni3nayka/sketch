const int PWMA = 6;
const int AIN1 = 5;
const int AIN2 = 7;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  analogWrite(PWMA, 255); // когда мотор будет крутиться, он будет крутиться с максимальной скоростью
}

void loop() {
  // крутим вперед
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  delay(1000);

  // крутим назад
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  delay(1000);
  
  // блокируем
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  delay(1000);
  
  // останавливаем
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 0);
  delay(1000);

  // и все со скоростью 255
}
