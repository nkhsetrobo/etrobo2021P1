#include "Starter.h"

/**
 * コンストラクタ
 * @param touchSensor タッチセンサ
 */
Starter::Starter(const ev3api::TouchSensor& touchSensor)
    : mTouchSensor(touchSensor) {
}

/**
 * 押下中か否か
 * @retval true  押下している
 * @retval false 押下していない
 */
bool Starter::isPushed() const {
    return mTouchSensor.isPressed();
}
