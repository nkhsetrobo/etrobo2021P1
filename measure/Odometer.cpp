#include "Odometer.h"

Odometer::Odometer()
{

}

void Odometer::load(float mload)
{
    ovalue = mload;
}

void Odometer::reset()
{

}

float Odometer::get_value()
{
    return ovalue;
}