#include <iarduino_RF433_Receiver.h>
iarduino_RF433_Receiver radio(2); // (пин)

int data[2]; // массив для обмена данными

#define PWM_R 10 
#define DIR_R 12
#define PWM_L 11
#define DIR_L 13

void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(i433_1KBPS); // Указываем скорость приёма данных (i433_5KBPS, i433_4KBPS, i433_3KBPS, i433_2KBPS, i433_1KBPS, i433_500BPS, i433_100BPS), i433_1KBPS - 1кбит/сек
  radio.openReadingPipe(5); // Открываем 5 трубу (от 0 до 7)
  radio.startListening();
  pinMode(PWM_R,OUTPUT);
  pinMode(PWM_L,OUTPUT);
  pinMode(DIR_R,OUTPUT);
  pinMode(DIR_L,OUTPUT);
}
void loop(){
  if(radio.available()){
    radio.read(&data, sizeof(data));
    for (int i = 0; i<2; i++) {
      data[i] = constrain(data[i]/2 - 255,-255,255);
      if (abs(data[i])<10) data[i] = 0;
    }
    // Serial.print(data[0]);
    // Serial.print(" ");
    // Serial.println(data[1]);
    int l = data[0]+data[1];
    int r = data[0]-data[1];
    digitalWrite(DIR_L,l>0);
    analogWrite(PWM_L,abs(l));
    digitalWrite(DIR_R,r>0);
    analogWrite(PWM_R,abs(r));
  }
}
