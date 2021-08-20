#ifndef EV3_MEASURE_COLORH_H_
#define EV3_MEASURE_COLORH_H_

#include "Main_Measure.h"

class Colorh : Main_Measure{
    public:
        
        Colorh();
        void  load(float mload);
        float get_value();


    private:

        float hvalue;

};

#endif 