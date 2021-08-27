#include "Distance_Judge.h"
#include "Section_management.h"

Distance_Judge::Distance_Judge()
    : Main_Judge(),
    dvalue(),
    baseline()
{

}

bool Distance_Judge::judge()
{
    dvalue=mOdometer->get_value();
    //printf("dvalue, baseline, %f,%f\n", dvalue, baseline);
    if(diff>=0){
        if(dvalue>=baseline){/**/
            return true;
        }else{
            return false;
        }
    }else{
        if(dvalue<=baseline){
            return true;
        }else{
            return false;
        }
    }
}

void Distance_Judge::set_param(double status[])
{
    baseline=status[0]+Section_management::DIST;
    diff = baseline - mOdometer->get_value();
}

void Distance_Judge::init()
{
    
}