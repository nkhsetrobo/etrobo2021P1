#include "Bright.h"
#include "ev3api.h"

Bright::Bright()
    : Main_Measure()
{
    
}

 
void Bright::load(float mload)
{
    bvalue=mload;
}

float Bright::get_value()
{
    printf("%f\n",bvalue);
    return bvalue;
}