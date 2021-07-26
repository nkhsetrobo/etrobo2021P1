#include "Angular.h"

Angular::Angular()
{

}

void Angular::load(float mload)
{
    angular_rate = mload;
}

void Angular::init()
{
    angular_rate.reset();
}

float Angular::get_value()
{
    return angular_rate;
}