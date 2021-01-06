void setup()
{
}

void loop()
{
  if (( ( distanceCM( IN1 ) ) > ( 20 ) ))
  {
    startMotor(1, 40);
    startMotor(2, 40);
    delay( 50 );
  }
  else
  {
    stopMotorHard(1);
    stopMotorHard(2);
    stopProgram();
  }
}


