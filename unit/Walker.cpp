#include "Walker.h"


Walker::Walker(Drive* drive)
    :mDrive(drive)
{
    mPid = new PID();
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