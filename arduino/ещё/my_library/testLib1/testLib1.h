/*#ifndef testLib1_h
#define testLib1_h
#include <Arduino.h> // если есть ардуино-функции
// код библиотеки
#endif
*/

#pragma once
#include <Arduino.h>
// описание класса
class Color {   // класс Color
public:
 Color(byte color = 5, byte bright = 30);
 void setColor(byte color);
 void setBright(byte bright);
 byte getColor();
 byte getBright();
private:
 byte _color;  // переменна€ цвета
 byte _bright; // переменна€ €ркости
};
