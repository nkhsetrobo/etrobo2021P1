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
#include "Sonar_Judge.h"

class Section{
    public:
        Section();
        bool run();
        void set_param(int walker_no, double walker_status[],
                        int judge_no, double judge_status[],
                        int judge2_no, double judge2_status[]
                        );
        void init();
        int get_error();


    protected:
        Walker*     mWalker;
        Main_Judge* mMain_Judge;
        Main_Judge* mMain_Judge2;
        Walker*     mWalker_list[10];
        Main_Judge* mJudge_list[20];

    private:
        int er;//エラーコード ソナーなどの時
        
};

#endif