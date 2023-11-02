#include <SPI.h>
#include <SD.h>
File myFile;

void setup() {
  if (!SD.begin(10)) error();
}

void loop() {
  float v = analogRead(A0)/204.6;
  unsigned long int t = millis()/1000;
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    delay(1000);
}

void error() {
  pinMode(13,OUTPUT);
  while (1) {
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    delay(1000);
  }
}

