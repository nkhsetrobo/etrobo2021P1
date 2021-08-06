#include "Distance_Judge.h"

Distance_Judge::Distance_Judge()
    : Main_Judge(),
    dvalue(),
    baseline()
{

}

bool Distance_Judge::judge()
{
    dvalue=mOdometer->get_value();
    if(dvalue>=baseline){
        return true;
    }else{
        return false;
    }
}

void Distance_Judge::set_param(double status[])
{
    baseline=status[0];
}

void Distance_Judge::init()
{
    
}