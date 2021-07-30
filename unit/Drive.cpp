#include "Drive.h"

Drive::Drive( MotorControl* motorcontrol)
      :mForward(0),
       mTurn(0),
       mMotorControl(motorcontrol) {
}


void Drive::init(){
    mForward = 0;
    mTurn    = 0;
}

void Drive::run(int mForword,int mTurn){
    int rPWM=mForword+mTurn;
    int lPWM=mForword-mTurn;
    fwd + turn = rPWM
    fwd - turn = lPWM


    if (a >= 85){               /*aが85より大きいときは*/
	    a-85 = n;
	
	    if (b >= 85){
		    b-85 = m;
		
		    if (a > b){         /*両方でかいときはここで大きさ比較する*/
			    b-n = new b;
	    	}
		    else (a < b){
			    a-m = new a;
    		}
	    }
	    b-n = new b;	
    }

    else (b >= 85){
	    b-85 = m;
	    a-m = new a;
    }

    mMotorControl->runcontrol(rPWM,lPWM);
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回方向
 */
/*void Drive::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}*/
