#include <RTClib.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;
//int rtc = 0;
//RTC_DS1307 rtc;


void setup() {
  Serial.begin(9600);
  while (!Serial) ;
}

void loop() {
  //rtc.adjust(DateTime(_DATE_,_TIME_));
  tmElements_t tm;
  if (RTC.read(tm)) {
    t1 = tm.Hour;
    t2 = tm.Minute;
    t3 = tm.Day;
    t4 = tm.Month;
    t5 = tmYearToCalendar(tm.Year);
    Serial.print(t1);
    Serial.print('.');
    Serial.print(t2);
    Serial.print('.');
    Serial.print(t3);
    Serial.print('.');
    Serial.print(t4);
    Serial.print('.');
    Serial.print(t5);
    Serial.println();
  }
}

