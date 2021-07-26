#include "Speedometer.h"

Speedometer::Speedometer()
{

}

void Speedometer::load(float mload,/*int Measurement_time*/)
{
    speed = mload;
}

float Speedometer::get_value()
{
    return speed;
}