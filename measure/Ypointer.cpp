#include "Ypointer.h"

Ypointer::Ypointer()
    : Main_Measure()
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
