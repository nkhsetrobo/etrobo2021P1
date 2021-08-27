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
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {LINETRACER,{50,1,5,3,LEFT,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            {TAIL,{1,1000},TAILJUDGE,{600},-1,{},UPDATE_ALL},  
            {LINETRACER,{50,1,5,10,LEFT,0}, DISTANCE,{4},-1,{}, UPDATE_ALL},
            {TAIL,{1,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL},  
            {STRAIGHT,{5,1,5,50,LEFT,0}, DISTANCE,{15},-1,{}, UPDATE_ALL},
            {CURVE,{30,1,5,3,0,2}, TURN,{60},-1,{}, UNUPDATE},//30
            {CURVE,{30,1,5,3,0,1}, TURN,{60},-1,{}, UNUPDATE},//30
            {LINETRACER,{5,1,5,3,LEFT,0}, DISTANCE,{10},-1,{}, UNUPDATE},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif