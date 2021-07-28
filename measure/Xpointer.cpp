#include "Xpointer.h"

Xpointer::Xpointer()
    : Main_Measure()
{

}

void Xpointer::load(float mload)
{
    x_coordinates=mload;
}

float Xpointer::get_value()
{
    return x_coordinates;
}
