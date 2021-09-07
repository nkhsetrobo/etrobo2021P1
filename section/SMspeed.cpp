#include "SMspeed.h"

SMspeed::SMspeed()
    : Section_management()
{
    
}

void SMspeed::init(){
    if(_LEFT==0){
        //status=rspeedpra;
        status=rspeedpraA;
    }else{
        //status=lspeedpra;
        status=lspeedpraA;
    }
    
}

void SMspeed::gonext(){
    RandomWalker::change_situation(RandomWalker::mSMslalom);
}