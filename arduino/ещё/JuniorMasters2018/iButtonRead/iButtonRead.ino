#include <OneWire.h> 
OneWire ds(17);
byte addr[8];

void setup() {
Serial.begin(9600);
}    

void loop() {
  if ( !ds.search(addr) ) { }
  else {
    for(int i=7; i>-1; i--){
      Serial.print(addr[i], HEX);
      Serial.print(" ");
    }                        
  Serial.println(); 
  ds.reset_search();
  }
}                  

