#include "Tail_Judge.h"

Tail_Judge::Tail_Judge()
    : Main_Judge(),
    tvalue(),
    baseline()
{

}

bool Tail_Judge::judge()
{
    tvalue=mTail->get_value();
    //printf("dvalue, baseline, %f,%f\n", dvalue, baseline);
    if(tvalue>=baseline){
        return true;
    }else{
        return false;
    }
}

void Tail_Judge::set_param(double status[])
{
    baseline=status[0];
}

void Tail_Judge::init()
{
    
}