#ifndef EV3_UNIT_DRIVE_H_
#define EV3_UNIT_DRIVE_H_

#include "Motor.h"
#include "MotorControl.h"
#include "Taikei.h"

class Drive {
public:

    static const int FWD;
    
    static const int TURN;

    Drive( MotorControl* motorcontrol,Taikei* taikei);
    void init();
    void run(int mForward,int mTurn);
    void setCommand(int forward, int turn);

private:
    float mForward;
    int mTurn;
    MotorControl* mMotorControl;
    Taikei* mTaikei;
};

#endif  // EV3_UNIT_WALKER_H_
