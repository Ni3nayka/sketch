void setup()
{
}

void loop()
{
  if (irWhite(IN1, 500))
  {
    stopMotor(1);
    startMotor(2, 40);
  }
  else
  {
    startMotor(1, 40);
    stopMotor(2);
  }
}


