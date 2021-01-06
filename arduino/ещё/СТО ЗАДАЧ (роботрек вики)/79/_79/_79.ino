void setup()
{
  IRRC_setup(IN1, 1);
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
  pinMode( OUT3 , OUTPUT );

}

void loop()
{
  if (RC(F1_KEY))
  {
    led ( OUT1 , HIGH );
  }
  if (RC(F2_KEY))
  {
    led ( OUT2 , HIGH );
  }
  if (RC(F3_KEY))
  {
    led ( OUT3 , HIGH );
  }
  if (RC(F4_KEY))
  {
    led ( OUT1 , LOW );
  }
  if (RC(F5_KEY))
  {
    led ( OUT2 , LOW );
  }
  if (RC(F6_KEY))
  {
    led ( OUT3 , LOW );
  }
}


