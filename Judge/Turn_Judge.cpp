#include "Turn_Judge.h"
#include "Section_management.h"

Turn_Judge::Turn_Judge()
    : Main_Judge(),
    tvalue(0.0),
    baseline(0.0)
    
{
    
}

bool Turn_Judge::judge()
{
    tvalue=mTurn->get_value();
    if(diff>=0){
        if(tvalue>=baseline){/**/
            return true;
        }else{
            return false;
        }
    }else{
        if(tvalue<=baseline){
            return true;
        }else{
            return false;
        }
    }
}

void Turn_Judge::set_param(double status[])
{
    float pi = 3.142592;
    baseline = pi*(status[0])/180+Section_management::ANG;
    diff = baseline - mTurn->get_value();
    //printf("baseline %f,%f\n",baseline,Section_management::ANG);
}

void Turn_Judge::init()
{

}