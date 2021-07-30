#ifndef EV3_UNIT_WALKER_H_  
#define EV3_UNIT_WALKER_H_
#include "Drive.h"
#include "PID.h"
#include "Bright.h"

class Walker{
    public:
        Walker(Drive* drive,Bright* bright);
        void run();
        void init();
        void setCommand(int forward, int turn);
        Drive* mDrive;
        PID* mPID;
        Bright* mBright;

    private:
        int mForward;
        int mTurn;

};

#endif