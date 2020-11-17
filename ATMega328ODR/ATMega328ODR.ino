#include <Adafruit_MCP23017.h>

#include "DriveEncoderHandler.h"
#include "DriveMotorPID.h"
#include "StepperMotorControl.h"
#define MAX 4294967295
Adafruit_MCP23017 mcp;
DriveEncoderHandler deh = DriveEncoderHandler(A3, A0, A2, A1);
StepperMotorControl SMC = StepperMotorControl(7,4,8,10);
int counter = 0;
double v=0;
unsigned long dur1=0;
unsigned long dur2=0;
unsigned long dur3=0;
unsigned long dur4=0;
unsigned long dur=0;
int inches=0;
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
DriveMotorPID BR_wheel = DriveMotorPID(11, 7, 6, true, BRSpeed, mcp);
DriveMotorPID BL_wheel = DriveMotorPID(5, 2, 3, false, BLSpeed, mcp);

void rightInterrupt() {
  deh.rightInterrupt();
}
void leftInterrupt() {
  deh.leftInterrupt();
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(2), rightInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), leftInterrupt, CHANGE);
  mcp.begin();
  deh.init();
  FR_wheel.init();
  FL_wheel.init();
  BR_wheel.init();
  BL_wheel.init();
  delay(100);
}
void loop() {
  // put your main code here, to run repeatedly:
  mcp.digitalWrite(8, LOW);
  mcp.digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur1 = pulseIn(13, HIGH);
  if(dur1==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, LOW);
  mcp.digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur2 = pulseIn(13, HIGH);
  if(dur2==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, HIGH);
  mcp.digitalWrite(9, LOW); 
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur3 = pulseIn(13, HIGH);
  if(dur3==0){dur1=MAX;}
  delay(1);
  mcp.digitalWrite(8, HIGH);
  mcp.digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  dur4 = pulseIn(13, HIGH);
  if(dur4==0){dur1=MAX;}
  delay(1);
  dur = min(min(dur1,dur2),min(dur3,dur4));
  inches = dur / 74 /2;
  if(inches<=6){
    FR_wheel.setBrakes(true);
    FL_wheel.setBrakes(true);
    BR_wheel.setBrakes(true);
    BL_wheel.setBrakes(true);
  }
  else{
    FR_wheel.setBrakes(false);
    FL_wheel.setBrakes(false);
    BR_wheel.setBrakes(false);
    BL_wheel.setBrakes(false);
  }
  
  counter++;
  if(counter%10==0){
    FR_wheel.setVelocity(v);
    FL_wheel.setVelocity(v);
    BR_wheel.setVelocity(v);
    BL_wheel.setVelocity(v);
    v=min(v+1,10);
  }
  FR_wheel.update();
  FL_wheel.update();
  BR_wheel.update();
  BL_wheel.update();
  deh.update();
  int j = (int)deh.getFrontRightSpeed();
  
  delay(5);
}
