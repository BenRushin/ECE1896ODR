#include "DriveEncoderHandler.h"
DriveEncoderHandler deh=DriveEncoderHandler(1,2,3,4,5,6);
void rightInterrupt(){
  deh.rightInterrupt();
}
void leftInterrupt(){
  deh.leftInterrupt();
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(5),rightInterrupt,CHANGE);
  attachInterrupt(digitalPinToInterrupt(6),leftInterrupt,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
