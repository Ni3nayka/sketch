#include <TrackingCamSPI.h>
#include <SPI.h>

#define nTRACKINGCAM_SPI_DEBUG
#define TRACKINGCAM_SPI_DEBUG_BAUD 115200
#define CMD_READ 0x0f

void TrackingCamSPI::init(uint32_t nss_digital_pin, uint32_t speed)
{
  this->nss_digital_pin = nss_digital_pin;
  this->speed = speed;

  pinMode(nss_digital_pin, OUTPUT);
  digitalWrite(nss_digital_pin, HIGH);
  SPI.begin();
  delay(100);
#ifdef TrackingCamSPI_DEBUG
  Serial.begin(TRACKINGCAM_SPI_DEBUG_BAUD);  // start serial for output
#endif
}

uint8_t TrackingCamSPI::readBlobs(uint8_t max_blob_n)
{  
  uint8_t resp[255];
  uint8_t n = 0;
  uint8_t idx = 0;
  bool is_bulk_reading = false;
  uint8_t lines = max_blob_n > 10? 10: max_blob_n;
 
  if(lines == 0)
    lines = 1;
    
  if(is_bulk_reading)
  {
    if(TrackingCam_ReadData(16, (max_blob_n? lines * 16: 6), resp)) //Bulk reading
      return 0;
  }
 
  for(int i = 0; i < lines; i++)
  {
    if(!is_bulk_reading)
    {
      if(TrackingCam_ReadData(16 + i*16, (max_blob_n? 16: 6), resp)) //Line by line reading
        return n; 
		idx = 0;
    }
    
    blob[i].type = resp[idx++];
    if(blob[i].type == 0xFF)
      return n;
    else
      n++;
      
    blob[i].dummy = resp[idx++];
    blob[i].cx = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    blob[i].cy = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    if(max_blob_n == 0)
      break;
    blob[i].area = (uint32_t)((((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8))) * 4;
    idx += 2;
    blob[i].left = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    blob[i].right = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    blob[i].top = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    blob[i].bottom = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
  }
  return n;
}

uint8_t TrackingCamSPI::readObjects(uint8_t max_obj_n)
{
  uint8_t resp[255];
  uint8_t n = 0;
  uint8_t idx = 0;
  bool is_bulk_reading = false;
  uint8_t lines = max_obj_n > 10? 10: max_obj_n;
 
  if(lines == 0)
    lines = 1;
    
  if(is_bulk_reading)
  {
    if(TrackingCam_ReadData(16, (max_obj_n? lines * 10: 6), resp)) //Bulk reading
      return 0;
  }
 
  for(int i = 0; i < lines; i++)
  {
    if(!is_bulk_reading)
    {
      if(TrackingCam_ReadData(16 + i*10, (max_obj_n? 10: 6), resp)) //Line by line reading
        return n; 
      idx = 0;
    }
    obj[i].type = resp[idx++];
    if(obj[i].type == 0xFF)
      return n;
    else
      n++;
    obj[i].dummy = resp[idx++];
    obj[i].cx = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    obj[i].cy = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    if(max_obj_n == 0)
      break;
    obj[i].angle = ((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8);
    idx += 2;
    obj[i].obj_size = (uint32_t)((((uint16_t)resp[idx]) + (((uint16_t)resp[idx + 1]) << 8))) * 4;
    idx += 2;
  }
  return n;
}

/* Reads specified number of bytes from camera control registers (dxl API)
 * Do not forget to disable debug prints!!!
 */
uint8_t TrackingCamSPI::TrackingCam_ReadData(uint8_t addr, uint8_t len, uint8_t* resp)
{ 
  digitalWrite(nss_digital_pin, LOW);
  SPI.beginTransaction(SPISettings(speed, MSBFIRST, SPI_MODE0));
  SPI.transfer(CMD_READ);
  SPI.transfer(addr);
  for(int i = 0; i < len; i++)
  {
    resp[i] = SPI.transfer(0);
#ifdef TRACKINGCAM_SPI_DEBUG
	Serial.print(resp[i], HEX);         // print the character
	Serial.print(" ");
#endif
  }
  digitalWrite(nss_digital_pin, HIGH);
  SPI.endTransaction();
#ifdef TRACKINGCAM_SPI_DEBUG 
  Serial.print("\n");
#endif
  return 0;
}