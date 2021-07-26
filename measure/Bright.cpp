#include "Bright.h"
#include "ev3api.h"

Bright::Bright()
{
    
}

 
void Bright::load(float mload)
{
    bvalue=mload;
}

float Bright::get_value()
{
    return bvalue;
}