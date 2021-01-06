void setup()
{
  pinMode( IN1 , INPUT);
}

void loop()
{
  if (digitalRead(IN1))
  {
    tone(OUT1, 1000);
  }
}


