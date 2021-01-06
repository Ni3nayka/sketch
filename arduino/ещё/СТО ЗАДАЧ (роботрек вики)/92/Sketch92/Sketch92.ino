void setup()
{
  pinMode( IN1 , INPUT);
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
}

void loop()
{
  if (digitalRead(IN1))
  {
    led ( OUT1 , HIGH );
    led ( OUT2 , LOW );
  }
  else
  {
    led ( OUT1 , LOW );
    led ( OUT2 , HIGH );
  }
}


