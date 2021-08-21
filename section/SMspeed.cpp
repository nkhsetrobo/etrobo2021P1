#include "SMspeed.h"

SMspeed::SMspeed()
    : Section_management()
{
    
}

void SMspeed::init(){
    if(_LEFT==0){
        status=rspeedpra;
    }else{
        status=speedpra;
    }
    
}