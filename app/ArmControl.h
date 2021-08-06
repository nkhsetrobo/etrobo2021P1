#ifndef EV3_APP_ARMCONTROL_H_
#define EV3_APP_ARMCONTROL_H_
#include "Arm.h"
#include "Walker.h"

class ArmControl : Walker{
    public:
        ArmControl(ev3api::Motor& motor_arm,Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm);
        void run();
        void init(double status[]);
        void angle_specification();
    private:
        ev3api::Motor& mMotor_Arm;
        int p;
        int i;
        int d;
        int theta;  
        int check;
};
#endif
