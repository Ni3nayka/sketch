double _ABVAR_1_L = 0.0 ;
double _ABVAR_2_R = 0.0 ;

void setup()
{
  pinMode( IN5 , INPUT);
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);
  Serial.begin(115200);


  setEncToZero(1);
  setEncToZero(2);
}

void loop()
{
  if (buttonRead(IN5))
  {
    _ABVAR_1_L = ( getEncDegrees(1) / 360.0 ) ;
    _ABVAR_2_R = ( getEncDegrees(2) / 360.0 ) ;
    setEncToZero(1);
    setEncToZero(2);
    Serial.print("L");
    Serial.print(_ABVAR_1_L);
    Serial.println();
    Serial.print("R");
    Serial.print(_ABVAR_2_R);
    Serial.println();
    startMotor(1, ( 100 * ( _ABVAR_1_L / abs( _ABVAR_1_L ) ) ));
    startMotor(2, ( 100 * ( _ABVAR_2_R / abs( _ABVAR_2_R ) ) ));
    while ( ( ( ( abs( _ABVAR_1_L ) ) > ( abs( ( getEncDegrees(1) / 360.0 ) ) ) ) || ( ( abs( _ABVAR_2_R ) ) > ( abs( ( getEncDegrees(2) / 360.0 ) ) ) ) ) )
    {
      if (( ( abs( _ABVAR_1_L ) ) <= ( abs( ( getEncDegrees(1) / 360.0 ) ) ) ))
      {
        stopMotor(1);
      }
      if (( ( abs( _ABVAR_2_R ) ) <= ( abs( ( getEncDegrees(2) / 360.0 ) ) ) ))
      {
        stopMotor(2);
      }
    }

    stopMotor(1);
    stopMotor(2);
    stopProgram();
  }
}


