#ifndef EV3_UNIT_SMSLALOM_H_
#define EV3_UNIT_SMSLALOM_H_

#include "Section_management.h"
#include "RandomWalker.h"
#include "Sonar.h"
#include "SonarMeasure.h"
#include "LineTracer.h"

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
        Main_Section lslalompra[100]={
            /*スラロムに登る*/
            {LINETRACER,{10,1,1,25,LineTracer::LEFT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{10,1,1,10,LineTracer::LEFT_EDGE,0}, DISTANCE,{5}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{300},-1,{},UPDATE_ALL},
            {WALKER,{-8,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{15,0},DISTANCE,{12},-1,{},UPDATE_ALL},    
            {TAIL,{1,550},TAILJUDGE,{500},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{12,0},DISTANCE,{13},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            {LINETRACER,{15,1,0.5,10,LineTracer::LEFT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            /*スラロム登った*/
            {WALKER,{0,-10},TURN,{-50},-1,{}, UPDATE_ANG},
            //{STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.6,15,0,21}, TURN,{43},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,12,0,-19}, TURN,{-30},-1,{}, UNUPDATE},
            //{CURVE,{10,2,0.6,13,0,27}, TURN,{0},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,12,0,45}, TURN,{-5},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,13,0,10}, TURN,{3},-1,{}, UNUPDATE},
            //{WALKER,{7,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            {WALKER,{7,0},DISTANCE,{4},SONARJUDGE,{16.5},UPDATE_DIST},
            {CURVE,{10,2,0.6,15,0,26}, TURN,{10},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {STRAIGHT,{10,2,0.6,15,8}, DISTANCE,{4},-1,{},UPDATE_DIST},
            {WALKER,{15,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            //踊り場旋回
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{0,-10},TURN,{-80},-1,{}, UPDATE_DIST},
            {STRAIGHT,{10,1,0.6,15,-80}, DISTANCE,{8},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{WALKER,{0,-10}, TURN,{-120},-1,{}, UPDATE_DIST},
            {CURVE,{10,2,0.6,15,0,-27},TURN,{-126} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.6,15,0,20},TURN,{-80} ,-1,{}, UNUPDATE},
            {WALKER,{10,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            {CURVE,{10,1,0.6,15,0,17.5},BRIGHT,{-0.1,-1}, -1,{},UNUPDATE},
            {LINETRACER,{19,1,0.5,15,LineTracer::LEFT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            {WALKER,{15,0}, SONARJUDGE,{60},-1,{}, UNDEFINED},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},

            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };

    Main_Section rslalompra[100]={
            /*スラロムに登る*/
            {LINETRACER,{10,1,1,25,LineTracer::RIGHT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{10,1,1,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{5}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{300},-1,{},UPDATE_ALL},
            {WALKER,{-8,0},DISTANCE,{-3},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UPDATE_ALL}, 
            {WALKER,{15,0},DISTANCE,{12},-1,{},UPDATE_ALL},    
            {TAIL,{1,550},TAILJUDGE,{500},-1,{},UPDATE_ALL},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UPDATE_ALL},  
            {WALKER,{12,0},DISTANCE,{13},-1,{}, UPDATE_ALL},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UPDATE_ALL}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UPDATE_ALL}, 
            /*↑----------------いじらないで------------------↑*/
            /*スラロム登った*/
            {LINETRACER,{15,1,0.5,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},//distanceをいじる
            {WALKER,{0,10},TURN,{50},-1,{}, UPDATE_ANG},//その場旋回50度
            //{STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.6,15,0,-21}, TURN,{-43},-1,{}, UNUPDATE},//カーブの配列最後が半径、turnがその角度で止める
            {CURVE,{10,2,0.6,12,0,19}, TURN,{30},-1,{}, UNUPDATE},
            //{CURVE,{10,2,0.6,13,0,27}, TURN,{0},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,12,0,-45}, TURN,{5},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.6,13,0,-10}, TURN,{-3},-1,{}, UNUPDATE},//ここまでやってくれると助かる
            //{WALKER,{7,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            {WALKER,{7,0},DISTANCE,{4},SONARJUDGE,{16.5},UPDATE_DIST},
            {CURVE,{10,2,0.6,15,0,-26}, TURN,{-10},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {STRAIGHT,{10,2,0.6,15,-8}, DISTANCE,{4},-1,{},UPDATE_DIST},
            {WALKER,{15,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            //踊り場旋回
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{0,10},TURN,{80},-1,{}, UPDATE_DIST},
            {STRAIGHT,{10,1,0.6,15,80}, DISTANCE,{8},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{WALKER,{0,-10}, TURN,{-120},-1,{}, UPDATE_DIST},
            {CURVE,{10,2,0.6,15,0,27},TURN,{126} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.6,15,0,-20},TURN,{80} ,-1,{}, UNUPDATE},
            {WALKER,{10,0},DISTANCE,{8},-1,{},UPDATE_DIST},
            {CURVE,{10,1,0.6,15,0,-17.5},BRIGHT,{-0.1,-1}, -1,{},UNUPDATE},
            {LINETRACER,{19,1,0.5,15,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            {WALKER,{15,0}, SONARJUDGE,{60},-1,{}, UNDEFINED},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},

            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };

};

#endif