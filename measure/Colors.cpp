#include "Colors.h"
#include "ev3api.h"

Colors::Colors()
    : Main_Measure()
{
    
}

 
void Colors::load(float mload)
{
    svalue=mload;
}

float Colors::get_value()
{
    return svalue;
}