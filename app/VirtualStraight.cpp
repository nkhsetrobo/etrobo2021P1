#include "VirtualStraight.h"

VirtualStraight::VirtualStraight(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm)
    :Walker(drive,bright,xpointer,ypointer,turn,arm),
    mIsInitialized(false),
    sx(0),
    sy(0),
    gx(0),
    gy(0),
    body(5.0),
    p(0),
    i(0),
    d(0),
    forw(0),
    theta(0),
    mdistance(0),
    dire(0)
    
{

}

void VirtualStraight::run(){
    float dire;
    if (mIsInitialized == false) {
        mDrive->init();
        mIsInitialized = true;
    }
    float x=mXpointer->get_value();//機体のx座標
    float y=mYpointer->get_value();//機体のy座標
    float th=mTurn->get_value(); //角度

   // printf("%f,%f,%f\n",x,y,th);

    x=body*cos(th)+x;
    y=body*sin(th)+y;

    float distance=calc_distance(x,y,sx,sy,gx,gy);
    //printf("%f,%f,%f,%f,%f,%f\n",x,y,sx,sy,gx,gy);
    dire=mPID->getOperation(distance);
    
    mDrive->run(forw,dire);
}






void VirtualStraight::init(double status[]){
    
    p=status[0];
    mPID->setKp(status[0]);
    i=status[1];
    mPID->setKi(status[1]);
    d=status[2];
    mPID->setKd(status[2]);
    forw=status[3];

    float pi=3.141592;
    theta=pi*(status[4])/180;   //θ(シータ)に値を追加

    float x=mXpointer->get_value(); //機体のx座標
    float y=mYpointer->get_value(); //機体のy座標

    sx=x;
    sy=y;

    gx=cos(theta)+x;
    gy=sin(theta)+y;

    mPID->setTarget(0);
    printf("%f,%f,%f,%f\n",sx,sy,gx,gy);
}

float VirtualStraight::calc_distance(float X,float Y,float x1,
                                        float y1,float x2,float y2){
    float dis=((y2 - y1)*X -(x2 - x1)*Y + x2*y1 - y2*x1);
    //printf("%f\n",-dis);
    return -dis;
}
