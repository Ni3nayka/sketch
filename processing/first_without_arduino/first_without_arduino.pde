// https://cxem.net/arduino/arduino198.php
// https://processing.org/reference/keyPressed_.html

//Создаем переменную для размера шрифта
int fontSize = 36;

int value = 0;
 
void setup() {
  //Определяем размер окна
  size(480, 480);
  //fill(value);
  //rect(0, 0, 500, 500);
   
}
 
void draw() { 
 //Задаем цвет фона в кодировке rgb или html, если не задать - будет черный
 background(#044f6f); 
  
 //Задаем цвет заполнения в кодировке rgb или html, если не задать - будт белый
 fill (#ffffff);
  
 //Создаем шрифт - его размер, стиль
 PFont myFont = createFont(PFont.list () [2], fontSize);
  
 //Задаем шрифт
 textFont(myFont);
  
 //Выводим показания датчиков на экран
  
 text(value, width / 2, height/ 2);
}

void keyPressed() {
  /*if (value == 0) {
    value = 255;
  } else {
    value = 0;
  }*/
  value++;
  print("!");
  text(value, width / 2, height/ 2);
}
