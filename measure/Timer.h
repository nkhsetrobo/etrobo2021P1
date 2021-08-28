#ifndef EV3_MEASURE_TIMER_H_
#define EV3_MEASURE_TIMER_H_

#include "Main_Measure.h"

class Timer : public Main_Measure{
    public:
        Timer();
        void load(float mload);
        void count();
        float get_value();
        void init();

    private:
        int time;
};

#endif