#ifndef EV3_JUDGE_COLORJUDGE_H_
#define EV3_JUDGE_COLORJUDGE_H_
#include "Main_Judge.h"

class Color_Judge : public Main_Judge{
    public:
        Color_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
    private:
        float hvalue;
        float svalue;
        float sbaseline;
        float hbaseline;
};

#endif 