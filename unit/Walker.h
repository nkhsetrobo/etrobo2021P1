#ifndef EV3_UNIT_WALKER_H_  
#define EV3_UNIT_WALKER_H_
#include "Drive.h"
#include "PID.h"
#include "Bright.h"
#include "Xpointer.h"
#include "Ypointer.h"
#include "Turn.h"
#include "Arm.h"
#include "Tail.h"

class Walker{
    public:
        Walker(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm,Tail* tail);
        virtual void run();
        virtual void init(double status[]);
        void setCommand(int forward, int turn);
        Drive* mDrive;
        PID* mPID;
        Bright* mBright;
        Xpointer* mXpointer;
        Ypointer* mYpointer;
        Turn*   mTurn;
        Arm* mArm;
        Tail* mTail;

    private:
        int tForward;
        int tTurn;

};

#endif