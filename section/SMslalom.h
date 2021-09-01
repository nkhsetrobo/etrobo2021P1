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
        float kp=10.0;
        float ki=1;
        float kd=0.5;
        Main_Section slalompra[100]={
            /*スラロムに登る*/
            {LINETRACER,{30,1,1,5,0,0}, DISTANCE,{10}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{30}, UNDEFINED},
            {ARM,{1,0},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{5,0}, DISTANCE,{20}, UNDEFINED},
            {LINETRACER,{55,1,0.5,15,0,0}, DISTANCE,{15}, -1,{0}, UPDATE_ALL},
            {WALKER,{-3,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{10,0},DISTANCE,{17},-1,{},UPDATE_ALL},    
            {TAIL,{1,650},TAILJUDGE,{600},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{5,0},DISTANCE,{9},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{10,1,0.5,6,LEFT,0}, DISTANCE,{6.1},-1,{}, UPDATE_ALL},
            /*スラロム登った*/
            {STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.6,3,0,19.7}, TURN,{42},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,3,0,-18.2}, TURN,{40},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,3,0,19.4}, TURN,{30},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            /*{CURVE,{30,1,5,10,0,-10}, TURN,{35},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,10}, TURN,{20},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,-10}, TURN,{15},-1,{}, UNUPDATE},
            {CURVE,{30,1,5,10,0,10}, TURN,{35},-1,{}, UNUPDATE},*/
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif