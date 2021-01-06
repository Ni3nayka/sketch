#include "config.h"
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps_V6_12.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;

#define INTERRUPT_PIN 21  // use pin 2 on Arduino Uno & most boards
#define LED_PIN 11 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 gy;         // [x, y, z]            gyro sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, '\r', '\n' };

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
  mpuInterrupt = true;
}

camBlock ball, home, target;
Pixy2 pixy;

double yaw = 0;
double yaw_zero = 0;
short speed = 0;
float dir = 0;
float heading = 0;
float k = 180;

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

void move() {
  int u = heading * k;
//  u = min(100, max(-100, u));
  setSpeed(0,  -speed * cos((dir + 0.785398163397448)) + u);
  setSpeed(1,  speed * cos((dir - 0.785398163397448)) + u);
  setSpeed(2,  speed * cos((dir + 0.785398163397448)) + u);
  setSpeed(3,  -speed * cos((dir - 0.785398163397448)) + u);
}

void updateCam() {
  ball.found = false;
  home.found = false;
  target.found = false;

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

        ball.found = true;
        ball.t = millis();
      }
      if (pixy.ccc.blocks[i].m_signature == HOME_GOAL) {
        home.x = pixy.ccc.blocks[i].m_x;
        home.y = pixy.ccc.blocks[i].m_y;
        home.w = pixy.ccc.blocks[i].m_width;
        home.h = pixy.ccc.blocks[i].m_height;

        home.dir = calcAngle(home.x, home.y);
        home.dist = calcDist(home.x, home.y);

        home.found = true;
        home.t = millis();
      }
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
    }
  }

  pixy.setLED(0, ball.found * 255, 0);

  ball.found = checkTimer(ball.t, 600);
  home.found = checkTimer(home.t, 300);
  target.found = checkTimer(target.t, 300);
}

void setup() {
  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);
  Serial.begin(115200);

  // Camera init
  pixy.init();
  pixy.setLED(0, 0, 0);

  // Motors init
  for (int i = 0; i < 4; ++i) {
    pinMode(motors_pwm[i], OUTPUT);
    pinMode(motors_in1[i], OUTPUT);
    pinMode(motors_in2[i], OUTPUT);
  }
  pinMode(L_STANDBY, OUTPUT);
  digitalWrite(L_STANDBY, HIGH);
  pinMode(R_STANDBY, OUTPUT);
  digitalWrite(R_STANDBY, HIGH);

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  // initialize serial communication
  // (115200 chosen because it is required for Teapot Demo output, but it's
  // really up to you depending on your project)
  Serial.begin(115200);
  while (!Serial); // wait for Leonardo enumeration, others continue immediately

  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);

  // verify connection
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  // load and configure the DMP
  Serial.println(F("Initializing DMP..."));
  devStatus = mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(195);
  mpu.setYGyroOffset(24);
  mpu.setZGyroOffset(-28);
  mpu.setXAccelOffset(-2660);
  mpu.setYAccelOffset(-2831);
  mpu.setZAccelOffset(509);
  // make sure it worked (returns 0 if so)
  if (devStatus == 0) {
    // Calibration Time: generate offsets and calibrate our MPU6050
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    Serial.println();
    mpu.PrintActiveOffsets();
    // turn on the DMP, now that it's ready
    Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);

    // enable Arduino interrupt detection
    Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
    Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
    Serial.println(F(")..."));
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;

    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }

  // configure LED for output
  pinMode(LED_PIN, OUTPUT);
}

void updateGyro() {
  if (!dmpReady) return;
  while (!mpuInterrupt && fifoCount < packetSize) {
    if (mpuInterrupt && fifoCount < packetSize) {
      fifoCount = mpu.getFIFOCount();
    }
  }
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();
  fifoCount = mpu.getFIFOCount();
  if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024) {
    mpu.resetFIFO();
    fifoCount = mpu.getFIFOCount();
    Serial.println(F("FIFO overflow!"));
  } else if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT)) {
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    yaw = ypr[0];
    if (digitalRead(LEFT_BTN) && digitalRead(RIGHT_BTN))
      yaw_zero = yaw;
    yaw = constrainAngle(yaw - yaw_zero);
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  }
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
}

void loop() {
  updateGyro();
  updateCam();
  heading = yaw;
  speed = 300;
  followBall();
  move();
}
