int _ABVAR_1_x = 0 ;

void setup()
{
  pinMode( IN2 , INPUT);
}

void loop()
{
  _ABVAR_1_x = distanceCM( IN1 ) ;
  if (buttonRead(IN2))
  {
    tone(OUT1, ( _ABVAR_1_x * 50 ));
  }
  else
  {
    tone(OUT1, ( _ABVAR_1_x * 100 ));
  }
  delay( 500 );
  noTone(OUT1);
}


