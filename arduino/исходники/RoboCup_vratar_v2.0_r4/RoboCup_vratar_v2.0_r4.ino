#include "config.h"
#include "math.h"

byte datIK[4] = {0,0,0,0};  // 
boolean datIKchesk = 0;
uint32_t datIKcheskTime = 0;
uint32_t datIKcheskTime2 = 0;
boolean moving = 0;
byte dirIKchesk = 0;
long int TIME = 0;
//long int time_ball = 0;

unsigned char Re_buf[8], counter = 0;

float k;

bool ballSensor = 0;
bool left_btn = false, center_btn = false, right_btn = false;
bool left_led = false, center_led = false, right_led = false;

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
  mpuInterrupt = true;
}

camBlock old_ball, ball, home, target;
uint32_t targetClear = 0;
bool ballCatched = false;
byte pr_lights = 0;
byte lineState = 0;
uint32_t sq_timer = 0;
uint32_t lightsTimer = 0;

double yaw = 0;
float yaw_offset = 0; 
double yaw_zero = 0;  // my
short speed = 0;
float dir = 0;
float heading = 0;
float pr_heading = 0;
//float k = 180;

#define ras_fil 10
int fil_ball[ras_fil][2];
int fil_home[ras_fil][2];
int fil_target[ras_fil][2];

int IKavailable[4][4] = {
  {552, 436, 646, 568},  
  {215, 284, 553, 652},  
  {353, 296, 245, 395},  
  {452, 315, 405, 287},
};

/*int IKavailable[4][4] = {
  {452, 336, 546, 468},  
  {115, 184, 353, 552},  
  {253, 196, 145, 295},  
  {352, 215, 205, 187},
};*/

template <typename T>
T sign(T value) {
  return T((value > 0) - (value < 0));
}

double constrainAngle(double x) {
  x = fmod(x + PI, 2 * PI);
  if (x < 0)
    x += 2 * PI;
  return x - PI;
}

float calcAngle(int x, int y) {
  return (-acos((x - CAM_CENTER_X) / sqrt(pow(y - CAM_CENTER_Y, 2) + pow(x - CAM_CENTER_X, 2))) * (1 - 2 * (y > CAM_CENTER_Y)));
}

float calcAngle(camBlock b) {
  int x = b.x;
  int y = b.y;
  return calcAngle(x, y);
}

float calcDist(int x, int y) {
  return sqrt(pow(x - CAM_CENTER_X, 2) + pow(y - CAM_CENTER_Y, 2));
}

float calcDist(camBlock b) {
  int x = b.x;
  int y = b.y;
  return calcDist(x, y);
}

bool checkTimer(uint32_t timer, int dt) {
  return (millis() - timer < dt);
}

void setSpeed(byte port, short motor_speed) {
  if (motor_speed > 255)
    motor_speed = 255;
  else if (motor_speed < -255)
    motor_speed = -255;

  analogWrite(motors_pwm[port], abs(motor_speed));
  digitalWrite(motors_in1[port], (motor_speed >= 0));
  digitalWrite(motors_in2[port], !(motor_speed >= 0));
}

void setLED(bool l = left_led, bool c = center_led, bool r = right_led) {
  digitalWrite(LEFT_LED, l);
  digitalWrite(CENTER_LED, c);
  digitalWrite(RIGHT_LED, r);
}

void move() {
  dir = constrainAngle(dir);
  int u = heading * 180;  // k = 180;
  if (abs(u) > 150) u = 150*(u/abs(u)); // my - чтобы не закручивался робот
  //int u = -heading * 210 + (heading - pr_heading) * -700; // new
  if (abs(heading) < 0.5) {
    setSpeed(0,  -speed * cos((dir + 0.785398163397448)) + u);
    setSpeed(1,   speed * cos((dir - 0.785398163397448)) + u);
    setSpeed(2,   speed * cos((dir + 0.785398163397448)) + u);
    setSpeed(3,  -speed * cos((dir - 0.785398163397448)) + u);
  }
  else {
    setSpeed(0, u);
    setSpeed(1, u);
    setSpeed(2, u);
    setSpeed(3, u);
  }
  pr_heading = heading;
}

void dribbler(short speed) {
  digitalWrite(DRIBBLER_DIR, (speed < 0));
  analogWrite(DRIBBLER_SPEED, abs(speed));
}

void updateBtns() {
  left_btn = digitalRead(LEFT_BTN);
  center_btn = digitalRead(CENTER_BTN);
  right_btn = digitalRead(RIGHT_BTN);
}

