#ifndef TrackingCamSPI_h
#define TrackingCamSPI_h

#include "Arduino.h"

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

class TrackingCamSPI
{
  uint32_t nss_digital_pin;
  uint32_t speed;
  uint8_t TrackingCam_ReadData(uint8_t addr, uint8_t len, uint8_t* resp);
public:
  void init(uint32_t nss_digital_pin, uint32_t speed);
  uint8_t readBlobs(uint8_t max_blob_n = 5);
  uint8_t readObjects(uint8_t max_obj_n = 5);
  TrackingCamBlobInfo_t blob[16];
  TrackingCamObjInfo_t obj[16];
};

#endif
