void setup()
{
  IRRC_setup(IN1, 1);

}

void loop()
{
  if (RC(F1_KEY))
  {
    tone(OUT1, 1000);
    delay( 200 );
  }
  else
  {
    if (RC(F2_KEY))
    {
      tone(OUT1, 2000);
      delay( 200 );
    }
    else
    {
      if (RC(F3_KEY))
      {
        tone(OUT1, 3000);
        delay( 200 );
      }
      else
      {
        if (RC(F4_KEY))
        {
          tone(OUT1, 4000);
          delay( 200 );
        }
        else
        {
          if (RC(F5_KEY))
          {
            tone(OUT1, 5000);
            delay( 200 );
          }
          else
          {
            if (RC(F6_KEY))
            {
              tone(OUT1, 6000);
              delay( 200 );
            }
            else
            {
              noTone(OUT1);
            }
          }
        }
      }
    }
  }
}


