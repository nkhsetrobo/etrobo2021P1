#ifndef EV3_UNIT_TURN_H_
#define EV3_UNIT_TURN_H_

#include "Main_Measure.h"

class Turn : public Main_Measure{
    public:
        Turn();
        void load(float mload);
        float get_value();
        void  init();

    private:

        float Turn_angle;
};

#endif