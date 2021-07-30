#include "Walker.h"


Walker::Walker(Drive* drive,Bright* bright)
    :mDrive(drive),
    mBright(bright)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->run(mForward,mTurn);

}
void Walker::init()
{
    
}

void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}