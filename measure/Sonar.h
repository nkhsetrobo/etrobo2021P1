#ifndef EV3_UNIT_Sonar_H_
#define EV3_UNIT_Sonar_H_

#include "Main_Measure.h"

class Sonar : Main_Measure{
    public:
        Sonar();
        void load(float mload);
        float get_value();
        void init();

    private:
        float Svalue;
};

#endif