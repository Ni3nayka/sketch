void setup()
{
  setupColorSensor(OUT1, OUT3, OUT2, IN1);

}

void loop()
{
  builtInRGB(getColor());
  delay( 1000 );
}


