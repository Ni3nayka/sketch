void setup()
{
}

void loop()
{
  if (( ( micAnalog(IN1) ) > ( 50 ) ))
  {
    startMotor(1, 80);
    startMotor(2, 80);
    delay( 5000 );
    stopMotor(1);
    stopMotor(2);
    stopProgram();
  }
}