void updateBallSensor() {
  ballSensor = digitalRead(BALL_SENSOR);
}

void kick(bool state) {
  static uint32_t kickTimer = 0;
  if (state) {
    if (!checkTimer(kickTimer, 2000)) {
      kickTimer = millis();
    }
  }

  if (checkTimer(kickTimer, 3)) {
    // dribbler(-255);
  } else if (checkTimer(kickTimer, 100)) {
    digitalWrite(KICKER, HIGH);
  } else {
    digitalWrite(KICKER, LOW);
  }
}

void updateCam() {
  /*ball.found = false;
  home.found = false;
  target.found = false;*/

  pixy.ccc.getBlocks(false, CCC_SIG1 | CCC_SIG2 | CCC_SIG3);
  if (pixy.ccc.numBlocks) {
    for (int i = 0; i < pixy.ccc.numBlocks; ++i) {
      if (pixy.ccc.blocks[i].m_signature == 1) {
        ball.x = pixy.ccc.blocks[i].m_x;
        ball.y = pixy.ccc.blocks[i].m_y;
        ball.w = pixy.ccc.blocks[i].m_width;
        ball.h = pixy.ccc.blocks[i].m_height;

        ball.dir = calcAngle(ball.x, ball.y);
        ball.dist = calcDist(ball.x, ball.y);

        //ball.found = true;
        ball.found = (abs(ball.dir) < 2);
        ball.t = millis();
      }
      else if (ball.t + 500 < millis()) ball.found = false;
      if (pixy.ccc.blocks[i].m_signature == HOME_GOAL) {
        home.x = pixy.ccc.blocks[i].m_x;
        home.y = pixy.ccc.blocks[i].m_y;
        home.w = pixy.ccc.blocks[i].m_width;
        home.h = pixy.ccc.blocks[i].m_height;

        home.dir = calcAngle(home.x, home.y);
        home.dist = calcDist(home.x, home.y);

        //home.found = true;
        ball.found = (abs(ball.dir) > 1);
        home.t = millis();
      }
      else if (home.t + 500 < millis()) home.found = false;
      if (pixy.ccc.blocks[i].m_signature == ENEMY_GOAL) {
        target.x = pixy.ccc.blocks[i].m_x;
        target.y = pixy.ccc.blocks[i].m_y;
        target.w = pixy.ccc.blocks[i].m_width;
        target.h = pixy.ccc.blocks[i].m_height;

        target.dir = calcAngle(target.x, target.y);
        target.dist = calcDist(target.x, target.y);

        target.found = true;
        target.t = millis();
      }
      else if (target.t + 500 < millis()) target.found = false;
    }
  }

  pixy.setLED(0, ball.found * 255, 0);

  ball.found = checkTimer(ball.t, 600);
  home.found = checkTimer(home.t, 300);
  target.found = checkTimer(target.t, 300);
}

