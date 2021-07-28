#include "MotorControl.h"

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */

MotorControl::MotorControl( ev3api::Motor& leftWheel,
                            ev3api::Motor& rightWheel)
                    : mLeftWheel(leftWheel),
                      mRightWheel(rightWheel)
                      {

}

void MotorControl::runcontrol( int rPWM,int lPWM){
  if(rPWM>-101 and rPWM<101)
    mLeftWheel.setPWM(lPWM);
  if(lPWM>-101 and rPWM<101)
    mRightWheel.setPWM(rPWM);
}

//void MotorControl::armcontrol(int PWM){}

//void MotorControl::tailcontrol(int PWM){}
