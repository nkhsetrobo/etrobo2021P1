#include "Arm.h"

Arm::Angle()
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

void Arm::reset()
{
    .reset();
}