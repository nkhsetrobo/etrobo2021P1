#include "Turn_Judge.h"

Turn_Judge::Turn_Judge()
    : Main_Judge(),
    tvalue(0.0),
    baseline(0.0)
    
{
    
}

bool Turn_Judge::judge()
{
    tvalue=mTurn->get_value();
    if(tvalue<baseline){/**/
        return true;
    }else{
        return false;
    }
}

void Turn_Judge::init(double status[])
{
    baseline=status[0];
}