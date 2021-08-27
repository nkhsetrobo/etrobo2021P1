#include "Tail.h"

Tail::Tail(ev3api::Motor& motor_tail)
    :Main_Measure(),
    mMotor_Tail(motor_tail)
{    
    
}

void Tail::load(float mload)
{
    Tail_angle=mload;
}

float Tail::get_value()
{
    return Tail_angle;
}

void Tail::init(){

}

void Tail::get_count(){
    load(mMotor_Tail.getCount());
}