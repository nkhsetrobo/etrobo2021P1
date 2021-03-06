#ifndef EV3_UNIT_SMBLOCK_H_
#define EV3_UNIT_SMBLOCK_H_

#include "Section_management.h"
#include "RandomWalker.h"
#include "LineTracer.h"

class SMblock : public Section_management{
    public:
        SMblock();
        void init();
        void gonext();

    private:
    Main_Section lblockpra[100]={
            /*{LINETRACER,{10,1,0.6,10,LineTracer::LEFT_EDGE,0}, SONARJUDGE,{70},-1,{}, UPDATE_ALL},
            {CURVE,{30,1,1,40,0,-30},TURN,{-60},-1,{},UNUPDATE},
            {STRAIGHT,{30,1,1,70,-65},DISTANCE,{105},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {STRAIGHT,{20,1,0.8,10,-75},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,-15}, TURN,{-140},-1,{}, UNUPDATE},
            //{CURVE,{30,1,5,15,0,-9},TURN,{-171},-1,{},UPDATE_DIST},
            {LINETRACER,{10,0,0.6,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_DIST},
            //{STRAIGHT,{30,1,1,1,-174},COLORJUDGE,{0.3,350},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,30,-168},DISTANCE,{20},-1,{},UPDATE_DIST},
            //ブロック取った後
            {CURVE,{30,1,1,40,0,-10},DISTANCE,{10},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,75,120},DISTANCE,{60},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,15,115},DISTANCE,{20},-1,{},UPDATE_DIST},
            //{CURVE,{30,1,1,10,0,-2},DISTANCE,{5},-1,{},UPDATE_DIST},

            {STRAIGHT,{10,1,0.6,7,90},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            //{CURVE,{30,1,1,20,0,-10},DISTANCE,{5},-1,{},UPDATE_DIST},
            {WALKER,{0,-5}, TURN,{-340},-1,{}, UNUPDATE},
            {LINETRACER,{10,0,0.6,10,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20},-1,{}, UPDATE_DIST},
            //{CURVE,{30,1,5,40,0,-1},TURN,{-30},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,1,1,20,16},SONARJUDGE,{4},-1,{},UPDATE_DIST},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {-1,{},-1,{}, -1,{}, UNUPDATE}*/

            //{LINETRACER,{10,1,0.6,15,LineTracer::LEFT_EDGE,0}, SONARJUDGE,{85},-1,{}, UPDATE_ALL},

            {CURVE,{30,2,1,30,0,-29.5},TURN,{-75},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,2,1,70,-75},DISTANCE,{105},-1,{},UNUPDATE},
            {STRAIGHT,{20,2,0.8,10,-75},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{20,0}, DISTANCE,{5},-1,{}, UPDATE_DIST},
            {WALKER,{0,-15}, TURN,{-150},-1,{}, UNUPDATE},
            //{CURVE,{30,1,5,15,0,-9},TURN,{-171},-1,{},UPDATE_DIST},
            {LINETRACER,{15,1,0.6,6,LineTracer::LEFT_EDGE,0}, DISTANCE,{12},-1,{}, UPDATE_DIST},
            //{STRAIGHT,{30,1,1,1,-174},COLORJUDGE,{0.3,350},-1,{},UPDATE_DIST},
            //{STRAIGHT,{15,1,1,30,-177},DISTANCE,{20},-1,{},UPDATE_DIST},
            {WALKER,{40,0},DISTANCE,{16},-1,{},UPDATE_DIST},
            //ブロック取った後
            //{WALKER,{0,10}, TURN,{10},-1,{}, UNUPDATE},
            {CURVE,{20,1,1,35,0,-10},TURN,{-80},-1,{},UPDATE_ANG},
            {STRAIGHT,{30,1,1,80,-75},DISTANCE,{55},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,40,-75},DISTANCE,{20},-1,{},UPDATE_DIST},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {CURVE,{30,1,1,20,0,-22},TURN,{-135},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {STRAIGHT,{10,0,0.6,10,-135},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,0}, TIMEJUDGE,{30},-1,{}, UNUPDATE},
            {WALKER,{8,-16}, TURN,{-150},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {LINETRACER,{15,0,0.6,20,LineTracer::LEFT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_DIST},
            //{WALKER,{-10,0}, DISTANCE,{-10},-1,{}, UNUPDATE},
            //{LINETRACER,{15,0,0.6,35,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{}, UPDATE_DIST},
            //{CURVE,{30,1,5,40,0,-1},TURN,{-30},-1,{},UPDATE_ALL},
            {WALKER,{20,0},SONARJUDGE,{4},-1,{},UPDATE_DIST},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {-1,{},-1,{}, -1,{}, UNUPDATE}
    };


    Main_Section rblockpra[100]={
            /*{LINETRACER,{10,1,0.6,15,LineTracer::RIGHT_EDGE,0}, SONARJUDGE,{85},-1,{}, UPDATE_ALL},

            {CURVE,{30,1,1,30,0,30},TURN,{75},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,1,1,70,75},DISTANCE,{105},-1,{},UNUPDATE},
            {STRAIGHT,{20,1,0.8,10,75},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,10}, TURN,{140},-1,{}, UNUPDATE},
            //{CURVE,{30,1,5,15,0,-9},TURN,{-171},-1,{},UPDATE_DIST},
            {LINETRACER,{10,0,0.6,8,LineTracer::RIGHT_EDGE,0}, DISTANCE,{15},-1,{}, UPDATE_DIST},
            //{STRAIGHT,{30,1,1,1,-174},COLORJUDGE,{0.3,350},-1,{},UPDATE_DIST},
            {WALKER,{30,0},DISTANCE,{20},-1,{},UPDATE_DIST},
            //ブロック取った後
            //{WALKER,{0,10}, TURN,{10},-1,{}, UNUPDATE},
            {CURVE,{20,1,1,35,0,10},TURN,{95},-1,{},UPDATE_ANG},
            {STRAIGHT,{30,1,1,70,95},DISTANCE,{45},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,30,95},DISTANCE,{20},-1,{},UPDATE_DIST},
            {CURVE,{30,1,1,20,0,25},TURN,{180},-1,{},UNUPDATE},

            {STRAIGHT,{10,0,0.6,10,110},BRIGHT,{-0.3,-1},-1,{},UNUPDATE},
            {WALKER,{10,10}, TURN,{140},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {LINETRACER,{15,0,0.6,15,LineTracer::RIGHT_EDGE,0}, DISTANCE,{8},-1,{}, UPDATE_DIST},
            //{CURVE,{30,1,5,40,0,-1},TURN,{-30},-1,{},UPDATE_ALL},
            {WALKER,{15,0},SONARJUDGE,{4},-1,{},UPDATE_DIST},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {-1,{},-1,{}, -1,{}, UNUPDATE}*/



            //{LINETRACER,{10,1,0.6,20,LineTracer::RIGHT_EDGE,0}, SONARJUDGE,{65},-1,{}, UPDATE_ALL},

            {CURVE,{30,2,1,30,0,29.5},TURN,{75},-1,{},UPDATE_ALL},
            {STRAIGHT,{30,2,1,70,75},DISTANCE,{105},-1,{},UNUPDATE},
            {STRAIGHT,{20,2,0.8,10,75},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,15}, TURN,{140},-1,{}, UNUPDATE},
            //{CURVE,{30,1,5,15,0,-9},TURN,{-171},-1,{},UPDATE_DIST},
            {LINETRACER,{20,1,0.6,15,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20},-1,{}, UPDATE_DIST},
            //{STRAIGHT,{30,1,1,1,-174},COLORJUDGE,{0.3,350},-1,{},UPDATE_DIST},
            //{STRAIGHT,{15,1,1,30,-177},DISTANCE,{20},-1,{},UPDATE_DIST},
            {WALKER,{40,0},DISTANCE,{10},-1,{},UPDATE_DIST},
            //ブロック取った後
            //{WALKER,{0,10}, TURN,{10},-1,{}, UNUPDATE},
            {CURVE,{20,1,1,25,0,10},TURN,{80},-1,{},UPDATE_ANG},
            {STRAIGHT,{30,1,1,60,80},DISTANCE,{55},-1,{},UPDATE_DIST},
            {STRAIGHT,{30,1,1,40,80},DISTANCE,{20},-1,{},UPDATE_DIST},
            {CURVE,{30,1,1,20,0,21},TURN,{125},-1,{},UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {STRAIGHT,{10,0,0.6,20,135},BRIGHT,{-0.1,-1},-1,{},UNUPDATE},
            {WALKER,{0,0}, TIMEJUDGE,{30},-1,{}, UNUPDATE},
            {WALKER,{20,20}, TURN,{150},-1,{}, UNUPDATE},
            //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            {LINETRACER,{20,0,0.6,33,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10},-1,{}, UPDATE_DIST},
            //{CURVE,{30,1,5,40,0,-1},TURN,{-30},-1,{},UPDATE_ALL},
            {WALKER,{30,0},SONARJUDGE,{4},-1,{},UPDATE_DIST},
            //{STRAIGHT,{10,0,0.6,10,0},SONARJUDGE,{4},-1,{},UNUPDATE},
            {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

            {-1,{},-1,{}, -1,{}, UNUPDATE}
    };
};

#endif 