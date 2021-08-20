#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

#include "Main_Measure.h"

class Bright : public Main_Measure{
    public:
        
        Bright();
        void  load(float mload);
        float get_value();


    private:

        float bvalue;

};

#endif 