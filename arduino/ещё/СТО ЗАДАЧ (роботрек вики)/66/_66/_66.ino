#include <Servo.h>

int _ABVAR_1_i = 0 ;
int _ABVAR_2_x = 0 ;
int _ABVAR_3_y = 0 ;
Servo servo_port_OUT1;

void setup()
{
  servo_port_OUT1.attach(OUT1);
  Serial.begin(115200);
  _ABVAR_1_i = 0 ;

  _ABVAR_2_x = 0 ;

  _ABVAR_3_y = 0 ;

  tone(OUT2, 1500);

  servo_port_OUT1.write( 0 );

  delay( 1000 );

  noTone(OUT2);

}

void loop()
{
  if (digitalRead(BTN_UP))
  {
    _ABVAR_1_i = ( _ABVAR_1_i + 1 ) ;
    Serial.print("i =");
    Serial.print(_ABVAR_1_i);
    Serial.println();
    delay( 300 );
  }
  if (digitalRead(BTN_RIGHT))
  {
    _ABVAR_2_x = ( _ABVAR_2_x + 1 ) ;
    Serial.print("x =");
    Serial.print(_ABVAR_2_x);
    Serial.println();
    delay( 300 );
  }
  if (digitalRead(BTN_DOWN))
  {
    _ABVAR_3_y = ( _ABVAR_3_y + 1 ) ;
    Serial.print("y =");
    Serial.print(_ABVAR_3_y);
    Serial.println();
    delay( 300 );
  }
  if (digitalRead(BTN_CENTER))
  {
    if (( ( ( _ABVAR_1_i ) == ( 2 ) ) && ( ( ( _ABVAR_2_x ) == ( 3 ) ) && ( ( _ABVAR_3_y ) == ( 5 ) ) ) ))
    {
      tone(OUT2, 4500);
      delay( 1000 );
      noTone(OUT2);
      servo_port_OUT1.write( 90 );
      stopProgram();
    }
    else
    {
      _ABVAR_1_i = 0 ;
      _ABVAR_2_x = 0 ;
      _ABVAR_3_y = 0 ;
      tone(OUT2, 1500);
      servo_port_OUT1.write( 0 );
      delay( 1000 );
      noTone(OUT2);
    }
  }
}


