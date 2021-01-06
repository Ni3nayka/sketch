void setup()
{
}

void loop()
{
  if (( ( distanceCM( IN1 ) ) < ( 25.0 ) ))
  {
    startMotor(1, 40);
    startMotor(2, 40);
  }
  else
  {
    startMotor(1, -40);
    startMotor(2, 40);
  }
}