void setup() {
  Serial.begin(115200);
  pinMode(LEFT_LED, OUTPUT);
  pinMode(CENTER_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  setLED(0, 1, 0); delay(1000); setLED(1, 0, 1);
  
  TIME = millis();
  while ((TIME + 2000 > millis()) && (!digitalRead(CENTER_BTN)));
  if (digitalRead(CENTER_BTN)) { ENEMY_GOAL = 3; HOME_GOAL = 2; rast_home = 57; } // мои желтые
  else { ENEMY_GOAL = 2; HOME_GOAL = 3; rast_home = 50; } // мои синие
  Serial.println(ENEMY_GOAL);
  
  setLED(0, 1, 0); delay(1000); setLED(1, 1, 1);
  for(int i = 0; i < ras_fil; i++) {
    fil_ball[i][0] = 0;
    fil_ball[i][1] = 0;
    fil_home[i][0] = 0;
    fil_home[i][1] = 0;
    fil_target[i][0] = 0;
    fil_target[i][1] = 0;
  }

  pinMode(MPL_1, OUTPUT);
  pinMode(MPL_2, OUTPUT);

  pinMode(L_STANDBY, OUTPUT);
  digitalWrite(L_STANDBY, HIGH);
  pinMode(R_STANDBY, OUTPUT);
  digitalWrite(R_STANDBY, HIGH);
  for (int i = 0; i < 4; ++i) {
    pinMode(motors_pwm[i], OUTPUT);
    pinMode(motors_in1[i], OUTPUT);
    pinMode(motors_in2[i], OUTPUT);
  }

  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(CENTER_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);

  Serial1.begin(115200);// SoftwareSerial can only support 9600 baud rate for GY 25 but Serial1 can support 115200 and 9600 both
  delay(4000);
  Serial1.write(0XA5);
  Serial1.write(0X54);//correction mode
  delay(4000);
  Serial1.write(0XA5);
  Serial1.write(0X51);//0X51:query mode, return directly to the angle value, to be sent each read, 0X52:Automatic mode,send a direct return angle, only initialization
  pixy.init();
  pixy.setLED(0, 0, 0);
  pinMode(DRIBBLER_SPEED, OUTPUT);
  pinMode(DRIBBLER_DIR, OUTPUT);
  pinMode(KICKER, OUTPUT);
  pinMode(BALL_SENSOR, INPUT);

  setLED(0, 0, 0); delay(200); setLED(1, 1, 1); delay(200); 
  setLED(0, 0, 0); delay(200); setLED(1, 1, 1); delay(200); 
  setLED(0, 0, 0); delay(200);
}

void updateGyro() {
  if (left_btn && right_btn) {
    Serial1.write(0xA5);
    Serial1.write(0x55);
  }

  Serial1.write(0XA5);
  Serial1.write(0X51);//send it for each read
  while (Serial1.available()) {
    Re_buf[counter] = (unsigned char)Serial1.read();
    if (counter == 0 && Re_buf[0] != 0xAA) return;
    counter++;
    if (counter == 8)
    {
      counter = 0;
      if (Re_buf[0] == 0xAA && Re_buf[7] == 0x55) // data package is correct
      {
        yaw = -DEG_TO_RAD * ((Re_buf[1] << 8 | Re_buf[2]) / 100.00);
      }
    }
  }
  if (digitalRead(LEFT_BTN) && digitalRead(RIGHT_BTN)) {
    Serial.print("update gyroscop");
    yaw_offset = yaw;
  }
  yaw = constrainAngle(yaw - yaw_offset);
  Serial.print("yaw: "); Serial.print(yaw); Serial.print("; ");
}

void followBall() {
  float homeDir = PI;
  if (home.found)
    homeDir = home.dir;

  if (ball.found) {
    dir = ball.dir;
    if (ball.dist < 65) {
      if (abs(ball.dir) < PI / 2.5) {
        dir = 2.5 * ball.dir;
      } else {
        dir = homeDir;
      }
    }

    float ang = constrainAngle(ball.dir - yaw);
    if (abs(ang) > 2.2 && ball.dist < 65)
      dir = ang + PI / 2 * sign(ang);

  } else {
    dir = homeDir;
    speed = 300;
  }

  if (!ball.found && ball.x > 190 && ball.x < 215 && ball.y > 100 && ball.y < 140) {
    dir = ball.dir;
    speed = BASIC_SPEED;
  }

  if (target.dist < 75 && abs(target.dir) > PI / 2.5) {
    dir = PI;
    speed = 200;
    center_led = true;
  }
}

void and_more_programs() {
  k = BASIC_K;
  left_led = false;
  center_led = false;
  right_led = false;
  kick(false);
  updateBtns();
  updateCam();
  updateBallSensor();
  updateGyro();
  byte lights = 0;
  //lights = updateLights();
  if (lights) {
    lightsTimer = millis();
    if (!lineState)
      lineState = lights;
  } else if (!checkTimer(lightsTimer, 600)) {
    lineState = 0;
  }

  speed = BASIC_SPEED;
  dir = ball.dir;
  heading = yaw;
  //  if (target.found) {
  //    heading = target.dir;
  //  }
  followBall();
  if (lineState) {
    if (target.dist > 80) {
      heading = yaw;
      speed = 160;
      if (ball.found)
        followBall();
      else
        dir = home.dir;
      if (lineState == 1) {
        if (lights & 8) {
          speed = 300;
          dir = PI / 2;
        }
        right_led = true;
      }

      if (lineState == 8) {
        if (lights & 1) {
          speed = 300;
          dir = -PI / 2;
        }
        left_led = true;
      }

      if (lights == 9) {
        lineState = 9;
        lightsTimer = millis();
        if (target.dist > home.dist) {
          dir = 0;
          speed = 360;
        } else {
          dir = PI;
          speed = 360;
        }
      }
    } else {
      if (lineState) {
        dir = home.dir;
        speed = 300;
        heading = yaw;
      }
    }
  }

  if (!ballSensor) {
    speed = 300;
    dribbler(BASIC_DRIBBLER_SPEED);
    if (ball.x > 190 && ball.x < 215 && ball.y > 100 && ball.y < 140 && !checkTimer(ball.t, 300)) {
      if (target.dist < 70 && abs(yaw - target.dir) > 0.8) {
        dir = PI;
        heading = yaw;
      }
      if (target.dist < 80 && abs(yaw - target.dir) < 0.45) {
        kick(true);
        left_led = true;
      }
      if (!checkTimer(ball.t, 1700)) {
        kick(true);
        left_led = true;
      }
      heading = target.dir;
      dir = target.dir;
    }
  } else {
    dribbler(SNOOZE_DRIBBLER_SPEED);
  }
  if (checkTimer(lightsTimer, 400) && lineState == 9) {
    speed = 300;
    heading = yaw;
    if (home.found) {
      dir = home.dir;
    } else if (target.found) {
      dir = target.dir;
    } else {
      dir = PI;
    }
  }

  if (home.found && abs(dir) > 2 && home.dist < 80 && !lights && (!ball.found || abs(ball.dir) > PI / 2)) {
    heading = yaw;
    speed = 0;
  }
  // Serial.println(ball.found);

  pr_lights = lights;

  setLED();
  move();
}

//===============================================================

void updateLights1() {
  //int result = 0;
  datIKchesk = 0;
  for(int i = 0; i < 4; i++) datIK[i] = 0;
  //for (byte i = 1; i < 4; i+=2) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(MPL_1, i & 1);
    digitalWrite(MPL_2, i >> 1);
    //for (int u = 0; u < 4; u++) { Serial.print(analogRead(u) > IKavailable[i][u]);  Serial.print(" "); } Serial.print(" "); // >> 2  /  analogRead(u)
    //for (byte u = 0; u < 4; u++) datIK[u] |= (analogRead(u) > 550) << i;
    // => for (byte u = 0; u < 4; u++) datIK[u] |= (analogRead(u) > IKavailable[i][u]) << i;
    datIK[2] |= (analogRead(2) > IKavailable[i][2]) << i; 
  }
  //Serial.println();
  //for(int i = 0; i < 4; i++) { Serial.print(datIK[i]); Serial.print(" "); } Serial.println();
  for(int i = 0; i < 4; i++) if ((datIK[i] > 0) && !(datIKchesk)) datIKchesk = true;
  return datIKchesk; 
}

