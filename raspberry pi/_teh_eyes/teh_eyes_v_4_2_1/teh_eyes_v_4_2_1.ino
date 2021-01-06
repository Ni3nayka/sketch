bool debug = 0; // for Serial output

#include <Wire.h>
#include <AFMotor.h>
#include <Servo.h> 
#include <PinChangeInt.h> // доп прерывания

#define D1 A3 // датчики (прерывание) на моторах
#define D2 A1
#define D3 A0
#define D4 A2

byte count_dat[13] = {0}; // нуливой пустой, на каждый датчик по три байта

void interruptFunction1() { interruptFunction(1); }
void interruptFunction2() { interruptFunction(2); }
void interruptFunction3() { interruptFunction(3); }
void interruptFunction4() { interruptFunction(4); }

void interruptFunction(int n) {
  if (count_dat[n*3] + 1 == 256) {
    if (count_dat[n*3-1] + 1 == 256) {
      count_dat[n*3-2]++;
      count_dat[n*3-1] = 0;
    }
    else count_dat[n*3-1]++;
    count_dat[n*3] = 0;
  }
  else count_dat[n*3]++;
}

unsigned long int encoder[5] = {0};
unsigned long int encoder_old[5] = {0};
unsigned long int encoder_time[5] = {0};
int speed_motor[5] = {0};
int need_speed_motor[5] = {0};
int need_speed_motor_local[5] = {0};
int old_need_speed_motor[5] = {0};
int old_real_speed[5][5] = {0};
int real_speed[5] = {0};

int SLAVE_ADDRESS = 0x04;

Servo S1; 
Servo S2;

#define S1_center 100
#define S2_center 100
#define S1_angle 60  // допустимый угол серворивода
#define S2_angle 60

int real_servo_angle[3] = {0, S1_center, S2_center}; // center
int need_servo_angle[3] = {0, S1_center, S2_center};
unsigned long int servo_time[3] = {0};

bool servo_control = 0;  // 0 - no control; 1 - yes control

AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

#define M 255 // доустимая скорость мотора
bool motor_control = 0; // 0 - no control; 1 - yes control (for encoder)
bool n_motor_control = 0; // control all motors

int flag = 0;
int in1 = 0;
int in2 = 0;
int flag2 = 1;

int num = 0;
int num2 = 1;
int flag_s = 0;
int in1_s = 0;
int in2_s = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(processMessage);
  Wire.onRequest(sendAnalogReading);
  S1.attach (9);
  S2.attach (10);
  S1.write(100);
  S2.write(100); 
  pinMode(D1, INPUT_PULLUP); 
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
  attachPinChangeInterrupt(D1, interruptFunction1, FALLING);  // CHANGE
  attachPinChangeInterrupt(D2, interruptFunction2, FALLING); 
  attachPinChangeInterrupt(D3, interruptFunction3, FALLING);
  attachPinChangeInterrupt(D4, interruptFunction4, FALLING);
  delay(500);
  //test_servo();
}

void loop() {
  serial_input();
  motor_encoder_control();
  servo_angle_control();
  //if (millis()%1000 == 0) print_counts2(); 
}

void test() {
  
}

