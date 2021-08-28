#ifndef EV3_JUDGE_MAINJUDGE_H_
#define EV3_JUDGE_MAINJUDGE_H_

#include "Main_Measure.h"
#include "Bright.h"
#include "Turn.h"
#include "Odometer.h"
#include "Colorh.h"
#include "Colors.h"
#include "Tail.h"
#include "Arm.h"
#include "SonarMeasure.h"
#include "Timer.h"



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
        Colorh*    mColorh;
        Colors*    mColors;
        Arm*       mArm;
        Tail*      mTail;
        SonarMeasure* mSonarMeasure;
        Timer*     mTimer;
    private:
        
};

#endif 