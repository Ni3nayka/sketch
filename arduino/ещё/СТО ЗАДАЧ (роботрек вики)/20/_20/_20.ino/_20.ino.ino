void setup()
{
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
  led ( OUT1 , HIGH );

  led ( OUT2 , HIGH );

  delay( 2000 );

}

void loop()
{
  led ( OUT1 , LOW );
  led ( OUT2 , LOW );
  if (buttonRead(BTN_LEFT))
  {
    led ( OUT1 , HIGH );
    delay( 3000 );
    led ( OUT1 , LOW );
    delay( 2000 );
    led ( OUT1 , HIGH );
    led ( OUT2 , HIGH );
  }
  if (buttonRead(BTN_RIGHT))
  {
    led ( OUT2 , HIGH );
    delay( 3000 );
    led ( OUT2 , LOW );
    delay( 2000 );
    led ( OUT1 , HIGH );
    led ( OUT2 , HIGH );
  }
}


