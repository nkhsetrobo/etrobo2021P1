#ifndef EV3_APP_TAILCONTROL_H_
#define EV3_APP_TAILCONTROL_H_
#include "Tail.h"
#include "Walker.h"

class TailControl :public Walker{
    public:
        TailControl(ev3api::Motor& motor_tail,Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm,Tail* tail);
        void run();
        void init(double status[]);
        void angle_specification();
        void angle_fixed();
    private:
        ev3api::Motor& mMotor_Tail;
        int p;
        int i;
        int d;
        int theta;  
        int check;
        enum State {
             LINE_TRACING,
            SCENARIO_TRACING
        };
        State mState;
};
#endif
