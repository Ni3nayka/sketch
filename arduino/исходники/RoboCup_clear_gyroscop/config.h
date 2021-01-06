#ifndef CONFIG_H
#define CONFIG_H

#define BASIC_SPEED 300

#define ENEMY_GOAL 2
#define WHITE_LINE 300

#define CAM_CENTER_X 166
#define CAM_CENTER_Y 122

#define KICKER 47
#define BALL_SENSOR 43

#define L_STANDBY 4
#define R_STANDBY 10

#define LEFT_LED 11
#define CENTER_LED 7
#define RIGHT_LED 17

#define LEFT_BTN 13
#define CENTER_BTN 9
#define RIGHT_BTN 5

#define MPL_1 33
#define MPL_2 35

#if ENEMY_GOAL == 3
#define HOME_GOAL 2 // 2 - yellow, 3 - blue
#endif // ENEMY_GOAL == 3
#if ENEMY_GOAL == 2
#define HOME_GOAL 3 // 2 - yellow, 3 - blue
#endif // ENEMY_GOAL == 2

const byte motors_pwm[4] = {2, 12, 8, 6};
const byte motors_in1[4] = {38, 40, 46, 32};
const byte motors_in2[4] = {36, 42, 44, 34};

#include <math.h>
#include <Pixy2.h>

struct camBlock {
  int x;
  int y;
  int w;
  int h;
  float dir;
  float dist;
  bool found;
  uint32_t t;
};

template <typename T>
T sign(T value);

void setSpeed(byte port, short motor_speed);
void move();


#endif
