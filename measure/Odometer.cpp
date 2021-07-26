#include "Odometer.h"

Odometer::Odometer()
{

}

void Odometer::load(float mload)
{
    mileage = mload;
}

void Odometer::reset()
{

}

float Odometer::get_value()
{
    return mileage;
}