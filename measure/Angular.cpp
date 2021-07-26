#include "Angular.h"

Angular::Angular()
{

}

void Angular::load(float mload)
{
    avalue = mload;
}

void Angular::reset()
{

}

float Angular::get_value()
{
    return avalue;
}