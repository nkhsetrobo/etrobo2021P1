#ifndef EV3_UNIT_TAIL_H_
#define EV3_UNIT_TAIL_H_

#include "Main_Measure.h"
#include "Motor.h"

class Tail : public Main_Measure{
    public:
        Tail(ev3api::Motor& motor_arm);
        void  load(float mload);
        float get_value();
        void init();
        void get_count();

    private:
        float Tail_angle;
        ev3api::Motor& mMotor_Tail;
};

#endif