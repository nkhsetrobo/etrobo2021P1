#ifndef EV3_UNIT_SMSLALOM_H_
#define EV3_UNIT_SMSLALOM_H_

#include "Section_management.h"
#include "RandomWalker.h"
#include "Sonar.h"
#include "SonarMeasure.h"

class SMslalom : public Section_management{
    public:
    
        SMslalom();
        void init();
        void gonext();

    private:
        Sonar*      mSonar;
        SonarMeasure*  mSonarMeasure;
        Main_Section slalompra[100]={
            {ARM,{0,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {LINETRACER,{50,1,5,8,LEFT,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
            {TAIL,{1,300},TAILJUDGE,{300},-1,{},UPDATE_ALL},  
            {LINETRACER,{20,1,5,8,LEFT,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL},  
            {TAIL,{1,-1000},TAILJUDGE,{-900},-1,{},UPDATE_ALL}, 
            {LINETRACER,{50,1,5,50,LEFT,0}, DISTANCE,{50},-1,{}, UPDATE_ALL},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif