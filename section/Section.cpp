#include "Section.h"

extern Walker           *gWalker;
extern LineTracer       *gLineTracer;
extern VirtualCurve     *gVirtualCurve;
extern VirtualStraight  *gVirtualStraight;

extern Bright_Judge     *gBright_Judge;
extern Distance_Judge   *gDistance_Judge;
extern Turn_Judge       *gTurn_Judge;

Section::Section()
{
    mWalker_list[WALKER]     = gWalker;
    mWalker_list[LINETRACER] = gLineTracer;
    mWalker_list[CURVE]      = gVirtualCurve;
    mWalker_list[STRAIGHT]   = gVirtualStraight;

    mJudge_list[BRIGHT]      = gBright_Judge;
    mJudge_list[DISTANCE]    = gDistance_Judge;
    mJudge_list[TURN]        = gTurn_Judge;
}

bool Section::run()
{
    if(mMain_Judge->judge()){
        return true;
    }
    else{
        mWalker->run();
    }
    return false;
}

void Section::set_param(int walker_no, double walker_status[],
                        int judge_no, double judge_status[])
{
    mWalker = mWalker_list[walker_no];
    mMain_Judge = mJudge_list[judge_no];

    mWalker->init(walker_status);
    mMain_Judge->set_param(judge_status);
}

void Section::init()
{
    
}