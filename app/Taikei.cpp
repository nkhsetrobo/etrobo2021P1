#include "Taikei.h"
#include "ev3api.h"
#include "math.h"
Taikei::Taikei()
:
a(0.5),
b(0.2)
{

}

float Taikei::control(float ns,float ts){
    if(ts==0){
        return 0;
    }
    if(round(ns)>round(ts)){
        ns=ns-a;
    }else if(round(ns)<round(ts)){
        ns=ns+b;
    }else{
            
    }
    //printf("%f,%f\n",ns,ts);
    return ns;
}

void Taikei::init(double status[]){

}

