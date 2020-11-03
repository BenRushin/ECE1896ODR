#ifndef ENCODE_D_H_
#define ENCODE_D_H_
#include <Arduino.h>
class DriveEncoderHandler{
  public:
    DriveEncoderHandler(uint8_t p_FR, uint8_t p_FL, uint8_t p_BR, uint8_t p_BL);
    void update();
    void rightInterrupt();
    void leftInterrupt();
    double getFrontRightSpeed();
    double getFrontLeftSpeed();
    double getBackRightSpeed();
    double getBackLeftSpeed();
  private:
    //void resetCounts();
    double speed_FR;
    double speed_FL;
    double speed_BR;
    double speed_BL;
    unsigned long previous_time;
    volatile bool previous_FR;
    volatile bool previous_FL;
    volatile bool previous_BR;
    volatile bool previous_BL;
    volatile long encoder_count_FR;
    volatile long encoder_count_FL;
    volatile long encoder_count_BR;
    volatile long encoder_count_BL;
    //long last_encoder_count_FR;
    //long last_encoder_count_FL;
    //long last_encoder_count_BR;
    //long last_encoder_count_BL;
  	uint8_t pin_FR;
  	uint8_t pin_FL;
  	uint8_t pin_BR;
  	uint8_t pin_BL;
};
#endif
