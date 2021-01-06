int _ABVAR_1_SoundLevel = 0 ;

void setup()
{
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
  pinMode( OUT3 , OUTPUT );
}

void loop()
{
  _ABVAR_1_SoundLevel = micAnalog(IN1) ;
  if (( ( _ABVAR_1_SoundLevel ) > ( 250 ) ))
  {
    led ( OUT1 , HIGH );
    if (( ( _ABVAR_1_SoundLevel ) > ( 500 ) ))
    {
      led ( OUT2 , HIGH );
      if (( ( _ABVAR_1_SoundLevel ) > ( 750 ) ))
      {
        led ( OUT3 , HIGH );
      }
    }
  }
  else
  {
    led ( OUT1 , LOW );
    led ( OUT2 , LOW );
    led ( OUT3 , LOW );
  }
}


