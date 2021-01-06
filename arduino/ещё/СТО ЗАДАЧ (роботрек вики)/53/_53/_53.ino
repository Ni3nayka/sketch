#include <Display.h>
#include <accel_gyro.h>

Display display(UART3);

void setup()
{
  setupAccel();

}

void loop()
{
  display.clear();
  display.text(0, 0, 1, WHITE, "X =");
  display.text(100, 0, 1, WHITE, readAccelAngle('x',FILTERED));
  display.text(0, 20, 1, WHITE, "Y =");
  display.text(100, 20, 1, WHITE, readAccelAngle('y',FILTERED));
  display.text(0, 40, 1, WHITE, "Z =");
  display.text(100, 40, 1, WHITE, readAccelAngle('z',RAW_GYRO));	
  delay( 1000 );
}


