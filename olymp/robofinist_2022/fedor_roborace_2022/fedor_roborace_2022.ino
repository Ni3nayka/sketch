#include <Trackduino.h>
#define PIN_TRIG IN1
#define PIN_ECHO IN2

long int enc = 0;
bool LST,LST2,CST2,CST;

void setup() 
{ 
  Trackduino.setup();
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  // Trackduino.reverse_motor(1,false);  
  //Trackduino.motor(1,100);   
  //delay(5000);           
  //Trackduino.stop_motor(1);
  attachInterrupt(4, test_3, CHANGE);
  attachInterrupt(5, test_4, CHANGE);
  LST=digitalRead(18);
  LST2=digitalRead(19);
  CST = LST;
  CST2 = LST2;
}
void loop ()
{ 
  //Trackduino.motor(1,ULT*2);
  //tic();
  Serial.println(enc);
}
void test_3() 
{
  //Serial.println("3");
  //CST = LST;
  CST2 = (!LST2);
  qwerty();
}
void test_4() 
{
  CST = (!LST);
  qwerty();
}

void qwerty() {
  if (CST != LST && CST==1) {
    if(CST2 != CST) {
      enc--;
    }
    else {
      enc++;
    }
  }
  LST = CST;
  LST2 = CST2;
}

int ULT()
{
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  return pulseIn(PIN_ECHO, HIGH) / 59.2;
}

void tic()
{
  CST=digitalRead(18);
  CST2=digitalRead(19);
  if (CST != LST && CST == 1)
  {
    if(digitalRead(19) != CST)
    {
      enc--;
    }
    else
    {
      enc++;
    }
  }
  LST = CST;
  Serial.println(enc);
}