void updateLights() {
  //int result = 0;
  datIKchesk = 0;
  for(int i = 0; i < 4; i++) datIK[i] = 0;
  //for (byte i = 1; i < 4; i+=2) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(MPL_1, i & 1);
    digitalWrite(MPL_2, i >> 1);
    //for (int u = 0; u < 4; u++) { Serial.print(analogRead(u) > IKavailable[i][u]);  Serial.print(" "); } Serial.print(" "); // >> 2  /  analogRead(u)
    //for (byte u = 0; u < 4; u++) datIK[u] |= (analogRead(u) > 550) << i;
    for (byte u = 0; u < 4; u++) datIK[u] |= (analogRead(u) > IKavailable[i][u]) << i;
    //datIK[2] |= (analogRead(2) > IKavailable[i][2]) << i; 
  }
  //Serial.println();
  //for(int i = 0; i < 4; i++) { Serial.print(datIK[i]); Serial.print(" "); } Serial.println();
  for(int i = 0; i < 4; i++) if ((datIK[i] > 0) && !(datIKchesk)) datIKchesk = true;
  Serial.print ("linia: "); Serial.print(datIKchesk); Serial.print("; ");
  return datIKchesk; 
}

void filtor() { // дописать
  updateCam();
  /*Serial.println();
  Serial.println(ball.x);
  Serial.println(ball.y);*/
  int i = 0;
  if (ball.found) {
    for (i = ras_fil; i > 0; i--) {
      fil_ball[i][0] = fil_ball[i-1][0];
      fil_ball[i][1] = fil_ball[i-1][1];
    }
    fil_ball[0][0] = ball.x;
    fil_ball[0][1] = ball.y;
    i = 0;
    ball.x = 0;
    ball.y = 0;
    while ((i < ras_fil) && (fil_ball[i][0] > 0)) {
      ball.x += fil_ball[i][0];
      ball.y += fil_ball[i][1];
      i++;
    }
    ball.x /= i;
    ball.y /= i;
    ball.dir = calcAngle(ball.x, ball.y);
    ball.dist = calcDist(ball.x, ball.y);
  }
  else {
    i = ras_fil - 1;
    while ((i >= 0) && (fil_ball[i][0] == 0)) i++;
    fil_ball[i][0] = 0;
    fil_ball[i][1] = 0;
  }
  if (home.found) {
    for (i = ras_fil; i > 0; i--) {
      fil_home[i][0] = fil_home[i-1][0];
      fil_home[i][1] = fil_home[i-1][1];
    }
    fil_home[0][0] = home.x;
    fil_home[0][1] = home.y;
    i = 0;
    home.x = 0;
    home.y = 0;
    while ((i < ras_fil) && (fil_home[i][0] > 0)) {
      home.x += fil_home[i][0];
      home.y += fil_home[i][1];
      i++;
    }
    home.x /= i;
    home.y /= i;
    home.dir = calcAngle(home.x, home.y);
    home.dist = calcDist(home.x, home.y);
  }
  else {
    i = ras_fil - 1;
    while ((i >= 0) && (fil_home[i][0] == 0)) i++;
    fil_home[i][0] = 0;
    fil_home[i][1] = 0;
  }
  if (target.found) {
    for (i = ras_fil; i > 0; i--) {
      fil_target[i][0] = fil_target[i-1][0];
      fil_target[i][1] = fil_target[i-1][1];
    }
    fil_target[0][0] = target.x;
    fil_target[0][1] = target.y;
    i = 0;
    target.x = 0;
    target.y = 0;
    while ((i < ras_fil) && (fil_target[i][0] > 0)) {
      target.x += fil_target[i][0];
      target.y += fil_target[i][1];
      i++;
    }
    target.x /= i;
    target.y /= i;
    target.dir = calcAngle(target.x, target.y);
    target.dist = calcDist(target.x, target.y);
  }
  else {
    i = ras_fil - 1;
    while ((i >= 0) && (fil_target[i][0] == 0)) i++;
    fil_target[i][0] = 0;
    fil_target[i][1] = 0;
  }
}

