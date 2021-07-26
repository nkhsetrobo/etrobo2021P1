#include "Arm.h"

Arm::Arm()
<<<<<<< HEAD
{    
=======
{
        
>>>>>>> 8eab3bef2cb909a652a87a2adc847337c4a3a6c5
}

void Arm::load(float mload)
{
    avalue=mload;
}

float Arm::get_value()
{
    return avalue;
}

void Arm::init()
{
<<<<<<< HEAD
    
=======
    avalue.reset();
>>>>>>> 8eab3bef2cb909a652a87a2adc847337c4a3a6c5
}