#include "DriveMotorPID.h"


DriveMotorPID::DriveMotorPID(uint8_t pwm_p, uint8_t mcp_p1, uint8_t mcp_p2, bool CW_i_f, encoderSpeed es, Adafruit_MCP23017 mcp_c){
	getSpeed = es;
	mcp = mcp_c;
	clock_wise=CW_i_f;
	CW_is_forward=CW_i_f;
	pwm_pin=pwm_p;
	mcp_pin_c1=mcp_p1;
	mcp_pin_c2=mcp_p2;
	previous_time=millis();
	error=0;
	last_error=0;
	cumulative_error=0;
	set_speed=0;
  pinMode(pwm_pin,OUTPUT);
  mcp.pinMode(mcp_pin_c1,OUTPUT);
  mcp.pinMode(mcp_pin_c2,OUTPUT);
}

void DriveMotorPID::update(){
	double delta_t = millis()-previous_time;
	error=set_speed-getSpeed();
	cumulative_error +=error;
	double d_error=error-last_error;
	double speed=set_speed*DriveMotorPID::kp+cumulative_error*DriveMotorPID::ki+d_error*DriveMotorPID::kd;
	previous_time=millis();
	analogWrite(pwm_pin,speed);
}
void DriveMotorPID::setVelocity(double velocity){
	if(velocity>0 != set_speed>0){
		setDirection(velocity>0);
	}
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
