#include <Servo.h>

Servo servo_port_OUT1;

void setup()
{
  IRRC_setup(IN1, 1);
  servo_port_OUT1.attach(OUT1);

  servo_port_OUT1.write( 0 );

}

void loop()
{
  if (RC(F1_KEY))
  {
    servo_port_OUT1.write( 30 );
    delay( 200 );
  }
  if (RC(F2_KEY))
  {
    servo_port_OUT1.write( 60 );
    delay( 200 );
  }
  if (RC(F3_KEY))
  {
    servo_port_OUT1.write( 90 );
    delay( 200 );
  }
  if (RC(F4_KEY))
  {
    servo_port_OUT1.write( 120 );
    delay( 200 );
  }
  if (RC(F5_KEY))
  {
    servo_port_OUT1.write( 150 );
    delay( 200 );
  }
  if (RC(F6_KEY))
  {
    servo_port_OUT1.write( 180 );
    delay( 200 );
  }
}


