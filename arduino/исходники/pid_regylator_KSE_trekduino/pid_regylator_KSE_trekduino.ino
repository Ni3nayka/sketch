double _ABVAR_1_k = 0.0 ;
double _ABVAR_2_Kd = 0.0 ;
int _ABVAR_3_Speed = 0 ;
int _ABVAR_4_Speed_Nazad = 0 ;
double _ABVAR_5_IR1porog = 0.0 ;
double _ABVAR_6_IR2porog = 0.0 ;
double _ABVAR_7_E = 0.0 ;
double _ABVAR_8_Ect = 0.0 ;
double _ABVAR_9_Est = 0.0 ;

void vpered();

void setup()
{
  Serial.begin(115200);
  _ABVAR_1_k = 0.05 ;

  _ABVAR_2_Kd = 0.15 ;

  _ABVAR_3_Speed = 70 ;

  _ABVAR_4_Speed_Nazad = -20 ;

  _ABVAR_5_IR1porog = 565.0 ;

  _ABVAR_6_IR2porog = 565.0 ;

  _ABVAR_7_E = 0.0 ;

  _ABVAR_8_Ect = 0.0 ;

}

void loop()
{
  if (( irBlack(IN1, 700) && irBlack(IN2, 700) ))
  {
    vpered();
  }
  if (( irWhite(IN1, 700) && irBlack(IN2, 700) ))
  {
    vpered();
    if (( irWhite(IN1, 700) && irWhite(IN2, 700) ))
    {
      startMotor(1, _ABVAR_4_Speed_Nazad);
      startMotor(2, _ABVAR_3_Speed);
    }
  }
  if (( irBlack(IN1, 700) && irWhite(IN2, 700) ))
  {
    vpered();
    if (( irWhite(IN1, 700) && irWhite(IN2, 700) ))
    {
      startMotor(1, _ABVAR_3_Speed);
      startMotor(2, _ABVAR_4_Speed_Nazad);
    }
  }
}

void vpered()
{
  _ABVAR_7_E = ( ( irAnalog(IN1) - _ABVAR_5_IR1porog ) - ( irAnalog(IN2) - _ABVAR_6_IR2porog ) ) ;
  startMotor(1, ( _ABVAR_3_Speed - ( ( _ABVAR_1_k * _ABVAR_7_E ) + ( _ABVAR_2_Kd * ( _ABVAR_7_E - _ABVAR_9_Est ) ) ) ));
  startMotor(2, ( _ABVAR_3_Speed + ( ( _ABVAR_1_k * _ABVAR_7_E ) + ( _ABVAR_2_Kd * ( _ABVAR_7_E - _ABVAR_9_Est ) ) ) ));
  _ABVAR_9_Est = _ABVAR_7_E ;
  Serial.print("_________");
  Serial.print(irAnalog(IN1));
  Serial.print("_________");
  Serial.print(irAnalog(IN2));
  Serial.print("_________");
  Serial.print(( irAnalog(IN1) - _ABVAR_5_IR1porog ));
  Serial.print("_________");
  Serial.print(( irAnalog(IN2) - _ABVAR_5_IR1porog ));
  Serial.print("_________(");
  Serial.print(( _ABVAR_1_k * ( ( irAnalog(IN1) - _ABVAR_5_IR1porog ) - ( irAnalog(IN2) - _ABVAR_6_IR2porog ) ) ));
  Serial.print(")_________");
  Serial.print(( _ABVAR_3_Speed - ( _ABVAR_1_k * ( ( irAnalog(IN1) - _ABVAR_5_IR1porog ) - ( irAnalog(IN2) - _ABVAR_6_IR2porog ) ) ) ));
  Serial.print("_________");
  Serial.print(( _ABVAR_3_Speed + ( _ABVAR_1_k * ( ( irAnalog(IN1) - _ABVAR_5_IR1porog ) - ( irAnalog(IN2) - _ABVAR_6_IR2porog ) ) ) ));
  Serial.println();
}



