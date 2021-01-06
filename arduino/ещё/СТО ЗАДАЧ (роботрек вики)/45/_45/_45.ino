#include <accel_gyro.h>

int _ABVAR_1_z = 0 ;

void setup()
{
  setupAccel();
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
  }
  while(( ( readAccelAngle('z',RAW_GYRO) ) < ( ( _ABVAR_1_z + 45 ) ) ));
  startMotor(1, 80);
  startMotor(2, 80);
  delay( 1000 );
  stopMotorHard(1);
  stopMotorHard(2);
  stopProgram();
}


