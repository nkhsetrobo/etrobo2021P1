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
                    Tail* tail,Arm* arm,Odometer* odometer,Speedmeter* speedmeter,
                    Turn* turn,Xpointer* xpointer,Ypointer* ypointer);
        void runcontrol(int rPWM,int lPWM);
        void armcontrol(int PWM);
        void tailcontrol(int PWM);
        void virtualposition();
    private:
        ev3api::Motor& mLeftWheel;
        ev3api::Motor& mRightWheel;
        Tail* mTail;
        Arm* mArm;
        Odometer* mOdometer;
        Speedmeter* mSpeedmeter;
        Turn* mTurn;
        Xpointer* mXpointer;
        Ypointer* mYpointer;

};
#endif