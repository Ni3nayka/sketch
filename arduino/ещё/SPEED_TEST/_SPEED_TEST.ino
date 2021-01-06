void setup() {
  Serial.begin(9600);
  Serial.println("Speed test:");
  Serial.println("Characteristics in 1 second");
  long int i = 0;
  long int time = millis();
  while(time + 1000 > millis()) i++; 
  Serial.print("Counter:      ");
  Serial.println(i);
  i = 0;
  time = millis();
  while(time + 1000 > millis()) {
    digitalWrite(11, 1);
    i++;
  }
  Serial.print("digitalWrite: ");
  Serial.println(i);
  i = 0;
  time = millis();
  while(time + 1000 > millis()) {
    digitalRead(11);
    i++;
  }
  Serial.print("digitalRead:  ");
  Serial.println(i);
  i = 0;
  time = millis();
  while(time + 1000 > millis()) {
    analogWrite(A0, 1);
    i++;
  }
  Serial.print("analogWrite:  ");
  Serial.println(i);
  i = 0;
  time = millis();
  while(time + 1000 > millis()) {
    analogRead(A0);
    i++;
  }
  Serial.print("analogRead:   ");
  Serial.println(i);
  i = 0;
  time = millis();
}

void loop() {
  
}
