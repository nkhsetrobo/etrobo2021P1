#ifndef EV3_JUDGE_ARMJUDGE_H_
#define EV3_JUDGE_ARMJUDGE_H_
#include "Main_Judge.h"

class Arm_Judge : public Main_Judge{
    public:
        Arm_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
    private:
        float avalue;
        float baseline;//判断基準（ゆーざーがきめる）
};

#endif 