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
LineTracer::LineTracer(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn)
    : Walker(drive,bright,xpointer,ypointer,turn),
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
    dire=mPID->getOperation(mBright->get_value()); 
    dire=bias+dire;
    if(edge==-1)
    {
        dire=dire*-1.0;
    }
    // 走行体の向きを計算する
    // 走行を行う
    mDrive->run(forw,dire);
}
    


void LineTracer::init(double status[]){
    //double status[];
                    /*0=p,1=i,2=d,3=FWD,
                   4=direction,5=edge,6=bias,*/
    p=status[0];
    mPID->setKp(status[0]);
    i=status[1];
    mPID->setKi(status[1]);
    d=status[2];
    mPID->setKd(status[2]);
    forw=status[3];
    dire=status[4];
    edge=status[5];
    bias=status[6];

}
