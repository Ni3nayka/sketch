double _ABVAR_1_L = 0.0 ;
double _ABVAR_2_R = 0.0 ;

void setup()
{
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);


  setEncToZero(1);
  setEncToZero(2);
  _ABVAR_1_L = -0.65 ;

  _ABVAR_2_R = 0.65 ;

}

void loop()
{
  startMotor(1, ( 80 * ( _ABVAR_1_L / abs( _ABVAR_1_L ) ) ));
  startMotor(2, ( 80 * ( _ABVAR_2_R / abs( _ABVAR_2_R ) ) ));
  while ( ( ( ( abs( _ABVAR_1_L ) ) > ( abs( ( getEncDegrees(1) / 360.0 ) ) ) ) || ( ( abs( _ABVAR_2_R ) ) > ( abs( ( getEncDegrees(2) / 360.0 ) ) ) ) ) )
  {
    if (( ( abs( _ABVAR_1_L ) ) <= ( abs( ( getEncDegrees(1) / 360.0 ) ) ) ))
    {
      stopMotorHard(1);
    }
    if (( ( abs( _ABVAR_2_R ) ) <= ( abs( ( getEncDegrees(2) / 360.0 ) ) ) ))
    {
      stopMotorHard(2);
    }
  }

  stopMotorHard(1);
  stopMotorHard(2);
  delay( 1000 );
  startMotor(1, 80);
  startMotor(2, 80);
  delay( 800 );
  setEncToZero(1);
  setEncToZero(2);
}


