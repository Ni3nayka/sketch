#include <testLib1.h>
Color myColor(10);  // создаём объект myColor, указав _color (получим 10, 30)
Color myColor2(10, 20);  // указываем цвет и яркость! (получим 10, 20)
Color myColor3;  // без инициализации (получим 5, 30)
void setup() {
  Serial.begin(9600);
  Serial.println(myColor.getColor());   // 10
  Serial.println(myColor2.getBright()); // 20
  Serial.println(myColor3.getColor());  // 5
}
void loop() {
}
