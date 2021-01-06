void setup()
{
}

void loop()
{
  startMotor(1, 100);
  startMotor(2, -100);
  if (shock(IN1))
  {
    startMotor(1, -100);
    startMotor(2, 100);
    delay( 2000 );
    startMotor(1, 100);
    startMotor(2, 100);
    delay( 2000 );
  }
}


