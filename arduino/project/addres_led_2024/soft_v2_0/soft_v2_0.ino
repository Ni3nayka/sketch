#define LED_PIN 8
#define LED_NUM 149
#define UPDATE_DT 30

struct led_group {
  const int color[3];
  int brightness[3];
  bool mode;
  const int button_pin;
  const int quantity;
};

#define LED_GROUP_NUM 6
led_group led_data[LED_GROUP_NUM] = {
  //           {r,g,b},       {0,0,0}, 0, button_pin, quantity),
  (led_group){ {0,128,255}, {0,0,0}, 0, 2, 6}, // 1
  (led_group){ {255,255,255}, {0,0,0}, 0, 5, 24}, 
  (led_group){ {128,0,255}, {0,0,0}, 0, 3, 7}, // 2
  (led_group){ {255,255,255}, {0,0,0}, 0, 5, 49}, 
  (led_group){ {0,0,255}, {0,0,0}, 0, 4, 5}, // 3
  (led_group){ {255,255,255}, {0,0,0}, 0, 5, 59},
};

#include <FastLED.h>
CRGB leds[LED_NUM];

unsigned long int led_couner = 0;

void setup() {
  // Serial.begin(9600);
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_NUM);
  for (int i = 0; i<LED_GROUP_NUM; i++) {
    pinMode(led_data[i].button_pin,INPUT_PULLUP);
  }
  pinMode(6,INPUT_PULLUP);
  // pinMode(7,INPUT_PULLUP);
  // hello world
  FastLED.setBrightness(255);
  FastLED.showColor(CRGB::White);
  delay(200);
  FastLED.showColor(CRGB::Red);
  delay(200);
  FastLED.showColor(CRGB::Green);
  delay(200);
  FastLED.showColor(CRGB::Blue);
  delay(200);
  FastLED.clear();
}

void loop() {
  // read data
  // if (Serial.available()) {
  //   char f = Serial.read();
  //   int i = -1;
  //   if (f=='0') i = 0;
  //   if (f=='1') i = 1;
  //   if (f=='2') i = 2;
  //   // if (f=='3') i = 3;
  //   // if (f=='4') i = 4;
  //   // if (f=='5') i = 5;
  //   if (i>-1) led_data[i].mode = !led_data[i].mode;
  // }
  if (!digitalRead(7)) {
    // mega play
    
  }
  if (!digitalRead(6)) {
    // led_data[0].mode = 1
    if (led_couner==0) {
      for (int i = 0; i<LED_GROUP_NUM; i++) led_data[i].mode = 0;  
      led_data[0].mode = 1;
    }
    else if (led_couner==100) led_data[2].mode = 1;
    else if (led_couner==150) led_data[4].mode = 1;
    else if (led_couner==200) { 
      for (int i = 0; i<LED_GROUP_NUM; i++) led_data[i].mode = 1;  
    }
    led_couner++;
  }
  else {
    led_couner = 0;
    for (int i = 0; i<LED_GROUP_NUM; i++) {
      led_data[i].mode = !digitalRead(led_data[i].button_pin);
    }
  }
  // update
  for (int i = 0; i<LED_GROUP_NUM; i++) {
    for (int j = 0; j<3; j++) {
      led_data[i].brightness[j] += (int(led_data[i].mode)*2-1);  //*UPDATE_DBRIGHTNESS; #define UPDATE_DBRIGHTNESS 1
      led_data[i].brightness[j] = constrain(led_data[i].brightness[j],0,led_data[i].color[j]);
    }
  }
  int led_write = 0;
  for (int i = 0; i<LED_GROUP_NUM; i++) { // LED_NUM
    for (int j = 0; j<led_data[i].quantity; j++) {
      leds[led_write++].setRGB(led_data[i].brightness[0], led_data[i].brightness[1], led_data[i].brightness[2]);
    }
  }
  FastLED.show();
  // fps
  delay(UPDATE_DT);
}

