#include <testLib1.h> // подключаем заголовок обязательно
#include <Arduino.h> // нужно для ардуино-функций
// реализация методов
Color::Color(byte color = 5, byte bright = 30) { // конструктор
 _color = color;   // запоминаем
 _bright = bright;
}
void Color::setColor(byte color) {_color = color;}
void Color::setBright(byte bright) {_bright = bright;}
byte Color::getColor() {return _color;}
byte Color::getBright() {return _bright;}
