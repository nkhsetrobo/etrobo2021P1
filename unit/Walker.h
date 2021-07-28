#ifndef EV3_UNIT_WALKER_H_  
#define EV3_UNIT_WALKER_H_
#include "Drive.h"
#include "PID.h"


class Walker{
    public:
        Walker();
        explicit Walker(Drive* drive,PID* pid);
        void  run();
        void init();
    
    private:
        Drive* drive;
        PID* pid;
        int mForward;
        int mTurn;

};

#endif