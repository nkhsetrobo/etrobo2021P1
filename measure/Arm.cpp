#include "Arm.h"

Arm::Arm()
{    
}

void Arm::load(float mload)
{
    Arm_angle=mload;
}

float Arm::get_value()
{
    return Arm_angle;
}

void Arm::init()
{
    Arm_angle.reset();
}