#include "Turn.h"

Turn::Turn()
{

}

void Turn::load(float mload)
{
    Turn_angle=mload;
}

float Turn::get_value()
{
    return Turn_angle;
}

void Turn::init()
{
}