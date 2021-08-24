#ifndef EV3_UNIT_SECTION_H_
#define EV3_UNIT_SECTION_H_

#include "Walker.h"
#include "Main_Judge.h"
#include "LineTracer.h"
#include "VirtualCurve.h"
#include "VirtualStraight.h"
#include "Bright_Judge.h"
#include "Distance_Judge.h"
#include "Turn_Judge.h"
#include "enum.h"
#include "ArmControl.h"
#include "TailControl.h"
#include "Arm_Judge.h"
#include "Tail_Judge.h"

class Section{
    public:
        Section();
        bool run();
        void set_param(int walker_no, double walker_status[],
                        int judge_no, double judge_status[]);
        void init();


    protected:
        Walker*     mWalker;
        Main_Judge* mMain_Judge;
        Walker*     mWalker_list[10];
        Main_Judge* mJudge_list[20];

    private:
        
};

#endif