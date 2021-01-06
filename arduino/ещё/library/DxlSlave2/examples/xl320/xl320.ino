#include <DxlSlave2.h>

/* Example shows how to emulate XL-320 robot actuator */

//EEPROM regs
#define XL_00_MODEL_NUMBER          0
#define XL_02_VERSION_OF_FIRMWARE   2
#define XL_03_ID                    3
#define XL_04_BAUD_RATE             4
#define XL_05_RETURN_DELAY_TIME     5
#define XL_06_CW_ANGLE_LIMIT        6
#define XL_08_CCW_ANGLE_LIMIT       8
#define XL_11_CONTROL_MODE          11
#define XL_12_TEMPERATURE_LIMIT     12
#define XL_13_MIN_LIMIT_VOLTAGE     13
#define XL_14_MXL_LIMIT_VOLTAGE     14
#define XL_15_MXL_TORQUE            15
#define XL_17_STATUS_RET_LEVEL      17
#define XL_18_ALARM_SHUTDOWN        18

//RAM regs
#define XL_24_TORQUE_ENABLE         24
#define XL_25_LED                   25
#define XL_27_D_GAIN                27
#define XL_28_I_GAIN   28
#define XL_29_P_GAIN  29
#define XL_30_GOAL_POSITION         30
#define XL_32_MOVING_SPEED          32
#define XL_35_TORQUE_LIMIT          35
#define XL_37_PRESENT_POSITION      37
#define XL_39_PRESENT_SPEED         39
#define XL_41_PRESENT_LOAD          41
#define XL_45_PRESENT_VOLTAGE       45
#define XL_46_PRESENT_TEMPERATURE   46
#define XL_47_REGISTERED            47
#define XL_49_MOVING                49
#define XL_50_HW_ERROR_STATUS       50
#define XL_51_PUNCH                 51

#define IS_INITED_REG 19

uint32_t cur_time = millis();

void setup() {
  // put your setup code here, to run once:
  DxlSlave.begin(350, 102);
  Serial.begin(9600);

  // init RAM
  DxlSlave.set(XL_24_TORQUE_ENABLE,         0);
  DxlSlave.set(XL_25_LED,                   0);
  DxlSlave.set(XL_27_D_GAIN, 1);
  DxlSlave.set(XL_28_I_GAIN,   32);
  DxlSlave.set(XL_29_P_GAIN, 32);
  DxlSlave.set16(XL_30_GOAL_POSITION,     1234);
  DxlSlave.set16(XL_32_MOVING_SPEED,      1345);
  DxlSlave.set16(XL_35_TORQUE_LIMIT,      1456);
  DxlSlave.set16(XL_37_PRESENT_POSITION,  345);
  DxlSlave.set16(XL_39_PRESENT_SPEED,     1345);
  DxlSlave.set16(XL_41_PRESENT_LOAD,      1456);
  DxlSlave.set(XL_45_PRESENT_VOLTAGE,     60);
  DxlSlave.set(XL_46_PRESENT_TEMPERATURE, 60);
  DxlSlave.set(XL_47_REGISTERED,          0);
  DxlSlave.set(XL_49_MOVING,              0);
  DxlSlave.set(XL_50_HW_ERROR_STATUS,                0);
  DxlSlave.set(XL_51_PUNCH,               32);

  // setup read-only regs
  DxlSlave.set_mode16(XL_37_PRESENT_POSITION,  0);
  DxlSlave.set_mode16(XL_39_PRESENT_SPEED,     0);
  DxlSlave.set_mode16(XL_41_PRESENT_LOAD,      0);
  DxlSlave.set_mode(XL_45_PRESENT_VOLTAGE,     0);
  DxlSlave.set_mode(XL_46_PRESENT_TEMPERATURE, 0);
  DxlSlave.set_mode(XL_47_REGISTERED,          0);
  DxlSlave.set_mode(XL_49_MOVING,              0);
}


void loop() {
  // put your main code here, to run repeatedly:
  while(DxlSlave.poll())
  { 
    uint8_t addr = DxlSlave.scan();
    switch(addr)
    {
      case XL_06_CW_ANGLE_LIMIT:
        Serial.print("CW Angle Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_08_CCW_ANGLE_LIMIT:
        Serial.print("CCW Angle Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_11_CONTROL_MODE:
        Serial.print("Control mode modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_12_TEMPERATURE_LIMIT:
        Serial.print("Temperature limit modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_13_MIN_LIMIT_VOLTAGE:
        Serial.print("Min Limit Voltage modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_14_MXL_LIMIT_VOLTAGE:
        Serial.print("Max Limit Voltage modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_17_STATUS_RET_LEVEL:
        Serial.print("Status Return Level modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_18_ALARM_SHUTDOWN:
        Serial.print("Alarm Shutdown modified to ");
        Serial.println(DxlSlave.get(addr));
        break;

      case XL_24_TORQUE_ENABLE:
        Serial.print("Torque Enable modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_25_LED:
        Serial.print("LED modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_27_D_GAIN:
        Serial.print("D Gain modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_28_I_GAIN:
        Serial.print("I Gain modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_29_P_GAIN:
        Serial.print("P Gain modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_30_GOAL_POSITION:
        Serial.print("Goal Position modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_32_MOVING_SPEED:
        Serial.print("Moving Speed modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_35_TORQUE_LIMIT:
        Serial.print("Torque Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case XL_50_HW_ERROR_STATUS:
        Serial.print("Lock modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case XL_51_PUNCH:
        Serial.print("Punch modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
    };
  }
  
  // some emulation for read only regs
  if (millis() - cur_time > 1000) // once per 1 s
  {
    cur_time = millis();
    DxlSlave.set16(XL_37_PRESENT_POSITION, DxlSlave.get16(XL_37_PRESENT_POSITION) < 1023? DxlSlave.get16(XL_37_PRESENT_POSITION) + 25: 0);
    DxlSlave.set16(XL_39_PRESENT_SPEED, DxlSlave.get16(XL_39_PRESENT_SPEED) < 2047? DxlSlave.get16(XL_39_PRESENT_SPEED) + 25: 0);
    DxlSlave.set16(XL_41_PRESENT_LOAD, DxlSlave.get16(XL_41_PRESENT_LOAD) < 2047? DxlSlave.get16(XL_41_PRESENT_LOAD) + 25: 0);
    DxlSlave.set(XL_45_PRESENT_VOLTAGE, DxlSlave.get(XL_45_PRESENT_VOLTAGE) + 3);
    DxlSlave.set(XL_46_PRESENT_TEMPERATURE, DxlSlave.get(XL_46_PRESENT_TEMPERATURE) + 3);
  }
}
