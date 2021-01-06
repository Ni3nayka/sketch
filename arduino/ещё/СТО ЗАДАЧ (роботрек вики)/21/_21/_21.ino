void setup()
{
  pinMode( IN6 , INPUT);
  pinMode( IN5 , INPUT);
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);


}

void loop()
{
  if (buttonRead(IN5))
  {
    startMotor(1, 80);
    while ( ( ( abs( getEncDegrees(1) ) ) < ( 360 ) ) )
    {
    }

    setEncToZero(1);
    stopMotor(1);
  }
  if (buttonRead(IN6))
  {
    startMotor(2, 80);
    while ( ( ( abs( getEncDegrees(2) ) ) < ( 360 ) ) )
    {
    }

    setEncToZero(2);
    stopMotor(2);
  }
}


