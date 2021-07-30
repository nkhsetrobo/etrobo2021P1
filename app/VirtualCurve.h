#ifndef EV3_APP_VIRTUALCURVE_H_
#define EV3_APP_VIRTUALCURVE_H_
#include "Walker.h"
class VirtualCurve{
    public:
        VirtualCurve(Walker* walker);
        void calc();

    private:
        Walker* mWalker;
};
#endif