void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("hello world!");
  Serial.println(analogRead(PA0));
  delay(1000);
}
