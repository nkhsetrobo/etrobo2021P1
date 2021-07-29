#ifndef EV3_UNIT_WALKER_H_  
#define EV3_UNIT_WALKER_H_
#include "Drive.h"
#include "PID.h"
#include "Bright.h"
#include "Xpointer.h"
#include "Ypointer.h"

class Walker{
    public:
         Walker(Drive* drive);
        void run();
        void init();
        void setCommand(int forward, int turn);
    
    private:
        Drive* mDrive;
        PID* mPID;
        Bright* mBright;
        Xpointer* mXpointer;
        Ypointer* mYpointer;
        int mForward;
        int mTurn;

};

#endif