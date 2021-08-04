#ifndef EV3_JUDGE_DISTANCEJUDGE_H_
#define EV3_JUDGE_DISTANCEJUDGE_H_
#include "Main_Judge.h"

class Distance_Judge : Main_Judge {
    public:
        Distance_Judge();
        bool judge();
        void init(double status[]);
    private:
        Main_Judge* mMain_Judge;
        float dvalue;
        float baseline;//判断基準（ゆーざーがきめる）dvalue以下なら右以上なら左
};

#endif