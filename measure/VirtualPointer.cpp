#include "VirtualPointer.h"

VirtualPointer::VirtualPointer(MotorControl* motorcontrol,Xpointer* xpointer,Ypointer* ypointer,
                            Odometer* odometer,Turn* turn)
    :
        mMotorControl(motorcontrol),
        mXpointer(xpointer),
        mYpointer(ypointer),
        mOdometer(odometer),
        mTurn(turn),
        current_rs1(0.0),//getcount
        current_rs2(0.0),//getcount
        prev_rs1(0.0),//値保持
        prev_rs2(0.0),//値保持
        th(0.0),
        x(0.0),//xpointer
        y(0.0),//ypointer
        sumlen(0.0)//odometer
        {
        }

        
void VirtualPointer::calc()
{
    current_rs1=mMotorControl->get_rightMotor();
    current_rs2=mMotorControl->get_leftMotor();

	float rs1 = current_rs1;
	float rs2 = current_rs2;
	float drs1=rs1-prev_rs1;
	float drs2=rs2-prev_rs2;
	float len_l = drs1*M_PI*D_LEFT/360.0;
	float len_r = drs2*M_PI*D_RIGHT/360.0;
	float dth=(len_r-len_l)/TREAD;
	x+= (len_r+len_l)/2.0*cos(th+dth/2.0); //進行方向 X軸 0度方向
	y+= (len_r+len_l)/2.0*sin(th+dth/2.0); //横	
	th+=dth; // 左旋回＋、右旋回-
	sumlen += (len_r+len_l)/2.0;
    printf("%f,%f,%f,%f\n",x,y,sumlen,th);
    mXpointer->load(x);
    mYpointer->load(y);
    mOdometer->load(sumlen);
    mTurn->load(th);
    //mSpeedmeter->load();
    prev_rs1=rs1;
    prev_rs2=rs2;
}