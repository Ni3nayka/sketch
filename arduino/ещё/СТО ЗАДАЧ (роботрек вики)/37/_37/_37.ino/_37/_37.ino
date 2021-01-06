#include <Servo.h>

int _ABVAR_1_Color = 0 ;
Servo servo_port_OUT4;

void setup()
{
  setupColorSensor(OUT1, OUT3, OUT2, IN1);
  servo_port_OUT4.attach(OUT4);

}

void loop()
{
  if (buttonRead(BTN_CENTER))
  {
    _ABVAR_1_Color = getColor() ;
    if (( ( _ABVAR_1_Color ) == ( RED ) ))
    {
      servo_port_OUT4.write( 20 );
    }
    if (( ( _ABVAR_1_Color ) == ( GREEN ) ))
    {
      servo_port_OUT4.write( 40 );
    }
    if (( ( _ABVAR_1_Color ) == ( WHITE ) ))
    {
      servo_port_OUT4.write( 60 );
    }
    if (( ( _ABVAR_1_Color ) == ( BLUE ) ))
    {
      servo_port_OUT4.write( 80 );
    }
    delay( 1000 );
  }
  servo_port_OUT4.write( 0 );
}



