// Motor shield использует четыре контакта 4, 5, 6, 7 для управления моторами 
// 4 и 7 — для направления, 5 и 6 — для скорости
#define SP      10 
#define DP      12
#define SL      11
#define DL      13
 
 
void setup() 
{
} 
 
void loop() 
{ 
if ((analogRead(A1)) > 700) {
  analogWrite(SP, 255);
  digitalWrite(DP, HIGH);
}
else {
  analogWrite(SP, 0);
  digitalWrite(DP, HIGH);
}
  
  //analogWrite(SP, 255);
  //digitalWrite(DP, HIGH);
  
}
