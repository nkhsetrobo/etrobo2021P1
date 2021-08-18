#include "Taikei.h"

Taikei::Taikei()
:
a(0.5)
{

}

float Taikei::control(float ns,float ts){
    if(ns>ts){
        ns=ns-a;
    }else if(ns<ts){
        ns=ts+a;
    }else{
            
    }
    return ns;
}

void Taikei::init(double status[]){

}

