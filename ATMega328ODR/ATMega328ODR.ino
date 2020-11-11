#include <Adafruit_MCP23017.h>

#include "DriveEncoderHandler.h"
#include "DriveMotorPID.h"

Adafruit_MCP23017 mcp;
DriveEncoderHandler deh=DriveEncoderHandler(4,6,8,7);

double FRSpeed(){
  return deh.getFrontRightSpeed();
}
double FLSpeed(){
  return deh.getFrontLeftSpeed();
}
double BRSpeed(){
  return deh.getBackRightSpeed();
}
double BLSpeed(){
  return deh.getBackLeftSpeed();
}
DriveMotorPID FR_wheel=DriveMotorPID(11, 4, 5, true, FRSpeed, mcp);
DriveMotorPID FL_wheel=DriveMotorPID(10, 3, 0, false, FLSpeed, mcp);
DriveMotorPID BR_wheel=DriveMotorPID(5, 1, 2, true, BRSpeed, mcp);
DriveMotorPID BL_wheel=DriveMotorPID(9, 7, 6, false, BLSpeed, mcp);
void rightInterrupt(){
  deh.rightInterrupt();
}
void leftInterrupt(){
  deh.leftInterrupt();
}


void setup() {
  attachInterrupt(digitalPinToInterrupt(5),rightInterrupt,CHANGE);
  attachInterrupt(digitalPinToInterrupt(6),leftInterrupt,CHANGE);
  mcp.begin();
  FR_wheel.setVelocity(0.25);
  FL_wheel.setVelocity(1);
  BR_wheel.setVelocity(10);
  BL_wheel.setVelocity(100);
  FR_wheel.setBrakes(false);
  FL_wheel.setBrakes(false);
  BR_wheel.setBrakes(false);
  BL_wheel.setBrakes(false);
}

void loop() {
  // put your main code here, to run repeatedly:
  FR_wheel.update();
  FL_wheel.update();
  BR_wheel.update();
  BL_wheel.update();
}
