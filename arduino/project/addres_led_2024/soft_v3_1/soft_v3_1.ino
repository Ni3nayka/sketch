#define LED_PIN 8
#define LED_NUM 149
#define MAX 80
const int UPDATE_DT = 4000/MAX;

// Наташа Гергель

#include <FastLED.h>
CRGB leds[LED_NUM];

// LED GROUP START-FINISH
#define LG1_ST 0
#define LG1_START 6

void ledGroup(int start, int finish, int color, bool flag=1) {
  for (int i = start; i<finish; i++) leds[i].setRGB(color, color, color);
  if (flag) FastLED.show();
}

void led1(int color,bool flag=1) { ledGroup(0,6,color,flag); }
void led2(int color,bool flag=1) { ledGroup(30,37,color,flag); }
void led3(int color,bool flag=1) { ledGroup(85,90,color,flag); }
void ledLast(int color,bool flag=1) { ledGroup(36,37,color),flag; }

void ledZone1(int color,bool flag=1) { 
  ledGroup(111,119,color,flag); 
}
void ledZone2(int color,bool flag=1) { 
  ledGroup(10,11,color,0);
  ledGroup(13,15,color,0);
  ledGroup(45,46,color,0); 
  ledGroup(59,60,color,0); 
  ledGroup(93,94,color,flag); 
}
void ledZone3(int color,bool flag=1) { 
  ledGroup(119,123,color,0); 
  ledGroup(132,134,color,flag); 
}
void ledZone4(int color,bool flag=1) { 
  ledGroup(134,135,color,0); 
  ledGroup(140,141,color,0); 
  ledGroup(142,144,color,0); 
  ledGroup(146,149,color,flag); 
}

unsigned long int time = 0;
float timer() {
  return (millis()-time)/1000.0; // +105000
}

void play() {
  time = millis();
  // созвездия
  while (timer()<20);
  for (int i = 0; i<MAX; i++) {
    led1(i);
    delay(UPDATE_DT);
  }
  while (timer()<26);
  for (int i = 0; i<MAX; i++) {
    led2(i);
    delay(UPDATE_DT);
  }
  while (timer()<39);
  for (int i = 0; i<MAX; i++) {
    led3(i);
    delay(UPDATE_DT);
  }
  while (timer()<50);
  // led1(MAX);
  // led2(MAX);
  // led3(MAX);
  // зоны
  for (int i = 0; i<MAX; i++) {
    ledZone2(i);
    delay(UPDATE_DT);
  }
  while (timer()<59);
  for (int i = 0; i<MAX; i++) {
    ledZone3(i);
    delay(UPDATE_DT);
  }
  while (timer()<68);
  for (int i = 0; i<MAX; i++) {
    ledZone1(i);
    delay(UPDATE_DT);
  }
  while (timer()<75);
  for (int i = 0; i<MAX; i++) {
    ledZone4(i);
    delay(UPDATE_DT);
  }
  while (timer()<105);//*/
  for (int i = MAX; i>=0; i--){
    led1(i,0);
    led2(i,0);
    led3(i,0);
    ledZone1(i,0);
    ledZone2(i,0);
    ledZone3(i,0);
    ledZone4(i);
    delay(UPDATE_DT/2);
  }
  // мерцание
  for (int j=0; j<40;j++) { 
    int dt = UPDATE_DT/2;
    for (int i = 0; i<MAX; i++) {
      led1(i,0);
      led2(i,0);
      led3(i,0);
      ledZone1(i,0);
      ledZone2(i,0);
      ledZone3(i,0);
      ledZone4(i);
      delay(dt);
    }
    for (int i = MAX; i>=0; i--) {
      led1(i,0);
      led2(i,0);
      led3(i,0);
      ledZone1(i,0);
      ledZone2(i,0);
      ledZone3(i,0);
      ledZone4(i);
      delay(dt);
    }
    if (j==17) {
      while (timer()<194); 
    }
    // Serial.println(String(j) + " " + String(timer()));
  }
  while (timer()<319);
  for (int i = 0; i<MAX; i++) {
    led1(i,0);
    led2(i,0);
    led3(i,0);
    ledZone1(i,0);
    ledZone2(i,0);
    ledZone3(i,0);
    ledZone4(i);
    delay(UPDATE_DT/2);
  }
  while (timer()<376);
  // очень плавно гасим фон ////////////////////////////////////////////////////////////////////////////////////////
  // 4
  ledOff(134);
  ledOff(140);
  ledOff(142);
  ledOff(143);
  ledOff(146);
  ledOff(147);
  ledOff(148);
  // 3
  ledOff(119);
  ledOff(120);
  ledOff(121);
  ledOff(122);
  ledOff(132);
  ledOff(133);
  // 1
  ledOff(111);
  ledOff(112);
  ledOff(113);
  ledOff(114);
  ledOff(115);
  ledOff(116);
  ledOff(117);
  ledOff(118);
  // 2
  ledOff(10);
  ledOff(13);
  ledOff(14);
  ledOff(45);
  ledOff(59);
  ledOff(93);
  // ledOff();
  // выключение созвездий
  while (timer()<401); // 389
  for (int i = MAX; i>=0; i--){
    led3(i);
    delay(UPDATE_DT);
  }
  while (timer()<409); // 397
  for (int i = MAX; i>=0; i--){
    led1(i);
    delay(UPDATE_DT);
  }
  while (timer()<418); // 406 // 421 - off end /////////////////////////////////////////////////////////////////////////////
  for (int i = MAX; i>=0; i--){
    led2(i);
    delay(UPDATE_DT);
  }
  // конец плавных выключений //////////////////////////////////////////////////////////////////////////
  while (timer()<426);
  // включить последнюю звезду
  for (int i = 0; i<MAX; i++) {
    ledLast(i);
    delay(UPDATE_DT*1.5);
  }
  while (!digitalRead(2));
  delay(500);//*/
  // end
  FastLED.clear();
  FastLED.show();
}

void ledOff(int n) {
  for (int i = MAX; i>=0; i--) {
    leds[n].setRGB(i, i, i);
    FastLED.show();
    delay(6);
  }
}

bool readButton() {
  for (int i = 0; i<7; i++) {
    if (digitalRead(2)) return 0;
    delay(10);
  }
  return 1;
}

void setup() {
  // Serial.begin(9600);
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_NUM);
  pinMode(2,INPUT_PULLUP);
  // pinMode(7,INPUT_PULLUP);
  // hello world
  FastLED.setBrightness(MAX);
  FastLED.showColor(CRGB::White);
  delay(200);
  FastLED.showColor(CRGB::Red);
  delay(200);
  FastLED.showColor(CRGB::Green);
  delay(200);
  FastLED.showColor(CRGB::Blue);
  delay(200);
  FastLED.clear();
  FastLED.show();
  // debug
  // play();
}

void loop() {
  // if (readButton()) play();
  if (readButton()) {
    // Serial.println("!");
    play();
    delay(30000);
  }
}

