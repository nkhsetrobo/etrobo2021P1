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
            {WALKER,{-6,0},DISTANCE,{-5},-1,{},UPDATE_ALL},
            {WALKER,{10,0},COLORJUDGE,{240,1},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{6000},-1,{}, UPDATE_ALL},

            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{10,0},DISTANCE,{24},-1,{},UPDATE_ALL},
                
            {TAIL,{1,620},TAILJUDGE,{600},-1,{},UPDATE_ALL},  
            {WALKER,{5,0},DISTANCE,{8},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{5,1,5,3,LEFT,0}, DISTANCE,{5},-1,{}, UPDATE_ALL},
            {CURVE,{30,1,5,3,0,1}, TURN,{240},-1,{}, UNUPDATE},//30
            {CURVE,{5,1,5,3,LEFT,0}, TURN,{110},-1,{}, UNUPDATE},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif