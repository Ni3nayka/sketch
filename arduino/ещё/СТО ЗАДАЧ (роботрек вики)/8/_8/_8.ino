void setup()
{
  pinMode( IN2 , INPUT);
}

void loop()
{
  delay( 50 );
  if (( ( distanceCM( IN1 ) ) < ( 25 ) ))
  {
    if (buttonRead(IN2))
    {
      noTone(OUT1);
      stopProgram();
    }
    else
    {
      tone(OUT1, 1000);
      delay( 1000 );
      noTone(OUT1);
      delay( 1000 );
    }
  }
  else
  {
    noTone(OUT1);
  }
}


