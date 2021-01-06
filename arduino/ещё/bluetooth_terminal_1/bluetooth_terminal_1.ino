int val;
int val1;
int LED = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}
void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    //val1 = Serial.read();
    if (val == '1') 
    {
      digitalWrite(LED, HIGH);
    }
    if ( val == '0')
    {
      digitalWrite(LED, LOW);
    }
    if (val == '2') 
    {
      Serial.println("win!");
    }
  }
}
