#include <accel_gyro.h>

int _ABVAR_1_z = 0 ;

void setup()
{
  setupAccel();
  Serial.begin(115200);
}

void loop()
{
  _ABVAR_1_z = readAccelAngle('z',RAW_GYRO) ;
  startMotor(1, 80);
  startMotor(2, 80);
  delay( 1000 );
  stopMotor(1);
  stopMotor(2);
  do
  {
    startMotor(1, -80);
    startMotor(2, 80);
    Serial.print("Z =");
    Serial.print(_ABVAR_1_z);
    Serial.println();
    Serial.print("A =");
    Serial.print(readAccelAngle('z',RAW_GYRO));
    Serial.println();
    delay( 300 );
  }
  while(( ( readAccelAngle('z',RAW_GYRO) ) < ( ( _ABVAR_1_z + 90 ) ) ));
  startMotor(1, 80);
  startMotor(2, 80);
  delay( 1000 );
  stopMotorHard(1);
  stopMotorHard(2);
  stopProgram();
}


