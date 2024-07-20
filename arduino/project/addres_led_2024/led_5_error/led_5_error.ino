#define LED_PIN 2     // пин

#define LED_DEFAULT_STAR 5
#define LED_GROUP_STAR 6

const int LED_NUM = LED_GROUP_STAR+LED_DEFAULT_STAR;    // количество светодиодов
int led_brightness[LED_GROUP_STAR+1][3] = {0};
bool led_mode[LED_GROUP_STAR+1] = {0};
const int led_color[LED_GROUP_STAR+1][3] = {
  // {20,20,20},
  // {20,20,20},
  // {20,20,20},
  // {20,20,20},
  // {20,20,20},
  // {20,20,20},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
};
#define UPDATE_DT 30
#define UPDATE_DBRIGHTNESS 1

#include <FastLED.h>
CRGB leds[LED_NUM];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(255);
}

void loop() {
  // read data
  if (Serial.available()) {
    char f = Serial.read();
    int i = -1;
    if (f=='0') i = 0;
    if (f=='1') i = 1;
    if (f=='2') i = 2;
    if (f=='3') i = 3;
    if (f=='4') i = 4;
    if (f=='5') i = 5;
    if (f=='6') i = 6;
    // if (f=='7') i = 7;
    // if (f=='8') i = 8;
    // if (f=='9') i = 9;
    // if (f=='10') i = 10;
    // if (f=='11') i = 11;
    if (i>-1) {
      led_mode[i] = !led_mode[i];
    }
  }
  // update
  for (int i = 0; i<LED_GROUP_STAR+1; i++) {
    for (int j = 0; j<3; j++) {
      led_brightness[i][j] += (int(led_mode[i])*2-1)*UPDATE_DBRIGHTNESS;
      led_brightness[i][j] = constrain(led_brightness[i][j],0,led_color[i][j]);
    }
    leds[i].setRGB(led_brightness[i][0], led_brightness[i][1], led_brightness[i][2]);
  }
  FastLED.show();
  // fps
  delay(UPDATE_DT);
  // debug
  // for (int i = 0; i<LED_GROUP_STAR+1; i++) {
  //   for (int j = 0; j<3; j++) {
  //     Serial.print(led_brightness[i][j]);
  //     Serial.print(" ");
  //   }
  //   Serial.print("     ");
  // }
  // Serial.println();
}


  // if (i>=LED_NUM) {
  //   i = 0;
  //   leds[LED_NUM-1] = 0x000000; 
  // }
  // else {
  //   leds[i] = 0x000000; 
  //   i++;
  // }
  // // hard += 50;
  // // if (hard>255) hard = HARD_MIN;
  // // leds[i].setRGB(hard, hard, hard);
  // if (i%2==0) leds[i] = 0xFFFFFF;
  // else leds[i] = 0x0F0F0F;
  // FastLED.show();
  // delay(500);

// FastLED.show() 
// FastLED.clear()
// FastLED.setBrightness(0-255)
// FastLED.showColor(CRGB цвет)
