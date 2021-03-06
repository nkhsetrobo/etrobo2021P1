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
#include "Section.h"    //de
#include "enum.h"    //de
#include "Section_management.h"//de
#include "Drive.h"
#include "SMspeed.h"
#include "SMblock.h"
#include "SMslalom.h"
#include "SMslalomb.h"
class SMspeed;
class SMslalom;
class SMslalomb;
class SMblock;

class RandomWalker {
    
public:
    RandomWalker(LineTracer* lineTracer,
                VirtualCurve* VirtualCurve,
                VirtualStraight* VirtualStraight,
                 ScenarioTracer* scenarioTracer,
                 const Starter* starter,
                 SimpleTimer* simpleTimer);
        void run();
    static SMspeed* mSMspeed;
    static SMslalom* mSMslalom;
    static SMslalomb* mSMslalomb;
    static SMblock* mSMblock;
    static void change_situation(Section_management* csituation);

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
    
    Section* mSection;  //???????????????
    static Section_management* mSection_management;

};

#endif  // EV3_APP_RANDOMWALKER_H_