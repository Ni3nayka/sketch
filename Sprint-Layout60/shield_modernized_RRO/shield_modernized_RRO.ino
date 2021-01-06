#define AIN1 2
#define AIN2 4
#define PWMA 3
#define BIN1 5
#define BIN2 7
#define PWMB 6
#define speaker 8

// пины для управления Motor Shield
#define E1          5
#define E2          6
#define H1          4
#define H2          7
 
// три режима управления шаговым мотором
// однофазный режим
#define WAVE_DRIVE  0
// двухфазный режим
#define FULL_STEP   1
// полушаговый режим
#define HALF_STEP   2
 
// задержка между переключением обмоток
// определяет скорость вращения
int delayTime = 100;
 
unsigned long startTime;

void setup() {
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(speaker,OUTPUT);
  /*Serial.begin(9600);
  zz();
  motor(2,250);
  delay(2000);
  motor(2,0);*/
  // запоминаем текущее время
  startTime = millis();
}

void loop() {
  // узнаём время прошедшее с начала работы в миллисекундах
  // и переводим его в секунды
  unsigned long loopTime = (millis() - startTime) / 1000;
  // меняем режим каждую секунду
  rotate(loopTime % 3);
}

// функция выставляет значение на пинах
bool more(bool f) {
  if (f) return 0;
  else return 1;
}

void doStep(bool E1State, bool H1State, bool E2State, bool H2State) {
  digitalWrite(AIN1, H1State);
  digitalWrite(AIN2, more(H1State));
  digitalWrite(PWMA, E1State);
  digitalWrite(BIN1, H2State);
  digitalWrite(BIN2, more(H2State));
  digitalWrite(PWMB, E2State);
  delay(delayTime);
}
 
// определяем комбинации управляющих импульсов в зависимости от режима
void rotate(byte rotateMode) {
  switch (rotateMode) {
    case WAVE_DRIVE:
      doStep(1, 1, 0, 0);
      doStep(0, 0, 1, 1);
      doStep(1, 0, 0, 0);
      doStep(0, 0, 1, 0);
      break;
 
    case FULL_STEP:
      doStep(1, 1, 1, 1);
      doStep(1, 0, 1, 1);
      doStep(1, 0, 1, 0);
      doStep(1, 1, 1, 0);
      break;
 
    case HALF_STEP:
      doStep(1, 1, 0, 0);
      doStep(1, 1, 1, 1);
      doStep(0, 0, 1, 1);
      doStep(1, 0, 1, 1);
 
      doStep(1, 0, 0, 0);
      doStep(1, 0, 1, 0);
      doStep(0, 0, 1, 0);
      doStep(1, 1, 1, 0);
      break;
  }
}

void zz() {
  digitalWrite(speaker,1);
  delay(100);
  digitalWrite(speaker,0);
  delay(100);
  digitalWrite(speaker,1);
  delay(100);
  digitalWrite(speaker,0);
}

void motor(byte motor_number, int motor_speed) {
  //                1:2            -100:100
  if (abs(motor_speed)) motor_speed = motor_speed/abs(motor_speed)*100;
  motor_speed = map(motor_speed,-100,100,-255,255);
  if (motor_number==1) {
    if (motor_speed==0) {
      digitalWrite(AIN1,0);
      digitalWrite(AIN2,0);
    }
    if (motor_speed>0) {
      digitalWrite(AIN1,1);
      digitalWrite(AIN2,0);
    }
    if (motor_speed<0) {
      digitalWrite(AIN1,0);
      digitalWrite(AIN2,1);
    }
    analogWrite(PWMA,abs(motor_speed));
  }
  if (motor_number==2) {
    if (motor_speed==0) {
      digitalWrite(BIN1,0);
      digitalWrite(BIN2,0);
    }
    if (motor_speed>0) {
      digitalWrite(BIN1,1);
      digitalWrite(BIN2,0);
    }
    if (motor_speed<0) {
      digitalWrite(BIN1,0);
      digitalWrite(BIN2,1);
    }
    analogWrite(PWMB,abs(motor_speed));
  }
}

void s_motor() {
  
}
