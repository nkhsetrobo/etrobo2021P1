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
        int     judge2;
        double     j2_status[10];
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
            END_SECTION,
        };

        Main_Section* status;

        int section_idx;
        Section* mSection;
        State mState;
        Main_Section* mMain_Section;
        int _LEFT;
        int error;
    private:

};

#endif