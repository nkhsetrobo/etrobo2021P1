#ifndef EV3_UNIT_WALKER_H_
#define EV3_UNIT_WALKER_H_

#include "Motor.h"

class Walker {
public:

    static const int FWD;
    
    static const int TURN;

    Walker(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel);

    void init();
    void run();
    void setCommand(int forward, int turn);

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int mForward=300;
    int mTurn=30;
};

#endif  // EV3_UNIT_WALKER_H_
