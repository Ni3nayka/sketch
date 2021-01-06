void setup()
{
  pinMode( OUT1 , OUTPUT );
}

void loop()
{
  if (cdsDark(IN1, 500))
  {
    led ( OUT1 , HIGH );
  }
  else
  {
    led ( OUT1 , LOW );
  }
}


