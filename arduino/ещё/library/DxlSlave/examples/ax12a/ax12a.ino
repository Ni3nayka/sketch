#include <DxlSlave.h>

/* Example shows how to emulate AX-12A robot actuator */

//EEPROM regs
#define AX_00_MODEL_NUMBER          0
#define AX_02_VERSION_OF_FIRMWARE   2
#define AX_03_ID                    3
#define AX_04_BAUD_RATE             4
#define AX_05_RETURN_DELAY_TIME     5
#define AX_06_CW_ANGLE_LIMIT        6
#define AX_08_CCW_ANGLE_LIMIT       8
#define AX_11_HIGH_LIMIT_TEMP       11
#define AX_12_LOWET_LIMIT_VOLTAGE   12
#define AX_13_HIGHEST_LIMIT_VOLTAGE 13
#define AX_14_MAX_TORQUE            14
#define AX_16_STATUS_RET_LEVEL      16
#define AX_17_ALARM_LED             17
#define AX_18_ALARM_SHUTDOWN        18

//RAM regs
#define AX_24_TORQUE_ENABLE         24
#define AX_25_LED                   25
#define AX_26_CW_COMPLIANCE_MARGIN  26
#define AX_27_CCW_COMPLIANCE_MARGIN 27
#define AX_28_CW_COMPLIANCE_SLOPE   28
#define AX_29_CCW_COMPLIANCE_SLOPE  29
#define AX_30_GOAL_POSITION         30
#define AX_32_MOVING_SPEED          32
#define AX_34_TORQUE_LIMIT          34
#define AX_36_PRESENT_POSITION      36
#define AX_38_PRESENT_SPEED         38
#define AX_40_PRESENT_LOAD          40
#define AX_42_PRESENT_VOLTAGE       42
#define AX_43_PRESENT_TEMPERATURE   43
#define AX_44_REGISTERED            44
#define AX_46_MOVING                46
#define AX_47_LOCK                  47
#define AX_48_PUNCH                 48

#define IS_INITED_REG 19

uint32_t cur_time = millis();

void setup() {
  // put your setup code here, to run once:
  DxlSlave.begin(12, 0);
  Serial.begin(9600);

  // init EEPROM only on first boot
  if(!DxlSlave.get(IS_INITED_REG))
  {
    Serial.println("First boot");
    DxlSlave.set(IS_INITED_REG, 1);

    DxlSlave.set_id(1); // the same as DxlSlave.set(AX_03_ID, 1);
    DxlSlave.set_baud(1); // the same as DxlSlave.set(AX_04_BAUD_RATE, 1);
    DxlSlave.set16(AX_06_CW_ANGLE_LIMIT,        0);
    DxlSlave.set16(AX_08_CCW_ANGLE_LIMIT,       1023);
    DxlSlave.set(AX_11_HIGH_LIMIT_TEMP,         70);
    DxlSlave.set(AX_12_LOWET_LIMIT_VOLTAGE,     60);
    DxlSlave.set(AX_13_HIGHEST_LIMIT_VOLTAGE,   140);
    DxlSlave.set16(AX_14_MAX_TORQUE,            1023);
    DxlSlave.set(AX_16_STATUS_RET_LEVEL,        2);
    DxlSlave.set(AX_17_ALARM_LED,               36);
    DxlSlave.set(AX_18_ALARM_SHUTDOWN,          36); 
  }

  // init RAM
  DxlSlave.set(AX_24_TORQUE_ENABLE,         0);
  DxlSlave.set(AX_25_LED,                   0);
  DxlSlave.set(AX_26_CW_COMPLIANCE_MARGIN,  1);
  DxlSlave.set(AX_27_CCW_COMPLIANCE_MARGIN, 1);
  DxlSlave.set(AX_28_CW_COMPLIANCE_SLOPE,   32);
  DxlSlave.set(AX_29_CCW_COMPLIANCE_SLOPE, 32);
  DxlSlave.set16(AX_30_GOAL_POSITION,     1234);
  DxlSlave.set16(AX_32_MOVING_SPEED,      1345);
  DxlSlave.set16(AX_34_TORQUE_LIMIT,      1456);
  DxlSlave.set16(AX_36_PRESENT_POSITION,  345);
  DxlSlave.set16(AX_38_PRESENT_SPEED,     1345);
  DxlSlave.set16(AX_40_PRESENT_LOAD,      1456);
  DxlSlave.set(AX_42_PRESENT_VOLTAGE,     60);
  DxlSlave.set(AX_43_PRESENT_TEMPERATURE, 60);
  DxlSlave.set(AX_44_REGISTERED,          0);
  DxlSlave.set(AX_46_MOVING,              0);
  DxlSlave.set(AX_47_LOCK,                0);
  DxlSlave.set(AX_48_PUNCH,               32);

  // setup read-only regs
  DxlSlave.set_mode16(AX_36_PRESENT_POSITION,  0);
  DxlSlave.set_mode16(AX_38_PRESENT_SPEED,     0);
  DxlSlave.set_mode16(AX_40_PRESENT_LOAD,      0);
  DxlSlave.set_mode(AX_42_PRESENT_VOLTAGE,     0);
  DxlSlave.set_mode(AX_43_PRESENT_TEMPERATURE, 0);
  DxlSlave.set_mode(AX_44_REGISTERED,          0);
  DxlSlave.set_mode(AX_46_MOVING,              0);
}


