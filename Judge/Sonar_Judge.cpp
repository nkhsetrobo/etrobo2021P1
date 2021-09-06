#include "Sonar_Judge.h"
#include "ev3api.h"

Sonar_Judge::Sonar_Judge()
    : Main_Judge(),
     svalue(),
     baseline()
{
}

bool Sonar_Judge::judge()
{
    svalue=mSonarMeasure->get_value();
    //printf("%f,%f\n",baseline,svalue);
    //printf("dvalue, baseline, %f,%f\n", dvalue, baseline);
    if(svalue<=baseline){
        return true;
    }else{
        return false;
    }
}

void Sonar_Judge::set_param(double status[]){
    baseline=status[0]; //値は1以上
}

void Sonar_Judge::init()
{
    
}