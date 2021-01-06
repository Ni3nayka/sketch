
//#include <iarduino_OLED.h>
#include <iarduino_OLED_txt.h>                
iarduino_OLED_txt myOLED(0x78);                        
extern uint8_t SmallFontRus[];      

#include <NewPing.h>
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Максимальное расстояние, которое мы контролируем (в сантиметрах). Максимальное расстояние подобных датчиков находится в диапазоне 400-500см.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Настройка пинов и максимального расстояния
int ras = 0;
int a = 0;
int b = 0;
int l = 0;
int k = 0;
int i = 0;
int l1 = 0;
int l2 = 0;
int l3 = 0;

void setup(){                                         
    myOLED.begin();                            
    myOLED.setFont(SmallFontRus);
    Serial.begin(115200);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    //pinMode(8, INPUT);
    nast_2();
    
}
// 0 нажата

void loop() {
  nast();
}

void nast_2() {
    myOLED.clrScr();
    myOLED.print( "нажмите на кнопку" , OLED_C, 3);
    myOLED.print( "чтобы настроить" , OLED_C, 4);
    myOLED.print( "растояние" , OLED_C, 5);
    myOLED.print( "до экрана" , OLED_C, 6);
    while ((analogRead(A0)) > 0) { delay(10); }
    while ((analogRead(A0)) == 0) { delay(10); }
    k = 1;
}

void nast() {
  if ((analogRead(A0)) < 2) {
    while ((analogRead(A0)) < 5) { delay(10); i++; }
    myOLED.clrScr();
    if (k == 1) {
      if (i < 100) { a = a + 10; }
      else { k++; }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      if (k == 1) { myOLED.print( "десятки", OLED_C, 2); } else { myOLED.print( "единицы", OLED_C, 2); }
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    if (k == 2) {
      if (i < 100) { a++; }
      else { k++; k++; myOLED.clrScr(); myOLED.print( "настройка", OLED_C, 1); myOLED.print( "завершена", OLED_C, 2);  myOLED.print( a, OLED_C, 3); }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      myOLED.print( "единицы", OLED_C, 2);
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    //if (k == 3) {myOLED.clrScr(); myOLED.print( "настройка", OLED_C, 1); myOLED.print( "завершена", OLED_C, 2);  myOLED.print( a, OLED_C, 3);
     // k++;
      //i = 0;  
    //}
    if (k == 4) {
      myOLED.clrScr();
      if (i < 100) { 
        rast();
        b = ras;
        l1 = a - b;
        myOLED.print( "ширина", OLED_C, 1);
        myOLED.print( "предмета (см):", OLED_C, 2);
        myOLED.print( l1, OLED_C, 3);
      }
      else { k++; a = 0; b = 0; }
      i = 0;
    }
    }
    }
    //-------------------------------------------------
    if (k == 5) {
      if (i < 100) { a = a + 10; }
      else { k++; }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      if (k == 5) { myOLED.print( "десятки", OLED_C, 2); } else { myOLED.print( "единицы", OLED_C, 2); }
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    if (k == 6) {
      if (i < 100) { a++; }
      else { k++; }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      myOLED.print( "единицы", OLED_C, 2);
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    if (k == 7) {myOLED.clrScr();
      myOLED.print( "настройка", OLED_C, 1);
      myOLED.print( "завершена", OLED_C, 2);
      myOLED.print( a, OLED_C, 3);
      k++;
      //i = 0;  
    }
    if (k == 8) {
      myOLED.clrScr();
      if (i < 100) { 
        rast();
        b = ras;
        l2 = a - b;
        myOLED.print( "ширина", OLED_C, 1);
        myOLED.print( "предмета (см):", OLED_C, 2);
        myOLED.print( l2, OLED_C, 3);
      }
      else { k++; a = 0; b = 0; }
      i = 0;
    }
    }
    }
    //-------------------------------------------------
    if (k == 9) {
      if (i < 100) { a = a + 10; }
      else { k++; }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      if (k == 9) { myOLED.print( "десятки", OLED_C, 2); } else { myOLED.print( "единицы", OLED_C, 2); }
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    if (k == 10) {
      if (i < 100) { a++; }
      else { k++; }
      myOLED.clrScr();
      myOLED.print( "настройки", OLED_C, 1);
      myOLED.print( "единицы", OLED_C, 2);
      myOLED.print( a, OLED_C, 3);
      i = 0;
    }
    else {
    if (k == 11) {myOLED.clrScr();
      myOLED.print( "настройка", OLED_C, 1);
      myOLED.print( "завершена", OLED_C, 2);
      myOLED.print( a, OLED_C, 3);
      k++;
      //i = 0;  
    }
    if (k == 12) {
      myOLED.clrScr();
      if (i < 100) { 
        rast();
        b = ras;
        l3 = a - b;
        myOLED.print( "ширина", OLED_C, 1);
        myOLED.print( "предмета (см):", OLED_C, 2);
        myOLED.print( l3, OLED_C, 3);
      }
      else { k++; a = 0; b = 0; }
      i = 0;
    }
    }
    }
    //-------------------------------------------------
    if (k == 13) {
      myOLED.clrScr();
      myOLED.print( "ширина предмета 1:", OLED_C, 0);
      myOLED.print( l1, OLED_C, 1);
      myOLED.print( "ширина предмета 2:", OLED_C, 2);
      myOLED.print( l2, OLED_C, 3);
      myOLED.print( "ширина предмета 3:", OLED_C, 4);
      myOLED.print( l3, OLED_C, 5);
    }
  }
  i = 0;
}

void test() {
  rast();
  myOLED.print( ras, OLED_C, 3);
  delay(1000);
  myOLED.clrScr();
}

void rast(){
  //delay(100);
  ras = sonar.ping() / US_ROUNDTRIP_CM;
  //Serial.println(ras);
}      

void led_prob() {
    myOLED.clrScr();  // Чистим экран.
    myOLED.print( "Большие буквы:"    ,      0, 0);    // Выводим текст начиная с 0 столбца 0 строки.
    myOLED.print( "ABCDEFGHIJKLM"     , OLED_C, 2);    // Выводим текст по центру 2 строки.
    myOLED.print( "NOPQRSTUVWXYZ"     , OLED_C, 3);    // Выводим текст по центру 3 строки.
    myOLED.print( "АБВГДЕЁЖЗИЙКЛМНОП" , OLED_C, 5);    // Выводим текст по центру 5 строки.
    myOLED.print( "РСТУФХЦЧШЩЪЫЬЭЮЯ"  , OLED_C, 6);    // Выводим текст по центру 6 строки.
    delay(3000);  
}
