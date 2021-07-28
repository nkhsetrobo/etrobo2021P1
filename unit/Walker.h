#ifndef EV3_UNIT_WALKER_H_  
#define EV3_UNIT_WALKER_H_
#include "Drive.h"

class Walker{
    public:
        Walker();
        explicit Walker(Drive* drive)
        void  run();
        void init();
    
    private:
        Drive* drive;
        int mForward;
        int mTurn;

};

#endif