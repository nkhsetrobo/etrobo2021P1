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
                                {CURVE,{30,1,5,30,0,18}, TURN,{160}, UPDATE_ANG},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,160}, DISTANCE,{25}, UPDATE_DIST},//45 STRAIGHT,{10,0,0,30,251}, DISTANCE,{376}
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,30,0,-18}, TURN,{70}, UNUPDATE},//25
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,40,70}, DISTANCE,{40}, UPDATE_DIST},//45
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,30,0,-9}, TURN,{-90}, UNUPDATE},//30
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},


                                {STRAIGHT,{30,1,5,40,-90}, DISTANCE,{1}, UPDATE_DIST},
                                
                                {CURVE,{30,1,5,30,0,15}, TURN,{70}, UNUPDATE},//30
                                {WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {STRAIGHT,{30,1,5,30,90}, DISTANCE,{45}, UPDATE_DIST},
                                //{WALKER,{0,0}, DISTANCE,{12000}, UNDEFINED},

                                {CURVE,{30,1,5,30,0,15}, DISTANCE,{20}, UNUPDATE},
                                {CURVE,{30,1,5,30,0,-20}, DISTANCE,{20}, UNUPDATE},
                                {STRAIGHT,{30,1,5,30,0}, DISTANCE,{20}, UNUPDATE},
                        
                                {-1,{}, -1,{}, UNUPDATE}
                                };

        int section_idx;
        Section* mSection;
        State mState;
        Main_Section* mMain_Section;



};

#endif