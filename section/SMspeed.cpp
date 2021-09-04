#include "SMspeed.h"

SMspeed::SMspeed()
    : Section_management()
{
    
}

void SMspeed::init(){
    if(_LEFT==0){
        status=rspeedpra;
    }else{
        //status=lspeedpra;
        status=speedpra;
    }
    
}

void SMspeed::gonext(){
    RandomWalker::change_situation(RandomWalker::mSMslalom);
}