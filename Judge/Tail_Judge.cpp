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

void Tail_Judge::set_param(double status[])
{
    baseline=status[0];
    diff = baseline - mTail->get_value();
}

void Tail_Judge::init()
{
    
}