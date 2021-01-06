#include <Servo.h>

int _ABVAR_1_Color = 0 ;
Servo servo_port_OUT4;

void setup()
{
  setupColorSensor(OUT1, OUT3, OUT2, IN1);
  servo_port_OUT4.attach(OUT4, BIG_SERVO);

}

void loop()
{
  if (buttonRead(BTN_CENTER))
  {
    _ABVAR_1_Color = getColor() ;
    if (( ( _ABVAR_1_Color ) == ( RED ) ))
    {
      tone(OUT5, 1500);
    }
    if (( ( _ABVAR_1_Color ) == ( GREEN ) ))
    {
      startMotor(1, 80);
      startMotor(2, 80);
    }
    if (( ( _ABVAR_1_Color ) == ( WHITE ) ))
    {
      startMotor(1, 80);
      startMotor(2, 80);
    }
    if (( ( _ABVAR_1_Color ) == ( BLUE ) ))
    {
      servo_port_OUT4.write( 90 );
    }
    delay( 1000 );
  }
  noTone(OUT5);
  stopMotor(1);
  stopMotor(2);
  servo_port_OUT4.write( 0 );
}


