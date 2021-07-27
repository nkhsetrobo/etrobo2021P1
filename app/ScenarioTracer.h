/******************************************************************************
 *  ScenarioTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class ScenarioTracer
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_SCENARIOTRACER_H_
#define EV3_APP_SCENARIOTRACER_H_

#include "Drive.h"
#include "Walker.h"
#include "SimpleTimer.h"
#include "Scenario.h"

class ScenarioTracer {
public:
    ScenarioTracer(Drive* drive,
                    Walker* walker,
                   Scenario* scenario,
                   SimpleTimer* timer);

    void run();

private:
    enum State {
        UNDEFINED,
        INITIAL,
        WALKING
    };

    Drive* mDrive;
    Walker* walker;
    Scenario* mScenario;
    SimpleTimer* mSimpleTimer;
    State mState;

    void initAction();
    void setCommand(SceneCommands command);
    void modeChangeAction();
    void execUndefined();
    void execInitial();
    void execWalking();
};

#endif  // EV3_APP_SCENARIOTRACER_H_