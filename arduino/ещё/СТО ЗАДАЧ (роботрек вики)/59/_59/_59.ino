#include <Display.h>

Display display(UART3);
double _ABVAR_1_D = 0.0 ;
double _ABVAR_2_R = 0.0 ;
double _ABVAR_3_L = 0.0 ;

void setup()
{
  setupEnc(1, IN1, IN2);
  setupEnc(2, IN3, IN4);



  setEncToZero(1);
  setEncToZero(2);
  _ABVAR_1_D = 4.5 ;

}

void loop()
{
  _ABVAR_2_R = ( getEncDegrees(1) / 360 ) ;
  _ABVAR_3_L = ( getEncDegrees(2) / 360 ) ;
  setEncToZero(1);
  setEncToZero(2);
  display.clear();
  display.text(0, 0, 1, WHITE, "Speed");
  display.text(100, 0, 1, WHITE, ( ( ( ( _ABVAR_2_R + _ABVAR_3_L ) / 2 ) * ( 3.1415927 * _ABVAR_1_D ) ) / 100 ));
  display.text(200, 0, 1, WHITE, "m/s");	
  delay( 1000 );
}


