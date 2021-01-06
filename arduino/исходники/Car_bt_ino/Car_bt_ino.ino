/*
 * Created by DIY ENERGY
 * Проект: Управление машинкой с помощью Android
 * Больше информации тут: https://www.youtube.com/VLADYOUTUBER
 */
 
//L298N Драйвер двигателей
  const int motorA1  = 10;  // L298N'in IN3
  const int motorA2  = 12;  // L298N'in IN1
  const int motorB1  = 11; // L298N'in IN2
  const int motorB2  = 13;  // L298N'in IN4


  int i=0; //Случайная переменная, назначенная циклам
  int j=0; //Случайная переменная, назначенная циклам
  int state; //Переменная сигнала от устройства Bluetooth
  int vSpeed=255;     // Стандартная скорость может принимать значение от 0-255

void setup() {
    // Давайте определим наши контакты
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
    // Давайте откроем последовательный порт со скоростью 9600
    Serial.begin(9600);
}
 
void loop() {
  //Остановите автомобиль, когда соединение Bluetooth отключено.
 //(Удалите "//" подстроки для активации.)
  if(digitalRead(state)==LOW) { state='S'; }    

  //Сохранить входящие данные в переменную " состояние
    if(Serial.available() > 0){     
      state = Serial.read();   
    }

  // 4 уровня скорости, которые можно регулировать из приложения.(Значения должны быть между 0-255)
 if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=25;}
    else if (state == '2'){
      vSpeed=50;}
    else if (state == '3'){
      vSpeed=75;}
    else if (state == '4'){
      vSpeed=100;}
    else if (state == '5'){
      vSpeed=125;}
    else if (state == '6'){
      vSpeed=150;}
    else if (state == '7'){
      vSpeed=175;}
    else if (state == '8'){
      vSpeed=200;}
    else if (state == '9'){
      vSpeed=225;}
    else if (state == 'q'){
      vSpeed=255;}
     
  /***********************İleri****************************/
  //Если входящие данные "F" автомобиль идет вперед.
    if (state == 'F') {
      analogWrite(motorA1, vSpeed);digitalWrite(motorA2,HIGH);
      analogWrite(motorB1, vSpeed);digitalWrite(motorB2,HIGH); 
    }
  /**********************İleri Sol************************/
  //Автомобиль идет вперед влево(по диагонали), если входящие данные " G.
    else if (state == 'G') {
      analogWrite(motorA1,0 );digitalWrite(motorA2,HIGH);  
        analogWrite(motorB1,vSpeed);digitalWrite(motorB2, HIGH); 
    }
  /**********************İleri Sağ************************/
  //Если входящие данные' I ' автомобиль идет вперед вправо(по диагонали).
    else if (state == 'I') {
        analogWrite(motorA1, vSpeed); digitalWrite(motorA2, HIGH); 
        analogWrite(motorB1, 0);digitalWrite(motorB2, HIGH); 
    }
  /***********************Geri****************************/
  //Автомобиль возвращается, если входящие данные " B.
    else if (state == 'B') {
      analogWrite(motorA1, vSpeed);digitalWrite(motorA2,LOW);
      analogWrite(motorB1, vSpeed);digitalWrite(motorB2,LOW);
    }
  /**********************Geri Sol************************/
  //Если данные из ' H ' автомобиль возвращается влево(по диагонали) 
    else if (state == 'H') {
      analogWrite(motorA1, vSpeed);digitalWrite(motorA2, LOW); 
        analogWrite(motorB1,0);digitalWrite(motorB2, LOW); 
    }
  /**********************Geri Sağ************************/
  //Если входящие данные 'J' автомобиль возвращается вправо(по диагонали)
    else if (state == 'J') {
      analogWrite(motorA1,0);digitalWrite(motorA2, LOW); 
        analogWrite(motorB1,vSpeed);digitalWrite(motorB2, LOW); 
    }
  /***************************Sol*****************************/
  //Если входящие данные 'L' автомобиль идет влево.
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);digitalWrite(motorA2, LOW); 
        analogWrite(motorB1, vSpeed);digitalWrite(motorB2,HIGH); 
    }
  /***************************Sağ*****************************/
  //Если входящие данные 'R' автомобиль идет вправо
    else if (state == 'R') {
      analogWrite(motorA1, vSpeed);digitalWrite(motorA2, HIGH); 
        analogWrite(motorB1, vSpeed);digitalWrite(motorB2, LOW);     
    }
  
  /************************Stop*****************************/
  //Остановить автомобиль, если входящие данные' s.
    else if (state == 'S'){
        analogWrite(motorA1, 0);digitalWrite(motorA2,LOW); 
        analogWrite(motorB1, 0);digitalWrite(motorB2,LOW);
    }  
}
