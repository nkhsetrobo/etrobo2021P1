#ifndef EV3_UNIT_ODOMETER_H_
#define EV3_UNIT_ODOMETER_H_
#include "Main_Measure.h"

class Odometer : Main_Measure{
    public:
        Odometer();
        void load(float mload);
        void init();
        float get_value();


    private:


        float mileage;
};

#endif 