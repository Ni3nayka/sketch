unsigned long int t = 0;

void setup() {
  Serial.begin(9600);
  t = millis();
}

void loop() {
  //Serial.println(digitalRead(3)); delay(1000);
  if (Serial.available() > 0) {
   char F = Serial.read();
   Serial.println(F);
   t = millis();
  }  
  if (millis()-t>=10000) {
    Serial.println(millis());
    t = millis();
  }
}
