void setup()
{
  pinMode( IN1 , INPUT);
}

void loop()
{
  if (digitalRead(IN1))
  {
    startMotor(1, 80);
    startMotor(2, 80);
  }
  else
  {
    startMotor(1, 40);
    startMotor(2, 40);
  }
}


