void setup()
{
  pinMode( IN1 , INPUT);
}

void loop()
{
  startMotor(1, 40);
  startMotor(2, 40);
  if (buttonRead(IN1))
  {
    stopMotor(1);
    stopMotor(2);
    stopProgram();
  }
}


