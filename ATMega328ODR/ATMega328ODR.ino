#include <Adafruit_MCP23017.h>

#include "DriveEncoderHandler.h"
#include "DriveMotorPID.h"

Adafruit_MCP23017 mcp;
DriveEncoderHandler deh=DriveEncoderHandler(A3,A0,A2,A1);

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
DriveMotorPID FR_wheel=DriveMotorPID(9, 5, 4, true, FRSpeed, mcp);
DriveMotorPID FL_wheel=DriveMotorPID(6, 1, 0, false, FLSpeed, mcp);
DriveMotorPID BR_wheel=DriveMotorPID(11, 6, 7, true, BRSpeed, mcp);
DriveMotorPID BL_wheel=DriveMotorPID(5, 3, 2, false, BLSpeed, mcp);
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
  deh.update();
  FR_wheel.update();
  FL_wheel.update();
  BR_wheel.update();
  BL_wheel.update();
}
