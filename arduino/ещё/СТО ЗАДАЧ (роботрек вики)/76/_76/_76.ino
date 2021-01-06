void setup()
{
  IRRC_setup(IN1, 1);

}

void loop()
{
  if (RC(UP_KEY))
  {
    startMotor(1, 80);
    startMotor(2, 80);
  }
  else
  {
    if (RC(DOWN_KEY))
    {
      startMotor(1, -80);
      startMotor(2, -80);
    }
    else
    {
      if (RC(LEFT_KEY))
      {
        startMotor(1, -80);
        startMotor(2, 80);
      }
      else
      {
        if (RC(RIGHT_KEY))
        {
          startMotor(1, 80);
          startMotor(2, -80);
        }
        else
        {
          stopMotor(1);
          stopMotor(2);
        }
      }
    }
  }
}


