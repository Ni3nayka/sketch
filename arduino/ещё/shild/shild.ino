/*#define AIN1 3
#define AIN2 2
#define PWMA 4
void setup() {
  // put your setup code here, to run once:
pinMode (PWMA, OUTPUT);
pinMode (AIN1, OUTPUT);
pinMode (AIN2, OUTPUT);
pinMode (13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (AIN1, HIGH);
digitalWrite (AIN2, LOW);
analogWrite (PWMA, 255);
digitalWrite (13, LOW);
delay (500);
digitalWrite (13, HIGH);
delay (500);
}*/
#define PWMA 4  // выходы arduino
#define AIN1 2
#define AIN2 3
#define STBY 5


int motorSpeed = 100; //  скорость мотора

void setup(){

    pinMode(PWMA, OUTPUT);  
    pinMode(AIN1, OUTPUT);  
    pinMode(AIN2, OUTPUT); 
    pinMode(STBY, OUTPUT);  
    digitalWrite(STBY, HIGH); 
    digitalWrite(PWMA, 255);
}

void loop()
{
     digitalWrite(AIN1, LOW);      // крутим моторы в одну сторону
     digitalWrite(AIN2, HIGH);     
     delay(1000);
     digitalWrite(AIN1, HIGH);      // крутим моторы в одну сторону
     digitalWrite(AIN2, HIGH);     
     delay(1000);
     digitalWrite(AIN1, HIGH);  
     digitalWrite(AIN2, LOW); 
     delay(1000);
     digitalWrite(AIN1, HIGH);      // крутим моторы в одну сторону
     digitalWrite(AIN2, HIGH);     
     delay(1000);
} 
