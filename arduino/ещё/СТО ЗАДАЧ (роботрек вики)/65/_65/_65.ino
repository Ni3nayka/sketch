#include <Display.h>

Display display(UART3);
int _ABVAR_1_i = 0 ;

void setup()
{

  _ABVAR_1_i = 0 ;

}

void loop()
{
  if (digitalRead(BTN_CENTER))
  {
    _ABVAR_1_i = ( _ABVAR_1_i + 1 ) ;
    display.clear();
    display.text(0, 0, 1, WHITE, "count");
    display.text(100, 0, 1, WHITE, _ABVAR_1_i);	
    while ( digitalRead(BTN_CENTER) )
    {
    }

  }
}


