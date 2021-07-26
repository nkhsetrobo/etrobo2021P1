#include "Tail.h"

Tail::Tail()
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