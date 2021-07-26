#include "Ypointer.h"

Ypointer::Ypointer()
{

}

void Ypointer::load(float mload)
{
    y_coordinates=mload;
}

float Ypointer::get_value()
{
    return y_coordinates;
}

void Ypointer::reset()
{
    y_coordinates.reset();
}