#ifndef ENCODE_D_H_
#define ENCODE_D_H_
#include <Arduino.h>
class DriveEncoderHandler{
  public:
    DriveEncoderHandler();
    static void update();
    static void rightInterrupt();
    static void leftInterrupt();
    static double getFrontRightSpeed();
    static double getFrontLeftSpeed();
    static double getBackRightSpeed();
    static double getBackLeftSpeed();
  private:
    static void resetCounts();
    static double speed_FR;
    static double speed_FL;
    static double speed_BR;
    static double speed_BL;
    static unsigned long previous_time;
    static bool previous_FR;
    static bool previous_FL;
    static bool previous_BR;
    static bool previous_BL;
    static long encoder_count_FR;
    static long encoder_count_FL;
    static long encoder_count_BR;
    static long encoder_count_BL;
    static long last_encoder_count_FR;
    static long last_encoder_count_FL;
    static long last_encoder_count_BR;
    static long last_encoder_count_BL;
}
