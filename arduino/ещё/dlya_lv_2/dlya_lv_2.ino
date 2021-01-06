#include <TroykaDHT.h>
DHT dht(A1, DHT11);

void setup() {
  //while (!Serial) ;
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  dht.read();
  t = dht.getTemperatureC();
}
