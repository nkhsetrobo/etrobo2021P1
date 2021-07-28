#ifndef EV3_UNIT_TAIL_H_
#define EV3_UNIT_TAIL_H_

#include "Main_Measure.h"

class Tail : Main_Measure{
    public:
        Tail();
        void  load(float mload);
        float get_value();

    private:
        float Tail_angle;
};

#endif