#ifndef EV3_JUDGE_TAILJUDGE_H_
#define EV3_JUDGE_TAILJUDGE_H_
#include "Main_Judge.h"

class Tail_Judge : public Main_Judge {
    public:
        Tail_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
        
    private:
        Main_Judge* mMain_Judge;
        float tvalue;
        float baseline;//判断基準（ゆーざーがきめる）dvalue以下なら右以上なら左
};

#endif