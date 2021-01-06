int sensorPin = A0;   
int sensorValue = 0; 

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() 
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(200);
  if(sensorValue < 600) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
}
