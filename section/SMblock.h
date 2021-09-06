#ifndef EV3_UNIT_SMBLOCK_H_
#define EV3_UNIT_SMBLOCK_H_

#include "Section_management.h"
#include "RandomWalker.h"

class SMblock : public Section_management{
    public:
        SMblock();
        void init();
        void gonext();

    private:
    Main_Section blockpra[100]={
            {LINETRACER,{30,1,1,15,LEFT,0}, DISTANCE,{5},-1,{}, UPDATE_ALL},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {CURVE,{30,1,1,30,0,-30},TURN,{-70},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {STRAIGHT,{30,1,1,70,-70},DISTANCE,{110},-1,{},UNUPDATE},
            {STRAIGHT,{20,1,0.8,10,-75},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,-10}, TURN,{-140},-1,{}, UNUPDATE},
            //{CURVE,{30,1,5,15,0,-9},TURN,{-171},-1,{},UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {LINETRACER,{10,1,0.6,8,RIGHT,0}, DISTANCE,{15},-1,{}, UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            //{STRAIGHT,{30,1,1,1,-174},COLORJUDGE,{0.3,350},-1,{},UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {STRAIGHT,{30,1,1,30,-170},DISTANCE,{17},-1,{},UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            //ブロック取った後
            {CURVE,{30,1,1,35,0,-10},TURN,{-70},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,1,1,70,-80},DISTANCE,{60},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,20,-80},DISTANCE,{20},-1,{},UPDATE_DIST},
            {CURVE,{30,1,1,20,0,-25},DISTANCE,{25},-1,{},UPDATE_DIST},

            //{STRAIGHT,{30,1,1,10,-85},BRIGHT,{-0.1,-1},-1,{},UPDATE_DIST},

            {LINETRACER,{30,1,1,7,LEFT,0}, DISTANCE,{15},-1,{}, UPDATE_ALL},
            //{CURVE,{30,1,5,40,0,-1},TURN,{-30},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,1,1,15,-32},SONARJUDGE,{4},-1,{},UPDATE_DIST},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {-1,{},-1,{}, -1,{}, UNUPDATE}
    };
};

#endif