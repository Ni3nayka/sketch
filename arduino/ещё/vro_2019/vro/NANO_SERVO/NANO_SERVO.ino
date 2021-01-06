#include <Servo.h>
Servo S;

char i;

void setup() {
  Serial.begin(9600);
  S.attach(9);
  pinMode (13, OUTPUT);
  S.write(17);
}

void loop() {
  if ((Serial.available()) != 0) {
    i = Serial.read();
    if (i == 'O') {
      digitalWrite(13, 1);
      S.write(70);
      delay(500);
      S.write(17);
      delay(1000);
      digitalWrite(13, 0);
    }
    i = 0;
  }
}
