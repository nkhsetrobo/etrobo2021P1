#include "Odometer.h"

Odometer::Odometer()
    : Main_Measure()
{

}

void Odometer::load(float mload)
{
    mileage = mload;
}

void Odometer::init()
{
    mileage=0;
}

float Odometer::get_value()
{
    return mileage;
}