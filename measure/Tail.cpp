#include "Tail.h"

Tail::Tail()
    :Main_Measure()
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