#include "Sonar.h"

Sonar::Sonar()
    : Main_Measure()
{
    
}

void Sonar::load(float mload)
{
    Svalue=mload;
}

float Sonar::get_value()
{
    return Svalue;
}

void Sonar::init()
{

}