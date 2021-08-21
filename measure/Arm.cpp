#include "Arm.h"

Arm::Arm(ev3api::Motor& motor_arm)
    : Main_Measure(),
    mMotor_Arm(motor_arm)
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

void Arm::get_count(){
    load(mMotor_Arm.getCount());

}