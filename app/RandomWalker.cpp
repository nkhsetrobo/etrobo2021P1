/******************************************************************************
 *  RandomWalker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include <stdlib.h>
#include "Clock.h"

#include "RandomWalker.h"

extern Drive*   gDrive;
extern Bright_Judge *gBright_Judge;
extern Turn_Judge *gTurn_Judge;
extern Distance_Judge *gDistance_Judge;

// 定数宣言
const int RandomWalker::MIN_TIME = 5000 * 1000;    // 切り替え時間の最小値
const int RandomWalker::MAX_TIME = 15000 * 1000;   // 切り替え時間の最大値

 SMspeed*   RandomWalker::mSMspeed=new SMspeed();
 SMslalom*   RandomWalker::mSMslalom=new SMslalom();
 SMslalomb*   RandomWalker::mSMslalomb=new SMslalomb();
 SMblock*   RandomWalker::mSMblock=new SMblock();
 Section_management* RandomWalker::mSection_management;

/**
 * コンストラクタ
 * @param lineTracer      ライントレーサ
 * @param scenarioTracer  シナリオトレーサ
 * @param starter         スタータ  
 * @param simpleTimer     タイマ
 */
RandomWalker::RandomWalker(LineTracer* lineTracer,
                           VirtualCurve* virtualcurve,
                           VirtualStraight* virtualstraight,
                           ScenarioTracer* scenarioTracer,
                           const Starter* starter,
                           SimpleTimer* simpleTimer)
    : mLineTracer(lineTracer),
      mVirtualCurve(virtualcurve),
      mVirtualStraight(virtualstraight),
      mScenarioTracer(scenarioTracer),
      mStarter(starter),
      mSimpleTimer(simpleTimer),
      mState(UNDEFINED) {
    ev3api::Clock* clock = new ev3api::Clock();

    srand(clock->now());  // 乱数をリセットする

    delete clock;
    mBright_Judge=gBright_Judge;
    mTurn_Judge=gTurn_Judge;
    mDistance_Judge=gDistance_Judge;


}

/**
 * ランダム走行する
 */
void RandomWalker::run() {
    switch (mState) {
    case UNDEFINED:
        execUndefined();
        break;
    case WAITING_FOR_START:
        execWaitingForStart();
        break;
    case LINE_TRACING:
        execLineTracing();
        break;
    case SCENARIO_TRACING:
        execScenarioTracing();
        break;
    default:
        break;
    }
}

/**
 * 乱数を取得する
 * @retrun 乱数
 */
int RandomWalker::getRandomTime() {
    return MIN_TIME +
        static_cast<int>(static_cast<double>(rand()) *
                         (MAX_TIME - MIN_TIME + 1.0) / (1.0 + RAND_MAX));
}
/**
 * シーン変更処理
 */
void RandomWalker::modeChangeAction() {
    mSimpleTimer->setTime(getRandomTime());
    mSimpleTimer->start();
}

/**
 * 未定義状態の処理
 */
void RandomWalker::execUndefined() {
    mState = WAITING_FOR_START;
}

/**
 * 開始待ち状態の処理
 */
void RandomWalker::execWaitingForStart() {
    if (mStarter->isPushed()) {
        mState = LINE_TRACING;

        /*
        double status[]={30,1,5,50,0,40};
        mVirtualCurve->init(status);
        */

        double status[]={30,5,1,30,-45,0};
        //mVirtualStraight->init(status);

        /*mSection = new Section();
        double walker_status[]={30,1,5,30,-40};
        double judge_status[]={30};
        mSection->set_param(STRAIGHT, walker_status, 
                            TURN, judge_status); */
        
        

        change_situation(mSMspeed);//mSMspeedに直す
        modeChangeAction();
    }
}

/**
 * ライントレース状態の処理
 */
void RandomWalker::execLineTracing() {
   
    //mVirtualStraight->run();
    
    //bool x = mSection->run();    //デバック用
    //printf("%d\n",x);

    bool x = mSection_management->do_run();   
    
    if(x==true){
        gDrive->run(0,0);
    }

    if (mSimpleTimer->isTimedOut()) {
        mSimpleTimer->stop();

        mState = LINE_TRACING;

        modeChangeAction();
    }
}

/**
 * シナリオトレース状態の処理
 */
void RandomWalker::execScenarioTracing() {
    mScenarioTracer->run();

    if (mSimpleTimer->isTimedOut()) {
        mSimpleTimer->stop();

        mState = LINE_TRACING;

        modeChangeAction();
    }
}

void RandomWalker::change_situation(Section_management* csituation){
    mSection_management = csituation;
}