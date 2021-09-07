#include "SMblock.h"

SMblock::SMblock()
    : Section_management()
{
    
}

void SMblock::init(){
        if(_LEFT==0){
        status=rblockpra;
    }else{
        //status=lspeedpra;
        status=lblockpra;
        //status=speedpra;
    }
;
        //printf("block\n");
}

void SMblock::gonext(){

}

