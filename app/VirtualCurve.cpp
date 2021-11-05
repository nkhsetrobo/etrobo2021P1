#include "VirtualCurve.h"
#include "Section_management.h"

VirtualCurve::VirtualCurve(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn,Arm* arm,Tail* tail)
    :Walker(drive,bright,xpointer,ypointer,turn,arm,tail),
    mIsInitialized(false),
    rx(0),
    ry(0),
    sx(0),
    sy(0),
    body(5.0),
    p(0),
    i(0),
    d(0),
    forw(0),
    bias(0),
    mdistance(0),
    dire(0)
    
{

}

void VirtualCurve::run(){
    float dire;
    if (mIsInitialized == false) {
        mIsInitialized = true;
    }
    float x=mXpointer->get_value();//機体のx座標
    float y=mYpointer->get_value();//機体のy座標
    float theta=mTurn->get_value();//角度

    x=body*cos(theta)+x;
    y=body*sin(theta)+y;
    float distance=calc_distance(rx,ry,x,y);
    //printf("%f,%f,%f,%f,%f\n",x,y,rx,ry,distance);
    dire=mPID->getOperation(distance);
    if(0<mdistance)//左回りのときに入る
    {
        dire=dire*-1.0;
    }  
    dire=bias+dire;
    mDrive->run(forw,dire);
}






void VirtualCurve::init(double status[]){
    
    p=status[0];
    mPID->setKp(status[0]);
    i=status[1];
    mPID->setKi(status[1]);
    d=status[2];
    mPID->setKd(status[2]);
    forw=status[3];      
    bias=status[4];      
    mdistance=status[5]; //半径の距離の維持

    float x=mXpointer->get_value();//機体のx座標
    float y=mYpointer->get_value();//機体のy座標
    float theta=mTurn->get_value();//角度

    sx = body*cos(theta)+x;
    sy = body*sin(theta)+y;
    
    rx = x-mdistance*sin(theta);
    ry = y+mdistance*cos(theta);
    
    mPID->setTarget(fabs(mdistance));
    //printf("%f,%f,%f,%f\n",sx,sy,rx,ry);
    //printf("x, y, theta,%f,%f,%f\n",x, y, theta);
}

float VirtualCurve::calc_distance(float x1,float y1,float x2,float y2){
    float dis=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    //printf ("%f\n",dis);
    return dis;
}
