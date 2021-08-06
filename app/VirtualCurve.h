#ifndef EV3_APP_VIRTUALCURVE_H_
#define EV3_APP_VIRTUALCURVE_H_
#include "Walker.h"
#include "math.h"

class VirtualCurve : public Walker{
    public:
        VirtualCurve(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn);
        void run();
        void init(double status[]);
    private:
        Walker* mWalker;
        bool mIsInitialized;
        float rx;//円の中心のx座標（円で移動するため）
        float ry;//円の中心のy座標
        float sx;//センサーのx
        float sy;//センサーのｙ
        float body;//車体縦幅 
        float p;
        float i;
        float d;
        float forw;
        float bias;
        float mdistance;
        float dire;
        float calc_distance(float a,float b, float c,float d);
};
#endif