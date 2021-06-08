

// C++ codebool Flag = 1;
bool Flag = 1;
unsigned long Time = 0;
unsigned long TimeS = 0;
unsigned long interval = 500;

#define pin_servo 9

int A = 544; // угол 0
int B = 1520; // угол 90
int C = 2400; // угол 180
void setup()
{
  pinMode(pin_servo, OUTPUT);
  Time = micros();
  Serial.begin(9600);
}
void Sm(int PIN, int U) //процедура работы Сервомоторов с двумя параметрами
{
  if (Flag == 1) {
    if (micros() - Time > U)
    {
      Time = micros();
      digitalWrite(PIN, 0);
      Flag = 0;
    }
  }
  if (Flag == 0) {
    if (micros() - Time > (20000 - U))
    {
      Time = micros();
      digitalWrite(PIN, 1);
      Flag = 1;
    }
  }
  //digitalWrite(PIN, !Flag);
  //Serial.println(Flag);
}

void loop()
{
  //Sm(pin_servo, C);
}
