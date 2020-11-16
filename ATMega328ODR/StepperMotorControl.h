#ifndef STEP_M_H
#define STEP_M_H
#include <Arduino.h>
class StepperMotorControl{
  public:
    StepperMotorControl(int pA1, int pA2, int pB1, int pB2);
    void face_dir(int d);
  private:
    int pin_A1;
    int pin_A2;
    int pin_B1;
    int pin_B2;
    int pos_id;
    void turn_90_right();
    void turn_90_left();
};
#endif
