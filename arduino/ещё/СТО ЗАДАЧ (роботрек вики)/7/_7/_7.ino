void setup()
{
}

void loop()
{
  delay( 50 );
  if (( ( distanceCM( IN1 ) ) < ( 25 ) ))
  {
    tone(OUT1, 1000);
    delay( 1000 );
    noTone(OUT1);
    delay( 1000 );
  }
  else
  {
    noTone(OUT1);
  }
}


