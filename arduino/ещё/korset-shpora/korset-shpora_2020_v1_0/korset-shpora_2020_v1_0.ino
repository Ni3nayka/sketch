#include "ABC.h"

#define BUTTON_PIN  A0

unsigned long int time = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  //Serial.println(morse_code(mas));
}

void loop() {
  read_symbol();
  out_symbol();
  //Serial.println(analogRead(A0));
}

boolean button_read() {
  boolean f = 0;
  if (analogRead(BUTTON_PIN) > 1000) digitalWrite(13, 0);
  else { digitalWrite(13, 1); f = 1; }
  delay(8);
  return f;
}

void button_input() {
  boolean button = button_read();
}

void out_symbol() {
  if (Serial.available() > 0) {
    char F = 0;
    F = Serial.read();
    if (abc_test(F)) {
      Serial.print(F);
      Serial.print(" - ");
      int mas[10] = {0};
      abc_code(F, mas);
      int i = 0;
      while ((mas[i] != 2) && (i < 10)) { Serial.print(mas[i]); i++; }
      Serial.println();
    }
  }
}

//void read_symbol(int (&mas)[10]) {
void read_symbol() {
  if (button_read()) {
    int mas[10] = {0};
    unsigned long int time1 = 0;
    boolean flag = 1, f = 0;
    int i;
    for (i = 0; i < 10; i++) mas[i] = 0;
    i = 0;
    time1 = millis();
    while (flag) {
      time1 = millis();
      while(button_read());
      if (time1 + 150 > millis()) mas[i] = 0;
      else mas[i] = 1;
      time1 = millis();
      while(!button_read() && (time1 + 400 > millis()));
      if (!button_read()) {
        mas[i+1] = 2;
        flag = 0;
      }
      //if (
      i++;
    }
    Serial.print(morse_code(mas));
    //for (i = 0; i < 10; i++) Serial.print(mas[i]); Serial.println();
    delay(50);
  }
}
