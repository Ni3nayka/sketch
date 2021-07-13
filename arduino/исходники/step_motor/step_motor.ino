// картинки по подключению:
// https://yandex.ru/images/search?text=подключение%20шаговых%20двигателей&stype=image&lr=213&source=wiz&pos=0&img_url=https%3A%2F%2Fsun9-30.userapi.com%2Fc836735%2Fv836735803%2F2b556%2FIe_t8m5qo7Q.jpg&rpt=simage
// https://yandex.ru/images/search?text=распиновка%20ардуино%20монстр%20шилд%20l298n&stype=image&lr=213&source=wiz&pos=1&img_url=https%3A%2F%2Fi.pinimg.com%2Foriginals%2Fb1%2F3a%2Fd2%2Fb13ad2c13e5c1ab897bafda0788c8802.jpg&rpt=simage
// методичка:
// https://robotchip.ru/obzor-drayvera-motora-na-l298n/

#include <Stepper.h>
 
const int stepsPerRevolution = 1000;   // Количество шагов 
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);
 
void setup()
{
  myStepper.setSpeed(60);             // Установка скорости 60 об/мин 
  Serial.begin(9600);  
}
 
void loop() 
{
                 
  Serial.println("clockwise");       
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
