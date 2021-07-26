#include "Speedmeter.h"

Speedmeter::Speedmeter()
{

}

void Speedmeter::load(float mload)
{
    speed = mload;
}

float Speedmeter::get_value()
{
    return speed;
}