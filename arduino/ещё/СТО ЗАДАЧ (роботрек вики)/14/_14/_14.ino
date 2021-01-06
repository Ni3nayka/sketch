int _ABVAR_1_y = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_y = ( cdsAnalog(IN1) / 10 ) ;
  startMotor(1, _ABVAR_1_y);
  startMotor(2, _ABVAR_1_y);
}


