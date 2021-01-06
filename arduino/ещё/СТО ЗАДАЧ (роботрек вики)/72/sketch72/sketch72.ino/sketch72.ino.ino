int _ABVAR_1_x = 0 ;
int _ABVAR_2_y = 0 ;

void setup()
{
}

void loop()
{
  _ABVAR_1_x = analogRead(IN1) ;
  _ABVAR_2_y = analogRead(IN2) ;
  if (( ( _ABVAR_1_x ) > ( 500 ) ))
  {
    startMotor(1, 40);
    stopMotor(2);
  }
  if (( ( _ABVAR_2_y ) > ( 500 ) ))
  {
    stopMotor(1);
    startMotor(2, 40);
  }
  if (( ( ( _ABVAR_1_x ) > ( 500 ) ) && ( ( _ABVAR_2_y ) > ( 500 ) ) ))
  {
    startMotor(1, 40);
    startMotor(2, 40);
  }
}


