#ifndef EV3_MEASURE_COLORS_H_
#define EV3_MEASURE_COLORS_H_

#include "Main_Measure.h"

class Colors : public Main_Measure{
    public:
        
        Colors();
        void  load(float mload);
        float get_value();


    private:

        float svalue;

};

#endif