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
 * @param Drive 走行0
 */
LineTracer::LineTracer(Drive* drive,Bright* bright)
    : Walker(drive,bright),
    mIsInitialized(false),
    p(0),
    i(0),
    d(0),
    forw(0),
    dire(0),
    bias(0),
    edge(0){
}

/**
 * ライントレースする
 */
void LineTracer::run() {
    if (mIsInitialized == false) {
        mDrive->init();
        mIsInitialized = true;
    }

    // 走行体の向きを計算する
    float direction=mPID->getOperation(mBright->get_value());
    // 走行を行う
    mDrive->run(50,direction);
}
    


void LineTracer::init(double status[]){
    //double status[];
                    /*0=p,1=i,2=d,3=FWD,
                   4=direction,5=edge,6=bias,*/
    mPID->setKp(40);
    /*satus[0]=p;
    mPID->setKp(status[0]);*/
    mPID->setKi(1);
    /*satus[1]=i;
    mPID->setKi(status[1]);*/
    mPID->setKd(5);
    /*satus[2]=d;
    mPID->setKd(status[2]);
    status[3]=forw;
    status[4]=dire;
    satus[5]=edge;
    status[6]=bias;*/

}
