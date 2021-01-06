void setup()
{
  Serial.begin(9600);


}

void loop()
{
  if (irWhite(IN1, 500))
  {
    builtInRGB(WHITE);
  }
  else
  {
    builtInRGB(OFF);
  }
  Serial.println(analogRead(IN3));    
  delay(100);
}


