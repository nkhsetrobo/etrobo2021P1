#include "Timer.h"
#include "ev3api.h"

 
Timer::Timer()
    :time()
{

}

void Timer::count() {
    time++;
}

void Timer::reset() {
    time=0;
}