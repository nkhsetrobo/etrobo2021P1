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

        Main_Section rspeedpra[100]={ 
                                {LINETRACER,{25,1,0.5,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{165}, -1,{0}, UPDATE_ALL},
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

                                {LINETRACER,{35,1,0.6,85,LineTracer::RIGHT_EDGE,0}, TURN,{80},-1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };


        Main_Section rspeedpraA[100]={ 
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{175}, -1,{0}, UPDATE_ALL},//285固定
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,15}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},//13
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,60,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー U字カ－ブ
                                {LINETRACER,{kp,ki,kd,55,LineTracer::RIGHT_EDGE,20}, DISTANCE,{53}, -1,{0}, UPDATE_ALL},//20
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{26}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,-14}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},//-30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {LINETRACER,{20,ki,0.2,35,LineTracer::RIGHT_EDGE,-25}, DISTANCE,{47}, -1,{0}, UPDATE_ALL},//-30 D 0.2
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{38}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{kp,ki,kd,40,LineTracer::RIGHT_EDGE,28}, DISTANCE,{32}, -1,{0}, UPDATE_ALL},//24
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{38}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,55,LineTracer::RIGHT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{kp,ki,kd,35,LineTracer::RIGHT_EDGE,23}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},//22
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{22}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{kp,ki,kd,50,LineTracer::RIGHT_EDGE,-15}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},//-15
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{190}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,20,LineTracer::RIGHT_EDGE,0}, TURN,{-80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };



        Main_Section lspeedpra[100]={
                                //{CURVE,{0,0,0,45,30,-15}, TURN,{180},-1,{0}, UNUPDATE},//35,1,0.5
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
            
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

                                {STRAIGHT,{35,1,1,55,-27}, DISTANCE,{21},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,0.5,40,30,11}, TURN,{82},-1,{0}, UNUPDATE},//45,1,0.5
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED}, 
                                //ここまでS字カーブ


                                {STRAIGHT,{35,1,1,85,82}, DISTANCE,{35},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,1,50,20,18}, TURN,{153},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,1,85,153}, DISTANCE,{30},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{50,1,1,85,30,-16}, TURN,{16},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{25,1,0.5,85,16}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,0.5,55,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{LINETRACER,{35,1,1,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{170},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{30,1,0.6,85,LineTracer::LEFT_EDGE,0}, TURN,{-80},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{30,1,0.6,30,LineTracer::LEFT_EDGE,0}, DISTANCE,{20},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };


        Main_Section lspeedpraA[100]={ 
                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{175}, -1,{0}, UPDATE_ALL},//285固定
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {LINETRACER,{kp,ki,kd,75,LineTracer::LEFT_EDGE,13}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::LEFT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,60,LineTracer::LEFT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー U字カ－ブ
                                {LINETRACER,{kp,ki,kd,55,LineTracer::LEFT_EDGE,20}, DISTANCE,{59}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{26}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,-30}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{53}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {LINETRACER,{kp,ki,kd,35,LineTracer::LEFT_EDGE,-30}, DISTANCE,{47}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::LEFT_EDGE,0}, DISTANCE,{38}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{10,ki,0.1,40,LineTracer::LEFT_EDGE,24}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,55,LineTracer::LEFT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{kp,ki,kd,35,LineTracer::LEFT_EDGE,22}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::LEFT_EDGE,0}, DISTANCE,{22}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{kp,ki,kd,50,LineTracer::LEFT_EDGE,-15}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{190}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,20,LineTracer::LEFT_EDGE,0}, TURN,{-80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif