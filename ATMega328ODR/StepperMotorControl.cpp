#include "StepperMotorControl.h"
StepperMotorControl::StepperMotorControl(int pA1, int pA2, int pB1, int pB2){
  pin_A1=pA1;
  pin_A2=pA2;
  pin_B1=pB1;
  pin_B2=pB2;
  pos_id=0;
  pinMode(pin_A1,OUTPUT);
  pinMode(pin_A2,OUTPUT);
  pinMode(pin_B1,OUTPUT);
  pinMode(pin_B2,OUTPUT);
  digitalWrite(pin_A1,LOW);
  digitalWrite(pin_A2,LOW);
  digitalWrite(pin_B1,LOW);
  digitalWrite(pin_B2,LOW);
}
void StepperMotorControl::face_dir(int d){
    turn_90_right();
    if(pos_id==0){
       
    }
    else if(pos_id==1){
      
    }
    else if(pos_id==2){

    }
    else if(pos_id==3){
      
    }
}
void StepperMotorControl::turn_90_right(){
  for(int i = 0; i<200; i++){
    digitalWrite(pin_A1,HIGH);
    delay(1);
    digitalWrite(pin_B1,HIGH);
    digitalWrite(pin_A1,LOW);
    delay(1);
    digitalWrite(pin_A2,HIGH);
    digitalWrite(pin_B1,LOW);
    delay(1);
    digitalWrite(pin_B2,HIGH);
    digitalWrite(pin_A2,LOW);
    delay(1);
    digitalWrite(pin_B2,LOW);
  }
}
void StepperMotorControl::turn_90_left(){
  
}
