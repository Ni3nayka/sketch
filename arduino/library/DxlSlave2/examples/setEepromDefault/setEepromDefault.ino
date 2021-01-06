#include<DxlSlave2.h>

/* Example shows how to reset EEPROM of dxl device */

const uint8_t romDefault[] = {0x5e, 1, 100, 1, 3, 250, 0, 0, 0xff, 3, 0, 2, 65, 60, 90, 0xff, 3, 2, 3};

void setup() {
  // put your setup code here, to run once:
  DxlSlave.begin();
  Serial.begin(9600);
  for(int i = 0; i < sizeof(romDefault); i++)
  {
    DxlSlave.set(i, romDefault[i]);
    if (DxlSlave.get(i) == romDefault[i])
    {
      Serial.println("OK!!!");
    }
    else
    {
      Serial.print("The value at address ");
      Serial.print(i);
      Serial.println(" is not valid!!!");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
