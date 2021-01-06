void setup()
{
  Serial.begin(115200);
}

void loop()
{ 
  Serial.println (analogRead (IN2));
  /*if ((analogRead(IN2)) > 800) {
    Serial.println("WHITE");
  }
  if (((analogRead(IN2)) > 700) || ((analogRead(IN2)) < 800)) {
    Serial.println("RED");
  }
  if ((analogRead(IN2)) < 700) {
    Serial.println("NO");
  }*/
  delay (100);
} 


