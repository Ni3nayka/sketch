#define SP     11
#define DP     13
#define SL     10
#define DL     12

void setup() 
{
//  int i = 0;
} 
 
void loop() { 
/*
digitalWrite(DL, HIGH );
analogWrite(SL, 255);
digitalWrite(DP, HIGH );
analogWrite(SP, 255);
*/
while ((analogRead (A0)) > 700) {
  //--------------------------------------------------------------------------
while (((analogRead(A1)) > 10) && ((analogRead(A1)) > 10)) {
  digitalWrite(DL, LOW );
  analogWrite(SL, 255);
  digitalWrite(DP, HIGH );
  analogWrite(SP, 255);
}
if (((analogRead(A1)) < 10) && ((analogRead(A1)) > 10)) {
digitalWrite(DL, HIGH );
analogWrite(SL, 50);
digitalWrite(DP, HIGH );
analogWrite(SP, 255);
}
if (((analogRead(A1)) < 10) && ((analogRead(A1)) < 10)) {
digitalWrite(DL, HIGH );
analogWrite(SL, 255);
digitalWrite(DP, HIGH );
analogWrite(SP, 255);
}
if (((analogRead(A1)) > 10) && ((analogRead(A1)) < 10)) {
digitalWrite(DL, HIGH );
analogWrite(SL, 255);
digitalWrite(DP, HIGH );
analogWrite(SP, 50);
}
//-----------------------------------------------------------------------------
}

digitalWrite(DL, LOW );
analogWrite(SL, 180);
digitalWrite(DP, LOW );
analogWrite(SP, 180);
//i = 0;
delay (1000);

}
