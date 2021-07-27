#include "MotorControl.h"

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */

MotorControl::MotorControl( ev3api::Motor& leftWheel,
                            ev3api::Motor& rightWheel,
                            Tail* tail,Arm* arm,Odometer* odometer,Speedmeter* speedmeter,
                            Turn* turn,Xpointer* xpointer,Ypointer* ypointer)
                    : mLeftWheel(leftWheel),
                      mRightWheel(rightWheel),
                      mTail(tail),
                      mArm(arm),
                      mOdometer(odometer),
                      mSpeedmeter(speedmeter),
                      mTurn(turn),
                      mXpointer(xpointer),
                      mYpointer(ypointer)

                      {

}

void MotorControl::runcontrol( int rPWM,int lPWM){
   
    mLeftWheel.setPWM(lPWM);
    mRightWheel.setPWM(rPWM);
}

void MotorControl::armcontrol(int PWM){

}

void MotorControl::tailcontrol(int PWM){

}

void virtualposition(){

}