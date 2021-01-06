#include "navigator_v2.1.h"

int i = 1;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  t_start = 11;
  navigator();
  i = 1;
  //while ((i < 40) && (dor[0][i] < 900)) {
  while ((i < 40) && (mas[i] < 900)) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(dor[0][i]);
    i++;
  }
  i = 1;
  Serial.println("------------");
  while ((i < 40) && (pyt[i] > 0)) {
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
}

void loop() {
  
}
