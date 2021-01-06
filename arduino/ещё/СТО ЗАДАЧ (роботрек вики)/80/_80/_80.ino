int _ABVAR_1_Speed = 0 ;

void setup()
{
  IRRC_setup(IN1, 1);

}

void loop()
{
  if (RC(F1_KEY))
  {
    _ABVAR_1_Speed = 4 ;
  }
  if (RC(F2_KEY))
  {
    _ABVAR_1_Speed = 5 ;
  }
  if (RC(F3_KEY))
  {
    _ABVAR_1_Speed = 6 ;
  }
  if (RC(F4_KEY))
  {
    _ABVAR_1_Speed = 8 ;
  }
  if (RC(F5_KEY))
  {
    _ABVAR_1_Speed = 9 ;
  }
  if (RC(F6_KEY))
  {
    _ABVAR_1_Speed = 10 ;
  }
  if (RC(UP_KEY))
  {
    startMotor(1, ( _ABVAR_1_Speed * 10 ));
    startMotor(2, ( _ABVAR_1_Speed * 10 ));
  }
  else
  {
    if (RC(DOWN_KEY))
    {
      startMotor(1, ( _ABVAR_1_Speed * -10 ));
      startMotor(2, ( _ABVAR_1_Speed * -10 ));
    }
    else
    {
      if (RC(LEFT_KEY))
      {
        startMotor(1, ( _ABVAR_1_Speed * -10 ));
        startMotor(2, ( _ABVAR_1_Speed * 10 ));
      }
      else
      {
        if (RC(RIGHT_KEY))
        {
          startMotor(1, ( _ABVAR_1_Speed * 10 ));
          startMotor(2, ( _ABVAR_1_Speed * -10 ));
        }
        else
        {
          stopMotor(1);
          stopMotor(2);
        }
      }
    }
  }
}


