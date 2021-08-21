#ifndef EV3_UNIT_ARM_H_
#define EV3_UNIT_ARM_H_

#include "Main_Measure.h"
#include "Motor.h"

class Arm : public Main_Measure{
    public:
        Arm(ev3api::Motor& motor_arm);
        void load(float mload);
        float get_value();
        void init();
        void get_count();

    private:
        ev3api::Motor& mMotor_Arm;
        float Arm_angle;
};

#endif