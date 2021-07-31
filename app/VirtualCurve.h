#ifndef EV3_APP_VIRTUALCURVE_H_
#define EV3_APP_VIRTUALCURVE_H_
#include "Walker.h"
#include "math.h"
class VirtualCurve : Walker{
    public:
        VirtualCurve(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn);
        void curve();
        void calc();
    private:
        Walker* mWalker;
};
#endif