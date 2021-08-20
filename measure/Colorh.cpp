#include "Colorh.h"
#include "ev3api.h"

Colorh::Colorh()
    : Main_Measure()
{
    
}

 
void Colorh::load(float mload)
{
    hvalue=mload;
}

float Colorh::get_value()
{
    return hvalue;
}