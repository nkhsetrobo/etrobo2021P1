#include "Arm_Judge.h"
#include "ev3api.h"

Arm_Judge::Arm_Judge()
    : Main_Judge(),
     avalue(),
     baseline()
{
}

bool Arm_Judge::judge()
{
    avalue=mArm->get_value();
    printf("%f,%f\n",baseline,avalue);
    //printf("dvalue, baseline, %f,%f\n", dvalue, baseline);
    if(avalue>=baseline){
        return true;//腕の角度が規定値を超えたとき
    }else{
        return false;
    }
}

void Arm_Judge::set_param(double status[]){
    baseline=status[0]; //値は1以上
}

void Arm_Judge::init()
{
    
}