#include <Display.h>

Display display(UART1);
int _ABVAR_1_L = 0 ;
int _ABVAR_2_R = 0 ;

void a();
void b();
void c();

void setup()
{
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);



  setEncToZero(1);
  setEncToZero(2);
}

void loop()
{
  _ABVAR_1_L = getEncDegrees(1) ;
  _ABVAR_2_R = getEncDegrees(2) ;
  display.clear();	
  a();
  b();
  c();
  delay( 1000 );
}

void c()
{
  if (( ( _ABVAR_1_L ) < ( _ABVAR_2_R ) ))
  {
    display.line(20, 120, 300, 120, WHITE);
    display.line(20, 120, 80, 180, WHITE);
    display.line(20, 120, 80, 60, WHITE);
  }
}

void b()
{
  if (( ( _ABVAR_1_L ) > ( _ABVAR_2_R ) ))
  {
    display.line(20, 120, 300, 120, WHITE);
    display.line(240, 60, 300, 120, WHITE);
    display.line(240, 180, 300, 120, WHITE);
  }
}

void a()
{
  if (( ( _ABVAR_1_L ) == ( _ABVAR_2_R ) ))
  {
    display.line(160, 20, 160, 220, WHITE);
    display.line(160, 20, 100, 80, WHITE);
    display.line(160, 20, 220, 80, WHITE);
  }
}


