int _ABVAR_1_Y = 0 ;
int _ABVAR_2_D = 0 ;
int _ABVAR_3_Y1 = 0 ;
int _ABVAR_4_D1 = 0 ;
int _ABVAR_5_FLAG1 = 0 ;
int _ABVAR_6_FLAG2 = 0 ;
extern int bluetooth_X, bluetooth_Y, bluetooth_Z, bluetooth_W, bluetooth_aX, bluetooth_aY,bluetooth_aZ;
extern bool bluetooth_F1, bluetooth_F2, bluetooth_F3, bluetooth_F4, bluetooth_F5, bluetooth_F6;
int _ABVAR_7_a;

#define Trig 6
#define Echo 7

void P();
void P1();
void P2();
void START();
void L();
void LI();

void setup()
{
  
pinMode(Trig, OUTPUT); //инициируем как выход 
pinMode(Echo, INPUT); //инициируем как вход 


  IRRC_setup(IN4, 7);
  BTinit();

  _ABVAR_1_Y = 0 ;

  _ABVAR_2_D = 0 ;

  _ABVAR_3_Y1 = 1 ;

  _ABVAR_4_D1 = 1 ;

  _ABVAR_5_FLAG1 = 0 ;

  _ABVAR_6_FLAG2 = 0 ;

}

unsigned int impulseTime=0; 
unsigned int distance_sm=0; 

