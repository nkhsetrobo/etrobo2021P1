#include "ArmControl.h"

ArmControl::ArmControl(ev3api::Motor& motor_arm,Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm*  arm)
    :Walker(drive,bright,xpointer,ypointer,turn,arm),
    mMotor_Arm(motor_arm),
    p(0),
    i(0),
    d(0),
    theta(),
    check(0)
    {
        mMotor_Arm.reset();
    }

void ArmControl::angle_specification(){

    float dire;
    float theta2=mArm->get_value();
    dire=mPID->getOperation(theta2);
    mMotor_Arm.setPWM(dire);
    printf("%f\n",dire);
}

void ArmControl::init(double status[]){
    p=2;
    i=0;
    d=0;
    check=status[0];//モード番号
    theta=status[1];//角度
    mPID->setKp(p);
    mPID->setKi(i);
    mPID->setKd(d);
    mPID->setTarget(theta);
}

void ArmControl::run(){
   

//if
    angle_specification();
}
