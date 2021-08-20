#include "Walker.h"


Walker::Walker(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm,Tail* tail)
   :mDrive(drive),
    mBright(bright),
    mXpointer(xpointer),
    mYpointer(ypointer),
    mTurn(turn),
    mArm(arm),
    mTail(tail)
{
    mPID = new PID();
}

void Walker::run()
{

    mDrive->run(tForward,tTurn);
    //printf("F, T,%d,%d\n",tForward, tTurn);

}

void Walker::setCommand(int forward, int turn) {
    //printf("forward, turn, %d,%d\n", forward, turn);
    tForward = forward;
    tTurn    = turn;
}

void Walker::init(double status[])
{
    //printf("s1,s2, %f,%f\n", status[0], status[1]);
    setCommand(status[0], status[1]);
}