void stop() {
  setSpeed(0, 0);
  setSpeed(1, 0);
  setSpeed(2, 0);
  setSpeed(3, 0);
  moving = 0;
}

void go_home() {
  /*if ((home.x > 120)) dir = home.dir/3; //  && ((home.y > 150) || (home.y < 50))
  else */dir = home.dir;
  heading = yaw;
  move();
}

void out_home() {
  /*if ((home.x > 120)) dir = home.dir/3; //  && ((home.y > 150) || (home.y < 50))
  else dir = home.dir - PI;*/
  dir = 0;
  heading = yaw;
  move();
}

void home_stabilisation() {
  if ((abs(CAM_CENTER_Y - home.y) > 10)) {// || (home.y > 150) || (home.y < 140))  {
    speed = basic_speed;//2;
    if (CAM_CENTER_Y > home.y) dir = -PI/4;
    else dir = PI/4;
    /*speed = basic_speed*abs(CAM_CENTER_Y - home.y)*0.1;
    if (CAM_CENTER_Y > home.y) dir = -PI*3/4;
    else dir = PI*3/4;*/
    move();
  }
  else {
    stop();
  }
}

void seen_ball_ataka() { // для нападающего
  if ((target.dir) && (target.found)) {
    digitalWrite(CENTER_LED, 1);
    digitalWrite(RIGHT_LED, 1);
    heading = yaw;
    //heading = target.dir*0.5;
    moving = 1;
  }
  else {
    digitalWrite(CENTER_LED, 0);
    digitalWrite(RIGHT_LED, 0);
    heading = yaw;
    moving = 1;
  }
  if ((ball.dist < 65) && (abs(ball.dir) > PI/10)) { // 65 // мяч рядом
    //stop();
    dir = ball.dir;  //obiezd_ball();
    if (ball.y > CAM_CENTER_Y) dir += PI/2;  // мяч слева
    else  dir -= PI/2;   // мяч справа
    moving = 1;
  }
  else if ((ball.dist < 45) && (abs(ball.dir) <= PI/15)) {  // мяч в "руках"  // 42/20
    //obiezd_ball();
    dir = target.dir*2; // vorota();
    //dir = ball.dir + target.dir;
    moving = 1;
  }
  else { // мяч далеко  
    dir = ball.dir*2;
    moving = 1;
  }
  //moving = 1;
}

