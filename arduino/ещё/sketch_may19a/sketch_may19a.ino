#include <Streaming.h>
#include <Vector.h>
#define inf 10000
#define PORT_DIR_1_L 11
#define PORT_DIR_2_L 12
#define PORT_POWER_L 10
#define PORT_DIR_1_R 7
#define PORT_DIR_2_R 8
#define PORT_POWER_R 9
float avgSpeed = 0.3;
float pid_p = 8;
byte storagesst[36];
Vector<byte>states(storagesst);
int x;
const int n = 35;
int temp;

int schtrix[7];
int t[n];
Vector<int> dist(t);

 
void setupMotors() {
  pinMode(PORT_DIR_1_L, OUTPUT);
  pinMode(PORT_DIR_2_L, OUTPUT);
  pinMode(PORT_POWER_L, OUTPUT);
  pinMode(PORT_DIR_1_R, OUTPUT);
  pinMode(PORT_DIR_2_R, OUTPUT);
  pinMode(PORT_POWER_R, OUTPUT);
  pinMode(13, OUTPUT);
}

void motors(float _rPower, float _lPower) {
  if (abs(_rPower) > 0.004) {
    if (_rPower > 0) {
      digitalWrite(PORT_DIR_1_R, HIGH);
      digitalWrite(PORT_DIR_2_R, LOW);
    }
    else {
      digitalWrite(PORT_DIR_1_R, LOW);
      digitalWrite(PORT_DIR_2_R, HIGH);
    }
    analogWrite(PORT_POWER_R, map(constrain(round(abs(_rPower) * 255), 0, 255), 0, 255, 50, 255));
  }
  else {
    digitalWrite(PORT_POWER_R, LOW);
    digitalWrite(PORT_DIR_1_R, HIGH);
    digitalWrite(PORT_DIR_2_R, HIGH);
  }
  //left
  if (abs(_lPower) > 0.004) {
    if (_lPower > 0) {
      digitalWrite(PORT_DIR_1_L, HIGH);
      digitalWrite(PORT_DIR_2_L, LOW);
    }
    else {
      digitalWrite(PORT_DIR_1_L, LOW);
      digitalWrite(PORT_DIR_2_L, HIGH);
    }
    analogWrite(PORT_POWER_L, map(constrain(round(abs(_lPower) * 255), 0, 255), 0, 255, 50, 255));
  }
  else {
    digitalWrite(PORT_POWER_L, LOW);
    digitalWrite(PORT_DIR_1_L, HIGH);
    digitalWrite(PORT_DIR_2_L, HIGH);
  }

}


#define PORT_COUNT 8
int measurePorts[PORT_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7};
int measureOrder[PORT_COUNT] = {0, 7, 1, 6, 2, 5, 3, 4};
int line[PORT_COUNT];

void readLine() {
  for (int i = 0; i < PORT_COUNT; i++) {
    if (i > 0) {
      delayMicroseconds(50);
    }
    line[measureOrder[i]] = analogRead(measurePorts[measureOrder[i]]);
  }
}

// вспомогательные переменные
byte linePro[PORT_COUNT];
int weights[PORT_COUNT] = { -4, -3, -2, -1, 1, 2, 3, 4};

// устанавливается при калибровке на конкретный полигон
byte whiteAvgs[PORT_COUNT] = {65, 65, 65, 65, 65, 65, 65, 65};
byte whiteSigmas[PORT_COUNT] = { 7, 7, 7, 7, 7, 7, 7, 7};
int blackAvgs[PORT_COUNT] = {475, 580, 522, 535, 530, 600, 418, 417};
byte blackSigmas[PORT_COUNT] = {30 , 30 , 30 , 30, 30, 30, 20, 30};

#define STUDENT_099 2.56 // коэффициент стьюдента для 99% уровня достовености 
float excentr = 0; // собственно, наш эксцентриситет
float prevExcentr = 0; // предыдущий эксцентриситет, ригодится в ПИД алгоритме

