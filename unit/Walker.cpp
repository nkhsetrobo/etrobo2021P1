#include "Walker.h"

// 定数宣言
const int Walker::FWD;

const int Walker::TURN;//マイナスが左、プラスが右
/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
Walker::Walker(ev3api::Motor& leftWheel,
                                 ev3api::Motor& rightWheel)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mForward(FWD),
      mTurn(TURN) {
}

/**
 * 走行する
 */
void Walker::run() {
    // 左右モータに回転を指示する
    int rightPWM = 0;
    int leftPWM = 0;
    
    if(mTurn > 0) {
        rightPWM = 0;
        leftPWM = mForward;
    } else if(mTurn < 0) {
        rightPWM = mForward;
        leftPWM = 0;
    } else {
        rightPWM = mForward;
        leftPWM = mForward;
    }
    
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

/**
 * 走行に必要なものをリセットする
 */
void Walker::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回方向
 */
void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
    mLeftWheel = mForward - mTurn;
    mRightWheel =  mForward + mTurn;

}
