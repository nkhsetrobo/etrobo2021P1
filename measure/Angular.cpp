#include "Angular.h"

Angular::Angular()
{

}

void Angular::load(float mload)
{
    angular_rate = mload;
}

void Angular::reset()
{

}

float Angular::get_value()
{
    return angular_rate;
}