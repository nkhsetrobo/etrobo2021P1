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
LineTracer::LineTracer(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm*  arm)
    : Walker(drive,bright,xpointer,ypointer,turn,arm),
    mIsInitialized(false),
    p(0),
    i(0),
    d(0),
    forw(0),
    bias(0),
    edge(0){
}

/**
 * ライントレースする
 */
void LineTracer::run() {
    float dire=0.0;
    if (mIsInitialized == false) {
        mDrive->init();
        mIsInitialized = true;
    }
    //mPID->setTarget(0);
    dire=mPID->getOperation(mBright->get_value()); 
    dire=bias+dire;
    if(edge==-1)
    {
        dire=dire*-1.0;
    }
    // 走行体の向きを計算する
    // 走行を行う
    mDrive->run(forw,dire);
    //printf("%f,%f\n",forw,dire);

}


void LineTracer::init(double status[]){
    //double status[];
                    /*0=p,1=i,2=d,3=FWD,4=edge,5=bias,*/
    p=status[0];
    mPID->setKp(status[0]);
    i=status[1];
    mPID->setKi(status[1]);
    d=status[2];
    mPID->setKd(status[2]);
    forw=status[3];
    edge=status[4];
    bias=status[5];

    //printf("%f,%f,%f,%f,%f,%f\n",p,i,d,forw,edge,bias);

}
