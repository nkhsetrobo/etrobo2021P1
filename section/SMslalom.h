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
        float ks=12;
        Main_Section lslalompra[100]={
            /*スラロムに登る*/
            {LINETRACER,{10,1,1,25,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{10,1,1,10,LineTracer::LEFT_EDGE,0}, DISTANCE,{5}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-65},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{400},-1,{},UPDATE_ALL},
            {WALKER,{-8,0},DISTANCE,{-4.2},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UNUPDATE}, 
            {WALKER,{15,0},DISTANCE,{14},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},    
            {TAIL,{1,550},TAILJUDGE,{520},-1,{},UNUPDATE},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UNUPDATE},  
            {WALKER,{10,0},DISTANCE,{21},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UNUPDATE}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UNUPDATE}, 
            {LINETRACER,{18,1,0.5,10,LineTracer::LEFT_EDGE,0}, DISTANCE,{37.7},-1,{}, UNUPDATE},
            /*スラロム登った*/
            {WALKER,{0,-5},TURN,{-45},-1,{}, UPDATE_ANG},
            //{STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.1,ks,0,20}, TURN,{40},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.1,ks,0,-19}, TURN,{-33},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{CURVE,{10,2,0.6,13,0,27}, TURN,{0},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.1,ks,0,20.5}, TURN,{-5},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.1,ks,0,11}, TURN,{-1},-1,{}, UNUPDATE},
            {WALKER,{7,0},DISTANCE,{10},-1,{},UPDATE_DIST},
            {WALKER,{7,0},DISTANCE,{8},SONARJUDGE,{16.5},UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{CURVE,{10,2,0.6,15,0,26}, TURN,{10},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {STRAIGHT,{10,2,0.1,15,8}, DISTANCE,{11},-1,{},UPDATE_DIST},
            //踊り場旋回
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{0,-10},TURN,{-95},-1,{}, UPDATE_ANG},
            {STRAIGHT,{10,1,0.1,15,-95}, DISTANCE,{8},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.1,15,0,-28.5},TURN,{-135} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.6,15,0,21},TURN,{-95} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{10,0},DISTANCE,{5},-1,{},UPDATE_DIST},
            {CURVE,{10,1,0.6,15,0,18.5},BRIGHT,{-0.1,-1}, -1,{},UNUPDATE},
            {LINETRACER,{19,1,0.5,10,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{}, UPDATE_ALL},
            {WALKER,{-10,0}, DISTANCE,{-10},-1,{}, UPDATE_DIST},
            //{LINETRACER,{19,1,0.5,15,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{}, UPDATE_ALL},
            {LINETRACER,{19,1,0.5,10,LineTracer::LEFT_EDGE,0}, SONARJUDGE,{58},-1,{}, UPDATE_ALL},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},

            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };

    Main_Section rslalompra[100]={
            /*スラロムに登る*/
            //{LINETRACER,{15,1,1,45,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{15,5,1,25,LineTracer::RIGHT_EDGE,0}, DISTANCE,{48}, -1,{0}, UPDATE_ALL},
            {LINETRACER,{15,5,1,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{5}, -1,{0}, UPDATE_ALL},
            {WALKER,{0,0}, TIMEJUDGE,{10},-1,{},UPDATE_ALL},
            {ARM,{1,-80},ARMJUDGE,{-70},-1,{},UPDATE_ALL},
            {WALKER,{7,0}, TIMEJUDGE,{600},-1,{},UPDATE_ALL},
            {WALKER,{-8,0},DISTANCE,{-4.2},-1,{},UPDATE_ALL},
            {ARM,{1,0},ARMJUDGE,{-10},-1,{},UNUPDATE}, 
            {WALKER,{8,0},DISTANCE,{12},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},    
            {TAIL,{1,600},TAILJUDGE,{580},-1,{},UNUPDATE},
            {WALKER,{0,0},TIMEJUDGE,{10},-1,{},UNUPDATE},  
            {WALKER,{10,0},DISTANCE,{22},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {TAIL,{0,0},TAILJUDGE,{10},-1,{},UNUPDATE}, 
            {ARM,{0,-50},ARMJUDGE,{-30},-1,{},UNUPDATE}, 
            {LINETRACER,{18,1,0.5,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{37},-1,{}, UNUPDATE},
            /*↑----------------いじらないで------------------↑*/
            /*スラロム登った*/
            {WALKER,{0,5},TURN,{45},-1,{}, UPDATE_ANG},
            //{STRAIGHT,{10,1,0.5,3,-50}, DISTANCE,{1},-1,{}, UPDATE_DIST},
            /*{WALKER,{0,0}, TIMEJUDGE,{50}, UNUPDATE},*/
            {CURVE,{10,2,0.1,ks,0,-20}, TURN,{-40},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.1,ks,0,21}, TURN,{33},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{CURVE,{10,2,0.6,13,0,27}, TURN,{0},-1,{}, UNUPDATE},
            {CURVE,{10,2,0.1,ks,0,-22.5}, TURN,{5},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.1,ks,0,-10}, TURN,{1},-1,{}, UNUPDATE},

            {STRAIGHT,{10,2,0.1,15,1}, DISTANCE,{10},-1,{},UPDATE_DIST},
            {STRAIGHT,{10,2,0.1,15,1}, DISTANCE,{8},SONARJUDGE,{16.5},UPDATE_DIST},

            /*{WALKER,{7,0},DISTANCE,{10},-1,{},UPDATE_DIST},
            {WALKER,{7,0},DISTANCE,{8},SONARJUDGE,{16.5},UPDATE_DIST},*/

            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            //{CURVE,{10,2,0.6,15,0,26}, TURN,{10},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {STRAIGHT,{10,2,0.1,15,-10}, DISTANCE,{8},-1,{},UPDATE_DIST},
            //踊り場旋回
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{0,10},TURN,{90},-1,{}, UPDATE_ANG},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {STRAIGHT,{10,1,0.1,14,90}, DISTANCE,{6},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.1,15,0,25},TURN,{140} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {CURVE,{10,2,0.6,15,0,-14.5},TURN,{95} ,-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {WALKER,{10,0},DISTANCE,{10},-1,{},UPDATE_DIST},
            {CURVE,{15,2,0.6,10,0,-18.5},BRIGHT,{-0.1,-1}, -1,{},UNUPDATE},
            //{CURVE,{10,1,0.6,15,0,-26.5},BRIGHT,{-0.2,-1}, -1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
            {LINETRACER,{19,1,0.5,15,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            //{LINETRACER,{19,1,0.5,15,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
            {WALKER,{-10,0},DISTANCE,{-5},-1,{},UPDATE_DIST},
            {LINETRACER,{19,1,0.5,15,LineTracer::RIGHT_EDGE,0}, SONARJUDGE,{58},-1,{}, UPDATE_ALL},
            //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},

            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };

};

#endif