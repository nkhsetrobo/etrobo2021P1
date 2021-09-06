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
            {LINETRACER,{10,1,1,25,0,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{10,1,1,10,0,0}, DISTANCE,{15}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{400},-1,{},UPDATE_ALL},
            {WALKER,{-8,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{10,0},DISTANCE,{18},-1,{},UPDATE_ALL},    
            {TAIL,{1,650},TAILJUDGE,{500},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{12,0},DISTANCE,{6},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{25,2,0.5,6,LEFT,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
            /*スラロム登った*/
            {WALKER,{0,-10},TURN,{-50},-1,{}, UPDATE_ANG},
            //{STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.6,11,0,22.5}, TURN,{48},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,-16.5}, TURN,{-39},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,26}, TURN,{-30},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,11,0,26}, TURN,{0},-1,{}, UNUPDATE},
            {WALKER,{1,0},DISTANCE,{2},SONARJUDGE,{15},UPDATE_DIST},
            {CURVE,{10,2,0.6,11,0,26}, TURN,{8},-1,{}, UNUPDATE},
            {STRAIGHT,{10,2,0.6,10,8}, DISTANCE,{4},-1,{},UPDATE_DIST},
            {WALKER,{10,0},DISTANCE,{12},-1,{},UPDATE_DIST},
            //踊り場旋回
            {WALKER,{0,-10},TURN,{-85},-1,{}, UPDATE_DIST},
            {STRAIGHT,{10,1,0.6,10,-85}, DISTANCE,{10},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{WALKER,{0,-10}, TURN,{-120},-1,{}, UPDATE_DIST},
            {CURVE,{10,2,0.6,11,0,-28.5},TURN,{-120} ,-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,6,0,27},TURN,{-85} ,-1,{}, UNUPDATE},
            {WALKER,{10,0},DISTANCE,{15},-1,{},UPDATE_DIST},
            {CURVE,{10,1,0.6,6,0,18},BRIGHT,{-0.1,-1}, -1,{},UNUPDATE},
            {LINETRACER,{19,1,0.5,6,LEFT,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            {WALKER,{10,0}, SONARJUDGE,{60},-1,{}, UNDEFINED},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},

            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};

#endif