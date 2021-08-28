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

        Main_Section speedpra[100]={  {LINETRACER,{50,1,4,63,0,0}, DISTANCE,{285},-1,{0}, UPDATE_ALL},//285固定
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                //{CURVE,{30,1,5,25,0,19}, DISTANCE,{52}, UPDATE_DIST},//52
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{60,1,5,50,0,18}, TURN,{165},-1,{0}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,0,50,165}, DISTANCE,{40},-1,{0}, UPDATE_DIST},//40 STRAIGHT,{10,0,0,30,251}, DISTANCE,{376}
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{40,1,3,50,0,-17}, TURN,{80},-1,{0}, UNUPDATE},//25
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,3,50,80}, DISTANCE,{45},-1,{0}, UPDATE_DIST},//45
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //ここから3つS字カーブ
                                {CURVE,{60,1,5,60,0,-17}, TURN,{-40},-1,{0}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,-40}, DISTANCE,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{60,1,5,60,0,17}, TURN,{90},-1,{0}, UPDATE_DIST},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,5,50,75}, DISTANCE,{30},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,5,60,0,19}, TURN,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,5,50,160}, DISTANCE,{13},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,5,50,0,-21}, TURN,{0},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,30,-20}, DISTANCE,{24}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200},-1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };

    Main_Section rspeedpra[100]={ 
                                {LINETRACER,{30,3,5,30,RIGHT,0}, DISTANCE,{3000},-1,{0}, UPDATE_ALL},//試し用
                        
                                {-1,{}, -1,{},0,{}, UNUPDATE}
                                };
    Main_Section lspeedpra[100]={ {LINETRACER,{30,3,5,35,LEFT,0}, DISTANCE,{1000},-1,{0}, UPDATE_ALL},//試し用
                                {LINETRACER,{30,3,5,10,LEFT,0}, DISTANCE,{30},-1,{0}, UPDATE_ALL},//試し用
                                {-1,{}, -1,{},0,{}, UNUPDATE}
                                };
};

#endif