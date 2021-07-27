#include "SpeedControl.h"

SpeedControl::SpeedControl(){

}

void SpeedControl::getFWD(int aimspeed){
    
}

void SpeedControl::init(){
    nspeed=0;
    aiming=0;
    fspeed=0;
}

void SpeedControl::addspeed(){
    nspeed=nspeed-fspeed;
}