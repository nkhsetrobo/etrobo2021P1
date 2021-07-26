#include "Speedometer.h"

Speedometer::Speedometer()
{

}

void Speedometer::load(float mload,/*int Measurement_time*/)
{
    svalue = mload;
}

float Speedometer::get_value()
{
    return svalue;
}