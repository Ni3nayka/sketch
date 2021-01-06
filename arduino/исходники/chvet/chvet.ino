// назначаем имена для портов
#define s2  A5
#define s3  A3
#define out A4
// освобождаем память для переменных
byte red = 0;
byte green = 0;
byte blue = 0;

void setup() // процедура setup
{
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 Serial.begin(9600);
} 
 
void loop() // процедура loop
{ 
 color();
 // выводим значения цветов
 Serial.print(" RED :" + String(red));
 Serial.print(" GREEN : " + String(green));
 Serial.println(" BLUE : " + String(blue));
 delay(500);
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
