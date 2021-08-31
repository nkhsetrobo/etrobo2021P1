#include "Time_Judge.h"

Time_Judge::Time_Judge()
    : Main_Judge(),
    tvalue(),
    baseline()
{

}

bool Time_Judge::judge()
{
    tvalue=mTimer->get_value();
    if(tvalue>=baseline){
        return true;
    }else{
        return false;
    }
}

void Time_Judge::set_param(double status[])
{
    baseline=status[0]+mTimer->get_value();
}

void Time_Judge::init()
{
    
}