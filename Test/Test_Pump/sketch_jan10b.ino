#include <AFMotor.h>

AF_DCMotor motor_air(1);
AF_DCMotor motor_A(2);
AF_DCMotor motor_B(3);

void setup() 
{
  motor_air.setSpeed(200);
  motor_A.setSpeed(200);
  motor_B.setSpeed(200);
  motor_air.run(RELEASE);
  motor_A.run(RELEASE);
  motor_B.run(RELEASE);
}

void loop() 
{
//  motor_air.run(BACKWARD);
//  motor_A.run(BACKWARD);
//  motor_B.run(BACKWARD);
  motor_air.run(RELEASE);
  motor_A.run(RELEASE);
  motor_B.run(RELEASE);
}
