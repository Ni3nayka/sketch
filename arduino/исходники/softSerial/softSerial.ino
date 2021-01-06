#include <SoftwareSerial.h>
//SoftwareSerial SoftSerial(8, 9); // RX, TX
//SoftwareSerial SoftSerial(5, 6);
SoftwareSerial SoftSerial(10, 11);
char F = 0;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    F = Serial.read();
    if (F == '/') {
      SoftSerial.println();
    }
    else {
      SoftSerial.print(F);
    }
  }
  if (SoftSerial.available() > 0) {
    F = SoftSerial.read();
    if (F == '/') {
      Serial.println();
    }
    else {
      Serial.print(F);
    }
  }
}
