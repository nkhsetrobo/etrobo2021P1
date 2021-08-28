#include "Timer.h"
#include "ev3api.h"

 
Timer::Timer()
    :Main_Measure(),
    time()
{
}

void Timer::count() {
    time++;
    //printf("%d\n",time);
}

void Timer::init() {
    time=0;
}

float Timer::get_value(){
    return time;
}

void Timer:: load(float mload){

}