#include <keyboard.h>

char F, F0;

void setup() {
  keyboard_setup();
  Serial.begin(9600);
}

void loop() {
  F = matrix();
  if ((F > 0) && (F0!= F)) Serial.println(F);
  F0 = F;
}