void serial_input() {
  if (Serial.available() > 0) {
    char F = Serial.read();
    if      (F == '1') num = num*10 + 1;
    else if (F == '2') num = num*10 + 2;
    else if (F == '3') num = num*10 + 3;
    else if (F == '4') num = num*10 + 4;
    else if (F == '5') num = num*10 + 5;
    else if (F == '6') num = num*10 + 6;
    else if (F == '7') num = num*10 + 7;
    else if (F == '8') num = num*10 + 8;
    else if (F == '9') num = num*10 + 9;
    else if (F == '0') num = num*10;
    else if (F == '-') num2 = -1;
    else if (F == 'D') {
      debug = 1;
      if (debug) Serial.println("debug: on");
    }
    else if (F == 'd') {
      if (debug) Serial.println("debug: off");
      debug = 0;
    }
    else if (F == 'M') {
      motor_control = 1;
      if (debug) Serial.println("motor_control: on");
      for(int y = 1; y <=4; y++) {
        old_need_speed_motor[y] = need_speed_motor[y];
        need_speed_motor_local[y] = need_speed_motor[y];
      }
    }
    else if (F == 'm') {
      motor_control = 0;
      if (debug) Serial.println("motor_control: off");
      for(int y = 1; y <=4; y++)  motor_s(y, need_speed_motor[y]);
    }
    else if (F == 'N') {
      n_motor_control = 1;
      if (debug) Serial.println("n_motor_control: on");
    }
    else if (F == 'n') {
      n_motor_control = 0;
      if (debug) Serial.println("n_motor_control: off");
    }
    else if (F == 'S') {
      servo_control = 1;
      if (debug) Serial.println("servo_control: on");
    }
    else if (F == 's') {
      servo_control = 0;
      if (debug) Serial.println("servo_control: off");
    }
    else if (F == ';') {
      if (flag_s == 0) {
        in1_s = num*num2;
        num = 0;
        num2 = 1;
        flag_s++;
      }
      else {
        in2_s = num*num2;
        num = 0;
        num2 = 1;
        if (debug) {
          Serial.print("move(");
          Serial.print(in1_s);
          Serial.print(", ");
          Serial.print(in2_s);
          Serial.println(");");
        }
        move(in1_s, in2_s + 100);
        flag_s = 0;
      }
    }
    else if (F == 'c') {
      for (int i = 1; i <= 12; i++) count_dat[i] = 0;
      for (int i = 1; i <= 4; i++) encoder[i] = 0;
      for (int i = 1; i <= 4; i++) encoder_old[i] = 0;
      if (debug) Serial.println("clean encoder");
    }
    else if (F == 'r') {
      encoder_translater();
      for (int i = 1; i <= 4; i++) {
        Serial.print(encoder[i]);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}

void encoder_translater() {
  for (int i = 1; i <= 4; i++) encoder[i] = count_dat[i*3 - 2]*256*256  + count_dat[i*3 - 1]*256  + count_dat[i*3];
}

void print_counts() {
  for(int i = 1; i <= 12; i++) {
    Serial.print(count_dat[i]); 
    Serial.print(" ");
    if (i%3 == 0) Serial.print(" ");
  }
  Serial.println();
}

void move(int a, int n) {
  if ((a > 0) && (a < 5)) { 
    //n = map(n, 0, 200, -M, M);
    n -= 100;
    motor(a, n);
  }
  else if ((a == 5) || (a == 6)) {
    //if (abs(n) > 100) n = abs(n)/n*100;
    if (n > 200) n = 200;
    if (n < 0) n = 0;
    if (a == 5) {
      n = map(n, 0, 200, -S1_angle, S1_angle) + S1_center;
      //Serial.println(n);
      servo(1, n);
    }
    if (a == 6) {
      n = map(n, 0, 200, -S2_angle, S2_angle) + S2_center;
      servo(2, n);
    }
  }
}

void processMessage(int n) {
  char F = Wire.read();
  if (F == 'c') { // clean encoder
    for (int i = 1; i <= 12; i++) count_dat[i] = 0;
    for (int i = 1; i <= 4; i++) encoder[i] = 0;
    for (int i = 1; i <= 4; i++) encoder_old[i] = 0;
  }
  else if (F == 'M') {
    motor_control = 1;
    for(int y = 1; y <=4; y++) {
      old_need_speed_motor[y] = need_speed_motor[y];
      need_speed_motor_local[y] = need_speed_motor[y];
    }
  }
  else if (F == 'm') {
    motor_control = 0;
    for(int y = 1; y <=4; y++)  motor_s(y, need_speed_motor[y]);
  }
  else if (F == 'N') n_motor_control = 1;
  else if (F == 'n') n_motor_control = 0;
  else if (F == 'S') servo_control = 1;
  else if (F == 's') servo_control = 0;
  else if (flag == 0) {
    in1 = byte(F);  // [1, 6]
    flag++;
  }
  else {
    in2 = byte(F); // [0, 200]
    move(in1, in2);
    flag = 0;
  }
}
 
void sendAnalogReading() {
  Wire.write(count_dat[flag2]);
  flag2++;
  if (flag2 > 12) flag2 = 1;
}

void test_servo() {
  servo(1,160); delay(2000);
  servo(1,40); delay(2000);
  servo(1,100); delay(2000);
  
  servo(2,160); delay(2000);
  servo(2,40); delay(2000);
  servo(2,100); delay(2000);
}

void servo(int ser, int finish) {
  if (ser == 1) {
    if (finish > S1_center + S1_angle) finish = S1_center + S1_angle;
    if (finish < S1_center - S1_angle) finish = S1_center - S1_angle; 
    if (!servo_control) real_servo_angle[1] = finish;
    need_servo_angle[1] = finish; 
  }
  if (ser == 2) {
    if (finish > S2_center + S2_angle) finish = S2_center + S2_angle;
    if (finish < S2_center - S2_angle) finish = S2_center - S2_angle; 
    if (!servo_control) real_servo_angle[2] = finish;
    need_servo_angle[2] = finish; 
  }
  if (!servo_control) servo_w(ser, finish);
}

void servo_w(int ser, int angle) {
  if (ser == 1) S1.write(angle);
  if (ser == 2) S2.write(angle);
}

void servo_angle_control() { // 5;-100;6;-100;
  if (servo_control) {
    for (int i = 1; i <= 2; i++) {
      if ((real_servo_angle[i] != need_servo_angle[i]) && (servo_time[i] + 10 < millis())) { 
        if (real_servo_angle[i] > need_servo_angle[i]) real_servo_angle[i]--;
        else  real_servo_angle[i]++;
        servo_w(i, real_servo_angle[i]);
        servo_time[i] = millis();
      }
    }
  }
  /*if(real_servo_angle[ser-1] != finish) {
    if(real_servo_angle[ser-1] < finish) {
      for(int i = real_servo_angle[ser-1]; i < finish; i++) { 
        if (ser == 1) S1.write(i);
        if (ser == 2) S2.write(i);
        delay(10);
      }  
    }
    else {
      for(int i = real_servo_angle[ser-1]; i > finish; i--) { 
        if (ser == 1) S1.write(i);
        if (ser == 2) S2.write(i);
        delay(10);
      }
    }
  }
  real_servo_angle[ser-1] = finish;*/
}

int poww(int a, int b) {
    int c = a;
    if (b < 0) return 0;
    else if (b == 0) return 1;
    else {
        //int d = a;
        for(; b > 1; b--) c *= a;
        return c;
    }
}

void bubble(int *mas, int v) {
    for(int i = 0; i <= v; i++) {
        for(int u = 0; u < v; u++) {
            if (mas[u+1] < mas[u]) {
                int t = mas[u+1];
                mas[u+1] = mas[u];
                mas[u] = t;
            }
        }
    }
}

void motor(int n, int speed) {
  speed = cut(speed, 100);
  if ((need_speed_motor[n] != speed) && (n > 0) && (n < 5)) need_speed_motor[n] = speed;
  if (!motor_control) motor_s(n, speed);
}

int cut(int a, int b) {
  if (abs(a) > b) a = abs(a)/a*b;
  return a;
}

int znak(int a) {
  if      (a > 0) return  1;
  else if (a < 0) return -1;
  else            return  0;
}

void motor_encoder_control() { // 1;0;2;0;3;0;4;0;
  if (motor_control) {
    encoder_translater();
    //float motor_control_K = 5; // 5
    float motor_control_K  = 0.15;
    float motor_control_D  = 1;
    float motor_control_K2 = 0.7;
    //float motor_control_D2 = 1;
    int timer = 250;
    for (int i = 1; i <= 4; i++)  {
      if (need_speed_motor[i] == 0) {
        speed_motor[i] = 0;
        for(int u = 4; u >= 0; u--) old_real_speed[u][i] = 0;
      }
      else if ((speed_motor[i] == 0 || (need_speed_motor[i]*old_need_speed_motor[i] < 0))) {
        speed_motor[i] = znak(need_speed_motor[i]);
        old_need_speed_motor[i] = need_speed_motor[i];
        encoder_old[i] = encoder[i];
        encoder_time[i] = millis();
      }
      else if (((int(millis()/timer) > int(encoder_time[i]/timer))) || (int(encoder[i]/10) > int(encoder_old[i]/10))) { 
        real_speed[i] = 0;
        if (encoder[i] > encoder_old[i]) real_speed[i] = znak(speed_motor[i])*int((encoder[i] - encoder_old[i])/float((millis() - encoder_time[i])/1000.));
        
        for(int u = 4; u > 0; u--) old_real_speed[u][i] = old_real_speed[u-1][i];
        old_real_speed[0][i] = real_speed[i];
        int mediana[5];
        for(int u = 4; u >= 0; u--) mediana[u] = old_real_speed[u][i];
        bubble(mediana, 4);
        real_speed[i] = mediana[2];

        //int need_speed_motor_local[i] = need_speed_motor[i];
        int b; // delta
        
        if (n_motor_control) {
          int i_max = 0, e_max = 0, e_new;
          for (int x = 1; x <= 4; x++) {
            if (abs(need_speed_motor[x]) > 0) { 
              e_new = map(real_speed[x], 0, need_speed_motor[x], 0, 100) - 100;
              // скорости по модулю 
//              if      (real_speed[x] > need_speed_motor[x]) e_new > 0; 
//              else if (real_speed[x] < need_speed_motor[x]) e_new < 0;
//              else if (real_speed[x]== need_speed_motor[x]) e_new = 0;
              if (abs(e_new) > abs(e_max)) {
                i_max = x;
                e_max = e_new; 
              }
            }
          }
          if ((abs(e_max) > 10) && (i_max != i)) { // иначе стабилизация не нужна
            e_max = map(e_max, 0, 100, 0, need_speed_motor[i]);
            need_speed_motor_local[i] = need_speed_motor[i] + e_max*motor_control_K2;
          }
          else need_speed_motor_local[i] = need_speed_motor[i];
        }
        else need_speed_motor_local[i] = need_speed_motor[i];
        
        b = (need_speed_motor_local[i] - real_speed[i])*motor_control_K;
        b = cut(b, motor_control_D);
        //b = znak(b); // костыль
        if ((real_speed[i] == 0) && (mediana[0] == 0)) { //  || (real_speed[i]*speed_motor[i] < 0)
          if (need_speed_motor_local[i] > 0) speed_motor[i] = speed_motor[i] + 80;
          else speed_motor[i] = speed_motor[i] - 80;
        }
        else if (abs(need_speed_motor_local[i] - real_speed[i]) > 30) {
          if (need_speed_motor_local[i] > real_speed[i]) speed_motor[i] += 2;
          else speed_motor[i] -= 2; 
        }
        else speed_motor[i] += b;
        
        if (abs(speed_motor[i]) > 100) speed_motor[i] = znak(speed_motor[i])*100;
        Serial.print(i); Serial.print(") "); Serial.print(real_speed[i]); Serial.print(" "); Serial.println(speed_motor[i]);
        encoder_time[i] = millis();
        encoder_old[i] = encoder[i];
      }
      motor_s(i, speed_motor[i]);
    }
  }
}

void motor_s(int n, int speed) {
  speed = map(speed, -100, 100, -M, M);
  speed = cut(speed, 255);
  if (n == 1) {
    if (speed == 0) M1.run(RELEASE);
    else if (speed > 0) M1.run(FORWARD);
    else M1.run(BACKWARD);
    M1.setSpeed(abs(speed));
  }
  else if (n == 2) {
    if (speed == 0) M2.run(RELEASE);
    else if (speed > 0) M2.run(FORWARD);
    else M2.run(BACKWARD);
    M2.setSpeed(abs(speed));
  }
  else if (n == 3) {
    if (speed == 0) M3.run(RELEASE);
    else if (speed > 0) M3.run(FORWARD);
    else M3.run(BACKWARD);
    M3.setSpeed(abs(speed));
  }
  else if (n == 4) {
    if (speed == 0) M4.run(RELEASE);
    else if (speed > 0) M4.run(FORWARD);
    else M4.run(BACKWARD);
    M4.setSpeed(abs(speed));
  }
}
