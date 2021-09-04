#ifndef EV3_UNIT_SMSPEED_H_
#define EV3_UNIT_SMSPEED_H_

#include "Section_management.h"
#include "RandomWalker.h"
#include "LineTracer.h"

class SMspeed : public Section_management{
    public:
    
        SMspeed();
        void init();
        void gonext();
        float kp = 30;
        float ki = 1;
        float kd = 0.5;

    private:

        Main_Section rspeedpra[100]={ {LINETRACER,{25,1,0.5,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{165}, -1,{0}, UPDATE_ALL},
                                    //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //第1コーナー
                                {LINETRACER,{30,1,0.5,50,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,0.5,55,LineTracer::RIGHT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,0.5,55,LineTracer::RIGHT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{50,1,0.5,45,0,-19}, TURN,{-155},-1,{0}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,1,85,-155}, DISTANCE,{50},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,0.3,45,0,15}, TURN,{-72},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{35,1,1,85,-72}, DISTANCE,{39},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{45,1,0.5,50,0,12}, TURN,{25},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                                                                /*{CURVE,{50,1,0.5,65,0,-10}, TURN,{40},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,55,0,-10}, TURN,{0},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,50,0,-25}, TURN,{-32},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/

                                {STRAIGHT,{35,1,1,85,25}, DISTANCE,{18},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,0.5,50,0,-12}, TURN,{-88},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED}, 
                                //ここまでS字カーブ


                                {STRAIGHT,{35,1,1,85,-88}, DISTANCE,{28},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,1,50,0,-18}, TURN,{-156},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,1,85,-156}, DISTANCE,{28},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,1,50,0,17}, TURN,{-21},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{25,1,0.5,85,-21}, BRIGHT,{-0.8,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{35,1,0.6,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{190},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{30,1,0.6,30,LineTracer::RIGHT_EDGE,0}, DISTANCE,{40},-1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };

        Main_Section lspeedpra[100]={ {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{185}, -1,{0}, UPDATE_ALL},//285固定
                                    //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第1コーナー
                                {LINETRACER,{25,ki,kd,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー
                                {LINETRACER,{50,ki,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{65,ki,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{55}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {LINETRACER,{60,1,1,65,LineTracer::LEFT_EDGE,0}, DISTANCE,{75}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{40,1,0.3,45,LineTracer::LEFT_EDGE,0}, DISTANCE,{15}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,0.7,45,LineTracer::LEFT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{35,ki,0.5,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{55,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{300}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{35,ki,kd,20,LineTracer::LEFT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };

        Main_Section speedpra[100]={{CURVE,{0,0,0,45,30,15}, TURN,{180},-1,{0}, UNUPDATE},//35,1,0.5
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            
             {LINETRACER,{25,1,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{165}, -1,{0}, UPDATE_ALL},
                                    //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //第1コーナー
                                {LINETRACER,{30,1,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,0.5,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{45,1,0.5,45,15,19}, TURN,{155},-1,{0}, UPDATE_ANG},//45,1,0.5
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,1,85,155}, DISTANCE,{49},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{35,1,0.5,45,-35,-15}, TURN,{69},-1,{0}, UNUPDATE},//35,1,0.5
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{35,1,1,85,69}, DISTANCE,{40},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {CURVE,{45,1,0.5,50,-40,-12}, TURN,{-27},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                                                                /*{CURVE,{50,1,0.5,65,0,-10}, TURN,{40},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,55,0,-10}, TURN,{0},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                                                                {CURVE,{35,1,1,50,0,-25}, TURN,{-32},-1,{0}, UNUPDATE},
                                                                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/

                                {STRAIGHT,{35,1,1,85,-26}, DISTANCE,{21},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,0.5,40,30,11}, TURN,{72},-1,{0}, UNUPDATE},//45,1,0.5
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED}, 
                                //ここまでS字カーブ


                                {STRAIGHT,{35,1,1,85,72}, DISTANCE,{35},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,1,50,20,18}, TURN,{153},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,1,85,153}, DISTANCE,{30},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,1,50,30,-16}, TURN,{17},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{25,1,0.5,85,17}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,1,1,55,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{35,1,1,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{170},-1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{30,1,0.6,85,LineTracer::LEFT_EDGE,0}, TURN,{-80},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{LINETRACER,{30,1,0.6,30,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };
};

#endif