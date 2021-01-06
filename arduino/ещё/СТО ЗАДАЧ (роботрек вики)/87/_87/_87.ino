void setup()
{
}

void loop()
{
  startMotor(1, 60);
  startMotor(2, 60);
  delay( 5000 );
  stopMotor(1);
  stopMotor(2);
  stopProgram();
}


