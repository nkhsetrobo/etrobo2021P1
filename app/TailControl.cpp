#include "TailControl.h"

TailControl::TailControl(ev3api::Motor& motor_tail,Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm*  arm,Tail* tail)
    :Walker(drive,bright,xpointer,ypointer,turn,arm,tail),
    mMotor_Tail(motor_tail),
    p(0),
    i(0),
    d(0),
    theta(),
    check(0),
    mState(SCENARIO_TRACING)
    {
        mMotor_Tail.reset();
    }

void TailControl::run(){
   switch (mState) {
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

void TailControl::angle_fixed(){
    float dire=0.0;
    if(check==0){
         mMotor_Tail.setPWM(dire);
        printf("F2:%f\n",mTail->get_value());
    }else{
        mState=SCENARIO_TRACING;
    }
}

void TailControl::angle_specification(){
    float dire;
    float theta2=mTail->get_value();
    dire=mPID->getOperation(theta2);
    mMotor_Tail.setPWM(dire);
    printf("dire %f,theta %f\n",dire,theta2);
}

void TailControl::init(double status[]){
    p=3;
    i=0;
    d=0;
    check=status[0];//モード番号
    theta=status[1];//角度
    mPID->setKp(p);
    mPID->setKi(i);
    mPID->setKd(d);
    mPID->setTarget(theta);
    mPID->setLimit(30);
}