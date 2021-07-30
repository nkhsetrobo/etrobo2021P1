/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "Walker.h"

class LineTracer : Walker{
    public:
        LineTracer(Drive* drive,Bright* bright);
        void run();
        void init();

    private:
        bool  mIsInitialized;
        float p;
        float i;
        float d;
        float forw;
        float dire;
        float bias;
        float edge;

};

#endif  // EV3_APP_LINETRACER_H_
