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

        Section_management();
        bool do_run();
        void execUndefined();
        void add_section();
        void section_run();
        void end_section();
        void update(int update_dist);
        static float DIST;
        static float ANG;

        //void get_param();
    
    private:
        enum State {
            UNDEFINED,
            ADD_SECTION,
            SECTION_RUN,
            END_SECTION,
        };

        Main_Section status[100]={ {LINETRACER,{30,1,5,50,0,0}, DISTANCE,{285}, UPDATE_ALL},//280固定
                                //{CURVE,{30,1,5,25,0,19}, DISTANCE,{52}, UPDATE_DIST},//52
                                {CURVE,{30,1,5,35,0,19}, TURN,{160}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,158}, DISTANCE,{38}, UPDATE_DIST},//40 STRAIGHT,{10,0,0,30,251}, DISTANCE,{376}
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,30,0,-17}, TURN,{70}, UNUPDATE},//25
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,70}, DISTANCE,{45}, UPDATE_DIST},//45
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                //ここから3つS字カーブ
                                {CURVE,{30,1,5,30,0,-17}, TURN,{-80}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,-80}, DISTANCE,{1}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                                
                                {CURVE,{30,1,5,30,0,16}, TURN,{80}, UPDATE_DIST},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {STRAIGHT,{30,1,5,40,70}, DISTANCE,{35}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,40,0,13}, TURN,{160}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,80}, DISTANCE,{1}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,40,0,-17}, TURN,{0}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,30,-20}, DISTANCE,{20}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {LINETRACER,{30,1,5,50,0,0}, DISTANCE,{200}, UPDATE_ALL},
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };

        int section_idx;
        Section* mSection;
        State mState;
        Main_Section* mMain_Section;



};

#endif