boolean isValid; // удалось ли нормально посчитать эксцентриситет
float blacks = 0; // сколько было чёрных точек
int changeCount; // сколько границ

// временные метки (в Ардуино это тип unsigned long), которые пригодятся нам в вычислениях регулятора
unsigned long lastBlacksFound;
unsigned long lastExcentrCalc = 0;
unsigned long excentrCalcDelay = 0;

void calcExcentr() {
  //calc excentr & other values
  // сохраняем предыдущий эксцентриситет
  prevExcentr = excentr;

  // инициализируем переменные
  float
  _excentr = 0;
  blacks = 0;
  isValid = true;
  changeCount = 0;

  // first run
  for (int i = 0; i < PORT_COUNT; i++) {
    if (line[i] >= blackAvgs[i] - blackSigmas[i]*STUDENT_099) { //if value is definetely in the black area
      linePro[i] = 1;
    }
    else { //if value is in between white and black
      linePro[i] = 0;
    }
  }

  // second run: borders definitions
  for (int i = 1; i < PORT_COUNT - 1; i++) {
    if (abs(linePro[i - 1] - linePro[i + 1]) > 0.3) { //диагностируем переход
      linePro[i] = float(line[i] - whiteAvgs[i]) / float(blackAvgs[i] - whiteAvgs[i]); //нормированное значение
      linePro[i] = constrain(linePro[i], 0, 1);
    }
  }

  // взвешенное суммирование даёт эксцентриситет
  for (int i = 0; i < PORT_COUNT; i++) {
    _excentr = _excentr + weights[i] * linePro[i];
    blacks = blacks + linePro[i]; //число найденных чёрных точек

    // check number of white-black border transitions
    if (i > 0) {
      if (abs(linePro[i] - linePro[i - 1]) > 0.7) { //считаем число переходов чёрное-белое. Для перехода через промежуточное значение можем получить проблему. Возможно, нужен более аккуратный подход
        changeCount++;
      }
    }
  }

  // если нашли чёрное, нормируем эксцентриситет и замечаем время, когда в последний раз находили чёрное (для диагностики схода)
  if (blacks > 0) {
    _excentr = _excentr * 2 / (blacks * PORT_COUNT);
    lastBlacksFound = millis();
  }

  // больше 2-х ереходов над одной линией быть не должно
  if (changeCount > 2) {
    isValid = false;
  }
  else {
    if (blacks > 0 ) {
      prevExcentr = excentr; // запомнили предыдущее значение эксцентриситета (нужно для дифференциальной части ПИД-регулятора)
      excentr = _excentr; // записли нынешнее значение
      if (lastExcentrCalc == 0) { //если первое чтение
        excentrCalcDelay = 0;
        lastExcentrCalc = micros();
      }
      else { // не первое чтение
        excentrCalcDelay = lastExcentrCalc;
        lastExcentrCalc = micros();
        excentrCalcDelay = lastExcentrCalc - excentrCalcDelay;
      }
    }
  }
}

#define INTEGRAL_WEGTH_FACTOR 0.97

#define REGULATOR_PART_CONSTR_PROPORT 1.1
#define REGULATOR_PART_CONSTR_DIFF 0.7
#define REGULATOR_PART_CONSTR_INTEGR 0.3

float rSpeed;
float lSpeed;



//float pid_p = 1.0;
// integral part +++++++++++++++++++++++++++++++++++is limited by -1/ln(0.9) (integral of exp(0.9x)
float pid_i = 0.010;
float pid_d = 8e8;

float power_difference;
float integral = 0;
float derivative = 0;

void calcSpeed() {
  if (excentrCalcDelay > 0 ) {
    derivative = float(excentr - prevExcentr) / excentrCalcDelay;
  }
  else {
    derivative = 0;
  }
  power_difference =
    constrain(excentr * pid_p, -REGULATOR_PART_CONSTR_PROPORT, REGULATOR_PART_CONSTR_PROPORT) +
    constrain(derivative * pid_d, -REGULATOR_PART_CONSTR_DIFF, REGULATOR_PART_CONSTR_DIFF);
  rSpeed = constrain(avgSpeed * (1 + power_difference / 2), 0, 1);
  lSpeed = constrain(avgSpeed * (1 - power_difference / 2), 0, 1);
}

//#define MYDEBUG
//#define SHOW_RAW_DATA


void right() {
  bool flag = true;
  motors(0.3, 0.3);
  delay(200);
  do {
    motors(-0.3, 0.3);
    if (flag) {
      delay(200);
      flag = false;
    }
    readLine();
    calcExcentr();
    calcSpeed();
  } while (linePro[0] == 0 && linePro[1] == 0 && linePro[2] == 0 && linePro[3] == 0 && linePro[4] == 0 && linePro[5] == 0 && linePro[6] == 0 && linePro[7] == 0);
  motors(0, 0);
}
void circle() {
  bool flag = true;
  motors(0.3, 0.3);
  delay(400);
  do {
    motors(-0.3, 0.3);
    if (flag) {
      delay(600);
      flag = false;
    }
    readLine();
    calcExcentr();
    calcSpeed();
  } while (linePro[0] == 0 && linePro[1] == 0 && linePro[2] == 0 && linePro[3] == 0 && linePro[4] == 0 && linePro[5] == 0 && linePro[6] == 0 && linePro[7] == 0);
  motors(0, 0);
}
void left() {
  bool flag = true;
  motors(0.3, 0.3);
  delay(200);
  do {
    motors(0.3, -0.3);
    if (flag) {
      delay(200);
      flag = false;
    }
    readLine();
    calcExcentr();
    calcSpeed();
  } while (linePro[0] == 0 && linePro[1] == 0 && linePro[2] == 0 && linePro[3] == 0 && linePro[4] == 0 && linePro[5] == 0 && linePro[6] == 0 && linePro[7] == 0);
  motors(0, 0);
}
bool adj[n][n] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  
 void dijkstra(int s) {

  dist.assign(n, 10000);
  //Serial << dist << endl;
  dist[s] = 0;
  int min_ = inf;
  bool used[n];
  for(int i = 0; i < n; i++){
    used[i] = false;
  }
  while (true) {

    int v = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i] && (v == -1 || dist[i] < dist[v])) {
        v = i;
        min_ = dist[i];
      }
    }
    if (v == -1) {
      break;
    }
    for (int i = 0; i < n; i++) {
      if (adj[v][i] > 0) {
        temp = min_ + adj[v][i];
        //Serial << temp << " ";
        if (temp < dist[i]) {
          dist[i] = temp;
        }
      }
    }
    used[v] = true;
  }
}

void setup() {
  setupMotors();
  for(byte i = n - 9; i < n; i++){
    for(byte j = 0; j < n; j++){
      adj[i][j] = byte(0);
    }
  }
  digitalWrite(6, HIGH);
  Serial.begin(9600);
  int coordinate = 0, y = 0;
  /*while (!(linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1)) {
    readLine();
    calcExcentr();
    calcSpeed();
    motors(rSpeed, lSpeed);
    for(int i = 0; i < 8; i++){
      Serial << linePro[i] << " ";
    }
    Serial << endl;
  }*/
  motors(0, 0);
  delay(1000);
  /*for (int i = 0; i < 10; i++) {
    if (i > 2) {
      readLine();
      calcExcentr();
      calcSpeed();
      if (linePro[4]) schtrix[i - 3] = 1;
      else schtrix[i - 3] = 0;
    }
    motors(0.1, 0.1);
    delay(125);
  }
  motors(0, 0);
  for (int i = 0; i < 7; i++) {
    Serial << schtrix[i] << " ";
    if (schtrix[i]) {
      int temp = 1;
      for (int j = 0; j < i; j++) {
        temp *= 2;
      }
      coordinate += temp;
      temp = 1;
    }
  }
  x = coordinate / 10 * 5 - (5 - coordinate % 10);
  if (x == 9) {
    digitalWrite(13, HIGH);
  }
  */
  x = 20;
  states.push_back(1);
  byte arr[3*58]={ 1, 2, 1,
                1, 3, 1,
                3, 4, 1,
                2, 5, 1,
                4, 10, 1,
                3, 9, 1,
                1, 8, 1,
                2, 7, 1,
                5, 6, 1,
                6, 7, 1,
                6, 11, 1,
                7, 8, 1,
                7, 12, 1,
                8, 9, 1,
                8, 13, 1,
                9, 10, 1,
                9, 14, 1,
                10, 15, 1,
                15, 20, 1,
                15, 14, 1,
                14, 19, 1,
                14, 13, 1,
                13, 18, 1,
                13, 12, 1,
                12, 11, 1,
                12, 17, 1,
                11, 16, 1,
                16, 17, 1,
                16, 21, 1,
                17, 22, 1,
                17, 18, 1,
                18, 19, 1,
                18, 23, 1,
                19, 24, 1,
                19, 20, 1,
                20, 25, 1,
                25, 30, 1,
                25, 24, 1,
                24, 29, 1,
                24, 23, 1,
                23, 28, 1,
                23, 22, 1,
                22, 27, 1,
                22, 21, 1,
                21, 26, 1,
                26, 27, 1,
                26, 31, 1,
                27, 32, 1,
                27, 28, 1,
                28, 33, 1,
                28, 29, 1,
                29, 34, 1,
                29, 30, 1,
                30, 35, 1,
                35, 34, 1,
                34, 33, 1,
                33, 31, 1,
                32, 31, 1};
  for (byte i = 0; i < 58 * 3; i += 3) {
    byte v1, v2, len;
    v1 = arr[i];
    v2 = arr[i + 1];
    v1--;
    v2--;
    len = arr[i + 2];
    adj[v1][v2] = len;
    adj[v2][v1] = len;
    temp = len;
  }
  Serial << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      //Serial << _DEC(adj[i][j]) << " ";
      Serial.print(adj[i][j]);
      Serial.print(" ");
      delay(1);
    }
    Serial << endl;
  }
  Serial << endl;
  Serial << endl;
  Serial << endl;
  dijkstra(0);
  Serial << "dijkstra ends!!" << endl;
  Serial << dist << endl;
  int storage[n];
  Vector<int>ans;
  ans.setStorage(storage);
  int end_ = 20;
  end_--;
  int start = 0;
  ans.push_back(end_ + 1);
  int k = 1;
  int weight = dist[end_];
  while (end_ > start) {
    for (int i = 0; i < n; i++) {
      if (adj[end_][i] != 0) {
        int temp = weight - adj[end_][i];
        if (temp == dist[i]) {
          weight = temp;
          end_ = i;
          ans.push_back(i + 1);
          k++;
        }
        if (end_ == start - 1) break;
      }
    }
    if (end_ == start - 1) break;
  }
  int storagex[n];
  Vector<int>rans(storagex);
  for (int i = ans.size() - 1; i >= 0; i--) {
    rans.push_back(ans[i]);
  }
  Serial << rans << endl;
  int prevAns = 1;

  for (int i = 1; i < rans.size(); i++) {
    if (rans[i] != 0) {
      if (rans[i] == 2 && rans[i - 1] == 1) {
        states.push_back(2);
      }
      else if (rans[i] == 3 && rans[i - 1] == 1) {
        states.push_back(4);
      }
      else if (rans[i] == 4 && rans[i - 1] == 3) {
        states.push_back(4);
      }
      else if(rans[i] == 5 && rans[i - 1] == 2){
        states.push_back(2);
      }
      else if(rans[i] == 6 && rans[i - 1] == 5){
        states.push_back(1);
      }
      else if (rans[i] - rans[i - 1] == 1) {
        states.push_back(4);
      }
      else if (rans[i - 1] - rans[i] == 1) {
        states.push_back(2);
      }
      else if (rans[i] - rans[i - 1] >= 5) {
        states.push_back(1);
      }
      else if (rans[i - 1] - rans[i] >= 5) {
        states.push_back(3);
      }
    }
  }
}

