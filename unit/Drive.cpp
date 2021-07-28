#include "Drive.h"

// 定数宣言
const int Drive::FWD=80;

const int Drive::TURN=0;//マイナスが左、プラスが右

Drive::Drive( MotorControl* motorcontrol)
      :mForward(FWD),
       mTurn(TURN),
       mMotorControl(motorcontrol) {
}


void Drive::init(){
    mForward = 0;
    mTurn    = 0;
}

void Drive::run(int mForword,int mTurn){
    int rPWM=mForword+mTurn;
    int lPWM=mForword-mTurn;
    mMotorControl->runcontrol(rPWM,lPWM);
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回方向
 */
/*void Drive::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}*/
