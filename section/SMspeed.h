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

        float kp = 30;//kはライントレース時
        float ki = 5;//1
        float kd = 3;//0.5
        
        float lp =20;//lは仮想時
        float li = 5;
        float ld = 2.5;

    private:

        Main_Section rspeedpra[100]={ 
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, TURN,{-80}, -1,{0}, UPDATE_ALL},//285固定
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{42}, -1,{0}, UPDATE_ALL},
                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10}, -1,{0}, UPDATE_ALL},



                                /*{LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{147}, -1,{0}, UPDATE_ALL},
                                {CURVE,{lp,li,ld,55,0,-12}, TURN,{-18},-1,{0}, UPDATE_DIST},
                                {STRAIGHT,{lp,lp,ld,85,-18}, DISTANCE,{35},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,55,0,-16}, TURN,{-83},-1,{0},UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,lp,ld,85,-83}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,55,18,-12}, TURN,{-90},-1,{0}, UPDATE_DIST},
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/


                                //{LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,14}, DISTANCE,{60}, -1,{0}, UPDATE_DIST},//13
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{LINETRACER,{kp,ki,kd,60,LineTracer::RIGHT_EDGE,0}, DISTANCE,{67}, -1,{0}, UPDATE_DIST},
                               
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //U字カーブ
                                {WALKER,{49,-19}, TURN,{-155},-1,{}, UPDATE_DIST},
                                //{CURVE,{lp,li,ld,55,-18,-23.5}, TURN,{-168},-1,{0}, UPDATE_DIST},

                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,lp,ld,70,-155}, DISTANCE,{45},-1,{0}, UPDATE_DIST},
                                //{STRAIGHT,{lp,lp,ld,60,-169}, DISTANCE,{12},-1,{0}, UPDATE_DIST},


                                /*{STRAIGHT,{lp,li,ld,45,-162}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                {CURVE,{lp,li,ld,55,0,15.1}, TURN,{-90},-1,{0}, UPDATE_DIST},
                                {LINETRACER,{ki,ki,kd,58,LineTracer::RIGHT_EDGE,0}, DISTANCE,{33}, -1,{0}, UPDATE_ALL},ライン復帰*/
                                //{STRAIGHT,{lp,li,ld,45,-162}, DISTANCE,{5},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,57,18,17.5}, TURN,{-90},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,lp,ld,70,-90}, DISTANCE,{46},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //{LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{}, -1,{0}, UPDATE_DIST},

                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //{LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,-14}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},//-30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{kp,ki,kd,60,LineTracer::RIGHT_EDGE,0}, DISTANCE,{29}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                /*{WALKER,{0,40}, TURN,{65}, -1,{0},UNUPDATE},
                                {STRAIGHT,{lp,li,ld,65,65}, DISTANCE,{55},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,65,65}, BRIGHT,{0.2},-1,{0}, UPDATE_DIST},直線S字*/
                                
                                
                                
                                /*{CURVE,{lp,li,ld,65,0,14.5}, TURN,{90},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,65,105}, DISTANCE,{14.5},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,65,0,-14.5}, TURN,{10},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,55,10}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                {CURVE,{lp,li,ld,55,0,12}, TURN,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{1,30}, TURN,{-5}, -1,{0},UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {LINETRACER,{ki,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,65,90}, BRIGHT,{-0.25,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},仮想+ライン*/

                                {WALKER,{40,30}, TURN,{20},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{CURVE,{lp,li,ld,50,20,10.5}, TURN,{17},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,75,15}, DISTANCE,{28},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                //{CURVE,{lp,li,ld,50,-20,-16}, TURN,{-90},-1,{0}, UPDATE_DIST},
                                {WALKER,{40,-30}, TURN,{-85},-1,{}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,75,-85},DISTANCE,{30},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{LINETRACER,{ki,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                {WALKER,{40,30}, TURN,{-1},-1,{}, UPDATE_DIST},


                                //{CURVE,{lp,li,ld,55,20,10.5}, TURN,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{1,30}, TURN,{-5}, -1,{0},UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{LINETRACER,{ki,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,72,-1}, DISTANCE,{24},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,65,-20,-13}, CURVE,{-54},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,75,-54}, DISTANCE,{34},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {CURVE,{lp,li,ld,65,0,12}, TURN,{-8},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {STRAIGHT,{lp,li,ld,70,-8}, BRIGHT,{-0.2,-1},-1,{0}, UPDATE_DIST},
                                //{CURVE,{lp,li,ld,55,0,10}, TURN,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{55,0}, DISTANCE,{0.4},-1,{}, UPDATE_DIST},
                                {STRAIGHT,{lp,li,ld,70,0}, DISTANCE,{5},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{}, UNDEFINED},
                                //{CURVE,{lp,li,ld,65,0,12}, TURN,{0},-1,{0}, UPDATE_DIST},


                                //ここからS字カーブ
                                //{CURVE,{kp,ki,kd,65,0,10}, TURN,{0},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{kp,ki,kd,60,100}, DISTANCE,{36.5},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{CURVE,{kp,ki,kd,35,27,-18}, TURN,{0},-1,{-90}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED}, 
                                //ここまでS字カーブ



                                //{LINETRACER,{kp,ki,kd,55,LineTracer::RIGHT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                //{LINETRACER,{kp,ki,kd,50,LineTracer::RIGHT_EDGE,0}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},//22
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //U字カーブ
                                //{CURVE,{kp,ki,kd,55,24,23.5}, TURN,{80},-1,{0}, UNUPDATE},





                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{CURVE,{lp,li,ld,80,0,-11}, TURN,{-90},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{LINETRACER,{lp,5,10,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{LINETRACER,{lp,5,10,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //{LINETRACER,{kp,ki,kd,70,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10}, -1,{0}, UPDATE_ALL},
                                //{LINETRACER,{lp,li,ld,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{10}, -1,{0}, UPDATE_ALL},
                                {LINETRACER,{lp,li,ld,85,LineTracer::RIGHT_EDGE,0}, TURN,{80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                /*{STRAIGHT,{kp,ki,kd,85,0}, DISTANCE,{35},-1,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{kp,ki,kd,50,20,-18}, TURN,{-120},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{kp,ki,kd,85,-120}, DISTANCE,{29},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //2つ目のU字カーブ
                                {CURVE,{kp,ki,kd,50,20,14}, TURN,{20},-1,{0}, UNUPDATE},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {STRAIGHT,{kp,ki,kd,85,20}, BRIGHT,{-0.8,-1},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{190},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, TURN,{80},-1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000},-1,{0}, UNDEFINED},

                                //{STRAIGHT,{40,1,1,85,10}, DISTANCE,{160},-1,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},*/
                        
                                {-1,{}, -1,{},-1,{0}, UNUPDATE}
                                };

        Main_Section rspeedpraB[100]={ 
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{168}, -1,{0}, UPDATE_ALL},//285固定
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,6,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー U字カ－ブ
                                {LINETRACER,{kp,7,kd,85,LineTracer::RIGHT_EDGE,21}, DISTANCE,{62}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,7,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{23}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},//58
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //減速
                                //{LINETRACER,{kp,ki,kd,80,LineTracer::LEFT_EDGE,0}, DISTANCE,{16}, -1,{0}, UPDATE_ALL},
                                //ここから3つS字カーブ
                                {LINETRACER,{40,9,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{39}, -1,{0}, UPDATE_ALL},//20  0.4
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {LINETRACER,{40,10,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {LINETRACER,{45,10,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{40,10,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{40}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{35,7,kd,80,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{35,9,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{45}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{kp,7,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,7,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{52}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{100}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,50,LineTracer::RIGHT_EDGE,0}, TURN,{80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
        
        Main_Section rspeedpraA[100]={ 
                                {LINETRACER,{kp,ki,kd,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{175}, -1,{0}, UPDATE_ALL},//285固定
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},//13
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
                                {LINETRACER,{kp,ki,0.4,45,LineTracer::RIGHT_EDGE,-25}, DISTANCE,{47}, -1,{0}, UPDATE_ALL},//-30 D 0.2
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,70,LineTracer::RIGHT_EDGE,0}, DISTANCE,{32}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{kp,ki,kd,45,LineTracer::RIGHT_EDGE,28}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},//24  0.4
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,75,LineTracer::RIGHT_EDGE,0}, DISTANCE,{41}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,55,LineTracer::RIGHT_EDGE,0}, DISTANCE,{25}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{kp,ki,kd,35,LineTracer::RIGHT_EDGE,22}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},//22
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,0}, DISTANCE,{22}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{kp,ki,kd,65,LineTracer::RIGHT_EDGE,-15}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},//-15
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,0.4,85,LineTracer::RIGHT_EDGE,0}, DISTANCE,{190}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,20,LineTracer::RIGHT_EDGE,0}, TURN,{80}, -1,{0}, UPDATE_ALL},
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
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

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
                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{168}, -1,{0}, UPDATE_ALL},//285固定
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,6,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{20}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第2コーナー U字カ－ブ
                                {LINETRACER,{kp,7,kd,85,LineTracer::LEFT_EDGE,21}, DISTANCE,{62}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{23}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第3コーナー
                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{43}, -1,{0}, UPDATE_ALL},//58
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                //減速
                                //{LINETRACER,{kp,ki,kd,80,LineTracer::LEFT_EDGE,0}, DISTANCE,{16}, -1,{0}, UPDATE_ALL},
                                //ここから3つS字カーブ
                                {LINETRACER,{40,10,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{39}, -1,{0}, UPDATE_ALL},//20  0.4
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {LINETRACER,{45,10,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                {LINETRACER,{45,10,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {LINETRACER,{45,10,kd,78,LineTracer::LEFT_EDGE,0}, DISTANCE,{30}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,10,kd,83,LineTracer::LEFT_EDGE,0}, DISTANCE,{50}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{45,10,kd,75,LineTracer::LEFT_EDGE,0}, DISTANCE,{35}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //第4コーナー
                                {LINETRACER,{kp,7,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{18}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,7,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{52}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                

                                //第5コーナー
                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{60}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,85,LineTracer::LEFT_EDGE,0}, DISTANCE,{100}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{kp,ki,kd,50,LineTracer::LEFT_EDGE,0}, TURN,{-80}, -1,{0}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };
};

#endif