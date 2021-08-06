#ifndef EV3_UNIT_SECTION_MANEGEMENT_H_
#define EV3_UNIT_SECTION_MANEGEMENT_H_

class Section_management{
    public:
        Section_management();
        void addi_section();
        bool do_run();
        void get_param();

        enum WALKER_NO  //上から順に番号を振ってくれる
        {
            WALKER,
            LINETRACER,
            CURVE,
            STRAIGHT,
        }

        enum　JUDGE_NO
        {
            BRIGHT,
            DISTANCE,
            TURN,
        }
}