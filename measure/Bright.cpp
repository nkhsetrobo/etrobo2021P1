#include "Bright.h"


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