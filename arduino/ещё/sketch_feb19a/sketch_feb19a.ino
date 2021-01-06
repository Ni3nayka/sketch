void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  // Получаем команды на включение-выключение светодиода на 13 порту.
  String str = Serial.readString();
  // Если команда «HIGH» то включаем светодиод.
  if (str == "HIGH") digitalWrite(13, HIGH);
  // Если команда «LOW» то выключаем светодиод. 
  if (str == "LOW")  digitalWrite(13, LOW);
  // Спим 1 секунду.
 // delay(100);
}
