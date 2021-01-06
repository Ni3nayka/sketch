// пины для подключения контактов STEP, DIR
#define STEP 3
int DIR = 2;
// для регулировки скорости - пин потенциометра
#define POT A0
// для кнопки
#define BUTTON 9
// для включения/выключения
#define EN 8

// количество шагов на 1 оборот
#define ROUND 200

// скорость двигателя
#define SPEED 1

// массив пинов для MS1,MS2,MS3
int pins_steps[] = {7, 6, 5};
int steps[5][3] = {
  {0, 0, 0}, // 1
  {1, 0, 0}, // 1/2
  {0, 1, 0}, // 1/4
  {1, 1, 0}, // 1/8
  {1, 1, 1} // 1/16
};

// для кнопки
int prevB = 0;
int tekB = 0;

boolean movement = false;

void setup() {
  // режим для выводов STEP и DIR как
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  // начальные значения
  digitalWrite(STEP, 1);
  digitalWrite(DIR, 0);
  // режим для enable
  pinMode(EN, OUTPUT);
  // не разрешать
  digitalWrite(EN, 1);
  // для MS1,MS2,MS3
  for (int i = 0; i < 3; i++) {
  pinMode(pins_steps[i], OUTPUT);
  }
}

void loop() {
  // получить режим микрошага
  //digitalWrite(DIR, 0);
  int mode = map(analogRead(POT), 0, 1024, 0, 5);
  mode = 0; // [0, 4] <==
  // установить
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins_steps[i], steps[mode][i]);
  }
  // сделать 1 оборот
  if (movement == true) {
    digitalWrite(STEP, 1);
    delay(SPEED);
    digitalWrite(STEP, 0);
    delay(SPEED);
  }
  movement = !movement; digitalWrite(EN, !movement);
}
