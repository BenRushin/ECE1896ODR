#include <Adafruit_MCP23017.h>

#include "DriveEncoderHandler.h"
#include "DriveMotorPID.h"

Adafruit_MCP23017 mcp;
DriveEncoderHandler deh = DriveEncoderHandler(A3, A0, A2, A1);

double FRSpeed() {
  return deh.getFrontRightSpeed();
}
double FLSpeed() {
  return deh.getFrontLeftSpeed();
}
double BRSpeed() {
  return deh.getBackRightSpeed();
}
double BLSpeed() {
  return deh.getBackLeftSpeed();
}
DriveMotorPID FR_wheel = DriveMotorPID(9, 5, 4, true, FRSpeed, mcp);
DriveMotorPID FL_wheel = DriveMotorPID(6, 1, 0, false, FLSpeed, mcp);
DriveMotorPID BR_wheel = DriveMotorPID(11, 6, 7, true, BRSpeed, mcp);
DriveMotorPID BL_wheel = DriveMotorPID(5, 3, 2, false, BLSpeed, mcp);
void rightInterrupt() {
  deh.rightInterrupt();
}
void leftInterrupt() {
  deh.leftInterrupt();
}


void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), rightInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), leftInterrupt, CHANGE);
  mcp.begin();
  deh.init();
  FR_wheel.init();
  FL_wheel.init();
  BR_wheel.init();
  BL_wheel.init();
  FR_wheel.setVelocity(100);
  FL_wheel.setVelocity(100);
  BR_wheel.setVelocity(100);
  BL_wheel.setVelocity(100);
  pinMode(10, OUTPUT);
  Serial.println("Go!");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  deh.update();
  FR_wheel.update();
  FL_wheel.update();
  BR_wheel.update();
  BL_wheel.update();
  analogWrite(10,255);
  Serial.println("tick");
}
