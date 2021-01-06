
#include "Arduino.h"

#ifndef TrackingCamDxlUart_h 
#define TrackingCamDxlUart_h 

struct TrackingCamObjInfo_t
{
  uint8_t type;
  uint8_t dummy;
  uint16_t cx;
  uint16_t cy;
  uint16_t angle;
  uint32_t obj_size;
};

struct TrackingCamBlobInfo_t
{
  uint8_t type;
  uint8_t dummy;
  uint16_t cx;
  uint16_t cy;
  uint32_t area;
  uint16_t left;
  uint16_t right;
  uint16_t top;
  uint16_t bottom;
};

class TrackingCamDxlUart
{
public:
  void TrackingCamDxlUartInit(uint8_t CAM_ID, uint8_t Serial_port, uint32_t CAM_BaudRate, uint32_t PC_BaudRate, uint8_t TrackingCamTimeout);
  uint8_t TrackingCamDxl_ReadBlobs();
  uint8_t TrackingCamDxl_ReadObjects();
  TrackingCamBlobInfo_t blob[10];
  TrackingCamObjInfo_t obj[10];
};

#endif