#include "Tail.h"

Tail::Tail()
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