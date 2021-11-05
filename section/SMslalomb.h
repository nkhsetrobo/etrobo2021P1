#ifndef EV3_UNIT_SMSLALOMB_H_
#define EV3_UNIT_SMSLALOMB_H_

#include "Section_management.h"
#include "RandomWalker.h"


class SMslalomb : public Section_management{
    public:
    
        SMslalomb();
        void init();
        void gonext();

    private:
        Main_Section lslalombpra[100]={
            //{WALKER,{10,0},DISTANCE,{2},-1,{},UNUPDATE},
             {CURVE,{15,2,0.6,11,0,-15.5}, TURN,{-28},-1,{}, UNUPDATE},
             //{WALKER,{0,-10},TURN,{-50},-1,{},UNUPDATE},
             //{WALKER,{10,0},DISTANCE,{10},-1,{},UNUPDATE},
            //{CURVE,{10,2,0.6,11,0,10},TURN,{-30} ,-1,{}, UNUPDATE},
             {CURVE,{10,2,0.6,11,0,-46},TURN,{-90} ,-1,{}, UNUPDATE},
             {WALKER,{10,0},DISTANCE,{10},-1,{},UPDATE_DIST},
             {CURVE,{10,1,0.6,6,0,-15},BRIGHT,{-0.3,-1}, -1,{},UNUPDATE},
             {LINETRACER,{14,1,0.5,15,LineTracer::LEFT_EDGE,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
             //{WALKER,{-10,0},DISTANCE,{-7},-1,{}, UPDATE_ALL},
             {LINETRACER,{10,1,0.6,15,LineTracer::LEFT_EDGE,0},SONARJUDGE,{58},-1,{}, UPDATE_ALL},
                        
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };




        Main_Section rslalombpra[100]={
            {WALKER,{10,0},DISTANCE,{5.2},-1,{},UNUPDATE},
            {CURVE,{10,2,0.6,6,0,13}, TURN,{35},-1,{}, UNUPDATE},
             //{WALKER,{0,-10},TURN,{-50},-1,{},UNUPDATE},
             //{WALKER,{10,0},DISTANCE,{10},-1,{},UNUPDATE},
             //{CURVE,{10,2,0.6,11,0,10},TURN,{-30} ,-1,{}, UNUPDATE},
             {CURVE,{10,2,0.6,6,0,41},TURN,{90} ,-1,{}, UNUPDATE},
             //{WALKER,{0,0},DISTANCE,{15},-1,{},UPDATE_DIST},
             {WALKER,{10,0},DISTANCE,{10},-1,{},UPDATE_DIST},
             {CURVE,{10,1,0.6,6,0,14},BRIGHT,{-0.3,-1}, -1,{},UNUPDATE},
             {LINETRACER,{14,1,0.5,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
             {LINETRACER,{14,1,0.5,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{8},-1,{}, UPDATE_ALL,},
             {LINETRACER,{10,1,0.6,15,LineTracer::RIGHT_EDGE,0},SONARJUDGE,{58},-1,{}, UPDATE_ALL},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};
#endif