void setup()
{
}

void loop()
{
  if (irBlack(IN1, 300))
  {
    stopMotorHard(1);
    stopMotorHard(2);
    stopProgram();
  }
  else
  {
    startMotor(1, 40);
    startMotor(2, 40);
  }
}


