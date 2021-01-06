void setup()
{
  pinMode( IN1 , INPUT);
}

void loop()
{
  if (digitalRead(IN1))
  {
    tone(OUT1, 1000, 200);
    delay( 200 );
    tone(OUT1, 2000, 200);
    delay( 200 );
    tone(OUT1, 3000, 200);
    delay( 200 );
  }
  else
  {
    noTone(OUT1);
  }
}


