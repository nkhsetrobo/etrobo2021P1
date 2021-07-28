#ifndef EV3_UNIT_ARM_H_
#define EV3_UNIT_ARM_H_

#include "Main_Measure.h"

class Arm : Main_Measure{
    public:
        Arm();
        void load(float mload);
        float get_value();
        void init();

    private:

        float Arm_angle;
};

#endif