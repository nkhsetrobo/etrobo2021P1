#include "Speedmeter.h"

Speedmeter::Speedmeter()
    : Main_Measure()
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