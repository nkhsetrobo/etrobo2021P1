#ifndef EV3_JUDGE_TURNJUDGE_H_
#define EV3_JUDGE_TURNJUDGE_H_
#include "Main_Judge.h"
class Turn_Judge : public Main_Judge{
    public:
        Turn_Judge();
        bool judge();
        void set_param(double status[]);
        void init();
        
    private:
        Main_Judge* mMain_Judge;
        float tvalue;
        float baseline;

};
#endif 