#include <iarduino_RF433_Transmitter.h>
iarduino_RF433_Transmitter radio(2); // (пин)

int data[2]; // массив для обмена данными

void setup(){
  radio.begin();
  radio.setDataRate(i433_1KBPS); // Указываем скорость приёма данных (i433_5KBPS, i433_4KBPS, i433_3KBPS, i433_2KBPS, i433_1KBPS, i433_500BPS, i433_100BPS), i433_1KBPS - 1кбит/сек
  radio.openWritingPipe(5); // Открываем 5 трубу (от 0 до 7)
}

void loop(){
  data[0] = analogRead(A0);
  data[1] = analogRead(A1);
  radio.write(&data, sizeof(data));
}
