//------------------------------------ подключать считыватель + (МК) с пином 13 через резистор 4.7кОМ к нему же ( к пину дату считывателя)
/*Alex Kuznetsov
********http://youtube.com/a2kuz************
********http://vk.com/arduino_ekb*********** группа в ВК подробная схема подключения там.
*/
#include <OneWire.h>

#define TIME_PERIOD_BUZZER 100 //переодичность включения\выключения пищалки
#define TIME_PERIOD_DOOR 3000 // сколько будет открыта дверь
#define DOOR 13 // зададим пин для двери
#define BUZZER 12 // зададим пин для пиищалки
#define BUTTON 11// зададим пин для кнопки

unsigned long time_door = 0;
unsigned long time_buzzer = 0;

boolean flag_buzzer = 0;
boolean flag_door = 0;

byte key[8] = {0xAF, 0x85, 0xB1, 0xA, 0x0, 0x0, 0x28}; // ключ AF 85 B1 A 0 0 28
byte addr[8];
byte val = 0;

OneWire  ds(10);

void setup(void) {
  pinMode(DOOR, OUTPUT);
  digitalWrite(DOOR, HIGH);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
}
void loop(void) {
  if (ds.search(addr)) {
    for (byte i = 0; i < 8; i++) if (addr[i] == key[i]) val++;
    if (val == 8) {
      open_door();//вынесли этот фрагмент в отдельную функцию
    }
    ds.reset_search();
  }
  door(); //функция двери
  if  (flag_door == 1) //если дверь еще открыта значит будем пищать
  {
    buzzer(); // функция пищалки
  }
  else if (flag_door == 0) // иначе если дверь уже закрылась то:
  {
    digitalWrite(BUZZER, LOW); // выключаем пищалку и больше не пищим пока дверь не откроется
    flag_buzzer = 0; // запоминаем что пищалка выключена
  }
  /* милисекунды в ардуино обнуляются каждые 49 суток
    для того чтобы в случае если включенное состояние замка небыло еще 49 суток
    нужно обнулить и время отсчета, при этом пищать buzzer либо открыта дверь будет вдвое больше обычного что не кретично.*/
  if (millis() < time_door)
  {
    time_door = 0;
    time_buzzer = 0;
  }
  //тут запишем что если нажали на кнопку - выполним функцию открытия двери
  if (digitalRead(BUTTON) == 0) //если нажал на кнопку
  {
    open_door();//функция открытия двери
  }
}
void door()
{
  if  (millis() >= time_door + TIME_PERIOD_DOOR) //если прошло время которое задавали для двери
  {
    digitalWrite(DOOR, HIGH); //то закрываем ее
    flag_door = 0; // и запоминаем что она закрыта
  }
}
void buzzer()
{
  if  ((millis() >= time_buzzer + TIME_PERIOD_BUZZER) && (flag_buzzer == 1))//если прошло время которое задавали для пищалки и она включена
  {
    digitalWrite(BUZZER, LOW); //мы ее выключаем
    time_buzzer = millis(); //запоминаем время когда выключили
    flag_buzzer = 0; //запоминаем что она выключена
  }
  else if ((millis() >= time_buzzer + TIME_PERIOD_BUZZER) && (flag_buzzer == 0)) //если прошло время которое задавали для пищалки и она выключена
  {
    digitalWrite(BUZZER, HIGH); //то включаем ее
    time_buzzer = millis(); //запоминаем время выключение пищалки
    flag_buzzer = 1; // запоминаем что она выключина
  }
}
void open_door()//функция открытия двери
{
  time_buzzer = millis(); //зададим отсчет времени для пищалки
  time_door = millis(); //зададим отсчет времени для двери
  digitalWrite(BUZZER, HIGH);//включаем пищалку
  digitalWrite(DOOR, LOW);//открываем дверь
  flag_buzzer = 1;//устанавливаем флаг что пищалка включена
  flag_door = 1;//устанавливаем флаг что дверь открыта
}
