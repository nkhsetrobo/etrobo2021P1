#ifndef EV3_JUDGE_TIMEJUDGE_H_
#define EV3_JUDGE_TIMEJUDGE_H_
#include "Main_Judge.h"
#include "Timer.h"

class Time_Judge : public Main_Judge {
    public:
        Time_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
        
    private:
        Main_Judge* mMain_Judge;
        float tvalue;
        float baseline;//判断基準（ゆーざーがきめる）dvalue以下なら右以上なら左
};

#endif