#include <Display.h>

Display display(UART1);

void setup()
{

}

void loop()
{
  display.clear();
  display.text(0, 0, 1, WHITE, "Proximity sensor");
  display.text(220, 0, 1, GREEN, distanceCM( IN1 ));	
  delay( 1000 );
}


