#include <keyboard.h>

void setup() {
  keyboard_setup();
  Serial.begin(9600);
}

void loop() {
  Serial.println(matrix());
}
