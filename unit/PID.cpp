#include "PID.h"

PID::PID()
    :PID(0.01)
{
    
}

PID::PID(float delta) {
    limit = 100;
    diff[0]=diff[1]=0.0;
    integral=0;
    DELTAT=delta;

    resetFlg=true;

    sec = 30;
    cnt=0;

    for(int i=0;i<sec;i++) 
        last_integral[i]=0.0f;

  //  printf("created %f %d\n",DELTAT,sec);

}
PID::~PID() 
{
}

void PID::setLimit(float limit) 
{
    this->limit = limit;
}
void PID::setTarget(float t)
{
    this->target = t;
}

float PID::getOperation(float value)
{

//   static char buf[256];


    diff[0]=diff[1];
    diff[1] = target-value;
    float prev_i=integral;

    delta = (diff[1]-diff[0])/DELTAT;
    /*
    if(debug)printf("%d\n",cnt);
    printf("debug\n");
    for(int i=0;i<section;i++) 
        printf("%d %f\n",i,last_integral[i]);
        */
    last_integral[cnt] = (diff[0]+diff[1])/2.0*DELTAT; 
    integral+=last_integral[cnt]; 
    integral-=last_integral[(cnt+1)%sec];
    
    cnt=(cnt+1)%sec;

    if(resetFlg) {
        diff[0]=diff[1];
        delta=0.0f;
        integral=0.0f;
        for(int i=0;i<sec;i++) 
            last_integral[i]=0.0f;
        cnt=0;
        resetFlg=false;
    }

    // 積分値のオーバーを防ぐ
    /*
    if (integral>10.0) 
        integral=10.0;
    if (integral<-10.0) 
        integral=-10.0;
        */
    // 積分の初期成分は使わない
    // if(cnt++<20) {
    //     integral=0;
    // }
 
    float val = diff[1]*Kp + delta*Kd + integral*Ki;

    if (debug) {
        //printf("pid:(%3.1f-%3.1f), diff:%4.2f d:%4.2f i:%4.2f  op:%5.3f\n",target,value,diff[1],delta,integral,val);
        //msg_num(debug_char,diff[1],integral,delta, val);
    }

    if(val>limit) 
        val=limit;
    if(val<-limit)
        val=-limit;
    
    return val;
}

void PID::setKp(float kp)
{
    Kp = kp;
}

void PID::setKi(float ki)
{
    Ki = ki;
}

void PID::setKd(float kd)
{
    Kd = kd;
}

float PID::getDiff() 
{
    return diff[1];
}

float PID::getIntegral()
{
    return integral;
}

void PID::resetParam()
{
    diff[0]=diff[1]=0.0f;
    integral=0;
    resetFlg=true;
}

float PID::getTarget()
{
    return target;
}

void PID::setDeltaT(float delta)
{
    DELTAT = delta;
}