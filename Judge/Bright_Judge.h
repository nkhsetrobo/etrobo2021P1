#ifndef EV3_JUDGE_BRIGHTJUDGE_H_
#define EV3_JUDGE_BRIGHTJUDGE_H_
#include "Main_Judge.h"

class Bright_Judge : public Main_Judge{
    public:
        Bright_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
    private:
        float bvalue;
        float baseline;//判断基準（ゆーざーがきめる）
        float value;//黒か白かの向き
};

#endif 