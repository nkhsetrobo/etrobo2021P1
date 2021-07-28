/******************************************************************************
 *  ScenarioTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class ScenarioTracer
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "ScenarioTracer.h"

/**
 * コンストラクタ
 * @param drive          走行
 * @param scenario        シナリオ
 * @param timer           タイマ
 */
   @param  
ScenarioTracer::ScenarioTracer(Drive* drive,
                                Walker* walker,
                               Scenario* scenario,
                               SimpleTimer* timer)
    : mDrive(drive),
      mWalker(walker),
      mScenario(scenario),
      mSimpleTimer(timer),
      mState(UNDEFINED) {
}

/**
 * シナリオトレースする
 */
void ScenarioTracer::run() {
    switch (mState) {
    case UNDEFINED:
        execUndefined();
        break;
    case INITIAL:
        execInitial();
        break;
    case WALKING:
        execWalking();
        break;
    default:
        break;
    }
}

/**
 * シナリオトレース初期化処理
 */
void ScenarioTracer::initAction() {
    mDrive->init();
}

/**
 * トレースコマンド設定
 * @param command 走行向き
 */
void ScenarioTracer::setCommand(SceneCommands command) {
    int turn = -1;
    if (command == TURN_LEFT) {
      turn = Drive::TURN;
    } else if (command == TURN_RIGHT) {
      turn = Drive::TURN;
    }

    mDrive->setCommand(Drive::FWD, turn);
}


/**
 * シーン変更処理
 */
void ScenarioTracer::modeChangeAction() {
    mScenario->next();

    SceneCommands command = mScenario->currentSceneCommand();
    setCommand(command);

    mSimpleTimer->setTime(mScenario->currentSceneTime());
    mSimpleTimer->start();
}

/**
 * 未定義状態の処理
 */
void ScenarioTracer::execUndefined() {
    mState = INITIAL;
}

/**
 * 初期状態の処理
 */
void ScenarioTracer::execInitial() {
    initAction();   // entry アクション(INITIAL)

    mState = WALKING;   // 状態遷移

    modeChangeAction();    // entry アクション(WALKING)
}

/**
 * 走行中状態の処理
 */
void ScenarioTracer::execWalking() {
    mWalker->run();             // do アクティビティ

    if (mSimpleTimer->isTimedOut()) {   // イベントチェック
        mSimpleTimer->stop();   // exit アクション

        modeChangeAction();    // entry アクション(WALKING)
    }
}