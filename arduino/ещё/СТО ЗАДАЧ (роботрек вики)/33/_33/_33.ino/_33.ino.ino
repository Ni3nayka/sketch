int _ABVAR_1_SoundLevel = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_SoundLevel = micAnalog(IN1) ;
  if (( ( _ABVAR_1_SoundLevel ) > ( 500 ) ))
  {
    startMotor(1, 80);
    startMotor(2, 80);
    delay( 3000 );
  }
  else
  {
    startMotor(1, 80);
    startMotor(2, -80);
  }
}


