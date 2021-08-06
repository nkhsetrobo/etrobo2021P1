#include "MotorControl.h"

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */

MotorControl::MotorControl( ev3api::Motor& leftWheel,
                            ev3api::Motor& rightWheel,
                            ev3api::Motor& motor_arm)
                    : mLeftWheel(leftWheel),
                      mRightWheel(rightWheel),
                      mMotor_Arm(motor_arm)
                      {
      mLeftWheel.reset();
      mRightWheel.reset();
      mMotor_Arm.reset();

}

void MotorControl::runcontrol( int rPWM,int lPWM){
    mLeftWheel.setPWM(lPWM);
    mRightWheel.setPWM(rPWM);
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



//void MotorControl::tailcontrol(int PWM){}
