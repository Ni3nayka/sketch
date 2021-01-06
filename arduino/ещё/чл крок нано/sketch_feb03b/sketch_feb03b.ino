#define PWMA 9     //задаем значение
#define PWMB 10
#define AIN1 3
#define AIN2 2
#define BIN1 5
#define BIN2 6

 
void setup() {

 pinMode ( PWMA, OUTPUT);  
 pinMode ( PWMB, OUTPUT);
 pinMode ( AIN1, OUTPUT);
 pinMode ( AIN2, OUTPUT);
 pinMode ( BIN1, OUTPUT);
 pinMode ( BIN2, OUTPUT);

Serial.begin(9600);
}

void loop() {

 if ((analogRead(A4)) > 300)
  {
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 255);
  }
  else {
    while((analogRead(A4)) < 300){
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 210);

    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 100);
    }
}
     if ((analogRead(A5)) > 300)
  {
    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 255);
  }
  else {
    while((analogRead(A5)) < 300){
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 100);

    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 210);
    }
  }  
}
