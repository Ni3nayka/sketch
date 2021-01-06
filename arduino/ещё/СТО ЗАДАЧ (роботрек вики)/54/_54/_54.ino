#include <Display.h>

Display display(UART3);

void setup()
{

}

void loop()
{
  display.clear();
  display.text(0, 0, 1, WHITE, "Light sensor");
  display.text(150, 0, 1, WHITE, cdsAnalog(IN1));	
  delay( 1000 );
}


