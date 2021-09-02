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

                                {LINETRACER,{30,1,0.5,85,0,0}, DISTANCE,{65}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{65,1,1,60,0,19}, TURN,{160},-1,{0}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,1,70,160}, DISTANCE,{50},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{55,1,1,65,0,-15}, TURN,{80},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{35,1,1,85,80}, DISTANCE,{43},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,0.5,65,0,-15}, TURN,{-35},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                                                                /*{CURVE,{50,1,0.5,65,0,-10}, TURN,{40},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,55,0,-10}, TURN,{0},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,50,0,-25}, TURN,{-32},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/

                                {STRAIGHT,{35,1,1,85,-32}, DISTANCE,{20},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,0.5,65,0,15}, TURN,{90},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{55,1,1,65,0,30}, TURN,{},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{55,1,1,65,0,-10}, TURN,{-15},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                               /* //ここから3つS字カーブ
                                {CURVE,{70,1,1,60,0,23}, TURN,{80},-1,{0}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,1,40,-25}, DISTANCE,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{55,1,1,50,0,22}, TURN,{83},-1,{0}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/


                                {STRAIGHT,{35,1,1,60,82}, DISTANCE,{30},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{55,1,1,50,0,18}, TURN,{171},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,1,50,172}, DISTANCE,{17},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{55,1,1,50,0,-18}, TURN,{-2},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{LINETRACER,{40,1,1,40,0,0}, DISTANCE,{10},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{LINETRACER,{40,1,1,40,0,0}, DISTANCE,{10},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{40,1,1,60,-2}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
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
                                
                                {LINETRACER,{40,1,1,5,0,0}, DISTANCE,{15}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{40,1,0.5,45,0,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{35,ki,0.5,80,0,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,0,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{60,ki,kd,85,0,0}, DISTANCE,{340}, -1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif