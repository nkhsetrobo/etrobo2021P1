#include "MotorControl.h"

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */

MotorControl::MotorControl( ev3api::Motor& leftWheel,
                            ev3api::Motor& rightWheel,
                            ev3api::Motor& motor_arm,
                            ev3api::Motor& motor_tail)
                    : mLeftWheel(leftWheel),
                      mRightWheel(rightWheel),
                      mMotor_Arm(motor_arm),
                      mMotor_Tail(motor_tail)
                      {
      mLeftWheel.reset();
      mRightWheel.reset();
      mMotor_Arm.reset();
      mMotor_Tail.reset();
      ls=0;
      rs=0;
}

void MotorControl::runcontrol( int rPWM,int lPWM){

    int max=5;
    int l= lPWM-ls;
    int r= rPWM-rs;

    if(l>max){
      l=max;
    }else if(l<-max){
      l=-max;
    }

    if(r>max){
      r=max;
    }else if(r<-max){
      r=-max;
    }

    ls+=l;
    rs+=r;

    mLeftWheel.setPWM(ls);
    mRightWheel.setPWM(rs);
}

void MotorControl::setMotor(int aPWM){
  mMotor_Arm.setPWM(aPWM);
}

int MotorControl::get_leftMotor(){
  return mLeftWheel.getCount();
}

int MotorControl::get_rightMotor(){
  return mRightWheel.getCount();
}

int MotorControl::get_motor_arm(){
  return mMotor_Arm.getCount();
}

int MotorControl::get_motor_tail(){
  return mMotor_Tail.getCount();
}



//void MotorControl::tailcontrol(int PWM){}
