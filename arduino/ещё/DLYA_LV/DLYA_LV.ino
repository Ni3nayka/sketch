int sensorValue = 0;               //  порт датчика влажности
#define PWMA 11                    //  порт управления скоростью мотора
#define AIN1 10                    //  порт управления направлением движения мотора 1
#define AIN2 9                     //  порт управления направлением движения мотора 2

void setup()                       //  установка
{
  pinMode (PWMA, OUTPUT);          //  задаем вывод управляющих мотором портов
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  Serial.begin(9600);              //  задаем скорость вывода (для отладки)
  pinMode(13, OUTPUT);             //  задаем порт светодиода поломки
}

void loop()                        //  цикл
{
  sensorValue = analogRead(A0);    //  считываем значение с датчика влажности
  Serial.println(sensorValue);     //  выводим значение датчика влажности на ПК (для отладки)
  delay(200);                      //  задержка 200 мсек.
  if(sensorValue == 0) {           //  если значение датчика = 0 (ошибка) то
    digitalWrite(13, HIGH);        //  загорается светодиод ошибки
    digitalWrite (PWMA, 0);        //  остановка двигателя 
    digitalWrite (AIN1, LOW);       
    digitalWrite (AIN2, LOW); 
    delay (5000);                  //  задержка 5 сек.
  }
  else {                           //  иначе (ошибок нет) 
    digitalWrite(13, LOW);         //  светодиод ошибки гаснет
    if (sensorValue == 1023) {     //  если значение датчика влажности = 1023 (сухо) то 
      digitalWrite (PWMA, 0);      //  остановка двигателя
      digitalWrite (AIN1, LOW);    
      digitalWrite (AIN2, LOW);    
    }
    if (sensorValue < 1023 ) {     //  если значение датчика влажности < 1023 (влажно) то
      digitalWrite (PWMA, 150);    //  пуск двигателя 
      digitalWrite (AIN1, HIGH);     
      digitalWrite (AIN2, LOW);     
    }
  }
}                                  //  конец программы (выполняется в цикле)
