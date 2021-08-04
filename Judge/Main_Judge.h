#ifndef EV3_JUDGE_MAINJUDGE_H_
#define EV3_JUDGE_MAINJUDGE_H_

#include "Main_Measure.h"
#include "Bright.h"
#include "Turn.h"
#include "Odometer.h"


class Main_Judge{
    public:
        Main_Judge();
        void run();
        float get_value(float value);
        void init();
        bool judge();
        Bright* mBright;
        Turn* mTurn;
        Odometer* mOdometer;

    private:
        
};

#endif 