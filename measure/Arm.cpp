#include "Arm.h"

Arm::Arm()
    : Main_Measure()
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

}