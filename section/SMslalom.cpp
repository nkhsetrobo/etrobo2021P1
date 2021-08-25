#include "SMslalom.h"
#include "ev3api.h"
extern Sonar*        gSonar;
extern SonarMeasure*  gSonarMeasure;

SMslalom::SMslalom()
    : Section_management()
{
    mSonar=gSonar;
    mSonarMeasure=gSonarMeasure;
}


void SMslalom::init(){
        status=slalompra;
}

void SMslalom::gonext(){
    if(error==0){
        RandomWalker::change_situation(RandomWalker::mSMblock);
    }else{
        RandomWalker::change_situation(RandomWalker::mSMslalomb);
    }
}
