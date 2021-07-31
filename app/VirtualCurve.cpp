#include "VirtualCurve.h"

VirtualCurve::Curve(Drive* drive,Bright* bright,Xpointer* xpointer,Ypointer* ypointer,Turn* turn)
    :Walker(drive,bright,xpointer,ypointer,turn),
{

}

void curve(){

}






void calc(){
    float x=mXpointer->get_value();//機体のx座標
    float y=mYpointer->get_value();//機体のy座標
    float theta=mTurn->get_value();//角度
    float rx;//円の中心のx座標（円で移動するため）
    float ry;//円の中心のy座標
    float sx=x-body;//センサーのx
    float sy=y-body;//センサーのｙ
    float body=5.0;//車体幅
    float diameter;//直径

    sx=sx*cos(theta);
    sy=sy*sin(theta);
    
    rx=x+diameter*cos(theta);
    ry=y+diameter*sin(theta);


}