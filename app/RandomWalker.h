/******************************************************************************
 *  RandomWalker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class RandomWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_RANDOMWALKER_H_
#define EV3_APP_RANDOMWALKER_H_

#include "Starter.h"
#include "SimpleTimer.h"

#include "LineTracer.h"
#include "VirtualCurve.h"
#include "VirtualStraight.h"
#include "ScenarioTracer.h"
#include "Bright_Judge.h"
#include "Turn_Judge.h"
#include "Distance_Judge.h"

class RandomWalker {
public:
    RandomWalker(LineTracer* lineTracer,
                VirtualCurve* VirtualCurve,
                VirtualStraight* VirtualStraight,
                 ScenarioTracer* scenarioTracer,
                 const Starter* starter,
                 SimpleTimer* simpleTimer);
                void run();

private:
    enum State {
        UNDEFINED,
        WAITING_FOR_START,
        LINE_TRACING,
        SCENARIO_TRACING
    };

    static const int MIN_TIME;
    static const int MAX_TIME;

    LineTracer* mLineTracer;
    VirtualCurve* mVirtualCurve;
    VirtualStraight* mVirtualStraight;
    ScenarioTracer* mScenarioTracer;
    const Starter* mStarter;
    SimpleTimer* mSimpleTimer;
    State mState;
    Bright_Judge* mBright_Judge;
    Turn_Judge* mTurn_Judge;
    Distance_Judge* mDistance_Judge;

    int getRandomTime();
    void modeChangeAction();
    void execUndefined();
    void execWaitingForStart();
    void execLineTracing();
    void execScenarioTracing();
};

#endif  // EV3_APP_RANDOMWALKER_H_