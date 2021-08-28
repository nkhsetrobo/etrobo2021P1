#include "Color_Judge.h"
#include "math.h"

Color_Judge::Color_Judge()
    : Main_Judge(),
     hvalue(),
     svalue(),
     hbaseline(),
     sbaseline()
{

}

bool Color_Judge::judge()
{
    hvalue=mColorh->get_value();
    svalue=mColors->get_value();
    printf("h,%f s,%f\n",hvalue,svalue);
    if(sbaseline>svalue){
        return false;
    }
    hvalue=hvalue-hbaseline;
    if(hvalue<180){
        hvalue=hvalue+360;
    }

    if(hvalue<hbaseline){
        return true;
    }else{
        return false;
    }
    
}

void Color_Judge::set_param(double status[]){
    sbaseline=status[0]; //s値の判断基準
    hbaseline=status[1]; //h値の判断

}

void Color_Judge::init()
{
    
}