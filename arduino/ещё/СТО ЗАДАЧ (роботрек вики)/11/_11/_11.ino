void setup()
{
}

void loop()
{
  if (irBlack(IN1, 300))
  {
    startMotor(1, 40);
    startMotor(2, -40);
    delay( 2000 );
  }
  else
  {
    startMotor(1, 40);
    startMotor(2, 40);
  }
}