void loop()
{
  if (RC(UP_KEY))
  {
    builtInRGB(RED);
    _ABVAR_1_Y = 2 ;
    delay( 300 );
  }
  if (RC(DOWN_KEY))
  {
    builtInRGB(RED);
    _ABVAR_1_Y = 1 ;
    delay( 300 );
  }
  if (RC(F1_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 1 ;
    delay( 300 );
  }
  if (RC(F2_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 2 ;
    delay( 300 );
  }
  if (RC(F3_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 3 ;
    delay( 300 );
  }
  if (RC(F4_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 4 ;
    delay( 300 );
  }
  if (RC(F5_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 5 ;
    delay( 300 );
  }
  if (RC(F6_KEY))
  {
    builtInRGB(RED);
    _ABVAR_2_D = 6 ;
    delay( 300 );
  }
  if (( RC(RIGHT_KEY) || RC(LEFT_KEY) ))
  {
    if (( ( ( ( _ABVAR_1_Y ) == ( 0 ) ) || ( ( _ABVAR_2_D ) == ( 0 ) ) ) || ( ( ( _ABVAR_4_D1 ) == ( _ABVAR_2_D ) ) && ( ( _ABVAR_3_Y1 ) == ( _ABVAR_1_Y ) ) ) ))
    {
      builtInRGB(WHITE);
      delay( 2000 );
    }
    else
    {
      builtInRGB(GREEN);
      delay( 500 );
      builtInRGB(OFF);
      delay( 500 );
      builtInRGB(GREEN);
      delay( 500 );
      START();
      delayMicroseconds( 1000 );
    }
  }
  builtInRGB(OFF);
  if (bluetooth_F4)
  {
    if (( ( bluetooth_aY ) > ( 0 ) ))
    {
      startMotor(1, ( bluetooth_aY + bluetooth_aX ));
      startMotor(2, ( bluetooth_aY + ( bluetooth_aX * -1 ) ));
    }
    else
    {
      startMotor(1, ( bluetooth_aY + ( bluetooth_aX * -1 ) ));
      startMotor(2, ( bluetooth_aY + bluetooth_aX ));
    }
    builtInRGB(BLUE);
  }
  else
  {
    if (bluetooth_F6)
    {
      startMotor(1, ( bluetooth_Y * 0.8 ));
      startMotor(2, ( bluetooth_W * 0.8 ));
      builtInRGB(BLUE);
    }
  }
  if (( bluetooth_F1 || ( bluetooth_F2 || bluetooth_F3 ) ))
  {
    stopMotor(1);
    stopMotor(2);
    builtInRGB(BLUE);
  }
}

void P2()
{
  if (( ( _ABVAR_1_Y ) == ( 1 ) ))
  {
    if (( ( _ABVAR_4_D1 ) > ( _ABVAR_2_D ) ))
    {
      L();
    }
    else
    {
      P();
    }
  }
  else
  {
    if (( ( _ABVAR_4_D1 ) > ( _ABVAR_2_D ) ))
    {
      P();
    }
    else
    {
      L();
    }
  }
}

void P()
{
  while ( irBlack(IN2, 700) )
  {
    startMotor(1, 50);
    startMotor(2, -50);
  }

  delayMicroseconds( 1000 );
  while ( irWhite(IN2, 700) )
  {
    startMotor(1, 50);
    startMotor(2, -50);
  }

  delayMicroseconds( 1000 );
  while ( irBlack(IN2, 700) )
  {
    startMotor(1, 50);
    startMotor(2, -50);
  }

  delayMicroseconds( 1000 );
}

void START()
{
  LI();
  delayMicroseconds( 1000 );
  if (( ( _ABVAR_4_D1 ) == ( _ABVAR_2_D ) ))
  {
  }
  else
  {
    delayMicroseconds( 1000 );
    startMotor(1, 50);
    startMotor(2, 50);
    delay( 500 );
    P1();
    delayMicroseconds( 1000 );
    if (( ( _ABVAR_2_D ) < ( _ABVAR_4_D1 ) ))
    {
      _ABVAR_6_FLAG2 = ( _ABVAR_4_D1 - _ABVAR_2_D ) ;
    }
    else
    {
      _ABVAR_6_FLAG2 = ( _ABVAR_2_D - _ABVAR_4_D1 ) ;
    }
    delayMicroseconds( 1000 );
    for (_ABVAR_7_a=1; _ABVAR_7_a<= ( _ABVAR_6_FLAG2 ); ++_ABVAR_7_a )
    {
      LI();
      startMotor(1, 50);
      startMotor(2, 50);
      delay( 500 );
    }
    delayMicroseconds( 1000 );
    P2();
    delayMicroseconds( 1000 );
  }
  delay( 1 );
  while ( irBlack(IN3, 700) )
  {
    LI();
  }

  delayMicroseconds( 1000 );
  P1();
  delay( 1 );
  stopMotor(1);
  stopMotor(2);
  _ABVAR_3_Y1 = _ABVAR_1_Y ;
  _ABVAR_4_D1 = _ABVAR_2_D ;
  delayMicroseconds( 1000 );
  _ABVAR_1_Y = 0 ;
  _ABVAR_2_D = 0 ;
}

void L()
{
  while ( irBlack(IN1, 700) )
  {
    startMotor(1, -50);
    startMotor(2, 50);
  }

  delayMicroseconds( 1000 );
  while ( irWhite(IN1, 700) )
  {
    startMotor(1, -50);
    startMotor(2, 50);
  }

  delayMicroseconds( 1000 );
  while ( irBlack(IN1, 700) )
  {
    startMotor(1, -50);
    startMotor(2, 50);
  }

  delayMicroseconds( 1000 );
}

void LI()
{
  while ( ( ( 0 ) == ( _ABVAR_5_FLAG1 ) ) )
  {
    digitalWrite(Trig, HIGH); 
    delayMicroseconds(10); // равный 10 микросекундам 
    digitalWrite(Trig, LOW); // Отключаем 
    impulseTime=pulseIn(Echo, HIGH); // Замеряем длину импульса 
    distance_sm=impulseTime/58; // Пересчитываем в сантиметры 

    if (irWhite(IN3, 700))
    {
      _ABVAR_5_FLAG1 = 1 ;
    }
    if (( irWhite(IN1, 700) && irWhite(IN2, 700) ))
    {
      delay( 10 );
      startMotor(1, 50);
      startMotor(2, 50);
    }
    if (( irWhite(IN1, 700) && irBlack(IN2, 700) ))
    {
      delay( 10 );
      startMotor(1, 50);
      startMotor(2, -25);
    }
    if (( irBlack(IN1, 700) && irWhite(IN2, 700) ))
    {
      startMotor(1, -25);
      startMotor(2, 50);
    }
    if (( irBlack(IN1, 700) && irBlack(IN2, 700) ))
    {
      _ABVAR_5_FLAG1 = 1 ;
    }
    if (distance_sm<80) //--------------------------------------------------------------------------------------------------------------------
    {
      stopMotor (1);
      stopMotor (2);
      delay (3000);
    }
  }

  delayMicroseconds( 1000 );
  _ABVAR_5_FLAG1 = 0 ;
  startMotor(1, 50);
  startMotor(2, 50);
  delayMicroseconds( 1000 );
}

void P1()
{
  if (( ( _ABVAR_3_Y1 ) == ( 1 ) ))
  {
    if (( ( _ABVAR_4_D1 ) > ( _ABVAR_2_D ) ))
    {
      L();
    }
    else
    {
      P();
    }
  }
  else
  {
    if (( ( _ABVAR_4_D1 ) > ( _ABVAR_2_D ) ))
    {
      P();
    }
    else
    {
      L();
    }
  }
}


