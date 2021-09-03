#ifndef EV3_UNIT_SMSPEED_H_
#define EV3_UNIT_SMSPEED_H_

#include "Section_management.h"
#include "RandomWalker.h"

class SMspeed : public Section_management{
    public:
    
        SMspeed();
        void init();
        void gonext();
        float kp = 30;
        float ki = 1;
        float kd = 0.5;

    private:

        Main_Section speedpra[100]={  //{LINETRACER,{40,1,1,85,0,0}, DISTANCE,{285},-1,{0}, UPDATE_ALL},//285固定
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                //{CURVE,{30,1,5,25,0,19}, DISTANCE,{52}, UPDATE_DIST},//52
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{25,1,0.5,85,0,0}, DISTANCE,{165}, -1,{0}, UPDATE_ALL},//285固定
                                    //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //第1コーナー
                                {LINETRACER,{30,1,0.5,80,0,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,0.5,85,0,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,0.5,85,0,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{50,1,0.5,45,0,19}, TURN,{155},-1,{0}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,1,85,155}, DISTANCE,{50},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,0.3,45,0,-15}, TURN,{69},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{35,1,1,85,69}, DISTANCE,{36},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{50,1,0.5,45,0,-15}, TURN,{-25},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                                                                /*{CURVE,{50,1,0.5,65,0,-10}, TURN,{40},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,55,0,-10}, TURN,{0},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,50,0,-25}, TURN,{-32},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/

                                {STRAIGHT,{35,1,1,85,-25}, DISTANCE,{15},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,0.5,50,0,15}, TURN,{88},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED}, 
                                //ここまでS字カーブ


                                {STRAIGHT,{35,1,1,85,88}, DISTANCE,{28},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,1,50,0,18}, TURN,{156},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,1,85,156}, DISTANCE,{28},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,1,50,0,-18}, TURN,{14},-1,{0}, UNUPDATE},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{30,1,1,85,14}, BRIGHT,{20,-0.4},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{40,1,0.6,85,0,0}, DISTANCE,{230},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };

    Main_Section rspeedpra[100]={ 
                                {LINETRACER,{30,3,5,30,RIGHT,0}, DISTANCE,{3000},-1,{0}, UPDATE_ALL},//試し用
                        
                                {-1,{}, -1,{},0,{}, UNUPDATE}
                                };
    Main_Section lspeedpra[100]={ {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{185}, -1,{0}, UPDATE_ALL},//285固定
                                    //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第1コーナー
                                {LINETRACER,{25,ki,kd,75,0,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー
                                {LINETRACER,{50,ki,0.5,85,0,0}, DISTANCE,{80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{65,ki,0.5,85,0,0}, DISTANCE,{55}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,0,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {LINETRACER,{60,1,1,65,0,0}, DISTANCE,{75}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,0,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{40,1,0.3,45,0,0}, DISTANCE,{15}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,0.2,45,0,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{35,ki,0.5,80,0,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{60,ki,kd,85,0,0}, DISTANCE,{350}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif