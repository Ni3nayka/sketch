#include <DxlSlave.h>

/* Example shows how to emulate dxl device with the following settings:
 *  device model      1234
 *  software version  12
 *  dxl id            1
 *  baud rate         1 (1000000 bps)
 *  
 * Register table:
 *  addr      mem     size    mode  function
 *  0..5      EEPROM  -       -     system 
 *  6..22     EEPROM  8 bit   RW    general purpose
 *  23        EEPROM  8 bit   RW    EEPROM initialized flag
 *  24..99    RAM     8 bit   RW    general purpose
 *  100       RAM     8 bit   R     auto incrementing demo
 *  101..199  RAM     8 bit   R     general purpose
 *  200..239  RAM     16 bit  RW    general purpose
 *  240       RAM     16 bit  R     auto incrementing demo
 *  242..254  RAM     16 bit  R     general purpose
 *  
 */

#define IS_INITED_REG 23
 
uint32_t cur_time = millis();

void setup() {
  // put your setup code here, to run once:
  // init dxl slave with model number 1234 and software version 12
  DxlSlave.begin(1234, 12);
  Serial.begin(9600);

  // init EEPROM only on first boot
  if(!DxlSlave.get(IS_INITED_REG))
  {
    Serial.println("First boot");
    DxlSlave.set(IS_INITED_REG, 1);

    DxlSlave.set_id(1); // the same as DxlSlave.set(3, 1);
    DxlSlave.set_baud(1); // the same as DxlSlave.set(4, 1);

    // fill regs with values = addr
    for(int i = 6; i < 23; i++)
      DxlSlave.set(i, i);
  }

  // fill RAM regs
  for(int i = 24; i < 200; i++)
  {
    DxlSlave.set(i, i);

    // set read only access modes to some regs
    if(i >= 100)
      DxlSlave.set_mode(i, 0);
  }

  // fill some regs as 16 bit pairs
  for(int i = 200; i < 255; i += 2)
  {
    DxlSlave.set16(i, 1000 + i);

    // set read only mode for some reg pairs
    if(i >= 240)
      DxlSlave.set_mode16(i, 0);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  while(DxlSlave.poll())
  { 
    uint8_t addr = DxlSlave.scan();

    if(addr < 200)
    {
      Serial.print(" The value at address ");
      Serial.print(addr);
      Serial.print(" was changed by master. New value is ");
      Serial.println(DxlSlave.get(addr));
    }
    else if(!(addr % 2))
    {
      Serial.print(" 16 bit value at address ");
      Serial.print(addr);
      Serial.print(" was changed by master. New value is ");
      Serial.println(DxlSlave.get16(addr));
    }
  }

  // some emulation for read only regs
  if (millis() - cur_time > 1000) // once per 1 s
  {
    cur_time = millis();
    DxlSlave.set(100, DxlSlave.get(100) + 1);
    DxlSlave.set16(240, DxlSlave.get16(240) + 25);
  }
}
