#include "Walker.h"


Walker::Walker(Drive* drive)
    :mDrive(drive)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->setCommand(mForward,mTurn);

}
void Walker::init()
{
    
}

void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}