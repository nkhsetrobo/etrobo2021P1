#ifndef EV3_JUDGE_SONARJUDGE_H_
#define EV3_JUDGE_SONARJUDGE_H_
#include "Main_Judge.h"

class Sonar_Judge : public Main_Judge{
    public:
        Sonar_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
    private:
        float svalue;
        float baseline;//判断基準（ゆーざーがきめる）
};

#endif 