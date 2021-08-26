#ifndef EV3_UNIT_SECTION_MANEGEMENT_H_
#define EV3_UNIT_SECTION_MANEGEMENT_H_

#include "enum.h"
#include "Section.h"
#include "Odometer.h"
#include "Turn.h"

struct Main_Section{
        int     walker;
        double   w_status[10];
        int     judge;
        double   j_status[10];
        int COMMAND;
    };



class Section_management{
    public:
        enum COMMAND {
            UPDATE_ALL,//両方の更新
            UPDATE_DIST,//距離の更新    
            UPDATE_ANG,//角度の更新
            UNUPDATE
        };
        enum EDGE{
            LEFT,//0
            RIGHT//1
        };
        Section_management();
        bool do_run();
        void execUndefined();
        void add_section();
        void section_run();
        void end_section();
        virtual  void init();
        void update(int update_dist);
        virtual void gonext();
        static float DIST;
        static float ANG;

        //void get_param();
    
    protected:
        enum State {
            UNDEFINED,
            ADD_SECTION,
            SECTION_RUN,
            END_SECTION
        };

        Main_Section status[100]={  {LINETRACER,{50,1,4,63,0,0}, DISTANCE,{285}, UPDATE_ALL},//285固定
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                    //{WALKER,{85,0.0}, DISTANCE,{150}, UPDATE_ALL},
                                //{CURVE,{30,1,5,25,0,19}, DISTANCE,{52}, UPDATE_DIST},//52
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{60,1,5,50,0,20}, TURN,{165}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,5,50,165}, DISTANCE,{36}, UPDATE_DIST},//40 STRAIGHT,{10,0,0,30,251}, DISTANCE,{376}
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{40,1,5,50,0,-17}, TURN,{80}, UNUPDATE},//25
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{45,1,5,50,80}, DISTANCE,{40}, UPDATE_DIST},//45
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //ここから3つS字カーブ
                                {CURVE,{60,1,5,60,0,-17}, TURN,{-40}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,-40}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{60,1,5,60,0,21}, TURN,{80}, UPDATE_DIST},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,5,50,75}, DISTANCE,{30}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,5,60,0,19}, TURN,{160}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{40,1,5,50,160}, DISTANCE,{13}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,40,70}, DISTANCE,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{45,1,5,50,0,-21}, TURN,{0}, UPDATE_DIST},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                //{STRAIGHT,{30,1,5,30,-20}, DISTANCE,{24}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };

        //Main_Section* status;
        int section_idx;
        Section* mSection;
        State mState;
        Main_Section* mMain_Section;
        int _LEFT;

    private:


};

#endif