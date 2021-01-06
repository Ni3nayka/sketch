#include <PinChangeInt.h>

#define D1 A3
#define D2 A1
#define D3 A0
#define D4 A2

unsigned int count_D1 = 0; 
unsigned int count_D2 = 0; 
unsigned int count_D3 = 0;
unsigned int count_D4 = 0;

void interruptFunction1() { count_D1++; }
void interruptFunction2() { count_D2++; }
void interruptFunction3() { count_D3++; }
void interruptFunction4() { count_D4++; }

void setup() {
  pinMode(D1, INPUT_PULLUP); 
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
  attachPinChangeInterrupt(D1, interruptFunction1, CHANGE);  // FALLING
  attachPinChangeInterrupt(D2, interruptFunction2, CHANGE); 
  attachPinChangeInterrupt(D3, interruptFunction3, CHANGE);
  attachPinChangeInterrupt(D4, interruptFunction4, CHANGE);
  Serial.begin(9600);
  Serial.println("---------------------------------------");
}

void loop() {
  delay(1000); 
  //Serial.print("Pin was interrupted: ");
  Serial.print(count_D1); 
  Serial.print(" ");
  Serial.print(count_D2); 
  Serial.print(" ");
  Serial.print(count_D3); 
  Serial.print(" ");
  Serial.print(count_D4);
  Serial.println();
}
