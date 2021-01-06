int _ABVAR_1_t = 0 ;
int _ABVAR_2_a;
int _ABVAR_3_x = 0 ;

void setup()
{
  setupEnc(1, IN1, IN2);

  setEncToZero(1);
  _ABVAR_1_t = 60 ;

}

void loop()
{
  while ( irBlack(IN3, 400) )
  {
    startMotor(1, 20);
  }

  stopMotorHard(1);
  delay( 1000 );
  setEncToZero(1);
  for (_ABVAR_2_a=1; _ABVAR_2_a<= ( _ABVAR_1_t ); ++_ABVAR_2_a )
  {
    _ABVAR_3_x = ( getEncDegrees(1) / 6 ) ;
    do
    {
      startMotor(1, 30);
    }
    while(( ( ( getEncDegrees(1) / 6 ) ) < ( ( _ABVAR_3_x + 1 ) ) ));
    stopMotorHard(1);
    delay( 1000 );
  }
  stopProgram();
}


