#include "Speedmeter.h"

Speedmeter::Speedmeter()
{

}

void Speedmeter::load(float mload/*int Measurement_time*/)
{
    speed = mload;
}

float Speedmeter::get_value()
{
    return speed;
}