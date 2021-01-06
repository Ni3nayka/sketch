#define PWMA 12   
#define PWMB 7
#define AIN1 10
#define AIN2 11
#define BIN1 9
#define BIN2 8
#define STBY 6
#define K    5

void setup() {

 pinMode ( PWMA, OUTPUT);  
 pinMode ( PWMB, OUTPUT);
 pinMode ( AIN1, OUTPUT);
 pinMode ( AIN2, OUTPUT);
 pinMode ( BIN1, OUTPUT);
 pinMode ( BIN2, OUTPUT);
 pinMode ( STBY, OUTPUT);
 
 digitalWrite(STBY, HIGH); 

 Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A7));
  delay (100);

/*
 if ((analogRead(A3)) < 850)
  {
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 255);
  }
  else {
    while((analogRead(A3)) > 850){
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 210);

    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 100);
    }
}
     if ((analogRead(A4)) < 850)
  {
    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 255);
  }
  else {
    while((analogRead(A4)) > 850){
    digitalWrite (AIN1, 1);      
    digitalWrite (AIN2, 0);
    analogWrite (PWMA, 100);

    digitalWrite (BIN1, 0);      
    digitalWrite (BIN2, 1);
    analogWrite (PWMB, 210);
    }
  } */  
}
