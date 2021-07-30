#ifndef EV3_UNIT_MOTORCONTROL_H_
#define EV3_UNIT_MOTORCONTROL_H_
#include "Motor.h"
#include "Tail.h"
#include "Arm.h"
#include "Odometer.h"
#include "Speedmeter.h"
#include "Turn.h"
#include "Xpointer.h"
#include "Ypointer.h"

class MotorControl{
    public:
        explicit MotorControl( ev3api::Motor& leftWheel,
                    ev3api::Motor& rightWheel);
        void runcontrol(int rPWM,int lPWM);
        int get_rightMotor();
        int get_leftMotor();
        //void armcontrol(int PWM);
        //void tailcontrol(int PWM);
    private:
        ev3api::Motor& mLeftWheel;
        ev3api::Motor& mRightWheel;
        //Tail* mTail;
        //Arm* mArm;
        //Turn* mTurn;

};
#endif