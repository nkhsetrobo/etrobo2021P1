#ifndef EV3_UNIT_WALKER_H_
#define EV3_UNIT_WALKER_H_

#include "Motor.h"

class Walker {
public:
    static const int LOW;
    static const int NORMAL;
    static const int HIGH;
    
    static const int RIGHT;
    static const int LEFT;

    Walker(ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel);

    void init();
    void run();
    void setCommand(int forward, int turn);

private:
    ev3api::Motor& mLeftWheel;
    ev3api::Motor& mRightWheel;
    int mForward;
    int mTurn;
};

#endif  // EV3_UNIT_WALKER_H_