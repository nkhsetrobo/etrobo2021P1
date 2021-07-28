#include "Angular.h"

Angular::Angular()
    : Main_Measure()
{

}

void Angular::load(float mload)
{
    angular_rate = mload;
}

void Angular::init()
{
}

float Angular::get_value()
{
    return angular_rate;
}