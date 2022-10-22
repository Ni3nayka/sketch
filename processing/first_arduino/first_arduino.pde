// https://cxem.net/arduino/arduino198.php


//Импортируем библиотеку для работы с Serial monitor
 
import processing.serial.*;
 
//Создаем объект класса Serial
 
Serial myPort; 
 
//Создаем переменные для полученных показаний
 
int reset, axisX, axisY;
 
//Создаем переменную для размера шрифта
 
int fontSize = 36;
 
void setup()
{
  //Определяем размер окна
   
  size(480, 480);
   
  //Выводим список COM портов и берем тот,
  //к которому подключен микроконтроллер
  //У Windows обычно 1 порт, а у MAC - 0
   
  println(Serial.list()) ;
  String portName = Serial.list()[1];
   
  //Открываем последовательный порт
   
  myPort = new Serial(this, portName, 9600);
   
  //Считываем приходящие данные, пока не дойдем до символа 
  //перевода строки
   
  myPort.bufferUntil('\n');
}
 //Этот метод вызывается тогда, когда в буффер пришло
 //значение перевода строки
 
void serialEvent(Serial myPort)
{
  //Считываем данные из буффера
   
  String inputString = myPort.readStringUntil('\n');
   
  //Отбрасываем ненужные символы(возврат каретки и перевод строки)
   
  inputString = trim(inputString);
   
  //Разделяем полученную строку по запятым и задаем переменным
  //нужные значения
   
  int axises[] = int(split(inputString, ','));
  if(axises.length == 3)
  {
    axisY = axises[0];
    axisX = axises[1];
    reset = axises[2];  
  }
}
 
//Этот метод рисует показания датчиков на экране
//В процессе дешифровки протокола участия не принимает
 
void draw()
{ 
 //Задаем цвет фона в кодировке rgb или html, если не задать - будет черный
  
 background(#044f6f); 
  
 //Задаем цвет заполнения в кодировке rgb или html, если не задать - будт белый
  
 fill (#ffffff);
  
 //Создаем шрифт - его размер, стиль
  
 PFont myFont = createFont(PFont.list () [2], fontSize);
  
 //Задаем шрифт
  
 textFont(myFont);
  
 //Выводим показания датчиков на экран
  
 text(axisY, width / 2, height/ 2);
 text(axisX, width / 2, height / 2 + 40);
 text(reset, width / 2, height / 2 - 40);
}
