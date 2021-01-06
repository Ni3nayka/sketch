//#include <Servo.h>
//Servo servo_port_OUT1;

#define M 40

void setup() {
  //servo_port_OUT1.attach(OUT1, SMALL_SERVO);
  Serial.begin(9600);
  //forward(1);
}

void loop()
{
  //Serial.println(analogRead(IN4));
  PDU();
  dist();
  /*quit();
  delay(1000);
  take();
  delay(1000);*/
}

void PDU() {
  if (buttonRead(BTN_UP))     test();
  if (buttonRead(BTN_DOWN))   forward(0);
  if (buttonRead(BTN_LEFT))   right();
  if (buttonRead(BTN_RIGHT))  left();
  if (buttonRead(BTN_CENTER)) forward(1);
}

void test() {
  forward(0);
  forward(1);
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
  if (dist()) F = 0;
  while (((in1 > M/2) || (in2 > M/2)) && Flag) {
    dat(in1, in2, in3);
    if (in3 && flag && (in1 > M/1.05) && (in2 > M/1.05) || (dist() && F)) Flag = 0;
    e = (in1 - in2)*2.3;
    startMotor(1, M + e);
    startMotor(2, M - e);
  }
  if (dist()) {
    startMotor(1, -M);
    startMotor(2, -M);
    delay(10);
  }
  //startMotor(1, M); startMotor(2, M); delay(50);
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

boolean dist() {
  boolean f = 0;
  if (analogRead(IN4) < 200) builtInRGB(RED);
  else { f = 1; builtInRGB(GREEN); }
  return f;
}

void left() {
  int in1, in2;
  boolean in3;
  dat(in1, in2, in3);
  startMotor(1, -M);
  startMotor(2, M*1.3);
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
  startMotor(1, M*1.3);
  startMotor(2, -M);
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
  //Serial.print(in1); Serial.print(" "); Serial.print(in2); Serial.print(" "); Serial.println(in3);   
}

boolean button() {
  boolean f = 0;
  if (buttonRead(BTN_UP) || buttonRead(BTN_DOWN) || buttonRead(BTN_LEFT) || buttonRead(BTN_RIGHT) || buttonRead(BTN_CENTER)) f = 1;
  return f;
}

/*startMotor(1, 100);
  if (( buttonRead(BTN_UP) || ( buttonRead(BTN_DOWN) || ( buttonRead(BTN_LEFT) || ( buttonRead(BTN_RIGHT) || buttonRead(BTN_CENTER) ) ) ) ))
  {
    servo_port_OUT1.write( 90 );
  }
  builtInRGB(OFF);
  builtInRGB(BLACK);
  builtInRGB(WHITE);
  builtInRGB(RED);
  builtInRGB(GREEN);
  builtInRGB(BLUE);*/


