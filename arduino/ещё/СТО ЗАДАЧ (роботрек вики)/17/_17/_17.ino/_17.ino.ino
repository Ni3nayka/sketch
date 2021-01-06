void setup()
{
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);


  setEncToZero(1);
  setEncToZero(2);
}

void loop()
{
  while ( ( ( distanceCM( IN5 ) ) > ( 20 ) ) )
  {
    startMotor(1, 60);
    startMotor(2, 60);
  }

  while ( ( ( ( getEncDegrees(1) ) > ( 0 ) ) && ( ( getEncDegrees(2) ) > ( 0 ) ) ) )
  {
    startMotor(1, -60);
    startMotor(2, -60);
  }

  stopMotor(1);
  stopMotor(2);
  stopProgram();
}