void naezd_na_linia() { // для нападающего
  digitalWrite(CENTER_LED, 0);
  digitalWrite(RIGHT_LED, 1);
  if (datIKcheskTime + 1300 > millis()) datIKcheskTime2 = 1;
  else datIKcheskTime2 = 0;
  if ((datIKchesk) && (!dirIKchesk)) {
    datIKcheskTime = millis();
    dirIKchesk = 1;
    dir += PI;
    while (datIKcheskTime + 400 > millis()) {
      //heading = yaw;
      move();
    }
    //delay(500);
  }
  moving = 1;
  if (datIKcheskTime2) {
    stop();
    datIKcheskTime = millis();
    while (datIKcheskTime + 2000 > millis()) {}
    datIKcheskTime = millis();
  }
  //stop();
}

void block_ball() {
  if (abs(CAM_CENTER_Y - ball.y) > 5) { // 10
    heading = yaw;
    speed = basic_speed;
    if (CAM_CENTER_Y > ball.y) dir = -PI/2.3; // /2
    else dir = PI/2.3; // /2
    move();
  }
  else {
    stop();
  }
}

void dont_seen_home_go_home() {
  heading = yaw;
  speed = basic_speed;//*abs(CAM_CENTER_Y - ball.y)*0.1;
  dir = -PI - dir;
  move();
}

void ataka_ball(int tttt) {
  TIME = millis();
  while ((TIME + tttt > millis()) && (datIKchesk)) {  // && (ball.dist > lunka_ball)
    updateLights();
    updateCam();
    updateGyro();
    heading = yaw;
    dir = ball.dir;
    speed = basic_speed;
    move();
  }
}

void game() {  // my
  old_ball.found = 0;
  if (!((old_ball.x + delta_ball > ball.x) && (old_ball.x - delta_ball < ball.x) && (old_ball.y + delta_ball > ball.y) && (old_ball.y - delta_ball < ball.y))) old_ball.t = millis();
  if (millis() - old_ball.t >= 1000) old_ball.found = 1;                      
  
  old_ball.x = ball.x;
  old_ball.y = ball.y; 
  
  boolean B = ball.found;
  B = (ball.x > CAM_CENTER_X);
  boolean H = home.found; //B = 0;
  boolean L = datIKchesk;
  setLED(L,B,H);
  //=====================================
  Serial.print("home.dist: "); Serial.print(home.dist); Serial.print("; ");
  Serial.print("ball.dist: "); Serial.print(ball.dist); Serial.print("; "); 
  Serial.print("ball.dir: "); Serial.print(ball.dir); Serial.print("; "); 
  //Serial.print("ball.t: "); Serial.println(ball.t);
  /*if (datIKchesk) {
    TIME = millis();
    dir = dir - PI;
    while (TIME + 500 > millis()) {
      updateCam();
      updateGyro();
      heading = yaw;
      speed = basic_speed;
      move();
    }
  }
  else*/ 
  if ((home.found) && (home.dist >= rast_home)) { //  && (home.x < CAM_CENTER_X - radius)
    go_home();
  }
  else if ((home.found) && (!ball.found)) { // && (!ball.found) 
    home_stabilisation();
  }
  /*else if ((home.found) && (!ball.found) && ((home.dist < rast_home) || (home.x >= CAM_CENTER_X - radius))) { // не вызывается хз почему
    out_home();
  }*/
  else if ((home.found) && (ball.found)) {  // y ворот
    if (((ball.dist < lunka_ball) && (abs(ball.dir) < 0.3)) || (false))  ataka_ball(1000);
    else if ((ball.dist < 70) && (abs(ball.dir) < 1.5)) ataka_ball(2000);
    else block_ball();
    /*if ((ball.dist < rast_ball) && (old_ball.found)) ataka_ball();
    else block_ball();*/
    //block_ball();
  }
  /*else if ((!home.found) && (target.found)) { // не видим своих ворот, двигаемся в противоположную сторону вражеских ворот
    dont_seen_home_go_home();
  }*/
  else {
    //stop();
    /*setLED(1,1,1);
    delay(50);
    setLED(0,0,0);
    delay(50);*/
    heading = yaw;
    speed = 0;
    move(); 
  }
  //Serial.println(home.y);
}

void test() {
  
}

void loop() {
  updateGyro();
  heading = yaw;
  updateLights();
  updateCam();
  //filtor();
  //Serial.println(ball.x); Serial.println(ball.y); Serial.println();
  //Serial.println(yaw);
  speed = basic_speed;
  game();
  //heading = yaw; speed = 0; move();
  //if (moving) move();
  Serial.println();
}
