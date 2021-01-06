void setup()
{
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
}

void loop()
{
  led ( OUT1 , HIGH );
  led ( OUT2 , LOW );
  delay( 1000 );
  led ( OUT1 , LOW );
  led ( OUT2 , HIGH );
  delay( 1000 );
}


