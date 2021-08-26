#include "Section.h"

extern Walker           *gWalker;
extern LineTracer       *gLineTracer;
extern VirtualCurve     *gVirtualCurve;
extern VirtualStraight  *gVirtualStraight;
extern ArmControl       *gArmControl;
extern TailControl      *gTailControl;
extern Bright_Judge     *gBright_Judge;
extern Distance_Judge   *gDistance_Judge;
extern Turn_Judge       *gTurn_Judge;
extern Arm_Judge        *gArm_Judge;
extern Tail_Judge       *gTail_Judge;
extern SonarMeasure     *gSonarMeasure;
extern Sonar_Judge      *gSonar_Judge;

Section::Section()
{
    mWalker_list[WALKER]     = gWalker;
    mWalker_list[LINETRACER] = gLineTracer;
    mWalker_list[CURVE]      = gVirtualCurve;
    mWalker_list[STRAIGHT]   = gVirtualStraight;
    mWalker_list[ARM]        = gArmControl;
    mWalker_list[TAIL]       = gTailControl;

    mJudge_list[BRIGHT]      = gBright_Judge;
    mJudge_list[DISTANCE]    = gDistance_Judge;
    mJudge_list[TURN]        = gTurn_Judge;
    mJudge_list[ARMJUDGE]    = gArm_Judge;
    mJudge_list[TAILJUDGE]   = gTail_Judge;
    mJudge_list[SONARJUDGE]  = gSonar_Judge;
    er=0;
}

bool Section::run()
{
    if(mMain_Judge->judge()){
        er=0;
        return true;
    }
        else if(mMain_Judge2 != 0 && mMain_Judge2->judge()){
            er=1;
            return true;
        } else {
        mWalker->run();
    }
    return false;
}

void Section::set_param(int walker_no, double walker_status[],
                        int judge_no, double judge_status[],
                        int judge2_no, double judge2_status[])
{
    /*printf("set_param : w %d j1 %d j2 %d  w_st %f,%f  j1_st %f,%f j2_st %f,%f \n",walker_no ,judge_no,judge2_no , 
    walker_status[0],walker_status[1],  judge_status[0],judge_status[1], judge2_status[0],judge2_status[1]);*/
    mWalker = mWalker_list[walker_no];
    mMain_Judge = mJudge_list[judge_no];

    mWalker->init(walker_status);
    mMain_Judge->set_param(judge_status);
    
    mMain_Judge2=0;
    if(judge2_no>=0){
        mMain_Judge2 = mJudge_list[judge2_no];
        mMain_Judge2->set_param(judge2_status);
    }
}

void Section::init()
{
    
}

int Section::get_error(){
    return er;
}