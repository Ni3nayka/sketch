#include <symbol_Serial.h>

void setup() {
  Serial.begin(9600);
}
void loop() {
  char symbol = abc_read();
  if (symbol) Serial.println(symbol);
}
