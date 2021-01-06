#define M 30

int in1, in2; 
boolean in3;


void setup() {
  Serial.begin(9600);
  //forward();
  builtInRGB(BLACK);
  delay(100);  
  builtInRGB(WHITE);
  delay(100);
  builtInRGB(RED);
  delay(100);
  builtInRGB(BLUE);
  delay(100);
  builtInRGB(GREEN);
  delay(100);
}

void loop() {
  PDU();
}

void forward() {
  boolean flag = 1;
  while (flag) {
    dat();
    if (((in1 < M/2) && (in2 < M/2)) || ((in1 > M/2) && (in2 > M/2) && (in3 == 0))) flag = 0;
    int e = (in1 - in2)*2.3;
    startMotor(1, M + e);
    startMotor(2, M - e);
  }
  startMotor(1, M);
  startMotor(2, M);
  delay(60);
  startMotor(1, 0);
  startMotor(2, 0);
}

void serial() {
  dat();
  Serial.print(in1);
  Serial.print(" ");
  Serial.print(in2);
  Serial.print(" ");
  Serial.print(in3);
  Serial.println();
}

void dat() {
  in1 = map(analogRead(IN1), 520, 990, 0, M);
  in2 = map(analogRead(IN2), 340, 970, 0, M);
  if (analogRead(IN3) > 400) in3 = 0;
  else in3 = 1;
}

//#include <Servo.h>
//Servo servo_port_OUT1;

void PDU() {
  if (buttonRead(BTN_UP))     test();
  if (buttonRead(BTN_DOWN))   forward();
  if (buttonRead(BTN_LEFT))   right();
  if (buttonRead(BTN_RIGHT))  left();
  if (buttonRead(BTN_CENTER)) {
    //forward();
    unsigned long int time = millis(); 
    boolean flag = 1;
    while (flag) {
      dat();
      if(time + 1000 < millis()) flag = 0;
      int e = (in1 - in2)*2.3;
      startMotor(1, (M + e)*1.3);
      startMotor(2, (M - e)*1.3);
    } 
    startMotor(1, M*1.4);
    startMotor(2, M*1.4);
    delay(1000);
    forward();
  }
}

void test() {
  forward();
  forward();
  right();
  forward();
  left();
  forward();
  if (dist()) {
    take();
    left();
    forward();
    forward();
    quit();
    left();
    forward();
    right();
  }
  else {
    left();
    forward();
    forward();
    take();
    left();
    forward();
    forward();
    quit();
    left();
    forward();
    left();
  }
  forward();
  left();
  forward();
  if (dist()) {
    take();
    left();
    forward();
    forward();
    quit();
    left();
    forward();
    right();
  }
  else {
    left();
    forward();
    forward();
    take();
    left();
    forward();
    forward();
    quit();
    left();
    forward();
    left();
  }
  forward();
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

/*void forward1(boolean flag) {
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
}*/

boolean dist() {
  boolean f = 0;
  if (analogRead(IN4) < 200) builtInRGB(RED);
  else { f = 1; builtInRGB(GREEN); }
  return f;
}

void left() {
  dat();
  startMotor(1, -M);
  startMotor(2, M*1.3);
  while (in1 <= M/2) dat();
  while (in1 >= M/2) dat();
  while (in1 <= M/2) dat();
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
}

void right() {
  dat();
  startMotor(1, M*1.3);
  startMotor(2, -M);
  while (in2 <= M/2) dat();
  while (in2 >= M/2) dat();
  while (in2 <= M/2) dat();
  startMotor(1, 0);
  startMotor(2, 0);
  delay(1000);
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
  delay(1000);  
  builtInRGB(WHITE);
  delay(1000);
  builtInRGB(RED);
  delay(1000);
  builtInRGB(GREEN);
  delay(1000);
  builtInRGB(BLUE);
  delay(1000);*/

