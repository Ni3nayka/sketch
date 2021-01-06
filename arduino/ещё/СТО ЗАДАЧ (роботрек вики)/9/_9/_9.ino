void setup()
{
}

void loop()
{
  if (( ( distanceCM( IN1 ) ) > ( 20 ) ))
  {
    startMotor(1, 20);
    delay( 50 );
  }
  else
  {
    stopMotorHard(1);
    stopProgram();
  }
}


