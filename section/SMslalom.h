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
            {LINETRACER,{30,1,1,15,0,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{700},-1,{},UPDATE_ALL},
            {WALKER,{-3,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{10,0},DISTANCE,{18},-1,{},UPDATE_ALL},    
            {TAIL,{1,650},TAILJUDGE,{500},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{8,0},DISTANCE,{6},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{14,1,0.5,6,LEFT,0}, DISTANCE,{10.4},-1,{}, UPDATE_ALL},
            /*スラロム登った*/
            {STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.6,11,0,22.2}, TURN,{38},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,-20.2}, TURN,{-34},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,30}, TURN,{-25},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,32}, TURN,{0},-1,{}, UNUPDATE},
            {WALKER,{6,0}, DISTANCE,{20},SONARJUDGE,{50}, UPDATE_DIST},
            //踊り場旋回
            {STRAIGHT,{10,1,0.5,3,-87}, DISTANCE,{1},-1,{}, UNUPDATE},
            {WALKER,{10,0}, DISTANCE,{3},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.6,10,0,6}, TURN,{50},-1,{}, UNUPDATE},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif