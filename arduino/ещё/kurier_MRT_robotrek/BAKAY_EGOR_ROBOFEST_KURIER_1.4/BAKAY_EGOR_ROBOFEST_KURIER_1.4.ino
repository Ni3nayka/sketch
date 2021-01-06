#define M 40

void setup() {
   
}

void loop()
{
  if (button()) test();
}

void test() {
  forward(0);
  forward_long(1); // объявлено дополнительно ниже
  right();
  forward(0);
  left();
  forward(1);
  if (dist()) {
    take();
    left();
    forward(0);
    forward(1);
    quit();
    left();
    forward(0);
    right();
  }
  else {
    left();
    forward(0);
    forward(1);
    take();
    left();
    forward(0);
    forward(1);
    quit();
    left();
    forward(0);
    left();
  }
  forward(0);
  left();
  forward(1);
  if (dist()) {
    take();
    left();
    forward(0);
    forward(1);
    quit();
    left();
    forward(0);
    right();
  }
  else {
    left();
    forward(0);
    forward(1);
    take();
    left();
    forward(0);
    forward(1);
    quit();
    left();
    forward(0);
    left();
  }
  forward(1);
  startMotor(1, M);
  startMotor(2, M);
  delay(200);
  startMotor(1, 0);
  startMotor(2, 0);
  
}

void quit() {
  startMotor(3, -20);
  startMotor(4, -20);
  delay(1000);
  startMotor(3, 0);
  startMotor(4, 0);
  startMotor(1, -M);
  startMotor(2, -M);
  delay(200);
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

void take() {
  startMotor(3, 20);
  startMotor(4, 20);
  delay(1000);
  startMotor(3, 10);
  startMotor(4, 10);
}

void forward(boolean flag) {
  int in1 = M, in2 = M, e;
  boolean in3 = 0, Flag = 1;
  boolean F = 1;
  float K = 0; // если у нас есть банка, то мы увеличиваем скорость моторов в К раз
  if (dist()) {
    F = 0;
    K = 1.5;
  }
  while (((in1 > M/2) || (in2 > M/2)) && Flag) {
    dat(in1, in2, in3);
    if (in3 && flag && (in1 > M/1.05) && (in2 > M/1.05) || (dist() && F)) Flag = 0;
    e = (in1 - in2)*2.3;
    startMotor(1, (M + e)*K); //  умножаем на K для ускорения
    startMotor(2, (M - e)*K);
  }
  if (dist()) {
    startMotor(1, -M);
    startMotor(2, -M);
    delay(10);
  }
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

void forward_long(boolean flag) { // для участков дороги, гдке может быть горка
  forward(flag);
  unsigned long int time = millis();
  int in1 = M, in2 = M, e;
  boolean in3 = 0;
  while (time + 5000 > millis()) { // пока мы едем по горке (предположительно 5 сек - 5000 милисекунд)
    dat(in1, in2, in3);            // едем по линии (не страшно, если мы ее не всегда видим)
    e = (in1 - in2)*2.3;
    startMotor(1, M + e); 
    startMotor(2, M - e);
  }
  forward(flag);
}

boolean dist() {
  boolean f = 0;
  if (analogRead(IN4) < 200) builtInRGB(RED);
  else { f = 1; builtInRGB(GREEN); }
  return f;
}

void left() { // for example
  int in1, in2;
  boolean in3;
  dat(in1, in2, in3);
  if (dist()) { // если у нас в захвате банка то
    startMotor(1, -M*1.5);      // мы поворачиваемся сильнее (быстрее)
    startMotor(2, M*2);
  }
  else { // иначе (если банки в захвате нет то)
    startMotor(1, -M);      // поворачиваемся слабее (медленнее)
    startMotor(2, M*1.3);
  }
  while (in1 <= M/2) dat(in1, in2, in3);
  while (in1 >= M/2) dat(in1, in2, in3);
  while (in1 <= M/2) dat(in1, in2, in3);
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

void right() {
  int in1, in2;
  boolean in3;
  dat(in1, in2, in3);
  if (dist()) { // если у нас в захвате банка то
    startMotor(1, M*2);      // мы поворачиваемся сильнее (быстрее)
    startMotor(2, -M*1.5);
  }
  else { // иначе (если банки в захвате нет то)
    startMotor(1, M*1.3);      // поворачиваемся слабее (медленнее)
    startMotor(2, -M);
  }
  while (in2 <= M/2) dat(in1, in2, in3);
  while (in2 >= M/2) dat(in1, in2, in3);
  while (in2 <= M/2) dat(in1, in2, in3);
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

void dat(int& in1, int& in2, boolean& in3) {
  in1 = map(analogRead(IN1), 350, 990, 0, M);
  in2 = map(analogRead(IN2), 285, 985, 0, M);
  if (analogRead(IN3) > 500) in3 = 1;
  else in3 = 0;
}

boolean button() {
  boolean f = 0;
  if (buttonRead(BTN_UP) || buttonRead(BTN_DOWN) || buttonRead(BTN_LEFT) || buttonRead(BTN_RIGHT) || buttonRead(BTN_CENTER)) f = 1;
  return f;
}



