#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;
int t6 = 0;

void setup() {
  Serial.begin(9600);
  //while (!Serial) ;
}

void loop() {
  Time();
}

void Time() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    t1 = tm.Hour;
    t2 = tm.Minute;
    t3 = tm.Second;
    t4 = tm.Day;
    t5 = tm.Month;
    t6 = tmYearToCalendar(tm.Year);
    Serial.print(t1);
    Serial.print(":");
    Serial.print(t2);
    Serial.print(":");
    Serial.print(t3);
    Serial.print("-");
    Serial.print(t4);
    Serial.print(".");
    Serial.print(t5);
    Serial.print(".");
    Serial.print(t6);
    Serial.println();
  }
}
