int _ABVAR_1_red = 0 ;
int _ABVAR_2_green = 0 ;
int _ABVAR_3_blue = 0 ;

void COLOR();

void setup()
{
  pinMode(OUT7, OUTPUT);     
  pinMode(OUT8, OUTPUT);     
  pinMode(IN8, INPUT);

  Serial.begin(115200);
  _ABVAR_1_red = 0 ;

  _ABVAR_2_green = 0 ;

  _ABVAR_3_blue = 0 ;


}

void loop()
{
  COLOR();
  Serial.print("red");
  Serial.print(_ABVAR_1_red);
  Serial.println();
  Serial.print("green");
  Serial.print(_ABVAR_2_green);
  Serial.println();
  Serial.print("blue");
  Serial.print(_ABVAR_3_blue);
  Serial.println();
  Serial.print("-----");
  Serial.println();
  delay( 100 );
}

void COLOR()
{
  digitalWrite(OUT7, LOW);     
  digitalWrite(OUT8, LOW);     
  _ABVAR_1_red = pulseIn(IN8, digitalRead(IN8) == HIGH ? LOW : HIGH);     
  digitalWrite(OUT8, HIGH);     
  _ABVAR_3_blue = pulseIn(IN8, digitalRead(IN8) == HIGH ? LOW : HIGH);     
  digitalWrite(OUT7, HIGH);     
  _ABVAR_2_green = pulseIn(IN8, digitalRead(IN8) == HIGH ? LOW : HIGH);
}


