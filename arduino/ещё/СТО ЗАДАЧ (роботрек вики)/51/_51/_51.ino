#include <Display.h>

Display display(UART3);

void setup()
{
  pinMode( IN1 , INPUT);

}

void loop()
{
  display.clear();
  display.text(0, 0, 1, WHITE, "Magnetic field sensor");
  display.text(260, 0, 1, WHITE, digitalRead(IN1));
  display.text(0, 20, 1, WHITE, "signal");
  display.text(80, 20, 1, WHITE, analogRead(IN1));	
  delay( 1000 );
}


