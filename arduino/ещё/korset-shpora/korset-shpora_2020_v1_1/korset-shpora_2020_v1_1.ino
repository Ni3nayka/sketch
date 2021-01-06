#include <symbol_Serial.h> // только для работы с UART вводом 
#include <morse_code.h>

#define BUTTON_PIN  A0

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  IN_code();
  OUT_code();
  //Serial.println(analogRead(A0));
}

void button_input() {
  boolean button = button_read(BUTTON_PIN);
}

void OUT_code() {
  char F = symbol_read(); // из библиотеки <symbol_Serial.h> (чтобы получать данные без мусора)
  if (F) {
    Serial.print(F);
    Serial.print(" - ");
    int mas[10] = {0};
    abc_code(F, mas);
    int i = 0;
    while ((mas[i] != 2) && (i < 10)) { Serial.print(mas[i]); i++; }
    Serial.println();
  }
}


void IN_code() { // получение буквы с нажатий кнопки
  char F = read_morse(BUTTON_PIN); // считываем букву по нажатиям кнопки на пине BUTTON_PIN и записываем в F, а если буква не введена, то будет записано 0
  if (F) Serial.print(F); // если данные пришли (F  не равно 0) то выводим в монитор порта
}
