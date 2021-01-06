#include <TroykaDHT.h>
DHT dht(A0, DHT11);
byte t = 0;        // темрература
byte t_1 = 0;      // влажность
#define vl 70
#define tm 25


void setup() {
  pinMode (10, OUTPUT );
  pinMode (11, OUTPUT );
  pinMode (12, OUTPUT );
  Serial.begin(9600);
  dht.begin();
}

void loop () {
  //Serial.println(analogRead(A0));   delay(100);
  temp_vlag ();
  if ( (t > tm ) || (t_1 > vl ) ) {
    digitalWrite ( 12, HIGH);
    if ( t > tm ) {
      digitalWrite ( 11, HIGH ); 
    }
    else { 
      digitalWrite ( 11, LOW ); 
    }
    if (t_1 > vl ) {
       digitalWrite ( 10, HIGH ); 
    }
    else {
      digitalWrite ( 10, LOW ); 
    }
  } 
  else {
    digitalWrite ( 12, LOW );
    digitalWrite ( 11, LOW ); 
    digitalWrite ( 10, LOW ); 
  }
  //delay (100);
}

void temp_vlag () {
  dht.read();
  t = dht.getTemperatureC();
  t_1 = dht.getHumidity();
  Serial.print("temp: ");
  Serial.print(t);
  Serial.print("   ");
  Serial.print("vlag: ");
  Serial.println(t_1);
}
