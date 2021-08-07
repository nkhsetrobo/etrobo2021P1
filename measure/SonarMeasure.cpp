#include "SonarMeasure.h"

SonarMeasure::SonarMeasure()
    : Main_Measure()
{
    
}

void SonarMeasure::load(float mload)
{
    Svalue=mload;
}

float SonarMeasure::get_value()
{
    return Svalue;
}

void SonarMeasure::init()
{

}