void setup()
{
}

void loop()
{
  while ((analogRead(IN2)) < 160)
  {
    startMotor(1, 50);
    startMotor(2, 50);
  }

  stopMotor(1);
  stopMotor(2);
  //stopProgram();
}


