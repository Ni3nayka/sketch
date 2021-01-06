import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

color off = color(4, 79, 111);
color on = color(84, 145, 158);

int[] values1 = { Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW };
 print.ln
 int[] values2 = { Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW };

void setup() {
  size(470, 200);
  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  
  for (int i = 0; i <= 13; i++)
    arduino.pinMode(i, Arduino.OUTPUT);
    
    for (int l = 0; l <= 13; l++)
    arduino.pinMode(l, Arduino.OUTPUT);
}

void draw() {
  background(off);
  stroke(on);
  
  for (int i = 0; i <= 4; i++) {
    if (values1[i] == Arduino.HIGH)
      fill(on);
    else
      fill(off);
      
    rect(420 - i * 30, 30, 20, 20);
  }
  
  for (int l = 0; l <= 4; l++) {
    if (values2[l] == Arduino.HIGH)
      fill(on);
    else
      fill(off);
      
    rect(420 - l * 30, 30, 20, 20);
  }
}

void mousePressed()
{
  int pin = (450 - mouseX) / 30;
  
  if (values1[pin] == Arduino.LOW) {
    arduino.digitalWrite(pin, Arduino.HIGH);
    values1[pin] = Arduino.HIGH;
  } else {
    arduino.digitalWrite(pin, Arduino.LOW);
    values1[pin] = Arduino.LOW;
  }
    
  if (values2[pin] == Arduino.LOW) {
    arduino.digitalWrite(pin, Arduino.HIGH);
    values2[pin] = Arduino.HIGH;
  } else {
    arduino.digitalWrite(pin, Arduino.LOW);
    values2[pin] = Arduino.LOW;
  }
}
