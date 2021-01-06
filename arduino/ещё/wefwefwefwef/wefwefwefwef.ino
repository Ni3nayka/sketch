#define s2  A5
#define s3  A3
#define out A4

byte red = 0;  // освобождаем память для переменных
byte green = 0;
byte blue = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void COLOR() // процедура color
{
 delay (500);
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
 // назначаем номер цвету---------------------------
 if (blue < 8) {
    C = 1;
  }
  else {
    C = 2;
  } 
  delay (500);
}
