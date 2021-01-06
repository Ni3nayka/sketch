void setup()
{
}

void loop()
{
  tone(OUT1, analogRead(IN1));
  delay( 500 );
  noTone(OUT1);
}


