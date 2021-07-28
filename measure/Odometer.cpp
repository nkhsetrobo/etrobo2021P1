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

}

float Odometer::get_value()
{
    return mileage;
}