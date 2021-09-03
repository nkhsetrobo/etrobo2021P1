#ifndef EV3_UNIT_SMSLALOMB_H_
#define EV3_UNIT_SMSLALOMB_H_

#include "Section_management.h"
#include "RandomWalker.h"


class SMslalomb : public Section_management{
    public:
    
        SMslalomb();
        void init();
        void gonext();

    private:
        Main_Section slalombpra[100]={
             {WALKER,{0,0}, DISTANCE,{10},-1,{}, UPDATE_ALL},
                        
            {-1,{}, -1,{},-1,{}, UNUPDATE}
                                };
};
#endif