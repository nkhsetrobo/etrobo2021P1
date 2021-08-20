#include "Drive.h"

Drive::Drive(MotorControl* motorcontrol,Taikei* taikei)
      :mForward(0.0),//現在速度
       mTurn(0),
       mMotorControl(motorcontrol),
       mTaikei(taikei) {
}


void Drive::init(){
    mForward = 0;
    mTurn    = 0;
}

void Drive::run(int forward,int turn){    //forword
    mForward=mTaikei->control(mForward,forward);
    int rPWM=mForward+turn;
    int lPWM=mForward-turn;
    int a = rPWM;
    int b = lPWM;
    int n=0;
    int m=0;
    


    if (a>85){               /*rPWMが85より大きいときは*/
	    n=a-85;
	
	    if(b>85){
		    m=b-85;
		
		    if (a>b){         /*両方85より大きいときはここで大きさ比較する*/
			    a=a-n;
                b=b-n;
	    	}else if(a<b){
			    a=a-m;
                b=b-m;
    		}
	    }
	    a=a-n;              /*a>85かつb<85の時*/
        b=b-n;	
    }

    if(b > 85){
	    b=b-m;             /*lBPMが85より大きくrPBMが85以下の時*/
	    a=a-m;
    }

    if (a<-85){               /*rPWMが-85未満ときは*/
	    n=a+85;
	
	    if(b<-85){
		    m=b+85;
		
		    if (a<b){         /*両方-85未満の時ここで大きさ比較する*/
			    a=a-n;
                b=b-n;
	    	}else if(a<b){
			    a=a-m;
                b=b-m;
    		}
	    }
	    a=a-n;              /*a<-85かつb>-85の時*/
        b=b-n;	
    }

    if(b<-85){
	    b=b-m;             /*lBPMが-85未満かつrPBMが-85未満の時*/
	    a=a-m;
    }
    rPWM=a;
    lPWM=b;

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
