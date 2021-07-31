#include "Walker.h"


Walker::Walker(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn)
   :mDrive(drive),
    mBright(bright),
    mXpointer(xpointer),
    mYpointer(ypointer),
    mTurn(turn)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->run(tForward,tTurn);

}
void Walker::init()
{
    
}

void Walker::setCommand(int forward, int turn) {
    tForward = forward;
    tTurn    = turn;
}