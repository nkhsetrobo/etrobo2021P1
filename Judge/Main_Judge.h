#ifndef EV3_JUDGE_MAINJUDGE_H_
#define EV3_JUDGE_MAINJUDGE_H_

#include "Main_Measure.h"
#include "Bright.h"
#include "Turn.h"
#include "Odometer.h"


class Main_Judge{
    public:
        Main_Judge();
        virtual void run();
        virtual float get_value(float value);
        virtual void init();
        virtual bool judge();
        virtual void set_param(double status[]);
        Bright*     mBright;
        Turn*       mTurn;
        Odometer*   mOdometer;

    private:
        
};

#endif 