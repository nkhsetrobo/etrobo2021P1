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
            {WALKER,{-3,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{10,0},DISTANCE,{17},-1,{},UPDATE_ALL},    
            {TAIL,{1,650},TAILJUDGE,{600},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{6,0},DISTANCE,{9},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{45,1,5,3,LEFT,0}, DISTANCE,{12},-1,{}, UPDATE_ALL},
            {STRAIGHT,{30,1,5,10,-100}, DISTANCE,{2},-1,{}, UPDATE_DIST},
            {WALKER,{0,0}, TIMEJUDGE,{20}, UNUPDATE},
            {CURVE,{45,1,5,10,0,7}, TURN,{140},-1,{}, UNUPDATE},
            {CURVE,{45,1,5,4,0,-10}, TURN,{80},-1,{}, UNUPDATE},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {CURVE,{45,1,5,10,0,-14}, TURN,{70},-1,{}, UNUPDATE},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {CURVE,{30,1,5,10,0,-5}, TURN,{30},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            /*{CURVE,{30,1,5,10,0,-10}, TURN,{35},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,10}, TURN,{20},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,-10}, TURN,{15},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,10}, TURN,{35},-1,{}, UNUPDATE},*/
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif