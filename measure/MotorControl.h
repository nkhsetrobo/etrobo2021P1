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
                    ev3api::Motor& rightWheel,
                    ev3api::Motor& motor_arm,
                    ev3api::Motor& motor_tail
                    );
        void runcontrol(int rPWM,int lPWM);
        void setMotor(int aPWM);
        int get_rightMotor();
        int get_leftMotor();
        int get_motor_arm();
        int get_motor_tail();
        //void tailcontrol(int PWM);
    private:
        ev3api::Motor& mLeftWheel;
        ev3api::Motor& mRightWheel;
        ev3api::Motor& mMotor_Arm;
        ev3api::Motor& mMotor_Tail;
        //Tail* mTail;
        //Arm* mArm;
        //Turn* mTurn;

};
#endif