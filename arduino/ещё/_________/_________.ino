void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(IN1));
  delay(100);
}


