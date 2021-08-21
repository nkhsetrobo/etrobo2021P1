#include "SMslalom.h"

SMslalom::SMslalom()
    : Section_management()
{
    
}


void SMslalom::init(){
        status=slalompra;
}

void SMslalom::gonext(){
    RandomWalker::change_situation(RandomWalker::mSMblock);
}