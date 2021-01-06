#include <TrackingCamDxlUart.h>


uint32_t CAM_BaudRate;
uint8_t CAM_ID;
uint8_t Serial_port;

static uint8_t TrackingCamDxl_ReadData(uint8_t cam_id, uint8_t addr, uint8_t len, uint8_t* resp);
static uint8_t TrackingCamDxl_GetCRC(uint8_t *bufData, uint8_t sizeData);

void TrackingCamDxlUart::TrackingCamDxlUartInit(uint8_t cam_id, uint8_t serial_port, uint32_t cam_BaudRate, uint32_t pc_BaudRate, uint8_t TrackingCamTimeout)
{
  CAM_ID = cam_id;
  CAM_BaudRate = cam_BaudRate;
  Serial_port = serial_port;

  Serial.begin(pc_BaudRate);

  if(Serial_port == 0)
  Serial.begin(CAM_BaudRate);
#if defined (__AVR_ATmega2560__)
  if(Serial_port == 1)
  Serial1.begin(CAM_BaudRate);
  if(Serial_port == 2)
  Serial2.begin(CAM_BaudRate);
  if(Serial_port == 3)
  Serial3.begin(CAM_BaudRate);
#endif
  delay(100);
  
  //Read cam ID
  uint8_t resp[10];
  if(!TrackingCamDxl_ReadData(CAM_ID, 0x00, 2, resp))
  {
    Serial.println("");
    Serial.print("Tracking cam ID: ");
    Serial.print(resp[5], HEX);
    Serial.println(resp[6], HEX);
  }   

  delay(100);
  Serial.setTimeout(30);
  delay(100);
  if(Serial_port == 0)
  Serial.setTimeout(TrackingCamTimeout);
#if defined (__AVR_ATmega2560__)
  if(Serial_port == 1)
  Serial1.setTimeout(TrackingCamTimeout);
  if(Serial_port == 2)
  Serial2.setTimeout(TrackingCamTimeout);
  if(Serial_port == 3)
  Serial3.setTimeout(TrackingCamTimeout);
#endif
  delay(100);
 

}

uint8_t TrackingCamDxlUart::TrackingCamDxl_ReadBlobs(){
    
  uint8_t max_blob_n = 10;
  uint8_t resp[255];
  uint8_t n = 0;
  uint8_t idx = 5;
  bool is_bulk_reading = false;
  uint8_t lines = max_blob_n > 10? 10: max_blob_n;
 
  if(lines == 0)
    lines = 1;
    
  if(is_bulk_reading)
  {
    if(TrackingCamDxl_ReadData(CAM_ID, 16, (max_blob_n? lines * 16: 6), resp)) //Bulk reading
      return 0;
  }
 
  for(int i = 0; i < lines; i++)
  {
    if(!is_bulk_reading)
    {
      idx = 5;
      if(TrackingCamDxl_ReadData(CAM_ID, 16 + i*16, (max_blob_n? 16: 6), resp)) //Line by line reading
        return n; 
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

uint8_t TrackingCamDxlUart::TrackingCamDxl_ReadObjects()
{
  uint8_t max_obj_n = 10;
  uint8_t resp[255];
  uint8_t n = 0;
  uint8_t idx = 5;
  bool is_bulk_reading = false;
  uint8_t lines = max_obj_n > 10? 10: max_obj_n;
 
  if(lines == 0)
    lines = 1;
    
  if(is_bulk_reading)
  {
    if(TrackingCamDxl_ReadData(CAM_ID, 16, (max_obj_n? lines * 10: 6), resp)) //Bulk reading
      return 0;
  }
 
  for(int i = 0; i < lines; i++)
  {
    if(!is_bulk_reading)
    {
      idx = 5;
      if(TrackingCamDxl_ReadData(CAM_ID, 16 + i*10, (max_obj_n? 10: 6), resp)) //Line by line reading
        return n; 
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
static uint8_t TrackingCamDxl_ReadData(uint8_t cam_id, uint8_t addr, uint8_t len, uint8_t* resp) 
{

  uint8_t buf[255];
  uint8_t idx = 0;

  if(Serial_port == 0)
  Serial.flush();
#if defined (__AVR_ATmega2560__)
  if(Serial_port == 1)
  Serial1.flush();
  if(Serial_port == 2)
  Serial2.flush();
  if(Serial_port == 3)
  Serial3.flush();
#endif

  if(Serial_port == 0)
  Serial.readBytes(buf, Serial.available()); //Clear port
#if defined (__AVR_ATmega2560__)
  if(Serial_port == 1)
  Serial1.readBytes(buf, Serial1.available()); //Clear port
  if(Serial_port == 2)
  Serial2.readBytes(buf, Serial2.available()); //Clear port
  if(Serial_port == 3)
  Serial3.readBytes(buf, Serial3.available()); //Clear port
#endif

  buf[idx++] = 0xff;    //Sync byte
  buf[idx++] = 0xff;    //Sync byte
  buf[idx++] = cam_id; 
  buf[idx++] = 4;       //Dxl length
  buf[idx++] = 0x02;    //Dxl read cmd
  buf[idx++] = addr;
  buf[idx++] = len;
  buf[idx++] = TrackingCamDxl_GetCRC(buf + 2, 5);

  if(Serial_port == 0)
  Serial.write(buf, idx); 
#if defined (__AVR_ATmega2560__) 
  if(Serial_port == 1)
  Serial1.write(buf, idx); 
  if(Serial_port == 2)
  Serial2.write(buf, idx); 
  if(Serial_port == 3)
  Serial3.write(buf, idx); 
#endif

  bool is_resp = false;
  for(int i = 0; i < 20; i++)
  {
    resp[0] = resp[1];
    resp[1] = resp[2];

    if(Serial_port == 0){
    if(!Serial.readBytes(resp + 2, 1))
      return 0xFF;
  }
  #if defined (__AVR_ATmega2560__)
    if(Serial_port == 1){
    if(!Serial1.readBytes(resp + 2, 1))
      return 0xFF;
  }
      if(Serial_port == 2){
    if(!Serial2.readBytes(resp + 2, 1))
      return 0xFF;
  }
      if(Serial_port == 3){
    if(!Serial3.readBytes(resp + 2, 1))
      return 0xFF;
  }
  #endif

    
    if(resp[0] == 0xFF && resp[1] == 0xFF && resp[2] == cam_id)
    {
      is_resp = true;
      break;
    }
  }

  if(!is_resp)
  {
    Serial.println("No packet sync!");
    //Serial.print("Packet: ");
    //for(int i = 0; i < len + 6; i++)
    //  Serial.print(resp[i], HEX);
    //Serial.println("");
    return 0xFF;
  }
    

  if(Serial_port == 0){ 
  if(Serial.readBytes(resp + 3, len + 3) != len + 3)
  {
    Serial.println("No response!");
    return 0xFF;
  }
  }
#if defined (__AVR_ATmega2560__)
  if(Serial_port == 1){ 
  if(Serial1.readBytes(resp + 3, len + 3) != len + 3)
  {
    Serial.println("No response!");
    return 0xFF;
  }
  }

    if(Serial_port == 2){ 
  if(Serial2.readBytes(resp + 3, len + 3) != len + 3)
  {
    Serial.println("No response!");
    return 0xFF;
  }
  }

    if(Serial_port == 3){ 
  if(Serial3.readBytes(resp + 3, len + 3) != len + 3)
  {
    Serial.println("No response!");
    return 0xFF;
  }
  }
#endif
  if(TrackingCamDxl_GetCRC(resp + 2, len + 3) != resp[len + 5])
  {
    Serial.println("Bad CRC!");
    //Serial.print("Packet: ");
    //for(int i = 0; i < len + 6; i++)
    //  Serial.print(resp[i], HEX);
    //Serial.println("");
    return 0xFF;
  }  
  return 0;
}

static uint8_t TrackingCamDxl_GetCRC(uint8_t *bufData, uint8_t sizeData) 
{
  uint32_t crc32 = 0;
  for(uint16_t i = 0; i < sizeData; i++)
    crc32 += bufData[i];
  return (uint8_t)((~crc32) & 0xFF);
}