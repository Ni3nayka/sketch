int _ABVAR_1_SoundLevel = 0 ;

void setup()
{
  pinMode( OUT1 , OUTPUT );
  pinMode( OUT2 , OUTPUT );
  pinMode( OUT3 , OUTPUT );
}

void loop()
{
  _ABVAR_1_SoundLevel = analogRead(IN1) ;
  if (( ( _ABVAR_1_SoundLevel ) < ( 20 ) ))
  {
    led ( OUT1 , HIGH );
    led ( OUT2 , LOW );
    led ( OUT3 , LOW );
  }
  else
  {
    if (( ( ( _ABVAR_1_SoundLevel ) > ( 20 ) ) && ( ( _ABVAR_1_SoundLevel ) < ( 50 ) ) ))
    {
      led ( OUT1 , LOW );
      led ( OUT2 , HIGH );
      led ( OUT3 , LOW );
    }
    else
    {
      led ( OUT1 , LOW );
      led ( OUT2 , LOW );
      led ( OUT3 , HIGH );
    }
  }
}


