#include "Odometer.h"

Odometer::Odometer()
{

}

void Odometer::load(float mload)
{
    mileage = mload;
}

void Odometer::init()
{
    mileage.reset();
}

float Odometer::get_value()
{
    return mileage;
}