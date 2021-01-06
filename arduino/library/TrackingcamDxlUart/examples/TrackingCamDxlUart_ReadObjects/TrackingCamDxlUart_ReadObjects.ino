#include "TrackingCamDxlUart.h"

TrackingCamDxlUart trackingCam;

void setup() {
/*
 * TrackingCamDxlUartInit(CAM_ID, Serial_port, CAM_BaudRate, PC_BaudRate, TrackingCamTimeout);
 * CAM_ID - default 51
 * Serial_port:
 * Serial (Rx\Tx) - 0
 * Serial1 (Rx1\Tx1) - 1
 * Serial2 (Rx2\Tx2) - 2
 * Serial3 (Rx3\Tx3) - 3
 * CAM_BaudRate - default 115200
 * PC_BaudRate - default 115200
 * TrackingCamTimeout - in ms - default 30
 */
trackingCam.TrackingCamDxlUartInit(51, 1, 115200, 115200, 30);
}

void loop() {
  uint8_t n = 0;
//read data about objects
  n = trackingCam.TrackingCamDxl_ReadObjects();
//print numbers of objects
  Serial.println(n);
//print information about all objects
    Serial.println("\nAll objects:");
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
    
  delay(20);        // delay in between reads for stability
}



