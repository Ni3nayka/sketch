int _ABVAR_1_x = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_x = cdsAnalog(IN1) ;
  if (( ( _ABVAR_1_x ) > ( 500 ) ))
  {
    tone(OUT1, 1500);
    delay( 1000 );
    noTone(OUT1);
    delay( 1000 );
  }
}


