#include "Bright_Judge.h"

Bright_Judge::Bright_Judge()
    : Main_Judge(),
     bvalue(),
     baseline(),
     value()
{
}

bool Bright_Judge::judge()
{
    bvalue=mBright->get_value();//黒で１白で0
    //printf("value, bvalue,%f,%f\n", value, bvalue);
    if(value>0){
        if(bvalue >= baseline){
            return true;
        }else{
            return false;
        }
    }else{
        if(bvalue <= baseline){
            return true;
        }else{
            return false;
        }
    }
    
}

void Bright_Judge::set_param(double status[]){
    baseline=status[0]; //値は1以上
    value=status[1];    //値は1以上
}

void Bright_Judge::init()
{
    
}