void setup()
{
}

void loop()
{
  if (( ( analogRead(IN1) ) > ( 500 ) ))
  {
    tone(OUT1, 440);
    startMotor(1, 100);
    delay( 1000 );
    stopMotor(1);
    stopProgram();
  }
}


