#include "SMslalomb.h"
#include "ev3api.h"

SMslalomb::SMslalomb()
    : Section_management()
{
    
}


void SMslalomb::init(){
        status=slalombpra;
        printf("slalomb\n");
}

void SMslalomb::gonext(){
    RandomWalker::change_situation(RandomWalker::mSMblock);
}
