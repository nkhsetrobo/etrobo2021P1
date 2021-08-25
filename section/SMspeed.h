#ifndef EV3_UNIT_SMSPEED_H_
#define EV3_UNIT_SMSPEED_H_

#include "Section_management.h"
#include "RandomWalker.h"

class SMspeed : public Section_management{
    public:
    
        SMspeed();
        void init();
        void gonext();

    private:

        Main_Section speedpra[100]={ {LINETRACER,{30,1,5,50,LEFT,0}, DISTANCE,{285},-1,{},UPDATE_ALL},//280固定
                                //{CURVE,{30,1,5,25,0,19}, DISTANCE,{52}, UPDATE_DIST},//52
                                {CURVE,{30,1,5,35,0,19}, TURN,{160},-1,{}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,158}, DISTANCE,{38},-1,{}, UPDATE_DIST},//40 STRAIGHT,{10,0,0,30,251}, DISTANCE,{376}
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,30,0,-17}, TURN,{70},-1,{},UNUPDATE},//25
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,70}, DISTANCE,{45},-1,{}, UPDATE_DIST},//45
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {CURVE,{30,1,5,30,0,-17}, TURN,{-80},-1,{}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,-80}, DISTANCE,{1},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{30,1,5,30,0,16}, TURN,{80},-1,{}, UPDATE_DIST},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {STRAIGHT,{30,1,5,40,70}, DISTANCE,{35},-1,{},UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,40,0,13}, TURN,{160},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,80}, DISTANCE,{1},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,40,0,-17}, TURN,{0},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,30,-20}, DISTANCE,{20},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,5,50,LEFT,0}, DISTANCE,{200},-1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNUPDATE},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };

    Main_Section rspeedpra[100]={ 
                                {LINETRACER,{30,3,5,30,RIGHT,0}, DISTANCE,{300},-1,{0}, UPDATE_ALL},//試し用
                        
                                {-1,{}, -1,{},0,{}, UNUPDATE}
                                };
    Main_Section lspeedpra[100]={ {LINETRACER,{30,3,5,30,LEFT,0}, DISTANCE,{300},-1,{0}, UPDATE_ALL},//試し用
                        
                                {-1,{}, -1,{},0,{}, UNUPDATE}
                                };
};

#endif