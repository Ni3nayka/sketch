/*#ifndef testLib1_h
#define testLib1_h
#include <Arduino.h> // ���� ���� �������-�������
// ��� ����������
#endif
*/

#pragma once
#include <Arduino.h>
// �������� ������
class Color {   // ����� Color
public:
 Color(byte color = 5, byte bright = 30);
 void setColor(byte color);
 void setBright(byte bright);
 byte getColor();
 byte getBright();
private:
 byte _color;  // ���������� �����
 byte _bright; // ���������� �������
};
