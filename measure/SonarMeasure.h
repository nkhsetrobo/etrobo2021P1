#ifndef EV3_UNIT_SONARMEASURE_H_
#define EV3_UNIT_SONARMEASURE_H_

#include "Main_Measure.h"

class SonarMeasure : Main_Measure{
    public:
        SonarMeasure();
        void load(float mload);
        float get_value();
        void init();

    private:
        float Svalue;
};

#endif