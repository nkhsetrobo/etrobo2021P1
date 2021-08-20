#ifndef EV3_UNIT_ANGULAR_H_
#define EV3_UNIT_ANGULAR_H_

#include "Main_Measure.h"

class Angular : public Main_Measure{
    public:
        Angular();
        void load(float mload);
        void init();
        float get_value();

    private:
    
        float angular_rate;
};

#endif 