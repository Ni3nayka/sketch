#ifndef CONFIG_H
#define CONFIG_H

#define lunka_ball 41
#define radius 50 // real 40
#define delta_ball 10
int rast_home = 50; // 55
#define rast_ball 85 //
#define basic_speed 200
#define BASIC_SPEED 300
#define SNOOZE_DRIBBLER_SPEED 80
#define BASIC_DRIBBLER_SPEED 80
#define BASIC_K 200


int ENEMY_GOAL = 3; // 2 - yellow, 3 - blue // вражеские ворота
int  HOME_GOAL = 2;
#define WHITE_LINE 300

#define CAM_CENTER_X 160 // 166
#define CAM_CENTER_Y 134 //122

#define GYRO_OFFSET_XG 192
#define GYRO_OFFSET_YG -2
#define GYRO_OFFSET_ZG -33
#define GYRO_OFFSET_ZA 531

#define INTERRUPT_PIN 21
#define DRIBBLER_SPEED 3
#define DRIBBLER_DIR 14
#define KICKER 47
#define BALL_SENSOR 43

#define MOTOR_A 0 // cw
#define MOTOR_B 1 // cw
#define MOTOR_C 2 // ccw
#define MOTOR_D 3 // cw
#define L_STANDBY 4
#define R_STANDBY 10
#define MPL_1 33
#define MPL_2 35

#define LEFT_LED 11
#define CENTER_LED 7
#define RIGHT_LED 17

#define LEFT_BTN 13
#define CENTER_BTN 9
#define RIGHT_BTN 5

#define MPL_1 33
#define MPL_2 35

/*#if ENEMY_GOAL == 3
#define HOME_GOAL 2 // 2 - yellow, 3 - blue
#endif // ENEMY_GOAL == 3
#if ENEMY_GOAL == 2
#define HOME_GOAL 3 // 2 - yellow, 3 - blue
#endif // ENEMY_GOAL == 2*/

const byte motors_pwm[4] = {2, 12, 8, 6};
const byte motors_in1[4] = {36, 42, 46, 34};
const byte motors_in2[4] = {38, 40, 44, 32};

#include <math.h>
#include <Pixy2.h>
Pixy2 pixy;

struct camBlock {
  int x;
  int y;
  int w;
  int h;
  float dir;
  float dist;
  bool found;
  uint32_t t;
  uint32_t T;
};

bool blinkState = false;

template <typename T>
T sign(T value);

double constrainAngle(double x);
float calcAngle(int x, int y);
float calcAngle(camBlock b);
float calcDist(camBlock b);
void dribbler(short speed);

#endif
