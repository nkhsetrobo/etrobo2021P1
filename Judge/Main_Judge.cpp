#include "Main_Judge.h"
extern Bright          *gBright;
extern Odometer        *gOdometer;
extern Turn            *gTurn;

Main_Judge::Main_Judge()
{
    mBright=gBright;
    mTurn=gTurn;
    mOdometer=gOdometer;
}

void Main_Judge::run(){

}

float Main_Judge::get_value(float value){
    return value;
}

bool Main_Judge::judge()
{
    return false;
}

void Main_Judge::set_param(double status[])
{

}

void Main_Judge::init(){
    
}