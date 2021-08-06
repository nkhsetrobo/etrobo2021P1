#ifndef EV3_APP_VIRTUALSTRAIGHT_H_
#define EV3_APP_VIRTUALSTRAIGHT_H_
#include "Walker.h"
#include "math.h"

class VirtualStraight : public Walker{
    public:
        VirtualStraight(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn);
        void run();
        void init(double status[]);
    private:
        Walker* mWalker;
        bool mIsInitialized;
        float sx;   //走行体のスタートのX座標   ﾒﾓ:X
        float sy;   //走行体のスタートのY座標   ﾒﾓ:Y
        float gx;   //ゴールのx座標     ﾒﾓ:x1
        float gy;   //ゴールのy座標     ﾒﾓ:y1
        float body; //車体縦幅
        float p;    //PIDの値
        float i;
        float d;
        float forw;//forword
        float theta;//θ(シータ)
        float mdistance;   //センサーの射程
        float dire;         //ディレイ
        float calc_distance(float a,float b,float c,
                                float d,float f,float g);//計算機、計算スペース
};
#endif