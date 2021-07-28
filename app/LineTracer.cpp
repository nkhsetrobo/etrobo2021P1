/******************************************************************************
 *  LineTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/26
 *  Implementation of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineTracer.h"

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param Drive 走行
 */
LineTracer::LineTracer(const LineMonitor* lineMonitor,
                       Drive* drive,PID* pid)
    : Walker(drive),
     mLineMonitor(lineMonitor),
     mDrive(drive),
     mPID(pid),
     mIsInitialized(false) {
}

/**
 * ライントレースする
 */
void LineTracer::run() {
    if (mIsInitialized == false) {
        mDrive->init();
        mIsInitialized = true;
    }

    bool isOnLine = mLineMonitor->isOnLine();

    // 走行体の向きを計算する
    int direction = calcDirection(isOnLine);

    mDrive->setCommand(Drive::FWD, direction);

    // 走行を行う
    mDrive->run();
}


void LineTracer::init(){
    mDrive->init();
}

/**
 * 走行体の向きを計算する
 * @param isOnLine true:ライン上/false:ライン外
 * @retval RIGHT  ライン上にある場合(右旋回指示)
 * @retval LEFT ライン外にある場合(左旋回指示)
 */
int LineTracer::calcDirection(bool isOnLine) {
    if (isOnLine) {
        // ライン上にある場合
        return Drive::TURN;
    } else {
        // ライン外にある場合
        return Drive::TURN;
    }
}