void setup()
{
  pinMode( OUT1 , OUTPUT);
}

void loop()
{
  ledPWM(OUT1 , cdsAnalog(IN1));
}


