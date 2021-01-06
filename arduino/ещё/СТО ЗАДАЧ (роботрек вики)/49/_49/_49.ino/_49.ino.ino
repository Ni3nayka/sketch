#include <accel_gyro.h>

int _ABVAR_1_a;
int _ABVAR_2_z = 0 ;

void setup()
{
  setupAccel();
}

void loop()
{
  for (_ABVAR_1_a=1; _ABVAR_1_a<= ( 8 ); ++_ABVAR_1_a )
  {
    startMotor(1, 80);
    startMotor(2, 80);
    delay( 1000 );
    stopMotorHard(1);
    stopMotorHard(2);
    _ABVAR_2_z = readAccelAngle('z',RAW_GYRO) ;
    do
    {
      startMotor(1, -40);
      startMotor(2, 40);
    }
    while(( ( readAccelAngle('z',RAW_GYRO) ) <= ( ( _ABVAR_2_z + 40 ) ) ));
    stopMotorHard(1);
    stopMotorHard(2);
    delay( 1000 );
  }
  stopProgram();
}


