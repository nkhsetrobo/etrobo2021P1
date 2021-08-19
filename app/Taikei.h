#ifndef EV3_APP_TAIKEI_H_
#define EV3_APP_TAIKEI_H_

class Taikei{
    public:
        Taikei();
        float control(float ns,float ts);//nsは現在速度,tsは目標速度
        void init(double status[]);
    private:

        float a;//加速度

};
#endif