#ifndef EV3_UNIT_DRIVE_H_
#define EV3_UNIT_DRIVE_H_

#include "Motor.h"
#include "MotorControl.h"

class Drive {
public:

    static const int FWD;
    
    static const int TURN;

    Drive( MotorControl* motorcontrol);
    void init();
    void run(int mForword,int mTurn);
    void setCommand(int forward, int turn);

private:
    int mForward;
    int mTurn;
    MotorControl* mMotorControl;
};

#endif  // EV3_UNIT_WALKER_H_
