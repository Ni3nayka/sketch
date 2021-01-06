int _ABVAR_1_x = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_x = distanceCM( IN1 ) ;
  tone(OUT1, ( _ABVAR_1_x * 100 ));
  delay( 500 );
  noTone(OUT1);
}


