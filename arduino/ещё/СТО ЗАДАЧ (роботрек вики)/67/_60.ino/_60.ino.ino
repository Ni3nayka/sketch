#include <Display.h>

Display display(UART3);
int _ABVAR_1_i = 0 ;

void setup()
{

}

void loop()
{
  if (irBlack(IN1, 700))
  {
    ++_ABVAR_1_i ;
    display.clear();
    display.text(0, 0, 1, WHITE, "count");
    display.text(100, 0, 1, WHITE, _ABVAR_1_i);	
    while ( irBlack(IN1, 700) )
    {
    }

  }
}


