#include "Tail.h"

Tail::Angle()
{    
}

void Tail::load(float mload)
{
    tvalue=mload;
}

float Tail::get_value()
{
    return tvalue;
}