void loop() {
  // put your main code here, to run repeatedly:
  while(DxlSlave.poll())
  { 
    uint8_t addr = DxlSlave.scan();
    switch(addr)
    {
      case AX_06_CW_ANGLE_LIMIT:
        Serial.print("CW Angle Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_08_CCW_ANGLE_LIMIT:
        Serial.print("CCW Angle Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_11_HIGH_LIMIT_TEMP:
        Serial.print("Highest Limit Temperature modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_12_LOWET_LIMIT_VOLTAGE:
        Serial.print("Lowest Limit Voltage modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_13_HIGHEST_LIMIT_VOLTAGE:
        Serial.print("Highest Limit Voltage modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_14_MAX_TORQUE:
        Serial.print("Max Torque modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_16_STATUS_RET_LEVEL:
        Serial.print("Status Return Level modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_17_ALARM_LED:
        Serial.print("Alarm LED modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_18_ALARM_SHUTDOWN:
        Serial.print("Alarm Shutdown modified to ");
        Serial.println(DxlSlave.get(addr));
        break;

      case AX_24_TORQUE_ENABLE:
        Serial.print("Torque Enable modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_25_LED:
        Serial.print("LED modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_26_CW_COMPLIANCE_MARGIN:
        Serial.print("CW Compliance Margin modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_27_CCW_COMPLIANCE_MARGIN:
        Serial.print("CCW Compliance Margin modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_28_CW_COMPLIANCE_SLOPE:
        Serial.print("CW Compliance Slope modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_29_CCW_COMPLIANCE_SLOPE:
        Serial.print("CCW Compliance Slope modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_30_GOAL_POSITION:
        Serial.print("Goal Position modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_32_MOVING_SPEED:
        Serial.print("Moving Speed modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_34_TORQUE_LIMIT:
        Serial.print("Torque Limit modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
      case AX_36_PRESENT_POSITION:
      case AX_38_PRESENT_SPEED:
      case AX_40_PRESENT_LOAD:
      case AX_42_PRESENT_VOLTAGE:
      case AX_43_PRESENT_TEMPERATURE:
      case AX_44_REGISTERED:
      case AX_46_MOVING:
        Serial.println("Error, trying to modify read only register");
        break;
      case AX_47_LOCK:
        Serial.print("Lock modified to ");
        Serial.println(DxlSlave.get(addr));
        break;
      case AX_48_PUNCH:
        Serial.print("Punch modified to ");
        Serial.println(DxlSlave.get16(addr));
        break;
    };
  }

  // some emulation for read only regs
  if (millis() - cur_time > 1000) // once per 1 s
  {
    cur_time = millis();
    DxlSlave.set16(AX_36_PRESENT_POSITION, DxlSlave.get16(AX_36_PRESENT_POSITION) < 1023? DxlSlave.get16(AX_36_PRESENT_POSITION) + 25: 0);
    DxlSlave.set16(AX_38_PRESENT_SPEED, DxlSlave.get16(AX_38_PRESENT_SPEED) < 2047? DxlSlave.get16(AX_38_PRESENT_SPEED) + 25: 0);
    DxlSlave.set16(AX_40_PRESENT_LOAD, DxlSlave.get16(AX_40_PRESENT_LOAD) < 2047? DxlSlave.get16(AX_40_PRESENT_LOAD) + 25: 0);
    DxlSlave.set(AX_42_PRESENT_VOLTAGE, DxlSlave.get(AX_42_PRESENT_VOLTAGE) + 3);
    DxlSlave.set(AX_43_PRESENT_TEMPERATURE, DxlSlave.get(AX_43_PRESENT_TEMPERATURE) + 3);
  }
}
