#include "Section.h"

Section::Section()
{

}

bool Section::run()
{
    if(mMain_Judge->judge()){
        return true;
    }
    else{
        mWalker->run();
    }
    return false;
}

void Section::init()
{

}