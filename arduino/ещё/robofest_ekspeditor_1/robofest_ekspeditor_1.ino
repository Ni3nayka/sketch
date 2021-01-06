#define SP     11
#define DP     13
#define SL     10
#define DL     12

#include <Servo.h>
Servo ser;
int s = 130;

#define s2  5
#define s3  3
#define out 6

int red   = 0;
int green = 0;
int blue  = 0;
int c     = 0;
int trigPin = A0;
int echoPin = A3;
int ras = 0;
int duration = 0;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(DL, OUTPUT);
  pinMode(DP, OUTPUT);  
  pinMode(4, OUTPUT);
  ser.attach(2);
  ser.write(s);
  Serial.begin(115200);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  lcd.init(); 
  lcd.backlight();
    
  /*
  lcd.setCursor(0, 0);  
  lcd.print("Bakaj Egor");
  lcd.setCursor(0, 1);  
  lcd.print("Robofest 2019");
  zum();
  */
  //while ((digitalRead(2)) == 1) { delay(10); } zum(); delay(500);
}

  /*
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 100);
  */

  // lcd.setCursor(0, 1); 
  // lcd.print(millis()/1000); 
  
  // S.write(150);
  
  // 1 white
  // 2 black
  // 3 red
  // 4 green
  // 5 blue
  // 6 yellow
  
void loop() {
  //S.write(90);
  //color();
  //Serial.println(digitalRead(2));
  //rast();
  //Serial.println(ras);
  digitalWrite(DL, HIGH );
  analogWrite(SL, 100);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 100);
  //linia();
}

void dv() {
  rast();
  if (ras < 12) {  // есть предмет 
    predmet();
  }
  else {           // нет предмета (движение по линии)
    linia();
  }
}
/*
void v() {
  while (s <= 250) {
    S.write(s);
    delay(2);
    s++;
  }
}

void o() {
  while (s >= 130) {
    S.write(s);
    delay(2);
    s--;
  }
}
*/
void predmet() {
  
}

void linia() {
  ///*
  digitalWrite(DL, HIGH );
  analogWrite(SL, (100 + 0.13*(analogRead(A1) - analogRead(A2))));
  digitalWrite(DP, HIGH );
  analogWrite(SP, (100 - 0.13*(analogRead(A1) - analogRead(A2))));
  //*/
  /*
  if  (((analogRead(A1)) > 600) && ((analogRead(A2)) > 600)) {
    M1.run(FORWARD);
    M1.setSpeed(70);
    M2.run(FORWARD);
    M2.setSpeed(70);
  }
  if  (((analogRead(A1)) > 600) && ((analogRead(A2)) < 600)) {
    M1.run(FORWARD);
    M1.setSpeed(200);
    M2.run(BACKWARD);
    M2.setSpeed(255);
  }
  if  (((analogRead(A1)) < 600) && ((analogRead(A2)) > 600)) {
    M1.run(BACKWARD);
    M1.setSpeed(255);
    M2.run(FORWARD);
    M2.setSpeed(200);
  }
  */
}

void color() {
  c = 0;
  delay(500);
  while (c == 0) {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s3, HIGH);
    blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s2, HIGH);
    green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    color_2(); 
  }
}

void color_2() {
  // 1 white
  // 2 black
  // 3 red
  // 4 green
  // 5 blue
  // 6 yellow
  
  if ((red < 8) && (green < 8) && (blue < 8)) { c = 1; }
  if ((red > 30) && (green > 30) && (blue > 20)) { c = 2; }
  if (c == 0) {
    if ((red < green)  && (red < blue)        ) { c = 3; }
    if ((green < red)  && (green < (blue + 5))) { c = 4; }
    if ((blue < red)   && (blue < (green - 5))) { c = 5; }
    if ((blue > green) && (blue > red)        ) { c = 6; }
  }
  /*
  Serial.print("red: ");
  Serial.print(red);
  Serial.print("; green: ");
  Serial.print(green);
  Serial.print("; blue: ");
  Serial.print(blue);
  Serial.println(";");
  
  if (c == 1) { Serial.println("white"); }
  if (c == 2) { Serial.println("black"); }
  if (c == 3) { Serial.println("red"); }
  if (c == 4) { Serial.println("green"); }
  if (c == 5) { Serial.println("blue"); }
  if (c == 6) { Serial.println("yellow"); }
  if (c == 0) { Serial.println("not"); }

  Serial.println("---");
  delay(100);
  */
}

void rast(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  ras = duration / 58;
} 

void zum() {
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
  digitalWrite (4, HIGH);
  delay (100);
  digitalWrite (4, LOW);
  delay (100);
}
