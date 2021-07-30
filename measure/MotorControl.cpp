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
    mLeftWheel.setPWM(lPWM);
    mRightWheel.setPWM(rPWM);
}

//void MotorControl::armcontrol(int PWM){}

//void MotorControl::tailcontrol(int PWM){}
