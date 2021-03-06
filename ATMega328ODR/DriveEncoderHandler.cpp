#include "DriveEncoderHandler.h"
#define CLICKS_PER_REVOLUTION 540.0

DriveEncoderHandler::DriveEncoderHandler(uint8_t p_FR, uint8_t p_FL, uint8_t p_BR, uint8_t p_BL){
	pin_FR=p_FR;
	pin_FL=p_FL;
	pin_BR=p_BR;
	pin_BL=p_BL;
	speed_FR=0;
	speed_FL=0;
	speed_BR=0;
	speed_BL=0;
	encoder_count_FR=0;
	encoder_count_FL=0;
	encoder_count_BR=0;
	encoder_count_BL=0;
	//last_encoder_count_FR=0;
	//last_encoder_count_FL=0;
	//last_encoder_count_BR=0;
	//last_encoder_count_BL=0;
}
void DriveEncoderHandler::init(){
  pinMode(pin_FR,INPUT);
  pinMode(pin_FL,INPUT);
  pinMode(pin_BR,INPUT);
  pinMode(pin_BL,INPUT);
  previous_FR=digitalRead(pin_FR);
  previous_FL=digitalRead(pin_FL);
  previous_BR=digitalRead(pin_BR);
  previous_BL=digitalRead(pin_BL);
  previous_time=millis();  
}
void DriveEncoderHandler::update(){
	noInterrupts();
	unsigned long delta = previous_time-millis();
  double delta_s = (double)delta / 60000.0;
	speed_FR=(encoder_count_FR/delta_s)/CLICKS_PER_REVOLUTION;
	speed_FL=(encoder_count_FL/delta_s)/CLICKS_PER_REVOLUTION;
	speed_BR=(encoder_count_BR/delta_s)/CLICKS_PER_REVOLUTION;
	speed_BL=(encoder_count_BL/delta_s)/CLICKS_PER_REVOLUTION;
	//last_encoder_count_FR=encoder_count_FR;
	//last_encoder_count_FL=encoder_count_FL;
	//last_encoder_count_BR=encoder_count_BR;
	//last_encoder_count_BL=encoder_count_BL;
	encoder_count_FR=0;
	encoder_count_FL=0;
	encoder_count_BR=0;
	encoder_count_BL=0;
	previous_time=millis();
	interrupts();
}
void DriveEncoderHandler::rightInterrupt(){
	if(digitalRead(pin_FR)!=previous_FR){
		encoder_count_FR++;
		previous_FR = !previous_FR;
	}
	if(digitalRead(pin_BR)!=previous_BR){
		encoder_count_BR++;
		previous_BR = !previous_BR;
	}
}
void DriveEncoderHandler::leftInterrupt(){
	if(digitalRead(pin_FL)!=previous_FL){
		encoder_count_FL++;
		previous_FL = !previous_FL;
	}
	if(digitalRead(pin_BL)!=previous_BL){
		encoder_count_BL++;
		previous_BL = !previous_BL;
	}
}
double DriveEncoderHandler::getFrontRightSpeed(){
	return speed_FR;
}
double DriveEncoderHandler::getFrontLeftSpeed(){
	return speed_FL;
}
double DriveEncoderHandler::getBackRightSpeed(){
	return speed_BR;
}
double DriveEncoderHandler::getBackLeftSpeed(){
	return speed_BL;
}
