#include "Walker.h"


Walker::Walker(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm)
   :mDrive(drive),
    mBright(bright),
    mXpointer(xpointer),
    mYpointer(ypointer),
    mTurn(turn),
    mArm(arm)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->run(tForward,tTurn);

}

void Walker::setCommand(int forward, int turn) {
    tForward = forward;
    tTurn    = turn;
}

void Walker::init(double status[])
{
    setCommand(status[0], status[1]);
}