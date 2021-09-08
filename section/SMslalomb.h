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
             {CURVE,{10,2,0.6,11,0,-24.5}, TURN,{-43},-1,{}, UNUPDATE},
             //{WALKER,{0,-10},TURN,{-50},-1,{},UNUPDATE},
             //{WALKER,{10,0},DISTANCE,{10},-1,{},UNUPDATE},
            //{CURVE,{10,2,0.6,11,0,10},TURN,{-30} ,-1,{}, UNUPDATE},
             {CURVE,{10,2,0.6,11,0,-45},TURN,{-85} ,-1,{}, UNUPDATE},
             {WALKER,{10,0},DISTANCE,{15},-1,{},UPDATE_DIST},
             {CURVE,{10,1,0.6,6,0,-15},BRIGHT,{-0.3,-1}, -1,{},UNUPDATE},
             {LINETRACER,{14,1,0.5,6,RIGHT,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
             {WALKER,{10,0},SONARJUDGE,{50},-1,{}, UPDATE_ALL},
                        
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };




        Main_Section rslalombpra[100]={
            {CURVE,{10,2,0.6,6,0,20}, TURN,{43},-1,{}, UNUPDATE},
             //{WALKER,{0,-10},TURN,{-50},-1,{},UNUPDATE},
             //{WALKER,{10,0},DISTANCE,{10},-1,{},UNUPDATE},
             //{CURVE,{10,2,0.6,11,0,10},TURN,{-30} ,-1,{}, UNUPDATE},
             {CURVE,{10,2,0.6,6,0,48},TURN,{95} ,-1,{}, UNUPDATE},
             //{WALKER,{0,0},DISTANCE,{15},-1,{},UPDATE_DIST},
             {WALKER,{10,-2},DISTANCE,{15.5},-1,{},UPDATE_DIST},
             {CURVE,{10,1,0.6,6,0,14},BRIGHT,{-0.3,-1}, -1,{},UNUPDATE},
             {LINETRACER,{14,1,0.5,6,RIGHT,0}, DISTANCE,{8},-1,{}, UPDATE_ALL},
             {WALKER,{10,0},SONARJUDGE,{85},-1,{}, UPDATE_ALL},
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};
#endif