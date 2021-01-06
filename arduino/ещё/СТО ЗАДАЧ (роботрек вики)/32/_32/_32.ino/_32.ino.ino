int _ABVAR_1_y = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_y = analogRead(IN1) ;
  startMotor(1, map ( _ABVAR_1_y , 0 , 1023 , 0 , 100 ) );
  startMotor(2, map ( _ABVAR_1_y , 0 , 1023 , 0 , 100 ) );
}


