#include "Arm.h"

Arm::Arm()
{    
}

void Arm::load(float mload)
{
    avalue=mload;
}

float Arm::get_value()
{
    return avalue;
}

void Arm::init()
{
    
}