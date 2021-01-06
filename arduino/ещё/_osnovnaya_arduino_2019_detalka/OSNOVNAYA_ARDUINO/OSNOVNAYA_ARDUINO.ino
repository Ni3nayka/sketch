// ЦВЕТ
#define s2  A5
#define s3  A3
#define out A4
byte red = 0;  // освобождаем память для переменных
byte green = 0;
byte blue = 0;
// МОТОРЫ
int E1 = 10;   // скорость вращения
int M1 = 12;   // направление вращения
int E2 =11;    // скорость вращения
int M2 = 13;   // направление вращения

void setup() // процедура setup
{
  Serial.begin(9600);
 //ЦВЕТ
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 //МОТОРЫ
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);
} 
 
/*void loop() // процедура loop
{ 
 color();
 // выводим значения цветов
 Serial.print(" RED :" + String(red));
 Serial.print(" GREEN : " + String(green));
 Serial.println(" BLUE : " + String(blue));
 delay(500);
}
*/

//датчик ИК:
//белый  >600 
//черный <600

// digitalWrite(M1,HIGH);
// digitalWrite(M2, HIGH);
// analogWrite(E1, 255);
// analogWrite(E2, 255);
//Serial.println(analogRead(A0));

void loop() {
  if ((analogRead(A1)) > 600) {
    digitalWrite(M1, HIGH);
    analogWrite(E1, 255);
  }
  else {
    digitalWrite(M1, HIGH);
    analogWrite(E1, 0);
  }
  if ((analogRead(A2)) > 600) {
    digitalWrite(M2, HIGH);
    analogWrite(E2, 255);
  }
  else {
    digitalWrite(M2, HIGH);
    analogWrite(E2, 0);
  }
}

void color() // процедура color
{
 // если 2 и 3 порты отключить, то получим значение красного цвета
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // если 3 порт включить, а 2 отключить, то получим синий цвет
 digitalWrite(s3, HIGH);
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

 // если 2 включить, а 3 отключить, то получим зеленый цвет
 digitalWrite(s2, HIGH);
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
}
