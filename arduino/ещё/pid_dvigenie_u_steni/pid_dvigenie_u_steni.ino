#include <NewPing.h>
#define TRIGGER_PIN  6 // 12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5 // 11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Максимальное расстояние, которое мы контролируем (в сантиметрах). Максимальное расстояние подобных датчиков находится в диапазоне 400-500см.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Настройка пинов и максимального расстояния
int ras = 0;

#define SP     11
#define DP     13
#define SL     10
#define DL     12

int p   = 0;
int i   = 0;
int d   = 0;
int pid = 0;

int  e1 = 0;
int  e2 = 0;
byte o [25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//--------------------------------------------------------------------
#define M   100  // средняя скорость мотора
#define l   10   // расстояние до стены
#define k   10   // пропорциональный коэффицент
#define k2  50   // диферинциальный коэффицент
#define k3  50   // интегральный коэффицент

//--------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);  
  pinMode(4, OUTPUT);
  digitalWrite(DL, HIGH );
  digitalWrite(DP, HIGH );
  while ((digitalRead(9)) == 1) { delay(10); }
  delay(1000);
}

void loop() {
  ras = sonar.ping() / US_ROUNDTRIP_CM;
  if ((ras == 0) || (ras > (M/k + l))) { ras = M/k + l; }
  e1 = ras - l;           // ошибка (сейчас) динамическая
  p = k*e1;               // пропорциональный
  i = k3*();        // интегральный
  d = k2*(e1 - e2);       // дифференциальный
  pid = p + i + d;
  analogWrite(SL, (M - pid));
  analogWrite(SP, (M + pid));
  e2 = e1;
}

/*
  ras = sonar.ping() / US_ROUNDTRIP_CM;
  if ((ras == 0) || (ras > (M/k + l))) { ras = M/k + l; }
  e1 = ras - l;
  analogWrite(SL, ( M - (e1*k + k2*(e1 - e2))));
  analogWrite(SP, ( M + (e1*k + k2*(e1 - e2))));
  e2 = e1;
*/

/*
  rast();
  delay(100);
  analogWrite(SL, (M - (ras - l)*k));
  analogWrite(SP, (M + (ras - l)*k));
*/

void rast(){
  ras = sonar.ping() / US_ROUNDTRIP_CM;
  //Serial.println(ras);
}   

void ZUM()        {
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
}
