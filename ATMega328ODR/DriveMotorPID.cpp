#include "DriveMotorPID.h"


DriveMotorPID::DriveMotorPID(uint8_t pwm_p, uint8_t mcp_p1, uint8_t mcp_p2, bool CW_i_f, encoderSpeed es, Adafruit_MCP23017 mcp_c){
	getSpeed = es;
	mcp = mcp_c;
	clock_wise=CW_i_f;
	CW_is_forward=CW_i_f;
	pwm_pin=pwm_p;
	mcp_pin_c1=mcp_p1;
	mcp_pin_c2=mcp_p2;
	previous_time=0;
	error=0;
	last_error=0;
	cumulative_error=0;
	set_speed=0;
  
}
void DriveMotorPID::init(){
  previous_time=millis();
  pinMode(pwm_pin,OUTPUT);
  mcp.pinMode(mcp_pin_c1,OUTPUT);
  mcp.pinMode(mcp_pin_c2,OUTPUT);
  mcp.digitalWrite(mcp_pin_c1,LOW);
  mcp.digitalWrite(mcp_pin_c2,HIGH);
}
void DriveMotorPID::update(){
	double delta_t = millis()-previous_time;
	error=set_speed-getSpeed();
	cumulative_error +=error;
	double d_error=error-last_error;
  last_error=error;
	double output=set_speed*kp+cumulative_error*ki+d_error*kd;
  uint8_t pwm = 0;
  if(output>254){
    pwm=255;
  }
  else{
    pwm=(uint8_t)output;
  }
	previous_time=millis();
	analogWrite(pwm_pin,pwm);
}
void DriveMotorPID::setVelocity(double velocity){
	setDirection(velocity>0);
	set_speed=abs(velocity);	
}
void DriveMotorPID::setBrakes(bool brake){
	braking=brake;
	if(braking){
		mcp.digitalWrite(mcp_pin_c1,HIGH);
		mcp.digitalWrite(mcp_pin_c2,HIGH);
	}
	else{
		if(clock_wise){
			mcp.digitalWrite(mcp_pin_c1,LOW);
			mcp.digitalWrite(mcp_pin_c2,HIGH);
		}
		else{
			mcp.digitalWrite(mcp_pin_c1,HIGH);
			mcp.digitalWrite(mcp_pin_c2,LOW);
		}
	}
}
void DriveMotorPID::setDirection(bool forward){
	clock_wise = (forward == CW_is_forward);
	if(clock_wise){
		mcp.digitalWrite(mcp_pin_c1,LOW);
		mcp.digitalWrite(mcp_pin_c2,HIGH);
	}
	else{
		mcp.digitalWrite(mcp_pin_c1,HIGH);
		mcp.digitalWrite(mcp_pin_c2,LOW);
	}
}
