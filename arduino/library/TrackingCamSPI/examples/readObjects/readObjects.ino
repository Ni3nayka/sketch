#include "TrackingCamSPI.h"

TrackingCamSPI trackingCam;
unsigned long previousMillis = 0; // stores last time cam was updated

void setup() {
/* TrackingCamSPI::init(uint32_t nss_digital_pin, uint32_t speed);
 * nss_digital_pin - arduino digital pin to select cam
 * speed - 1000000 max, cam enables auto detection of master clock 
 */
  trackingCam.init(24, 1000000);
  Serial.begin(115200);
  delay(5000);
}

void loop() {
  uint8_t n = trackingCam.readObjects(5); // read data about 5 first objects
  Serial.println("All objects"); // print information about all objects
  Serial.println(n); // print numbers of objects
  for(int i = 0; i < n; i++)
  {
    Serial.print(trackingCam.obj[i].type, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.obj[i].cx, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.obj[i].cy, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.obj[i].angle, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.obj[i].obj_size, DEC);
    Serial.println("");
  }    
    
  // wait for the next frame
  while(millis() - previousMillis < 33) 
  {};
  previousMillis = millis();
}