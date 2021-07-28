#include "Walker.h"


Walker::Walker(Drive* drive,PID* mPID)
    :mDrive(drive)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->setCommand(mForword,mTurn);

}
void Walker::init()
{
    
}
void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}