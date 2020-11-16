#include <Adafruit_MCP23017.h>

#include "DriveEncoderHandler.h"
#include "DriveMotorPID.h"
#include "StepperMotorControl.h"
#define MAX 4294967295
Adafruit_MCP23017 mcp;
DriveEncoderHandler deh = DriveEncoderHandler(A3, A0, A2, A1);
StepperMotorControl SMC = StepperMotorControl(7,4,8,10);

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
//DriveMotorPID FR_wheel = DriveMotorPID(9, 5, 4, true, FRSpeed, mcp);
//DriveMotorPID FL_wheel = DriveMotorPID(6, 1, 0, false, FLSpeed, mcp);
//DriveMotorPID BR_wheel = DriveMotorPID(11, 6, 7, true, BRSpeed, mcp);
//DriveMotorPID BL_wheel = DriveMotorPID(5, 3, 2, false, BLSpeed, mcp);

void rightInterrupt() {
  deh.rightInterrupt();
}
void leftInterrupt() {
  deh.leftInterrupt();
}
void go_forward(){
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(5,LOW);
  delay(10);
  mcp.digitalWrite(4,HIGH);
  mcp.digitalWrite(5, LOW);
  mcp.digitalWrite(1,HIGH);
  mcp.digitalWrite(0,LOW);
  mcp.digitalWrite(6,HIGH);
  mcp.digitalWrite(7,LOW);
  mcp.digitalWrite(2,HIGH);
  mcp.digitalWrite(3,LOW);
  delay(10);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
}
void go_backwards(){
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(5,LOW);
  delay(10);
  mcp.digitalWrite(4,LOW);
  mcp.digitalWrite(5,HIGH);
  mcp.digitalWrite(1,LOW);
  mcp.digitalWrite(0,HIGH);
  mcp.digitalWrite(6,LOW);
  mcp.digitalWrite(7,HIGH);
  mcp.digitalWrite(2,LOW);
  mcp.digitalWrite(3,HIGH);
  delay(10);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
}

void go_right(){
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(5,LOW);
  delay(10);
  mcp.digitalWrite(4,HIGH);
  mcp.digitalWrite(5,LOW);
  mcp.digitalWrite(1,HIGH);
  mcp.digitalWrite(0,LOW);
  mcp.digitalWrite(6,LOW);
  mcp.digitalWrite(7,HIGH);
  mcp.digitalWrite(2,LOW);
  mcp.digitalWrite(3,HIGH);
  delay(10);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
}
void go_left(){
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(5,LOW);
  delay(10);
  mcp.digitalWrite(4,LOW);
  mcp.digitalWrite(5,HIGH);
  mcp.digitalWrite(1,LOW);
  mcp.digitalWrite(0,HIGH);
  mcp.digitalWrite(6,HIGH);
  mcp.digitalWrite(7,LOW);
  mcp.digitalWrite(2,HIGH);
  mcp.digitalWrite(3,LOW);
  delay(10);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
}
void stop_now(){
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(5,LOW);
}
void setup() {
  attachInterrupt(digitalPinToInterrupt(2), rightInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), leftInterrupt, CHANGE);
  mcp.begin();
  deh.init();
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  mcp.pinMode(5, OUTPUT);
  mcp.pinMode(4, OUTPUT);
  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(0,OUTPUT);
  mcp.pinMode(6, OUTPUT);
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(3, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.pinMode(8, OUTPUT);
  mcp.pinMode(9, OUTPUT);
  //FR_wheel.init();
  //FL_wheel.init();
  //BR_wheel.init();
  //BL_wheel.init();
  //FR_wheel.setVelocity(100);
  //FL_wheel.setVelocity(100);
  //BR_wheel.setVelocity(100);
  //BL_wheel.setVelocity(100);
  delay(100);
  go_forward();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*mcp.digitalWrite(8, LOW);
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
    stop_now();
  }
  else{
    go_forward();
  }
  deh.update();
  delay(5);*/
  delay(1000);
  go_right();
  delay(1000);
  go_left();
  delay(2000);
  go_backwards();
  //FR_wheel.update();
  //FL_wheel.update();
  //BR_wheel.update();
  //BL_wheel.update();
}
