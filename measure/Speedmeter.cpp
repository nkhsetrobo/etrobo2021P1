#include "Speedmeter.h"

Speedmeter::Speedmeter()
{

}

<<<<<<< HEAD
void Speedmeter::load(float mload,/*int Measurement_time*/)
=======
void Speedmeter::load(float mload/*int Measurement_time*/)
>>>>>>> 8eab3bef2cb909a652a87a2adc847337c4a3a6c5
{
    speed = mload;
}

float Speedmeter::get_value()
{
    return speed;
}