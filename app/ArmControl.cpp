#include "ArmControl.h"

ArmControl::ArmControl(ev3api::Motor& motor_arm,Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm*  arm,Tail* tail)
    :Walker(drive,bright,xpointer,ypointer,turn,arm,tail),
    mMotor_Arm(motor_arm),
    p(0),
    i(0),
    d(0),
    theta(),
    check(0),
    mState(UNDEFINED),
    Brake_Mood(false)
    {
        mMotor_Arm.reset();
    }

void ArmControl::run(){
   switch (mState) {
    case UNDEFINED:
        first_angle();
        break;
    case LINE_TRACING:
        angle_fixed();
        break;
    case SCENARIO_TRACING:
        angle_specification();
        break;
    default:
        break;
    }

}

void ArmControl::first_angle(){
    float theta2=mArm->get_value();
    mMotor_Arm.setPWM(-1);
    //printf("F:%f\n",theta2);
        if(theta2 <= -50){
            mState=LINE_TRACING;
        }
}

void ArmControl::angle_fixed(){
    float dire=0.0;
    if(Brake_Mood==false){
        mMotor_Arm.setBrake(Brake_Mood);
         mMotor_Arm.setPWM(dire);
        //printf("F2:%f\n",mArm->get_value());
    }else{
        mState=SCENARIO_TRACING;
    }
}

void ArmControl::angle_specification(){

    float dire;
    float theta2=mArm->get_value();
    dire=mPID->getOperation(theta2);
    mMotor_Arm.setPWM(dire);
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

