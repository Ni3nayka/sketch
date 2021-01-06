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
  uint8_t n = trackingCam.readBlobs(5); // read data about first 5 blobs
  Serial.println(n); // print numbers of blobs
  if(n) // print information about first blob
  {
    Serial.print(trackingCam.blob[0].type, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].dummy, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].cx, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].cy, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].area, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].left, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].right, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].top, DEC);
    Serial.print(" ");
    Serial.print(trackingCam.blob[0].bottom, DEC);
    Serial.println(" ");
  }

  // wait for the next frame
  while(millis() - previousMillis < 33) 
  {};
  previousMillis = millis();
}