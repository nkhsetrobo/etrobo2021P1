#include "SMslalomb.h"
#include "ev3api.h"

SMslalomb::SMslalomb()
    : Section_management()
{
    
}


void SMslalomb::init(){
        
    if(_LEFT==0){
        status=rslalombpra;
    }else{
        status=lslalombpra;
    }
        printf("slalomb\n");
}

void SMslalomb::gonext(){
    RandomWalker::change_situation(RandomWalker::mSMblock);
}
