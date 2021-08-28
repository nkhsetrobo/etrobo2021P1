#include "Main_Judge.h"
extern Bright          *gBright;
extern Odometer        *gOdometer;
extern Turn            *gTurn;
extern Colorh         *gColorh;
extern Colors         *gColors;
extern Tail            *gTail;
extern Arm             *gArm;
extern SonarMeasure    *gSonarMeasure;
extern Timer           *gTimer;

Main_Judge::Main_Judge()
{
    mBright=gBright;
    mTurn=gTurn;
    mOdometer=gOdometer;
    mColorh=gColorh;
    mColors=gColors;
    mTail=gTail;
    mArm=gArm;
    mSonarMeasure=gSonarMeasure;
    mTimer=gTimer;
    //printf("Timer,%d,%f",mTimer,mTimer->get_value());
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