#ifdef MYDEBUG
#define LOOP_DELAY 100
#else
#define LOOP_DELAY 2
#endif

bool flag = true;
void loop() {
  readLine();
  calcExcentr();
  calcSpeed();
  /*for(int i = 0; i < 8; i++){
    Serial << linePro[i] << " ";
  }
  Serial << endl;*/
  //motors(255, 255);
  //delay(10000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  int prev_state = 1;
  Serial << states << endl;
  for (int i = 1; i < states.size(); i++) {
    if ( prev_state - states[i] == -1 || prev_state - states[i] == 3) {
      while (true) {
        readLine();
        calcExcentr();
        calcSpeed();
        if (linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1) {
          right();
          while (true) {
            readLine();
            calcExcentr();
            calcSpeed();
            motors(rSpeed, lSpeed);
            if ((linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1))break;
          }
          motors(0, 0);
          break;
        }
        else {
          motors(rSpeed, lSpeed);
        }
      }
    } else if (states[i] == prev_state) {
      motors(0.3, 0.3);
      delay(400);
      readLine();
      calcExcentr();
      calcSpeed();
      while (!(linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1)) {
        readLine();
        calcExcentr();
        calcSpeed();
        motors(rSpeed, lSpeed);
      }
      motors(0, 0);

    } else {
      while (true) {
        readLine();
        calcExcentr();
        calcSpeed();
        if (linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1) {
          left();
          while (true) {
            readLine();
            calcExcentr();
            calcSpeed();
            motors(rSpeed, lSpeed);
            if ((linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1
                 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1))break;
          }
          motors(0, 0);
          break;
        }
        else {
          motors(rSpeed, lSpeed);
        }
      }
    }
    prev_state = states[i];
    delay(LOOP_DELAY);
  }
  delay(5000);
  circle();
  readLine();
  calcExcentr();
  calcSpeed();
  motors(rSpeed, lSpeed);
  delay(10);
  motors(0, 0);
  delay(100);
  for (int i = states.size() - 1; i >= 0; i--) {
    if ( prev_state - states[i] == -1 || prev_state - states[i] == 3) {
      while (true) {
        readLine();
        calcExcentr();
        calcSpeed();
        if (linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1) {
          right();
          while (true) {
            readLine();
            calcExcentr();
            calcSpeed();
            motors(rSpeed, lSpeed);
            if ((linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1))break;
          }
          motors(0, 0);
          break;
        }
        else {
          motors(rSpeed, lSpeed);
        }
      }
    } else if (states[i] == prev_state) {
      motors(0.3, 0.3);
      delay(200);
      readLine();
      calcExcentr();
      calcSpeed();
      while (!(linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1)) {
        readLine();
        calcExcentr();
        calcSpeed();
        motors(rSpeed, lSpeed);
      }
      motors(0, 0);

    } else {
      while (true) {
        readLine();
        calcExcentr();
        calcSpeed();
        if (linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1) {
          left();
          while (true) {
            readLine();
            calcExcentr();
            calcSpeed();
            motors(rSpeed, lSpeed);
            if ((linePro[0] == 1 && linePro[1] == 1 && linePro[2] == 1 && linePro[3] == 1 && linePro[4] == 1 && linePro[5] == 1 && linePro[6] == 1 && linePro[7] == 1))break;
          }
          motors(0, 0);
          break;
        }
        else {
          motors(rSpeed, lSpeed);
        }
      }
    }
    prev_state = states[i];
    delay(LOOP_DELAY);
  }
  motors(0, 0);
  delay(10000);
  //delay(10000);
}
