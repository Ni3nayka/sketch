#include <Servo.h>

Servo servo_port_OUT4;

void setup()
{
  setupColorSensor(OUT1, OUT3, OUT2, IN1);
  servo_port_OUT4.attach(OUT4, BIG_SERVO);

  servo_port_OUT4.write( 0 );

}

void loop()
{
  if (( ( getColor() ) == ( 2 ) ))
  {
    servo_port_OUT4.write( 100 );
    delay( 30000 );
  }
  else
  {
    servo_port_OUT4.write( 0 );
  }
}


